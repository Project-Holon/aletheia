/*
 * file:     itemmenu_p09.c
 * unit:     yes
 * function: func_021B8280, func_021B832C, func_021B83A0, func_021B83B8, func_021B8600, func_021B8640, func_021B8688
 * address:  0x021B8280
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
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_02020F34  0x02020F34  thumb
 *   func_021B822C  0x021B822C  thumb  ov070
 *   func_021B8F68  0x021B8F68  thumb  ov070
 *   func_02021014  0x02021014  thumb
 *   func_020213E0  0x020213E0  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021BB998 0x021BB998 data ov070 a4
 *   d_021BB95C 0x021BB95C data a1
 *   func_021BA9C0 0x021BA9C0 thumb ov070
 *   func_0202E448 0x0202E448 thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_021B8CE4  0x021B8CE4  thumb  ov070
 *   func_021B8F90  0x021B8F90  thumb  ov070
 *   func_021B8080  0x021B8080  thumb  ov070
 *   func_021B6138  0x021B6138  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8EA8  0x021B8EA8  thumb  ov070
 *   func_021B811C  0x021B811C  thumb  ov070
 *   func_021B81B8  0x021B81B8  thumb  ov070
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_020355D8  0x020355D8  arm
 *   func_021B7250  0x021B7250  thumb  ov070
 *   func_021B624C  0x021B624C  thumb  ov070
 *   func_021B9850  0x021B9850  thumb  ov070
 *   func_021B8B7C  0x021B8B7C  thumb  ov070
 *   func_021B8134  0x021B8134  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_021B6288  0x021B6288  thumb  ov070
 *   func_021B80BC  0x021B80BC  thumb  ov070
 *   d_021BB984     0x021BB984  data  a4
 *   func_021B97CC  0x021B97CC  thumb  ov070
 *   func_02021D50  0x02021D50  thumb
 *   func_0204A648  0x0204A648  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_021BB690  0x021BB690  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 */
#include "../../matched/include/Obj00002.h"
#include "../../matched/include/Obj20669.h"
#include "../../matched/include/Obj07689.h"
#include "../../matched/include/Obj20670.h"

struct Obj;
struct Rec;
struct S02021D50;
struct PrintSys;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int v[11]; } T44;

typedef struct { unsigned char v[4]; } T4;

typedef struct Obj Obj;

struct Obj {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x4F8 - 0x14];
    void (*f4F8)(Obj *o);
    unsigned char pad4FC[0x80C - 0x4FC];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    unsigned char pad81C[0x844 - 0x81C];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
};

typedef struct TabTbl {
    int v[5];
} TabTbl;

extern int func_021B61B8(u8 *p);
extern void *func_021B616C(u8 *p, int i);
extern void *func_02020F34(unsigned int item, unsigned int which, unsigned int heap);
extern void func_021B822C(struct Obj *o, void *rec, unsigned short *p, u8 *out);
extern int func_021B8F68(char *p, int value);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020213E0(u16 v);
extern u32 func_020307B0(void *p);
extern void func_021BA9C0(unsigned char *p, int *tbl, int n);
extern u32 func_0202E448(u32 id);
extern int func_02012BF8(int p, int value);
extern int func_021B61C8(unsigned char *p);
extern void func_021B80C4(struct Obj *o, int flag);
extern void func_021B8CE4(int p, int u, int a, int b);
extern void func_021B8F90(void *o);
extern void func_021B8080(u8 *p);
extern void func_021B6138(char *p);
extern void func_021B6100(char *p, int k);
extern void func_021B8EA8(int p);
extern int func_021B811C(u8 *p);
extern void func_021B81B8(u8 *p);
extern void func_021B8C1C(int p, int a, int b);
extern void func_020355D8(u8 v);
extern void func_021B7250(Obj *o);
extern void func_021B624C(void *o, int a, int b);
extern void func_021B9850(char *p);
extern void func_021B8B7C(int p);
extern int func_021B8134(struct Obj *o, int k);
extern void func_020061E4(unsigned int se);
extern void func_021B6288(struct Obj *o, int a, int b);
extern void func_021B80BC(void *p);
extern void func_021B97CC(void *p, int v);
extern void func_02021D50(struct S02021D50 *p);
extern void func_0204A648();
extern unsigned int func_0201C6B4(const struct PrintSys *p);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern int func_021BB690(const char *p);
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_021B8AF4(void *p);
void func_021B8280(struct Obj *p, unsigned char *q);
void func_021B832C(struct Obj *p);
int func_021B83A0(char *p, int value);
void func_021B83B8(u32 idx, int flag, Obj *o);
void func_021B8600(int u, int p);
void func_021B8640(int p);
void func_021B8688(int p);
extern T44 d_021BB998;
extern T4 d_021BB95C;
extern const TabTbl d_021BB984;


void func_021B8280(struct Obj *p, unsigned char *q)
{
    unsigned short *e = func_021B616C((u8 *)p, func_021B61B8((u8 *)p));
    if (e != 0 && *e != 0) {
        void *h = func_02020F34(*e, 0, ((struct Obj00002 *)p)->f544);
        unsigned char v = ((struct Obj00002 *)p)->f80C;
        func_021B822C(p, h, e, q);
        if (func_021B8F68((char *)p, v) == 0 && q[0] != 2) {
            q[0] = 0xFF;
        }
        if (func_02021014(h, 3) == 0) {
            if (func_020213E0(*e) == 1) {
                q[1] = 6;
            }
            if (v != 2) {
                q[2] = 3;
            }
        }
        if (func_02021014(h, 4) != 0) {
            if (func_021B83A0((char *)p, *e) == 1) {
                q[2] = 5;
            } else {
                q[2] = 4;
            }
        }
        q[3] = 8;
        func_020307B0(h);
    }
}

