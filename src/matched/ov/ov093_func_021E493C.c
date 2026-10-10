/*
 * function: func_021E493C
 * address: 0x021E493C
 * packet: pkt_ov093_021E493C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E492C.c and filed here.
 *
 * symbols:
 *   d_021F2BA0 0x021F2BA0 data ov093 a4
 */

int *func_021E493C(int *p);

/* 021E4948  stack-arg wrapper: func_021E4958(a, b, c, d, 0x6f) */
extern int d_021F2BA0[];

int *func_021E493C(int *p)
{
    *p = 3;
    return d_021F2BA0;
}
