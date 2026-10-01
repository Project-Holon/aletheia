/*
 * function: func_021BC960
 * address: 0x021BC960
 * packet: pkt_ov217_021BC960
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C30B2 0x021C30B2 data a1 ov217
 *   d_021C3190 0x021C3190 data a4
 *   d_021C3070 0x021C3070 data a4 ov217
 * Pool +94 names 021C3190; no cross-overlay loading proof. Drop contested
 * ov217 token to use the sole-ref/data witness without swapping tables.
 */
typedef unsigned char u8;
extern const u8 d_021C30B2[];
extern const u8 d_021C3190[];
extern const u8 d_021C3070[];
void func_021BC960(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p[i * 4 + 0x5A] = d_021C30B2[i * 4];
        p[i * 4 + 0x5B] = d_021C30B2[i * 4 + 1];
        p[i * 4 + 0x58] = d_021C30B2[i * 4 + 2];
        p[i * 4 + 0x59] = d_021C30B2[i * 4 + 3];
    }
    for (i = 0; i < 11; i++) {
        p[i * 4 + 0x66] = d_021C3190[i * 4];
        p[i * 4 + 0x67] = d_021C3190[i * 4 + 1];
        p[i * 4 + 0x64] = d_021C3190[i * 4 + 2];
        p[i * 4 + 0x65] = d_021C3190[i * 4 + 3];
    }
    for (i = 0; i < 2; i++) {
        p[i * 4 + 0x92] = d_021C3070[i * 4];
        p[i * 4 + 0x93] = d_021C3070[i * 4 + 1];
        p[i * 4 + 0x90] = d_021C3070[i * 4 + 2];
        p[i * 4 + 0x91] = d_021C3070[i * 4 + 3];
    }
}
