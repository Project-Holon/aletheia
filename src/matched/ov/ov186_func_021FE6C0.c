/*
 * function: func_021FE6C0
 * address: 0x021FE6C0
 * packet: pkt_ov186_021FE6C0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   d_02200D6C 0x02200D6C data a1
 */
extern const char d_02200D6C[];
extern void *func_02030734(unsigned, unsigned, unsigned, const char *, unsigned);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void *func_02021518(unsigned);
extern void func_0202155C(void *, unsigned, unsigned, unsigned);
extern void func_02021EE4(void *, int);
int *func_021FE6C0(unsigned heap)
{
    int *p = func_02030734(heap, 0x40, 0, d_02200D6C, 0x62);
    func_02082BCC(p, 0, 0x40);
    p[15] = 0xFFFF;
    p[8] = (int)func_02021518(heap);
    func_0202155C((void *)p[8], 0, 0x200, heap);
    func_0202155C((void *)p[8], 2, 0x1C0, heap);
    func_0202155C((void *)p[8], 1, 0x200, heap);
    func_0202155C((void *)p[8], 3, 0x1C0, heap);
    func_02021EE4((void *)p[8], 1);
    return p;
}
