/*
 * function: func_021BA9D4
 * address:  0x021BA9D4
 * packet:   pkt_ov088_021BA9D4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   d_021BD60C     0x021BD60C  data  ov088  a4
 */

typedef unsigned int   u32;
extern void func_0204335C(u32 keep);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern char d_021BD60C[];

void func_021BA9D4(void)
{
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BD60C);
}
