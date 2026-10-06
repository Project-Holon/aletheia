/*
 * function: func_021E57E8
 * address:  0x021E57E8
 * packet:   pkt_ov119_021E57E8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203FC28 0x0203FC28 arm
 *   d_021E7D20 0x021E7D20 data a4
 */
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern const char d_021E7D20[];
void func_021E57E8(int i)
{
    func_0203FC28((struct DispConfig *)(d_021E7D20 + i * 16));
}
