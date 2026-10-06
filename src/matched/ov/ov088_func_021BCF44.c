/*
 * function: func_021BCF44
 * address:  0x021BCF44
 * packet:   pkt_ov088_021BCF44
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
 *   d_021BD9B0     0x021BD9B0  data  a4
 */

typedef unsigned int u32;

typedef struct Banks {
    u32 w[12];
} Banks;

extern Banks d_021BD9B0;

extern void func_0204335C(u32 keep);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);

void func_021BCF44(void)
{
    Banks b = d_021BD9B0;

    func_0204335C(0);
    func_020433E0((const struct DispVram *)(&b));
}
