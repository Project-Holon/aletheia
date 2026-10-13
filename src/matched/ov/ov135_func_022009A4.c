/*
 * function: func_022009A4
 * address: 0x022009A4
 * packet: pkt_ov135_022009A4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02202858 0x02202858 thumb ov135
 */
#include "../include/Obj02863.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
void func_022009A4(u8 *p, u32 n, int a2, int a3, int a4)
{
    u32 w;
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj02863 *)p)->fB6C), n, ((struct Obj02863 *)p)->fB88);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02863 *)p)->fD40)), 0xf);
    w = ((struct Obj02863 *)p)->fD40;
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    func_0201F73C((void *)(((struct Obj02863 *)p)->fD40), 0, 1, 0xe);
    func_02202858((void *)(((struct Obj02863 *)p)->fD40), 0, ((struct Obj02863 *)p)->fB88, 0, 0, p + 0xfa0);
}
