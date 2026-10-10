/*
 * function: func_021DFF98
 * address: 0x021DFF98
 * packet: pkt_ov093_021DFF98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFCE8.c and filed here.
 *
 * symbols:
 *   d_021F18BC 0x021F18BC data ov093 a4
 */

int *func_021DFF98(int *p);

/* 021DFFA4  stack-arg wrapper: func_021E0284(a, b, c, d, 0xe) */
extern int d_021F18BC[];

int *func_021DFF98(int *p)
{
    *p = 3;
    return d_021F18BC;
}
