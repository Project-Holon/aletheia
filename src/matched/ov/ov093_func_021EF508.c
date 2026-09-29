/*
 * function: func_021EF508
 * address:  0x021EF508
 * packet:   pkt_ov093_021EF508
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: `t = b + r5 * 3;` as its own statement, then `t + k` (the one-line
 * `b + r5 * 3 + k` swaps the last add); `id = p[0]` re-read after the first
 * call into a u8 local hoists the load above the u16 test.
 *
 * symbols:
 *   func_021EED00  0x021EED00  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8CE8  0x021B8CE8  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   d_021F6398     0x021F6398  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void ***f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 pad[11];
    u32 f54;
    u16 f58;
    u16 f5a;
} D;

extern void func_021EED00(int a, int b);
extern int func_021B8DDC(int m);
extern int func_021B8CE8(int a, u8 b, int c);
extern void *func_021B86B8(void ***p);
extern void func_02045CAC(u32 a, u16 b, u32 c);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern D d_021F6398;

void func_021EF508(u32 a, int b, u32 *p)
{
    u8 r5 = p[1] - 1;
    int k;
    int t;
    u8 id;

    func_021EED00((u8)p[0], 0);
    id = p[0];
    if (d_021F6398.f58 == 0 &&
        func_021B8CE8((int)d_021F6398.f0, d_021F6398.f54,
                      func_021B8DDC(id))) {
        if (func_021B86B8(d_021F6398.f0) == 0 || func_021B86B8(d_021F6398.f0) == (void *)4)
            k = 1;
        else
            k = 2;
    } else {
        k = 0;
    }
    t = b + r5 * 3;
    func_02045CAC(d_021F6398.f14, t + k, d_021F6398.fc);
    func_0201F250(d_021F6398.f8, a, d_021F6398.fc);
}
