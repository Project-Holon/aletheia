/*
 * function: func_021E6728
 * address:  0x021E6728
 * packet:   pkt_ov093_021E6728
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
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021E67E4  0x021E67E4  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021D7090  0x021D7090  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B68(void *p);
extern int func_021E67E4(u32 v);
extern int func_021B9A24(u32 a, u32 b);
extern void func_021D7090(int m);
extern void func_021D7040(int m);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021E6728(int m, void *a, u32 b)
{
    u8 *e;
    void *x;
    u8 k;

    if (b == func_021D775C(4)) {
        if (func_021D5B68(func_021C7CF4(a, b)) != 0) {
            if (func_021E67E4((u16)func_021D775C(0x12)) == 0) {
                k = func_021D775C(3);
                x = func_021C7CF4(a, k);
                if (func_021B9A24(b, k) == 0 && func_021D5B68(x) == 0) {
                    func_021D7090(m);
                    e = func_021C88A4(a, 0x13, b);
                    e[4] = b;
                    e[5] = 1;
                    func_021C88C8(a, e);
                    e = func_021C88A4(a, 0x13, b);
                    e[4] = func_021D775C(3);
                    func_021C8838(e + 8, 2, 0x275);
                    func_021C8860((struct S *)(e + 8), b);
                    func_021C88C8(a, e);
                }
            }
            func_021D7040(m);
        }
    }
}
