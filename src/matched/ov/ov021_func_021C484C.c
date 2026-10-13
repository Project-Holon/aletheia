/*
 * function: FLDEFF_RIPPLE_Start
 * address:  0x021C484C
 * packet:   pkt_ov021_021C484C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sRippleFuncs     0x021DA9F0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct Arg { u32 a; Vec3 v; } Arg;

extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 sRippleFuncs[];

void FLDEFF_RIPPLE_Start(u32 a, int b, int c, s32 d)
{
    Vec3 v;
    Arg s;

    FLDMMDL_MOVE_GridToVectorPos(b, c, (int *)(&v));
    v.y = d - 0x8000;
    v.z -= 0x5000;
    s.a = FIELD_EFFECT_GetResource(a, 7);
    s.v = v;
    FIELD_EFFECT_AddObject(a, sRippleFuncs, 0, 0, &s, 0);
}
