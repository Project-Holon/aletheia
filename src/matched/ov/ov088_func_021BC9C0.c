/*
 * function: func_021BC9C0
 * address:  0x021BC9C0
 * packet:   pkt_ov088_021BC9C0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 */

extern void  func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(int a, int size, int heap);
extern void  func_02082BCC(void *p, int v, int n);

int func_021BC9C0(int a0)
{
    func_0203064C(1, 0x16, 0x70000);
    func_02082BCC(func_0203159C(a0, 8, 0x16), 0, 8);
    return 1;
}
