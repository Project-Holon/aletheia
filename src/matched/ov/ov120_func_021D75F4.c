/*
 * function: GTSNEGO_MSG_StepIdleFade
 * address: 0x021D75F4
 * packet: pkt_ov120_021D75F4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 */
#include "../include/Obj04488.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void BG_SYS_ChangeScrollImmediate(u32,u32,u32);
void GTSNEGO_MSG_StepIdleFade(char *p) { if(((struct Obj04488 *)p)->f114) { BG_SYS_ChangeScrollImmediate(2,3,((struct Obj04488 *)p)->f110); ((struct Obj04488 *)p)->f110+=1; } }
