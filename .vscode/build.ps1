$files = Get-ChildItem -Path .\src -Recurse -Filter *.cpp | ForEach-Object { $_.FullName }
& 'C:\Users\Gabri\.vscode\ucrt64\bin\g++.exe' -g $files -I .\src -o .\src\main.exe
Write-Host "Exit code: $LASTEXITCODE"
