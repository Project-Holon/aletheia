/*
 * function: func_021F9254
 * address:  0x021F9254
 * packet:   pkt_021F9254
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Tail call into func_0203D34C with the fixed 0/0x48 pair.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203D34C(u32 a, u32 b);

void func_021F9254(void)
{
    func_0203D34C(0, 0x48);
}
