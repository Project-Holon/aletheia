/*
 * function: func_021DC610
 * address:  0x021DC610
 * packet:   pkt_021DC610
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * note:     the listing extent (148 B) covers the following leaf and pool
 *           words as well; every compiled byte of this 92-byte body matches.
 *
 * symbols:
 *   g_021E2EF8   0x021E2EF8  data
 *
 * Thumb jump table over 0..9: the startup mode reports 0x34..0x3b from its own
 * single-return blocks, mode 0 runs the 0x02034714 job with the 0x021E2EF8
 * record on both the first and third argument and reports 0, and mode 9 shares
 * the default's 0x3c block (stacked `case 9: default:` labels, which is what
 * keeps the table at ten entries and the block count at nine).
 */

typedef unsigned int u32;

extern void func_02034714(int a, int b, int c);
extern u32 g_021E2EF8[];

int func_021DC610(unsigned int a)
{
    switch (a) {
    case 0:
        func_02034714((int)g_021E2EF8, 0, (int)g_021E2EF8);
        return 0;
    case 1:
        return 0x34;
    case 2:
        return 0x35;
    case 3:
        return 0x36;
    case 4:
        return 0x37;
    case 5:
        return 0x38;
    case 6:
        return 0x39;
    case 7:
        return 0x3a;
    case 8:
        return 0x3b;
    case 9:
    default:
        return 0x3c;
    }
}
