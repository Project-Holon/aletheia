/*
 * file:     game_beacon_search_p04.c
 * unit:     yes
 * function: func_02165C78, func_02165C90, func_02165CB4, func_02165CC0, func_02165CD8, func_02165CE4, func_02165CE8, func_02165D08, func_02165D10, func_02165D20, func_02165D28, func_02165D34, func_02165D40, func_02165D48, func_02165D50, func_02165D6C, func_02165D8C, func_02165DAC, func_02165DBC, func_02165DF0, func_02165E24, func_02165E34, func_02165E78, func_02165E8C, func_02165E9C, func_02165EAC, func_02165EBC, func_02165ECC, func_02165F30, func_02165F64, func_02165F74, func_02165F84, func_02165F94, func_02165FA4, func_02165FB4
 * address:  0x02165C78
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
 *   func_0200E3A4  0x0200E3A4  thumb
 *   func_02087D1C  0x02087D1C  arm
 *   func_0204581C  0x0204581C  arm
 *   func_02045994  0x02045994  arm
 *   func_02045924  0x02045924  arm
 *   d_02171CE8  0x02171CE8  data  a1
 */
#include "../../matched/include/Obj17722.h"
#include "../../matched/include/Obj17723.h"
#include "../../matched/include/Obj19000.h"
#include "../../matched/include/Obj17724.h"
#include "../../matched/include/Obj17725.h"
#include "../../matched/include/Obj19003.h"
#include "../../matched/include/Obj07306.h"
#include "../../matched/include/Obj17726.h"

struct Rec;
struct Strbuf;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Packed {u16 low:8,a:3,b:5;};

struct R {u8 pad[0x48];struct Packed fields;u16 c,d;};

struct Quad {u16 a,b,c,d;};

typedef struct {
    u32 w0;
    u32 w4;
    u32 w8;
    u32 lo : 9;
    u32 f : 3;
    u32 hi : 20;
} S_02165CB4;

struct S_02165CD8 {
    u8 pad0[12];
    u32 : 12;
    u32 f : 4;
};

struct S_02165CE8 {
    u8 pad0[3];
    u8 : 7;
    u8 f3 : 1;
    u8 pad4[8];
    u32 : 6;
    u32 f : 3;
};

typedef signed char s8;

typedef short s16;

typedef struct Rec {
    u8 pad00[3];
    u8 lo : 7;
    u8 hi : 1;
} Rec;

struct S {u32 a,b,c;u32 low:16;u32 first:10;u32 second:6;};

struct Bits_02165D28 { unsigned a; unsigned low:17; unsigned value:10; unsigned high:5; };

struct Bits_02165D34 { unsigned a, b; unsigned low:22; unsigned value:10; };

struct S_02165D40 {u32 a,b;u32 value:17;u32 rest:15;};

struct S_02165D48 {u32 a;u32 value:17;u32 rest:15;};

typedef struct Rec_02165E34 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165E34;

typedef struct Rec_02165E78 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165E78;

