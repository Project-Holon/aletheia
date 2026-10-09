/*
 * file:     weather_task_p08.c
 * unit:     yes
 * function: func_021A3460, func_021A3484, func_021A34EC, func_021A34F8, func_021A3504, func_021A3524, func_021A3550, func_021A356C, func_021A3584, func_021A35A0, func_021A35BC, func_021A35E0, func_021A35F0, func_021A35FC, func_021A3624, func_021A3644, func_021A3664, func_021A3674, func_021A3680, func_021A368C, func_021A3698, func_021A36A4, func_021A36B0, func_021A36BC, func_021A36C8, func_021A36D4, func_021A36E0, func_021A36E4
 * address:  0x021A3460
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
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A330C  0x021A330C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0219E784  0x0219E784  thumb
 *   func_021A3A10  0x021A3A10  thumb
 *   func_021A39E4  0x021A39E4  thumb
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021AB5AC  0x021AB5AC  thumb  ov021
 *   func_021AB11C  0x021AB11C  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB310  0x021AB310  thumb  ov021
 *   func_021A5738  0x021A5738  thumb  ov021
 *   func_021A575C  0x021A575C  thumb  ov021
 *   func_021A5764  0x021A5764  thumb  ov021
 *   func_021A5768  0x021A5768  thumb  ov021
 *   func_021A30BC  0x021A30BC  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021A4140  0x021A4140  thumb  ov021
 *   func_021A41B0  0x021A41B0  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021A54A0  0x021A54A0  thumb  ov021
 *   func_021A54B4  0x021A54B4  thumb
 *   func_021A5880  0x021A5880  thumb  ov021
 *   func_021A596C  0x021A596C  thumb
 *   func_021A5928  0x021A5928  thumb
 *   func_021A5964  0x021A5964  thumb  ov021
 *   func_021A59EC  0x021A59EC  thumb
 *   func_021A5A30  0x021A5A30  thumb  ov021
 *   func_021A5A00  0x021A5A00  thumb  ov021
 *   func_021A5A0C  0x021A5A0C  thumb  ov021
 *   func_021A5A18  0x021A5A18  thumb  ov021
 *   func_021A5A24  0x021A5A24  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_02012B34  0x02012B34  thumb
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_021A3998  0x021A3998  thumb  ov021
 *   func_0216DB80  0x0216DB80  thumb  ov010
 *   d_021DDEB8     0x021DDEB8  data  a1
 *   d_021D89A0     0x021D89A0  data  a4
 */
#include "../../matched/include/Obj18021.h"
#include "../../matched/include/Obj19771.h"
#include "../../matched/include/Obj12087.h"
#include "../../matched/include/Obj18022.h"
#include "../../matched/include/Obj06010.h"
#include "../../matched/include/Obj18023.h"
#include "../../matched/include/Obj18024.h"
#include "../../matched/include/Obj18025.h"
#include "../../matched/include/Obj18026.h"
#include "../../matched/include/Obj18027.h"
#include "../../matched/include/Obj00614.h"
#include "../../matched/include/Obj18028.h"
#include "../../matched/include/Obj18029.h"
#include "../../matched/include/Obj18030.h"
#include "../../matched/include/Obj18031.h"

struct BigObj;
struct Ctx;
struct Rec44;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed char s8;

typedef signed int s32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A36E4;

typedef struct {
    s16 x;
    s16 z;
    int y;
} Pos021A36E4;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad4[0x18];
    Pos021A36E4 pos;
} Tmpl021A36E4;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u8 pad10[8];
    u32 f18;
    void *f1c;
    u16 f20;
    u16 f22;
} Obj021A36E4;

