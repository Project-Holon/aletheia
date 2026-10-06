/*
 * function: func_0215A760
 * address: 0x0215A760
 * packet: pkt_ov010_0215A760
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: original narrows r1/r2 by shift pairs; u16 extern preserves this.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 */
#include "../include/Obj05883.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
void func_0215A760(u8 *a, unsigned b, unsigned c) {
 ((struct Obj05883 *)a)->f14 = func_02045B38(0, (u16)b, (u16)c, ((struct Obj05883 *)a)->f0);
 ((struct Obj05883 *)a)->f18 = c;
}
