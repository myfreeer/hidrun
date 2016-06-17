#include <windows.h>

int WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow
        )
{
    STARTUPINFO si={sizeof(si)};
    PROCESS_INFORMATION pi;
    si.dwFlags=STARTF_USESHOWWINDOW;//指定wShowWindow成员有效
    si.wShowWindow=TRUE;//此成员设为TRUE的话则显示新建进程的主窗口
    BOOL bRet=CreateProcess(
    NULL,//不在此指定可执行文件的文件名
    lpCmdLine,//命令行参数
    NULL,//默认进程安全性
    NULL,//默认进程安全性
    FALSE,//指定当前进程内句柄不可以被子进程继承
    CREATE_NO_WINDOW,//为新进程创建一个新的控制台窗口
    NULL,//使用本进程的环境变量
    NULL,//使用本进程的驱动器和目录
    &si,
    &pi);
    if(bRet)
    {
        WaitForSingleObject(pi.hProcess, INFINITE);
        // Get the exit code.
        result = GetExitCodeProcess(pi.hProcess, &exitCode);
        //不使用的句柄最好关掉
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
        return result;
    }
    return 0;
}
