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
 *   MI_CpuFill8 0x02082BCC arm
 *   TOWNMAP_ProcSetStep 0x021B995C thumb ov072
 */
extern void MI_CpuFill8(void *, int, int);
extern void TOWNMAP_ProcSetStep(int *, int);
void TOWNMAP_ProcInit(int *p, int a, int b) {
    MI_CpuFill8(p, 0, 16);
    p[3] = a;
    TOWNMAP_ProcSetStep(p, b);
}
