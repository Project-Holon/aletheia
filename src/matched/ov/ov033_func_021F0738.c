/*
 * function: DOWSING_ExitBgsAndActorUnit
 * address: 0x021F0738
 * packet: pkt_ov033_021F0738
 * region: ov033
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   sDowsingBgSetup 0x021F0DF0 data ov033 a4
 */
#include "../include/Obj20474.h"
#include "../include/G_ov033_021F0DF0.h"
extern struct G_ov033_021F0DF0 sDowsingBgSetup[];
struct Bank;
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
typedef unsigned int   u32;
extern void BG_SYS_FreeLayerBuf(u32 i);
void DOWSING_ExitBgsAndActorUnit(char *p) { unsigned i; CLACT_DeleteUnit((struct Bank *)(((struct Obj20474 *)p)->fC)); for(i=0;i<2;i++) BG_SYS_FreeLayerBuf((unsigned char)sDowsingBgSetup[i].f00); }
