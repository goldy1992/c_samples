#pragma once

typedef long long uint64_t;

typedef struct 
{
    uint64_t volatile ticket;
    uint64_t volatile serving;
} TicketMutex;

struct PlatformInstrisicsApi
{
    void (*beginTicket)(TicketMutex *mutex);
    void (*endTicket)(TicketMutex *mutex);
};