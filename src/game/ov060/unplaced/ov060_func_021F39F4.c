/*
 * function: func_021F39F4
 * address:  0x021F39F4
 * packet:   pkt_ov060_021F39F4
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     closes docs/notes/ov060_func_021F39F4.c.txt: the Thumb callee at
 *           0x021BE6BC is ov021's leaf, now matched (ov021 token); the
 *           function is 52 bytes, the rest of the handed 492 is data.
 *
 * symbols:
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 */

typedef unsigned char u8;

extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern int func_021BE6BC(int *p);
extern void func_021BE4B4(char *p, int i, int j, int v);

void func_021F39F4(u8 *a, void *p)
{
    if (a[1] != 0) {
        if (func_021BE6BC(func_021BE674(p, 0, 0x14, 0)) != 0) {
            func_021BE4B4(p, 0, 0x14, 1);
            a[1] = 0;
        }
    }
}
