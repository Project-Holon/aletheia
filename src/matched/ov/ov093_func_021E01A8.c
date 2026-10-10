/*
 * function: func_021E01A8
 * address: 0x021E01A8
 * packet: pkt_ov093_021E01A8
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
 *   d_021F19C4 0x021F19C4 data ov093 a4
 */

int *func_021E01A8(int *p);

/* 021E01B4  stack-arg wrapper: calls func_021E01D4 with e = 0 */
extern int d_021F19C4[];

/*
 * Tail forwarder; following code starts at 021E01B0.
 */
int *func_021E01A8(int *p)
{
    *p = 3;
    return d_021F19C4;
}
