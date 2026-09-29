/*
 * function: func_021B68F0
 * address:  0x021B68F0
 * packet:   pkt_ov091_021B68F0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case 20 is written before case 19: case 19's fallback repeats case 20's
 * body and mwcc tail-merges it into the earlier copy, which puts case 20's
 * code first in the original.
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021B83D8  0x021B83D8  thumb  ov091
 *   func_021B981C  0x021B981C  thumb  ov091
 *   func_021B9020  0x021B9020  thumb  ov091
 *   func_021B9750  0x021B9750  thumb  ov091
 *   func_021B97D4  0x021B97D4  thumb  ov091
 *   func_021BB30C  0x021BB30C  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB358  0x021BB358  thumb  ov091
 *   func_021B6184  0x021B6184  thumb  ov090
 *   func_021BBE44  0x021BBE44  thumb  ov091
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BBA68  0x021BBA68  thumb  ov091
 *   func_021BC6CC  0x021BC6CC  thumb  ov091
 *   func_021BD8B0  0x021BD8B0  thumb  ov091
 *   func_021BD9C8  0x021BD9C8  thumb  ov091
 *   func_021BD8E4  0x021BD8E4  thumb  ov091
 *   func_021B61E8  0x021B61E8  thumb  ov090
 *   func_021B61FC  0x021B61FC  thumb  ov090
 *   func_0204B98C  0x0204B98C  arm
 *   func_021BA8CC  0x021BA8CC  thumb  ov091
 *   func_021BB644  0x021BB644  thumb  ov091
 *   func_021B6B24  0x021B6B24  thumb  ov091
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BCDE8  0x021BCDE8  thumb  ov091
 *   func_021BBE50  0x021BBE50  thumb  ov091
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0202208C(int, int, int, int, int, int, int);
extern int func_020221A4(void);
extern void func_021B83D8(u8 *p);
extern void func_021B981C(u8 *p);
extern void func_021B9020(u8 *p);
extern void func_021B9750(u8 *p);
extern void func_021B97D4(u8 *p);
extern void func_021BB30C(u8 *p, int s);
extern void func_020061E4(u32 id);
extern int func_021BB358(u8 *p, int s);
extern int func_021B6184(int w, int a, int b);
extern void func_021BBE44(int x);
extern void func_021BB714(u8 *p, int s, u32 k);
extern void func_021BB7E8(u8 *p, int s, u32 x);
extern void func_021BBA68(u8 *p, int s);
extern void func_021BC6CC(u8 *p);
extern void func_021BD8B0(u8 *p);
extern void func_021BD9C8(u8 *p);
extern void func_021BD8E4(u8 *p);
extern void func_021B61E8(int w, int a);
extern int func_021B61FC(int w, int a);
extern int func_0204B98C(int);
extern void func_021BA8CC(u8 *p, int s);
extern void func_021BB644(u8 *p, int s);
extern void func_021B6B24(u8 *p);
extern int func_021B9A84(u8 *p);
extern void func_021BCDE8(u8 *p);
extern void func_021BBE50(int x);
extern void func_0201C4E4(int x);
extern void func_0204A600(void);

#define W(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

typedef void (*Fn)(u8 *p);

int func_021B68F0(u8 *p)
{
    u8 i;
    Fn fn;

    switch (p[0xc]) {
    case 0:
        func_0202208C(2, 1, 1, 0, 6, 1, H(0));
        p[0xc] = 1;
        break;
    case 1:
        if (func_020221A4() == 1)
            p[0xc] = p[0xd];
        break;
    case 2:
    case 3:
    case 4:
        func_021B83D8(p);
        break;
    case 5:
        func_021B981C(p);
        break;
    case 6:
        func_021B9020(p);
        break;
    case 7:
        func_021B9750(p);
        break;
    case 9:
        func_021B97D4(p);
        break;
    case 10:
        func_021BB30C(p, *(int *)(p + W(0x2c) * 4 + 0x160));
        if (W(0x24) == 1) {
            W(0x24) = 0;
            func_020061E4(0x56f);
        }
        p[0xc] = 0xb;
    case 11:
        if (func_021BB358(p, *(int *)(p + W(0x2c) * 4 + 0x160)) == 1) {
            fn = *(Fn *)(p + 0x120);
            if (fn != 0)
                fn(p);
            else
                p[0xc] = 0x15;
        }
        break;
    case 12:
        p[0x114]++;
        if (p[0x114] > 0x10) {
            if (W(0x20) == 1) {
                if (func_021B6184(W(0x280), 0, 0) == 1) {
                    p[0xc] = 0x11;
                    func_021BBE44(W(0x108));
                    func_021BBE44(W(0x10c));
                    W(0x108) = 0;
                    W(0x10c) = 0;
                    func_021BB714(p, W(0x150), 0);
                    func_021BB7E8(p, W(0x150), 0xb0);
                    func_021BBA68(p, W(0x150));
                }
            } else {
                p[0xc] = 0x13;
            }
        }
        break;
    case 13:
        func_021BC6CC(p);
        break;
    case 14:
        func_021BD8B0(p);
        break;
    case 15:
        func_021BD9C8(p);
        break;
    case 16:
        func_021BD8E4(p);
        break;
    case 17:
        func_021B61E8(W(0x280), 2);
        p[0xc] = 0x12;
        break;
    case 18:
        if (func_021B61FC(W(0x280), 2) == 1)
            p[0xc] = 0x13;
        break;
    case 20:
        func_0202208C(0, 0, 0, 0, 6, 1, H(0));
        p[0xc] = 0x15;
        break;
    case 19:
        if (W(0x1e8) == 0 || func_0204B98C(W(0x1e8)) == 0) {
            func_0202208C(0, 0, 0, 0, 6, 1, H(0));
            p[0xc] = 0x15;
        }
        break;
    case 21:
        if (func_020221A4() == 1)
            return 1;
        break;
    }
    for (i = 0; i < 6; i++)
        func_021BA8CC(p, ((int *)(p + 0x160))[i]);
    func_021BB644(p, W(0x150));
    func_021B6B24(p);
    if (func_021B9A84(p) == 1) {
        func_021BCDE8(p);
        func_021BBE50(W(0x108));
        func_021BBE50(W(0x10c));
    }
    func_0201C4E4(W(0x140));
    func_0204A600();
    return 0;
}
