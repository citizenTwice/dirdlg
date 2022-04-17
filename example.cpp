// #define UNICODE
// #define _UNICODE

#include "dirdlg.h"
#include <stdio.h>
#include <windows.h>

int main() {
  auto s = DIRDLG{}.get_dir(_T("."));
  if (s) {
#if defined(UNICODE)
    // assuming UTF-8 console, "chcp 65001"
    char tmp[4096]{};
    WideCharToMultiByte(CP_UTF8, 0, s, wcslen(s), tmp, sizeof(tmp), 0, 0);
    printf("You selected %s\n", tmp);
#else
    _tprintf(_T("You selected %s\n"), s);
#endif
  } else {
    _tprintf(_T("You didn't select a directory.\n"));
  }
  return 0;
}
