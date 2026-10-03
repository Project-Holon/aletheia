/*
 * function: func_021BC418
 * address:  0x021BC418
 * packet:   pkt_ov093_021BC418
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021B9C50  0x021B9C50  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C5108  0x021C5108  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021D8548  0x021D8548  thumb  ov093
 *   func_021DCFB4  0x021DCFB4  thumb  ov093
 *   func_021BC4CC  0x021BC4CC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Slot {
    u32 kind : 3;
    u32 rest : 29;
};

extern u8 *func_021B9AEC(u8 *p, int i);
extern void func_021CD4B0(void *w, u32 id, ...);
extern void func_021B9C50(u8 **p, int k, u8 **o1, u8 **o2);
extern int func_021D5B68(void *p);
extern void func_021C5108(u8 *p, u8 *a, int b);
extern int func_021EF948(int k);
extern int func_021D62C4(void *p, int i);
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021D8548(void *p);
extern void func_021DCFB4(void *p);
extern void func_021BC4CC(u8 *p, int a, int b, u8 *c, u8 *d);

void func_021BC418(u8 *p, int a, int b)
{
    u8 *t;
    u8 *v1;
    u8 *v2;
    int k;

    if (b == 1)
        return;
    if (b == 0)
        return;
    t = func_021B9AEC(*(u8 **)(p + 8), a);
    func_021CD4B0(*(void **)(p + 0xc), 0x48, a, b);
    func_021B9C50((u8 **)t, b, &v1, &v2);
    if (func_021D5B68(v1) == 0)
        func_021C5108(p, v1, 1);
    if (func_021D5B68(v2) == 0) {
        if (func_021EF948(2) != 0) {
            k = 0x20;
            if (func_021D62C4(v2, k) != 0)
                func_021C5620(p, v2, k, 0);
            k = 0x1e;
            if (func_021D62C4(v2, k) != 0)
                func_021C5620(p, v2, k, 0);
        }
        func_021D8548(v2);
        func_021DCFB4(v2);
    }
    func_021BC4CC(p + 0x1ab8, b, a, v2, *(u8 **)(p + 8));
}
