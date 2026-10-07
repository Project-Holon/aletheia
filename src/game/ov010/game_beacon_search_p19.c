/*
 * file:     game_beacon_search_p19.c
 * unit:     yes
 * function: func_02165C78, func_02165C90, func_02165CB4, func_02165CC0, func_02165CD8, func_02165CE4, func_02165CE8, func_02165D08
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
 */
#include "../../matched/include/Obj17722.h"
#include "../../matched/include/Obj17723.h"
#include "../../matched/include/Obj19000.h"

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

extern u32 func_0200E3A4(const u8 *bits, int id);
extern char *func_02087D1C(void);
int func_02165C78(int a0);
void func_02165C90(const struct R *p,struct Quad *q);
u8 func_02165CB4(S_02165CB4 *a0);
void func_02165CC0(int a0, int a1);
u8 func_02165CD8(struct S_02165CD8 *p);
u16 func_02165CE4(u8 *r);
u8 func_02165CE8(struct S_02165CE8 *p);
u8 func_02165D08(Rec *r);


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
