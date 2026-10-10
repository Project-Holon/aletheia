/*
 * function: func_021E00A0
 * address: 0x021E00A0
 * packet: pkt_ov093_021E00A0
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
 *   d_021F185C 0x021F185C data ov093 a4
 */

int *func_021E00A0(int *p);

/* 021E00AC  stack-arg wrapper: func_021E0284(a, b, c, d, 0x6) */
extern int d_021F185C[];

int *func_021E00A0(int *p)
{
    *p = 3;
    return d_021F185C;
}
