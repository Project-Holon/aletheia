/*
 * function: func_021C7500
 * address: 0x021C7500
 * packet: pkt_ov128_021C7500
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 */
#include "../include/Obj23075.h"
typedef unsigned char u8;
extern void func_021C6B38(u8 *);
extern void BG_SYS_SetTileEntry(unsigned,int,int,int,u8,u8,u8);
extern void func_02041B6C(unsigned);
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
void func_021C7500(u8 *p,u8 *q)
{
    void *obj;
    func_021C6B38(q);
    BG_SYS_SetTileEntry(2,0,0,0,32,24,16);
    func_02041B6C(2);
    BG_SYS_SetTileEntry(3,0,0,0,32,24,16);
    func_02041B6C(3);
    obj=((struct Obj23075 *)p)->fC;
    BMP_WIN_ClearScreen(obj);
    func_02041B6C(BMP_WIN_GetBgLayer(obj));
}
