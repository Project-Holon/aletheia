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
#include "../include/Obj01514.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;

extern int func_021B61C8(u8 *p);
extern void func_021BB724(void **p);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec;
struct WordSet;
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32);
extern int func_02020F14(u32 heap);
extern void *func_021B616C(u8 *p, int i);
extern int func_02020F20(int h, int id, u16 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern const u8 d_021BBA79[];
extern int func_021BA1D0(int);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u16 func_020212B0(u16 id);
extern void func_021B61F4(u8 *p, int a, unsigned int b);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u8 func_02021350(u16 id);
extern u32 func_0202130C(u32 id);
extern int func_021B83A0(char *p, int value);
extern void func_020307B0(void *p);
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

    if (func_021B61C8((u8 *)p) == 0) {
        func_021BB724((void **)(p + 0x774));
    } else {
        w = ((struct Obj01514 *)p)->f774;
        func_020456F8((struct Descriptor *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    if (((struct Obj01514 *)p)->f818 == ((struct Obj01514 *)p)->f814) {
        return;
    }
    h = func_02020F14(((struct Obj01514 *)p)->f544);
    for (i = 0; i < 8; i++) {
        *(u32 *)(p + i * 4 + 0x654) = 0;
        idx = ((struct Obj01514 *)p)->f814 + i;
        if (idx < 0) {
            continue;
        }
        e = func_021B616C((u8 *)p, idx);
        if (e == 0 || *e == 0) {
            continue;
        }
        rec = func_02020F20(h, *e, ((struct Obj01514 *)p)->f544);
        kind = func_02021014((struct Rec *)rec, 0xf);
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
        func_02043B5C((struct CharBuf *)(*(u32 *)(p + i * 4 + 0x614)), 0xd);
        func_02045CAC((struct MsgBank *)(((struct Obj01514 *)p)->f51C), 0x82, (void *)(((struct Obj01514 *)p)->f524));
        r = func_020212B0(*e);
        if (r == 0) {
            func_021B61F4((u8 *)p, 0, *e);
        } else {
            func_0201EF34((struct WordSet *)(((struct Obj01514 *)p)->f520), 0, r);
        }
        func_0201F250((struct WordSet *)(((struct Obj01514 *)p)->f520), (void *)(((struct Obj01514 *)p)->f528), (void *)(((struct Obj01514 *)p)->f524));
        func_0201C7D0((void *)(*(u32 *)(p + i * 4 + 0x614)), 0, 0, (void *)(((struct Obj01514 *)p)->f528), (void *)(((struct Obj01514 *)p)->f530), color);
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
        } else if (func_02021014((struct Rec *)rec, 4) == 0) {
            *(u32 *)(p + i * 4 + 0x654) = 3;
        } else if (func_021B83A0(p, *e) == 0) {
            *(u32 *)(p + i * 4 + 0x654) = 2;
        } else {
            *(u32 *)(p + i * 4 + 0x654) = 1;
        }
        func_020307B0((void *)rec);
    }
    func_02049238(h);
    ((struct Obj01514 *)p)->f83C = 1;
}
