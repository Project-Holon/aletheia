/*
 * function: func_021DA114
 * address: 0x021DA114
 * packet: pkt_ov093_021DA114
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D9ADC.c and filed here.
 *
 * symbols:
 *   d_021F0808 0x021F0808 data ov093 a4
 */

int *func_021DA114(int *p);

/* 021DA120  shape F1: gate on func_021D775C(2) */
extern int d_021F0808[];

int *func_021DA114(int *p)
{
    *p = 1;
    return d_021F0808;
}