extern u16 func_0216D5F8(void *p);
extern void *func_021A3074(u8 *p);
extern u32 func_021A330C(u32, u32, u32, u32, u32);
extern void *func_021A3960(unsigned char *p);
extern u32 func_02188CFC(u8 *p);
extern int func_021641E8(int a);
extern int func_021641F8(int a);
extern void func_0207CCA4();
extern void func_0219E784(u32 o, u32 idx, s16 *v);
extern int func_021A3A10(u32 a);
extern int func_021A39E4(u8 *p);
u32 func_021A3098(u8 *p);
int func_021AB5AC(unsigned long a, unsigned long b);
int func_021AB11C(u32 attr);
u16 func_021AB0F0(u32 attr);
int func_021AB310(u16 id);
void func_021A5738(u32 x, int a);
void func_021A575C(u32 *x);
extern u32 func_021A5764(u8 *p);
int func_021A5768(u32 a, u32 b);
int func_021A30BC(u8 *p);
void *func_020120F4(const struct Ctx *p);
u32 func_0201296C(const struct BigObj *p);
u32 func_020142E8(void *bitmap, s32 id);
u32 *func_021A4140(u32 a, u32 b);
extern u32 func_021A41B0(u32, u32, u32, u32);
int func_0216D83C(void *p);
int func_0216D854(void *p);
int func_0216D86C(void *p);
extern int func_021A54A0(u32 a);
extern void func_021A54B4(u8 *p);
u8 *func_021A5880(u8 *obj, int heap);
extern void func_021A596C(u8 *p, u32 b, u32 c);
extern void func_021A5928(u8 *p, int v);
extern void func_021A5964(u32 *p);
extern u32 func_021A59EC(u32 p);
extern u32 func_021A5A30(u32 *p);
extern void func_021A5A00(u8 *p, void *r);
extern void func_021A5A0C(u8 *p, void *a1);
extern int func_021A5A18(u8 *p, u32 k, void *buf);
extern void func_021A5A24(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02188C80(void *p);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DE94(void *a, u32 b);
extern u16 func_02012B34(const struct Rec44 *p);
extern u32 func_021A3974(u8 *p);
extern int func_021A31A4(int i, int v);
extern void *func_0216CE60(void *a, Tmpl021A36E4 *b, int c);
extern void func_0216D844(void *h, s16 v);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);
extern void func_0216D89C(void *h, const Vec021A36E4 *v);
extern int func_021A3998(u8 *a);
extern void func_0216DB80(unsigned int *p, unsigned int v);
int func_021A3460(u32 a, u32 b, u32 c, u32 d);
void func_021A3484(unsigned char **a, int b, s32 *c);
int func_021A34EC(u8 *p);
int func_021A34F8(u8 *p);
int func_021A3504(u8 *a, int b, int c);
int func_021A3524(u8 *a, int b, int c);
void func_021A3550(u32 *p, int a);
void func_021A356C(void **p);
int func_021A3584(void *a);
void func_021A35A0(u32 *p, int a);
int func_021A35BC(int a);
void func_021A35E0(u32 *p, u32 heap);
int func_021A35F0(u32 a, u32 b, u32 c, u32 d);
void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c);
int func_021A3624(void *a);
void func_021A3644(void **p);
void func_021A3664(u32 *p, u32 heap);
void func_021A3674(u8 *p, u32 b, u32 c);
void func_021A3680(u8 *p, int a1);
void func_021A368C(u8 *p);
u32 func_021A3698(u8 *p);
u32 func_021A36A4(u8 *p);
void func_021A36B0(u8 *p, void *r);
void func_021A36BC(struct Obj18028 *p, void *a1);
int func_021A36C8(u8 *p, u32 k, void *buf);
void func_021A36D4(u8 *p, u32 v);
u32 func_021A36E0(u8 *p);
Obj021A36E4 *func_021A36E4(u32 a, u32 b, const Vec021A36E4 *pos, u32 d, u16 heap);
extern const char d_021DDEB8[];
extern Tmpl021A36E4 d_021D89A0;





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3460(u32 a, u32 b, u32 c, u32 d)
{
return func_021A330C(a, func_0216D5F8(func_021A3074((u8 *)a)), b, c, d);
}





/*
 * Addresses are Black-image addresses.
 */
void func_021A3484(unsigned char **a, int b, s32 *c)
{
    s16 v[4];
    s32 t1;
    s32 t2;
    s32 t3;
    void *h = func_021A3960(a[1]);

    if (func_02188CFC(a[0]) == 0) {
        s32 t;

        c[1] = 0;
        c[0] = func_021641E8(b);
        t = func_021641F8(b);
        c[0] = c[0] << 16;
        c[2] = t << 16;
        func_0207CCA4(c, c);
        return;
    }
    func_0219E784((u32)h, b, v);
    t3 = v[2];
    t2 = v[1];
    t1 = v[0];
    c[0] = t1;
    c[1] = t2;
    c[2] = t3;
}





/*
 * Tail-call thunk: the object's word at +0x4.
 *
 * Addresses are Black-image addresses.
 */
int func_021A34EC(u8 *p)
{
    return func_021A3A10(((struct Obj18021 *)p)->f4);
}





/*
 * Unlabelled leaf, tail-call thunk: the object's word at +0x4.
 * Sole blocker of the func_021645E0 MATCH (ov010).
 *
 * Addresses are Black-image addresses.
 */
int func_021A34F8(u8 *p)
{
    return func_021A39E4(*(u8 * *)&((struct Obj19771 *)p)->f4);
}





int func_021A3504(u8 *a, int b, int c)
{
    int r = func_021A3098(a);

    if (r == 2 || r == 3)
        return 0;
    return func_021AB5AC(b, c);
}





int func_021A3524(u8 *a, int b, int c)
{
    int r = func_021A3098(a);

    if (func_021AB11C(b) != 0 || r != 2)
        return 0;
    return func_021AB310(func_021AB0F0(c));
}





void func_021A3550(u32 *p, int a)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A5738(p[2], a);
}





void func_021A356C(void **p)
{
    if (func_02188CFC(p[0]) == 0)
        func_021A575C(p[2]);
}





int func_021A3584(void *a)
{
if (func_02188CFC((u8 *)(((struct Obj12087 *)((u8 *)(a)))->f0)) == 0) {
    return func_021A5764((u8 *)(((struct Obj12087 *)((u8 *)(a)))->f8));
}
return 0;
}





