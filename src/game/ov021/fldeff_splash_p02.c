/*
 * file:     fldeff_splash_p02.c
 * unit:     yes
 * function: func_021C49C0, func_021C4A00, func_021C4A10, func_021C4A3C, func_021C4AE8, func_021C4B04, func_021C4B24, func_021C4B28, func_021C4B50, func_021C4B64, func_021C4BC4, func_021C4BE0, func_021C4C0C, func_021C4C50
 * address:  0x021C49C0
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
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAA2C     0x021DAA2C  data  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021DE478     0x021DE478  data  a4
 *   d_021DE47C     0x021DE47C  data  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   d_021DAA18     0x021DAA18  data  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 */
#include "../../matched/include/Obj07561.h"

struct BbActRec;
struct BbActSys;
struct X;
struct Actor;
struct VecFx32;
struct BbActDesc;
struct P_021C4B28;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct S_021C49C0 { u32 w0; u8 b4, b5, b6, b7; u32 w8; } S_021C49C0;

typedef struct P_021C49C0 { u32 f0; u32 f4; u16 f8; } P_021C49C0;

typedef struct {
    u32 f0;
    u32 obj;
    u16 id;
} S_021C4A00;

typedef struct {
    u32 a;
    u32 b;
} P2;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Pair { u32 f0; u32 f4; } Pair;

typedef struct Res { Pair p; u16 h8; } Res;

typedef struct Head { u8 pad[4]; u32 f4; u16 h8; } Head;

typedef struct {
    u32 *p;
    u32 f4;
    u16 id;
} S;

typedef struct {
    void *owner;
    u32 f4;
} R;

typedef signed int     s32;

typedef struct P_021C4B28 { u32 f0; u16 h4; u16 h6; } P_021C4B28;

typedef struct {
    u32 owner;
    u16 h4;
    u16 h6;
} S_021C4BC4;

typedef struct { int a; int b; } S_021C4C0C;

extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *fn, u32 c, u32 d, P2 *e, u32 f);
extern int func_021AC1AC(u32 a);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE18(unsigned char *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *a, u32 b);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u16 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);
extern void func_021C6628(u32 o, u16 v);
extern void func_021C6580(u8 *p, int i);
extern int func_0216E1A4(int a0, int a1);
extern void func_021AC1CC(int a, int *v);
void func_021C49C0(P_021C49C0 *p);
void func_021C4A00(S_021C4A00 *s);
void func_021C4A10(void *a, u32 b);
void func_021C4A3C(u32 a, Res *r);
void func_021C4AE8(void *a, S *s);
void func_021C4B04(void *a, S *s);
void func_021C4B24(void);
R *func_021C4B28(void *owner, u32 heap);
void func_021C4B50(u32 a, u8 *p);
void func_021C4B64(P_021C4B28 *p);
void func_021C4BC4(S_021C4BC4 *s);
void func_021C4BE0(void *a, u32 b);
void func_021C4C0C(int a, int *b);
void func_021C4C50(void);
extern char d_021DAA2C[];
extern u8 d_021DE478[];
extern char d_021DE47C[];
extern char d_021DAA18[];








void func_021C49C0(P_021C49C0 *p)
{
    S_021C49C0 s;
    u32 x = func_021ABE24((u8 *)p->f0);

    s.b4 = 2;
    s.b5 = 0x13;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.w8 = 1;
    s.w0 = (u32)func_02046E24(x, 0x2d);
    func_021AC1F0((struct X *)p->f0, (void *)s.w0);
    p->f8 = func_020500F0((struct BbActSys *)p->f4, (const struct BbActRec *)(&s), 1);
}








void func_021C4A00(S_021C4A00 *s)
{
    func_02050278((struct BbActSys *)s->obj, s->id, 1);
}








/*
 * Queues callback d_021DAA2C with a two-word argument block.
 */
void func_021C4A10(void *a, u32 b)
{
    P2 t;

    t.a = func_021ABEA0((u32)a, 8);
    t.b = b;
    func_021ABFA8(a, d_021DAA2C, 0, 0, &t, 0);
}








