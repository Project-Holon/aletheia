/*
 * function: FLDEFF_NAMIPOKE_Start
 * address:  0x021ACB38
 * packet:   pkt_ov021_021ACB38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sNamipokeRailFuncs     0x021D915C  data  a4
 *   sNamipokeGridFuncs     0x021D9184  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct Arg { u32 a; u32 b; u16 c, d, e; } Arg;

extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern u16 FLDMMDL_GetObjId(void *p);
extern u16 FLDMMDL_GetZoneId(void *p);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern void FIELD_EFFECT_AddObject(u32 a, u8 *b, Vec3 *c, u32 d, Arg *e, u32 f);
extern u8 sNamipokeRailFuncs[];
extern u8 sNamipokeGridFuncs[];

void FLDEFF_NAMIPOKE_Start(u32 a, u32 b, Vec3 *c, u32 d, u32 e)
{
    Vec3 v;
    Arg s;
    s.a = FIELD_EFFECT_GetResource(a, 3);
    s.b = d;
    s.c = FLDMMDL_GetObjId((void *)d);
    s.d = FLDMMDL_GetZoneId((void *)d);
    s.e = b;
    v = *c;
    if (FLDMMDL_CheckStatusBit(d, 0x2000) != 0)
        FIELD_EFFECT_AddObject(a, sNamipokeRailFuncs, &v, e, &s, 0);
    else
        FIELD_EFFECT_AddObject(a, sNamipokeGridFuncs, &v, e, &s, 0);
}
