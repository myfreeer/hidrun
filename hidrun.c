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
    si.dwFlags=STARTF_USESHOWWINDOW;//ָ��wShowWindow��Ա��Ч
    si.wShowWindow=TRUE;//�˳�Ա��ΪTRUE�Ļ�����ʾ�½����̵�������
    BOOL bRet=CreateProcess(
    NULL,//���ڴ�ָ����ִ���ļ����ļ���
    lpCmdLine,//�����в���
    NULL,//Ĭ�Ͻ��̰�ȫ��
    NULL,//Ĭ�Ͻ��̰�ȫ��
    FALSE,//ָ����ǰ�����ھ�������Ա��ӽ��̼̳�
    CREATE_NO_WINDOW,//Ϊ�½��̴���һ���µĿ���̨����
    NULL,//ʹ�ñ����̵Ļ�������
    NULL,//ʹ�ñ����̵���������Ŀ¼
    &si,
    &pi);
    if(bRet)
    {
        //��ʹ�õľ����ùص�
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);\
    }
    return 0;
}
