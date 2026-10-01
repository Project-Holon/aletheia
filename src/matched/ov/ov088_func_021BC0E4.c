/*
 * function: func_021BC0E4
 * address:  0x021BC0E4
 * packet:   pkt_ov088_021BC0E4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020312F8  0x020312F8  arm
 *   d_021BD818     0x021BD818  data  a4
 *   ov088_id       0x00000058  data  a1
 */

extern void func_020312F8(void *a, void *b, int c);
extern char d_021BD818[];
extern char ov088_id[];

void func_021BC0E4(void)
{
    func_020312F8(ov088_id, d_021BD818, 0);
}
