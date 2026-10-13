/*
 * function: FLDEFF_D06DENKI_StartSpark
 * address:  0x021C8F7C
 * packet:   pkt_ov021_021C8F7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-01: EXACT once the own-overlay ov021 hint was dropped from the sD06DenkiSparkFuncs
 * symbols line (own-window rule). Old note: the ABS32 to sD06DenkiSparkFuncs was unresolved (the ov021
 * hint is contested: another overlay in the window starts an object at
 * 0x021DABA4, and this function loads no ov021 overlay_id). Needs an
 * independent data witness for 0x021DABA4 in ov021.
 *
 * symbols:
 *   sD06DenkiSparkFuncs  0x021DABA4  data  a4
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 a; V v; } T;
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *v);
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern u8 sD06DenkiSparkFuncs[];
void FLDEFF_D06DENKI_StartSpark(u32 a, u32 b)
{
    V pos;
    T t;
    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&pos);
    t.a = FIELD_EFFECT_GetResource(b, 0xb);
    t.v = pos;
    FIELD_EFFECT_AddObject(b, sD06DenkiSparkFuncs, 0, 0, &t, 0);
}
