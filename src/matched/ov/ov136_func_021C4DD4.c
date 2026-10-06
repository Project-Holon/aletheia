/*
 * function: func_021C4DD4
 * address:  0x021C4DD4
 * packet:   pkt_ov136_021C4DD4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4DD4 0x021C4DD4 thumb
 *   func_020433E0 0x020433E0 arm
 *   d_021C77C4 0x021C77C4 data a1
 */
extern const char d_021C77C4[];
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
void func_021C4DD4(void)
{
    func_020433E0((const struct DispVram *)d_021C77C4);
}
