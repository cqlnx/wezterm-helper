# Wezterm-helper

Made this so i could have WezTerm open in a specific directory without having to navigate to it manually using cd.

Opening WezTerm from the Explorer address bar doesn't put you in the current directory like cmd does.

---

# Setup

Before building check `wezterm-helper/main.cpp`

```cpp
constexpr wchar_t kWezTermGui[] = L"directory to wezterm here";
```

and make sure you have the correct path to WezTerm in there.

---

# Do actually make it work

1. Copy the build into bin (make sure the bin folder exists first).

```cmd
copy "yourpath\wezterm-helper\x64\Release\wezterm-helper.exe" "C:\Users\youruser\bin\wezterm-helper.exe"
```

replace `yourpath` with the path where you have the helper executable built and `youruser` with your Windows username.

2. A quick test: open any folder and type this in the Explorer address bar

```cmd
C:\Users\youruser\bin\wezterm-helper.exe
```

WezTerm should open up in that directory. Replace `youruser` with your actual Windows user.

3. If that works and you want to be able to type something like `wez` into the Explorer address bar instead of the full path, you can add the bin directory to your user PATH.

First, copy the executable and give it whatever name you want:

```cmd
copy "C:\Users\youruser\bin\wezterm-helper.exe" "C:\Users\youruser\bin\wez.exe"
```

Then add `C:\Users\youruser\bin` to your user PATH:

1. Search for `Edit environment variables for your account` in Windows.
2. Select `Path` and click Edit.
3. Click New and add:

```text
C:\Users\youruser\bin
```

After that, restart Explorer and typing `wez` or `wez.exe` into the address bar should open WezTerm in that directory.

Replace `youruser` with your actual Windows username. You can also name the copied executable whatever you want, just use that name when launching it.