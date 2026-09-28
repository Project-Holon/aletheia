/*
 * function: func_021DFFC8
 * address:  0x021DFFC8
 * packet:   pkt_021DFFC8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E054C  0x021E054C  arm
 *
 * Submit the `i`-th word of the +0x124 block's dynamic area (base 0x44 plus
 * the +0x2c and +0x30 sizes) with the caller's value.
 */

extern void func_021E054C(void *, int);

int func_021DFFC8(char *obj, int i, int v)
{
    char *ip = *(char **)(obj + 0x124);
    int off = *(int *)(ip + 0x2c) + 0x44 + *(int *)(ip + 0x30) + i * 4;

    func_021E054C(ip + off, v);
    return 0;
}

