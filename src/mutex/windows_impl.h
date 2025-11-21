#pragma once

// #include <windows.h>
#include <intrin.h>
#include "platform_mutex.h"

void win32BeginTicket(TicketMutex *mutex);
void win32EndTicket(TicketMutex *mutex);

inline long AtomicCompareExchangeLong(long volatile *Value, long New, long Expected)
{
    long Result = _InterlockedCompareExchange((long volatile *)Value, New, Expected);
    
    return(Result);
}
inline long long AtomicExchangeU64(long long volatile *Value, long long New)
{
    long long Result = _InterlockedExchange64((__int64 volatile *)Value, New);
    
    return(Result);
}
inline long long AtomicAddU64(long long volatile *Value, long long Addend)
{
    // NOTE(casey): Returns the original value _prior_ to adding
    long long Result = _InterlockedExchangeAdd64((__int64 volatile *)Value, Addend);
    
    return(Result);
}