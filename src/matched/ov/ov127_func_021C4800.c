/*
 * function: func_021C4800
 * address: 0x021C4800
 * packet: pkt_ov127_021C4800
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Follower of 021C47E4, separate because 021C47F8/47FC already have shards.
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj10469.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuCopy8(void *,const void *,u32);
void func_021C4800(u8 *p,void *out) { MI_CpuCopy8(out,((struct Obj10469 *)p)->f4,((struct Obj10469 *)p)->f0 * ((struct Obj10469 *)p)->f2 * 4); }
