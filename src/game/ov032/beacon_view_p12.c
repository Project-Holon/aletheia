/*
 * file:     beacon_view_p12.c
 * unit:     yes
 * function: func_021F18C4, func_021F18E0, func_021F1930, func_021F199C, func_021F1A08, func_021F1A18, func_021F1A28, func_021F1B94
 * address:  0x021F18C4
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
 *   func_021F05E8 0x021F05E8 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02045838 0x02045838 arm
 *   func_021F0B80 0x021F0B80 thumb
 *   func_021F178C 0x021F178C thumb
 *   func_021F0BA8 0x021F0BA8 thumb
 *   func_02031194 0x02031194 arm
 *   func_02165EBC 0x02165EBC thumb ov010
 *   func_02165D20 0x02165D20 thumb ov010
 *   sub_02010EA0  0x02010EA0 thumb
 *   func_02165FCC 0x02165FCC thumb ov010
 *   func_0201F250 0x0201F250 thumb
 *   func_021F1CF0 0x021F1CF0 thumb ov032
 *   func_02031288 0x02031288 arm
 *   func_0201F184 0x0201F184 thumb
 *   func_02010FA0 0x02010FA0 thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02010EEC 0x02010EEC thumb
 *   d_021F352C 0x021F352C data ov032 a1
 *   func_021F029C 0x021F029C thumb ov032
 *   func_021F0C04 0x021F0C04 thumb ov032
 *   func_021F0B64 0x021F0B64 thumb ov032
 *   func_021F0E04 0x021F0E04 thumb ov032
 *   func_021F0C70 0x021F0C70 thumb ov032
 *   func_021F253C 0x021F253C thumb ov032
 *   func_021F0D38 0x021F0D38 thumb ov032
 *   func_021F0CF8 0x021F0CF8 thumb ov032
 *   func_021F0B10 0x021F0B10 thumb ov032
 */
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj09798.h"
#include "../../matched/include/Obj02751.h"
#include "../../matched/include/Obj20431.h"
#include "../../matched/include/Obj20433.h"
#include "../../matched/include/Obj01037.h"

struct S02030FB4;
struct U16Vec;
struct TcblNode;
struct Rec;
struct WordSet;
struct Rec02010FA0;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

extern void func_021F0A98(char *p, unsigned a);
extern void func_021F05E8(u8 *p, int a, u32 b);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_021F0B80(char *p, void *t, unsigned a);
extern void func_021F178C(char *this, u8 a, int *p);
extern int func_021F0BA8(u8 *s);
extern void func_02031194(struct TcblNode *n);
extern u16 func_02165EBC(struct Rec *r);
extern u8 func_02165D20(struct Rec *r);
extern u8 sub_02010EA0(int slot, u8 *rec);
extern void func_02165FCC(void *r, u32 win, u32 heap);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021F1CF0(void *h, u8 *t);
extern void func_02031288(int *p, int v);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern unsigned int func_02010FA0(struct Rec02010FA0 *p, int idx);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_02010EEC(void);
extern void func_021F029C(char *p, int a);
extern void func_021F0C04(char *p, int flag);
extern void func_021F0B64(char *p);
extern void func_021F0E04(char *p, unsigned a);
extern int func_021F0C70(char *p, int flag);
extern void func_021F253C(char *p, int v);
extern void func_021F0D38(char *p);
extern int func_021F0CF8(char *p, int i);
extern void func_021F0B10(char *p, int a, int b);
void func_021F18C4(char *p, int b);
void func_021F18E0(char *p, u32 a, int *c);
void func_021F1930(void *task, u8 *s);
int func_021F199C(char *p, void *x, int flag);
void func_021F1A08(char *p);
void func_021F1A18(char *p, int b);
void func_021F1A28(char *p, int b, u8 c, int *r);
void func_021F1B94(void *h, u8 *t);
extern u8 d_021F352C[];

