/*
 * file:     btl_net_p20.c
 * unit:     yes
 * function: func_021D554C, func_021D5568, func_021D5584, func_021D55A0, func_021D55D8, func_021D5608, func_021D5640, func_021D5674, func_021D56A0, func_021D56CC, func_021D5734, func_021D5750, func_021D5778, func_021D57A8, func_021D57FC, func_021D5814, func_021D5844, func_021D5848, func_021D5854, func_021D5864, func_021D587C, func_021D58A8, func_021D590C, func_021D5970, func_021D59B4, func_021D5AD8, func_021D5B40, func_021D5B44, func_021D5B48, func_021D5B68, func_021D5B7C, func_021D5BA4, func_021D5BB0, func_021D5BDC, func_021D5C08, func_021D5C30, func_021D5C44, func_021D5CB4, func_021D5D14, func_021D5D50, func_021D5D68, func_021D5DC0
 * address:  0x021D554C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E40  0x02017E40  thumb
 *   func_021D51DC 0x021D51DC thumb ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021E8CE0  0x021E8CE0  thumb  ov093
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_02017D30  0x02017D30  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_021D78E4  0x021D78E4  thumb  ov093
 *   data_021F040C  0x021F040C  data  ov093
 *   _dflt   0x0209B750  arm
 *   _dfltu  0x0209B790  arm
 *   _ddiv   0x0209D1E0  arm
 *   _dgr    0x0209B864  arm
 *   _dmul   0x0209B2E8  arm
 *   _dadd   0x0209AC04  arm
 *   _dsub   0x0209AF34  arm
 *   _dfix   0x0209C508  arm
 */
#include "../../matched/include/Obj00041.h"
#include "../../matched/include/Obj18410.h"

struct S;
struct Unk021D62A8;
struct Sav;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct UtilEntry {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u16 f4;
    u16 f6;
    u8 f8;
    u8 f9;
    u16 fA;
    u8 fC;
    u8 fD;
};

struct UtilWork {
    void *f0;
    u8 pad4[0x100];
    struct UtilEntry e[4];
    u8 pad13C[4];
    u8 n140;
    u8 pad141[3];
    u8 f144;
    u8 pad145[5];
    u16 f14A;
    u16 f14C;
    u16 f14E;
    u8 pad150[3];
    u8 bits153[2];
    u8 bits155[2];
    u8 f157[5];
};

typedef struct { u16 a; u8 b; u8 c; u8 pad[10]; } Ent;

struct Entry_021D5640 { u8 pad0[2]; u8 a; u8 pad3[9]; u8 flag; u8 rest; };

struct Work_021D5640 { void *obj; u8 pad4[0x100]; struct Entry_021D5640 e[]; };

struct Entry_021D5674 { u16 id; u8 a; u8 b; u16 c; u16 other; u8 x; u8 y; u16 z; u8 flag; u8 rest; };

struct Entry_021D56A0 { u16 id; u8 a; u8 b; u16 c; u16 other; u8 x; u8 y; u16 z; u8 flag; u8 rest; };

struct Ent {
    u8 pad0[5];
    u8 lo5:4;
    u8 hi5:4;
    u8 pad6[5];
    u8 lo11:4;
    u8 hi11:4;
    u8 c;
    u8 padD;
};

struct Work_021D56CC {
    u8 pad0[0x104];
    struct Ent e[4];
    u8 pad13C[7];
    u8 c143;
};

/* 021D5848  ldrb r2,[r0,#0x1b]; str r1,[r0,#4]; movs r1,#0x40; orrs r1,r2;
 *           strb r1,[r0,#0x1b] */
struct QH { u8 pad[4]; void *v; u8 pad2[0x1b - 8]; u8 flags; };

struct Work_021D5854 { void *a; void *b; u8 pad[0x13]; u8 low:6; u8 flag:1; u8 high:1; };

struct Work_021D5864 { void *a; void *b; u8 pad[0x13]; u8 low:6; u8 flag:1; u8 high:1; };

/* 021D5B40  ldrh r0,[r0,#0x12] */
struct QI { u8 pad[0x12]; u16 v; };

struct Rat {
    u8 pad0[0xe];
    u16 den;
    u16 num;
};

extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_021D51DC(struct S *p, unsigned int a, unsigned int b, unsigned int c);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u16 func_021E8CE0(u32 a, u32 b);
extern int func_021EF948(int);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017E1C(void *h, u32 k, u32 z);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern unsigned short func_021D78E4(unsigned short a, int i);
u8 func_021D554C(u8 *p, u8 i);
u8 func_021D5568(u8 *p, u32 i);
u8 func_021D5584(struct UtilWork *p, u32 i);
int func_021D55A0(struct UtilWork *p, int id);
int func_021D55D8(u8 *p, int i, int s);
void func_021D5608(struct UtilWork *p, int i, u8 n);
void func_021D5640(struct Work_021D5640 *p, u32 i, u32 n);
u16 func_021D5674(u8 *p, u32 i, u8 n);
u16 func_021D56A0(u8 *p, u32 i, u8 n);
void func_021D56CC(struct Work_021D56CC *p, int i);
void func_021D5734(u8 *p, u8 i, u16 a, u8 b, u32 c);
int func_021D5750(u8 *p, u16 id);
u8 func_021D5778(struct UtilWork *p, u16 id);
void func_021D57A8(u8 *p, u8 *a, u8 *b);
u16 func_021D57FC(void *p);
int func_021D5814(void *p, int k);
/* 021D5844 ldr r0,[r0] */ void *func_021D5844(void *m);
void func_021D5848(struct QH *p, void *v);
void func_021D5854(struct Work_021D5854 *p);
void *func_021D5864(struct Work_021D5864 *p);
int func_021D587C(void *p, int k);
int func_021D58A8(u8 *p, int k);
void func_021D590C(void **p, u16 *out);
void func_021D5970(u8 *p, int k, u16 v);
int func_021D59B4(u8 *p, int k);
int func_021D5AD8(u8 *p, int k);
u16 func_021D5B40(struct QI *p);
/* 021D5B44 strh r1,[r0,#0x12] */ void func_021D5B44(struct QI *p, u16 v);
int func_021D5B48(u8 *p);
int func_021D5B68(void *p);
int func_021D5B7C(void *m);
unsigned short func_021D5BA4(int *p);
int func_021D5BB0(struct UtilWork *p, u32 n);
int func_021D5BDC(struct UtilWork *p, u32 n);
u32 func_021D5C08(struct UtilWork *p);
int func_021D5C30(struct UtilWork *p);
int func_021D5C44(struct Rat *p);
s8 *func_021D5CB4(s8 *p, int i, u8 *a, u8 *b);
int func_021D5D14(s8 *p, int i, int sign);
int func_021D5D50(s8 *p, int i);
int func_021D5D68(s8 *p);
u8 func_021D5DC0(s8 *p, int i, u8 n);
extern const u32 data_021F040C[4];

u8 func_021D554C(u8 *p, u8 i) { u8 *q = (u8 *)((u32)p + i * 14); return q[0x10d] - q[0x10c]; }

u8 func_021D5568(u8 *p, u32 i) { u8 *q = (u8 *)((u32)p + i * 14); return q[0x107] - q[0x106]; }


u8 func_021D5584(struct UtilWork *p, u32 i)
{
    if (i < p->n140) return p->e[i].f8;
    return 0;
}


int func_021D55A0(struct UtilWork *p, int id)
{
    u32 i;
    for (i = 0; i < *(volatile u8 *)&p->n140; i++) {
        if (id == p->e[i].f6) return p->e[i].f8;
    }
    return 0;
}

/*
 * lever: the index is added in each arm of the table select, so the sum is
 * formed once and shared by the halfword and byte loads.
 */
int func_021D55D8(u8 *p, int i, int s)
{
    Ent *e;
    if (s) e = (Ent *)(p + 0x104) + i; else e = (Ent *)(p + 0x10a) + i;
    if (e->a != 0 && e->b == e->c) return 1;
    return 0;
}


void func_021D5608(struct UtilWork *p, int i, u8 n)
{
    if (p->e[i].f8 >= n) p->e[i].f8 -= n;
    else p->e[i].f8 = 0;
    if (p->e[i].fC != 0) {
        p->e[i].f2 = p->e[i].f8;
        func_02017E40(p->f0, i + 0x3A, p->e[i].f2);
    }
}

