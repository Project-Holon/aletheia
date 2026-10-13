/*
 * function: MONOLITH_TOOL_UpdateRows
 * address:  0x021BA140
 * packet:   pkt_ov071_021BA140
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_OAM_SetPos  0x0202590C  thumb
 *   BMP_CopyPixels  0x02043814  arm
 */
#include "../include/Obj20759.h"

typedef unsigned char u8;

typedef signed short   s16;
struct Bmp;
struct Grid;
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);
extern void BMP_CopyPixels(struct Bmp *dst, const struct Bmp *src);

void MONOLITH_TOOL_UpdateRows(u8 *p)
{
    int x = ((struct Obj20759 *)p)->f2D8 >> 8;
    int b = 8 - x % 32;
    u8 *q = p + (x / 32) * 4;
    int i;

    for (i = 0; i < 7; i++) {
        BMP_OAM_SetPos(*(void **)(p + i * 4 + 0x2a0), 0x20, b + i * 32);
        if (*(void **)(q + i * 4 + 0x24) != 0) {
            BMP_CopyPixels(*(void **)(q + i * 4 + 0x24), *(void **)(p + i * 4 + 0x2bc));
        }
    }
}
