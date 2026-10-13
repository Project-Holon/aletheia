/*
 * function: GAMESYSTEM_LeakHeapPenalty
 * address:  0x02011D40
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_AddMainTask   0x020056A0  thumb
 *   GAMESYSTEM_ReadTimerTwice  0x02011D34  thumb
 *   _GameSystemGlobal     0x02146248  data
 *
 * Allocates 0x7F bytes off heap 0 through GFL_USE_AddMainTask.c's allocator
 * wrapper, tagged with GAMESYSTEM_ReadTimerTwice's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * _GameSystemGlobal's +4 counter. See unit_02011D28.c's header for the sibling
 * GAMESYSTEM_LeakHeapPenaltyRepeat and the documented near miss on this increment.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GAMESYSTEM_LeakHeapPenalty.c \
 *       --func GAMESYSTEM_LeakHeapPenalty --addr 0x02011D40 --cc 1.1p1 --thumb
 */

#include "../include/G_G02146248.h"

typedef unsigned int u32;

extern void *GFL_USE_AddMainTask(u32 a, u32 b, u32 c);
extern void  GAMESYSTEM_ReadTimerTwice(void);
extern struct G02146248 _GameSystemGlobal;

void GAMESYSTEM_LeakHeapPenalty(void)
{
    GFL_USE_AddMainTask((u32)GAMESYSTEM_ReadTimerTwice, 0, 0x7f);
    _GameSystemGlobal.unk04 += 1;
}
