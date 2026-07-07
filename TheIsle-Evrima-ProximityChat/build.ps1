
Write-Host "Building TheIsle_Evrima_MumbleLink_DX11.exe..."

# Auto-detect MSBuild inside Visual Studio 18
$msbuild = Get-ChildItem "C:\Program Files\Microsoft Visual Studio\18" -Recurse -Filter MSBuild.exe | Select-Object -First 1

if (-not $msbuild) {
    Write-Host "MSBuild.exe not found! Install C++ build tools."
    exit
}

$vsPath = $msbuild.FullName

Write-Host "Using MSBuild at: $vsPath"

# Build the project
& $vsPath ".\src\TheIsle_Evrima_MumbleLink_DX11.vcxproj" /p:Configuration=Release /p:Platform=x64

Write-Host "Build complete."
