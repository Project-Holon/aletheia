/*
 * function: FLDEFF_KEMURI_Start
 * address:  0x021AC528
 * packet:   pkt_ov021_021AC528
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   gFldeffKemuriObjFuncs     0x021D90AC  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct Arg { u32 a; Vec3 v; } Arg;

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *v);
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 gFldeffKemuriObjFuncs[];

void FLDEFF_KEMURI_Start(u32 a, u32 b)
{
    Vec3 v;
    Arg s;
    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    v.z += 0x6000;
    s.a = FIELD_EFFECT_GetResource(b, 1);
    s.v = v;
    FIELD_EFFECT_AddObject(b, gFldeffKemuriObjFuncs, 0, 0, &s, 0);
}
