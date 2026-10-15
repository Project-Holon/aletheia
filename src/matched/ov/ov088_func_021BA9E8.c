/*
 * function: STARTMENU_SetupBackgrounds
 * address:  0x021BA9E8
 * packet:   pkt_ov088_021BA9E8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seven-background graphics setup: bank select, BG mode header copied from
 * a 16-byte template, then seven 32-byte BG templates each copied to the
 * stack and handed to BG_SYS_InitBgLayer.  Twin: ov088_func_021BCF6C.c.
 *
 * symbols:
 *   BG_SYS_Create  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   d_021BD678     0x021BD678  data  a4
 *   d_021BD724     0x021BD724  data  a4
 *   d_021BD764     0x021BD764  data  a4
 *   d_021BD6C4     0x021BD6C4  data  a4
 *   d_021BD6E4     0x021BD6E4  data  a4
 *   d_021BD744     0x021BD744  data  a4
 *   d_021BD6A4     0x021BD6A4  data  a4
 *   d_021BD704     0x021BD704  data  a4
 */

typedef unsigned int u32;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B32 {
    u32 w[8];
} B32;

extern A16 d_021BD678;
extern B32 d_021BD724;
extern B32 d_021BD764;
extern B32 d_021BD6C4;
extern B32 d_021BD6E4;
extern B32 d_021BD744;
extern B32 d_021BD6A4;
extern B32 d_021BD704;

typedef unsigned short u16;
extern void BG_SYS_Create(u16 heapId);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void STARTMENU_SetupBackgrounds(void)
{
    A16 a;
    B32 b0;
    B32 b1;
    B32 b2;
    B32 b3;
    B32 b4;
    B32 b5;
    B32 b6;

    BG_SYS_Create(0xb);
    a = d_021BD678;
    func_0203FC28((struct DispConfig *)(&a));
    b0 = d_021BD724;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&b0), 0);
    b1 = d_021BD764;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&b1), 0);
    b2 = d_021BD6C4;
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&b2), 0);
    b3 = d_021BD6E4;
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)(&b3), 0);
    b4 = d_021BD744;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&b4), 0);
    b5 = d_021BD6A4;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&b5), 0);
    b6 = d_021BD704;
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)(&b6), 0);
    BG_SYS_SetMainPlaneVisible(0xf, 1);
    BG_SYS_SetSubPlaneVisible(7, 1);
}
