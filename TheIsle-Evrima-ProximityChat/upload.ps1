# Upload your EXE to GitHub Releases
$token = "<YOUR_GITHUB_TOKEN>"
$repo = "pandabanana0221/TheIsle-Evrima-ProximityChat"
$tag = "v1.0"
$filePath = ".\src\x64\Release\TheIsle_Evrima_MumbleLink_DX11.exe"

Write-Host "Creating GitHub release..."

# Create release
$release = Invoke-RestMethod -Method Post `
    -Uri "https://api.github.com/repos/$repo/releases" `
    -Headers @{Authorization="token $token"} `
    -Body (@{
        tag_name = $tag
        name = "Evrima Proximity Chat DX11"
        body = "DX11 positional audio helper for The Isle Evrima."
    } | ConvertTo-Json)

# Upload asset
Invoke-RestMethod -Method Post `
    -Uri "$($release.upload_url.Replace('{?name,label}',''))?name=TheIsle_Evrima_MumbleLink_DX11.exe" `
    -Headers @{
        Authorization="token $token"
        "Content-Type"="application/octet-stream"
    } `
    -InFile $filePath

Write-Host "Upload complete."