void func_021D5640(struct Work_021D5640 *p, u32 i, u32 n)
{
    int v;
    if (p->e[i].flag == 0) {
        v = (int)((u32)p->e[i].a - n);
        if (v < 0) v = 0;
        p->e[i].a = v;
        func_02017E40(p->obj, i + 0x3a, p->e[i].a);
    }
}

u16 func_021D5674(u8 *p, u32 i, u8 n)
{
    struct Entry_021D5674 *e = (struct Entry_021D5674 *)((u32)p + 0x104 + i * 14);
    e->x += n;
    if (e->x > e->y) e->x = e->y;
    if (e->flag) e->a = e->x;
    return e->other;
}

u16 func_021D56A0(u8 *p, u32 i, u8 n)
{
    struct Entry_021D56A0 *e = (struct Entry_021D56A0 *)((u32)p + 0x104 + i * 14);
    e->a += n;
    if (e->a > e->b) e->a = e->b;
    if (e->flag) e->x = e->a;
    return e->id;
}


void func_021D56CC(struct Work_021D56CC *p, int i)
{
    struct Ent *e = &p->e[i];
    if (e->hi11 == 0) {
        e->hi11 = 1;
        p->c143++;
    }
    e->lo11 = 1;
    if (e->c != 0) {
        e->lo5 = e->lo11;
        e->hi5 = e->hi11;
    }
}

void func_021D5734(u8 *p, u8 i, u16 a, u8 b, u32 c)
{ func_021D51DC((void *)((u32)p + 0x104 + i * 14), a, b, c); }

int func_021D5750(u8 *p, u16 id)
{ u32 i; for(i=0;i<4;i++) if(id == *(u16 *)((u32)p + i * 14 + 0x10a)) return 1; return 0; }


u8 func_021D5778(struct UtilWork *p, u16 id)
{
    u32 i;
    if (id != 0) {
        for (i = 0; i < 4; i++) {
            if (id == p->e[i].f6) return (u8)i;
        }
    }
    return 4;
}


void func_021D57A8(u8 *p, u8 *a, u8 *b)
{
    int r = func_021D62C4((struct Unk021D62A8 *)p, 0x18);
    u8 v;
    v = p[0xF8];
    if (v == 2 && r) *a = 0x11;
    else *a = v;
    v = p[0xF9];
    if (v == 2 && r) *b = 0x11;
    else *b = v;
    if (*a == 0x11) {
        if (*b == 0x11) *b = 0;
        *a = *b;
    } else if (*b == 0x11) {
        *b = *a;
    }
}


u16 func_021D57FC(void *p)
{
    u8 a;
    u8 b;
    func_021D57A8(p, &a, &b);
    return func_021E8CE0(a, b);
}


int func_021D5814(void *p, int k)
{
    u8 a;
    u8 b;
    if (k != 0x11) {
        func_021D57A8(p, &a, &b);
        if (a == k || b == k) return 1;
    }
    return 0;
}


/* 021D5844  ldr r0,[r0] */
/*
 * Reads the u32 field at offset 0 of the argument and returns it.
 */
void *func_021D5844(void *m) { return ((struct Obj00041 *)m)->f0; }

/*
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: ldrb r2, [r0, #0x1b]; str r1, [r0, #4]; movs r1, #0x40; orrs r1, r2; strb r1, [r0, #0x1b]; bx lr.
 */
void func_021D5848(struct QH *p, void *v)
{
    u8 f = p->flags;
    p->v = v;
    p->flags = f | 0x40;
}

void func_021D5854(struct Work_021D5854 *p) { p->b = 0; p->flag = 0; }

void *func_021D5864(struct Work_021D5864 *p) { if (p->b && p->flag) return p->b; return p->a; }

int func_021D587C(void *p, int k)
{
    switch(k) {
    case 9: if (func_021EF948(6)) k = 11; break;
    case 11: if (func_021EF948(6)) k = 9; break;
    }
    return k;
}


int func_021D58A8(u8 *p, int k)
{
    int v = func_021D587C(p, k);
    switch (v) {
    case 8:
        return ((struct Obj00041 *)p)->fEE;
    case 9:
        return ((struct Obj00041 *)p)->fF0;
    case 10:
        return ((struct Obj00041 *)p)->fF2;
    case 11:
        return ((struct Obj00041 *)p)->fF4;
    case 12:
        return ((struct Obj00041 *)p)->fF6;
    case 6:
        return 6;
    case 7:
        return 6;
    }
    return func_021D59B4(p, v);
}


