/*
 * function: FLDEFF_FOOTMARK_InitResource
 * address:  0x021BBD0C
 * packet:   pkt_ov021_021BBD0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   FIELD_EFFECT_ApplyPaletteTable  0x021AC1F0  thumb  ov021
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 *   gFootmarkResId     0x021D9B0C  data  a2
 *
 * Twin of FLDEFF_GRASS_CreateSlots (same Arg local, same three calls per iteration).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Arg { u32 a; u8 b4, b5, b6, b7; u32 c; } Arg;

struct BbActRec;
struct BbActSys;
struct X;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern void FIELD_EFFECT_ApplyPaletteTable(struct X *x, void *b);
extern u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern u16 gFootmarkResId[];

void FLDEFF_FOOTMARK_InitResource(u32 *p)
{
    Arg s;
    int i;
    const u16 *t = gFootmarkResId;
    u32 r7 = FIELD_EFFECT_GetArcHandle((u8 *)p[0]);
    s.b4 = 2;
    s.b5 = 0x11;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.c = 1;
    for (i = 0; i < 0x1a; i++, t++) {
        s.a = (u32)G3D_SYSTEM_CreateResourceArcHandle(r7, *t);
        FIELD_EFFECT_ApplyPaletteTable((struct X *)p[0], (void *)s.a);
        ((u16 *)p)[4 + i] = BILLBOARD_ACT_CreateSlots((struct BbActSys *)p[1], (const struct BbActRec *)(&s), 1);
    }
}
