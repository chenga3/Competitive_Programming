## Compiling <bits/stdc++.h>

### On Mac

By default, MacOS uses Clang g++ compiler rather than GCC.

#### Recommended: Install GCC

```
brew install gcc
```

By default the g++ compiler will be located at `/opt/homebrew/bin/g++-11`. Make sure to adjust the compiler in the build task and C/C++ configuration files if using VSCode.

#### Not recommended: Download `stdc++.h` file

To compile `<bits/stdc++.h>` using the Clang compiler:

- Create a `bits` folder in `/usr/local/include`:

```
sudo mkdir -p /usr/local/include/bits
```

- Create the `stdc++.h` header file in that folder and copy in the contents from [here](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/precompiled/stdc%2B%2B.h).

```
sudo touch /usr/local/include/bits/stdc++.h
```
