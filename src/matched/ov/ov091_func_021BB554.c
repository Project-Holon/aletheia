/*
 * function: func_021BB554
 * address: 0x021BB554
 * packet: pkt_ov091_021BB554
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202D034 0x0202D034 thumb
 */
#include "../include/Obj03680.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_02017E1C(void *,u32,u32);
extern int func_0202D034(u32 a, u32 b);
int func_021BB554(u32 p) { return func_0202D034(((struct Obj03680 *)p)->f6,func_02017E1C(((struct Obj03680 *)p)->f0,0xa1,0)); }
