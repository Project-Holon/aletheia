/*
 * function: FIELD_BBD_COLOR_Apply
 * address:  0x021CD214
 * packet:   pkt_ov021_021CD214
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VEC_Fx16Normalize  0x0207CDB8  arm
 *   BILLBOARD_SetFlagWord  0x0204ED4C  arm
 *   BILLBOARD_SetField1C  0x0204ED80  arm
 *   BILLBOARD_SetField1E  0x0204ED8C  arm
 *   BILLBOARD_SetField20  0x0204ED98  arm
 *   BILLBOARD_SetField22  0x0204EDA4  arm
 */
#include "../include/Obj01220.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void VEC_Fx16Normalize(u16 *a, u16 *b);
extern void BILLBOARD_SetFlagWord(u8 *a0, short *a1);
extern void BILLBOARD_SetField1C(u8 *dst, u16 *src);
extern void BILLBOARD_SetField1E(u8 *dst, u16 *src);
extern void BILLBOARD_SetField20(u8 *dst, u16 *src);
extern void BILLBOARD_SetField22(u8 *dst, u16 *src);

void FIELD_BBD_COLOR_Apply(u8 *s, void *o)
{
    u16 v[3];
    u16 c[4];

    v[0] = ((struct Obj01220 *)s)->f4;
    v[1] = ((struct Obj01220 *)s)->f8;
    v[2] = ((struct Obj01220 *)s)->fC;
    VEC_Fx16Normalize(v, v);
    BILLBOARD_SetFlagWord(o, (short int *)v);
    c[3] = ((struct Obj01220 *)s)->f10 | (((struct Obj01220 *)s)->f12 << 5) | (((struct Obj01220 *)s)->f14 << 10);
    BILLBOARD_SetField1C(o, &c[3]);
    c[2] = ((struct Obj01220 *)s)->f16 | (((struct Obj01220 *)s)->f18 << 5) | (((struct Obj01220 *)s)->f1A << 10);
    BILLBOARD_SetField1E(o, &c[2]);
    c[1] = ((struct Obj01220 *)s)->f1C | (((struct Obj01220 *)s)->f1E << 5) | (((struct Obj01220 *)s)->f20 << 10);
    BILLBOARD_SetField20(o, &c[1]);
    c[0] = ((struct Obj01220 *)s)->f22 | (((struct Obj01220 *)s)->f24 << 5) | (((struct Obj01220 *)s)->f26 << 10);
    BILLBOARD_SetField22(o, &c[0]);
}
