# Qtサンプルプロジェクト

## 1. Qtとは

## 2. 開発環境セットアップ
### 2-1. MinGWセットアップ(MSYS2使用)

MinGW(Minimalist GNU for Windows)はWindowsにおけるGNU開発環境のことである。GNU(GNU is Not Unix!)とは1983年にMITのリチャードストールマンによって発表された、フリーソフトウェアコラボレーションプロジェクトの「GNUプロジェクト」のもとに開発されたオペレーティングシステムを含む広範囲のソフトウェアコレクションのことである。

MinGW自体はパッケージ管理の機能を備えていないため、MSYS2(Minimal System2)を使用しMinGWのパッケージ管理を行う。MSYS2はArchLinuxライクなシェル環境を提供しており、パッケージ管理もpacmanを使うと容易である。

競合先としてCygWin(Cygnus is your gnu support for Windows)があるが、パッケージ管理ツールの使い勝手が悪く、パス体系も独特との意見があったためMSYS2を採用した。

下記から64bit版インストーラーをダウンロードしてインストールした。
(インストール先ディレクトリはC:\tool\msys64)

https://www.msys2.org/

プロキシ環境の場合はインストール時に必要なパッケージが全て入りきらないためインストール完了時に改めてセットアップが必要である。

下記環境変数をランコマンドファイルに追記し、実行中のShellに適応する。
```
echo "export http_proxy=hogehoge" >> ~/.bashrc
echo "export https_proxy=hogehoge" >> ~/.bashrc
source ~/.bashrc
```

パッケージ更新を実行
```
pacman -Syu
```

MSYS2を再起動することになるので再起動後に再度更新する。

```
pacman -Su
```

開発に必要なパッケージを入手する。
```
pacman -S base-devel mingw-w64-x86_64-toolchain
```

c++に必要なパッケージを入手する。
```
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb
```

ビルド自動化ツールCMakeとビルドツールNinjaのインストール
```
pacman -S mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja
```

### 2-2.VSCodeセットアップ

エディタはVisual Studio Codeを使用する。

https://code.visualstudio.com/Download

拡張機能は下記を使用する。

|拡張名|識別子|用途|
|--|--|--|
|C/C++|ms-vscode.cpptools||
|C/C++ Extention Pack|ms-vscode.cpptools-extension-pack||
|C/C++ Themes|ms-vscode.cpptools-themes||
|CMake|twxs.cmake||
|CMake Tools|ms-vscode.cmake-tools||
|Doxygen Document|cschlosser.doxdocgen||

次に、MSYS2をVSCodeのShellに登録し、コンパイラへのパスを環境変数で設定しておく。
Ctrl + Shift + P を押下し、検索ボックスにsetting.jsonと入力し、
Open User Settingを選択する。

setting.jsonファイルの編集画面から以下のように編集する。
``` json
{
    "terminal.integrated.tabStopWidth": 4,
    "terminal.integrated.profiles.windows":{
        "MSYS2 Bash": {
            "path": [
                "/msys64/usr/bin/bashへのパス"
            ],
            "args": [
                "--login"
            ],
            "env": {
                "MSYSTEM": "MINGW64",
                "CHERE_INVOKING": "1",
                "http_proxy": "hogehoge",
                "https_proxy": "hogehoge",
                "LOCAL_COMPILER": "g++",
                "LOCAL_COMPILER_PATH": "/msys64/mingw64/bin/g++へのパス"
            },
            "overrideName": true,
            "color": "terminal.ansiCyan"
        }
    },
    "terminal.integrated.defaultProfile.windows": "MSYS2 Bash",
    "cmake.configureOnOpen": true,
    "C_Cpp.default.compilerPath": "/msys64/mingw64/bin/g++へのパス"
}
```


### 2-3.Qtセットアップ

下記リンクを参考に必要なものをpacmanでインストールする。
(Qtのバージョンは6を使用する。)

https://qiita.com/mususu644/items/fb3cff72579c994fe06c

```
pacman -S mingw-w64-x86_64-qt6 mingw-w64-x86_64-qt-creator
```

Qt Creatorが起動できるか確認する。
```
qtcreator
```

``` shell
# ビルドの出力先にbuildディレクトリを指定
cmake -S . -B build

# buildフォルダを指定し、ビルド
cmake --build build
```

プログラムを実行するには下記を実行する。

``` shell
./build/sample.exe
```

エクスプローラから直接実行したい場合はMinGWとQtの提供するdllの配置ディレクトリへパスを通しておく必要がある。

### 2-4.他者に配布する場合

MinGW、Qt由来の必要なdllをexeファイルと同じフォルダに配置する必要がある。

``` shell
# release用ディレクトリを作成
mkdir release
# sample.exeをreleaseディレクトリへコピー
cp build/sample.exe release
# release用ディレクトリへ移動
cd release
# Qt由来のDLLを収集
windeployqt-qt6 sample.exe
# MinGW由来のDLLを収集
ldd sample.exe | grep /mingw64 | awk '{print $3}' | xargs -I {} cp {} .
```
