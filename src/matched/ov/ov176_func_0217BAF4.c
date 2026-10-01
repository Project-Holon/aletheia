/*
 * function: func_0217BAF4
 * address: 0x0217BAF4
 * packet: pkt_ov176_0217BAF4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_0217E074 0x0217E074 thumb ov176
 *   func_021E7E08 0x021E7E08 thumb ov177
 *   func_021E64C0 0x021E64C0 thumb ov177
 *   func_021E7774 0x021E7774 thumb ov177
 *   func_021E84F8 0x021E84F8 thumb ov177
 */
extern void func_021E8A80(int);
extern void func_0217E074(int);
extern void func_021E7E08(int);
extern void func_021E64C0(int, int);
extern void func_021E7774(int, int);
extern void func_021E84F8(int, int);
void func_0217BAF4(int *p)
{
    func_021E8A80(p[0]);
    func_0217E074(p[3]);
    func_021E7E08(p[7]);
    if (p[4]) func_021E64C0(p[4], p[0x6B]);
    if (p[5]) func_021E7774(p[5], p[0x6B]);
    if (p[6]) func_021E84F8(p[6], p[0x6B]);
}
