/*
 * file:     eventdata_system_p12.c
 * unit:     yes
 * function: func_02162438, func_02162450, func_02162458, func_0216245C, func_02162478, func_021624B0, func_02162530, func_0216255C, func_02162560, func_02162564, func_02162598, func_021625CC, func_021625E8, func_021625FC, func_02162694, func_021626A8, func_021626B0, func_021626B8, func_021626E8, func_021626EC, func_02162708, func_02162740
 * address:  0x02162438
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215E2B8  0x0215E2B8  thumb  ov010
 *   func_02162F0C 0x02162F0C thumb ov010
 *   func_02013ECC  0x02013ECC  thumb
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02162D2C 0x02162D2C thumb ov010
 *   func_02162E00 0x02162E00 thumb ov010
 *   func_020140F8 0x020140F8 thumb
 *   func_02014110 0x02014110 thumb
 *   func_02014134 0x02014134 thumb
 *   func_02162C84 0x02162C84 thumb ov010
 *   func_02162D90 0x02162D90 thumb ov010
 *   func_0201416C  0x0201416C  thumb
 *   func_02162B68  0x02162B68  thumb  ov010
 *   func_02162BCC  0x02162BCC  thumb  ov010
 */
#include "../../matched/include/Obj04155.h"
#include "../../matched/include/Obj17714.h"
#include "../../matched/include/Obj18957.h"
#include "../../matched/include/Obj12335.h"
#include "../../matched/include/Obj01639.h"
#include "../../matched/include/Obj12337.h"
#include "../../matched/include/Obj02059.h"
#include "../../matched/include/Obj18958.h"
#include "../../matched/include/Obj12338.h"
#include "../../matched/include/Obj07293.h"
#include "../../matched/include/Obj07294.h"
#include "../../matched/include/Obj00193.h"
#include "../../matched/include/Obj07295.h"
#include "../../matched/include/Obj17715.h"
#include "../../matched/include/Obj17716.h"

struct R;
struct ArcFile;
struct Box;
struct Q;
struct Out;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short   s16_02162450;

typedef struct {
    u16 a;
    u16 b;
    u8 rest[0x10];
} Rec14;

typedef struct {
    u8 n[4];
    u8 data[1];
} H;

typedef struct {
    int pad0;
    struct ArcFile *f4;
    u8 pad8[0xA];
    u16 c12;
    u16 c14;
    u16 c16;
    u16 c18;
    u16 pad1A;
    char *p1C;
    char *p20;
    char *p24;
    char *p28;
    u16 c2C;
    u16 c2E;
    u16 c30;
    u16 c32;
    u8 pad34[0x120 - 0x34];
    char *p120;
    int size;
    H hdr;
} O;

typedef struct { u16 h0; u16 h2; } R;

typedef short s16_021625FC;

typedef struct { u16 a, b; s16_021625FC c; u16 d; } B;

typedef struct { int x, y, z; } A;

typedef signed short   s16_021626E8;

struct Ent {
    u16 pad0[3];
    u16 f6;
    u16 f8;
    u16 fa;
    u16 fc;
    u16 pad[3];
};

struct Ctx {
    u16 pad0[11];
    u16 f16;
    u16 pad18[6];
    struct Ent *f24;
};

typedef signed short   s16_02162740;

extern int func_0215E2B8(struct R *r, int a, int b, int n);
extern int func_02162F0C(char *, int *);
extern unsigned func_02013ECC(unsigned);
extern unsigned func_020493D4(struct ArcFile *, unsigned);
extern void func_0204944C(struct ArcFile *, unsigned, unsigned, unsigned, void *);
extern void func_02082BCC(void *, int, int);
extern int func_02162D2C(const struct Box *b, const int *pos);
extern int func_02162E00(struct Box *, struct Q *);
extern void func_020140F8(int p0);
extern void func_02014110(int *, u16, s16_021625FC, u16, int, unsigned, unsigned, unsigned);
extern void func_02014134(int *, u16, s16_021625FC, u16, int, u16, u16, s16_021625FC);
extern void func_02162C84(struct Box *b, int q, int *out);
extern void func_02162D90(const struct Box *b, int q, struct Out *o);
extern int func_0201416C(int a0, int a1, int a2, int a3);
u16 func_02162B68(struct Box *b, int *pos);
extern u16 func_02162BCC(struct Box *b, struct Q *q);
void func_02162438(int a0, int a1, int a2);
u32 func_02162450(void *p);
u32 func_02162458(u8 *p);
void func_0216245C(u8 *o, u16 idx);
int func_02162478(char *p, int *v);
void func_021624B0(O *o, int x);
void func_02162530(char *p);
u32 func_0216255C(u32 a);
u16 func_02162560(u8 *p);
int func_02162564(char *p, struct Q *q);
int func_02162598(char *p, struct Q *q);
void *func_021625CC(char *p, unsigned i);
int func_021625E8(R *p);
int func_021625FC(const u8 *q, int *out, int id, int k);
int func_02162694(int a0, int a1, int a2);
u16 func_021626A8(void *b, void *pos);
u16 func_021626B0(void *b, void *q);
int func_021626B8(char *a0, int a1);
u8 func_021626E8(u8 *p);
int func_021626EC(u16 *p);
void func_02162708(struct Ctx *c, u32 idx, u16 a, u32 b, u16 e);
u32 func_02162740(u8 *p);


