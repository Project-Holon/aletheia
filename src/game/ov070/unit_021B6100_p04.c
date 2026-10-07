/*
 * file:     unit_021B6100_p04.c
 * unit:     yes
 * function: func_021B66B8, func_021B66E8, func_021B66FC, func_021B68E8, func_021B690C, func_021B6934, func_021B6A14, func_021B6A78, func_021B6AD8, func_021B6AF0, func_021B6BC4, func_021B6C30, func_021B6C98, func_021B6D00, func_021B6D70, func_021B6DD8, func_021B6E4C, func_021B6EC8
 * address:  0x021B66B8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_021BB5DC 0x021BB5DC thumb ov070
 *   func_021B8AF4 0x021B8AF4 thumb ov070
 *   func_0202EA40  0x0202EA40  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B63F8  0x021B63F8  thumb  ov070
 *   func_021B624C  0x021B624C  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_02035C38  0x02035C38  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02007CC8  0x02007CC8  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_020362DC  0x020362DC  arm
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_021B65E8  0x021B65E8  thumb  ov070
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_021B64A0  0x021B64A0  thumb  ov070
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_02020FE4  0x02020FE4  thumb
 *   func_0200D55C  0x0200D55C  thumb
 *   func_021B7D20  0x021B7D20  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021B61F4  0x021B61F4  thumb  ov070
 *   func_0201F250  0x0201F250  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_02035C60  0x02035C60  arm
 *   func_020414EC  0x020414EC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_02028754  0x02028754  thumb
 *   d_021BB9C4  0x021BB9C4  data  a4
 */
#include "../../matched/include/Obj00002.h"

struct Obj;
struct PrintSys;
struct Row;
struct Big;
struct Blk38;
struct MsgBank;
struct WordSet;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct RangeEnt {
    u16 lo;
    u16 n;
    void (*fn)(void *);
} RangeEnt;

extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021BB5DC(int, int);
extern void func_021B8AF4(void *p);
extern s32 func_0202EA40(struct Row *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_021B61B8(u8 *p);
extern u32  func_021B63F8(u8 *p);
extern void func_021B624C(void *o, int a, int b);
extern void func_021B6138(char *p);
extern int  func_02035C38(void);
extern void func_020061E4(u32 se);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B80C4(struct Obj *o, int flag);
extern u32  func_020362DC(void);
extern void func_021B8C1C(int p, int a, int b);
extern int  func_021B65E8(u8 *p);
extern void func_021BA6A4(char *p);
extern int  func_021B64A0(void *o);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern u32 func_0200D58C(struct Blk38 *p);
extern u32   func_02020FE4(u16 a, u32 sel, u32 id);
extern void func_0200D55C(struct Blk38 *p, u8 v);
extern void func_021B7D20(struct Obj *o, int x);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_021B61F4(u8 *p, int a, unsigned int b);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BACF0(int p, int mode);
extern void func_021B6100(char *p, int k);
extern int func_021BADF0(int p);
extern int func_02035C60(void);
extern void func_020414EC(u32 i);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BB3F4(int p, int mode);
extern u32 func_02028754(struct Obj *obj, u32 n);
int func_021B66B8(void);
void func_021B66E8(int p);
void func_021B66FC(u8 *p);
int func_021B68E8(u16 id);
int func_021B690C(u16 id);
void func_021B6934(u8 *p);
void func_021B6A14(u8 *p);
void func_021B6A78(u8 *p);
void func_021B6AD8(int p);
u32 func_021B6AF0(u8 *p);
u32 func_021B6BC4(u8 *p);
u32 func_021B6C30(u8 *p);
u32 func_021B6C98(u8 *p);
u32 func_021B6D00(u8 *p);
u32 func_021B6D70(u8 *p);
u32 func_021B6DD8(u8 *p);
u32 func_021B6E4C(u8 *p);
int func_021B6EC8(u16 id);
extern const RangeEnt d_021BB9C4[8];

int func_021B66B8(void)
{
    unsigned int x;
    unsigned int y;
    if (func_02035D20(&x, &y) == 1 && x >= 0xE0 && x <= 0xF7 && y >= 0xA8 && y <= 0xBF) return 1;
    return 0;
}

/*
 * Extent ends in two zero alignment bytes.
 */
void func_021B66E8(int p)
{
    func_021BB5DC(p, 1);
    func_021B8AF4((void *)p);
}


void func_021B66FC(u8 *p)
{
    int a;

    func_0202EA40((struct Row *)(*(u32 *)&((struct Obj00002 *)p)->f850));
    if (func_0201C6B4((const struct PrintSys *)(*(u32 *)&((struct Obj00002 *)p)->f50C)) == 0)
        return;
    a = func_021B61B8(p);
    if (func_021B63F8(p)) {
        func_021B624C(p, a, func_021B61B8(p));
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        func_021B6138((char *)p);
        return;
    }
    if (func_02035C38() == 0) {
        ((struct Obj00002 *)p)->f85C = 0;
        if (((struct Obj00002 *)p)->f860 == 1) {
            func_020061E4(0x54C);
            ((struct Obj00002 *)p)->f860 = 0;
            func_02007CC8(((struct Obj00002 *)p)->f18, p + 0x20, *(u32 *)&((struct Obj00002 *)p)->f80C, 0);
            func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00002 *)p)->f6A4), 1);
            func_021BB5DC((int)p, 1);
            ((struct Obj00002 *)p)->f81C = 0;
            func_021B80C4((struct Obj *)p, 0);
            func_021B8AF4(p);
            return;
        }
    }
    if (((struct Obj00002 *)p)->f85C == 1)
        return;
    if (func_020362DC() & 5) {
        func_020061E4(0x54C);
        func_02007CC8(((struct Obj00002 *)p)->f18, p + 0x20, *(u32 *)&((struct Obj00002 *)p)->f80C, 0);
        func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00002 *)p)->f6A4), 1);
        func_021BB5DC((int)p, 1);
        ((struct Obj00002 *)p)->f81C = 0;
        func_021B80C4((struct Obj *)p, 1);
        func_021B8AF4(p);
        return;
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00002 *)p)->f6A4), 1);
        ((struct Obj00002 *)p)->f81C = 0;
        func_021B80C4((struct Obj *)p, 1);
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        func_021B6138((char *)p);
        func_021B8C1C((int)p, 4, (int)((void *)func_021B66E8));
        return;
    }
    if (func_021B66B8() == 1) {
        func_020061E4(0x551);
        func_0204B878((struct Obj *)(*(u32 *)&((struct Obj00002 *)p)->f6A4), 1);
        ((struct Obj00002 *)p)->f81C = 0;
        func_021B80C4((struct Obj *)p, 0);
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        func_021B6138((char *)p);
        func_021B8C1C((int)p, 4, (int)((void *)func_021B66E8));
        return;
    }
    if (func_021B65E8(p)) {
        ((struct Obj00002 *)p)->f860 = 1;
        func_021BA6A4((char *)p);
        func_020061E4(0x548);
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        func_021B6138((char *)p);
        return;
    }
    if (func_021B64A0(p)) {
        func_021BA6A4((char *)p);
        func_020061E4(0x548);
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        func_021B6138((char *)p);
    }
}

