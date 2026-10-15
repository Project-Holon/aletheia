/*
 * function: CTVT_TALK_PlotPixel
 * address: 0x021B9B88
 * packet: pkt_ov172_021B9B88
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Explicit weights pointer retains the array base in r1 and cell in r3.
 * symbols:
 *   d_021C6FA0 0x021C6FA0 data a2
 *   d_021C6F66 0x021C6F66 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_021C6FA0[4], d_021C6F66[4];
void CTVT_TALK_PlotPixel(u8 *p, u8 x, u8 y, u8 value)
{
    u8 subx = x % 8;
    u8 shift = subx % 4;
    u16 *cell = (u16 *)(p + (u16)((u32)x / 8 + (u32)y / 8 * 16) * 32 + (subx / 4 + (u8)(y % 8) * 2) * 2);
    u16 weights[4];
    u16 *w = weights;
    weights[0] = d_021C6FA0[0];
    weights[1] = d_021C6FA0[1];
    weights[2] = d_021C6FA0[2];
    weights[3] = d_021C6FA0[3];
    if ((u8 *)cell < p + 4096 && (u8 *)cell >= p)
        *cell = (*cell & d_021C6F66[shift]) + w[shift] * value;
}
