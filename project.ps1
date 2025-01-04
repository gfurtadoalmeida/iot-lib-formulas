$BuildPath = 'build'

if ($Null -eq $Env:GITHUB_WORKSPACE) {
    $WorkDir = '.'
}
else {
    $WorkDir = $Env:GITHUB_WORKSPACE
}

$VsWhere = Join-Path (Join-Path (Join-Path ${Env:ProgramFiles(x86)} 'Microsoft Visual Studio') Installer) vswhere.exe
$VsPath = & $VsWhere -prerelease -latest -property installationPath | Select-Object -Last 1

Import-Module -ea stop (Join-Path (Join-Path (Join-Path $VsPath Common7) Tools) Microsoft.VisualStudio.DevShell.dll)
Enter-VsDevShell -VsInstallPath $VsPath -SkipAutomaticLocation -DevCmdArguments '-arch=x86'

switch ($args[0]) {
    'generate' {
        $UseFloat = ($args[1] -eq 'float') ? 1 : 0

        &cmake.exe -G 'Ninja' -DCONFIG_IOT_LIB_FORMULAS_USE_FLOAT:BOOL=$UseFloat -DBUILD_TEST:BOOL=ON -B "$WorkDir\$BuildPath"
    }
    'build' {
        $Config = ($args.Count -eq 0) ? 'Release' : $args[1]

        &cmake.exe --build "$WorkDir\$BuildPath" -v --config "$Config"
    }
    'test' {
        &"$WorkDir\$BuildPath\test\test_app.exe" --gtest_brief=1 --gtest_print_time=1
    }
    'test-generate-report' {
        $App = "$WorkDir\$BuildPath\test\test_app.exe"
        $Config = "$WorkDir\coverage.runsettings"
        $Coverage = "$WorkDir\$BuildPath\test\coverage.xml"

        &Microsoft.CodeCoverage.Console.exe instrument -s $Config $App
        &Microsoft.CodeCoverage.Console.exe collect -o $Coverage -f xml -s $Config $App --gtest_brief=1 --gtest_print_time=1
    }
    Default {
        Write-Host 'Command not recognized. Valid commands:'
        Write-Host "`t* generate: generate compilation files"
        Write-Host "`t* build: build the project"
        Write-Host "`t* test: run the tests"
        Write-Host "`t* test-generate-report: run the tests and generate code coverage report"
    }
}
