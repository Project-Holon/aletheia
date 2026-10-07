/*
 * file:     unit_021D66B0.c
 * unit:     yes
 * function: func_021D66B0, func_021D66D0, func_021D66D8, func_021D6730, func_021D6738, func_021D6740, func_021D6744, func_021D679C, func_021D67A8, func_021D67B0, func_021D67B8, func_021D67C4, func_021D67D0, func_021D67D8, func_021D67E8, func_021D67F4, func_021D6824, func_021D6848, func_021D6920, func_021D6940, func_021D69A0, func_021D69AC, func_021D69B8, func_021D6B6C, func_021D6B84, func_021D6BFC, func_021D6C24, func_021D6C2C, func_021D6C3C, func_021D6C50, func_021D6D54, func_021D6D5C, func_021D6D70, func_021D6D7C, func_021D6D90, func_021D6D9C, func_021D6DC4
 * address:  0x021D66B0
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
 *   func_021E8CFC 0x021E8CFC thumb ov093
 *   func_021E8D04 0x021E8D04 thumb ov093
 *   func_02017D30  0x02017D30  thumb
 *   func_02017988  0x02017988  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_021D52B4  0x021D52B4  thumb  ov093
 *   func_02082BCC 0x02082BCC arm
 *   func_02018584 0x02018584 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_021D505C 0x021D505C thumb ov093
 *   func_02017F9C  0x02017F9C  thumb
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D4EFC 0x021D4EFC thumb ov093
 *   func_021D4F84 0x021D4F84 thumb ov093
 *   func_021D50B4 0x021D50B4 thumb ov093
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_021D51DC  0x021D51DC  thumb  ov093
 *   d_021F3B8C     0x021F3B8C  data  a4
 *   d_021F3BC4     0x021F3BC4  data  a4
 *   func_021D6238 0x021D6238 thumb ov093
 */
#include "../../matched/include/Obj00041.h"
#include "../../matched/include/Obj03699.h"
#include "../../matched/include/Obj21234.h"
#include "../../matched/include/Obj18417.h"
#include "../../matched/include/Obj18418.h"
#include "../../matched/include/Obj21235.h"
#include "../../matched/include/Obj18419.h"
#include "../../matched/include/Obj02137.h"
#include "../../matched/include/Obj13443.h"
#include "../../matched/include/Obj21239.h"
#include "../../matched/include/Obj21240.h"
#include "../../matched/include/Obj18420.h"
#include "../../matched/include/Obj18421.h"
#include "../../matched/include/Obj07801.h"

struct Sav;
struct A;
struct Unk021D62A8;
struct S;
struct Work;
struct UtilSlots;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021D66D0  movs r2,#0x4f; lsls r2,#2; strh r1,[r0,r2] */
struct QJ { u8 pad[0x13c]; u16 v; };

