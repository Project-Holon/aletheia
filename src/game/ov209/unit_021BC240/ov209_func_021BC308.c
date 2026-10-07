/*
 * function: func_021BC308
 * address: 0x021BC308
 * packet: pkt_ov209_021BC308
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: VCOUNT read at 021BC30A; BLDALPHA writes at 021BC314, 021BC320, 021BC32C, 021BC338, 021BC344, 021BC34A
 */
typedef unsigned short u16;
void func_021BC308(void)
{
    int v = *(volatile u16 *)0x04000006;
    if (v >= 168) {
        *(volatile u16 *)0x04001052 = 0x050B;
        return;
    }
    if (v >= 144) {
        *(volatile u16 *)0x04001052 = 0x060A;
        return;
    }
    if (v >= 120) {
        *(volatile u16 *)0x04001052 = 0x0709;
        return;
    }
    if (v >= 96) {
        *(volatile u16 *)0x04001052 = 0x0808;
        return;
    }
    if (v >= 72) {
        *(volatile u16 *)0x04001052 = 0x0A06;
        return;
    }
    *(volatile u16 *)0x04001052 = 0x0C04;
}
