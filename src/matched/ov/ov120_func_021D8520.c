/*
 * function: func_021D8520
 * address: 0x021D8520
 * packet: pkt_ov120_021D8520
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D858E.
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj04490.h"
typedef unsigned short u16;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, void *dest);
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, unsigned char c, unsigned char d, unsigned char slot);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
typedef signed short   s16;
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D8520(char *p, u16 n)
{
    void *q;
    MSGDATA_ReadString(((struct Obj04490 *)p)->fC, n, (void *)(((struct Obj04490 *)p)->f18));
    if (!((struct Obj04490 *)p)->f68) ((struct Obj04490 *)p)->f68 = (void *)BMP_WIN_Create(1, 0, 0, 14, 2, 11, 1);
    q = ((struct Obj04490 *)p)->f68;
    BMP_Clear(func_02045770(q), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    PRINTSYS_Print(func_02045770(q), 2, 2, (void *)(((struct Obj04490 *)p)->f18), (void *)(((struct Obj04490 *)p)->f14));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}
