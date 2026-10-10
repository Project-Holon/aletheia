/*
 * function: func_021DFF6C
 * address: 0x021DFF6C
 * packet: pkt_ov093_021DFF6C
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
 *   d_021F18A4 0x021F18A4 data ov093 a4
 */

int *func_021DFF6C(int *p);

/* 021DFF78  stack-arg wrapper: func_021E0284(a, b, c, d, 0xb) */
extern int d_021F18A4[];

int *func_021DFF6C(int *p)
{
    *p = 3;
    return d_021F18A4;
}