void func_021F18C4(char *p, int b)
{
    func_021F0A98(p, b);
    func_021F18E0(p, *(u32 *)&((struct Obj00007 *)p)->f11C, (int *)(p + 0xa8));
}


void func_021F18E0(char *p, u32 a, int *c)
{
    u8 *r;

    r = func_02031290(func_020311B8(*(u32 *)&((struct Obj00007 *)p)->fA0, (void *)func_021F1930, 0x10, 0));
    func_02082BCC(r, 0, 0x10);
    func_02045838((struct U16Vec *)(*(u32 *)&((struct Obj00007 *)p)->f120), (struct U16Vec *)a);
    *(char * *)&((struct Obj09798 *)r)->f8 = p;
    r[1] = 0x5a;
    func_021F05E8((u8 *)p, 4, 2);
    *(int * *)&((struct Obj09798 *)r)->fC = c;
    (*c)++;
}


void func_021F1930(void *task, u8 *s)
{
    if (((struct Obj02751 *)s)->f4 != 0)
        return;
    switch (s[0]) {
    case 0:
        func_021F0B80(*(char * *)&((struct Obj02751 *)s)->f8, (void *)(((struct Obj20431 *)(*(char * *)&((struct Obj02751 *)s)->f8))->f120), (unsigned int)(s + 4));
        s[0]++;
        return;
    case 1:
        func_021F178C(*(char * *)&((struct Obj02751 *)s)->f8, 0, (int *)(s + 4));
        s[0]++;
        return;
    case 2:
        if (func_021F0BA8(s + 1) != 0) {
            func_021F178C(*(char * *)&((struct Obj02751 *)s)->f8, 1, (int *)(s + 4));
            s[0]++;
        }
        return;
    default:
        (**(int * *)&((struct Obj02751 *)s)->fC)--;
        func_02031194(task);
        return;
    }
}


int func_021F199C(char *p, void *x, int flag)
{
    int r;

    if (flag)
        r = func_02165EBC(x);
    else
        r = func_02165D20(x);
    if (r == 0x30 || r > 0x2d)
        return 0;
    if (r == sub_02010EA0(r, *(u8 * *)&((struct Obj00007 *)p)->f24))
        return 0;
    func_02165FCC(x, *(u32 *)&((struct Obj00007 *)p)->f110, ((struct Obj00007 *)p)->f96);
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00007 *)p)->f110), (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (void *)(*(u32 *)&((struct Obj00007 *)p)->f118));
    func_021F1A28(p, r, 1, (int *)(p + 0xa8));
    return 1;
}

void func_021F1A08(char *p)
{
    func_021F1A28(p, ((struct Obj20433 *)p)->f28, 0, (int *)(p + 0xa8));
}

void func_021F1A18(char *p, int b)
{
    func_021F1A28(p, b, 2, (int *)(p + 0xa8));
}


/*
 * Byte-correct; the only wildcard is the bl to func_02010FA0 (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, Ilias's; it sits
 * in the word run after sub_02010EA0/func_02010EEC). Verified leaf C
 * (EXACT, arm9 0x02010FA0, thumb, `one --thumb` with no --region):
 *   typedef unsigned short u16;
 *   u16 func_02010FA0(unsigned char *rec, int slot)
 *   { return *(u16 *)(rec + slot * 0xc + 2); }
 * `u8 c` and `int flag` with `flag = 0` after the p[0x7f] store are what
 * put the flag's zero store after the argument copies.
 */
