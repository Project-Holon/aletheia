/*
 * function: STARTMENU_SaveEraseSetupGraphics
 * address:  0x021BCF6C
 * packet:   pkt_ov088_021BCF6C
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 *   d_021BD980     0x021BD980  data  a4
 *   d_021BD990     0x021BD990  data  a4
 */

typedef unsigned int u32;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B32 {
    u32 w[8];
} B32;

extern A16 d_021BD980;
extern B32 d_021BD990;

typedef unsigned short u16;
extern void BG_SYS_Create(u16 heapId);
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);

void STARTMENU_SaveEraseSetupGraphics(void)
{
    A16 a;
    B32 b;

    BG_SYS_Create(0x81);
    a = d_021BD980;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&a));
    b = d_021BD990;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&b), 0);
    BG_SYS_SetMainPlaneVisible(1, 1);
    BG_SYS_LoadPlttEntry(0, 0x7D8C);
    BG_SYS_LoadPlttEntry(4, 0x7D8C);
}
