/*
 * function: func_021E83C0
 * address: 0x021E83C0
 * packet: pkt_ov093_021E83C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E8384.c and filed here.
 *
 * symbols:
 *   d_021F2F68 0x021F2F68 data ov093 a4
 */

int *func_021E83C0(int *p);
extern int d_021F2F68[];

/*
 * Return r0 from func_021EC01C and func_021EA858 is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 */
int *func_021E83C0(int *p)
{
    *p = 6;
    return d_021F2F68;
}
