/*
 * function: func_0217534C
 * address: 0x0217534C
 * packet: pkt_ov012_0217534C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 * evidence: unlabelled Thumb tail-call leaf (ldr r3,=func_02082BCC; bx r3) after
 * func_02175280; called by the bl at 0x02174A94 in func_02174744.
 */
extern void func_02082BCC(void *p, int v, int n);

void func_0217534C(void *p)
{
    func_02082BCC(p, 0, 0x58);
}
