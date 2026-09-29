/*
 * function: func_021BE700
 * address:  0x021BE700
 * packet:   pkt_ov021_021BE700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE700  0x021BE700  thumb
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 */

typedef unsigned char u8;

extern void *func_021BE4C4(void *a, int b, int c);
extern u8 *func_021BE674(void *a, int b, int c, int d);
extern void func_020477A4(void *a, int b);
extern void func_020477D4(void *a, int b);

void func_021BE700(void *p, int i, int j, int k, int flag)
{
    void *r6 = func_021BE4C4(p, i, j);
    u8 *e = func_021BE674(p, i, j, k);

    if (e == 0) {
        return;
    }
    if (flag != 0) {
        if (e[2] != 0) {
            return;
        }
        func_020477A4(r6, k);
    } else {
        if (e[2] == 0) {
            return;
        }
        func_020477D4(r6, k);
    }
    e[2] = flag;
}
