/*
 * function: func_021C3678
 * address: 0x021C3678
 * packet: pkt_ov208_021C3678
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_FillRect 0x02043AF4 arm
 *   func_021C3A24 0x021C3A24 thumb ov208
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor; struct CharBuf; struct Bmp;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *p, u8 v);
extern void BMP_FillRect(struct Bmp *p,u32 a,u32 b,u32 c,u32 d,u32 e);
extern void func_021C3A24(u16 *heap,u8 *p,int key);
void func_021C3678(u16 *heap,u8 *p,int key)
{
    struct Bmp *bmp;
    p[0x24] = 0;
    ((struct Obj00146 *)p)->f18 = 0;
    ((struct Obj00146 *)p)->f1A = 0;
    ((struct Obj00146 *)p)->f26 = 0;
    ((struct Obj00146 *)p)->f28 = 0;
    ((struct Obj00146 *)p)->f30 = 0;
    ((struct Obj00146 *)p)->f32 = *(s16 *)&((struct Obj00146 *)p)->f30;
    ((struct Obj00146 *)p)->f38 = 0;
    bmp = BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00146 *)p)->f20);
    BMP_Clear((struct CharBuf *)bmp,0);
    BMP_FillRect(bmp,0,0x37,0xee,1,0xf);
    func_021C3A24(heap,p,key);
}
