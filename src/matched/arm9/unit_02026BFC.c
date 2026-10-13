/*
 * unit:     yes
 * function: GAME_BEACON_GetLogFromWork
 * address:  0x02026BFC
 * packet:   pkt_0202685C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five unlabelled leaves between GAME_BEACON_ReceiveInfo and GAME_BEACON_GetNextNewLogIndex
 * (0x02026BFC..0x02026CA0), tu-verified: two ring-slot accessors, their
 * GAME_BEACON_Work tail-call wrappers, and the +0xBA8 count getter.
 *   GAME_BEACON_GetLogFromWork  slot n of the ring if n is below the s8 at +0xBAE
 *   GAME_BEACON_GetLog  GAME_BEACON_GetLogFromWork(GAME_BEACON_Work, n)
 *   GAME_BEACON_GetLogByReceiveNoFromWork  the slot n records back from the hi cursor, wrapped at 30;
 *                 the zero test on count - n is `c - n == 0` (a `subs`),
 *                 not `c == n` (a `cmp`)
 *   GAME_BEACON_GetLogByReceiveNo  GAME_BEACON_GetLogByReceiveNoFromWork(GAME_BEACON_Work, n)
 *   GAME_BEACON_GetReceiveCount  the +0xBA8 insert count
 * None has an lr save, so the integrator should seed all five starts.
 *
 * symbols:
 *   GAME_BEACON_Work  0x02146940  data
 */
#include "../include/Obj11840.h"
#include "../include/Obj17251.h"
typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *GAME_BEACON_Work;

void *GAME_BEACON_GetLogFromWork(u8 *base, int n)
{
    int c = ((struct Obj17251 *)base)->fBAE;
    if (c == 0 || c - n <= 0)
        return 0;
    return base + 0x64 + n * 0x60;
}

void *GAME_BEACON_GetLog(int n)
{
    return GAME_BEACON_GetLogFromWork(GAME_BEACON_Work, n);
}

void *GAME_BEACON_GetLogByReceiveNoFromWork(u8 *base, int n)
{
    u32 c = ((struct Obj11840 *)base)->fBA8;
    int j;
    if (c == 0 || c - n == 0)
        return 0;
    j = ((struct Obj11840 *)base)->fBAD - (int)(c - 1 - n);
    if ((j < 0 ? -j : j) >= 30)
        return 0;
    if (j < 0)
        j += 30;
    return base + 0x64 + j * 0x60;
}

void *GAME_BEACON_GetLogByReceiveNo(int n)
{
    return GAME_BEACON_GetLogByReceiveNoFromWork(GAME_BEACON_Work, n);
}

u32 GAME_BEACON_GetReceiveCount(void)
{
    return *(u32 *)(GAME_BEACON_Work + 0xBA8);
}