typedef struct {
    void *w;
    u8 pad4[8];
    u16 fC;
    u8 pad0E[13];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj_021D66D8;

/* 021D6730  strh r1,[r0,#0x14]; movs r1,#0; strh r1,[r0,#0x12] */
struct QK { u8 pad[0x12]; u16 a; u16 b; };

/* 021D67A8  movs r1,#0x53; lsls r1,#2; ldrh r0,[r0,r1] */
struct QL { u8 pad[0x14c]; u16 v; };

/* 021D67B0  movs r1,#0x51; lsls r1,#2; ldrb r0,[r0,r1] */
struct QM { u8 pad[0x144]; u8 v; };

/* 021D67D0  ldrb r0,[r0,#0x1b]; lsls #0x18; lsrs #0x1f */
struct R3 { u8 pad[0x1b]; u8 a : 7; u8 b : 1; };

struct Rec {u16 a,b,c,d;};

struct Obj_021D69B8 {void *w; u32 f4,exp; u16 species,hp,total,item,f14,f16; u8 level,f19,f1A; u8 low:5,b5:1,b6:1,b7:1;};

struct Result {u8 level,pad; u16 hp,a,b,c,d,e;};

typedef struct {
    void *w;
    u8 pad4[4];
    u32 f8;
    u8 padC[4];
    u16 f10;
    u16 f12;
    u8 pad14[7];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj_021D6B84;

struct Flags { u8 pad[0x1b]; u8 low:5; u8 active:1; u8 high:2; };

/* 021D6C24  ldrb r0,[r0,#0x1b]; lsls #0x19; lsrs #0x1f */
struct R4 { u8 pad[0x1b]; u8 a : 6; u8 b : 1; u8 c : 1; };

struct Unk021D6C2C {
    u32 f0;
    u32 f4;
    u8 pad8[0x13];
    u8 lo : 6;
    u8 b6 : 1;
    u8 b7 : 1;
};

typedef struct { u32 w[0x3b]; } Head;

typedef struct { u16 h[6]; u8 pad[2]; } Ent;

typedef struct Unk021D6C50 {
    u32 pad00[6];
    u8 pad18[3];
    u8 lo : 5;
    u8 flag : 1;
    u8 hi : 2;
    u8 pad1c[0x104 - 0x1c];
    Ent ent[4];
    u8 pad13c[8];
    u8 f144;
    u8 pad145;
    u16 f146;
    u16 f148;
    u16 f14a;
    u16 f14c;
    u16 f14e;
    u8 pad150[2];
    u8 f152;
    u8 f153[2];
    u8 f155[2];
    u8 pad157[0x1f2 - 0x157];
    u16 h1f2;
    u8 pad1f4[4];
} S;

/* 021D6D54  ldrb r0,[r0,#0x1b]; lsls #0x1a; lsrs #0x1f */
struct R5 { u8 pad[0x1b]; u8 a : 5; u8 b : 1; u8 c : 2; };

extern u8 func_021E8CFC(int);
extern int func_021E8D04(int x);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017988(void *p, u32 a);
extern u32 func_02017E1C(void *h, u32 k, u32 z);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_021D52B4(u8 *p, void *h, u32 flag);
extern void func_02082BCC(void *,u8,u32);
extern u32 func_02018584(u16,u16,u16);
extern void func_02017E40(void *,u32,u32);
extern void func_020185C4(void *);
extern void func_021D505C(struct A *a);
extern void func_02017F9C(void *p, u32 v);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern void func_021D4EFC(struct S *,void *,u32,u32);
extern int func_021D4F84(u8 *,void *,int);
extern void func_021D50B4(struct Work *);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_021D51DC(struct S *p, u32 a, u32 b, u32 c);
extern void func_021D6238(struct UtilSlots *,int);
void func_021D66B0(u8 *p,int n);
void func_021D66D0(struct QJ *p, u32 v);
void func_021D66D8(Obj_021D66D8 *p, u32 v);
void func_021D6730(struct QK *p, u16 v);
void func_021D6738(u8 *p);
/* 021D6740 ldrh r0,[r0,#0x14] */ u16 func_021D6740(struct QK *p);
void func_021D6744(u8 *p, u8 a, int f, u8 b, u16 c, u16 d);
u16 func_021D679C(u8 *p);
u16 func_021D67A8(struct QL *p);
u8 func_021D67B0(struct QM *p);
u16 func_021D67B8(u8 *p);
u8 func_021D67C4(u8 *p);
int func_021D67D0(struct R3 *p);
void func_021D67D8(u8 *p, u32 n);
u16 func_021D67E8(u8 *p);
void func_021D67F4(u8 *p);
void func_021D6824(u8 *p);
void func_021D6848(u8 *p, struct Rec *r);
int func_021D6920(u8 *p, u32 n);
int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
void func_021D69A0(unsigned char *base, int idx, unsigned char val);
unsigned char func_021D69AC(unsigned char *base, int idx);
int func_021D69B8(struct Obj_021D69B8 *p, u32 *remaining, struct Result *r);
u32 func_021D6B6C(u8 *p);
void func_021D6B84(Obj_021D6B84 *p, int flag);
void func_021D6BFC(u8 *p);
int func_021D6C24(struct R4 *p);
void func_021D6C2C(struct Unk021D6C2C *p);
void func_021D6C3C(void **p,void *q);
int func_021D6C50(S *a, S *b);
int func_021D6D54(struct R5 *p);
void func_021D6D5C(u8 *p,u16 n);
void func_021D6D70(unsigned char *p);
/* 021D6D7C halfword field 0x1f2 != 0 */ u32 func_021D6D7C(u8 *p);
int func_021D6D90(u8 *p);
int func_021D6D9C(u8 *p, u16 *value);
void func_021D6DC4(u8 *p);
void func_021D6DCC(u8 *p, u32 v);
extern u8 d_021F3B8C[0x38];
extern Head d_021F3BC4;

void func_021D66B0(u8 *p,int n) { p[0xf8]=func_021E8CFC(n); p[0xf9]=func_021E8D04(n); }

void func_021D66D0(struct QJ *p, u32 v) { p->v = v; }


void func_021D66D8(Obj_021D66D8 *p, u32 v)
{
    u32 t;
    ((u8 *)p)[0x141] = v;
    t = func_02017D30(p->w);
    func_02017988(p->w, v);
    func_021D52B4((u8 *)p, p->w, 1);
    if (p->fC == 0x1ec && v == 0) {
        p->f1b_lo = 0;
        ((struct Obj00041 *)p)->f13C = func_02017E1C(p->w, 10, 0);
    }
    func_02017D70(p->w, t);
}

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: strh r1, [r0, #0x14]; movs r1, #0; strh r1, [r0, #0x12]; bx lr.
 */
void func_021D6730(struct QK *p, u16 v)
{
    p->b = v;
    p->a = 0;
}


void func_021D6738(u8 *p)
{
    *(u16 *)&p[0x14] = 0x0;
}

/* 021D6740  ldrh r0,[r0,#0x14] */
/*
 * Reads the u16 field at #0x14 of the argument and returns it.
 */
u16 func_021D6740(struct QK *p) { return p->b; }

void func_021D6744(u8 *p, u8 a, int f, u8 b, u16 c, u16 d)
{
    u16 old = ((struct Obj03699 *)p)->f14C;
    ((struct Obj03699 *)p)->f14A = d;
    ((struct Obj03699 *)p)->f14C = c;
    p[0x152] = a;
    p[0x144] = b;
    if (old == c) {
        if (f) ((struct Obj03699 *)p)->f14E += 1;
        else ((struct Obj03699 *)p)->f14E = 0;
    } else {
        ((struct Obj03699 *)p)->f14E = f ? 1 : 0;
    }
}

u16 func_021D679C(u8 *p) { return ((struct Obj21234 *)p)->f14E; }

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x53; lsls r1, r1, #2; ldrh r0, [r0, r1]; bx lr.
 */
u16 func_021D67A8(struct QL *p) { return p->v; }

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0x51; lsls r1, r1, #2; ldrb r0, [r0, r1]; bx lr.
 */
u8 func_021D67B0(struct QM *p) { return p->v; }


/*
 * ldrh at #0x14a (pool constant)
 */
u16 func_021D67B8(u8 *p)
{
    return ((struct Obj18417 *)p)->f14A;
}


/*
 * ldrb at #0x152 (pool constant)
 */
u8 func_021D67C4(u8 *p)
{
    return ((struct Obj18418 *)p)->f152;
}

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldrb r0, [r0, #0x1b]; lsls r0, r0, #0x18; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021D67D0(struct R3 *p) { return p->b; }

void func_021D67D8(u8 *p, u32 n) { if(n<1) n=1; ((struct Obj21235 *)p)->f13E=n; }


/*
 * ldrh at #0x13e (pool constant)
 */
u16 func_021D67E8(u8 *p)
{
    return ((struct Obj18419 *)p)->f13E;
}

void func_021D67F4(u8 *p) { func_02082BCC(p+0x15c,0,0x90); func_02082BCC(p+0x1ec,0,3); p[0x1ef]=0; p[0x1f0]=0; }

void func_021D6824(u8 *p) { p[0x1ef]++; if(p[0x1ef]>=3) p[0x1ef]=0; (p+p[0x1ef])[0x1ec]=0; }

void func_021D6848(u8 *p, struct Rec *r)
{
    u8 n;
    u8 k = p[0x1ef];
    u32 i;
    u8 *q;
    n = (p + 0x1ec)[k];
    if (n == 6) {
        for (i = 0; i < 5; i++) {
            q = p + k * 0x30 + i * 8;
            ((struct Obj02137 *)q)->f15C = ((struct Obj02137 *)q)->f164;
            ((struct Obj02137 *)q)->f15E = ((struct Obj02137 *)q)->f166;
            ((struct Obj02137 *)q)->f160 = ((struct Obj02137 *)q)->f168;
            ((struct Obj02137 *)q)->f162 = ((struct Obj02137 *)q)->f16A;
        }
        n--;
    }
    q = p + k * 0x30 + n * 8;
    ((struct Obj02137 *)q)->f15C = r->a;
    ((struct Obj02137 *)q)->f15E = r->b;
    ((struct Obj02137 *)q)->f160 = r->c;
    ((struct Obj02137 *)q)->f162 = r->d;
    if ((p + 0x1ec)[k] < 6) (p + 0x1ec)[k]++;
}

int func_021D6920(u8 *p, u32 n) { if(n<3) { n=p[0x1ef]-n; if((int)n<0) n+=3; return (p+n)[0x1ec]; } return 0; }


int func_021D6940(const u8 *p, int i, u32 j, u16 *out)
{
    int k;
    u32 n;
    u16 *e;

    if ((u32)i < 3) {
        k = p[0x1ef] - i;
        if (k < 0) k += 3;
        n = (p + k)[0x1ec];
        if (j < n) {
            e = (u16 *)(p + k * 0x30 + (u8)(n - j - 1) * 8);
            out[0] = e[0x15c / 2];
            out[1] = e[0x15e / 2];
            out[2] = e[0x160 / 2];
            out[3] = e[0x162 / 2];
            return 1;
        }
    }
    return 0;
}

void func_021D69A0(unsigned char *base, int idx, unsigned char val)
{
    unsigned char *p = base + idx;

    p[0x157] = val;
}


unsigned char func_021D69AC(unsigned char *base, int idx)
{
    unsigned char *p = base + idx;

    return p[0x157];
}

int func_021D69B8(struct Obj_021D69B8 *p, u32 *remaining, struct Result *r)
{
    u32 old, total, delta, threshold;
    u16 hp,a,b,d,e,c;
    u8 saved;
    if (p->level < 100) {
        old = p->exp;
        total = old + *remaining;
        threshold = func_02018584(p->species,((u8 *)p)[0x141],p->level + 1);
        if (total >= threshold) {
            delta = threshold - old;
            hp = p->hp;
            saved = func_02017D30(p->w);
            a = func_02017E1C(p->w,0xa2,0);
            b = func_02017E1C(p->w,0xa3,0);
            c = func_02017E1C(p->w,0xa4,0);
            d = func_02017E1C(p->w,0xa5,0);
            e = func_02017E1C(p->w,0xa6,0);
            p->exp = old + delta;
            func_02017E40(p->w,8,p->exp);
            func_020185C4(p->w);
            p->hp = func_02017E1C(p->w,0xa1,0);
            p->level = func_02017E1C(p->w,0x9e,0);
            hp = p->hp - hp;
            r->a = func_02017E1C(p->w,0xa2,0);
            r->b = func_02017E1C(p->w,0xa3,0);
            r->c = func_02017E1C(p->w,0xa5,0);
            r->d = func_02017E1C(p->w,0xa6,0);
            r->e = func_02017E1C(p->w,0xa4,0);
            if (p->b5 == 0) {
                ((struct Obj00041 *)p)->fEE = r->a;
                ((struct Obj00041 *)p)->fF0 = r->b;
                ((struct Obj00041 *)p)->fF2 = r->c;
                ((struct Obj00041 *)p)->fF4 = r->d;
                ((struct Obj00041 *)p)->fF6 = r->e;
            }
            r->level = p->level;
            r->hp = hp;
            r->a -= a;
            r->b -= b;
            r->c -= d;
            r->d -= e;
            r->e -= c;
            p->total += hp;
            func_02017E40(p->w,0xa0,p->total);
            func_021D505C((struct A *)p);
            func_02017D70(p->w,saved);
            *remaining -= delta;
            return 1;
        } else {
            p->exp = total;
            func_02017E40(p->w,8,total);
        }
    }
    if (r != 0) func_02082BCC(r,0,14);
    return 0;
}

u32 func_021D6B6C(u8 *p) { return func_02018584(((struct Obj13443 *)p)->fC,p[0x141],100); }


void func_021D6B84(Obj_021D6B84 *p, int flag)
{
    void *w = p->w;
    u32 r;

    func_02017E40(w, 8, p->f8);
    func_02017E40(w, 0xa0, p->f10);
    if (p->f10 != 0)
        func_02017F9C(w, func_021D62A8((struct Unk021D62A8 *)p));
    else
        func_02017F9C(w, 0);
    func_021D505C((struct A *)p);
    if (p->f1b_b5 || flag != 0)
        r = p->f1b_lo;
    else
        r = ((u8 *)p)[0x141];
    func_02017E40(w, 0x6f, (u8)r);
    func_020185C4(w);
    func_02017E40(w, 6, p->f12);
}

void func_021D6BFC(u8 *p) { if(!((struct Flags *)p)->active) { func_021D4EFC((struct S *)p,((struct Obj00041 *)p)->f0,1,0); func_021D50B4((struct Work *)p); } else { func_021D4F84(p,((struct Obj00041 *)p)->f0,0); } }

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldrb r0, [r0, #0x1b]; lsls r0, r0, #0x19; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021D6C24(struct R4 *p) { return p->b; }


void func_021D6C2C(struct Unk021D6C2C *p)
{
    p->b6 = 0;
    p->f4 = 0;
}

void func_021D6C3C(void **p,void *q) { func_02017E1C(q,5,0); *p=q; }

int func_021D6C50(S *a, S *b)
{
    u16 save;
    int i;
    if (a->flag == 0 && b->flag == 0 && b->h1f2 == 0) {
        MI_CpuCopy8(a->ent, d_021F3B8C, 0x38);
        d_021F3BC4 = *(Head *)a;
        save = a->h1f2;
        *a = *b;
        *(Head *)a = d_021F3BC4;
        a->h1f2 = save;
        MI_CpuCopy8(d_021F3B8C, a->ent, 0x38);
        for (i = 0; i < 4; i++)
            func_021D51DC((struct S *)(&a->ent[i]), b->ent[i].h[3], 5, 0);
        MI_CpuFill8(a->f153, 0, sizeof(a->f153));
        MI_CpuFill8(a->f155, 0, sizeof(a->f155));
        a->f148 = 10000;
        a->f146 = 0;
        a->f14a = 0;
        a->f14c = 0;
        a->f144 = 0x11;
        a->f14e = 0;
        a->flag = 1;
        return 1;
    }
    return 0;
}

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: ldrb r0, [r0, #0x1b]; lsls r0, r0, #0x1a; lsrs r0, r0, #0x1f; bx lr.
 */
int func_021D6D54(struct R5 *p) { return p->b; }

void func_021D6D5C(u8 *p,u16 n) { ((struct Obj21239 *)p)->f1F2=n; func_021D6238((struct UtilSlots *)p,8); }


void func_021D6D70(unsigned char *p)
{
    ((struct Obj21240 *)p)->f1F2 = 0;
}


/* 021D6D7C  halfword field 0x1f2 != 0 */
u32 func_021D6D7C(u8 *p)
{
    return (((struct Obj18420 *)p)->f1F2 != 0);
}


/*
 * ldrh at #0x1f2 (pool constant)
 */
int func_021D6D90(u8 *p)
{
    return ((struct Obj18421 *)p)->f1F2;
}

/*
 * lever: bind the requested halfword, keeping the object's remaining value inline.
 */
int func_021D6D9C(u8 *p, u16 *value)
{
    u16 requested;
    requested = *value;
    if (((struct Obj07801 *)p)->f1F2 <= requested) {
        *value = ((struct Obj07801 *)p)->f1F2;
        ((struct Obj07801 *)p)->f1F2 = 0;
        return 1;
    }
    ((struct Obj07801 *)p)->f1F2 -= requested;
    return 0;
}


void func_021D6DC4(u8 *p)
{
    p[0xd0] = 0;
}


void func_021D6DCC(u8 *p, u32 v)
{
    u32 i;
    u8 n = p[0xd0];

    for (i = 0; i < n; i++) {
        if (v == (p + i)[0xd1]) return;
    }
    if (i < 0x18) {
        (p + i)[0xd1] = v;
        p[0xd0]++;
    }
}
