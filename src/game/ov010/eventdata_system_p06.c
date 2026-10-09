/*
 * file:     eventdata_system_p06.c
 * unit:     yes
 * function: func_0216242C, func_02162438, func_02162450, func_02162458, func_0216245C, func_02162478, func_021624B0, func_02162530, func_0216255C, func_02162560, func_02162564, func_02162598, func_021625CC, func_021625E8, func_021625FC, func_02162694, func_021626A8, func_021626B0, func_021626B8, func_021626E8, func_021626EC, func_02162708, func_02162740, func_02162744, func_02162748, func_02162774, func_02162788, func_0216279C, func_021627C8, func_0216282C, func_02162890, func_021628E4, func_02162928, func_02162940, func_02162958, func_02162970, func_02162A54, func_02162A5C, func_02162A64, func_02162A6C, func_02162A74, func_02162AA4, func_02162B68
 * address:  0x0216242C
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
 *   func_020143CC  0x020143CC  thumb
 *   func_02162F74  0x02162F74  thumb  ov010
 *   func_02162FC8  0x02162FC8  thumb  ov010
 *   func_021628E4 0x021628E4 thumb ov010
 *   func_02162E48  0x02162E48  thumb  ov010
 *   func_02162E9C  0x02162E9C  thumb  ov010
 *   func_02164708  0x02164708  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 *   func_02162CE8  0x02162CE8  thumb  ov010
 *   func_02162ECC  0x02162ECC  thumb  ov010
 *   func_02162C54  0x02162C54  thumb  ov010
 */
#include "../../matched/include/Obj17713.h"
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
#include "../../matched/include/Obj17717.h"
#include "../../matched/include/Obj07296.h"
#include "../../matched/include/Obj18964.h"

struct R;
struct ArcFile;
struct Box;
struct Q;
struct Out;
struct Ctx_02162744;
struct Rec_0216242C;
struct Ctx;
struct CellKey;
struct VecFx32;
struct TriggerSet;
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

struct Ctx_0216242C {
    u16 pad0[11];
    u16 f16;
    u16 pad18[6];
    struct Ent *f24;
};

typedef signed short   s16_02162740;

typedef signed short   s16_0216242C;

typedef struct {
    u16 x;
    u16 h;
    u32 w;
} Sub;

typedef struct {
    u8 pad0[0xC];
    u16 a;
    u8 pad1[0xA];
    u32 busy;
    Sub s;
} Rec_0216242C;

typedef struct {
    u8 pad0[0x14];
    u16 n;
    u8 pad1[0xA];
    Rec_0216242C *tbl;
} Own;

struct Rec_0216242C {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 pad[7];
};

struct Ctx_02162744 {
    u16 pad0[12];
    u16 f18;
    u16 pad1a[7];
    struct Rec_0216242C *f28;
};

typedef int s32;

typedef struct Trigger {
    u16 id;             /* 0x00 */
    u16 kind2;          /* 0x02 */
    u16 kind;           /* 0x04 */
    u16 mode;           /* 0x06 */
    s32 data[3];        /* 0x08 */
} Trigger;

typedef struct TriggerSet {
    u8 pad00[0x12];
    u16 count;          /* 0x12 */
    u8 pad14[8];
    Trigger *list;      /* 0x1C */
} TriggerSet;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef struct { u32 e,f,g; } Payload;

typedef struct { u16 a,b,c,d; Payload data; } Rec_02162A74;

typedef struct { u8 pad[18]; u16 n; u8 pad14[8]; Rec_02162A74 *r; } Ctx;

typedef short s16_02162A74;

struct Sub {
    s16_02162A74 f0;
    s16_02162A74 f2;
    s16_02162A74 f4;
    u16 f6;
    u16 f8;
};

