/*
 * function: func_021D7CF4
 * address: 0x021D7CF4
 * packet: pkt_ov116_021D7CF4
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 */
#include "../include/Obj13869.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
void func_021D7CF4(u8 *p)
{
    if (((struct Obj13869 *)p)->f0 != 0) TCBL_Main(((struct Obj13869 *)p)->f9A8);
}
