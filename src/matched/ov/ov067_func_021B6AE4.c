/*
 * function: TOUCHBAR_PrintAligned
 * address:  0x021B6AE4
 * packet:   pkt_ov067_021B6AE4
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     b and c are u16 as the matched caller TOUCHBAR_PrintYesNoCancelLabels passes
 *           them; the difference is written back into the parameter
 *           (`b = b - f()`): a separate u16 local y swapped p and b between
 *           r4/r5, and `b -= f()` truncates the call result first (worse).
 *
 * symbols:
 *   TOUCHBAR_GetStringAlignOffset  0x021B6C4C  thumb  ov067
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 */
#include "../include/Obj05378.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

struct StrObj;
extern u16 TOUCHBAR_GetStringAlignOffset(struct StrObj *s, u32 a, u32 mode);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3)
{
    b = b - TOUCHBAR_GetStringAlignOffset((struct StrObj *)s0, s1, s3);
    PRINTSYS_PrintQueColor(a, (u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj05378 *)p)->f0), (s16)b, (s16)c, s0, s1, s2);
    p[4] = 1;
}
