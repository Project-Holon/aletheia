/*
 * function: func_02179824
 * address: 0x02179824
 * packet: pkt_ov015_02179824
 * region: ov015
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0217983E.
 * symbols:
 *   func_02179A4C 0x02179A4C thumb ov015
 */
typedef unsigned char u8;
extern void func_02179A4C(void *, u8, u8);
int func_02179824(void *dst, int a, int unused, void (*cb)(int))
{
    func_02179A4C(dst, (u8)a, 0);
    if (cb != 0) cb(1);
    return 1;
}
