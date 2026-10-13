/*
 * function: func_021D8484
 * address: 0x021D8484
 * packet: pkt_ov120_021D8484
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8B20 0x021D8B20 data ov120 a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   PMS_DRAW_PrintOffset  0x0202DC60  thumb  arm9
 *   PMS_DRAW_SetNullColorPalette  0x0202DE5C  thumb  arm9
 *   PMS_DRAW_SetPrintColor  0x0202DE64  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj05353.h"
typedef struct { int a, b; } Pair;
extern const Pair d_021D8B20;
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, unsigned char c, unsigned char d, unsigned char slot);
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PmsDraw;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern void PMS_DRAW_SetPrintColor(struct PmsDraw *p, u16 v);
struct Obj;
extern void PMS_DRAW_PrintOffset(struct Obj *p, u32 a, void *w, u32 i, u32 e);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D8484(struct Obj05353 *p, void *n)
{
    Pair c = d_021D8B20;
    void *q;
    if (!p->f88) p->f88 = (void *)BMP_WIN_Create(1, 1, 15, 30, 5, 11, 1);
    q = p->f88;
    BMP_Clear(BMP_WIN_GetBmp(q), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    PMS_DRAW_SetNullColorPalette(p->fCC, 0);
    PMS_DRAW_SetPrintColor(p->fCC, 0x3c40);
    PMS_DRAW_PrintOffset(p->fCC, (u32)q, n, 0, (u32)(&c));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}
