/*
 * function: func_021C3A24
 * address: 0x021C3A24
 * packet: pkt_ov208_021C3A24
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetCharOffset 0x02045768 arm
 *   func_02041090 0x02041090 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj06685.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
extern u16 BMP_WIN_GetCharOffset(struct Descriptor *p);
extern void func_02041090(u32 index,u32 a,u32 b,u32 c,u8 d,u8 e);
extern void BMP_WIN_TransferChars(struct Descriptor *p);
void func_021C3A24(u16 *heap,u8 *p,int key)
{
    u16 tile;
    u16 row;
    u16 index;
    u16 col;
    int base;
    tile=BMP_WIN_GetCharOffset(*(struct Descriptor * *)&((struct Obj06685 *)p)->f20);
    index=0;
    for(row=0;row<15;row++) {
        base=tile+row*31;
        for(col=0;col<31;col++) {
            (*(u16 **)(p+0x14))[index]=(u16)(base+(col+((struct Obj06685 *)p)->f1A)%31)|0x1000;
            index++;
        }
    }
    func_02041090(3,((struct Obj06685 *)p)->f14,1,2,31,15);
    ((struct Obj06685 *)p)->f1C=1;
    BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj06685 *)p)->f20);
}
