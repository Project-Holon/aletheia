/*
 * function: func_021D7858
 * address: 0x021D7858
 * packet: pkt_ov120_021D7858
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02028178 0x02028178 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 */
#include "../include/Obj05351.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0201DD78(u32, u32, u32);
struct PrintSys;
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02028178(u8 *p);
extern void PMS_DRAW_Main(u8 *p);
void func_021D7858(u8 *p)
{
    func_0201DD78(1, 2, 15);
    func_020310C4(((struct Obj05351 *)p)->fA0);
    func_0201C4E4(((struct Obj05351 *)p)->fA4);
    if (((struct Obj05351 *)p)->fC4) func_02028178(((struct Obj05351 *)p)->fC4);
    if (((struct Obj05351 *)p)->fCC) PMS_DRAW_Main(((struct Obj05351 *)p)->fCC);
}
