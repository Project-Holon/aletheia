/*
 * function: func_021B991C
 * address: 0x021B991C
 * packet: pkt_ov072_021B991C
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021B995C 0x021B995C thumb ov072
 */
extern void func_02082BCC(void *, int, int);
extern void func_021B995C(int *, int);
void func_021B991C(int *p, int a, int b) {
    func_02082BCC(p, 0, 16);
    p[3] = a;
    func_021B995C(p, b);
}
