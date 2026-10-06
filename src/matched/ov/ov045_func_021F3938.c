/*
 * function: func_021F3938
 * address:  0x021F3938
 * packet:   pkt_ov045_021F3938
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 */

typedef unsigned short u16;

extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern void *func_021BE674(void *p, int i, u16 j, u16 k);
extern void func_021BE6B0(unsigned char *p, int v);

void func_021F3938(void *a0, int a1, int a2, int a3)
{
    int r4, r7;

    if (a1) {
        r4 = 1;
        r7 = 0;
    } else {
        r4 = 0;
        r7 = 1;
    }
    if (a3 != 1) {
        a2 += 3;
    }
    func_021BE700(a0, 0, a2, r4, 1);
    func_021BE700(a0, 0, a2, r7, 0);
    func_021BE6CC((int)a0, 0, (u16)a2, (u16)r4, 0);
    func_021BE6B0(func_021BE674(a0, 0, a2, r4), 1);
}
