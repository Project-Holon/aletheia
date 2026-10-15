/*
 * function: BG_SYS_FreeSlot
 * address:  0x020414AC
 * packet:   pkt_020414AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_InitSlot 0x020414C4 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 */

typedef unsigned char u8;
extern void BG_SYS_InitSlot(u8 idx);
extern void BG_SYS_ClearSlot(unsigned int i);

void BG_SYS_FreeSlot(u8 idx)
{
    BG_SYS_InitSlot(idx);
    BG_SYS_ClearSlot(idx);
}
