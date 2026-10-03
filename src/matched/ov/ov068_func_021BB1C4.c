/*
 * function: func_021BB1C4
 * address:  0x021BB1C4
 * packet:   pkt_ov068_021BB1C4
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021BA7C0 receives a fifth (stack) argument, w + 0x104, that its own
 * body never reads.
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021BA03C  0x021BA03C  thumb  ov068
 *   func_021BA65C  0x021BA65C  thumb  ov068
 *   func_021BA7C0  0x021BA7C0  thumb  ov068
 *   func_021BA448  0x021BA448  thumb  ov068
 *   func_021BA730  0x021BA730  thumb  ov068
 *   func_021BA9C0  0x021BA9C0  thumb  ov068
 *   func_021BA668  0x021BA668  thumb  ov068
 *   func_021BA9E0  0x021BA9E0  thumb  ov068
 *   func_021BB0E4  0x021BB0E4  thumb  ov068
 *   func_021BB138  0x021BB138  thumb  ov068
 *   func_021BA694  0x021BA694  thumb  ov068
 *   func_021BB4D4  0x021BB4D4  thumb  ov068
 *   func_021BB4A4  0x021BB4A4  thumb  ov068
 *   func_021BB418  0x021BB418  thumb  ov068
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071F0  0x020071F0  thumb
 *   func_021BB0D0  0x021BB0D0  thumb  ov068
 *   func_021BAF0C  0x021BAF0C  thumb  ov068
 *   func_021BAEC4  0x021BAEC4  thumb  ov068
 *   func_021BA9FC  0x021BA9FC  thumb  ov068
 *   func_021BA9F0  0x021BA9F0  thumb  ov068
 *   func_021BAF38  0x021BAF38  thumb  ov068
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a;
    u8  b;
    u8  pad5[3];
    u32 c;
} Blk;

extern int  func_0201C6B4(int a);
extern void func_021BA03C(int *p);
extern int  func_021BA65C(u8 *p, int *out);
extern void func_021BA7C0(u8 *p, void *a1, void *a2, void *a3, void *a4);
extern void func_021BA448(u8 *p, u8 *a, u8 *b);
extern int  func_021BA730(u8 *p);
extern void func_021BA9C0(u8 *p, u8 *w);
extern u32  func_021BA668(u8 *p);
extern void func_021BA9E0(u8 *p, Blk *out);
extern int  func_021BB0E4(u8 *p, Blk *b);
extern void func_021BB138(void *p, int v);
extern void func_021BA694(u8 *p);
extern void func_021BB4D4(void *a, u32 b, u8 *p);
extern void func_021BB4A4(void *a, u32 b, u8 *p);
extern void func_021BB418(void *a0, u32 *st, u8 *base);
extern u32  func_020120F4(u32 a);
extern u32  func_02012EBC(u32 a);
extern int  func_020071F0(u32 a);
extern u32  func_021BB0D0(Blk *b);
extern void func_021BAF0C(void *p, u32 id, u32 value);
extern void func_021BAEC4(void *a, u32 b, u32 c);
extern void func_021BA9FC(u8 *p, u8 v);
extern void func_021BA9F0(u8 *p, int v);
extern int  func_021BAF38(u8 *p);

void func_021BB1C4(void *a, u32 *st, u8 *w)
{
    Blk b50;
    Blk b44;
    Blk b38;
    Blk b2C;
    Blk b20;
    Blk b14;
    Blk b8;
    int k;
    int r;

    if (func_0201C6B4(*(int *)(w + 0x258)) == 0)
        return;
    switch (*st) {
    case 0:
        func_021BA03C((int *)(w + 0xE4));
        if (func_021BA65C(w + 0x104, 0) == 0)
            func_021BA7C0(w + 0x148, w + 0xE4, w + 0x1A0, w, w + 0x104);
        func_021BA448(w + 0x104, w + 0xE4, w + 0x148);
        if (func_021BA730(w + 0x104))
            func_021BA9C0(w + 0x148, w);
        if (func_021BA65C(w + 0x104, &k)) {
            switch (k) {
            case 0:
                if (func_021BA668(w + 0x104))
                    func_021BB138(a, (int)func_021BB4D4);
                break;
            case 2:
                **(int **)(w + 0x26C) = 1;
                func_021BA9E0(w + 0x148, &b50);
                if (func_021BB0E4(w + 0x248, &b50)) {
                    func_021BB138(a, (int)func_021BB4A4);
                } else {
                    func_021BA694(w + 0x104);
                    func_021BB138(a, (int)func_021BB418);
                }
                break;
            case 1:
                if (func_021BA668(w + 0x104)) {
                    func_021BA9E0(w + 0x148, &b44);
                    if (func_021BB0E4(w + 0x248, &b44)) {
                        func_021BB138(a, (int)func_021BB4A4);
                    } else {
                        func_021BA694(w + 0x104);
                        func_021BB138(a, (int)func_021BB418);
                    }
                }
                break;
            }
        }
        r = func_020071F0(func_02012EBC(func_020120F4(*(u32 *)(*(u8 **)(w + 0x26C) + 4))));
        func_021BA9E0(w + 0x148, &b38);
        if (b38.b == 0 && r != 0)
            *st = 1;
        break;
    case 1:
        func_021BA9E0(w + 0x148, &b2C);
        func_021BAF0C(w + 0x1D8, 0x20, func_021BB0D0(&b2C));
        func_021BA9FC(w + 0x148, 1);
        *st = 5;
        break;
    case 2:
        func_021BA9E0(w + 0x148, &b20);
        func_021BAEC4(w + 0x1D8, 0x16, func_021BB0D0(&b20));
        func_021BA9F0(w + 0x148, 0);
        *st = 5;
        break;
    case 3:
        func_021BA9E0(w + 0x148, &b14);
        func_021BAEC4(w + 0x1D8, 0x16, func_021BB0D0(&b14));
        func_021BA9F0(w + 0x148, 0);
        *st = 5;
        break;
    case 4:
        func_021BA9E0(w + 0x148, &b8);
        func_021BAF0C(w + 0x1D8, 0x24, func_021BB0D0(&b8));
        func_021BA9F0(w + 0x148, 1);
        *st = 5;
        break;
    case 5:
        if (func_021BAF38(w + 0x1D8))
            *st = 0;
        break;
    }
}
