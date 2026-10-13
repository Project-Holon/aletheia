/*
 * function: DOWSING_ExitFade
 * address: 0x021F0C0C
 * packet: pkt_ov033_021F0C0C
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj06144.h"
typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
void DOWSING_ExitFade(char *p) { PALANM_FreeSlotBuffers(((struct Obj06144 *)p)->fBC,1); PALANM_FreeSlotBuffers(((struct Obj06144 *)p)->fBC,3); PALANM_Delete(((struct Obj06144 *)p)->fBC); func_02030DA4(((struct Obj06144 *)p)->fB4); func_020307B0(((struct Obj06144 *)p)->fB8); }
