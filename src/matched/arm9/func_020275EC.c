/*
 * function: APP_ICON_GetTypePaletteOffset
 * address:  0x020275EC
 * packet:   pkt_020275EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: byte lookup in a u8 table; called from ov094 BTLV_INPUT_DrawWazaButtons (bl at
 *   +0x1EE, 0x02204EAE) with a u8 index.
 * symbols:
 *   _PokeTypePltOffset  0x0209FCF8  data
 */

typedef unsigned char u8;

extern const u8 _PokeTypePltOffset[];

u8 APP_ICON_GetTypePaletteOffset(int i)
{
    return _PokeTypePltOffset[i];
}
