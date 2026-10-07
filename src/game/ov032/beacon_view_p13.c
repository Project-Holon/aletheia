/*
 * file:     beacon_view_p13.c
 * unit:     yes
 * function: func_021F1CF0, func_021F1E40, func_021F1EAC, func_021F1F00, func_021F1F34, func_021F1F9C, func_021F201C, func_021F20A8
 * address:  0x021F1CF0
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F0A98 0x021F0A98 thumb ov032
 *   func_021F0B80 0x021F0B80 thumb ov032
 *   func_021F178C 0x021F178C thumb ov032
 *   func_021F0C04 0x021F0C04 thumb ov032
 *   func_021F0B64 0x021F0B64 thumb ov032
 *   func_021F0E04 0x021F0E04 thumb ov032
 *   func_021F0C70 0x021F0C70 thumb ov032
 *   func_021F253C 0x021F253C thumb ov032
 *   func_021F0D9C 0x021F0D9C thumb ov032
 *   func_021F0D5C 0x021F0D5C thumb ov032
 *   func_021F0B10 0x021F0B10 thumb ov032
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   func_02031194 0x02031194 arm
 *   func_021F0FC8 0x021F0FC8 thumb
 *   func_021F0ED0 0x021F0ED0 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02165E24 0x02165E24 thumb ov010
 *   func_02165FC0 0x02165FC0 thumb ov010
 *   func_021F1080 0x021F1080 thumb
 *   func_021659F0 0x021659F0 thumb ov010
 *   func_021F0F44 0x021F0F44 thumb ov032
 *   func_021F0DD8 0x021F0DD8 thumb ov032
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02045770 0x02045770 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F20E4 0x021F20E4 thumb ov032
 */
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj00879.h"
#include "../../matched/include/Obj00225.h"
#include "../../matched/include/Obj05121.h"
#include "../../matched/include/Obj20436.h"
#include "../../matched/include/Obj02113.h"
#include "../../matched/include/Obj20437.h"
#include "../../matched/include/Obj20438.h"
#include "../../matched/include/Obj13066.h"
#include "../../matched/include/Obj04312.h"
#include "../../matched/include/Obj20439.h"
#include "../../matched/include/Obj20441.h"
#include "../../matched/include/Obj02752.h"
#include "../../matched/include/Obj20443.h"
#include "../../matched/include/Obj20444.h"
#include "../../matched/include/Obj06135.h"
#include "../../matched/include/Obj07634.h"
#include "../../matched/include/Obj09799.h"
#include "../../matched/include/Obj20446.h"

struct TcblNode;
struct S02030FB4;
struct Chan02021FD8;
struct Cfg;
struct CharBuf;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_021F0A98(char *p, unsigned a);
extern void func_021F0B80(char *p, void *t, unsigned a);
extern void func_021F178C(char *p, u8 a, int *s);
extern void func_021F0C04(char *p, int flag);
extern void func_021F0B64(char *p);
extern void func_021F0E04(char *p, unsigned a);
extern int func_021F0C70(char *p, int flag);
extern void func_021F253C(char *p, int v);
extern void func_021F0D9C(char *p);
extern int func_021F0D5C(char *p, int i);
extern void func_021F0B10(char *p, int a, int b);
extern void func_021F05E8(u8 *p, int a, u32 b);
extern void func_02031194(struct TcblNode *n);
extern void func_021F0FC8(char *p, u8 *q, int r);
extern void func_021F0ED0(char *q, int a);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
extern int func_02165E24(int a0);
extern u8 func_02165FC0(u32 type);
extern void func_021F1080(char *p, char *q, int r, int t);
extern int func_021659F0(u8 *q, int delta);
extern u8 *func_021F0F44(u8 *p, int a);
extern void func_021F0DD8(unsigned int a);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(u32 bmp, u32 x, u32 y, const void *text, u32 f, u16 color);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_021F20E4(void *task, char *q);
void func_021F1CF0(void *h, u8 *t);
void func_021F1E40(char *p, char *q, void *x, int flag);
void func_021F1EAC(void *task, u8 *s);
void func_021F1F00(char *p, int a);
void func_021F1F34(char *p, u8 *q, int *r);
void func_021F1F9C(void *task, u8 *s);
void func_021F201C(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7);
void func_021F20A8(char *p, char *q, int *r);


