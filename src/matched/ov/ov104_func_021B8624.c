/*
 * function: IRC_RHYTHM_RecordTap
 * address: 0x021B8624
 * packet: pkt_ov104_021B8624
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: The +0x7c timestamp is u64 (both words stored by 021B85E4).
 * Keeping the subtraction 64-bit pins the low-word load in r2;
 * a u32 timestamp leaves two register-allocation bytes different.
 * Pair field subscripts reproduce the indexed +0/+4 stores.
 * symbols:
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 */
#include "../include/Obj01389.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern unsigned long long func_020870D0(void);
typedef struct { u32 f0; u32 f4; } Pair;
void IRC_RHYTHM_RecordTap(u8 *p) { if(((struct Obj01389 *)p)->f78<10) { ((Pair *)p)[((struct Obj01389 *)p)->f78].f0=(func_020870D0()<<6)/33514-*(unsigned long long *)(p+0x7c); if(((struct Obj01389 *)p)->f78==0) ((Pair *)p)[((struct Obj01389 *)p)->f78].f4=0; else ((Pair *)p)[((struct Obj01389 *)p)->f78].f4=((Pair *)p)[((struct Obj01389 *)p)->f78].f0-((Pair *)p)[((struct Obj01389 *)p)->f78-1].f0; ++((struct Obj01389 *)p)->f78; } else if(((struct Obj01389 *)p)->f7A<99) ++((struct Obj01389 *)p)->f7A; }
