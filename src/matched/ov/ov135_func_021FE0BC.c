/*
 * function: func_021FE0BC
 * address: 0x021FE0BC
 * packet: pkt_ov135_021FE0BC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202940 0x02202940 thumb ov135
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_02040DA8 0x02040DA8 arm
 */
#include "../include/Obj14174.h"
struct Obj;
extern void func_02202940(struct Obj *p);
typedef unsigned int   u32;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
void func_021FE0BC(unsigned char *p)
{
    int i;
    func_02202940((struct Obj *)(p + 0xfa0));
    BMP_WIN_Delete(((struct Obj14174 *)p)->fDE0);
    BMP_WIN_Delete(((struct Obj14174 *)p)->fD40);
    for (i = 0; i < 9; ++i)
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xd90));
    for (i = 0; i < 2; ++i)
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0xdd8));
    func_02040DA8(3, 1, 0);
}