void func_021D590C(void **p, u16 *out)
{
    u8 v = func_02017D30(*p);
    out[1] = func_02017E1C(*p, 0xa1, 0);
    out[2] = func_02017E1C(*p, 0xa2, 0);
    out[3] = func_02017E1C(*p, 0xa3, 0);
    out[4] = func_02017E1C(*p, 0xa5, 0);
    out[5] = func_02017E1C(*p, 0xa6, 0);
    out[6] = func_02017E1C(*p, 0xa4, 0);
    func_02017D70(*p, v);
}


void func_021D5970(u8 *p, int k, u16 v)
{
    switch (func_021D587C(p, k)) {
    case 8:
        ((struct Obj00041 *)p)->fEE = v;
        break;
    case 9:
        ((struct Obj00041 *)p)->fF0 = v;
        break;
    case 10:
        ((struct Obj00041 *)p)->fF2 = v;
        break;
    case 11:
        ((struct Obj00041 *)p)->fF4 = v;
        break;
    case 12:
        ((struct Obj00041 *)p)->fF6 = v;
        break;
    }
}


/*
 * lever: the switch value stays in r1 and is the hidden second argument of
 * func_021D58A8; case 17 falls through into case 16.
 *
 * Addresses are Black-image addresses.
 */
int func_021D59B4(u8 *p, int k)
{
    int v = func_021D587C(p, k);

    switch (v) {
    case 8:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct Obj00041 *)p)->fFC);
    case 9:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct Obj00041 *)p)->fFD);
    case 10:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct Obj00041 *)p)->fFE);
    case 11:
        return func_021D78E4(func_021D58A8(p, v), *(u8 *)&((struct Obj00041 *)p)->fFF);
    case 12:
        return func_021D78E4(func_021D58A8(p, v), ((struct Obj00041 *)p)->f100);
    case 1:
        return ((struct Obj00041 *)p)->fFC;
    case 2:
        return ((struct Obj00041 *)p)->fFD;
    case 3:
        return ((struct Obj00041 *)p)->fFE;
    case 4:
        return ((struct Obj00041 *)p)->fFF;
    case 5:
        return *(s8 *)&((struct Obj00041 *)p)->f100;
    case 6:
        return ((struct Obj00041 *)p)->f101;
    case 7:
        return ((struct Obj00041 *)p)->f102;
    case 15:
        return ((struct Obj00041 *)p)->f18;
    case 18:
        return ((struct Obj00041 *)p)->fFA;
    case 13:
        return ((struct Obj00041 *)p)->f10;
    case 14:
        return ((struct Obj00041 *)p)->fE;
    case 21:
        return ((struct Obj00041 *)p)->f1A;
    case 17:
        if (func_021D62C4((struct Unk021D62A8 *)p, 0x10) != 0)
            return 0;
    case 16:
        return ((struct Obj00041 *)p)->f13C;
    case 19:
        return ((struct Obj00041 *)p)->f141;
    case 20:
        return ((struct Obj00041 *)p)->f8;
    case 0:
        break;
    }
    return 0;
}


int func_021D5AD8(u8 *p, int k)
{
    int r = 0;
    switch (func_021D587C(p, k)) {
    case 8:
        if (((struct Obj00041 *)p)->fFC < 6) r = 1;
        break;
    case 10:
        if (((struct Obj00041 *)p)->fFE < 6) r = 1;
        break;
    case 9:
        if (((struct Obj00041 *)p)->fFD > 6) r = 1;
        break;
    case 11:
        if (((struct Obj00041 *)p)->fFF > 6) r = 1;
        break;
    }
    if (r) return func_021D58A8(p, k);
    return func_021D59B4(p, k);
}

/*
 * Reads the u16 field at #0x12 of the argument and returns it.
 */
u16 func_021D5B40(struct QI *p) { return p->v; }

/* 021D5B44  strh r1,[r0,#0x12] */
/*
 * Stores the second argument (a u16) into the field at #0x12.
 */
