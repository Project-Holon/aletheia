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
#include "../include/Obj00282.h"
#include "../include/Obj03139.h"
#include "../include/Obj09656.h"

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

extern unsigned int func_021BE17C(unsigned char *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
typedef unsigned char  u8;
extern u16 func_021A3050(u8 *p);
typedef unsigned int   u32;
extern int func_021BE194(u32 a);
extern struct Q func_021BE148(int a);
extern int func_021BE1B0(u32 a);
extern void func_021A7B08(int a, struct V3 *b);
struct VecFx32;
extern void func_021A3038(u8 *p, struct VecFx32 *out);
extern void func_0218FEA4(int a);
extern void func_0218FE78(int a, void *b);

void func_021BDFB0(char *a)
{
    char *r6 = a + 8;
    char *r4 = r6 + 0x24;
    struct Q q;
    void *r7;
    int t30;
    int x;
    int y;
    int z;

    func_021BE17C((unsigned char *)a);
    r7 = func_02188CB4((struct Obj00020 *)(*(unsigned char * *)&((struct Obj00282 *)a)->f0));
    func_021A3050(r7);
    q = func_021BE148(func_021BE194((u32)a));
    ((struct Obj09656 *)r6)->f48 = q.f3c;
    ((struct Obj09656 *)r6)->f44 = q.f38;
    t30 = q.f30;
    ((struct Obj00282 *)a)->f68 = t30;
    *(int *)&((struct Obj00282 *)a)->f6C = q.f34;
    if (t30 == 0) {
        return;
    }
    if (func_021BE1B0((u32)a) != 0) {
        func_021A7B08(*(int *)&((struct Obj00282 *)a)->f0, &q.f40);
    } else {
        func_021A3038(r7, (struct VecFx32 *)(&q.f40));
    }
    func_0218FEA4(*(int *)&((struct Obj00282 *)a)->f54);
    func_0218FE78(*(int *)&((struct Obj00282 *)a)->f4, r6 + 4);
    ((struct Obj09656 *)r6)->f0 = q.f2c;
    ((struct Obj03139 *)r4)->f0 = q.f4;
    ((struct Obj03139 *)r4)->f2 = q.f8;
    ((struct Obj03139 *)r4)->f4 = q.fc << 12;
    z = q.f28 << 12;
    y = q.f24 << 12;
    x = q.f20 << 12;
    ((struct Obj03139 *)r4)->f14 = x;
    ((struct Obj03139 *)r4)->f18 = y;
    ((struct Obj03139 *)r4)->f1C = z;
    if (q.f10 != 0) {
        z = q.f1c << 12;
        y = q.f18 << 12;
        x = q.f14 << 12;
        ((struct Obj03139 *)r4)->f8 = x;
        ((struct Obj03139 *)r4)->fC = y;
        ((struct Obj03139 *)r4)->f10 = z;
    } else {
        *(struct V3 *)(r4 + 8) = q.f40;
    }
}
