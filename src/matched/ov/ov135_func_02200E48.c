/*
 * function: func_02200E48
 * address: 0x02200E48
 * packet: pkt_ov135_02200E48
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 02200E92..02200E94 two zero alignment bytes.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj10594.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32);
void func_02200E48(u8 *p)
{
    u32 w;
    ((struct Obj10594 *)p)->fD40 = BMP_WIN_Create(0, 2, 0x13, 0x1b, 4, 0xd, 1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj10594 *)p)->fD40)), 0);
    w = ((struct Obj10594 *)p)->fD40;
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)w));
}
