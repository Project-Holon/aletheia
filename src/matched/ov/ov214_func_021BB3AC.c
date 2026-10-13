/*
 * function: func_021BB3AC
 * address: 0x021BB3AC
 * packet: pkt_ov214_021BB3AC
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj25732.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_02082BCC(void *,u32,u32);
void func_021BB3AC(void *p) { CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25732 *)p)->f0);CLACT_ExitSystem();func_02082BCC(p,0,4); }
