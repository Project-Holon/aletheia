/*
 * function: func_022003BC
 * address: 0x022003BC
 * packet: pkt_ov135_022003BC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202940 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj08194.h"
typedef unsigned char u8;
struct Obj;
extern void func_02202940(struct Obj *p);
struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void func_022003BC(u8 *p)
{
    int i;
    func_02202940((struct Obj *)(p + 0xFA0));
    BMP_WIN_Delete(((struct Obj08194 *)p)->fDE0);
    BMP_WIN_Delete(((struct Obj08194 *)p)->fDD0);
    BMP_WIN_Delete(((struct Obj08194 *)p)->fD40);
    for (i = 0; i < 3; i++) BMP_WIN_Delete(*(void **)(p + i * 4 + 0xD50));
    BMP_WIN_Delete(((struct Obj08194 *)p)->fD48);
}