struct Box {
    u16 pad0[4];
    struct Sub s;
};

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
void func_02162708(struct Ctx_0216242C *c, u32 idx, u16 a, u32 b, u16 e);
u32 func_02162740(u8 *p);
extern u32 func_020143CC(u32 a, u32 b);
extern int func_02162F74(char *p, int *v);
extern int func_02162FC8(char *p, u16 *v);
struct Rec_0216242C *func_021627C8(struct Ctx_02162744 *c, void *a, int key, int mode);
struct Rec_0216242C *func_0216282C(struct Ctx_02162744 *c, void *a, int *key, int mode);
struct Rec_0216242C *func_02162890(struct Ctx_02162744 *c, void *a, int key);
struct Rec_0216242C *func_021628E4(struct Ctx_02162744 *c, void *a, int key);
u16 func_02162928(void *p, void *q, int key, int mode);
u16 func_02162940(void *p, void *q, int key);
/* * Reads the halfword field at +0x14. * * Addresses are Black-image addresses. */ u16 func_02162744(u8 *p);
/* * Unlabelled leaf: when idx is below the halfword count at +0x14 and the * 0x24-byte record idx in the table at +0x20 has a zero word at +0x18, fills * the record: halfword at +0xC, then a sub-record at +0x1C (halfword, halfword, * word). The last two arguments are stack arguments (word, halfword). * * 2026-10-05 note: the guard reads o->tbl[idx].busy and the body takes * &o->tbl[idx] again. Taking the pointer once before the guard gives the * table load before the 0x24 constant (7 bytes off). * * Addresses are Black-image addresses. */ void func_02162748(Own *o, u32 idx, u16 a, u16 b, u32 w, u16 h);
void func_02162774(char *p, unsigned i, u16 v);
void func_02162788(char *p, unsigned i, u16 v);
u16 func_0216279C(int mode);
extern int func_02162E48(struct Trigger *t, const struct VecFx32 *pos);
extern int func_02162E9C(struct Trigger *t, const struct CellKey *k);
extern u16 func_02164708(u16 id);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void func_02162CE8(const void *p, V3 *out);
extern void func_02162ECC(const char *p, int *out);
u16 func_02162958(void *c, void *a, int key);
/* * Finds the trigger that fires at a place: walks the 0x14-byte entries, * tests position (mode 0) or map cell (mode 1), then filters by entry * kind against the facing/type argument. Answers the entry id or 0xFFFF. * * Levers (2026-09-28 tree_ov010_4): one guarded body (single 0xFFFF * exit), the count held in a u32 local (a u16 local is re-read from its * spill slot before the guard), and case 5 as `type == 2 || type == 3`, * which 1.1p1 folds to a loop-hoisted `(u16)(type + 0xFFFE) <= 1` * (`(u16)(type - 2) <= 1` gives `subs 2` instead). */ u16 func_02162970(TriggerSet *set, void *flags, const void *where, u16 type);
/* * Unlabelled leaf (a .word run in the ov010 listing): forwards all four * arguments to func_02162970. Callee of ov021 func_02189BD0. * * Addresses are Black-image addresses. */ u16 func_02162A54(void *set, void *flags, const void *where, u16 type);
/* * Unlabelled leaf (a .word run in the ov010 listing): forwards all four * arguments to func_02162970. Callee of ov021 func_0218A278. * * Addresses are Black-image addresses. */ u16 func_02162A5C(void *set, void *flags, const void *where, u16 type);
/* * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to * func_02162CE8. Blocker of ov061 func_021F388C. */ void func_02162A64(const void *p, V3 *out);
/* * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to * func_02162ECC. Blocker of ov021 func_021AFDAC. */ void func_02162A6C(int a, int b);
extern int func_02162C54(u8 *p);
void func_0216242C(void *a0, u16 a1, u8 a2);
void func_02162438(int a0, int a1, int a2);
/* * generated: lane O24 (ov010 leaf/wrapper sweep) * * Shifted-index word-field getter: the field table sits at a byte offset built from a small constant shifted left, so the leaf folds it to one immediate. * * Addresses are Black-image addresses. --region ov010 is required: this * address is only ov010 in the overlay that defines it. * * Verified with: * python tools/match.py one --src src/matched/func_02162450.c \ * --func func_02162450 --addr 0x02162450 --region ov010 --cc dsi/1.1p1 --thumb */ u32 func_02162450(void *p);
/* * Unlabelled thumb leaf (ldr r0,[r0,0x34]; bx lr), the sole blocker of * ov021 func_021892CC (lane S26). * Addresses are Black-image addresses. */ u32 func_02162458(u8 *p);
/* * Unlabelled leaf: when idx is below the halfword count at +0x16, marks the * first two halfwords of the 0x14-byte record idx in the table at +0x24 as * 0xFFFF. * * Addresses are Black-image addresses. */ void func_0216245C(u8 *o, u16 idx);
int func_02162478(char *p, int *v);
/* * pass 5 2026-10-06 P5L08: EXACT* (126 B code plus 2 B pad), also EXACT* under -lang c. The file is read * into o->size, then the header is parsed: o->p120 is the end of the data, and four sections follow the * four count bytes. Each section is its own block with a u8 count local, written in one uniform shape: * store the count, store the table pointer d + off, then add count * record size to off. The first * pointer is d + 0 (folded), the last section has no step. With this shape the zero offset, the 0x14 * constant (r7) and h/d (r3/r2) get the original's colours; the earlier straight-line forms (one n local * per count, steps before the pointer stores, enum offset local) stayed at 54/126 or 102/128 in passes * 1 to 4. */ void func_021624B0(O *o, int x);
void func_02162530(char *p);
/* * Addresses are Black-image addresses. */ u32 func_0216255C(u32 a);
/* * Unlabelled leaf getter: the halfword at +0x16. Blocker of ov061 * func_021F388C. */ u16 func_02162560(u8 *p);
/* * note 2026-10-05: the old draft (DIFF45) wrote the tail as a do/while(0) with a goto. * The branch-to-branch stubs are the tail `a = hw + (a - h)` written out in each arm * (cross-jumped later). `long w = n` keeps the final `a >= n` reload from the stack slot; * `hw` is unsigned (lsrs). EXACT* = 2 byte trailing pad (194 of 196 listing extent). */ u16 func_02162AA4(int v, int m, int flag, int dir, u16 n);





