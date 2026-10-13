/*
 * function: FIELD_LIGHT_EvalBlend
 * address:  0x021A0B4C
 * packet:   pkt_ov021_021A0B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Inverse of FIELD_LIGHT_BeginColorBlend. The source pointer must be const: without it
 * the six trailing strh stores are scheduled ahead of the next call's
 * `adds rN, #0xf0/#0xf2` address setup (24 bytes differ).
 *
 * symbols:
 *   FIELD_LIGHT_EvalColorLerp  0x021A0860  thumb  ov021
 *   FIELD_LIGHT_EvalDirLerp  0x021A0918  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01034.h"
#include "../include/Obj03125.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u16 FIELD_LIGHT_EvalColorLerp(const void *o, u32 x, u32 y);
extern void FIELD_LIGHT_EvalDirLerp(u8 *a, s32 x, s32 y, s16 *out);

void FIELD_LIGHT_EvalBlend(const u8 *a, u8 *b)
{
    s32 i;
    u16 r;

    ((struct Obj03125 *)b)->f0 = *(const u16 *)&((struct Obj01034 *)a)->f0;
    ((struct Obj03125 *)b)->f2 = *(const s16 *)&((struct Obj01034 *)a)->f2;
    for (i = 0; i < 4; i++) {
        *(u16 *)(b + 8 + i * 2) = FIELD_LIGHT_EvalColorLerp(a + 8 + i * 12, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
        FIELD_LIGHT_EvalDirLerp((u8 *)(a + 0x38 + i * 0x1c), *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2, (s16 *)(b + 0x10 + i * 6));
        b[4 + i] = a[4 + i];
    }
    r = FIELD_LIGHT_EvalColorLerp(a + 0xa8, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f28 = r;
    r = FIELD_LIGHT_EvalColorLerp(a + 0xb4, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2A = r;
    r = FIELD_LIGHT_EvalColorLerp(a + 0xc0, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2C = r;
    r = FIELD_LIGHT_EvalColorLerp(a + 0xcc, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f2E = r;
    r = FIELD_LIGHT_EvalColorLerp(a + 0xd8, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f30 = r;
    r = FIELD_LIGHT_EvalColorLerp(a + 0xe4, *(const u16 *)&((struct Obj01034 *)a)->fF0, *(const u16 *)&((struct Obj01034 *)a)->fF2);
    ((struct Obj03125 *)b)->f32 = r;
}
