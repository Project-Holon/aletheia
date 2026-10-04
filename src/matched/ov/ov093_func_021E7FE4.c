/*
 * function: func_021E7FE4
 * address:  0x021E7FE4
 * packet:   pkt_ov093_021E7FE4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C846C  0x021C846C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C846C(u8 *p, int a, int b, int *out);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E7FE4(int a, u8 *b, int c)
{
    u8 k;
    int x;
    u8 *p;

    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        x = 0;
        if (k == 0x1f || func_021C846C(b, c, k, &x) == 0) {
            func_021D76BC(0x41, 1);
            if (x != 0)
                func_021D76BC(0x4f, 1);
        } else if (func_021D76BC(0x51, 1) != 0) {
            p = func_021C88A4(b, 4, c);
            func_021C8838(p + 4, 2, 1118);
            func_021C8860((struct S *)(p + 4), c);
            func_021C8860((struct S *)(p + 4), k);
            func_021C88C8(b, p);
        }
    }
}
