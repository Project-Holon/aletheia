/*
 * function: func_021DE4B8
 * address: 0x021DE4B8
 * packet: pkt_ov093_021DE4B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DE4A0.c and filed here.
 *
 * symbols:
 *   d_021F164C 0x021F164C data ov093 a4
 */

int *func_021DE4B8(int *p);

/*
 * extent: two-byte alignment padding at 021DE4F2.
 * lever: u8 result local narrows in r0 before copying to r1; twin 021DE3FC.
 */
extern int d_021F164C[];

int *func_021DE4B8(int *p)
{
    *p = 2;
    return d_021F164C;
}
