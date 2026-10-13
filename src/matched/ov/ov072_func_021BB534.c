/*
 * function: TOWNMAP_GRH_ExitLabel
 * address: 0x021BB534
 * packet: pkt_ov072_021BB534
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOWNMAP_GRH_ExitTextBox 0x021BB42C thumb ov072
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void TOWNMAP_GRH_ExitTextBox(void **p);
extern void MI_CpuFill8(void *p,int v,int n);
void TOWNMAP_GRH_ExitLabel(void *p) { TOWNMAP_GRH_ExitTextBox(p); MI_CpuFill8(p,0,0x20); }