typedef struct Rec_02165E8C {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165E8C;

typedef struct Rec_02165E9C {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165E9C;

typedef struct Rec_02165EAC {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165EAC;

typedef struct Rec_02165EBC {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165EBC;

typedef struct Rec_02165ECC {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u8 pad32[2];
    u16 text[11];       /* 0x34 */
} Rec_02165ECC;

typedef struct Rec_02165F30 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    u16 f34;            /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F30;

typedef struct Rec_02165F64 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F64;

typedef struct Rec_02165F74 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F74;

typedef struct Rec_02165F84 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F84;

typedef struct Rec_02165F94 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165F94;

typedef struct Rec_02165FA4 {
    u8 pad00[0x30];
    u16 type;           /* 0x30 */
    u16 f32;            /* 0x32 */
    union {
        u8 b;
        u16 h;
        u32 w;
    } f34;              /* 0x34 */
    u16 f36;            /* 0x36 */
    u16 f38;            /* 0x38 */
} Rec_02165FA4;

typedef struct Row {
    u8 a;
    u8 b;
} Row;

extern u32 func_0200E3A4(const u8 *bits, int id);
extern char *func_02087D1C(void);
void func_02165C90(const struct R *p,struct Quad *q);
u8 func_02165CB4(S_02165CB4 *a0);
void func_02165CC0(int a0, int a1);
u8 func_02165CD8(struct S_02165CD8 *p);
u16 func_02165CE4(u8 *r);
u8 func_02165CE8(struct S_02165CE8 *p);
u8 func_02165D08(Rec *r);
void func_02165D10(const struct S *p,u16 *a,u16 *b);
u8 func_02165D20(Rec *r);
unsigned short func_02165D28(const struct Bits_02165D28 *p);
unsigned short func_02165D34(const struct Bits_02165D34 *p);
u32 func_02165D40(const struct S_02165D40 *p);
u32 func_02165D48(const struct S_02165D48 *p);
extern int func_0204581C(struct U16Vec *);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern int func_02045924();
int func_02165C78(int a0);
int func_02165D6C(int a0, int a1);
int func_02165D8C(int a0, int a1);
unsigned func_02165DAC(const char *p);
unsigned short func_02165DBC(const char *p);
unsigned short func_02165DF0(const char *p);
int func_02165E24(int a0);
u16 func_02165E34(Rec_02165E34 *r);
u16 func_02165E78(Rec_02165E78 *r);
u16 func_02165E8C(Rec_02165E8C *r);
u16 func_02165E9C(Rec_02165E9C *r);
u16 func_02165EAC(Rec_02165EAC *r);
u16 func_02165EBC(Rec_02165EBC *r);
void func_02165ECC(Rec_02165ECC *r, void *buf);
u16 func_02165F30(Rec_02165F30 *r);
u32 func_02165F64(Rec_02165F64 *r);
u16 func_02165F74(Rec_02165F74 *r);
u32 func_02165F84(Rec_02165F84 *r);
u8 func_02165F94(Rec_02165F94 *r);
u16 func_02165FA4(Rec_02165FA4 *r);
u8 func_02165FB4(u16 type);
extern const Row d_02171CE8[];






int func_02165C78(int a0)
{
    int a1;

a0 = a0 + 0x50;
a1 = 0x19;
    a0 = func_0200E3A4((const u8 *)a0, a1);
loc_02165C82:
    if (a0 != 0) goto loc_02165C8A;
loc_02165C86:
a0 = 0xff;
    return a0;
loc_02165C8A:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}





/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: 2B zero padding 02165CB2.
 */
void func_02165C90(const struct R *p,struct Quad *q)
{
    q->a=p->fields.a;
    q->b=p->fields.b;
    q->c=p->c;
    q->d=p->d;
}


/*
 * Unlabelled Thumb leaf (prints as .word data in ov010.s), the sole blocker
 * of ov032 func_021F10D8 +000A: returns the three-bit field at bit 9 of the
 * fourth word of its argument.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02165CB4(S_02165CB4 *a0)
{
    return a0->f;
}


/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x02087D1C now has an
 * EXACT arm9 shard entry (pkt_02087D1C), so the call resolves via `matched`.
 * Verified EXACT* (listing 144 vs compiled 24 is the multi-function extent;
 * the function's own bytes are exact).
 *
 * 2026-10-02: func_02087D1C returns a pointer, but it stays declared
 * `extern int func_02087D1C();` here.  A declaration-only fix (a pointer
 * return and a char * receiving local) does not keep the bytes: the
 * compiler moves the shift chain that builds t5.  A variant that folds the
 * shift chain into one expression,
 * `t5 = (unsigned)(*(int *)((char *)a1 + 0xc) << 0x10) >> 0x1c;`, with
 * `char *p = func_02087D1C();`, does match (EXACT, the same verdict as
 * this file against the current listings).  It changes code and not just
 * types, so it is kept outside the tree pending a decision:
 * docs/notes/func_02165CC0_variantF.c.txt.
 */
void func_02165CC0(int a0, int a1)
{
    int t4;
    int t5;

t4 = a0 + 0;
a0 = ((struct Obj17722 *)a1)->fC;
a0 = a0 << 0x10;
t5 = (unsigned)a0 >> 0x1c;
    a0 = (int)func_02087D1C();
loc_02165CCE:
a1 = t5 << 0x1c;
a1 = (unsigned)a1 >> 0x1b;
a0 = *(u16 *)((char *)a0 + a1);
((struct Obj17723 *)((char *)t4))->f0 = a0;
    return;}


/*
 * Unlabelled leaf, filed as the only overlay blocker of ov029 func_021F1CD8.
 */
u8 func_02165CD8(struct S_02165CD8 *p)
{
    return p->f;
}


/*
 * Unlabelled leaf, filed as a blocker of ov032 func_021F1144.
 */
u16 func_02165CE4(u8 *r)
{
    return ((struct Obj19000 *)r)->f10;
}


/*
 * Unlabelled leaf, filed as the only blocker of ov032 func_021F0F74.
 */
u8 func_02165CE8(struct S_02165CE8 *p)
{
    if (p->f3 == 0) {
        return p->f;
    }
    return p->f + 8;
}


/*
 * Top bit of byte 3.
 */
u8 func_02165D08(Rec *r)
{
    return r->hi;
}


/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: 2B zero padding 02165D1E.
 */
void func_02165D10(const struct S *p,u16 *a,u16 *b)
{
    *a=p->first;
    *b=p->second;
}


/*
 * Low seven bits of byte 3 (unlabelled leaf; sibling of func_02165D08).
 */
u8 func_02165D20(Rec *r)
{
    return r->lo;
}

/*
 * Parent-cleared leaf for ov216 021BCE04. ov010 coherent Thumb accessor;
 * overlapping ov009 address is interior ARM code, as explicit shows prove.
 */
unsigned short func_02165D28(const struct Bits_02165D28 *p) { return p->value; }

/*
 * Parent-cleared leaf for ov216021BD448 after same-region source/unit/shard
 * and SDK union checks. Coherent ov010 Thumb accessor; ov009 is interior ARM.
 */
unsigned short func_02165D34(const struct Bits_02165D34 *p) { return p->value; }


/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: next 8B getter 02165D48, separately owned and filed.
 */
u32 func_02165D40(const struct S_02165D40 *p) { return p->value; }

/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 */
u32 func_02165D48(const struct S_02165D48 *p) { return p->value; }


void func_02165D50(struct Rec *r, struct Strbuf *buf)
{
    func_0204581C((struct U16Vec *)buf);
    func_02045994(buf, (const u16 *)((char *)r + 0x20), 9);
}




int func_02165D6C(int a0, int a1)
{
    int a2;

a2 = a0 + 0;
a0 = ((struct Obj17724 *)a2)->f30;
    if (a0 == 0x18) goto loc_02165D7E;
loc_02165D76:
a0 = a1 + 0;
    a0 = func_0204581C((struct U16Vec *)a0);
loc_02165D7C:
    return a0;
loc_02165D7E:
a2 = a2 + 0x34;
a0 = a1 + 0;
a1 = a2 + 0;
    a0 = func_02045924(a0, a1);
loc_02165D88:
    return a0;}




int func_02165D8C(int a0, int a1)
{
    int a2;

a2 = a0 + 0;
a0 = ((struct Obj17725 *)a2)->f30;
    if (a0 == 0x31) goto loc_02165D9E;
loc_02165D96:
a0 = a1 + 0;
    a0 = func_0204581C((struct U16Vec *)a0);
loc_02165D9C:
    return a0;
loc_02165D9E:
a2 = a2 + 0x34;
a0 = a1 + 0;
a1 = a2 + 0;
    a0 = func_02045924(a0, a1);
loc_02165DA8:
    return a0;}



unsigned func_02165DAC(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj19003 *)p)->f48;
    if(a>=6) a=5;
    return a;
}



unsigned short func_02165DBC(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj07306 *)p)->f48;
    unsigned b=*(const unsigned short *)&((struct Obj07306 *)p)->f4E;
    switch(a) { case 2: case 3: case 4:
        if(b==0 || b>=616) b=1;
        return b;
    default: return 1;
    }
}



