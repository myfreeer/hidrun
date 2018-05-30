#define WIN32_LEAN_AND_MEAN
#include "winmain.h"
#define UNUSED __attribute__((unused))

int WinMain(HINSTANCE UNUSED hInstance, HINSTANCE UNUSED hPrevInstance,
            LPSTR lpCmdLine, int UNUSED nCmdShow) {
    STARTUPINFO si = {0};
    si.cb = sizeof(STARTUPINFO);
    PROCESS_INFORMATION pi = {0};
    si.dwFlags = STARTF_USESHOWWINDOW; //指定wShowWindow成员有效
    si.wShowWindow = FALSE; //此成员设为TRUE的话则显示新建进程的主窗口
    BOOL bRet = CreateProcess(NULL, lpCmdLine, NULL, NULL, FALSE,
                              CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    if (bRet) {
        //不使用的句柄最好关掉
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
    return 0;
}
