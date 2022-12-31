//security scripts

SMB share created in cloud vm and accessed by target machine to retrieve required security scripts and files

Security script tests wifi by running command to list stored cleartext wifi passwords 

Security script, presecuritytest.bat, retrieves nc.exe and privesc.exe and runs both executables to see whether windows
defender or antivirus system detects and removes malicious files

nc.exe provides basic reverse shell with cloud vm and if connection occurs then defender has failed to detect virus

privesc.exe runs privilege escalation script and returns results on how a low privileged user could escalate privileges to administrator/system user


