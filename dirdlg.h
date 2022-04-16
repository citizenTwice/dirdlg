/*

DIRDLG - coded by Luigi Galli feedback@THLG.NL

MIT License

Copyright (c) 2022 Luigi Galli

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once

//#define UNICODE
//#define _UNICODE

#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <windows.h>
#include <shlwapi.h>
#include <tchar.h>
#include <pathcch.h>
#include <stringapiset.h>

#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "pathcch.lib")

#if !defined(UNICODE)
#define str    std::string
#define to_str std::to_string
#else 
#define str    std::wstring
#define to_str std::to_wstring
#define printf wprintf
#define _strdup _wcsdup
#define strlen wcslen
#define strcmp wcscmp
#endif

#define tsizeof(x) (sizeof(x) / sizeof(_TCHAR))


//#pragma pack(show)
#pragma pack(push, 4)  
static struct _new_dir_prompt_template {
  struct {
    WORD      dlgVer{ 1 };
    WORD      signature{ 0xFFFF };
    DWORD     helpID{ 1 };
    DWORD     exStyle{ 0 };
    DWORD     style{ DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | DS_CENTER | WS_POPUP | WS_CAPTION | WS_SYSMENU };
    WORD      cDlgItems{ 3 };
    short     x{ 0 };
    short     y{ 0 };
    short     cx{ 185 };
    short     cy{ 35 };
    WORD      menu{ 0x000 };
    WORD      windowClass{ 0x000 };;
    WCHAR     title[19]{ L"New directory name" };
    WORD      pointsize{ 8 };
    WORD      weight{ 400 };
    BYTE      italic{ 0 };
    BYTE      charset{ 0 };
    WCHAR     face[13]{ L"MS Shell Dlg" };
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ ES_AUTOHSCROLL | ES_LEFT | WS_GROUP | WS_TABSTOP | WS_CHILD | WS_BORDER | WS_VISIBLE | WS_TABSTOP };
      short     x{ 1 };
      short     y{ 3 };
      short     cx{ 181 };
      short     cy{ 14 };
      DWORD     id{ 1004 };
      WORD      windowClass[2]{ 0xFFFF, 0x081 };
      WCHAR     title[5]{ L"TEST" };
      WORD      extraCount{ 0x000 };
    } e1;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ BS_DEFPUSHBUTTON | WS_GROUP | WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_TABSTOP };
      short     x{ 75 };
      short     y{ 19 };
      short     cx{ 50 };
      short     cy{ 14 };
      DWORD     id{ IDOK };
      WORD      windowClass[2]{ 0xFFFF, 0x080 };
      WCHAR     title[3]{ L"Ok" };
      WORD      extraCount{ 0x000 };
    } b1;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ BS_PUSHBUTTON | WS_GROUP | WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_TABSTOP };
      short     x{ 133 };
      short     y{ 19 };
      short     cx{ 50 };
      short     cy{ 14 };
      DWORD     id{ IDCANCEL };
      WORD      windowClass[2]{ 0xFFFF, 0x080 };
      WCHAR     title[7]{ L"Cancel" };
      WORD      extraCount{ 0x000 };
    } b2;
  } dlg;
  WORD dummy{ 0x0 };
} new_dir_prompt_template;
#pragma pack(pop)
//#pragma pack(show)

#pragma pack(push, 4)  
static struct _dir_dlg_template {
  struct {
    WORD      dlgVer{ 1 };
    WORD      signature{ 0xFFFF };
    DWORD     helpID{ 1 };
    DWORD     exStyle{ WS_EX_CONTROLPARENT };
    DWORD     style{ DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | DS_CENTER | WS_POPUP | WS_CAPTION | WS_SYSMENU };
    WORD      cDlgItems{ 9 };
    short     x{ 0 };
    short     y{ 0 };
    short     cx{ 257 };
    short     cy{ 207 };
    WORD      menu{ 0x000 };
    WORD      windowClass{ 0x000 };;
    WCHAR     title[20]{ L"Directory selection" };
    WORD      pointsize{ 8 };
    WORD      weight{ 400 };
    BYTE      italic{ 0 };
    BYTE      charset{ 0 };
    // WCHAR     face[13]{ L"MS Shell Dlg" };
    WCHAR     face[9]{ L"Segoe UI" };
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ SS_LEFT | WS_GROUP | WS_CHILD | WS_VISIBLE };
      short     x{ 7 };
      short     y{ 7 };
      short     cx{ 206 };
      short     cy{ 8 };
      DWORD     id{ 1009 };
      WORD      windowClass[2]{ 0xFFFF, 0x082 };
      WCHAR     title[5]{ L"TEST" };
      WORD      extraCount{ 0x000 };
    } t1;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ LBS_WANTKEYBOARDINPUT };
      DWORD     style{ LBS_SORT | LBS_WANTKEYBOARDINPUT | LBS_NOINTEGRALHEIGHT | LBS_HASSTRINGS |
        WS_BORDER | WS_VSCROLL | WS_GROUP | WS_CHILD | WS_VISIBLE | WS_TABSTOP };
      short     x{ 7 };
      short     y{ 17 };
      short     cx{ 243 };
      short     cy{ 132 };
      DWORD     id{ 1006 };
      WORD      windowClass[2]{ 0xFFFF, 0x083 };
      WCHAR     title[3]{ L"Ok" };
      WORD      extraCount{ 0x000 };
    } l1;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ SS_LEFT | WS_GROUP | WS_CHILD | WS_VISIBLE };
      short     x{ 8 };
      short     y{ 153 };
      short     cx{ 16 };
      short     cy{ 8 };
      DWORD     id{ 1008 };
      WORD      windowClass[2]{ 0xFFFF, 0x082 };
      WCHAR     title[6]{ L"&Path" };
      WORD      extraCount{ 0x000 };
    } t2;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ ES_AUTOHSCROLL | ES_LEFT | WS_GROUP | WS_TABSTOP | WS_CHILD | WS_BORDER | WS_VISIBLE | WS_TABSTOP };
      short     x{ 38 };
      short     y{ 152 };
      short     cx{ 212 };
      short     cy{ 12 };
      DWORD     id{ 1005 };
      WORD      windowClass[2]{ 0xFFFF, 0x081 };
      WCHAR     title[5]{ L"TEST" };
      WORD      extraCount{ 0x000 };
    } e1;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ SS_LEFT | WS_GROUP | WS_CHILD | WS_VISIBLE };
      short     x{ 8 };
      short     y{ 171 };
      short     cx{ 21 };
      short     cy{ 8 };
      DWORD     id{ 1007 };
      WORD      windowClass[2]{ 0xFFFF, 0x082 };
      WCHAR     title[8]{ L"&Drives" };
      WORD      extraCount{ 0x000 };
    } t3;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ CBS_DROPDOWNLIST | WS_VSCROLL | WS_GROUP | WS_TABSTOP | WS_CHILD | WS_VISIBLE };
      short     x{ 38 };
      short     y{ 169 };
      short     cx{ 212 };
      short     cy{ 209 };
      DWORD     id{ 1003 };
      WCHAR     windowClass[9]{ L"COMBOBOX" };
      WCHAR     title[1]{ 0x00 };
      WORD      extraCount{ 0x000 };
    } c1;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ BS_PUSHBUTTON | WS_GROUP | WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_TABSTOP };
      short     x{ 140 };
      short     y{ 186 };
      short     cx{ 50 };
      short     cy{ 14 };
      DWORD     id{ 1002 };
      WORD      windowClass[2]{ 0xFFFF, 0x080 };
      WCHAR     title[8]{ L"&Select" };
      WORD      extraCount{ 0x000 };
    } b1;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ BS_PUSHBUTTON | WS_GROUP | WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_TABSTOP };
      short     x{ 200 };
      short     y{ 186 };
      short     cx{ 50 };
      short     cy{ 14 };
      DWORD     id{ 1001 };
      WORD      windowClass[2]{ 0xFFFF, 0x080 };
      WCHAR     title[7]{ L"Cancel" };
      WORD      extraCount{ 0x000 };
    } b2;
    struct {
      DWORD     helpID{ 11 };
      DWORD     exStyle{ 0 };
      DWORD     style{ BS_PUSHBUTTON | WS_GROUP | WS_TABSTOP | WS_CHILD | WS_VISIBLE | WS_TABSTOP };
      short     x{ 227 };
      short     y{ 6 };
      short     cx{ 23 };
      short     cy{ 11 };
      DWORD     id{ 1010 };
      WORD      windowClass[2]{ 0xFFFF, 0x080 };
      WCHAR     title[5]{ L"&New" };
      WORD      extraCount{ 0x000 };
    } b3;
  } dlg;
  WORD dummy{ 0x0 };
} dir_dlg_template;
#pragma pack(pop)

struct DIRDLG {
  static const  int    RET_SELECTED = 1;
  static const  int    RET_CANCEL = 2;
  static const  int    RET_ERROR = -1;

  _TCHAR        selected_dir[MAX_PATH]{};
  _TCHAR        new_dir[MAX_PATH]{};
  const _TCHAR* title{ _T("Select a directory") };
  const _TCHAR* initial_path{ _T(".") };
  bool          error{ false };
  DWORD         error_code{ 0 };

  struct DIRLIST {
    str                  parent_path{};
    str                  name{};
    std::vector<str>     subdirs{};
    bool                  error{ false };
    UINT                  error_code{ 0 };

    str tostr() {
      str retval{ _T("{ ") };
      if (error) {
        retval += _T("ERROR : CODE(") + to_str(error_code) + _T(")");
      } else {
        retval += _T("\n");
        retval += _T(" NAME:   ") + name + _T("\n");
        retval += _T(" PARENT: ") + parent_path + _T("\n");
        retval += _T(" SUBDIRS: [\n");
        for (const auto& s : subdirs) {
          retval += _T("   ") + s + _T("\n");
        }
        retval += _T(" ]\n");
      }
      retval += _T("}");
      return retval;
    }
  };

  static bool is_dir(const _TCHAR* path) {
    auto a = GetFileAttributes(path);
    return (a != INVALID_FILE_ATTRIBUTES) && (a & FILE_ATTRIBUTE_DIRECTORY);
  }

  static INT_PTR CALLBACK dir_prompt_dlgproc(
    HWND hdlg,
    UINT umsg,
    WPARAM wparm,
    LPARAM lparm
  ) {
    DIRDLG* _this{ nullptr };
    if (umsg == WM_INITDIALOG) {
      SetWindowLongPtr(
        hdlg,
        DWLP_USER,
        LONG_PTR(lparm)
      );
      _this = (DIRDLG*)lparm;
      return 0;
    } else {
      _this = (DIRDLG*)GetWindowLongPtr(
        hdlg,
        DWLP_USER);
    }
    if (umsg == WM_SHOWWINDOW) {
      // SetWindowText(hWin, g_title);
      HWND edi = GetDlgItem(hdlg, 1004);
      SetFocus(edi);
      SendMessage(edi, EM_SETSEL, 2000, 2000);
      SendMessage(edi, EM_SCROLLCARET, 0, 0);
      return 0;
    } else if (umsg == WM_COMMAND) {
      if (wparm == IDOK) {
        GetDlgItemText(hdlg, 1004, _this->new_dir, tsizeof(DIRDLG::new_dir) - 1);        
        EndDialog(hdlg, 1);
        return 1;
      } else if (wparm == IDCANCEL) {
        EndDialog(hdlg, 0);
        return 1;
      }
    }
    return 0;
  }

  static DIRLIST list(const _TCHAR* path) {
    DIRLIST           retval;
    str               dirp = path;
    WIN32_FIND_DATA   wfd;
    std::vector<str>  subs;
    // sanity check
    if (!is_dir(path)) {
      retval.error = true;
      return retval;
    }
    {
      // get basename
      auto tmp = _strdup(path);
      PathStripPath(tmp);
      retval.name = tmp;
      free(tmp);
    }
    {
      // get parent path
      auto tmp = _strdup(path);
      if (PathRemoveFileSpec(tmp)) {
        retval.parent_path = tmp;
      };
      free(tmp);
    }
    // get subdirectories
    HANDLE hfind{};
    if (dirp[dirp.size() - 1] == '\\') {
      hfind = FindFirstFile((dirp + _T("*.*")).c_str(), &wfd);
    } else {
      hfind = FindFirstFile((dirp + _T("\\*.*")).c_str(), &wfd);
    }    
    if (INVALID_HANDLE_VALUE != hfind) {
      do {
        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
          if (strcmp(_T("."), wfd.cFileName)) {
            retval.subdirs.push_back(str{ wfd.cFileName });
          }
        }
      } while (FindNextFile(hfind, &wfd));
      FindClose(hfind);
    } else {
      retval.error = true;
      retval.error_code = GetLastError();
    }
    return retval;
  }

  static bool update_dialog(HWND hdlg, const _TCHAR* path) {
    SendMessage(GetDlgItem(hdlg, 1009), WM_SETTEXT, 0, LPARAM(path));
    SetWindowText(GetDlgItem(hdlg, 1005), path);
    SendMessage(GetDlgItem(hdlg, 1006), LB_RESETCONTENT, 0, 0);
    auto lst = list(path);
    // if (lst.error || lst.subdirs.empty()) {
    if (lst.error || lst.subdirs.size() < 1) {
      return false;
    }
    for (const auto& d : lst.subdirs) {
      auto t = str{ _T("[") } + d + _T("]");
      SendMessage(GetDlgItem(hdlg, 1006), LB_ADDSTRING, 0, LPARAM(t.c_str()));
    }
    SendMessage(GetDlgItem(hdlg, 1006), LB_SETCURSEL, WPARAM(1), 0);
    auto dn = PathGetDriveNumber(path);
    if (dn >= 0) {
      TCHAR drv[8]{ _T('A'),_T(':'),_T('\\'),0 };
      drv[0] += dn;
      // SendMessage(GetDlgItem(hdlg, 1003), CB_SETCURSEL, WPARAM(dn), 0);
    }
    return true;
  }

  static std::vector<str> get_drive_letters() {
    std::vector<str> retval{};
    _TCHAR buf[4096]{};
    GetLogicalDriveStrings(tsizeof(buf) - 1, buf);
    for (UINT i = 0; i < ((tsizeof(buf) - 1)); i++) {
      if (isalpha(buf[i])) {
        retval.push_back(&(buf[i]));
      }
    }
    return retval;
  }

  static bool go_to_parent(HWND hdlg, str& path) {
    auto bkp = path;
    auto t1 = _strdup(path.c_str());
    PathRemoveBackslash(t1);
    PathRemoveFileSpec(t1);
    path = t1;
    free(t1);
    if (!(update_dialog(hdlg, path.c_str()))) {
      path = bkp;
      return update_dialog(hdlg, path.c_str());
    } else {
      return true;
    }
  }


  bool go_to_root(HWND hdlg, str& path) {
    str bkp = path;
#if !defined(UNICODE)
    WCHAR wbuf[MAX_PATH];
    if (!MultiByteToWideChar(CP_ACP, 0, path.c_str(), -1, wbuf, MAX_PATH)) {
      return false;
    }
    bool ok = PathCchStripToRoot(wbuf, wcslen(wbuf)) == S_OK;
    if (!ok) {
      // nothing to do, probably already at root dir
      return true;
    }
    char mbuf[MAX_PATH];
    if (!WideCharToMultiByte(CP_ACP, 0, wbuf, -1, mbuf, MAX_PATH, NULL, NULL)) {
      return false;
    }
    path = mbuf;
#else
    auto wtmp = _wcsdup(path.c_str());
    auto ok = PathCchStripToRoot(wtmp, wcslen(wtmp)) == S_OK;
    if (!ok) {
      // nothing to do, probably already at root dir
      free(wtmp);
      return true;
    }
    path = wtmp;
    free(wtmp);
#endif
    auto retval{ false };
    if (!(update_dialog(hdlg, path.c_str()))) {
      path = bkp;
      retval = update_dialog(hdlg, path.c_str());
    } else {
      retval = true;
    }
    return retval;
  }

  static INT_PTR dir_sel_dlgproc(
    HWND    hdlg,
    UINT    msg,
    WPARAM  wparm,
    LPARAM  lparm
  ) {
    INT_PTR retval = 0;
    static const _TCHAR* path = nullptr;
    static str           current_path{};
    static bool          edit_focus{ false };
    DIRDLG* _this{ nullptr };
    if (msg == WM_INITDIALOG) {
      SetWindowLongPtr(
        hdlg,
        DWLP_USER,
        LONG_PTR(lparm)
      );
      _this = (DIRDLG*)lparm;
      SetWindowText(hdlg, _this->title);
      for (const auto& d : get_drive_letters()) {
        SendMessage(GetDlgItem(hdlg, 1003), CB_ADDSTRING, 0, LPARAM(d.c_str()));
      }
      auto path = (const _TCHAR*)(_this->initial_path);
      if (is_dir(path)) {
        current_path = path;
      } else {
        _TCHAR tmp[MAX_PATH];
        GetCurrentDirectory(tsizeof(tmp), tmp);
        current_path = tmp;
      }
      if (!update_dialog(hdlg, current_path.c_str())) {
        _this->error = true;
        EndDialog(hdlg, DIRDLG::RET_ERROR);
      }
      SHAutoComplete(GetDlgItem(hdlg, 1005), SHACF_FILESYS_DIRS);
      return 1;
    } else {
      _this = (DIRDLG*)GetWindowLongPtr(
        hdlg,
        DWLP_USER
      );
    }
    if (msg == WM_VKEYTOITEM) {
      if (LOWORD(wparm) == VK_BACK) {
        if (!go_to_parent(hdlg, current_path)) {
          _this->error = true;
          EndDialog(hdlg, DIRDLG::RET_ERROR);
        }
        return -2;
      } else if (LOWORD(wparm) == VK_OEM_5) {
        if (!_this->go_to_root(hdlg, current_path)) {
          _this->error = true;
          EndDialog(hdlg, DIRDLG::RET_ERROR);
        }
        return -2;
      } else if (LOWORD(wparm) == VK_F1) {
        SetFocus(GetDlgItem(hdlg, 1003));
        return -2;
      } else {
        return -1;
      }
    } else if (msg == WM_CLOSE) {
      EndDialog(hdlg, DIRDLG::RET_CANCEL);
      retval = 1;
    } else if (msg == WM_COMMAND) {
      if ((LOWORD(wparm) == 1010) && (HIWORD(wparm) == BN_CLICKED)) {
        auto r = DialogBoxIndirectParamW(GetModuleHandle(0),
          (LPCDLGTEMPLATEW)(&new_dir_prompt_template),
          0, DLGPROC(dir_prompt_dlgproc), LPARAM(_this));
        if (r < 0) {
          return 1;
        }
        if (r) {
          auto tmpd = current_path + _T("\\") + _this->new_dir;
          if (!CreateDirectory(tmpd.c_str(), 0)) {
            MessageBox(hdlg, _T("Error creating directory"), (str{ _T("Error code: ") } + to_str(GetLastError())).c_str(), MB_ICONSTOP);
          } else if (is_dir(tmpd.c_str())) {
            current_path = tmpd;
            update_dialog(hdlg, current_path.c_str());
          }
        } else {
        }
        return 1;
      } else if ((LOWORD(wparm) == 1002) && (HIWORD(wparm) == BN_CLICKED)) {
        EndDialog(hdlg, DIRDLG::RET_SELECTED);
        StrNCpy(_this->selected_dir, current_path.c_str(), tsizeof(DIRDLG::selected_dir));
        return 1;
      } else if (((wparm == 2) && (lparm == 0)) ||
        ((LOWORD(wparm) == 1001) && (HIWORD(wparm) == BN_CLICKED))
      ) {
        EndDialog(hdlg, DIRDLG::RET_CANCEL);
        return 1;
      } else if (LOWORD(wparm) == 1005) {
        // edit control
        if (HIWORD(wparm) == EN_SETFOCUS) {
          edit_focus = true;
          SHAutoComplete(GetDlgItem(hdlg, 1005), SHACF_FILESYS_DIRS);
        } else if (HIWORD(wparm) == EN_KILLFOCUS) {
          edit_focus = false;
        }
      } else if ((LOWORD(wparm) == 1003) && (HIWORD(wparm) == CBN_SELENDOK)) {
        auto ord = SendMessage(GetDlgItem(hdlg, 1003), CB_GETCURSEL, 0, 0);
        if (ord != CB_ERR) {
          INT sz = (UINT)SendMessage(GetDlgItem(hdlg, 1003), CB_GETLBTEXTLEN, WPARAM(ord), 0);
          if (sz > 0) {
            auto buf = new _TCHAR[sz + 1];
            auto r = SendMessage(GetDlgItem(hdlg, 1003), CB_GETLBTEXT, WPARAM(ord), LPARAM(buf));
            if (r != CB_ERR) {
              current_path = buf;
              update_dialog(hdlg, buf);
            }
            delete buf;
          }
        }
      } else if (wparm == IDOK) {
        if (edit_focus) {
          auto bkp = current_path;
          _TCHAR tbuf[1024];
          GetWindowText(GetDlgItem(hdlg, 1005), tbuf, tsizeof(tbuf));
          bool ok_dir{ false };
          if (is_dir(tbuf)) {
            current_path = tbuf;
            if (PathIsRelative(current_path.c_str())) {
              _TCHAR tmp1[MAX_PATH];
              _TCHAR* dummy;
              if (GetFullPathName(current_path.c_str(), tsizeof(tmp1), tmp1, &dummy)) {
                ok_dir = true;
                current_path = tmp1;
              } else {
                ok_dir = false;
              }
            } else {
              ok_dir = true;
            }
            if (ok_dir) {
              if (update_dialog(hdlg, current_path.c_str())) {
                SetFocus(GetDlgItem(hdlg, 1006));
              } else {
                current_path = bkp;
                update_dialog(hdlg, current_path.c_str());
              }              
            }
          }
        } else {
          _TCHAR namebuf[MAX_PATH];
          if (DlgDirSelectEx(hdlg, namebuf, MAX_PATH,
            1006)) {
            if (strcmp(_T("..\\"), namebuf) == 0) {
              if (!go_to_parent(hdlg, current_path)) {
                EndDialog(hdlg, DIRDLG::RET_CANCEL);
              }
              return 1;
            } else {
              auto new_path = current_path = current_path +
                ((current_path[current_path.length() - 1] != _T('\\')) ? _T("\\") : _T("")) +
                namebuf;
              if (!update_dialog(hdlg, new_path.c_str())) {
                if (!update_dialog(hdlg, current_path.c_str())) {
                  EndDialog(hdlg, DIRDLG::RET_CANCEL);
                }
              } else {
                current_path = new_path;
              }
              return 1;
            }
          }
        }
      }
      return 1;
    }
    return 0;
  }

  /**
  * Directory selection dialog.
  * @param initial_path = initial directory path on opening the dialog.
  *
  * @return: nullptr = user did not select anything / pressed cancel
  *          char*   = null-terminated string represnting the path that was selected.
  */
  const _TCHAR* get_dir(const _TCHAR* _initial_path) {
    _TCHAR tmp1[MAX_PATH]{};
    if (PathIsRelative(_initial_path)) {
      _TCHAR* dummy;
      GetFullPathName(_initial_path, tsizeof(tmp1), tmp1, &dummy);
      this->initial_path = tmp1;
    } else {
      this->initial_path = _initial_path;
    }
    auto r = DialogBoxIndirectParamW(GetModuleHandle(0),
      (LPCDLGTEMPLATEW)(&dir_dlg_template),
      0, DLGPROC(dir_sel_dlgproc), LPARAM(this)
    );
    if (r < 0) {
      return nullptr;
    } else if (r == DIRDLG::RET_SELECTED) {
      return DIRDLG::selected_dir;
    } else {
      return nullptr;
    }
  }

  DIRDLG() = default;

  DIRDLG(const _TCHAR* title) {
    this->title = title;
  }
};
