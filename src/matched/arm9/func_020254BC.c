/*
 * function: ACTOR_TOOL_LoadCharSimplePalAnm
 * address:  0x020254BC
 * packet:   pkt_020254BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ACTOR_TOOL_LoadCharSimple   0x02025440  thumb
 *   ACTOR_TOOL_GetCharBlock   0x02025508  thumb
 *   PALANM_CopyHwPaletteToSlot   0x020216D4  thumb
 *
 * The wide-tile twin of ACTOR_TOOL_LoadCharPalAnm: identical body, but the tile builder
 * is ACTOR_TOOL_LoadCharSimple rather than ACTOR_TOOL_LoadChar.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ACTOR_TOOL_LoadCharSimplePalAnm.c \
 *       --func ACTOR_TOOL_LoadCharSimplePalAnm --addr 0x020254BC --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int ACTOR_TOOL_LoadCharSimple(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern unsigned int ACTOR_TOOL_GetCharBlock(int a0, int a1, int a2);
struct PalAnmSlot;
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

u32 ACTOR_TOOL_LoadCharSimplePalAnm(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    u32 mode = 2;
    u32 p;
    u32 v;

    if (a4 != 0) {
        mode = 3;
    }
    p = ACTOR_TOOL_LoadCharSimple(a1, a2, a3, a4, a5, a6);
    v = ACTOR_TOOL_GetCharBlock(a1, p, a4);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)a0, mode, (u16)(v << 4), a5 << 5);
    return p;
}
