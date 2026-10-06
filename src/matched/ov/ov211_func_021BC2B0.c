/*
 * function: func_021BC2B0
 * address:  0x021BC2B0
 * packet:   pkt_021BC2B0
 * region:   ov211
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   d_021BC990    0x021BC990 data ov211
 */

typedef struct
{
    int v[12];
} S021BC2B0;

typedef unsigned int   u32;
extern void func_0204335C(u32 keep);
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern S021BC2B0 d_021BC990;

void func_021BC2B0(void)
{
    S021BC2B0 buf = d_021BC990;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)(&buf));
}
