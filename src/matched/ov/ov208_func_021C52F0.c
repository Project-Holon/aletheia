/*
 * function: ZUKAN_DETAIL_FORM_LoadIconResources
 * address:  0x021C52F0
 * packet:   pkt_ov208_021C52F0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The three ARM9 callees 0x0201BC3C, 0x0201BC78 and 0x0201BCEC were
 * unlabelled; seeds_3 labelled them and matched them in
 * src/matched/unit_0201BC3C.c, so every relocation now attests.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Menu {
    u8  pad0[0x128];
    void *arc;
    u32 res[2];
    u32 j;
    u32 k;
};

extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern int func_0201BC3C(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

void ZUKAN_DETAIL_FORM_LoadIconResources(u16 *heap, struct Ov208Menu *p)
{
    p->arc = func_020490F4(7, *heap);
    p->j = CLACT_RegisterPaletteCompressed(p->arc, func_0201BC3C(), 1, 0, *heap);
    p->k = CLACT_RegisterCellAnim(p->arc, func_0201BC78(), func_0201BCEC(), *heap);
}
