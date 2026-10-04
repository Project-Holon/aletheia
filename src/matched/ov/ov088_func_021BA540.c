/*
 * function: func_021BA540
 * address:  0x021BA540
 * packet:   pkt_ov088_021BA540
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two 0/-2 result tests are small switches: their compare chain puts
 * both bodies after a shared `b` to the tail, which the outer switch's
 * out-of-range `bhi` reuses. The countdown is `-= 1` (re-reads the byte).
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_021BB9DC  0x021BB9DC  thumb  ov088
 *   func_020090E0  0x020090E0  thumb
 *   func_021BC080  0x021BC080  thumb  ov088
 *   func_021BBF1C  0x021BBF1C  thumb  ov088
 *   func_021BBD80  0x021BBD80  thumb  ov088
 *   func_021BBFA8  0x021BBFA8  thumb  ov088
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_0202EB44  0x0202EB44  thumb
 *   func_021BBE3C  0x021BBE3C  thumb  ov088
 *   func_021BBF98  0x021BBF98  thumb  ov088
 *   func_020362DC  0x020362DC  arm
 *   func_021BC024  0x021BC024  thumb  ov088
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 */
#include "../include/Obj00339.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
struct Sub020090B0Obj;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_021BB9DC(char *, int);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern int func_021BC080(char *p, int v);
extern void func_021BBF1C(char *p, u32 a1);
extern void func_021BBD80(char *p);
extern int func_021BBFA8(char *p);
extern u32 func_0201FEBC(u8 *);
extern int func_0202EB44(void);
extern void func_021BBE3C(char *p);
extern void func_021BBF98(char *p);
extern u32 func_020362DC(void);
extern void func_021BC024(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);

int func_021BA540(char *p)
{
    void *t;
    u32 r;
    switch (((struct Obj00339 *)p)->f12A) {
    case 0:
        func_020434DC(6, 0);
        func_021BB9DC(p, 0);
        if (func_020090E0(((struct Obj00339 *)p)->fC) == 0) {
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 0;
            return func_021BC080(p, 1);
        }
        ((struct Obj00339 *)p)->f12B = 8;
        ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 1:
        if (((struct Obj00339 *)p)->f12B != 0) {
            ((struct Obj00339 *)p)->f12B -= 1;
            break;
        }
        func_021BBF1C(p, 0x1a);
        func_021BBD80(p);
        ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 2:
        if (func_021BBFA8(p) == 0) {
            func_021BC024(p);
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        }
        break;
    case 3:
        r = func_0201FEBC(*(u8 * *)&((struct Obj00339 *)p)->f7C);
        switch (r) {
        case 0:
            if (func_0202EB44() == 0) {
                func_021BBF1C(p, 0x11);
                ((struct Obj00339 *)p)->f12A = 5;
            } else {
                ((struct Obj00339 *)p)->f12C = 0;
                ((struct Obj00339 *)p)->f12A = 4;
            }
            break;
        case (u32)-2:
            func_021BBF1C(p, 0x1b);
            ((struct Obj00339 *)p)->f12A = 7;
            break;
        }
        break;
    case 4:
        func_021BBE3C(p);
        func_021BBF98(p);
        ((struct Obj00339 *)p)->f12A = 0;
        return func_021BC080(p, 1);
    case 5:
        if (func_021BBFA8(p) == 0)
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 6:
        if (func_020362DC() & 3) {
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 4;
        }
        break;
    case 7:
        if (func_021BBFA8(p) == 0) {
            func_021BC024(p);
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        }
        break;
    case 8:
        r = func_0201FEBC(*(u8 * *)&((struct Obj00339 *)p)->f7C);
        switch (r) {
        case 0:
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 4;
            break;
        case (u32)-2:
            func_021BBF1C(p, 0x1a);
            ((struct Obj00339 *)p)->f12A = 2;
            break;
        }
        break;
    }
    func_0201C4E4(((struct Obj00339 *)p)->f68);
    t = ((struct Obj00339 *)p)->f68;
    if (((struct Obj00339 *)p)->fF4 != 0 && func_0201C6C4(t, func_02045770(((struct Obj00339 *)p)->fF0)) == 0) {
        func_02045334(((struct Obj00339 *)p)->fF0);
        ((struct Obj00339 *)p)->fF4 = 0;
    }
    return 7;
}
