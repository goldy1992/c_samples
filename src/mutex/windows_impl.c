#include "windows_impl.h"
typedef struct {
    void (*function)(void *);
    void *argument;
} ThreadParams;

DWORD WINAPI ThreadStarter(LPVOID lpParam)
{
    PlatformThreadData*params = (PlatformThreadData*)lpParam;
    params->threadFunction(params->arguments);
    return 0;
}


PlatformThread win32CreatePlatformThread(PlatformThreadData threadData, PlatformThreadAttributes attributes)
{
    HANDLE hThread;
    DWORD dwThreadId;

    // Create the new thread
    hThread = CreateThread(
        NULL,                   // Default security attributes
        0,                      // Default stack size
        ThreadStarter,       // Thread function
        &threadData,                   // No parameter to pass to the thread function
        attributes.startSuspended,                      // Default creation flags
        &dwThreadId             // Receives the thread identifier
    );

    PlatformThread toReurn;
    toReurn.handle = hThread;
    toReurn.data= threadData;
    return toReurn;
}

void win32JoinPlatformThread(PlatformThread platformThread) {
    WaitForSingleObject(platformThread.handle, INFINITE);
}

void win32ClosePlatformThreadHandle(PlatformThread platformThread) {
    CloseHandle(platformThread.handle);
}

void win32Sleep(unsigned int milliseconds)
{
    Sleep(milliseconds);
}