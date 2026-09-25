/*
 * function: func_021F4E58
 * address:  0x021F4E58
 * packet:   pkt_021F4E58
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F41C 0x0201F41C thumb
 */

extern void func_0201F41C(int, int, int);

int func_021F4E58(int p, int idx, unsigned short *tab, int val, unsigned char *out)
{
    unsigned char i;

    func_0201F41C(p + 0xe + 0x18 * idx, (int)tab, val);
    i = 0;
    while (i < 3 && tab[i] != 0x3000) {
        i++;
    }
    if (out != 0) {
        *out = (unsigned char)i;
    }
    return i != 0;
}
