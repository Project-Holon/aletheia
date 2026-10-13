/*
 * function: FLDEFF_SHADOW_CreateSlot
 * address:  0x021AC274
 * packet:   pkt_ov021_021AC274
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm  arm9
 *   BILLBOARD_ACT_CreateSlots  0x020500F0  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Tmpl { u32 res; u8 b4, b5, b6, b7; u32 w8; } Tmpl;
typedef struct Ctl { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; u32 f14; u32 f18; } Ctl;

struct BbActRec;
struct BbActSys;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern u16 BILLBOARD_ACT_CreateSlots(struct BbActSys *o, const struct BbActRec *recs, u32 n);

void FLDEFF_SHADOW_CreateSlot(Ctl *p)
{
    Tmpl t;

    t.res = (u32)G3D_SYSTEM_CreateResourceArcHandle(FIELD_EFFECT_GetArcHandle((u8 *)p->f0), 0x2f);
    t.b4 = 2;
    t.b5 = 0x11;
    t.b6 = 0x10;
    t.b7 = 0x10;
    t.w8 = 1;
    p->f18 = BILLBOARD_ACT_CreateSlots((struct BbActSys *)p->f10, (const struct BbActRec *)(&t), 1);
}