/*
 * lever: func_021BA9C0 reads the count in r2; passing j keeps it in r2.
 */
void func_021B832C(struct Obj *p)
{
    T44 t = d_021BB998;
    T4 a = d_021BB95C;
    int tmp[4];
    int j;
    int i;
    func_021B8280(p, (unsigned char *)(&a));
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        int c = a.v[i];
        if (c != 0xFF) {
            *(int *)((char *)p + j * 4 + 0x828) = c;
            tmp[j] = t.v[a.v[i]];
            j++;
        }
    }
    func_021BA9C0((unsigned char *)p, tmp, j);
}

int func_021B83A0(char *p, int value)
{
    return func_02012BF8(((struct Obj20669 *)p)->f0, (int)func_0202E448((u16)value));
}


/*
 * Touch-button dispatch of the list screen: buttons 0-4 pick a pocket tab
 * through the table d_021BB984, 5/6 step the tab, 7-10 are the sort,
 * select, exit and back buttons, 11-16 pick a list row, 17+ pick a slot.
 * Touch twin of func_021B7250's key handling.
 */
void func_021B83B8(u32 idx, int flag, Obj *o)
{
    int tab;
    int count;
    int v;
    int saved;
    int cur;
    TabTbl t;

    tab = -1;
    count = func_021B61C8((unsigned char *)o);
    if (flag != 0)
        return;
    if (idx < 5) {
        t = d_021BB984;
        if (o->f80C != t.v[idx]) {
            tab = t.v[idx];
            func_021B80C4(o, 0);
        }
    } else if (idx == 5) {
        func_021B80C4(o, 0);
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        func_021B8CE4((int)o, v, 0, (int)((void *)func_021B8F90));
        return;
    } else if (idx == 6) {
        func_021B80C4(o, 0);
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        func_021B8CE4((int)o, v, 1, (int)((void *)func_021B8F90));
        return;
    } else if (idx == 7) {
        if (o->f80C != 2 && o->f80C != 3 && func_021B61C8((unsigned char *)o) > 1) {
            func_021B8080((u8 *)o);
            func_021B80C4(o, 0);
            o->f818 = 0xFFFF;
            func_021B6138((char *)o);
            func_021B6100((char *)o, (int)((void *)func_021B8EA8));
        }
    } else if (idx == 8) {
        if (func_021B811C((u8 *)o) == 1) {
            func_021B81B8((u8 *)o);
            func_021B80C4(o, 0);
            o->f818 = 0xFFFF;
            func_021B6138((char *)o);
        }
    } else if (idx == 9) {
        if (o->f010 != 2) {
            o->f844 = 0;
            o->f84C = 0;
            func_021B8C1C((int)o, 3, 0);
            func_020355D8(1);
        }
    } else if (idx == 10) {
        o->f844 = 1;
        o->f84C = 0;
        func_021B8C1C((int)o, 4, 0);
        func_020355D8(1);
    } else if (idx >= 11 && idx < 17) {
        if (o->f4F8 != func_021B7250)
            return;
        saved = o->f810;
        cur = func_021B61B8((u8 *)o);
        if (func_021B61C8((unsigned char *)o) == 0)
            return;
        if (o->f810 != idx - 11) {
            o->f810 = idx - 11;
            if (count <= func_021B61B8((u8 *)o)) {
                o->f810 = saved;
                return;
            }
        }
        func_021B624C(o, cur, func_021B61B8((u8 *)o));
        func_021B80C4(o, 0);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
        func_021B9850((char *)o);
        func_021B6100((char *)o, (int)((void *)func_021B8B7C));
        return;
    } else if (idx >= 17) {
        if (func_021B811C((u8 *)o) == 1 && func_021B8134(o, idx - 17) == 1) {
            func_021B80C4(o, 0);
            func_021B6138((char *)o);
        }
    }
    if (tab != -1) {
        v = o->f80C;
        o->f80C = tab;
        func_020061E4(0x7D9);
        func_021B6288(o, v, o->f80C);
        func_021B80BC(o);
        func_021B80C4(o, 0);
        o->f818 = 0xFFFF;
        func_021B6138((char *)o);
    }
}


void func_021B8600(int u, int p)
{
    int s = ((struct Obj07689 *)p)->f840;
    if (s == 1) {
        func_021B97CC((void *)p, 1);
        ((struct Obj07689 *)p)->f840 = 0;
    } else if (s == 2) {
        func_021B97CC((void *)p, 0);
        ((struct Obj07689 *)p)->f840 = 0;
    }
    func_02021D50((struct S02021D50 *)(((struct Obj07689 *)p)->f854));
    func_0204A648();
}


void func_021B8640(int p)
{
    if (func_0201C6B4((const struct PrintSys *)(*(int *)&((struct Obj00002 *)p)->f50C))) {
        func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj00002 *)p)->f544);
        func_020061E4(0x79F);
        func_021B6100((char *)p, (int)func_021B8688);
    }
}


/*
 * blocked:
 */
void func_021B8688(int p)
{
    int a = func_020221A4();
    int b = func_021BB690((const char *)p);
    if (a == 1 && b == 0) {
        func_0204B92C((struct Obj *)((struct Obj20670 *)p)->f6A8, 1);
        func_021B8AF4((void *)p);
    }
}