void func_021F1CF0(void *h, u8 *t)
{
    char *p;
    int r;

    p = *(char * *)&((struct Obj00879 *)t)->f1C;
    if (((struct Obj00879 *)t)->f8 > 0)
        return;
    switch (t[0]) {
    case 0:
        if (((struct Obj00879 *)t)->f14 != 0)
            func_021F0A98(p, (u8)((((struct Obj00879 *)t)->f16 != 0 ? 1 : 0) + 9));
        else if (((struct Obj00879 *)t)->f10 < ((struct Obj00879 *)t)->f12)
            func_021F0A98(p, (u8)8);
        func_021F0B80(p, (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (unsigned int)((int *)(t + 8)));
        t[0]++;
        break;
    case 1:
        func_021F178C(p, 0, (int *)(t + 8));
        t[0]++;
        break;
    case 2:
        func_021F0E04(p, 0);
        t[0]++;
        break;
    case 3:
        func_021F0C04(p, 1);
        func_021F0B64(p);
        t[0]++;
        break;
    case 4:
        r = func_021F0C70(p, 1);
        if (r < 0)
            break;
        t[5] = r;
        if (t[5] == 0) {
            func_021F253C(p, 7);
            p[0x79] = 1;
            t[0] = 5;
        } else {
            t[0] = 6;
        }
        break;
    case 5:
        if (((struct Obj00007 *)p)->f79 != 0) {
            t[0] = 4;
            break;
        }
        func_021F0D9C(p);
        t[0] = 7;
        break;
    case 6:
        if (func_021F0D5C(p, t[5]) == 0)
            break;
        t[0]++;
        break;
    case 7:
        func_021F0B10(p, 1, (int)((int *)(t + 8)));
        func_021F0E04(p, 1);
        func_021F178C(p, 1, (int *)(t + 8));
        t[0]++;
        break;
    default:
        func_021F05E8((u8 *)p, 4, (int)0);
        (**(int * *)&((struct Obj00879 *)t)->f20)--;
        func_02031194(h);
        break;
    }
}


void func_021F1E40(char *p, char *q, void *x, int flag)
{
    void *t;
    u8 *r;

    t = func_020311B8(((struct Obj20436 *)p)->fA0, (void *)func_021F1EAC, 0x18, 0);
    r = func_02031290(t);
    func_02082BCC(r, 0, 0x18);
    *(char * *)&((struct Obj05121 *)r)->f10 = p;
    *(char * *)&((struct Obj05121 *)r)->f8 = q;
    r[1] = 0x5a;
    ((struct Obj00225 *)q)->f30 = t;
    if (flag)
        ((struct Obj05121 *)r)->fC = 1;
    else
        ((struct Obj05121 *)r)->fC = func_02165E24((int)x);
    func_021F0FC8(p, (u8 *)q, func_02165FC0(((struct Obj05121 *)r)->fC));
    func_021F0ED0(q, flag ? 0 : 1);
}


void func_021F1EAC(void *task, u8 *s)
{
    if (s[0] == 0) {
        u8 c = s[1];
        s[1] = c - 1;
        if (c != 0)
            return;
        if (((struct Obj02113 *)s)->fC == 1 || ((struct Obj02113 *)s)->fC == 0x18 || ((struct Obj02113 *)s)->fC == 0x31) {
            func_021F1080((char *)(((struct Obj02113 *)s)->f10), (char *)(*(u32 *)&((struct Obj02113 *)s)->f8), 1, 0);
            s[0]++;
            return;
        }
    } else {
        if (((struct Obj20437 *)(*(char * *)&((struct Obj02113 *)s)->f8))->f2C != 0)
            return;
    }
    ((struct Obj20438 *)(*(char * *)&((struct Obj02113 *)s)->f8))->f30 = 0;
    func_021F0ED0(*(char * *)&((struct Obj02113 *)s)->f8, 0);
    func_02031194(task);
}

void func_021F1F00(char *p, int a)
{
    u8 *q;
    u8 index;
    index = func_021659F0(*(u8 * *)&((struct Obj13066 *)p)->f3C, a + ((struct Obj13066 *)p)->f7C);
    q = func_021F0F44((u8 *)p, index);
    func_021F1F34(p, q, (int *)(p + 0xa8));
    func_021F0DD8(0x54c);
}


void func_021F1F34(char *p, u8 *q, int *r)
{
    u8 *t;

    t = func_02031290(func_020311B8(((struct Obj20439 *)p)->fA0, (void *)func_021F1F9C, 0x14, 0));
    func_02082BCC(t, 0, 0x14);
    *(char * *)&((struct Obj04312 *)t)->fC = p;
    *(u8 * *)&((struct Obj04312 *)t)->f8 = q;
    t[2] = 2;
    t[3] = (q[0] + 4) << 4;
    func_02021FD8((struct Chan02021FD8 *)(((struct Obj20441 *)(*(char * *)&((struct Obj04312 *)t)->fC))->fAC), 3, t[3], 0x10, 4, 0x7fff);
    if (r != 0) {
        *(int * *)&((struct Obj04312 *)t)->f10 = r;
        (*r)++;
    }
}


void func_021F1F9C(void *task, u8 *s)
{
    u8 c = s[0];

    if (c < 2) {
        if (s[1]++ >= s[2]) {
            func_02021FD8((struct Chan02021FD8 *)(((struct Obj20443 *)(*(char * *)&((struct Obj02752 *)s)->fC))->fAC), 3, s[3], 0x10, (c % 2) << 2, 0x7fff);
            s[0]++;
            s[1] = 0;
        }
    } else {
        int *r;

        func_02021FD8((struct Chan02021FD8 *)(((struct Obj20444 *)(*(char * *)&((struct Obj02752 *)s)->fC))->fAC), 3, s[3], 0x10, 0, 0x7fff);
        r = *(int * *)&((struct Obj02752 *)s)->f10;
        if (r != 0)
            (*r)--;
        func_02031194(task);
    }
}


void func_021F201C(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7)
{
    u32 w;
    u32 v;

    func_02043B5C((struct CharBuf *)(((struct Obj06135 *)q)->f4), a5);
    if (((struct Obj07634 *)p)->f7A != 0) {
        func_0201C7D0(((struct Obj06135 *)q)->f4, x, y, text, ((struct Obj07634 *)p)->fB0, col);
        w = ((struct Obj06135 *)q)->f0;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        return;
    }
    v = ((struct Obj07634 *)p)->fB4;
    func_0201C724((void *)v, (u32)func_02045770((struct Descriptor *)((struct Obj06135 *)q)->f8), x, y, (u32)text,
                  ((struct Obj07634 *)p)->fB0, col);
    ((struct Obj06135 *)q)->fC = 1;
    func_021F20A8(p, q, (int *)a7);
}

void func_021F20A8(char *p, char *q, int *r)
{
    u8 *t;
    t = func_02031290(func_020311B8(((struct Obj20446 *)p)->fA0, (void *)func_021F20E4, 0x10, 0));
    func_02082BCC(t, 0, 0x10);
    *(char * *)&((struct Obj09799 *)t)->f8 = p;
    *(char * *)&((struct Obj09799 *)t)->f4 = q;
    if (r != 0) {
        *(int * *)&((struct Obj09799 *)t)->fC = r;
        (*r)++;
    }
}