void func_02162438(int a0, int a1, int a2)
{
    int a3;
    int t4;
    int t5;

t4 = a0 + 0;
t5 = a1 + 0;
a3 = a2 + 0;
a1 = *(int *)&((struct Obj04155 *)t4)->f8;
a0 = a0 + 0x38;
a2 = t5 + 0;
    a0 = func_0215E2B8((struct R *)a0, a1, a2, a3);
loc_0216244A:
a0 = 1;
*(int *)&((struct Obj04155 *)t4)->f34 = a0;
    return;}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02162450.c \
 *       --func func_02162450 --addr 0x02162450 --region ov010 --cc dsi/1.1p1 --thumb
 */
u32 func_02162450(void *p) { return ((struct Obj17714 *)p)->f120; }


/*
 * Unlabelled thumb leaf (ldr r0,[r0,#0x34]; bx lr), the sole blocker of
 * ov021 func_021892CC (lane S26).
 * Addresses are Black-image addresses.
 */
u32 func_02162458(u8 *p)
{
    return ((struct Obj18957 *)p)->f34;
}


/*
 * Unlabelled leaf: when idx is below the halfword count at +0x16, marks the
 * first two halfwords of the 0x14-byte record idx in the table at +0x24 as
 * 0xFFFF.
 *
 * Addresses are Black-image addresses.
 */
void func_0216245C(u8 *o, u16 idx)
{
    Rec14 *t = *(Rec14 * *)&((struct Obj12335 *)o)->f24;

    if (((struct Obj12335 *)o)->f16 > idx) {
        t[idx].a = 0xFFFF;
        t[idx].b = 0xFFFF;
    }
}

int func_02162478(char *p, int *v) { char *r=*(char * *)&((struct Obj12337 *)p)->f28; u16 n,i; if(r) { n=((struct Obj12337 *)p)->f18; for(i=0;i<n;i++,r+=22) { if(func_02162F0C(r,v) && ((struct Obj01639 *)r)->f6==6) return 1; } } return 0; }



/*
 * pass 5 2026-10-06 P5L08: EXACT* (126 B code plus 2 B pad), also EXACT* under -lang c. The file is read
 * into o->size, then the header is parsed: o->p120 is the end of the data, and four sections follow the
 * four count bytes. Each section is its own block with a u8 count local, written in one uniform shape:
 * store the count, store the table pointer d + off, then add count * record size to off. The first
 * pointer is d + 0 (folded), the last section has no step. With this shape the zero offset, the 0x14
 * constant (r7) and h/d (r3/r2) get the original's colours; the earlier straight-line forms (one n local
 * per count, steps before the pointer stores, enum offset local) stayed at 54/126 or 102/128 in passes
 * 1 to 4.
 */
void func_021624B0(O *o, int x)
{
    int a;
    unsigned r;
    unsigned d;
    unsigned off;
    const H *h;

    a = func_02013ECC(x);
    r = func_020493D4(o->f4, a);
    func_0204944C(o->f4, a, 0, r, &o->size);
    off = 0;
    h = &o->hdr;
    d = (unsigned)h + 4;
    o->p120 = (char *)h + o->size;
    {
        u8 n = h->n[0];
        o->c12 = n;
        o->p1C = (char *)(d + off);
        off += n * 0x14;
    }
    {
        u8 n = h->n[1];
        o->c14 = n;
        o->p20 = (char *)(d + off);
        off += n * 0x24;
    }
    {
        u8 n = h->n[2];
        o->c16 = n;
        o->p24 = (char *)(d + off);
        off += n * 0x14;
    }
    {
        u8 n = h->n[3];
        o->c18 = n;
        o->p28 = (char *)(d + off);
    }
    o->c2C = o->c12;
    o->c2E = o->c14;
    o->c30 = o->c16;
    o->c32 = o->c18;
}

void func_02162530(char *p) { ((struct Obj02059 *)p)->f2C=0; ((struct Obj02059 *)p)->f2E=0; ((struct Obj02059 *)p)->f30=0; ((struct Obj02059 *)p)->f32=0; ((struct Obj02059 *)p)->f12=0; ((struct Obj02059 *)p)->f14=0; ((struct Obj02059 *)p)->f16=0; ((struct Obj02059 *)p)->f18=0; ((struct Obj02059 *)p)->f1C=0; ((struct Obj02059 *)p)->f20=0; ((struct Obj02059 *)p)->f24=0; ((struct Obj02059 *)p)->f28=0; func_02082BCC(p+0x128,0,0x880); }


/*
 * Addresses are Black-image addresses.
 */
u32 func_0216255C(u32 a)
{
    return a + 0x38;
}


/*
 * Unlabelled leaf getter: the halfword at +0x16.  Blocker of ov061
 * func_021F388C.
 */
