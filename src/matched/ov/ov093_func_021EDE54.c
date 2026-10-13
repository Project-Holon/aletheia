/*
 * function: BTLV_SCU_DrawNamePlate
 * address: 0x021EDE54
 * packet: pkt_ov093_021EDE54
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_GetByteSize 0x020437EC arm
 *   BMP_GetPixels 0x020437D4 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj01524.h"
#include "../include/Obj02797.h"
#include "../include/Obj21615.h"
#include "../include/Obj21616.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Bmp;
struct StrObj;
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void MIi_CpuCopy32(const void *, void *, u32);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void BTL_MSG_FormatArgs(u32, u16, u32, ...);
extern u32 func_0201D33C(struct StrObj *s, u32 a, u32 b, u32 *out, u32 max);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D37C(struct StrObj *src, struct StrObj *dst, u32 n);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
void BTLV_SCU_DrawNamePlate(u8 *p)
{
    u8 *q;
    u32 size;
    void *pixels;
    u32 widths[2];
    int right;
    int left;
    int gap;
    int extra;
    int half;
    u32 edge;
    u32 width;
    u32 center;
    q = *(u8 * *)&((struct Obj02797 *)p)->f0;
    size = BMP_GetByteSize(((struct Obj02797 *)p)->f4);
    pixels = BMP_GetPixels(((struct Obj02797 *)p)->f4);
    MIi_CpuCopy32(*(u8 * *)&((struct Obj21616 *)(*(u8 * *)&((struct Obj21615 *)(*(u8 * *)&((struct Obj02797 *)p)->f0))->fDC))->f14 + p[0xa] * 0x900, pixels, size);
    GF_FONT_SetTextColor(1, 2, 0);
    BTL_MSG_FormatArgs(*(u32 *)&((struct Obj01524 *)q)->f38, 0x67, 2, p[0xc], ((struct Obj02797 *)p)->f8);
    if ((u8)func_0201D33C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f28, 0, widths, 2) > 1) {
        width = widths[0];
        edge = width + 8;
        right = 0x84 - widths[1];
        gap = edge - right;
        if (gap < 12) {
            extra = 12 - gap;
            half = extra / 2;
            edge += half;
            extra -= half;
            right -= extra;
        }
        left = edge;
        left = left - width;
        if (left < 0) left = 0;
        if (right < 0) right = 0;
        func_0201D37C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f3C, 0);
        PRINTSYS_Print(((struct Obj02797 *)p)->f4, left, 7, ((struct Obj01524 *)q)->f3C, (void *)(((struct Obj01524 *)q)->f28));
        func_0201D37C(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f3C, 1);
        PRINTSYS_Print(((struct Obj02797 *)p)->f4, right, 18, ((struct Obj01524 *)q)->f3C, (void *)(((struct Obj01524 *)q)->f28));
    } else {
        center = (0x88 - func_0201D304(((struct Obj01524 *)q)->f38, ((struct Obj01524 *)q)->f28, 0)) / 2;
        if ((int)center < 0) center = 0;
        PRINTSYS_Print(((struct Obj02797 *)p)->f4, center, 18, ((struct Obj01524 *)q)->f38, (void *)(((struct Obj01524 *)q)->f28));
    }
}