void func_021F1A28(char *p, int b, u8 c, int *r)
{
    void *h;
    int flag;
    u8 *t;

    h = func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F1B94, 0x24, 0);
    t = func_02031290(h);
    func_02082BCC(t, 0, 0x24);
    p[0x7f] = 0x30;
    flag = 0;
    if (c == 0)
        flag = 1;
    p[0x80] = flag;
    *(char **)(t + 0x1c) = p;
    t[2] = 0x5a;
    *(int *)(t + 0xc) = b;
    t[3] = c;
    func_0201F184((struct WordSet *)(*(u32 *)(p + 0x110)), 1, b);
    if (t[3] == 0) {
        *(u16 *)(t + 0x12) = func_02010FA0((struct Rec02010FA0 *)(*(u32 *)(p + 0x24)), b);
        *(u16 *)(t + 0x10) = func_02007FB8((u8 *)(*(u32 *)(p + 0x18)), 0x23f, *(u16 *)(p + 0x96));
        func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x110)), 2, *(u16 *)(t + 0x12), 3, 0, 1);
        func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x110)), 3, *(u16 *)(t + 0x10), 3, 0, 1);
        if (b == sub_02010EA0(b, (u8 *)(*(u32 *)(p + 0x24)))) {
            *(u16 *)(t + 0x14) = func_02010EEC();
            if (*(u16 *)(t + 0x14) != 0) {
                *(u16 *)(t + 0x16) = *(u16 *)(t + 0x14) / 60;
                *(u16 *)(t + 0x18) = *(u16 *)(t + 0x14) % 60;
                func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x110)), 4, *(u16 *)(t + 0x16), 3, 0, 1);
                func_0201EFA4((struct WordSet *)(*(u32 *)(p + 0x110)), 5, *(u16 *)(t + 0x18), 2, 0, 1);
            }
        }
    }
    if (t[3] != 0)
        func_021F05E8((u8 *)p, 0, 2);
    func_021F05E8((u8 *)p, 1, 2);
    func_021F05E8((u8 *)p, 2, 2);
    func_021F05E8((u8 *)p, 3, 2);
    if (*(u16 *)(t + 0x14) != 0 || *(u16 *)(t + 0x10) < *(u16 *)(t + 0x12))
        func_02031288(h, (int)((void *)func_021F1CF0));
    *(int **)(t + 0x20) = r;
    (*r)++;
}


void func_021F1B94(void *h, u8 *t)
{
    char *p;
    int r;

    p = *(char * *)&((struct Obj01037 *)t)->f1C;
    if (((struct Obj01037 *)t)->f8 > 0)
        return;
    switch (t[0]) {
    case 0:
        func_021F0A98(p, d_021F352C[t[3]]);
        func_021F0B80(p, (void *)(*(u32 *)&((struct Obj00007 *)p)->f11C), (unsigned int)((int *)(t + 8)));
        t[0]++;
        break;
    case 1:
        func_021F178C(p, 0, (int *)(t + 8));
        t[0]++;
        break;
    case 2:
        func_021F029C(p, 1);
        func_021F0C04(p, 0);
        func_021F0B64(p);
        func_021F0E04(p, 0);
        t[0]++;
        break;
    case 3:
        r = func_021F0C70(p, 0);
        if (r < 0)
            break;
        t[5] = r;
        switch (t[5]) {
        case 0:
            func_021F253C(p, 6);
            t[0] = 3;
            break;
        case 1:
            p[0x7f] = ((struct Obj01037 *)t)->fC;
            func_021F253C(p, 5);
            t[0] = 4;
            break;
        case 2:
            t[0] = 5;
            break;
        }
        break;
    case 4:
        if (*(u8 *)&((struct Obj00007 *)p)->f7F != 0x30) {
            p[0x7f] = 0x30;
            t[0] = 3;
            break;
        }
        func_021F0D38(p);
        t[0] = 6;
        break;
    case 5:
        if (func_021F0CF8(p, t[5]) == 0)
            break;
        t[0]++;
        break;
    case 6:
        func_021F0B10(p, 1, (int)((int *)(t + 8)));
        func_021F0E04(p, 1);
        func_021F178C(p, 1, (int *)(t + 8));
        t[0]++;
        break;
    default:
        func_021F05E8((u8 *)p, 4, 0);
        func_021F029C(p, 0);
        (**(int * *)&((struct Obj01037 *)t)->f20)--;
        func_02031194(h);
        break;
    }
}