void func_021D5B44(struct QI *p, u16 v) { p->v = v; }

int func_021D5B48(u8 *p)
{
    if (func_021D59B4(p, 0xd) == func_021D59B4(p, 0xe)) return 1;
    return 0;
}


int func_021D5B68(void *p)
{
    if (func_021D59B4(p, 13) == 0) return 1;
    return 0;
}

/*
 * extent: follower 021D5BA4 is already filed in pkt_021D5BA4.
 */
int func_021D5B7C(void *m)
{
    int ok;
    ok = 0;
    if (func_02017E1C(((struct Obj00041 *)m)->f0, 0x4c, 0)) return ok;
    if (func_021D5B68(m) == 0) ok = 1;
    return ok;
}


/*
 * Unlabelled ov093 leaf hidden in a .word run: returns the unsigned halfword
 * at +0x146 of its argument.  Matched to supply the `matched` witness for the
 * pending ov096 caller func_02189A9C.
 */
unsigned short func_021D5BA4(int *p)
{
    return ((struct Obj18410 *)p)->f146;
}


int func_021D5BB0(struct UtilWork *p, u32 n)
{
    return (p->bits153[(u8)(n >> 3)] & (u8)(1 << (n & 7))) ? 1 : 0;
}


int func_021D5BDC(struct UtilWork *p, u32 n)
{
    return (p->bits155[(u8)(n >> 3)] & (u8)(1 << (n & 7))) ? 1 : 0;
}


u32 func_021D5C08(struct UtilWork *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        if (func_021D5BDC(p, data_021F040C[i])) return data_021F040C[i];
    }
    return 0x10;
}

int func_021D5C30(struct UtilWork *p)
{
    if (func_021D5C08(p) != 16) return 1;
    return 0;
}


int func_021D5C44(struct Rat *p)
{
    double x = (double)(100 * p->num) / (double)p->den;
    double y;
    if (x > 0)
        y = 4096.0 * x + 0.5;
    else
        y = 4096.0 * x - 0.5;
    return (int)y;
}

s8 *func_021D5CB4(s8 *p, int i, u8 *a, u8 *b)
{
    *a = 0;
    *b = 12;
    switch (i) {
    case 1: return p + 0xfc;
    case 2: return p + 0xfd;
    case 3: return p + 0xfe;
    case 4: return p + 0xff;
    case 5: return p + 0x100;
    case 6: return p + 0x101;
    case 7: return p + 0x102;
    default: return 0;
    }
}

/*
 * extent: final two bytes are zero alignment padding.
 * evidence: 021D5CB4 unconditionally writes both outputs before its switch.
 */
int func_021D5D14(s8 *p, int i, int sign)
{
    s8 a;
    s8 b;
    s8 *v;
    v = func_021D5CB4(p, i, (u8 *)&a, (u8 *)&b);
    if (sign > 0) return *v < b;
    else return *v > a;
}

/*
 * lever: a declared before b places b at stack offset zero.
 * evidence: 021D5CB4 unconditionally writes both outputs before its switch.
 */
int func_021D5D50(s8 *p, int i)
{
    s8 a;
    s8 b;
    s8 *v;
    v = func_021D5CB4(p, i, (u8 *)&a, (u8 *)&b);
    return b - *v;
}

int func_021D5D68(s8 *p)
{
    if (p[0xfc] < 6) return 1;
    if (p[0xfd] < 6) return 1;
    if (p[0xfe] < 6) return 1;
    if (p[0xff] < 6) return 1;
    if (p[0x100] < 6) return 1;
    if (p[0x101] < 6) return 1;
    if (p[0x102] < 6) return 1;
    return 0;
}

u8 func_021D5DC0(s8 *p, int i, u8 n)
{
    s8 *q;
    int t;
    switch (i) {
    case 1: q = p + 0xfc; break;
    case 2: q = p + 0xfd; break;
    case 3: q = p + 0xfe; break;
    case 4: q = p + 0xff; break;
    case 5: q = p + 0x100; break;
    case 6: q = p + 0x101; break;
    case 7: q = p + 0x102; break;
    default: return 0;
    }
    t = q[0];
    if (t < 12) {
        if (t + n > 12) n = 12 - t;
        q[0] += n;
        return n;
    }
    return 0;
}
