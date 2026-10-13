/*
 * function: func_022051FC
 * address:  0x022051FC
 * packet:   pkt_022051FC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02028590 0x02028590 thumb
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj00844.h"

typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Tcbl;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern u32 func_02028590(int, int, int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);

void func_022051FC(int a, char *b)
{
    u32 p;

    func_02049B40(0x17, 5, 0, 0x20, 0x20, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f70 = BMP_WIN_Create(1, 0, 0, 1, 1, 1, 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00844 *)b)->f70)), 0);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00844 *)b)->f70);
    ((struct Obj00844 *)b)->f6C = BMP_WIN_Create(1, 1, 0x13, 0x1e, 4, 1, 1);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00844 *)b)->f6C)), 0);
    p = ((struct Obj00844 *)b)->f6C;
    BMP_WIN_TransferChars((struct Descriptor *)p);
    BMP_WIN_MakeScreen((struct Cfg *)p);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p));
    ((struct Obj00844 *)b)->f74 = (u32)func_0201F5DC((void *)1, 2, 0, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f78 = (u32)func_02045B38(0, 2, 0xac, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f7C = (u32)func_02045B38(0, 2, 0xcc, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f68 = (u32)TCBL_Create(((struct Obj00844 *)b)->f2, ((struct Obj00844 *)b)->f2, 1, 0);
    GF_FONT_SetTextColor(1, 2, 0xf);
    ((struct Obj00844 *)b)->f80 = 0;
    ((struct Obj00844 *)b)->f64 = 0;
    ((struct Obj00844 *)b)->f84 = func_02028590(0xf, 1, 1, ((struct Obj00844 *)b)->f2);
    ((struct Obj00844 *)b)->f88 = 0;
    func_02040588(1, 0);
    ((struct Obj00844 *)b)->f8C = 0;
}