/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_021624B0, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216242C.c \
 *       --func func_0216242C --addr 0x0216242C --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216242C(void *a0, u16 a1, u8 a2)
{
    ((struct Obj17713 *)a0)->f10 = a1;
    func_021624B0(a0, a1);
}






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
 * Unlabelled thumb leaf (ldr r0,[r0,0x34]; bx lr), the sole blocker of
 * ov021 func_021892CC (lane S26).
 * Addresses are Black-image addresses.
 */
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
 * interface: callee argument id is s16_0216242C as caller's explicit asrs shows;
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


void func_02162708(struct Ctx_0216242C *c, u32 idx, u16 a, u32 b, u16 e)
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




/*
 * Reads the halfword field at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162744(u8 *p)
{
    return ((struct Obj17717 *)p)->f14;
}



/*
 * Unlabelled leaf: when idx is below the halfword count at +0x14 and the
 * 0x24-byte record idx in the table at +0x20 has a zero word at +0x18, fills
 * the record: halfword at +0xC, then a sub-record at +0x1C (halfword, halfword,
 * word). The last two arguments are stack arguments (word, halfword).
 *
 * 2026-10-05 note: the guard reads o->tbl[idx].busy and the body takes
 * &o->tbl[idx] again. Taking the pointer once before the guard gives the
 * table load before the 0x24 constant (7 bytes off).
 *
 * Addresses are Black-image addresses.
 */
void func_02162748(Own *o, u32 idx, u16 a, u16 b, u32 w, u16 h)
{
    if (idx < o->n) {
        if (o->tbl[idx].busy == 0) {
            Rec_0216242C *r = &o->tbl[idx];
            Sub *s = &r->s;
            r->a = a;
            s->x = b;
            s->w = w;
            s->h = h;
        }
    }
}


void func_02162774(char *p, unsigned i, u16 v) { if(i < ((struct Obj07296 *)p)->f14) *(u16 *)(*(char * *)&((struct Obj07296 *)p)->f20+i*0x24+2)=v; }


void func_02162788(char *p, unsigned i, u16 v) { if(i < ((struct Obj07296 *)p)->f14) *(u16 *)(*(char * *)&((struct Obj07296 *)p)->f20+i*0x24+10)=v; }


