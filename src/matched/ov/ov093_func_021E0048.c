/*
 * function: func_021E0048
 * address: 0x021E0048
 * packet: pkt_ov093_021E0048
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
 *   d_021F1A24 0x021F1A24 data ov093 a4
 */

int *func_021E0048(int *p);

/* 021E0054  stack-arg wrapper: func_021E0284(a, b, c, d, 0x2) */
extern int d_021F1A24[];

int *func_021E0048(int *p)
{
    *p = 3;
    return d_021F1A24;
}
