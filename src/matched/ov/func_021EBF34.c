/*
 * function: func_021EBF34
 * address:  0x021EBF34
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Release slot i of the 0x9E74 array when non-null.
 *   CLOSES the register-order residue: `struct S { char pad[0x9E74]; int arr[1]; }`
 *   with `p->arr[i]` gives the image's r4 = p+0x9E74 / r5 = i*4; a plain
 *   `char *p` plus `p + i * 4 + 0x9E74` puts the index in r1 and the constant
 *   in r5 instead.
 */


extern void func_0204B3B4(int);
struct S { char pad[0x9E74]; int arr[1]; };
void func_021EBF34(struct S *p, int i)
{
    if (p->arr[i] != 0) {
        func_0204B3B4(p->arr[i]);
        p->arr[i] = 0;
    }
}
