/*
 * file:     game_beacon_search_p23.c
 * unit:     yes
 * function: func_02165DAC, func_02165DBC, func_02165DF0, func_02165E24, func_02165E34, func_02165E78, func_02165E8C, func_02165E9C, func_02165EAC, func_02165EBC, func_02165ECC, func_02165F30, func_02165F64, func_02165F74, func_02165F84, func_02165F94, func_02165FA4, func_02165FB4
 * address:  0x02165DAC
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
 *   func_0204581C  0x0204581C  arm
 *   func_02045994  0x02045994  arm
 *   d_02171CE8  0x02171CE8  data  a1
 */
#include "../../matched/include/Obj19003.h"
#include "../../matched/include/Obj07306.h"
#include "../../matched/include/Obj17726.h"

struct Strbuf;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

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

extern void func_0204581C(struct U16Vec *vec);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
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

/*
 * Parent-cleared leaf for ov216 021BCE04. ov010 coherent Thumb accessor;
 * overlapping ov009 address is interior ARM code, as explicit shows prove.
 */
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