u16 func_0216279C(int mode) {
    switch(mode) { case 0: return 1; case 1: return 2; case 2: return 3; case 3: return 4; default: return 0; }
}



struct Rec_0216242C *func_021627C8(struct Ctx_02162744 *c, void *a, int key, int mode)
{
    struct Rec_0216242C *r = c->f28;
    u16 v;
    u16 t;
    u16 i;
    u16 n;
    if (r != 0) {
        t = func_0216279C(mode);
        i = 0;
        n = c->f18;
        for (; i < n; i++, r++) {
            if (func_02162F0C((char *)r, (int *)key) != 0 && r->f6 == t) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}


struct Rec_0216242C *func_0216282C(struct Ctx_02162744 *c, void *a, int *key, int mode)
{
    struct Rec_0216242C *r = c->f28;
    u16 v;
    u16 t;
    u16 i;
    u16 n;
    if (r != 0) {
        t = func_0216279C(mode);
        i = 0;
        n = c->f18;
        for (; i < n; i++, r++) {
            if (func_02162F74((char *)r, key) != 0 && r->f6 == t) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}


struct Rec_0216242C *func_02162890(struct Ctx_02162744 *c, void *a, int key)
{
    struct Rec_0216242C *r = c->f28;
    u16 i;
    u16 n;
    u16 v;
    if (r != 0) {
        n = c->f18;
        for (i = 0; i < n; i++, r++) {
            if (func_02162F0C((char *)r, (int *)key) != 0 && r->f6 == 6) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}


struct Rec_0216242C *func_021628E4(struct Ctx_02162744 *c, void *a, int key)
{
    struct Rec_0216242C *r = c->f28;
    u16 i;
    u16 n;
    u16 v;
    if (r != 0) {
        n = c->f18;
        for (i = 0; i < n; i++, r++) {
            if (func_02162FC8((char *)r, (u16 *)key) != 0) {
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}

u16 func_02162928(void *p, void *q, int key, int mode) { u16 *r=(u16 *)func_021627C8(p,q,key,mode); if(r) return *r; return 0xffff; }

u16 func_02162940(void *p, void *q, int key) { u16 *r=(u16 *)func_02162890(p,q,key); if(r) return *r; return 0xffff; }


u16 func_02162958(void *c, void *a, int key)
{
    u16 *r = (u16 *)func_021628E4(c, a, key);
    if (r != 0) return *r;
    return 0xffff;
}



/*
 * Finds the trigger that fires at a place: walks the 0x14-byte entries,
 * tests position (mode 0) or map cell (mode 1), then filters by entry
 * kind against the facing/type argument. Answers the entry id or 0xFFFF.
 *
 * Levers (2026-09-28 tree_ov010_4): one guarded body (single 0xFFFF
 * exit), the count held in a u32 local (a u16 local is re-read from its
 * spill slot before the guard), and case 5 as `type == 2 || type == 3`,
 * which 1.1p1 folds to a loop-hoisted `(u16)(type + 0xFFFE) <= 1`
 * (`(u16)(type - 2) <= 1` gives `subs 2` instead).
 */
u16 func_02162970(TriggerSet *set, void *flags, const void *where, u16 type)
{
    Trigger *t;
    u16 i;
    u32 count;

    t = set->list;
    if (t != 0) {
    count = set->count;
    for (i = 0; i < count; i++, t++) {
        if (t->mode == 0) {
            if (!func_02162E48(t, where))
                continue;
        } else {
            if (!func_02162E9C(t, where))
                continue;
        }
        if (t->kind2 == 2) {
            if (func_020142E8(flags, func_02164708(t->id)) == 0)
                return t->id;
            continue;
        }
        switch (t->kind) {
        case 0:
            if (type == 0)
                return t->id;
            break;
        case 1:
            if (type == 3)
                return t->id;
            break;
        case 2:
            if (type == 2)
                return t->id;
            break;
        case 3:
            if (type == 1)
                return t->id;
            break;
        case 4:
            return t->id;
        case 5:
            if (type == 2 || type == 3)
                return t->id;
            break;
        case 6:
            if (type <= 1)
                return t->id;
            break;
        }
    }
    }
    return 0xFFFF;
}



/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to func_02162970.  Callee of ov021 func_02189BD0.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162A54(void *set, void *flags, const void *where, u16 type)
{
    return func_02162970(set, flags, where, type);
}



/*
 * Unlabelled leaf (a .word run in the ov010 listing): forwards all four
 * arguments to func_02162970.  Callee of ov021 func_0218A278.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162A5C(void *set, void *flags, const void *where, u16 type)
{
    return func_02162970(set, flags, where, type);
}



/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162CE8.  Blocker of ov061 func_021F388C.
 */
void func_02162A64(const void *p, V3 *out)
{
    func_02162CE8(p, out);
}



/*
 * Unlabelled leaf (tail-call thunk, a .word run in the ov010 listing) to
 * func_02162ECC.  Blocker of ov021 func_021AFDAC.
 */
void func_02162A6C(int a, int b)
{
    func_02162ECC((const char *)a, (int *)b);
}


static inline void set(Rec_02162A74 *r, u32 a, u32 b, u16 d)
{
    Payload *p = &r->data;
    ((struct Obj18964 *)r)->f8 = a;
    p->f = d;
    p->g = b << 4;
}


/*
 * extent: 46 code bytes followed by two zero alignment bytes.
 * lever: inline setter takes the whole Rec_02162A74 and all three payload inputs;
 * its own Payload pointer preserves the parent base and explicit +8 copy.
 * domain: unsigned index comparison and modular word address arithmetic.
 */
void func_02162A74(const Ctx *c, u32 i, u32 a, u32 b, u16 d)
{
    Rec_02162A74 *r;
    if (c->n >= i && c->r != 0) {
        r = (Rec_02162A74 *)((u32)c->r + i * 20u);
        if (r->d == 0) {
            set(r, a, b, d);
        }
    }
}



/*
 * note 2026-10-05: the old draft (DIFF45) wrote the tail as a do/while(0) with a goto.
 * The branch-to-branch stubs are the tail `a = hw + (a - h)` written out in each arm
 * (cross-jumped later). `long w = n` keeps the final `a >= n` reload from the stack slot;
 * `hw` is unsigned (lsrs). EXACT* = 2 byte trailing pad (194 of 196 listing extent).
 */
u16 func_02162AA4(int v, int m, int flag, int dir, u16 n)
{
    int b, a, c;
    unsigned h, hw;
    int d;
    long w;
    if (v == 0)
        return 0;
    b = (v & 0xf0) >> 4;
    a = v & 0xf;
    c = (v & 0xf00) >> 8;
    if ((c == 0 && m == 3) || (c == 1 && m == 2) || (c == 3 && m == 0) || (c == 2 && m == 1))
        a = (b - 1) - a;
    if (flag != 0) {
        switch (dir) {
        case 0:
            if ((unsigned)(c - 2) <= 1)
                a = (b - 1) - a;
            break;
        case 1:
            if ((unsigned)c <= 1)
                a = (b - 1) - a;
            break;
        case 2:
            a = (b - 1) - a;
            break;
        }
    }
    w = n;
    h = (unsigned)b / 2;
    d = w - b;
    hw = (unsigned)w / 2;
    if (d != 0) {
        if (d % 2 != 0) {
            if (w % 2 != 0) {
                if (a < h) {
                    h = h - 1;
                    a = hw + (a - h);
                } else {
                    a = hw + (a - h);
                }
            } else {
                if (a <= h) {
                    a = (hw - 1) + (a - h);
                    goto clamp;
                } else {
                    a = hw + (a - h);
                }
            }
        } else {
            a = hw + (a - h);
        }
    }
clamp:
    if (a < 0)
        a = 0;
    else if (a >= n)
        a = w - 1;
    return a;
}



u16 func_02162B68(struct Box *b, int *pos)
{
    struct Sub *s;
    int m = func_02162C54((u8 *)b);
    s = &b->s;
    if (s->f6 > 1)
        return (s->f6 << 4) | (((pos[0] >> 12) - s->f0) / 16) | (m << 8);
    if (s->f8 > 1)
        return (s->f8 << 4) | (((pos[2] >> 12) - s->f4) / 16) | (m << 8);
    return (m << 8) | 0x10;
}
