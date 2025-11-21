// #include <stdio.h>
// #include <windows.h>
// #include "platform_thread.h"
// #include "windows_impl.h"

// typedef struct {
//     PlatformThreadAPI threadAPI; // we might want to spin up another thread from inside the thread
//     const char* message;
// } MyThreadParams;

// void MyThreadFunction(void* params) {
//     MyThreadParams* threadParams = (MyThreadParams*)params;
//     const char* message = (const char*)threadParams->message;
//     PlatformThreadAPI threadAPI = threadParams->threadAPI;
//     printf("Thread started with message: %s\n", message);
//     fflush(stdout);
//     for (int i = 0; i < 5; ++i) {
//         printf("Thread %d says: %d\n", GetCurrentThreadId() ,i);
//         fflush(stdout);
//         threadAPI.sleep(500); // Simulate some work
//     }
//     return;
// }

// // for simplicity all memory is allocated on the stack!
// int main()
// {
//     // Link to the Win32 API functions
//     PlatformThreadAPI threadAPI;
//     threadAPI.createPlatformThread = &win32CreatePlatformThread;
//     threadAPI.joinPlatformThread= &win32JoinPlatformThread;
//     threadAPI.closePlatformThreadHandle= &win32ClosePlatformThreadHandle;
//     threadAPI.sleep = &win32Sleep;

//     // Create the thread runtime parameters
//     const char* message = "Hello from thread!";
//     MyThreadParams params;
//     params.threadAPI = threadAPI;
//     params.message = message;
    
//     // Define the thread data including a pointer to the function
//     PlatformThreadData threadData; // Make the thread on the stack to avoid memory management
//     threadData.threadFunction = &MyThreadFunction;
//     threadData.arguments = &params;

//     // Create the platform thread and execute it
//     PlatformThread thread = threadAPI.createPlatformThread(threadData, (PlatformThreadAttributes){CREATE_THREAD_AND_EXECUTE});
      
//     // Block the main method to wait for the new thread to finish
//     threadAPI.joinPlatformThread(thread);
//     // Once finished, close the thread handle
//     threadAPI.closePlatformThreadHandle(thread);
//     return 0;
// }