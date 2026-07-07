# Encode the compiled EXE into Base64
$inputFile = ".\src\x64\Release\TheIsle_Evrima_MumbleLink_DX11.exe"
$outputFile = ".\build\Base64.txt"

Write-Host "Encoding to Base64..."
$bytes = [IO.File]::ReadAllBytes($inputFile)
$base64 = [Convert]::ToBase64String($bytes)
Set-Content -Path $outputFile -Value $base64

Write-Host "Base64 saved to build\Base64.txt"
