/*
 * function: TOWNMAP_ProcInit
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
 *   TOWNMAP_ProcSetStep 0x021B995C thumb ov072
 */
extern void func_02082BCC(void *, int, int);
extern void TOWNMAP_ProcSetStep(int *, int);
void TOWNMAP_ProcInit(int *p, int a, int b) {
    func_02082BCC(p, 0, 16);
    p[3] = a;
    TOWNMAP_ProcSetStep(p, b);
}
