/*
 * file:     weather_task_p09.c
 * unit:     yes
 * function: func_021A31D0, func_021A3208, func_021A3220, func_021A322C, func_021A3238, func_021A3244, func_021A3250, func_021A32A8, func_021A330C, func_021A3364
 * address:  0x021A31D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_021D890C  0x021D890C  data  a2
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3938  0x021A3938  thumb  ov021
 *   func_021A394C  0x021A394C  thumb  ov021
 *   func_021A3A20  0x021A3A20  thumb
 *   func_021A3A3C  0x021A3A3C  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_021A3460  0x021A3460  thumb
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_021A3960  0x021A3960  thumb
 *   func_0219E634  0x0219E634  thumb
 *   func_0219E570  0x0219E570  thumb
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02164280  0x02164280  thumb  ov010
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB480  0x021BB480  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 *   func_021B7D38  0x021B7D38  thumb  ov021
 *   func_0219E784  0x0219E784  thumb  ov021
 *   func_021B7C38  0x021B7C38  thumb  ov021
 *   _ll_mul        0x0209C054  arm
 */
#include "../../matched/include/Obj19768.h"
#include "../../matched/include/Obj19769.h"
#include "../../matched/include/Obj18019.h"
#include "../../matched/include/Obj18020.h"

typedef unsigned short u16;

typedef struct {
    u16 id;
    u16 val;
} Ent021A31D0;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed int     s32;

u32 func_021A3098(u8 *p);
extern int func_021A3938(u32 a, u32 b);
extern void func_021A394C(u8 *p);
extern int func_021A3A20(u32 a);
extern int func_021A3A3C(u32 *p);
extern void *func_02188C7C(unsigned char *p);
extern u32 func_02188CFC(u8 *p);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern void *func_021A3960(unsigned char *p);
extern void func_0219E634();
extern u32 func_0219E570(u32 o, u32 k, u32 flag);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D83C(void *p);
extern int func_0216D854(void *p);
extern int func_0216D86C(void *p);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_02164280(int x, int y, int *p);
extern u32 func_02188C5C(u8 *p);
extern void *func_021BB480(void *p);
extern void func_0219E2F4(void *o, void *out);
extern void func_021B7D38(u32, s16 *, int *);
extern void func_0219E784(u32 o, u32 idx, s16 *v);
extern int func_021B7C38(u8 *o);
int func_021A31D0(u16 id);
int func_021A3208(u8 *a);
void func_021A3220(u8 *p, u32 res);
void func_021A322C(u8 *p);
int func_021A3238(u8 *p);
int func_021A3244(void *p);
void func_021A3250(u32 *a);
void func_021A32A8(unsigned char **a, u32 b);
void func_021A330C(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e);
void func_021A3364(u32 *a, int b, int *out);
extern const Ent021A31D0 data_021D890C[2][10];



int func_021A31D0(u16 id)
{
    int j;
    int i;
    const Ent021A31D0 *e;

    for (j = 0; j < 2; j++) {
        e = data_021D890C[j];
        for (i = 0; i < 10; i++) {
            if (e->id == id)
                return i;
            e++;
        }
    }
    return 10;
}



int func_021A3208(u8 *a)
{
    switch (func_021A3098(a)) {
    case 2:
    case 3:
        return 0;
    }
    return 1;
}



/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: tail call on the object's
 * word at +0x4, the second argument passing through in r1.
 */
void func_021A3220(u8 *p, u32 res)
{
    func_021A3938(((struct Obj19768 *)p)->f4, res);
}



/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: tail call on the object's
 * word at +0x4, the same shape as func_021A3038.
 */
void func_021A322C(u8 *p)
{
    func_021A394C((u8 *)(((struct Obj19769 *)p)->f4));
}



/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3238(u8 *p)
{
    return func_021A3A20(((struct Obj18019 *)p)->f4);
}



/*
 * Tail-call thunk: ldr r0,[r0,#4]; ldr r3,[pc]; bx r3; .word func_021A3A3C.
 * Unlabelled in the ARM9 listings (the .word run at 0x021A3244 in ov021);
 * blocker target of ov010's func_0216A244 (pkt_0216A244).
 */
int func_021A3244(void *p)
{
    return func_021A3A3C(((struct Obj18020 *)p)->f4);
}



/*
 * Addresses are Black-image addresses.
 * func_0216DDC0 forwards r0-r3 to func_0216DD60, so it takes four
 * arguments; the fourth is the literal 0 whose register the compiler also
 * uses as the v[0] index.
 */
void func_021A3250(u32 *a)
{
    s16 v[8];
    void *h = func_02188C7C((u8 *)a[0]);

    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_021A3460((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
        func_0216DDC0((u32)h, v[2], v[0], 0);
        return;
    }
    func_0219E634(func_021A3960((u8 *)a[1]), &v[3]);
    func_0219E570((u32)h, (u32)(&v[3]), 0);
}



/*
 * Addresses are Black-image addresses.
 */
void func_021A32A8(unsigned char **a, u32 b)
{
    s16 v[8];
    void *h = func_02188C7C(a[0]);

    if (func_02188CFC(a[0]) == 0) {
        func_021A3460((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
        func_0216DDDC((u32)h, v[2], v[0], v[1] << 16, b, 0);
        return;
    }
    func_0219E634(func_021A3960(a[1]), &v[3]);
    func_0219E570((u32)h, (u32)(&v[3]), 0);
}



void func_021A330C(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e)
{
    void *t = func_021A3074((unsigned char *)a);

    if (func_02188CFC(a[0]) == 0) {
        *c = func_0216D83C(t);
        *d = func_0216D854(t);
        *e = func_0216D86C(t);
        *c = *c + func_021641E8(b);
        *e = *e + func_021641F8(b);
    }
}



void func_021A3364(u32 *a, int b, int *out)
{
    int v[3];
    s16 d[3];
    s16 r[4];
    s16 z;
    s16 y;
    s16 x;
    void *e;
    u32 h;
    int m;

    e = func_021A3960((void *)a[1]);
    if (func_02188CFC((u8 *)a[0]) == 0) {
        func_021A330C((unsigned char **)a, b, &z, &y, &x);
        func_02164280(z, x, out);
        out[1] = y << 16;
        return;
    }
    h = (u32)func_021BB480((void *)func_02188C5C((u8 *)a[0]));
    func_0219E2F4(e, r);
    func_021B7D38(h, r, v);
    func_0219E784((u32)e, b, d);
    m = func_021B7C38((u8 *)h);
    out[0] = v[0] + (int)(((long long)d[0] * m + 0x800) >> 12);
    out[1] = v[1] + (int)(((long long)d[1] * m + 0x800) >> 12);
    out[2] = v[2] + (int)(((long long)d[2] * m + 0x800) >> 12);
}
