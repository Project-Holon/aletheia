/*
 * unit:     no
 * function: GFL_NET_SAVE_DeleteScreenWork
 * address:  0x02010B98
 * packet:   pkt_02010A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_Delete  0x02012704  thumb
 *   OS_ResetSystem  0x02087BCC  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 */
#include "../include/Obj15614.h"

extern void GAME_DATA_Delete(unsigned char *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);

int GFL_NET_SAVE_DeleteScreenWork(int a0, int a1, int a2, int a3){ int t2, t3; GAME_DATA_Delete((unsigned char *)((struct Obj15614 *)((char *)(a3)))->f44); func_020315D4((struct S020315D4 *)((a0 + 0) + 0)); t2 = GFL_HEAP_DeleteChecked((int)0x67); t3 = OS_ResetSystem((int)0); return 1; }
