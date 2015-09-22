


#TODO
#   . execute at startup
#   . associate with phone numbers (ie. outlook)
#   . ensure 1 active instance only
#   . kill soft before uninstalling
#   . execute after installation	

# activate it only to build final package, as it takes time to compress
# 22Mo vs 38Mo uncompressed
#SetCompressor /FINAL /SOLID lzma

!define COMPANYNAME "har.bour.cc"
!define APPNAME "SmsSync"
# appversion-pkgversion
!define VERSION "0.1.0-1"

RequestExecutionLevel admin

#
OutFile "SmsSync Installer - ${VERSION}.exe"
InstallDir "$PROGRAMFILES\${COMPANYNAME}\${APPNAME}"
Name "${COMPANYNAME} - ${APPNAME}"
Icon "smssync.ico"
LicenseData "LICENSE"

page license
page instfiles

#
Section "install"
  SetOutPath $INSTDIR

  file "smssync.ico"
  file "desktop-smssync.exe"
  file /r qtlibs\*

  # create uninstaller
  WriteUninstaller $INSTDIR\uninstall.exe

  # startmenu entry
  createDirectory "$SMPROGRAMS\SmsSync"
  createShortCut "$SMPROGRAMS\${APPNAME}\${APPNAME}.lnk" "$INSTDIR\desktop-smssync.exe" "" "$INSTDIR\smssync.ico"
  createShortCut "$SMPROGRAMS\${APPNAME}\uninstall.lnk" "$INSTDIR\uninstall.exe"

  # config file
  # what is current user ?
  setOutPath "C:\Users\Default\AppData\Roaming\${APPNAME}\desktop-smssync"
  file "desktop-smssync.conf"

  # autorun
  # HKLM = all users, HK  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Run" "SmsSync" "$INSTDIR\desktop-smssync.exe"


  # run application at the end
  Exec "$INSTDIR\desktop-smssync.exe"
SectionEnd


Section "Uninstall"
  deleteRegValue HKCU "Software\Microsoft\Windows\CurrentVersion\Run" "SmsSync"

  # delete shortcuts
  delete "$SMPROGRAMS\${APPNAME}\*"
  rmDir /r "$SMPROGRAMS\${APPNAME}"

  delete "$INSTDIR\*"
  rmDir "$INSTDIR"

  # NOTE: we keep configuration file
SectionEnd