void func_021A35A0(u32 *p, int a)
{
    if (func_02188CFC((u8 *)p[0]) == 0)
        func_021A5768(p[2], a);
}





int func_021A35BC(int a)
{
    if (func_020142E8((void *)func_0201296C(func_020120F4((const struct Ctx *)func_021A30BC((u8 *)a))), 0x963) != 0)
        return 1;
    return 0;
}





void func_021A35E0(u32 *p, u32 heap)
{
    p[2] = (u32)func_021A4140(p[1], heap);
}





int func_021A35F0(u32 a, u32 b, u32 c, u32 d)
{
return func_021A41B0(((struct Obj18022 *)((u8 *)(a)))->f8, b, c, d);
}





void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c)
{
    void *h = func_021A3960(p[1]);

    *a = func_0216D83C(h);
    *b = func_0216D854(h);
    *c = func_0216D86C(h);
}





int func_021A3624(void *a)
{
if (func_02188CFC((u8 *)(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f0)) == 0) {
    if (func_021A54A0(*(u32 *)&((struct Obj06010 *)((u8 *)(a)))->f8) == 1) {
        return 1;
    }
}
return 0;
}





void func_021A3644(void **p)
{
    if (func_02188CFC(p[0]) == 0 && func_021A54A0((u32)p[2]) == 1)
        func_021A54B4(p[2]);
}





void func_021A3664(u32 *p, u32 heap)
{
    p[3] = (u32)func_021A5880((u8 *)p[1], heap);
}





/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3674(u8 *p, u32 b, u32 c)
{
    func_021A596C((u8 *)(((struct Obj18023 *)p)->fC), b, c);
}




void func_021A3680(u8 *p, int a1)
{
    func_021A5928((u8 *)(((struct Obj18024 *)p)->fC), a1);
}




void func_021A368C(u8 *p)
{
    func_021A5964((u32 *)(((struct Obj18025 *)p)->fC));
}




u32 func_021A3698(u8 *p)
{
    return func_021A59EC(((struct Obj18026 *)p)->fC);
}




u32 func_021A36A4(u8 *p)
{
    return func_021A5A30((u32 *)(((struct Obj18027 *)p)->fC));
}




/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A00.
 *
 * Addresses are Black-image addresses.
 */
void func_021A36B0(u8 *p, void *r)
{
    func_021A5A00(*(u8 * *)&((struct Obj00614 *)p)->fC, r);
}




/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A0C.
 *
 * Addresses are Black-image addresses.
 */
void func_021A36BC(struct Obj18028 *p, void *a1)
{
    func_021A5A0C((u8 *)(p->fC), a1);
}




/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A18.
 *
 * Addresses are Black-image addresses.
 */
int func_021A36C8(u8 *p, u32 k, void *buf)
{
    return func_021A5A18(*(u8 * *)&((struct Obj18029 *)p)->fC, k, buf);
}



/*
 * Tail-call thunk: forwards the field at +0xc of the object to func_021A5A24.
 *
 * Addresses are Black-image addresses.
 */
void func_021A36D4(u8 *p, u32 v)
{
    func_021A5A24((u8 *)(((struct Obj18030 *)p)->fC));
}



/*
 * Loads the 32-bit word at byte +0x8 of the object.
 */
u32 func_021A36E0(u8 *p)
{
    return ((struct Obj18031 *)p)->f8;
}



Obj021A36E4 *func_021A36E4(u32 a, u32 b, const Vec021A36E4 *pos, u32 d, u16 heap)
{
    Obj021A36E4 *o;
    void *m;
    int k;
    void *h;

    o = func_02030734(heap, 0x34, 1, d_021DDEB8, 0x97);
    o->fc = a;
    o->f8 = b;
    o->f4 = (u32)func_02188C80((void *)b);
    o->f20 = 9;
    o->f22 = 9;
    m = func_02188C7C((void *)b);
    o->f1c = func_0216DE94(m, 0xff);
    o->f18 = d;
    k = func_02012B34((const struct Rec44 *)o->fc);
    h = o->f1c;
    if (h == 0) {
        Tmpl021A36E4 t = d_021D89A0;
        Pos021A36E4 *ps = &t.pos;
        ps->x = (pos->x >> 4) / 4096;
        ps->z = (pos->z >> 4) / 4096;
        ps->y = pos->y;
        if (k == 0xFFFF)
            t.f2 = func_021A31A4(d, func_021A3974((u8 *)o));
        else
            t.f2 = k;
        o->f1c = func_0216CE60(m, &t, 0);
    } else {
        int y;
        int z;
        y = (pos->y >> 4) / 4096;
        z = (pos->z >> 4) / 4096;
        func_0216D844(h, (pos->x >> 4) / 4096);
        func_0216D85C(h, (s16)y);
        func_0216D874((int)h, (s16)z);
        func_0216D89C(h, pos);
        if (k == 0xFFFF)
            func_021A3998((u8 *)o);
    }
    func_0216DB80(o->f1c, 1);
    return o;
}
