/*
 * function: GAMESYSTEM_ApplyTamperPenaltyRepeat
 * address:  0x02011D7C
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
 *   GAMESYSTEM_RandTwice  0x02011D34  thumb
 *   _GameSystemGlobal     0x02146248  data
 *
 * Allocates 0x7F bytes off heap 0 through GFL_USE_AddMainTask.c's allocator
 * wrapper, tagged with GAMESYSTEM_RandTwice's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * _GameSystemGlobal's +4 counter. See unit_02011D28.c's header for the sibling
 * GAMESYSTEM_LeakHeapPenalty (src/matched/GAMESYSTEM_LeakHeapPenalty.c, converted to EXACT
 * alongside this one) and the formerly-documented near miss on this
 * increment: the `struct.unk04 += 1` register swap resolves when the
 * global is declared as a real struct (`_GameSystemGlobal.unk04 += 1`) rather
 * than accessed through raw pointer-plus-offset arithmetic.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GAMESYSTEM_ApplyTamperPenaltyRepeat.c \
 *       --func GAMESYSTEM_ApplyTamperPenaltyRepeat --addr 0x02011D7C --cc 1.1p1 --thumb
 */

#include "../include/G_G02146248.h"

typedef unsigned int u32;

extern void *GFL_USE_AddMainTask(u32 a, u32 b, u32 c);
extern void  GAMESYSTEM_RandTwice(void);
extern struct G02146248 _GameSystemGlobal;

void GAMESYSTEM_ApplyTamperPenaltyRepeat(void)
{
    GFL_USE_AddMainTask((u32)GAMESYSTEM_RandTwice, 0, 0x7f);
    _GameSystemGlobal.unk04 += 1;
}
