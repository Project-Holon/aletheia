/*
 * file:     game_beacon_search_p18.c
 * unit:     yes
 * function: func_02165B2C, func_02165B5C, func_02165C10, func_02165C34, func_02165C48, func_02165C50, func_02165C58, func_02165C5C, func_02165C60
 * address:  0x02165B2C
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
 *   func_02030734 0x02030734 arm
 *   d_021729D4 0x021729D4 data a4
 *   func_02165FB4  0x02165FB4  thumb  ov010
 *   d_02171CA8     0x02171CA8  data
 *   func_02045994  0x02045994  arm
 *   func_0200E3A4  0x0200E3A4  thumb
 */
#include "../../matched/include/Obj18996.h"

struct Strbuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rec_02165B5C {
    u8 f00[3];
    u8 f03 : 7;         /* 0x03 */
    u8 f03_7 : 1;
    u32 f04_0 : 17;     /* 0x04 */
    u32 f04_17 : 10;
    u32 f04_27 : 5;
    u32 f08_0 : 17;     /* 0x08 */
    u32 f08_17 : 5;
    u32 f08_22 : 10;
    u32 f0C_0 : 9;      /* 0x0C */
    u32 f0C_9 : 3;
    u32 f0C_12 : 4;
    u32 f0C_16 : 10;
    u32 f0C_26 : 6;
    u8 pad10[0x30 - 0x10];
    u16 f30;            /* 0x30 kind */
    u8 pad32[0x48 - 0x32];
    u16 f48_0 : 8;      /* 0x48 */
    u16 f48_8 : 8;
} Rec_02165B5C;

typedef int (*RecCheck)(Rec_02165B5C *r);

typedef signed char s8;

typedef short s16;

typedef struct Rec_02165C34 {
    u8 pad00[0x12];
    u16 name[8];        /* 0x12 */
} Rec_02165C34;

typedef struct {
    u32 _pad0;
    u32 _pad1;
    u32 _pad2;
    u32 field : 6;
} S_02165C48;

typedef struct {
    u32 w0;
    u32 lo : 27;
    u32 hi : 5;
} S_02165C50;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 func_02165FB4(u16 kind);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u32 func_0200E3A4(const u8 *bits, int id);
u8 *func_02165B2C(u32 heap);
int func_02165B5C(Rec_02165B5C *r);
int func_02165C10(u8 *p);
void func_02165C34(Rec_02165C34 *r, void *buf);
u32 func_02165C48(S_02165C48 *a0);
u32 func_02165C50(S_02165C50 *a0);
u8 func_02165C58(const u8 *p);
u8 func_02165C5C(const u8 *p);
int func_02165C60(int a0);
extern const char d_021729D4[];
extern const RecCheck d_02171CA8[];

u8 *func_02165B2C(u32 heap) { u8 *p=func_02030734(heap,0xb08,1,d_021729D4,0x1c1); p[0xb04]=0; p[0xb05]=0; return p; }


/*
 * Range check of a packed record: returns 1 (invalid) on the first field
 * out of range, else the verdict of the per-kind checker picked from
 * the table at 0x02171CA8 by func_02165FB4(kind).
 */
int func_02165B5C(Rec_02165B5C *r)
{
    if (r->f30 == 0 || r->f30 >= 0x33)
        return 1;
    if (r->f48_0 >= 6)
        return 1;
    if (r->f0C_9 >= 6)
        return 1;
    if (r->f0C_16 > 999 || r->f0C_26 > 59)
        return 1;
    if (r->f03 > 0x2D && r->f03 != 0x30)
        return 1;
    if (r->f04_17 >= 427 || r->f08_22 >= 427)
        return 1;
    if (r->f04_0 > 99999 || r->f08_0 > 99999)
        return 1;
    if (d_02171CA8[func_02165FB4(r->f30)](r) != 0)
        return 1;
    return 0;
}


int func_02165C10(u8 *p)
{
    switch (((struct Obj18996 *)p)->f30) {
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x32:
        return 1;
    }
    return 0;
}


/*
 * Copy the eight-character name at +0x12 into a string buffer.
 */
void func_02165C34(Rec_02165C34 *r, void *buf)
{
    func_02045994(buf, r->name, 8);
}


/*
 * Recursive MATCH unblocker: callee of func_021BCDC0 (ov216) +0002. Coherent
 * Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes that site
 * attest as `matched`.
 */
u32 func_02165C48(S_02165C48 *a0)
{
    return a0->field;
}


/*
 * Unlabelled Thumb leaf (prints as .word data in ov010.s), the sole blocker
 * of ov011 func_02173368 +00CA: returns the top five bits of the second
 * word of its argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_02165C50(S_02165C50 *a0)
{
    return a0->hi;
}

/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 * tail: next 4B getter 02165C5C, separately owned and filed.
 */
u8 func_02165C58(const u8 *p) { return p[1]; }

/*
 * blocker-leaf: ov216 021BD174 MATCH*; parent ownership cleared; no source/unit/shard; full original getter body read.
 */
u8 func_02165C5C(const u8 *p) { return p[2]; }


int func_02165C60(int a0)
{
    int a1;

a0 = a0 + 0x50;
a1 = 0x1a;
    a0 = func_0200E3A4((const u8 *)a0, a1);
loc_02165C6A:
    if (a0 != 0) goto loc_02165C72;
loc_02165C6E:
a0 = 0xff;
    return a0;
loc_02165C72:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}
