/*
 * function: func_021B9910
 * address:  0x021B9910
 * packet:   pkt_ov088_021B9910
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020433E0  0x020433E0  arm
 *   func_0203FC28  0x0203FC28  arm
 *   d_021BD508     0x021BD508  data  a4  ov088
 *   d_021BD420     0x021BD420  data  a4  ov088
 */

struct DispConfig;
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern char d_021BD508[];
extern char d_021BD420[];

void func_021B9910(void)
{
    func_020433E0((const struct DispVram *)d_021BD508);
    func_0203FC28((struct DispConfig *)d_021BD420);
}
