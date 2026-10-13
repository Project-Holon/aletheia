/*
 * function: FLDEFF_D06DENKI_StartFollow
 * address:  0x021C9064
 * packet:   pkt_ov021_021C9064
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sD06DenkiFollowFuncs  0x021DABB8  data  ov021  a4
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 a; V v; u32 c; } T;
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern u8 sD06DenkiFollowFuncs[];
void FLDEFF_D06DENKI_StartFollow(u32 a, V *v, u32 c)
{
    T t;
    t.a = FIELD_EFFECT_GetResource(a, 0xb);
    t.v = *v;
    t.c = c;
    FIELD_EFFECT_AddObject(a, sD06DenkiFollowFuncs, 0, 0, &t, 0);
}
