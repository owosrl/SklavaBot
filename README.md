# SklavaBot

Telegram Bot in C++ with TgBot

**📜 Command**:
- `/start` : _starts bot_;
- `/help` : _print help message with command list_;
- `/info` : _print informations about Compile System_;
- `/ocr` : _Optical Character Recognition with Tesseract_;
- `/metar <ICAO Code>` : _get METAR informations_;


**Requirements**:
- CMake
- Ninja
- GCC or Clang
- CURL
- Boost Lib
- OpenSSL
- JsonCpp
- Tesseract
- Leptonica


**Compilation**
```bash
./build.sh
# or
cmake -G Ninja . && ninja build
```


_GPLv3 License_
