/*
 * function: func_021E19F8
 * address:  0x021E19F8
 * packet:   pkt_ov093_021E19F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021E1AE4  0x021E1AE4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */

typedef struct Ent { unsigned short a; unsigned short b; unsigned char c, d, e, f; } Ent;

extern int func_021D775C(int key);
extern int func_021C7CF4(int a, int b);
extern int func_021E1AE4(void *m, int x, Ent *out);
extern int func_021D76BC(int a, int b);

void func_021E19F8(int a, int b, int c, int d)
{
    Ent e;

    if (b == func_021D775C(2) && func_021E1AE4((void *)func_021C7CF4(a, b), d, &e) == 0)
        func_021D76BC(34, 26);
}