unsigned short func_02165DF0(const char *p)
{
    unsigned a=(unsigned char)*(const unsigned short *)&((struct Obj07306 *)p)->f48;
    unsigned b=*(const unsigned short *)&((struct Obj07306 *)p)->f4E;
    switch(a) { case 0: case 1:
        if(b==0 || b>649) b=504;
        return b;
    default: return 504;
    }
}






int func_02165E24(int a0)
{

a0 = ((struct Obj17726 *)a0)->f30;
    if (a0 == 0) goto loc_02165E2E;
loc_02165E2A:
    if ((unsigned)a0 < (unsigned)0x33) goto loc_02165E30;
loc_02165E2E:
a0 = 1;
loc_02165E30:
    return a0;}




/*
 * Returns the f32 halfword for the record types that carry one, else 0x1F8.
 */
u16 func_02165E34(Rec_02165E34 *r)
{
    switch (r->type) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 14:
    case 15:
    case 17:
    case 38:
        return r->f32;
    }
    return 0x1F8;
}




/*
 * Returns the f34 halfword of a type 0x13/0x23 record, else 0x11.
 */
u16 func_02165E78(Rec_02165E78 *r)
{
    if (r->type == 0x13 || r->type == 0x23)
        return r->f34.h;
    return 0x11;
}




