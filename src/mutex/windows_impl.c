#include "windows_impl.h"

void win32BeginTicket(TicketMutex *mutex) {
    long long ticket = AtomicAddU64(&mutex->ticket, 1);
    while(ticket != mutex->serving) {_mm_pause();}
}
void win32EndTicket(TicketMutex *mutex) {
    AtomicAddU64(&mutex->serving, 1);
}