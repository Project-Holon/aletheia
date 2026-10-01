/*
 * function: func_021BC114
 * address:  0x021BC114
 * packet:   pkt_ov088_021BC114
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020312F8  0x020312F8  arm
 *   d_021BD824     0x021BD824  data  a4
 *   ov088_id       0x00000058  data  a1
 */

extern void func_020312F8(void *a, void *b, int c);
extern char d_021BD824[];
extern char ov088_id[];

void func_021BC114(void)
{
    func_020312F8(ov088_id, d_021BD824, 2);
}
