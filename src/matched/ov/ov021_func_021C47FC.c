/*
 * function: FLDEFF_RIPPLE_AddActor
 * address:  0x021C47FC
 * packet:   pkt_ov021_021C47FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   FIELD_EFFECT_ApplyPaletteTable  0x021AC1F0  thumb  ov021
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct S { u32 w0; u8 b4, b5, b6, b7; u32 w8; } S;
typedef struct P { u32 f0; u32 f4; u16 f8; } P;

struct BbActRec;
struct BbActSys;
struct X;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern void FIELD_EFFECT_ApplyPaletteTable(struct X *x, void *b);
extern u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *o, const struct BbActRec *recs, u32 n);

void FLDEFF_RIPPLE_AddActor(P *p)
{
    S s;
    u32 x = FIELD_EFFECT_GetArcHandle((u8 *)p->f0);

    s.b4 = 2;
    s.b5 = 0x13;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.w8 = 1;
    s.w0 = (u32)G3D_SYSTEM_CreateResourceArcHandle(x, 0x2e);
    FIELD_EFFECT_ApplyPaletteTable((struct X *)p->f0, (void *)s.w0);
    p->f8 = BILLBOARD_ACT_CreateSlots((struct BbActSys *)p->f4, (const struct BbActRec *)(&s), 1);
}
