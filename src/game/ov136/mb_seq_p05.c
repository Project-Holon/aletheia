/*
 * file:     mb_seq_p05.c
 * unit:     yes
 * function: func_021C71A8, func_021C71BC, func_021C71D0, func_021C7250, func_021C7298, func_021C730C, func_021C7350, func_021C7360, func_021C73C8, func_021C7420, func_021C7430, func_021C7494
 * address:  0x021C71A8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C5974 0x021C5974 thumb
 *   func_021C670C 0x021C670C thumb ov136
 *   func_0207D63C 0x0207D63C arm
 *   func_021C5D68 0x021C5D68 thumb
 *   func_021C6374 0x021C6374 thumb
 *   func_02008FC8 0x02008FC8 thumb
 *   func_02024450 0x02024450 thumb
 *   func_020414EC 0x020414EC arm
 *   func_02008FA4 0x02008FA4 thumb
 *   func_0200902C 0x0200902C thumb
 *   func_02030734 0x02030734 arm
 *   d_021C7F04 0x021C7F04 data a1
 *   func_02031348  0x02031348  arm
 *   ov091_id 0x0000005B data
 *   d_021BED00 0x021BED00 data ov091 a4
 */
#include "../../matched/include/Obj00127.h"
#include "../../matched/include/Obj23639.h"
#include "../../matched/include/Obj08199.h"
#include "../../matched/include/Obj23640.h"
#include "../../matched/include/Obj00412.h"
#include "../../matched/include/Obj01066.h"
#include "../../matched/include/Obj23643.h"
#include "../../matched/include/Obj23644.h"
#include "../../matched/include/Obj23645.h"
#include "../../matched/include/Obj03837.h"
#include "../../matched/include/Obj06531.h"
#include "../../matched/include/Obj10610.h"
#include "../../matched/include/Obj23650.h"

struct WinMgr;
struct Obj0202DC98;
struct Sub02008F80Entry;
struct Sub02008F80Obj;
struct BigObj;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

struct Control_021C71D0 {
    u8 enabled : 1;
    u8 mode : 7;
    u8 action : 4;
    u8 phase : 4;
    u8 a, b, c, d, e, f;
};

struct Control_021C7250 {
    u8 enabled : 1;
    u8 mode : 7;
    u8 action : 4;
    u8 phase : 4;
    u8 a, b;
};

struct Flags { u8 index : 7; u8 flag : 1; };

struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};

extern void func_021C5974(u8 *);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
extern void func_021C670C(u8 *p, int i, int on);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_021C5D68(u8 *);
extern void func_021C6374(u8 *);
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern int func_02024450(const u16 *p);
extern void func_0202DC9C(struct Obj0202DC98 *o, int i, u32 a1);
extern void func_020414EC(u32);
extern void *func_0201292C(const struct BigObj *p);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u16 func_020213AC(u32);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0200CA1C(void *a);
extern void func_02031348(void *, u32, const void *, void *);
int func_021C71A8(char *p, int v, int w);
int func_021C71BC(u8 *p, int v);
int func_021C71D0(u8 *p, int v, int w);
int func_021C7250(u8 *p, int v, int w);
void func_021C7298(void *p, int v);
void func_021C730C(void *p);
void func_021C7350(u8 *p);
void func_021C7360(u8 *p);
void func_021C73C8(u8 *p);
void func_021C7420(u8 *p);
void func_021C7430(u8 *p, int a, u16 b, u16 c);
int func_021C7494(u8 *p);
extern const char d_021C7F04[];
extern const u8 d_021BED00[];
extern u8 ov091_id[];


int func_021C71A8(char *p, int v, int w)
{
    ((struct Obj23639 *)(*(char * *)&((struct Obj00127 *)p)->f8))->f1DD = v;
    *(int *)&((struct Obj00127 *)p)->f28 = w;
    return 3;
}

int func_021C71BC(u8 *p, int v)
{
    ((struct Obj23640 *)(*(u8 * *)&((struct Obj08199 *)p)->f8))->f1E0 = v;
    func_021C5974(p);
    return 4;
}

int func_021C71D0(u8 *p, int v, int w)
{
    struct Temp { s8 b, a; u16 c, d; } t;
    struct Control_021C71D0 *q;
    func_0202CF98(**(void ** *)&((struct Obj00412 *)p)->f8, v, &t.a, &t.b);
    func_0202CFC0(**(void ** *)&((struct Obj00412 *)p)->f8, v, &t.d, &t.c);
    q = (struct Control_021C71D0 *)(*(u8 * *)&((struct Obj00412 *)p)->f8 + 0x300);
    q->enabled = 1;
    q->mode = 2;
    q->action = 2;
    q->phase = 1;
    q->a = 0;
    q->b = 0;
    q->c = t.a;
    q->d = t.b;
    q->e = t.d;
    q->f = t.c;
    *(int *)&((struct Obj00412 *)p)->f28 = w;
    return 5;
}

