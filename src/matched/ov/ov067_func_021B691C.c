/*
 * function: func_021B691C
 * address: 0x021B691C
 * packet: pkt_ov067_021B691C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding at 0x021B6932.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_0204B3B4(void *a);
extern void func_02082BCC(void *p, unsigned int v, unsigned int n);
void func_021B691C(void **p)
{
    func_0204B3B4(*p);
    func_02082BCC(p, 0, 0x38);
}
