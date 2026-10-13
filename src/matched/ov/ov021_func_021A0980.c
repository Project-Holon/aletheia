/*
 * function: FIELD_LIGHT_BeginBlend
 * address:  0x021A0980
 * packet:   pkt_ov021_021A0980
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_LIGHT_InitColorLerp  0x021A0818  thumb  ov021
 *   FIELD_LIGHT_InitDirLerp  0x021A08CC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01498.h"
#include "../include/Obj02080.h"
#include "../include/Obj03124.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_LIGHT_InitColorLerp(s16 *o, s32 a, u32 b);
extern void FIELD_LIGHT_InitDirLerp(s32 *o, const s16 *in, u32 c);

void FIELD_LIGHT_BeginBlend(u8 *a, u8 *b, u8 *c, u32 d)
{
    u8 *p0;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    int i;

    i = 0;
    ((struct Obj02080 *)a)->fF0 = i;
    ((struct Obj02080 *)a)->fF2 = d;
    ((struct Obj02080 *)a)->f0 = ((struct Obj03124 *)c)->f0;
    ((struct Obj02080 *)a)->f2 = ((struct Obj03124 *)c)->f2;
    p0 = a;
    p0 += 8;
    p1 = a;
    p1 += 0x38;
    p2 = b;
    p2 += 0x10;
    p3 = c;
    p3 += 0x10;
    for (; i < 4; i++) {
        FIELD_LIGHT_InitColorLerp((s16 *)(p0 + i * 12), *(u16 *)(b + 8 + i * 2), *(u16 *)(c + 8 + i * 2));
        FIELD_LIGHT_InitDirLerp((s32 *)(p1 + i * 0x1c), (const s16 *)(p2 + i * 6), (u32)(p3 + i * 6));
        a[4 + i] = c[4 + i];
    }
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xa8), ((struct Obj01498 *)b)->f28, ((struct Obj03124 *)c)->f28);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xb4), ((struct Obj01498 *)b)->f2A, ((struct Obj03124 *)c)->f2A);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xc0), ((struct Obj01498 *)b)->f2C, ((struct Obj03124 *)c)->f2C);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xcc), ((struct Obj01498 *)b)->f2E, ((struct Obj03124 *)c)->f2E);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xd8), ((struct Obj01498 *)b)->f30, ((struct Obj03124 *)c)->f30);
    FIELD_LIGHT_InitColorLerp((s16 *)(a + 0xe4), ((struct Obj01498 *)b)->f32, ((struct Obj03124 *)c)->f32);
}
