/*
 * function: GURU2_SessionDestroy
 * address: 0x021DC90C
 * packet: pkt_ov137_021DC90C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_COMM_Exit 0x021DCB90 thumb ov137
 *   GURU2_COMM_Destroy 0x021DCB60 thumb ov137
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj14201.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GURU2_COMM_Exit(void *);
extern void GURU2_COMM_Destroy(u8 *p);
extern u32 func_020307B0(void *p);
void GURU2_SessionDestroy(u8 *p) {GURU2_COMM_Exit(((struct Obj14201 *)p)->f18);GURU2_COMM_Destroy(((struct Obj14201 *)p)->f18);func_020307B0(p);}
