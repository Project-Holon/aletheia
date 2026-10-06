/*
 * function: func_021C6698
 * address:  0x021C6698
 * packet:   pkt_021C6698
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020433E0  0x020433E0  arm
 *   d_021CA5CC     0x021CA5CC  data
 *
 * Addresses are Black-image addresses.
 */

struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern char d_021CA5CC[];

void func_021C6698(void *a0)
{
    func_020433E0((const struct DispVram *)d_021CA5CC);
}
