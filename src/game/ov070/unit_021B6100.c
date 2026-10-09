/*
 * file:     unit_021B6100.c
 * unit:     yes
 * function: func_021B6100, func_021B6138, func_021B616C, func_021B619C, func_021B61B8, func_021B61C8, func_021B61F4, func_021B6204, func_021B621C, func_021B624C, func_021B6288, func_021B6300, func_021B6374, func_021B63F8, func_021B64A0, func_021B6554, func_021B65E8, func_021B66B8, func_021B66E8, func_021B66FC, func_021B68E8, func_021B690C, func_021B6934, func_021B6A14, func_021B6A78, func_021B6AD8, func_021B6AF0, func_021B6BC4, func_021B6C30, func_021B6C98, func_021B6D00, func_021B6D70, func_021B6DD8, func_021B6E4C, func_021B6EC8
 * address:  0x021B6100
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
 *   func_02036270 0x02036270 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021B9850 0x021B9850 thumb ov070
 *   func_021B9AAC 0x021B9AAC thumb ov070
 *   func_021BA218 0x021BA218 thumb ov070
 *   func_021B81F4 0x021B81F4 thumb ov070
 *   func_020081DC 0x020081DC thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_02007F7C 0x02007F7C thumb
 *   func_02007FA0 0x02007FA0 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF6C 0x0201EF6C thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_02008298  0x02008298  thumb
 *   func_02008288  0x02008288  thumb
 *   func_02008270  0x02008270  thumb
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_021BAF38  0x021BAF38  thumb  ov070
 *   func_021BA96C  0x021BA96C  thumb  ov070
 *   func_021BAAA4  0x021BAAA4  thumb  ov070
 *   func_02035CB8  0x02035CB8  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_0202EDE4  0x0202EDE4  thumb
 *   func_021BA654  0x021BA654  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_0203633C  0x0203633C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02035D20 0x02035D20 arm
 *   func_021BB5DC 0x021BB5DC thumb ov070
 *   func_021B8AF4 0x021B8AF4 thumb ov070
 *   func_0202EA40  0x0202EA40  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02035C38  0x02035C38  arm
 *   func_02007CC8  0x02007CC8  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_0200D55C  0x0200D55C  thumb
 *   func_021B7D20  0x021B7D20  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_020414EC  0x020414EC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_02028754  0x02028754  thumb
 *   d_021BB9C4  0x021BB9C4  data  a4
 */
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj20659.h"
#include "../../matched/include/Obj20660.h"
#include "../../matched/include/Obj20661.h"
#include "../../matched/include/Obj20662.h"

struct Item;
struct WordSet;
struct MyItemSave;
struct Obj;
struct PrintSys;
struct Row;
struct Big;
struct Blk38;
struct MsgBank;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short s16;

typedef struct Obj_021B6288 {
    unsigned char pad000[0x14];
    void *gfx;
    unsigned char pad018[0x810 - 0x18];
    int f810;
    int f814;
} Obj_021B6288;

typedef struct Obj_021B6300 {
    unsigned char pad000[0x810];
    int a;
    int b;
} Obj_021B6300;

typedef struct Obj {
    unsigned char pad000[0x810];
    int a;
    int b;
} Obj;

typedef signed int     s32;

typedef struct RangeEnt {
    u16 lo;
    u16 n;
    void (*fn)(void *);
} RangeEnt;

