/*
 * file:     unit_021B95A0_p10.c
 * unit:     yes
 * function: func_021BAC70, func_021BACF4, func_021BAD14, func_021BAD38, func_021BAD58, func_021BAD60, func_021BADFC, func_021BAE28, func_021BAE90, func_021BAEBC
 * address:  0x021BAC70
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021BB704     0x021BB704  data  ov068  a4
 *   func_020061E4  0x020061E4  thumb
 *   func_021BB508  0x021BB508  thumb  ov068
 *   func_021BAFD8  0x021BAFD8  thumb  ov068
 *   func_02005C28  0x02005C28  thumb
 *   func_021BB000  0x021BB000  thumb
 *   func_02040804 0x02040804 arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_021BA1C4  0x021BA1C4  thumb  ov068
 *   func_02045808 0x02045808 arm
 *   func_021BA254 0x021BA254 thumb ov068
 *   func_021BA31C  0x021BA31C  thumb  ov068
 *   func_02027778  0x02027778  thumb
 *   func_02027974  0x02027974  thumb
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   func_02027858  0x02027858  thumb
 *   func_0207D658 0x0207D658 arm
 *   func_02040588 0x02040588 arm
 *   func_021BA278 0x021BA278 thumb ov068
 */
#include "../../matched/include/Obj13141.h"
#include "../../matched/include/Obj20645.h"
#include "../../matched/include/Obj09870.h"
#include "../../matched/include/Obj13142.h"
#include "../../matched/include/Obj20646.h"
#include "../../matched/include/Obj20647.h"
#include "../../matched/include/Obj02763.h"
#include "../../matched/include/Obj09871.h"
#include "../../matched/include/Obj02417.h"
#include "../../matched/include/Obj20648.h"

struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef signed char   s8;

typedef signed short  s16;

typedef unsigned int  u32;

typedef struct {
    u8  pad[0x10];
    s16 f10;
    s16 f12;
    s16 f14;
    s16 f16;
} Ent;

typedef unsigned short u16;

