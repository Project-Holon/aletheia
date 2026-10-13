/*
 * function: POKEGRA_RegisterTrainerPalette
 * address:  0x0202DA18
 * packet:   pkt_0202DA18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEGRA_GetTrainerPalArcIndex  0x0202D61C  thumb
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  POKEGRA_GetTrainerPalArcIndex(u32 a, u32 b);
typedef signed int     s32;
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

s32 POKEGRA_RegisterTrainerPalette(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    return CLACT_RegisterPaletteEx((void *)a, POKEGRA_GetTrainerPalArcIndex(b, 0), c, d, 0, 1, e);
}
