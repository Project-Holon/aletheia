/*
 * function: EGG_DEMO_GRAPHIC_DeleteClact
 * address: 0x021F6600
 * packet: pkt_ov215_021F6600
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding follows the body.
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj25751.h"
struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *,int,unsigned);
void EGG_DEMO_GRAPHIC_DeleteClact(char *p){CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25751 *)p)->f0);CLACT_ExitSystem();MI_CpuFill8(p,0,4);}
