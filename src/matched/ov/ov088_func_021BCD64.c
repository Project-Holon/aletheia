/*
 * function: func_021BCD64
 * address:  0x021BCD64
 * packet:   pkt_ov088_021BCD64
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020312F8  0x020312F8  arm
 *   d_021BD574     0x021BD574  data  a4
 *   ov088_id       0x00000058  data  a1
 */

struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_020312F8(void *a, void *b, int c);
extern char d_021BD574[];
extern char ov088_id[];

int func_021BCD64(int a0)
{
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x81);
    func_020312F8(ov088_id, d_021BD574, 0);
    return 1;
}
