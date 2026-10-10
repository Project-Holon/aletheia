/*
 * function: func_021DEAE8
 * address: 0x021DEAE8
 * packet: pkt_ov093_021DEAE8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE980.c and filed here.
 *
 * symbols:
 *   d_021F191C 0x021F191C data a4
 */

int *func_021DEAE8(int *p);
extern int d_021F191C;

/*
 * lever: int n = (unsigned char)func_021DCFF8(a,2) schedules the
 * narrowing in r0 then r1. An inline call cast costs an extra copy (62 B).
 */
int *func_021DEAE8(int *p)
{
    *p = 3;
    return &d_021F191C;
}
