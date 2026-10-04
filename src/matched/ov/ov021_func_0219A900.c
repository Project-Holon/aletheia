/*
 * function: func_0219A900
 * address:  0x0219A900
 * packet:   pkt_ov021_0219A900
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219B2E8  0x0219B2E8  thumb  ov021
 *   func_0216D7E8  0x0216D7E8  thumb  ov010
 *   func_0216D7F8  0x0216D7F8  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   func_021642A4  0x021642A4  thumb  ov010
 *   func_0216D600  0x0216D600  thumb  ov010
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021639C0  0x021639C0  thumb  ov010
 *   func_0219B334  0x0219B334  thumb  ov021
 *   func_0219B060  0x0219B060  thumb  ov021
 *   func_02164168  0x02164168  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0219B390  0x0219B390  thumb  ov021
 *   func_0216DA44  0x0216DA44  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_0219B2E8(int a, u8 *b);
extern int func_0216D7E8(void *p);
extern int func_0216D7F8(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u16 func_0216D608(void *p);
extern u32 func_021642A4(u16);
extern void func_0216D600(u32, u16);
extern int func_0219B358(u32);
extern void func_0216D5E0(u32, u16);
extern int func_021639C0(u32, u16);
extern int func_0219B334(u32);
extern int func_0219B060(void);
extern int func_02164168(int a);
extern u32 func_02197E7C(u16, u16);
extern void func_0216D438(u32, u16);
extern void func_0219B390(u32, u8 *);
extern void func_0216DA44(u32);

int func_0219A900(u32 a, u8 *b)
{
    int x;
    int y;
    int tx;
    int ty;
    u32 u;
    u32 d;
    int r;
    u32 k;

    if (func_0219B2E8(a, b + 2) == 0)
        return 0;
    if (b[1] != 0) {
        x = func_0216D7E8((void *)a);
        y = func_0216D7F8((void *)a);
        tx = func_0216D83C((void *)a);
        ty = func_0216D86C((void *)a);
        if (x == tx && y == ty) {
            u = func_021642A4(func_0216D608((void *)a));
            func_0216D600(a, u);
            if (func_0219B358(a) == 0)
                func_0216D5E0(a, u);
            b[1] = 0;
        }
    }
    d = func_0216D608((void *)a);
    r = func_021639C0(a, d);
    if (r & 1) {
        b[1] = 1;
        d = func_021642A4(d);
        r = func_021639C0(a, d);
    }
    k = 12;
    if (func_0219B334(a) != 0 && func_0219B060() == 1 && func_02164168(a) == 1)
        k = 16;
    if (r != 0)
        k = 32;
    func_0216D438(a, func_02197E7C(d, k));
    if (func_0219B358(a) == 1)
        func_0219B390(a, b + 4);
    func_0216DA44(a);
    b[0] = 2;
    return 1;
}
