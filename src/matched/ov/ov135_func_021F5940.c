/*
 * function: func_021F5940
 * address: 0x021F5940
 * packet: pkt_ov135_021F5940
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202940 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
struct Obj;
extern void func_02202940(struct Obj *p);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void func_021F5940(u8 *p)
{
    func_02202940((struct Obj *)(p + 0xfa0));
    BMP_WIN_Delete(((struct Obj00287 *)p)->fDE0);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fDD0);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fD54);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fD40);
    BMP_WIN_Delete(((struct Obj00287 *)p)->fD4C);
}