int func_021B68E8(u16 id)
{
    int result = 0;
    id = (u16)(id + 0xFFB4);
    if (id <= 3 && ((1 << id) & 0xB)) result = 1;
    return result;
}

int func_021B690C(u16 id)
{
    if (func_021B68E8(id)) return 1;
    if (id == 0x268 || id == 0x269) return 2;
    return 0;
}


void func_021B6934(u8 *p)
{
    void *blk;
    u8 v;

    if (func_021B68E8(((struct Obj00002 *)p)->f84C)) {
        blk = func_0200D418(func_02012EBC(((struct Obj00002 *)p)->f0));
        if (func_0200D58C(blk)) {
            v = func_02020FE4(((struct Obj00002 *)p)->f84C, 2, ((struct Obj00002 *)p)->f544);
            func_0200D55C(blk, v);
            func_021B7D20((struct Obj *)p, 1);
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3F, (void *)(((struct Obj00002 *)p)->f524));
            func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
            func_021B61F4(p, 1, ((struct Obj00002 *)p)->f84C);
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            func_021BACF0((int)p, 1);
            func_020061E4(0x7CD);
        } else {
            func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x40, (void *)(((struct Obj00002 *)p)->f524));
            func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
            func_021BACF0((int)p, 1);
        }
        func_021B6100((char *)p, (int)((void *)func_021B6A14));
    }
}


void func_021B6A14(u8 *p)
{
    if (func_021BADF0((int)p) == 0)
        return;
    if ((func_020362DC() & 3) == 0 && func_02035C60() == 0)
        return;
    func_020414EC(3);
    *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
    func_021B6138((char *)p);
    ((struct Obj00002 *)p)->f83E = 1;
    func_021BA6A4((char *)p);
    func_0204B92C(((struct Obj00002 *)p)->f6A8, 1);
    func_021BB3F4((int)p, 1);
    func_021B8AF4(p);
}


