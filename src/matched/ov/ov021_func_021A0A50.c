/*
 * function: FIELD_LIGHT_BeginColorBlend
 * address:  0x021A0A50
 * packet:   pkt_ov021_021A0A50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_LIGHT_InitColorLerp  0x021A0818  thumb  ov021
 *   FIELD_LIGHT_InitDirLerp  0x021A08CC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01498.h"
#include "../include/Obj02080.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_LIGHT_InitColorLerp(s16 *o, s32 a, u32 b);
extern void FIELD_LIGHT_InitDirLerp(s32 *o, const s16 *in, u32 c);

void FIELD_LIGHT_BeginColorBlend(u8 *a, u8 *b, u32 c, u32 d)
{
    s32 i;

    ((struct Obj02080 *)a)->fF0 = 0;
    ((struct Obj02080 *)a)->fF2 = d;
    ((struct Obj02080 *)a)->f0 = ((struct Obj01498 *)b)->f0;
    ((struct Obj02080 *)a)->f2 = ((struct Obj01498 *)b)->f2;
    for (i = 0; i < 4; i++) {
        FIELD_LIGHT_InitColorLerp((s16 *)(a + 8 + i * 12), *(u16 *)(b + 8 + i * 2), c);
        FIELD_LIGHT_InitDirLerp((s32 *)(a + 0x38 + i * 0x1c), (const s16 *)(b + 0x10 + i * 6), (u32)(b + 0x10 + i * 6));
        a[4 + i] = b[4 + i];
    }
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xa8), ((struct Obj01498 *)b)->f28, c);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xb4), ((struct Obj01498 *)b)->f2A, c);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xc0), ((struct Obj01498 *)b)->f2C, c);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xcc), ((struct Obj01498 *)b)->f2E, c);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xd8), ((struct Obj01498 *)b)->f30, c);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xe4), ((struct Obj01498 *)b)->f32, c);
}