extern void func_020061E4(u32 id);
extern int  func_021BB508(int *rect, void *b);
extern void func_021BAFD8(u8 *p, int i);
extern void func_02005C28(u32 a);
extern void func_021BB000(u8 *p, int i, int delta);
extern u32 func_02040804(u32 layer);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021BA1C4(u8 *p, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u16 s2);
extern void func_02045808(struct U16Vec *vec);
extern void func_021BA254(u8 *);
extern int func_021BA31C(u8 *p);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void  func_02027974(void *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8    func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_0207D658(u32, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021BA278(u8 *p, u32 a, u32 b, u32 c);
void func_021BAC70(u8 *p, void *b);
void func_021BACF4(u8 *p, u32 a, u32 b);
void func_021BAD14(u8 *p, u32 v);
int func_021BAD38(u8 *p, int *q);
void func_021BAD58(void *p);
void func_021BAD60(u8 *p, u32 a, u32 b, void *c, u32 s0, u32 s1, u32 s2, u16 s3);
void func_021BADFC(u8 *p);
void func_021BAE28(u8 *p);
void func_021BAE90(void *p, u32 value);
u16 func_021BAEBC(u8 *p);
extern Ent d_021BB704[];


void func_021BAC70(u8 *p, void *b)
{
    int i;
    int r[4];
    int x;
    int y;

    for (i = 0; i < 11; i++) {
        Ent *e = &d_021BB704[i];

        y = ((struct Obj13141 *)p)->f34 + e->f12;
        x = e->f10;
        r[1] = y;
        r[0] = x;
        r[3] = y + e->f16;
        r[2] = x + e->f14;
        if (y >= 0x18 && y <= 0xa8 && r[3] >= 0x18 && r[3] <= 0xa8) {
            if (func_021BB508(r, b)) {
                func_020061E4(0x548);
                func_021BAFD8(p + 0x44, i);
                func_021BACF4(p, ((struct Obj13141 *)p)->f47, 0);
                return;
            }
        }
    }
}


void func_021BACF4(u8 *p, u32 a, u32 b)
{
    if (((struct Obj20645 *)p)->f4 == 3 || b == 1) {
        if (a == 0) {
            func_02005C28(1);
        } else {
            func_02005C28(0);
        }
    }
}


void func_021BAD14(u8 *p, u32 v)
{
    if (((struct Obj09870 *)p)->f4 < 5) {
        func_021BB000(p + 0x44, ((struct Obj09870 *)p)->f4, v);
        func_021BACF4(p, *(s8 *)(p + 0x44 + ((struct Obj09870 *)p)->f4), 0);
    }
}

/*
 * Lever: name the call result before addition (commutative operand idiom).
 * Arithmetic: unsigned word addition/subtraction wraps before signed division.
 */
int func_021BAD38(u8 *p, int *q)
{
    int n;
    n = func_02040804(((struct Obj13142 *)p)->f2);
    n = (int)((u32)n + ((struct Obj20646 *)q)->f4 - 16u) / 24;
    if ((u32)n >= 5) n = ((struct Obj13142 *)p)->f4;
    return n;
}


void func_021BAD58(void *p)
{
    ((struct Obj20647 *)p)->f3C <<= 1;
}


void func_021BAD60(u8 *p, u32 a, u32 b, void *c, u32 s0, u32 s1, u32 s2, u16 s3)
{
    int i;

    func_02082BCC(p, 0, 0x70);
    ((struct Obj02763 *)p)->f54 = 0;
    ((struct Obj02763 *)p)->f6C = s1;
    func_021BA1C4(p, a, b, (u32)c, s0, s2, s3);
    for (i = 0; i < 2; i++) {
        u8 *e = p + i * 12;

        ((struct Obj09871 *)e)->f3C = func_02045EC0(c, i + 0x22);
        ((struct Obj09871 *)e)->f40 = 0x39E3;
        ((struct Obj09871 *)e)->f44 = 0;
    }
    ((struct Obj02763 *)p)->f58 = s3;
    ((struct Obj02763 *)p)->f5C = 2;
    *(u8 * *)&((struct Obj02763 *)p)->f60 = p + 0x3c;
    ((struct Obj02763 *)p)->f64 = 1;
    ((struct Obj02763 *)p)->f68 = 0x20;
    ((struct Obj02763 *)p)->f69 = 0xc;
    ((struct Obj02763 *)p)->f6A = 0xd;
    ((struct Obj02763 *)p)->f6B = 3;
}

void func_021BADFC(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++) func_02045808((struct U16Vec *)(*(u32 *)(p + i * 12 + 60)));
    func_021BA254(p);
    func_02082BCC(p, 0, 112);
}


void func_021BAE28(u8 *p)
{
    switch (((struct Obj02417 *)p)->f56) {
    case 0:
        if (func_021BA31C(p) != 0) {
            ((struct Obj02417 *)p)->f56 = 1;
        }
        break;
    case 1:
        ((struct Obj02417 *)p)->f38 = func_02027778((struct TaskMenuTmpl *)(p + 0x58), ((struct Obj02417 *)p)->f6C);
        ((struct Obj02417 *)p)->f56 = 2;
        break;
    case 2:
        func_02027974(((struct Obj02417 *)p)->f38);
        if (func_020279E8(((struct Obj02417 *)p)->f38) != 0) {
            ((struct Obj02417 *)p)->f54 = func_02027A04(*(u8 * *)&((struct Obj02417 *)p)->f38) + 1;
            ((struct Obj02417 *)p)->f56 = 3;
            func_02027858(((struct Obj02417 *)p)->f38);
        }
        break;
    }
}

void func_021BAE90(void *p, u32 value)
{
    func_0207D658(0x04000050, 23, 8);
    func_02040588(3, 1);
    func_021BA278(p, 33, value, 0);
}


/*
 * Unlabelled leaf (halfword getter) found while matching func_021BB418.
 */
u16 func_021BAEBC(u8 *p)
{
    return ((struct Obj20648 *)p)->f54;
}
