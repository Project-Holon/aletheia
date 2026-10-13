/*
 * function: func_021BAD98
 * address: 0x021BAD98
 * packet: pkt_ov213_021BAD98
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 021BADB2.
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj25716.h"
struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *,unsigned,unsigned);
void func_021BAD98(void *p){CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25716 *)p)->f0);CLACT_ExitSystem();MI_CpuFill8(p,0,4);}
