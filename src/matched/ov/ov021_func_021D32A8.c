/*
 * function: FLD_VREQ_ApplyBlendNone
 * address: 0x021D32A8
 * packet: pkt_ov021_021D32A8
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_palace_sys.c and filed here.
 */

void FLD_VREQ_ApplyBlendNone(int a, int sel);

void FLD_VREQ_ApplyBlendNone(int a, int sel)
{
    if (sel != 0) {
        *(volatile unsigned short *)0x04000050 = 0;
    } else {
        *(volatile unsigned short *)0x04001050 = 0;
    }
}
