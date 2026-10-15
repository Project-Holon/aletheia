/*
 * function: func_020414AC
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
 *   func_020414C4 0x020414C4 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 */

typedef unsigned char u8;
extern void func_020414C4(u8 idx);
extern void BG_SYS_ClearSlot(unsigned int i);

void func_020414AC(u8 idx)
{
    func_020414C4(idx);
    BG_SYS_ClearSlot(idx);
}