/*
 * extent: trailing 021C7296 halfword is zero alignment padding.
 */
int func_021C7250(u8 *p, int v, int w)
{
    struct Control_021C7250 *q = (struct Control_021C7250 *)(*(u8 * *)&((struct Obj00412 *)p)->f8 + 0x300);
    q->enabled = 0;
    q->mode = (u8)v;
    q->action = 1;
    q->phase = 0;
    q->a = 0;
    q->b = 0;
    *(int *)&((struct Obj00412 *)p)->f28 = w;
    return 5;
}

/*
 * volatile: hardware register write at 021C7302 (0x04000050).
 */
void func_021C7298(void *p, int v)
{
    if (v == 1) {
        func_021C670C(p, 0, 1);
        func_021C670C(p, 1, 1);
        func_021C670C(p, 3, 1);
        func_021C670C(p, 7, 1);
        func_0207D63C((void *)0x04000050, 4, 8, 4, 12);
    } else {
        func_021C670C(p, 0, 0);
        func_021C670C(p, 1, 0);
        func_021C670C(p, 3, 0);
        func_021C670C(p, 7, 0);
        *(volatile unsigned short *)0x04000050 = 0;
    }
}

void func_021C730C(void *p)
{
    func_021C670C(p, 0, 1);
    func_021C670C(p, 1, 1);
    func_021C670C(p, 3, 0);
    func_021C670C(p, 7, 0);
    func_0207D63C((void *)0x04000050, 4, 8, 4, 12);
}

void func_021C7350(u8 *p)
{
    func_021C5D68(p);
    func_021C6374(p);
}

/*
 *   2026-10-02: src/matched/arm9/func_02024450.c exists (EXACT) but has no shard yet.
 *   After the integrator runs manifest on it, re-run: expect EXACT.
 *   Verified Thumb C is preserved here; ARM9 filing belongs to Ilias.
 *   typedef unsigned short u16;
 *   int func_02024450(const u16 *p)
 *   {
 *       if (*p != 0xFFFF) return 1;
 *       return 0;
 *   }
 */
void func_021C7360(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (func_02024450((const u16 *)func_02008FC8(*(void **)(*(u8 * *)&((struct Obj01066 *)p)->f8 + p[0x1F]*4 + 0x298), (u8)i)) != 0) {
            func_0202DC9C(((struct Obj23643 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f35C, (u8)i, (int)0);
        }
    }
    if (((struct Obj23644 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f364 != 0) {
        func_0202DC9C(((struct Obj23645 *)(*(u8 * *)&((struct Obj01066 *)p)->f8))->f35C, (u8)i, (int)0);
    }
    func_020414EC(4);
    func_020414EC(5);
}

/*
 * extent: trailing 021C741E halfword is zero alignment padding.
 */
void func_021C73C8(u8 *p)
{
    void *q = func_0201292C(**(void ** *)&((struct Obj00127 *)p)->f4);
    ((struct Obj00127 *)p)->f22 = func_020213AC(func_02008FA4(*(void **)(*(u8 * *)&((struct Obj00127 *)p)->f8 + p[0x1F]*4 + 0x298)));
    if (func_02007E50(q, ((struct Obj00127 *)p)->f22, 1, 0x66) == 1) {
        ((struct Flags *)(p + 0x21))->flag = 0;
        return;
    } else {
        ((struct Flags *)(p + 0x21))->flag = 1;
        return;
    }
}

void func_021C7420(u8 *p)
{
    func_0200902C(((struct Obj00127 *)p)->f0, 0, p[0x1F]);
}

void func_021C7430(u8 *p, int a, u16 b, u16 c)
{
    u8 *q = func_02030734(0x65, 0x98, 1, d_021C7F04, 0x529);
    ((struct Obj03837 *)q)->f0 = func_02012934(**(void ** *)&((struct Obj06531 *)p)->f4);
    ((struct Obj03837 *)q)->f4 = func_0201292C(**(void ** *)&((struct Obj06531 *)p)->f4);
    ((struct Obj03837 *)q)->f8 = ((struct Obj06531 *)p)->f0;
    ((struct Obj03837 *)q)->f38 = 0;
    ((struct Obj03837 *)q)->f34 = a;
    ((struct Obj03837 *)q)->f44 = b;
    ((struct Obj03837 *)q)->f5C = c;
    ((struct Obj03837 *)q)->f18 = (u32)func_0200CA1C(**(void ** *)&((struct Obj06531 *)p)->f4);
    *(u8 * *)&((struct Obj06531 *)p)->f10 = q;
}

int func_021C7494(u8 *p)
{
    u32 v = ((struct Bf7 *)(p + 0x21))->v;
    ((struct Obj23650 *)(*(u8 * *)&((struct Obj10610 *)p)->f10))->f3C = v;
    func_02031348(((struct Obj10610 *)p)->f30, (u32)ov091_id, d_021BED00, ((struct Obj10610 *)p)->f10);
    return 0;
}
