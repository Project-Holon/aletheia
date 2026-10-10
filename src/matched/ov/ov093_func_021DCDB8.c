/*
 * function: func_021DCDB8
 * address: 0x021DCDB8
 * packet: pkt_ov093_021DCDB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DCAE8.c and filed here.
 *
 * symbols:
 *   d_021F0750 0x021F0750 data ov093 a4
 */

int *func_021DCDB8(int *p);
extern int d_021F0750[];

/*
 * Allocate 76 bytes, keep the handle, then configure it.
 */
int *func_021DCDB8(int *p)
{
    *p = 1;
    return d_021F0750;
}
