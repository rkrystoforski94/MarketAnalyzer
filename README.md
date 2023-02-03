# MarketAnalyzer
During integrating qt with vs I changed QT version in MarketAnal project options.
Properties->Qt Project Settings -> Qt Installation ->
My QT installation is named "Qt6.4"
Yours is different ("QT 6.4.1")
You may need to change it to work.
Because of many changes with solution paths, I needed to push with that change.
You can change it like it was before my push.

Also built MarketAnal  project creates executable "MarketAnal.exe". Run throws error which indicates
missing dlls:
Qt6Widgetsd.dll
Qt6Cored.dll

P.S.
If you decide this note is not required or important for this project, please remove it.
If you don't mind,  leave it as it is. In the future, there should be installation/use instructions.


To get subomdule:
cd FastHTML/
git submodule init
git submodule update