void func_021B6A78(u8 *p)
{
    if (((struct Obj00002 *)p)->f84C - 0x268 <= 1) {
        func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x38, (void *)(((struct Obj00002 *)p)->f524));
        func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021BACF0((int)p, 1);
        func_021B6100((char *)p, (int)((void *)func_021B6A14));
    }
}

void func_021B6AD8(int p) { func_021BACF0(p, 1); func_021B6100((void *)p, (int)((void *)func_021B6A14)); }


u32 func_021B6AF0(u8 *p)
{
    if (((struct Obj00002 *)p)->f848 == 0) {
        if (func_02028754(((struct Obj00002 *)p)->fC, 0)) {
            ((struct Obj00002 *)p)->f844 = 0xA;
            func_021B6100((char *)p, 0);
            return 1;
        }
        func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
        func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021B6100((char *)p, (int)((void *)func_021B6AD8));
        return 0;
    } else if (((struct Obj00002 *)p)->f848 == 1) {
        if (func_02028754(((struct Obj00002 *)p)->fC, 0)) {
            ((struct Obj00002 *)p)->f844 = 0xB;
            func_021B6100((char *)p, 0);
            return 1;
        }
        func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x39, (void *)(((struct Obj00002 *)p)->f524));
        func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021B6100((char *)p, (int)((void *)func_021B6AD8));
        return 0;
    }
    return 0;
}


u32 func_021B6BC4(u8 *p)
{
    u32 r = 1;

    if (func_02028754(((struct Obj00002 *)p)->fC, 1)) {
        ((struct Obj00002 *)p)->f844 = 7;
        func_021B6100((char *)p, 0);
        return r;
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
    func_021B6100((char *)p, (int)((void *)func_021B6AD8));
    return 0;
}


u32 func_021B6C30(u8 *p)
{
    if (func_02028754(((struct Obj00002 *)p)->fC, 2)) {
        ((struct Obj00002 *)p)->f844 = 8;
        func_021B6100((char *)p, 0);
        return 1;
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
    func_021B6100((char *)p, (int)((void *)func_021B6AD8));
    return 0;
}


u32 func_021B6C98(u8 *p)
{
    if (func_02028754(((struct Obj00002 *)p)->fC, 6)) {
        ((struct Obj00002 *)p)->f844 = 0x11;
        func_021B6100((char *)p, 0);
        return 1;
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
    func_021B6100((char *)p, (int)((void *)func_021B6AD8));
    return 0;
}


u32 func_021B6D00(u8 *p)
{
    if (func_02028754(((struct Obj00002 *)p)->fC, 4)) {
        ((struct Obj00002 *)p)->f844 = 0xF;
        func_021B6100((char *)p, 0);
        func_021B7D20((struct Obj *)p, 1);
        return 1;
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
    func_021B6100((char *)p, (int)((void *)func_021B6AD8));
    return 0;
}


u32 func_021B6D70(u8 *p)
{
    if (func_02028754(((struct Obj00002 *)p)->fC, 5)) {
        ((struct Obj00002 *)p)->f844 = 0x10;
        func_021B6100((char *)p, 0);
        return 1;
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
    func_021B6100((char *)p, (int)((void *)func_021B6AD8));
    return 0;
}


u32 func_021B6DD8(u8 *p)
{
    if (((struct Obj00002 *)p)->f848 == 0) {
        if (func_02028754(((struct Obj00002 *)p)->fC, 9)) {
            ((struct Obj00002 *)p)->f844 = 0x14;
            func_021B6100((char *)p, 0);
            return 1;
        }
        func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
        func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021B6100((char *)p, (int)((void *)func_021B6AD8));
        return 0;
    }
    return 0;
}


u32 func_021B6E4C(u8 *p)
{
    if (((struct Obj00002 *)p)->f848 == 0) {
        if (func_02028754(((struct Obj00002 *)p)->fC, 3)) {
            ((struct Obj00002 *)p)->f844 = 0xE;
            func_021B6100((char *)p, 0);
            func_021B7D20((struct Obj *)p, 1);
            return 1;
        }
        func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x3A, (void *)(((struct Obj00002 *)p)->f524));
        func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
        func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
        func_021B6100((char *)p, (int)((void *)func_021B6AD8));
        return 0;
    }
    return 0;
}


/*
 * Unlabelled leaf (push {r4,r5}, no lr) called twice by func_021B6EF8:
 * finds the entry of the 8-entry range table at 0x021BB9C4 whose
 * [lo, lo + n) holds id, or -1.
 */
int func_021B6EC8(u16 id)
{
    u32 i;
    const RangeEnt *e;

    for (i = 0; i < 8; i++) {
        e = &d_021BB9C4[i];
        if (id >= e->lo && id < e->lo + e->n)
            return i;
    }
    return -1;
}