/*
 * Returns the f34.h payload of a type-0x24 record, else 1.
 */
u16 func_02165E8C(Rec_02165E8C *r)
{
    if (r->type == 0x24)
        return r->f34.h;
    return 1;
}




/*
 * Returns the f34.h payload of a type-0x19 record, else 0x1F8.
 */
u16 func_02165E9C(Rec_02165E9C *r)
{
    if (r->type == 0x19)
        return r->f34.h;
    return 0x1F8;
}




/*
 * Returns the f36 payload of a type-0x1A record, else 0x11.
 */
u16 func_02165EAC(Rec_02165EAC *r)
{
    if (r->type == 0x1A)
        return r->f36;
    return 0x11;
}




/*
 * Returns the f38 payload of a type-0x32 record, else 0.
 */
u16 func_02165EBC(Rec_02165EBC *r)
{
    if (r->type == 0x32)
        return r->f38;
    return 0;
}




/*
 * Clear a string buffer and copy the 11-character text at +0x34 into it;
 * the type switch that follows has no effect left in it.
 *
 * The image dispatches as a two-node switch tree (`cmp #0x26; bgt` to the
 * lone `cmp #0x2f`, then `subs #0x10; bmi` into a 0x10..0x26 table). 1.1p1
 * builds that tree only when the 16..38 cluster holds 10 or 11 case labels
 * (9 or fewer: compare chain; 12 or more: one 0x10..0x2F table). The table
 * holes and the listed cases all reach the same exit, so WHICH ten labels
 * the source had is not recoverable from the bytes; 16..24 and 38 are a
 * stand-in, only the endpoints are pinned (2026-09-28 tree_ov010_4).
 */
void func_02165ECC(Rec_02165ECC *r, void *buf)
{
    func_0204581C(buf);
    func_02045994(buf, r->text, 11);
    switch (r->type) {
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 38:
    case 47:
        return;
    }
}




/*
 * Returns the f34 halfword for record types 6..11, else 1.
 */
u16 func_02165F30(Rec_02165F30 *r)
{
    switch (r->type) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return r->f34;
    }
    return 1;
}




/*
 * Returns the f34.w payload of a type-0x16 record, else 1.
 */
u32 func_02165F64(Rec_02165F64 *r)
{
    if (r->type == 0x16)
        return r->f34.w;
    return 1;
}




/*
 * Returns the f34.h payload of a type-0x14 record, else 1.
 */
u16 func_02165F74(Rec_02165F74 *r)
{
    if (r->type == 0x14)
        return r->f34.h;
    return 1;
}




/*
 * Returns the f34.w payload of a type-0x29 record, else 1.
 */
u32 func_02165F84(Rec_02165F84 *r)
{
    if (r->type == 0x29)
        return r->f34.w;
    return 1;
}




/*
 * Returns the f34.b payload of a type-0x2C record, else 0.
 */
u8 func_02165F94(Rec_02165F94 *r)
{
    if (r->type == 0x2C)
        return r->f34.b;
    return 0;
}




/*
 * Returns the f34.h payload of a type-0x30 record, else 0.
 */
u16 func_02165FA4(Rec_02165FA4 *r)
{
    if (r->type == 0x30)
        return r->f34.h;
    return 0;
}




/*
 * First byte of the two-byte table row for a record type.
 */
u8 func_02165FB4(u16 type)
{
    return d_02171CE8[type].a;
}
