/*
 * function: func_021848D0
 * address:  0x021848D0
 * packet:   pkt_ov023_021848D0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call: apply the VRAM bank descriptor at 0x02186ACC.
 *
 * symbols:
 *   func_020433E0  0x020433E0  arm
 *   d_02186ACC     0x02186ACC  data  ov023  a4
 */
struct DispVram;
extern const struct DispVram d_02186ACC;
extern void func_020433E0(const struct DispVram *);

void func_021848D0(void)
{
    func_020433E0(&d_02186ACC);
}
