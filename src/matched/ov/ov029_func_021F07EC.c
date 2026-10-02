/*
 * function: func_021F07EC
 * address: 0x021F07EC
 * packet: pkt_ov029_021F07EC
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F0D08 0x021F0D08 thumb ov029
 *   func_021F08BC 0x021F08BC thumb ov029
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F3255 0x021F3255 data ov029 a1
 */
extern unsigned int func_021F0D08(unsigned short *p, int i);
extern void func_021F08BC(void *p, int i, int j, int k);
extern unsigned char d_021F3255[];
void func_021F07EC(void *p, int i, unsigned short *q)
{
    unsigned int v = func_021F0D08(q, i);
    if (v > 112 || v < 12) return;
    v = (unsigned)((unsigned short)(v - 12)) * 28 / 100;
    v = d_021F3255[v];
    func_021F08BC(p, i, v, 31);
}
