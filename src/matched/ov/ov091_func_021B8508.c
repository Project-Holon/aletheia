/*
 * function: func_021B8508
 * address:  0x021B8508
 * packet:   pkt_ov091_021B8508
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case bodies are laid out 3, 0, 1, 2: case 3 is written first.
 *
 * symbols:
 *   func_021BB7A4  0x021BB7A4  thumb  ov091
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_02041300  0x02041300  arm
 *   func_021BB43C  0x021BB43C  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021B7CC4  0x021B7CC4  thumb  ov091
 *   func_021B892C  0x021B892C  thumb  ov091
 *   func_021BAFA0  0x021BAFA0  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_021BBE68  0x021BBE68  thumb  ov091
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct Obj;
extern void func_021BB7A4(void *p, u32 *s);
extern int func_021B9A84(u32 p);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern int func_021BB43C(int *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_020061E4(u32 id);
extern void func_021B7CC4(u8 *p);
extern void func_021B892C(u8 *p);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
extern void func_021BBE5C(int h, int f);
extern void func_021BBE68(int h, int f);
extern void func_0204B878(struct Obj *p, u16 value);

#define W(o) (*(int *)(p + (o)))

void func_021B8508(u8 *p)
{
    u8 i;
    u8 k;
    int n;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (func_021B9A84((u32)p) == 1) {
        func_02041300(0, 0, 0, 0x15, 0x20, 3, 0x10);
        for (i = 0; i < 6; i++) {
            ((u8 *)W(0x280))[i + 0x49] = 0;
        }
        for (k = 0; k < 6; k++) {
            n = func_021BB43C((int *)(*(int *)(p + k * 4 + 0x160)));
            if (n <= 5) {
                ((u8 *)W(0x280))[n + 0x49] = k + 1;
            }
        }
    }
    switch (p[0xf]) {
    case 3:
        func_0204B3DC((struct Obj *)W(0x1d8), 0);
        W(0x38) = (int)func_0201AB28(*(void **)W(0x280), W(0x2c));
        *(int *)(W(0x280) + 0x3c) = W(0x2c);
        func_020061E4(0x54c);
        func_021B7CC4(p);
        return;
    case 0:
        if (func_021B9A84((u32)p) == 1) {
            func_021B892C(p);
            return;
        }
        p[0xc] = 0x13;
        *(int *)(W(0x280) + 0x3c) = 6;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x54c);
        return;
    case 1:
        if (W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        if (func_021B9A84((u32)p) == 1) {
            func_021BBE5C(W(0x108), 0);
            func_021BBE68(W(0x10c), 1);
            p[0xc] = 0xc;
            W(0x2c) = 7;
        } else {
            p[0xc] = 0x13;
            W(0x1e8) = W(0x1e0);
            func_0204B878((struct Obj *)W(0x1e8), 9);
        }
        *(int *)(W(0x280) + 0x3c) = 7;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x551);
        return;
    case 2:
        if (W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        p[0xc] = 0x13;
        *(int *)(W(0x280) + 0x3c) = 8;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x556);
        W(0x1e8) = W(0x1e4);
        func_0204B878((struct Obj *)W(0x1e8), 8);
        return;
    }
}
