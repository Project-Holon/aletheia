/*
 * function: func_021E0FB0
 * address:  0x021E0FB0
 * packet:   pkt_ov170_021E0FB0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED14C 0x021ED14C thumb
 *   func_021ED310 0x021ED310 thumb
 */

extern void func_021ED14C(int a, int b, int c);
extern void func_021ED310(char *w);

void func_021E0FB0(char *w, int x, int y)
{
    func_021ED14C((int)w, (short)x, (short)y);
    func_021ED310(w);
    *(int *)(w + 0xA180) = x;
    *(int *)(w + 0xA184) = y;
}
