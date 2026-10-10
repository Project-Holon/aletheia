/*
 * function: func_021DFF14
 * address: 0x021DFF14
 * packet: pkt_ov093_021DFF14
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
 *   d_021F1A54 0x021F1A54 data ov093 a4
 */

int *func_021DFF14(int *p);

/* 021DFF20  stack-arg wrapper: func_021E0284(a, b, c, d, 0xa) */
extern int d_021F1A54[];

int *func_021DFF14(int *p)
{
    *p = 3;
    return d_021F1A54;
}