/*
 * Spawns the field effect object above the owner's position and starts it.
 */
void func_021C4A3C(u32 a, Res *r)
{
    Pair *s = (Pair *)func_021AC1AC(a);
    Head *h;
    u32 t, k;
    V3 pos;
    Desc d;

    r->p = *s;
    func_0216D88C((const struct Actor *)r->p.f4, (struct VecFx32 *)&pos);
    h = (Head *)r->p.f0;
    t = h->f4;
    pos.y -= 0xE000;
    pos.z -= 0xA000;
    d.slot = h->h8;
    d.v12 = 0x1000;
    d.v14 = 0x1000;
    d.k = 0x1f;
    d.flag = 1;
    d.w = 1;
    d.pos = pos;
    d.f1c = 0;
    d.f20 = (u32)r;
    r->h8 = func_02050340((struct BbActSys *)t, 0, (const struct BbActDesc *)(&d), 1, 3);
    if (r->h8 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)t, r->h8, (u32)d_021DE478, 1);
    k = r->h8;
    func_0205082C((void *)t, k, 0);
    func_020507F0((void *)t, k, 1);
}








/*
 * Sets flag 1 on the field object unless the id is 0xFFFF.
 */
void func_021C4AE8(void *a, S *s)
{
    u32 x = s->p[1];

    if (s->id != 0xFFFF)
        func_02050468((struct BbActSys *)x, s->id, 1);
}






/*
 * Notifies the owner when the field-object query succeeds (EXACT*:
 * follower).
 */
void func_021C4B04(void *a, S *s)
{
    u32 tmp;

    if (func_020508EC((u8 *)s->p[1], s->id, (u16 *)(&tmp)) != 0)
        func_021AC154((u32)a);
}





void func_021C4B24(void) {}





/*
 * Allocates the 8-byte record and initialises it.
 */
R *func_021C4B28(void *owner, u32 heap)
{
    R *r = func_02030734(heap, 8, 1, d_021DE47C, 0x163);

    r->owner = owner;
    func_021C4B64((P_021C4B28 *)((struct P_021C4B28 *)r));
    return r;
}






/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C4B50(u32 a, u8 *p)
{
    func_021C4BC4((S_021C4BC4 *)p);
    func_020307B0(p);
}






void func_021C4B64(P_021C4B28 *p)
{
    u32 buf[9];
    u32 x = func_021ABE18((unsigned char *)p->f0);
    u32 y = func_021ABE24((u8 *)p->f0);

    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, y, 0x5f);
    func_021C6AF8(buf, y);
    func_021C6AFC(buf, 0x6a);
    p->h4 = func_021C6574(x, (u32)buf, 0);
    p->h6 = func_021C6590(x, p->h4, 0, 0);
    func_021C67D8(x, p->h6, 1);
}




/*
 * Applies the record's two parameters to the owner's map object.
 */
void func_021C4BC4(S_021C4BC4 *s)
{
    u32 o = func_021ABE18((unsigned char *)s->owner);

    func_021C6628(o, s->h6);
    func_021C6580((u8 *)o, s->h4);
}




/*
 * Queues callback d_021DAA18 with a two-word argument block.
 */
void func_021C4BE0(void *a, u32 b)
{
    P2 t;

    t.a = func_021ABEA0((u32)a, 0x11);
    t.b = b;
    func_021ABFA8(a, d_021DAA18, 0, 0, &t, 0);
}




void func_021C4C0C(int a, int *b)
{
    int v[3];
    int *p = (int *)func_021AC1AC(a);

    *(S_021C4C0C *)b = *(S_021C4C0C *)p;
    func_0216E1A4(b[1], (int)(b + 2));
    func_0216D88C((const struct Actor *)b[1], (struct VecFx32 *)v);
    v[2] += 0x8000;
    func_021AC1CC(a, v);
    ((struct Obj07561 *)b)->f10 = *(u16 *)(b[0] + 6);
}


void func_021C4C50(void) {}
