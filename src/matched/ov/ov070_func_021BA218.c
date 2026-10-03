/*
 * function: func_021BA218
 * address:  0x021BA218
 * packet:   pkt_ov070_021BA218
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever:    `color` is a u16 local; as int the stack argument to
 *           func_0201C7D0 gains an lsls/lsrs #16 pair.
 *
 * symbols:
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_021BB724  0x021BB724  thumb  ov070
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02020F14  0x02020F14  thumb
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   d_021BBA79     0x021BBA79  data  ov070  a1
 *   func_021BA1D0  0x021BA1D0  thumb  ov070
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201EF34  0x0201EF34  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02021350  0x02021350  thumb
 *   func_0202130C  0x0202130C  thumb
 *   func_021B83A0  0x021B83A0  thumb  ov070
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;

extern int func_021B61C8(char *);
extern void func_021BB724(char *);
extern void func_020456F8(u32);
extern u32 func_02045730(u32);
extern void func_020409B4(u32);
extern int func_02020F14(u32 heap);
extern u16 *func_021B616C(char *o, int k);
extern int func_02020F20(int h, int id, u16 heap);
extern u32 func_02021014(int rec, u32 sel);
extern const u8 d_021BBA79[];
extern int func_021BA1D0(int);
extern void func_02043B5C(u32, u32);
extern void func_02045CAC(u32, u32, u32);
extern u16 func_020212B0(u16 id);
extern void func_021B61F4(void *o, int a, u32 b);
extern void func_0201EF34(u32 a, int b, u32 c);
extern void func_0201F250(u32 a0, u32 a1, u32 a2);
extern void func_0201C7D0(u32 x, s16 y, s16 z, u32 s, u32 w, u16 v);
extern u8 func_02021350(u16 id);
extern u8 func_0202130C(u16 id);
extern int func_021B83A0(char *p, int value);
extern void func_020307B0(int);
extern void func_02049238(int);

void func_021BA218(char *p)
{
    int h;
    int i;
    int idx;
    u16 *e;
    int rec;
    u32 kind;
    u16 color;
    u16 r;
    u32 w;

    if (func_021B61C8(p) == 0) {
        func_021BB724(p + 0x774);
    } else {
        w = *(u32 *)(p + 0x774);
        func_020456F8(w);
        func_020409B4(func_02045730(w));
    }
    if (*(int *)(p + 0x818) == *(int *)(p + 0x814)) {
        return;
    }
    h = func_02020F14(*(u16 *)(p + 0x544));
    for (i = 0; i < 8; i++) {
        *(u32 *)(p + i * 4 + 0x654) = 0;
        idx = *(int *)(p + 0x814) + i;
        if (idx < 0) {
            continue;
        }
        e = func_021B616C(p, idx);
        if (e == 0 || *e == 0) {
            continue;
        }
        rec = func_02020F20(h, *e, *(u16 *)(p + 0x544));
        kind = func_02021014(rec, 0xf);
        if (d_021BBA79[i] == 0) {
            if (func_021BA1D0(*e) == 1) {
                color = 0x18AD;
            } else {
                color = 0x82D;
            }
        } else {
            if (func_021BA1D0(*e) == 1) {
                color = 0x20ED;
            } else {
                color = 0x106D;
            }
        }
        func_02043B5C(*(u32 *)(p + i * 4 + 0x614), 0xd);
        func_02045CAC(*(u32 *)(p + 0x51C), 0x82, *(u32 *)(p + 0x524));
        r = func_020212B0(*e);
        if (r == 0) {
            func_021B61F4(p, 0, *e);
        } else {
            func_0201EF34(*(u32 *)(p + 0x520), 0, r);
        }
        func_0201F250(*(u32 *)(p + 0x520), *(u32 *)(p + 0x528), *(u32 *)(p + 0x524));
        func_0201C7D0(*(u32 *)(p + i * 4 + 0x614), 0, 0, *(u32 *)(p + 0x528), *(u32 *)(p + 0x530), color);
        if (kind == 4) {
            *(u32 *)(p + i * 4 + 0x654) = 4;
        } else if (kind == 5) {
            *(u32 *)(p + i * 4 + 0x654) = 5;
        } else if (kind == 1) {
            *(u32 *)(p + i * 4 + 0x654) = 6;
        } else if (func_02021350(*e) != 0xff) {
            *(u32 *)(p + i * 4 + 0x654) = 8;
        } else if (func_0202130C(*e) != 0xff) {
            *(u32 *)(p + i * 4 + 0x654) = 7;
        } else if (func_02021014(rec, 4) == 0) {
            *(u32 *)(p + i * 4 + 0x654) = 3;
        } else if (func_021B83A0(p, *e) == 0) {
            *(u32 *)(p + i * 4 + 0x654) = 2;
        } else {
            *(u32 *)(p + i * 4 + 0x654) = 1;
        }
        func_020307B0(rec);
    }
    func_02049238(h);
    *(u16 *)(p + 0x83C) = 1;
}