u16 func_02162560(u8 *p)
{
    return ((struct Obj18958 *)p)->f16;
}

/*
 * note: same shape as func_02162598 with the callee func_02162D2C.
 */
int func_02162564(char *p, struct Q *q) { int i; char *r; i=0; r=*(char * *)&((struct Obj12338 *)p)->f24; for(;i<((struct Obj12338 *)p)->f16;i++,r+=20) { if(func_02162D2C((struct Box *)r,(const int *)q)) return i; } return 0xffff; }

int func_02162598(char *p, struct Q *q) { int i; char *r; i=0; r=*(char * *)&((struct Obj12338 *)p)->f24; for(;i<((struct Obj12338 *)p)->f16;i++,r+=20) { if(func_02162E00((struct Box *)r,q)) return i; } return 0xffff; }

void *func_021625CC(char *p, unsigned i) { char *r=*(char * *)&((struct Obj07293 *)p)->f24; if(!r) return 0; if(i>=((struct Obj07293 *)p)->f16) return 0; return r+i*20; }


/*
 * Unlabelled leaf, callee of ov020 func_02185360.
 */
int func_021625E8(R *p)
{
    if (p->h2 == 0x100) {
        return 1;
    }
    return 0;
}

/*
 * extent: 150-byte function followed by two alignment bytes at 02162692.
 * lever: read-only const source parameter schedules the final signed-id
 * truncation after the argument loads; exact callee widths keep B on r1.
 * interface: callee argument id is s16 as caller's explicit asrs shows;
 * k stays full-width because the original forwards it without truncation.
 */
int func_021625FC(const u8 *q, int *out, int id, int k)
{
    u8 *r;
    A s;
    B t;
    r = func_021625CC((char *)q, id);
    if (r == 0) return 0;
    func_020140F8((int)out);
    if (((struct Obj07294 *)r)->f2 == 0x100) *out = 3;
    else *out = 2;
    if (((struct Obj07294 *)r)->f6 == 0) {
        func_02162C84((struct Box *)r, k, (int *)(&s));
        func_02014110(out, ((struct Obj07293 *)q)->f10, id, r[4], k, s.x, s.y, s.z);
    } else {
        func_02162D90((const struct Box *)r, k, (struct Out *)(&t));
        func_02014134(out, ((struct Obj07293 *)q)->f10, id, r[4], k, t.a, t.d, t.c);
    }
    return 1;
}


int func_02162694(int a0, int a1, int a2)
{
    int a3;
    int t4;

t4 = a0 + 0;
a3 = a2 + 0;
a0 = a1 + 0;
a1 = *(u16 *)&((struct Obj00193 *)((char *)t4))->f0;
a2 = *(u16 *)((char *)t4 + 2);
    a0 = func_0201416C(a0, a1, a2, a3);
loc_021626A4:
    return a0;}


/*
 * Unlabelled leaf, blocker of ov021 func_0218AD80: compiler tail call (ldr r3,=; bx r3) of
 * func_02162B68; not a linker veneer.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u16 func_021626A8(void *b, void *pos)
{
    return func_02162B68(b, pos);
}


/*
 * Unlabelled tail-call wrapper over func_02162BCC (a pool word plus bx r3,
 * no prologue); witness for ov021 func_0218B2E8.
 */
u16 func_021626B0(void *b, void *q)
{
    return func_02162BCC(b, q);
}


/*
 * Recursive MATCH unblocker: ABS32 target of func_0218AECC (ov021) +0004.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 */
int func_021626B8(char *a0, int a1)
{
    if ((a1 == 0 && ((struct Obj07295 *)a0)->f4 == 2) ||
        (a1 == 1 && ((struct Obj07295 *)a0)->f4 == 1) ||
        (a1 == 2 && ((struct Obj07295 *)a0)->f4 == 4) ||
        (a1 == 3 && ((struct Obj07295 *)a0)->f4 == 3))
        return 1;
    return 0;
}



/*
 * Reads the byte field at +0x5.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021626E8(u8 *p)
{
    return ((struct Obj17715 *)p)->f5;
}


/*
 * Unlabelled leaf (a .word run in the ov010 listing): true when either of
 * the first two halfwords is 0xFFFF.  Callee of ov021 func_0218B0CC.
 * Addresses are Black-image addresses.
 */
int func_021626EC(u16 *p)
{
    if (p[0] == 0xFFFF || p[1] == 0xFFFF)
        return 1;
    return 0;
}


void func_02162708(struct Ctx *c, u32 idx, u16 a, u32 b, u16 e)
{
    struct Ent *p;
    if (c->f16 >= idx && c->f24 != 0) {
        p = &c->f24[idx];
        if (p->f6 == 0) {
            u16 *q;
            u16 t = (a << 4) + 8;
            q = (u16 *)p + 4;
            p->f8 = t;
            q[1] = b << 4;
            q[2] = (e << 4) + 8;
        }
    }
}



/*
 * Reads the word field at +0x20.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02162740(u8 *p)
{
    return ((struct Obj17716 *)p)->f20;
}
