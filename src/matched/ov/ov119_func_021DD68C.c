/*
 * function: func_021DD68C
 * address:  0x021DD68C
 * packet:   pkt_ov119_021DD68C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021E7704     0x021E7704  data  a4
 *   func_020275E4  0x020275E4  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020450F0  0x020450F0  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct {
    int a;
    int b;
} Pair;

extern const Pair d_021E7704;
extern u32 func_020275E4(void);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
struct Cfg;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void func_020452E8(struct Descriptor *d);
extern void *func_020450F0(u32, u8, u8, u8, u8, u32, u32);
extern void func_0201DD78(u32, u32, u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_0201F02C(void *a, int b, int c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);

void func_021DD68C(char *p)
{
    Pair t;
    Pair u;
    void *h;
    int q;
    void *h2;
    int i;
    int k;
    int m;
    int x;

    t = d_021E7704;
    u.a = *(int *)(p + 0x830);
    u.b = *(int *)(p + 0x834);
    func_02049B40(func_020275E4(), 0x1F, 0, 0x1A0, 0x20, *(u16 *)(p + 0x5F4));
    if (*(void **)(p + 0x5D4) != 0) {
        func_020452E8(*(void **)(p + 0x5D4));
        func_020452E8(*(void **)(p + 0x5D8));
    }
    h = func_020450F0(3, 0, 0, 0x20, 2, 13, 0);
    *(void **)(p + 0x5D4) = h;
    func_0201DD78(14, 15, 0);
    if (*(int *)(p + 0x118C) == 3 && *(int *)(p + 0x1050) != -1) {
        func_02045CAC(*(void **)(p + 0x720), 0x85, *(void **)(p + 0x730));
        func_0201C7A4(func_02045770(h), 8, 2, *(void **)(p + 0x730), *(void **)(p + 0x728));
        func_02045CAC(*(void **)(p + 0x720), *(int *)(p + 0x1050) + 0x7B, *(void **)(p + 0x730));
        func_0201C7A4(func_02045770(h), 0x88, 2, *(void **)(p + 0x730), *(void **)(p + 0x728));
    }
    func_02045334(h);
    func_02045374(h);
    i = 0;
    h2 = func_020450F0(3, 0, 3, 0x20, 8, 5, 0);
    *(void **)(p + 0x5D8) = h2;
    for (i = 0; i < 2; i++) {
        k = i * 4;
        q = *(int *)((char *)&u + k);
        if (q != 0) {
            if (*(int *)(p + 0x118C) == 3 && *(int *)(p + k + 0x1048) != -1) {
                m = 0x75;
            } else {
                m = 0x80;
            }
            func_0201DD78(1, 2, 0);
            func_02045CAC(*(void **)(p + 0x720), m, *(void **)(p + 0x734));
            func_0201F02C(*(void **)(p + 0x724), 0, q);
            func_0201F250(*(void **)(p + 0x724), *(void **)(p + 0x730), *(void **)(p + 0x734));
            x = *(int *)((char *)&t + k) * 8;
            func_0201C7A4(func_02045770(h2), x, 2, *(void **)(p + 0x730), *(void **)(p + 0x728));
            if (*(int *)(p + 0x118C) == 3 && *(int *)(p + k + 0x1048) != -1) {
                func_0201DD78(3, 4, 0);
                func_02045CAC(*(void **)(p + 0x720), *(int *)(p + k + 0x1048) + 0x76, *(void **)(p + 0x730));
                func_0201C7A4(func_02045770(h2), x + 4, 0x22, *(void **)(p + 0x730), *(void **)(p + 0x728));
            }
        }
    }
    func_02045334(h2);
    func_02045374(h2);
    func_02041B6C(3);
}
