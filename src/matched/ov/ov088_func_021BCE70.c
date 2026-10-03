/*
 * function: func_021BCE70
 * address:  0x021BCE70
 * packet:   pkt_ov088_021BCE70
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf (four instructions and two pool words) between
 * func_021BCE3C and func_021BCE80: loads the pointer held at 0x021BDA20 and
 * tail-calls func_0202F0B0 with it.  Its only reference is the callback
 * pointer 0x021BCE71 in func_021BCE80.
 *
 * symbols:
 *   func_0202F0B0  0x0202F0B0  thumb
 *   d_021BDA20     0x021BDA20  data  a4
 */

extern void *d_021BDA20;
typedef unsigned char  u8;
extern void func_0202F0B0(u8 *p);

void func_021BCE70(void)
{
    func_0202F0B0(d_021BDA20);
}
