/*
 * function: FLDEFF_D06DENKI_StartPulse
 * address:  0x021C9258
 * packet:   pkt_ov021_021C9258
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sD06DenkiPulseFuncs  0x021DAB90  data  ov021  a4
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;
typedef struct { u32 a; V v; } T;
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern u8 sD06DenkiPulseFuncs[];
void FLDEFF_D06DENKI_StartPulse(u32 a, V *v)
{
    T t;
    t.a = FIELD_EFFECT_GetResource(a, 0xb);
    t.v = *v;
    FIELD_EFFECT_AddObject(a, sD06DenkiPulseFuncs, 0, 0, &t, 0);
}
