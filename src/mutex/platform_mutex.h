#pragma once

// typedef void *PlatformThreadHandle;
// typedef void (*PlatformThreadFunction)(void *);

// #define CREATE_THREAD_SUSPENDED 1 
// #define CREATE_THREAD_AND_EXECUTE 0


// typedef struct {
//     unsigned int startSuspended;
// } PlatformThreadAttributes;

// // in the thread data we need to also specify a reference to the function so that the trampoline method can call the thread function.
// typedef struct {
//     PlatformThreadFunction threadFunction;
//     void *arguments;
// } PlatformThreadData;

// typedef struct
// {
//     PlatformThreadHandle handle; // Platform-specific thread handle
//     PlatformThreadData data;
// } PlatformThread;

// // API to be extended for more complex threading operations
// typedef struct
// {
//     PlatformThread (*createPlatformThread)(PlatformThreadData threadData, PlatformThreadAttributes threadAttributes);
//     void (*joinPlatformThread)(PlatformThread platformThread);
//     void (*closePlatformThreadHandle)(PlatformThread platformThread);
//     void (*sleep)(unsigned int milliseconds);
// } PlatformThreadAPI;