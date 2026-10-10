/*
 * function: func_021E0074
 * address: 0x021E0074
 * packet: pkt_ov093_021E0074
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
 *   d_021F1A6C 0x021F1A6C data ov093 a4
 */

int *func_021E0074(int *p);

/* 021E0080  stack-arg wrapper: func_021E0284(a, b, c, d, 0xd) */
extern int d_021F1A6C[];

int *func_021E0074(int *p)
{
    *p = 3;
    return d_021F1A6C;
}