extern int func_02036270(int a0, int a1);
extern u8 func_020355C4(void);
extern void func_021B9850(char *p);
extern void func_021B9AAC(char *p);
extern void func_021BA218(char *p);
extern void func_021B81F4(u8 *p);
extern struct Item *func_020081DC(u8 *base, u32 id, u32 index);
extern u32 func_02020FE4(u16 a, u32 sel, u32 id);
extern unsigned int func_02007F7C(const struct Item *arr, unsigned int n);
extern u32 func_02007FA0(u8 *base, u32 id);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern void MI_CpuCopy8(const void *, void *, unsigned int);
extern void func_02008298(struct MyItemSave *p, u16 v);
extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern void func_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b);
extern void func_021BA6A4(char *p);
extern void func_021BAF38(int p, int val);
extern void func_021BA96C(int p, unsigned sel);
extern void func_021BAAA4(int p, int mode);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int func_02035C60(void);
extern void func_021B80C4(struct Obj *o, int flag);
extern u32 func_0202EDE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_021BA654(char *p);
extern void func_020061E4(u32 se);
extern unsigned int func_0203633C(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021BB5DC(int, int);
extern void func_021B8AF4(void *p);
extern s32 func_0202EA40(struct Row *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int  func_02035C38(void);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32  func_020362DC(void);
extern void func_021B8C1C(int p, int a, int b);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *sys);
extern u32 func_0200D58C(struct Blk38 *p);
extern void func_0200D55C(struct Blk38 *p, u8 v);
extern void func_021B7D20(struct Obj *o, int x);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021BACF0(int p, int mode);
extern int func_021BADF0(int p);
extern void func_020414EC(u32 i);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BB3F4(int p, int mode);
extern u32 func_02028754(struct Obj *obj, u32 n);
void func_021B6100(char *p, int k);
void func_021B6120(char *p);
void func_021B6138(char *p);
void *func_021B616C(u8 *p, int i);
int func_021B619C(int a, int b, unsigned int id);
int func_021B61B8(u8 *p);
int func_021B61C8(u8 *p);
void func_021B61F4(u8 *p, int a, unsigned int b);
void func_021B6204(u8 *p, int a, unsigned int b, int c, int d);
void func_021B621C(u8 *p, int a, int b);
void func_021B624C(void *p, int a, int b);
void func_021B6288(Obj_021B6288 *o, int a, int b);
int func_021B6300(Obj_021B6300 *o, int n, int k);
int func_021B6374(Obj *o, int n, int k);
u32 func_021B63F8(u8 *p);
int func_021B64A0(void *o);
int func_021B6554(void *o);
int func_021B65E8(u8 *p);
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




void func_021B6100(char *p, int k)
{
    *(int *)&((struct Obj00002 *)p)->f4F8 = k;
    func_02036270(((struct Obj00002 *)p)->f86C, ((struct Obj00002 *)p)->f870);
}




void func_021B6120(char *p)
{
    ((struct Obj20659 *)p)->f818 = 0xFFFF;
    func_021B6138(p);
}




void func_021B6138(char *p)
{
    if (func_020355C4() == 0)
        func_021B9850(p);
    else
        func_021B9AAC(p);
    func_021BA218(p);
    func_021B81F4((u8 *)p);
    ((struct Obj20660 *)p)->f83E = 1;
}




void *func_021B616C(u8 *p, int i)
{
    if (*(int *)&((struct Obj00002 *)p)->f81C) return (void *)((unsigned int)p + 0x20U + (unsigned int)i * 4U);
    return func_020081DC(((struct Obj00002 *)p)->f18, (u16)(((struct Obj00002 *)p)->f80C), (u16)i);
}




/*
 * extent: two bytes of zero alignment follow the 26-byte function.
 * lever: enum quotient preserves its r1 web and the copy to return r0.
 * The signed quotient is multiplied with unsigned modular arithmetic.
 */
int func_021B619C(int a, int b, unsigned int id)
{
    typedef enum { HALF_ZERO } Half;
    Half half;
    half = (Half)((int)func_02020FE4((u16)a, 0, id) / 2);
    return (int)((unsigned int)half * (unsigned int)b);
}




int func_021B61B8(u8 *p)
{
    return (int)(*(unsigned int *)&((struct Obj00002 *)p)->f810 + *(unsigned int *)&((struct Obj00002 *)p)->f814 + 1U);
}




int func_021B61C8(u8 *p)
{
    if (*(int *)&((struct Obj00002 *)p)->f81C) return func_02007F7C((const struct Item *)(p + 0x20), 0x136);
    return func_02007FA0(((struct Obj00002 *)p)->f18, ((struct Obj00002 *)p)->f80C);
}




void func_021B61F4(u8 *p, int a, unsigned int b)
{
    func_0201EF40(((struct Obj20661 *)p)->f520, a, b);
}




/*
 * Extent ends in two zero alignment bytes.
 */
void func_021B6204(u8 *p, int a, unsigned int b, int c, int d)
{
    func_0201EF6C(((struct Obj20662 *)p)->f520, a, b, c, d);
}




void func_021B621C(u8 *p, int a, int b)
{
    int tmp;
    MI_CpuCopy8(p + 0x20 + (int)((unsigned int)a * 4U), &tmp, 4);
    MI_CpuCopy8(p + 0x20 + (int)((unsigned int)b * 4U), p + 0x20 + (int)((unsigned int)a * 4U), 4);
    MI_CpuCopy8(&tmp, p + 0x20 + (int)((unsigned int)b * 4U), 4);
}




void func_021B624C(void *p, int a, int b)
{
    if (a == b) return;
    if (a < b) {
        for (; a < b; a++) func_021B621C(p, a, a + 1);
    } else {
        for (; a > b; a--) func_021B621C(p, a, a - 1);
    }
}





void func_021B6288(Obj_021B6288 *o, int a, int b)
{
    s16 s[2];

    func_02008298(o->gfx, a);
    func_02008288(o->gfx, (u16)a, o->f810, o->f814 + 1);
    func_02008270(o->gfx, (u16)b, &s[1], &s[0]);
    o->f810 = s[1];
    o->f814 = s[0] - 1;
    func_021BA6A4((char *)o);
    func_021BAF38((int)o, b);
    func_021BA96C((int)o, b);
    func_021BAAA4((int)o, b);
}





int func_021B6300(Obj_021B6300 *o, int n, int k)
{
    int a, b;

    if (n == 0)
        return 0;
    a = o->a;
    b = o->b;
    if (a == 5 && b + 7 < n) {
        o->b = o->b + 1;
    } else if (a != 5 && a + 1 < n) {
        o->a = o->a + 1;
    } else if (k == 1) {
        o->b = -1;
        o->a = 0;
    }
    return a != o->a || b != o->b;
}




int func_021B6374(Obj *o, int n, int k)
{
    int a, b, v;

    if (n == 0)
        return 0;
    a = o->a;
    b = o->b;
    if (a == 0 && b != -1) {
        o->b = o->b - 1;
    } else if (a != 0) {
        o->a = o->a - 1;
    } else if (k == 1) {
        v = n - 7;
        o->b = v;
        if (v < -1)
            o->b = -1;
        if ((o->a = 5) >= n)
            o->a = n - 1;
    }
    return a != o->a || b != o->b;
}




u32 func_021B63F8(u8 *p)
{
    u32 x, y, old;
    int k;

    k = func_021B61C8(p);
    if (k >= 7 && func_02035CB8(&x, &y) == 1) {
        if (x >= 0x100 || x < 0xE0)
            return 0;
        if (((struct Obj00002 *)p)->f85C == 0) {
            if (func_02035C60() == 1) {
                if (y < 0x10 || y >= 0x98)
                    return 0;
                ((struct Obj00002 *)p)->f85C = 1;
            } else
                return 0;
        }
        func_021B80C4((struct Obj *)p, 0);
        old = *(u32 *)&((struct Obj00002 *)p)->f814;
        *(u32 *)&((struct Obj00002 *)p)->f814 = func_0202EDE4(k - 6, y, 0x1A, 0x8E, 0) - 1;
        func_021BA654((char *)p);
        if (*(u32 *)&((struct Obj00002 *)p)->f814 != old) {
            func_020061E4(0x548);
            return 1;
        }
    }
    return 0;
}




int func_021B64A0(void *o)
{
    int res = 0;
    int a, k;
    u32 cnt;

    a = func_021B61B8(o);
    k = func_021B61C8(o);
    if (func_0203633C() & 0x80) {
        res = func_021B6300((Obj_021B6300 *)o, k, 1);
    } else if (func_0203633C() & 0x40) {
        res = func_021B6374(o, k, 1);
    } else if (func_0203633C() & 0x100) {
        cnt = res;
        do {
            if (func_021B6300((Obj_021B6300 *)o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    } else if (func_0203633C() & 0x200) {
        cnt = res;
        do {
            if (func_021B6374(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    }
    if (res) {
        k = func_021B61B8(o);
        func_020061E4(0x548);
        func_021B624C(o, a, k);
    }
    return res;
}




int func_021B6554(void *o)
{
    int res = 0;
    int k;
    u32 cnt;

    k = func_021B61C8(o);
    if (func_0203633C() & 0x80) {
        res = func_021B6300((Obj_021B6300 *)o, k, 1);
    } else if (func_0203633C() & 0x40) {
        res = func_021B6374(o, k, 1);
    } else if (func_0203633C() & 0x100) {
        cnt = res;
        do {
            if (func_021B6300((Obj_021B6300 *)o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    } else if (func_0203633C() & 0x200) {
        cnt = res;
        do {
            if (func_021B6374(o, k, 0) == 0)
                break;
            cnt++;
        } while (cnt < 6);
        if (cnt != 0)
            res = 1;
    }
    return res;
}




int func_021B65E8(u8 *p)
{
    u32 x, y;
    int k, a;
    u32 target;
    int n;
    u32 i;

    if (func_02035CB8(&x, &y) == 1) {
        if (x < 0x90 || x > 0xE7 || y < 0xC || y > 0x9B)
            return 0;
        target = (y - 0xC) / 0x18;
        if (*(u32 *)&((struct Obj00002 *)p)->f810 == target)
            return 0;
        k = func_021B61C8(p);
        a = func_021B61B8(p);
        n = *(u32 *)&((struct Obj00002 *)p)->f810 - target;
        if (n < 0)
            n = -n;
        if (*(u32 *)&((struct Obj00002 *)p)->f810 < target) {
            for (i = 0; i < n; i++) {
                if (func_021B6300((Obj_021B6300 *)((struct Obj *)p), k, 0) == 0)
                    break;
            }
        } else if (*(u32 *)&((struct Obj00002 *)p)->f810 > target) {
            for (i = 0; i < n; i++) {
                if (func_021B6374((struct Obj *)p, k, 0) == 0)
                    break;
            }
        }
        if (i == 0)
            return 0;
        func_021B624C(p, a, func_021B61B8(p));
        func_021B80C4((struct Obj *)p, 0);
        return 1;
    }
    return 0;
}


int func_021B66B8(void)
{
    unsigned int x;
    unsigned int y;
    if (func_02035D20(&x, &y) == 1 && x >= 0xE0 && x <= 0xF7 && y >= 0xA8 && y <= 0xBF) return 1;
    return 0;
}


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
