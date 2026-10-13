/*
 * function: FLDEFF_IAIGIRI_Start
 * address:  0x021C9550
 * packet:   pkt_ov021_021C9550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sIaigiriFuncs     0x021DAC80  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct V3 { int v[3]; } V3;
typedef struct Rec { u32 h; V3 pos; } Rec;

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
typedef unsigned short u16;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32, void *, u32, u32, Rec *, u32);
extern u32 sIaigiriFuncs[];

void FLDEFF_IAIGIRI_Start(u32 a, u32 b)
{
    V3 v;
    Rec r;

    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&v);
    switch (FLDMMDL_GetDirDisp((void *)a)) {
    case 0:
        v.v[2] -= 0x10000;
        break;
    case 1:
        v.v[2] += 0x10000;
        break;
    case 2:
        v.v[0] -= 0x10000;
        break;
    case 3:
        v.v[0] += 0x10000;
        break;
    }
    r.h = FIELD_EFFECT_GetResource(b, 0xc);
    r.pos = v;
    FIELD_EFFECT_AddObject(b, sIaigiriFuncs, 0, 0, &r, 0);
}
