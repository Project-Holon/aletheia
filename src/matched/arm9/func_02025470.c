/*
 * function: ACTOR_TOOL_LoadCharPalAnm
 * address:  0x02025470
 * packet:   pkt_02025470
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ACTOR_TOOL_LoadChar   0x02025404  thumb
 *   ACTOR_TOOL_GetCharBlock   0x02025508  thumb
 *   PALANM_CopyHwPaletteToSlot   0x020216D4  thumb
 *
 * Create one map tile: a4's flag word picks the 3-versus-2 mode, the tile is
 * built by ACTOR_TOOL_LoadChar over (a1, a2, a3, a4, a5, a6), its width comes back
 * from ACTOR_TOOL_GetCharBlock packed into the low half of a5's shifted word and the
 * tile is handed to PALANM_CopyHwPaletteToSlot with a5 shifted up five.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ACTOR_TOOL_LoadCharPalAnm.c \
 *       --func ACTOR_TOOL_LoadCharPalAnm --addr 0x02025470 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern s32 ACTOR_TOOL_LoadChar(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern unsigned int ACTOR_TOOL_GetCharBlock(int a0, int a1, int a2);
struct PalAnmSlot;
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

u32 ACTOR_TOOL_LoadCharPalAnm(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    u32 mode = 2;
    u32 p;
    u32 v;

    if (a4 != 0) {
        mode = 3;
    }
    p = ACTOR_TOOL_LoadChar(a1, a2, a3, a4, a5, a6);
    v = ACTOR_TOOL_GetCharBlock(a1, p, a4);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)a0, mode, (u16)(v << 4), a5 << 5);
    return p;
}
