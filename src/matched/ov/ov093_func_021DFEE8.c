/*
 * function: func_021DFEE8
 * address: 0x021DFEE8
 * packet: pkt_ov093_021DFEE8
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
 *   d_021F1A3C 0x021F1A3C data a4
 */

int *func_021DFEE8(int *p);

/* 021DFEF4  stack-arg wrapper: func_021E0284(a, b, c, d, 0x9) */
extern int d_021F1A3C[];

int *func_021DFEE8(int *p)
{
    *p = 3;
    return d_021F1A3C;
}
