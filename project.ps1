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

        cmake.exe -G 'Ninja' -DIOT_LIB_FORMULAS_USE_FLOAT:BOOL=$UseFloat -DBUILD_TEST:BOOL=ON -B "$WorkDir\$BuildPath"
    }
    'build' {
        cmake.exe --build "$WorkDir\$BuildPath" -v --config Release
    }
    'test' {
        & "$WorkDir\$BuildPath\test\test_app.exe" -v -c
    }
    Default {
        Write-Error 'Invalid command'
    }
}
