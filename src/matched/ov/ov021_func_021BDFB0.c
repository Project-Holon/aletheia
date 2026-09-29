/*
 * function: func_021BDFB0
 * address:  0x021BDFB0
 * packet:   pkt_ov021_021BDFB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDFB0  0x021BDFB0  thumb
 *   func_021BE17C  0x021BE17C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021BE194  0x021BE194  thumb  ov021
 *   func_021BE148  0x021BE148  thumb  ov021
 *   func_021BE1B0  0x021BE1B0  thumb  ov021
 *   func_021A7B08  0x021A7B08  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 */

typedef unsigned short u16;

struct V3 {
    int x;
    int y;
    int z;
};

struct Q {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    struct V3 f40;
};

extern int func_021BE17C(void *a);
extern int func_02188CB4(int a);
extern int func_021A3050(void);
extern int func_021BE194(void *a);
extern struct Q func_021BE148(int a);
extern int func_021BE1B0(void *a);
extern void func_021A7B08(int a, struct V3 *b);
extern void func_021A3038(int a, struct V3 *b);
extern void func_0218FEA4(int a);
extern void func_0218FE78(int a, void *b);

void func_021BDFB0(char *a)
{
    char *r6 = a + 8;
    char *r4 = r6 + 0x24;
    struct Q q;
    int r7;
    int t30;
    int x;
    int y;
    int z;

    func_021BE17C(a);
    r7 = func_02188CB4(*(int *)a);
    func_021A3050();
    q = func_021BE148(func_021BE194(a));
    *(int *)(r6 + 0x48) = q.f3c;
    *(int *)(r6 + 0x44) = q.f38;
    t30 = q.f30;
    *(int *)(a + 0x68) = t30;
    *(int *)(a + 0x6c) = q.f34;
    if (t30 == 0) {
        return;
    }
    if (func_021BE1B0(a) != 0) {
        func_021A7B08(*(int *)a, &q.f40);
    } else {
        func_021A3038(r7, &q.f40);
    }
    func_0218FEA4(*(int *)(a + 0x54));
    func_0218FE78(*(int *)(a + 4), r6 + 4);
    *(int *)r6 = q.f2c;
    *(u16 *)r4 = q.f4;
    *(u16 *)(r4 + 2) = q.f8;
    *(int *)(r4 + 4) = q.fc << 12;
    z = q.f28 << 12;
    y = q.f24 << 12;
    x = q.f20 << 12;
    *(int *)(r4 + 0x14) = x;
    *(int *)(r4 + 0x18) = y;
    *(int *)(r4 + 0x1c) = z;
    if (q.f10 != 0) {
        z = q.f1c << 12;
        y = q.f18 << 12;
        x = q.f14 << 12;
        *(int *)(r4 + 8) = x;
        *(int *)(r4 + 0xc) = y;
        *(int *)(r4 + 0x10) = z;
    } else {
        *(struct V3 *)(r4 + 8) = q.f40;
    }
}
