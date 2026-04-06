# Which-MSVC

GNU `which` 的 Windows/MSVC 友好构建版本。

本仓库保留了原始 C 源码，并增加了 Visual Studio 工程，方便你在 Windows 上直接构建 `which`。

## 程序作用

`which` 用于打印在 `PATH` 中找到的命令的完整路径。

与非常老的 `which` 变体相比，本代码库保持了 GNU 行为，包括：

- `--all` / `-a`
- `--read-alias` / `-i`
- `--read-functions`

## 构建（Visual Studio）

### 方式一：IDE

1. 打开 `Which-MSVC.slnx`。
2. 选择配置（`Debug|x64` 或 `Release|x64`）。
3. 构建项目 `Which-MSVC`。

### 方式二：命令行

在 Developer PowerShell / Developer Command Prompt 中运行：

```powershell
msbuild .\Which-MSVC\Which-MSVC.vcxproj /t:Build /p:Configuration=Debug /p:Platform=x64
```

Release 构建：

```powershell
msbuild .\Which-MSVC\Which-MSVC.vcxproj /t:Build /p:Configuration=Release /p:Platform=x64
```

## 快速验证

构建完成后运行：

```powershell
.\x64\Debug\which.exe --version
.\x64\Debug\which.exe cmd
.\x64\Debug\which.exe where
```

## 使用方式

1. 将 `which.exe` 移动到你希望存放的目录。
2. 将该目录加入系统环境变量 `PATH`。
3. 重启终端。
4. 运行 `which`。

## 仓库结构

- `which.c`：主程序与参数处理。
- `bash.c`、`tilde.c`：路径/波浪线/函数查找辅助逻辑。
- `getopt.c`、`getopt1.c`：GNU getopt 实现。
- `sys.h`：平台兼容宏定义。
- `win_compat.c`、`win_compat.h`：Windows 辅助函数。
- `Which-MSVC/Which-MSVC.vcxproj`：Visual Studio 工程文件。

## 说明

- 本项目面向 Windows，VS 工程保持 `CharacterSet=Unicode`。
- 在需要处理 `char *` 逻辑时，兼容代码使用 Win32 的 `A` 系列 API。

## 许可证

完整许可证文本见 `COPYING`。
