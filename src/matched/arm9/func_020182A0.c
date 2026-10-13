/*
 * function: POKE_TOOL_ReplaceMoveSlot
 * address:  0x020182A0
 * packet:   pkt_020182A0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_ReplaceBoxMoveSlot  0x020182A8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern void POKE_TOOL_ReplaceBoxMoveSlot(void *, u16, u8);

void POKE_TOOL_ReplaceMoveSlot(void *p, u16 move, u8 slot)
{
    POKE_TOOL_ReplaceBoxMoveSlot(p, move, slot);
}
