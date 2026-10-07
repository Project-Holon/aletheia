/*
 * file:     mcss_p01.c
 * unit:     yes
 * function: func_02014910, func_0201493C, func_02014A10, func_02014A20, func_02014A80, func_02014B08, func_02014BA8, func_02014C08, func_02014CB8, func_02014CD4
 * address:  0x02014910
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02013F2C  0x02013F2C  thumb
 *   func_02013B38  0x02013B38  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_020140DC  0x020140DC  thumb
 *   func_020140B4  0x020140B4  thumb
 *   sub_020307B0   0x020307B0  arm
 *   sub_0209E054_Map  0x0209E054  data
 *   func_020490A8       0x020490A8  arm
 *   func_02048F60       0x02048F60  arm
 *   _u32_div_f          0x0209C2B0  arm
 *   VEC_Fx16Normalize   0x0207CDB8  arm
 *   func_02011400  0x02011400  thumb
 *   func_02030734     0x02030734  arm
 *   func_020637D4     0x020637D4  arm
 *   func_02049F34     0x02049F34  arm
 *   func_020056A0     0x020056A0  thumb
 *   func_02016880     0x02016880  thumb
 *   sFile_020A72CC    0x020A72CC  data
 *   func_02014CD4   0x02014CD4  thumb
 *   func_02030EE8   0x02030EE8  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_02015BA4   0x02015BA4  thumb
 *   func_020169E8  0x020169E8  thumb
 *   func_02016374  0x02016374  thumb
 *   func_020490F4         0x020490F4  arm
 *   ENV_SetResourceSet_2  0x02049238  arm
 */
#include "../../matched/include/Obj02990.h"
#include "../../matched/include/Obj03429.h"
#include "../../matched/include/Obj11255.h"
#include "../../matched/include/Obj15656.h"
#include "../../matched/include/Obj01459.h"

struct Desc;
struct Obj;
struct Sub020140BCObj;
struct Obj_02016880;
struct Node;
struct Sub02014CB8Obj;
struct S02030EE8;
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned char  u8;

typedef signed short s16;

typedef struct {
    u8  pad00[0xc];
    void *f0c;
    u32 f10;
    u32 f14;
    u8  f18[0x18];
    u32 f30;
    u32 f34;
    u8  pad38[8];
    void *f40;
    u32 f44;
} Obj;

typedef struct {
    u8  f00[4];
    u8  f04[8];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    Obj *f20;
} Sub;

typedef struct B1 { unsigned int b0 : 1; } B1;

struct Sub02014CB8Obj {
    void *f00;
    u32   f04;
    u32   pad08[0xE];
    u32   f40;
};

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02014878(u32 a0, u32 *mode, u32 *p);
extern u32 func_02013F2C(u32 id);
extern u32 func_02013B38(u32 id);
extern void *func_0201407C(u16 heap, u32 a, u32 b);
extern u8 func_020140DC(struct Sub020140BCObj *p);
extern u32 func_020140B4(void *a);
extern u32 sub_020307B0(void *p);
extern u32   func_020490A8(u32 a, u32 b);
extern void *func_02048F60(u32 archive, u32 member, u32 heap);
extern u32   _u32_div_f(u32 a, u32 b);
extern void  VEC_Fx16Normalize(void *dest, const void *src);
extern u8 func_02011400(int row, int col);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020637D4(u32 *p);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_020056A0(void *fn, Sub *s, u32 a);
extern void func_02016880(void *a0, struct Obj_02016880 *a1);
extern void func_02014CD4(struct Sub02014CB8Obj *o);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void  func_02015BA4(void *a0, void *a1);
extern void func_020649D4(char *member, int value);
extern void func_02016374(void *obj);
extern void func_020169E8(u8 *a0, u8 *a1);
extern void *func_020490F4(u32 id, u32 heap);
extern void  ENV_SetResourceSet_2(void *p);
void *func_02014910(char *a0, int a1, int a2, int a3);
void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3, u32 b0, u16 *b1, u16 heap);
u16 func_02014A10(u32 i);
void *func_02014A20(u32 archive, u32 member, u32 *count_out, u32 heap);
void func_02014A80(u8 *a0, u32 a1, s32 a2, u32 a3, u16 *out);
void *func_02014B08(u32 id, void *heap);
void func_02014BA8(u8 *a0);
void func_02014C08(char *self);
extern u32 sub_0209E054_Map[];
extern char  sFile_020A72CC[];


/*
 *           Closed at the bottom, not unfiled: no branch anywhere in the image
 *           reaches 0x02014878, so only a `matched` entry could attest it, and
 *           func_02014878 is itself capped at MATCH by two own-pool words
 *           (0x0000005B at 0x02014900, 0x00000083 at 0x02014908 - each occurs
 *           exactly once in arm9, inside its own compared range).  See
 *           docs/notes/pkt_02014808.c.txt.
 */
void *func_02014910(char *a0, int a1, int a2, int a3)
{
    void *r = func_020122C0(a0, 0, (void *)((int)func_02014878), 0x10);
    u32 *p = func_020124E8(r);

    p[0] = (u32)a0;
    p[1] = a1;
    p[2] = a2;
    p[3] = a3;
    return r;
}

/*
 * The three-way fallback load of the 0x34-byte time-of-day table (member
 * 0x3e for an explicit id, 0x52 for the id func_02013F2C maps, else 0x3d
 * built through func_0201407C), then func_02014A80 over it and a free.
 *
 * Closed in wave 13 by the declaration, not the body: the seventh
 * parameter is a u16 heap id (the ov094 caller at 0x021F7702 loads it
 * with ldrh), written `(heap & 0x7fff) | 0x8000` at each of the four
 * uses.  The earlier note (docs/notes/pkt_0201493C.c.txt) read it as the
 * low half of a word through `*(u16 *)((char *)&b0 + 8)` and had to spell
 * the first tag as 0x10000000; with the real parameter type both of its
 * "back-end tie-breaks" (the pooled 0x0FFFFFFF + 1 tag and the late b0
 * reload) disappear.
 */
void func_0201493C(u32 id, u32 a1, u32 a2, u32 a3,
                   u32 b0, u16 *b1, u16 heap)
{
    u32 count;
    void *p = 0;
    s32 o2;
    s32 o1;

    o1 = a2 * 0x3c;
    o2 = a1 * 0xe10;

    if (a3 != 0) {
        p = func_02014A20(0x3e, func_02014A10(a3), &count, (u16)((heap & 0x7fff) | 0x8000));
    }
    if (p == 0) {
        u32 t = func_02013F2C((u16)id);
        if (t != 0xfffffff)
            p = func_02014A20(0x52, t, &count, (u16)((heap & 0x7fff) | 0x8000));
    }
    if (p == 0) {
        void *q = func_0201407C((heap & 0x7fff) | 0x8000, func_02013B38((u16)id), b0);
        p = func_02014A20(0x3d, func_020140DC(q), &count, (u16)((heap & 0x7fff) | 0x8000));
        func_020140B4((void *)q);
    }
    func_02014A80(p, count, o1 + o2, b0, b1);
    sub_020307B0(p);
}


u16 func_02014A10(u32 i)
{
    return sub_0209E054_Map[i];
}


/*
 * Load a record table out of an archive sub-file: the sub-file's byte size
 * divided by 0x34 is the record count (unsigned divide, `_u32_div_f`), the
 * count is handed back through a3's slot and the block itself is loaded by
 * func_02048F60.  Each 0x34-byte record carries four 6-byte vectors at +0x10
 * (a VecFx16 triple plus a spare halfword) and each is normalized in place
 * before the count is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014A20.c \
 *       --func func_02014A20 --addr 0x02014A20 --cc 1.1p1 --thumb
 */
void *func_02014A20(u32 archive, u32 member, u32 *count_out, u32 heap)
{
    u32 n;
    u32 i;
    u8 *q;
    u8 *p;
    int j;

    n = func_020490A8(archive, member) / 0x34;
    *count_out = n;
    p = func_02048F60(archive, member, heap);
    for (i = 0; i < n; i++) {
        q = p + i * 0x34 + 0x10;
        for (j = 0; j < 4; j++) {
            VEC_Fx16Normalize(q + j * 6, q + j * 6);
        }
    }
    return p;
}


/*
 * Scans the 0x34-byte-stride table at a0 for the element whose 3600*hour +
 * 60*minute value first climbs past a2 while the best so far is still at or
 * below it, then returns that element's eight halfword fields through the
 * caller's buffer (the four at +8 and the four at +0x28).
 *
 * Shape notes:
 *  - the index runs from 0 and the loop is entered only when a1 != 0, so the
 *    counter's first comparison sits at the bottom (`cmp r4, a1 / blo`) and
 *    the guard at the top is a bare `adds r0, r1, #0 / beq`);
 *  - the element's +2 field is signed (`ldrsh` with a register offset,
 *    docs/idioms/ldrsh-register-offset-is-signedness.md), which is why both
 *    comparisons on the running value are `bgt`;
 *  - `i % a1` is one call to the unsigned divmod helper with the remainder
 *    read out of r1, so the source must stay a modulo expression and not a
 *    hand-rolled subtraction loop;
 *  - the two products are two statements (`v = 0xE10 * ...; v += ...;`).
 *    Written as one expression mwcc evaluates the s16 arm first and the
 *    15-byte window at +0x2C comes out in the other order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014A80.c \
 *       --func func_02014A80 --addr 0x02014A80 --cc 1.1p1 --thumb
 */
void func_02014A80(u8 *a0, u32 a1, s32 a2, u32 a3, u16 *out)
{
    u32 i;
    s32 best;
    s32 v;
    u32 k;
    u8 *e;

    best = 0;
    i = 0;
    if (a1 != 0) {
        do {
            e = a0 + i * 0x34;
            v = 0xE10 * (s32)func_02011400(a3, *(u16 *)(a0 + i * 0x34));
            v += ((struct Obj02990 *)e)->f2 * 0x3C;
            if (best <= a2 && v > a2) {
                break;
            }
            best = v;
            i++;
        } while (i < a1);
    }

    k = i % a1;
    e = a0 + k * 0x34;
    out[0] = ((struct Obj02990 *)e)->f8;
    out[1] = ((struct Obj02990 *)e)->fA;
    out[2] = ((struct Obj02990 *)e)->fC;
    out[3] = ((struct Obj02990 *)e)->fE;
    out[4] = ((struct Obj02990 *)e)->f28;
    out[5] = ((struct Obj02990 *)e)->f2A;
    out[6] = ((struct Obj02990 *)e)->f2C;
    out[7] = ((struct Obj02990 *)e)->f2E;
}


void *func_02014B08(u32 id, void *heap)
{
    Obj *o;
    Sub *s;
    u32 m;

    o = func_02030734((u32)heap, 0x4c, 1, sFile_020A72CC, 0x78);
    o->f10 = id;
    o->f40 = heap;
    o->f44 = 0x1000;
    o->f14 = (u32)func_02030734((u32)heap, id * 4, 1, sFile_020A72CC, 0x7f);
    o->f30 = 9 << 14;
    o->f34 = 0x1000;
    func_020637D4((u32 *)o->f18);
    m = ((u32)heap & 0x7fff) | 0x8000;
    s = func_02030734((u32)((void *)(u16)m), 0x2c, 1, sFile_020A72CC, 0x8e);
    s->f20 = o;
    s->f0c = (u32)o->f18;
    s->f1c = 0x1100;
    s->f14 = (u32)func_02049F34(0xb, 0x58, (u32)s->f04, (u16)m);
    o->f0c = func_020056A0((void *)func_02016880, s, 0);
    return o;
}


/*
 * Tear-down of a "list of arrays" record: close the open sub-object at +0xC
 * (three frees through the handle returned by func_02030EE8, then the handle
 * itself), then walk the +0x14 array of +0x10 entries and release each live
 * one through func_02015BA4, finally the array and the record itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02014BA8.c \
 *       --func func_02014BA8 --addr 0x02014BA8 --cc 1.1p1 --thumb
 */
void func_02014BA8(u8 *a0)
{
    int i;

    func_02014CD4((struct Sub02014CB8Obj *)a0);
    if (*(u8 * *)&((struct Obj03429 *)a0)->fC != 0) {
        u8 *p = (u8 *)func_02030EE8((struct S02030EE8 *)(*(u8 * *)&((struct Obj03429 *)a0)->fC));

        func_020307B0(*(u8 * *)&((struct Obj15656 *)(*(u8 * *)&((struct Obj11255 *)p)->f4))->fC);
        func_020307B0(*(u8 * *)&((struct Obj11255 *)p)->f4);
        func_020307B0(p);
        func_02030EAC((struct Node *)(*(u8 * *)&((struct Obj03429 *)a0)->fC));
        *(u8 * *)&((struct Obj03429 *)a0)->fC = 0;
    }
    for (i = 0; i < ((struct Obj03429 *)a0)->f10; i++) {
        u32 *arr = *(u32 * *)&((struct Obj03429 *)a0)->f14;
        u32 e = arr[i];

        if (e != 0) {
            func_02015BA4(a0, (u8 *)e);
        }
    }
    func_020307B0(*(u8 * *)&((struct Obj03429 *)a0)->f14);
    func_020307B0(a0);
}


/*
 * Closed in the second pass (2026-09-22) from the 7-byte near miss in
 * docs/notes/pkt_02014C08.c.txt.  That note, and the two full permuter
 * runs made on it today (tools/permuter.py --mode hill, 171 single
 * mutations; --mode anneal, 2000 compiles) could not move the residue by
 * a single byte, which is the tell the brief names: a residue nothing in
 * the body reaches lives in the DECLARATIONS.
 *
 * THE LEVER IS func_02016374's ARITY.  The original leaves the slot
 * pointer live in r0 through the third bit test:
 *
 *     02014C7C  ldr r0, [r5, #0x14]     ; the slot array
 *     02014C7E  ldr r1, [sp, #4]        ; the offset constant 0x144
 *     02014C80  ldr r0, [r0, r4]        ; the slot -- STAYS in r0
 *     02014C82  ldr r1, [r0, r1]        ; the flag word into r1
 *     ...
 *     02014C8C  bl  #0x2016374          ; called with r0 already set
 *
 * Declared `void func_02016374(void)` the compiler has no reason to keep
 * the slot in r0, puts the flag word there instead and the six
 * instructions at +0x0076..+0x0080 come out with r0 and r1 swapped, the
 * whole 7-byte residue.  Declared `func_02016374(char *w)` and CALLED
 * with the slot, the allocation the image shows is the only legal one and
 * every byte closes.  This confirms the prototype
 * docs/families/mcss.h already carried (`void func_02016374(struct
 * McssWork *w)`), which the note had not applied at the call site.
 *
 * The 0x020169E8 site resolves through sole-ref/code (and, since
 * src/matched/func_020169E8.c was filed in the same pass, through
 * `matched` as well).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02014C08.c \
 *       --func func_02014C08 --addr 0x02014C08 --cc 1.1p1 --thumb
 */
void func_02014C08(char *self)
{
    int i;

    for (i = 0; i < ((struct Obj01459 *)self)->f10; i++) {
        if (*(int *)(((struct Obj01459 *)self)->f14 + i * 4) == 0)
            continue;
        if (((*(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x140) << 0x15) >> 0x1e) == 0)
            func_020649D4((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x34),
                          *(int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x174));
        if (((*(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x140) << 0x13) >> 0x1f) != 0)
            func_020169E8((u8 *)self, (u8 *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4)));
        if (((B1 *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x144))->b0 == 1) {
            func_02016374((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4)));
            func_020649D4((char *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x34), 0);
            *(unsigned int *)(*(int *)(((struct Obj01459 *)self)->f14 + i * 4) + 0x144) &= ~1u;
        }
    }
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: an acquire/release pair on the same object. sub_02014CB8 only
 * acts the first time (its own field at +0 is the guard); it records the
 * argument at +4 and installs whatever func_020490F4 returns at +0.
 * sub_02014CD4 is the release: if +0 is set it tears it down and clears
 * both fields.
 *
 * ENV_SetResourceSet_2 is not the same call site as
 * src/matched/unit_02014444.c's ENV_SetResourceSet: `layout/symbols_sdk.txt`
 * recovers three separate addresses for that SDK name (0x020307B0,
 * 0x02049238, 0x0204B084), one per statically linked object that pulled the
 * small library routine in, and this file only ever reaches the second one.
 * The two extern declarations therefore differ (three registers forwarded
 * there, one used here), which is a property of each call site, not a
 * disagreement about the routine.
 *
 * The one detail that pinned the source: the field at +0x40 is read with a
 * plain `ldr` (word reach, +124) and truncated to u16 afterwards rather than
 * loaded with `ldrh` (reach +62) directly, which only happens when the field
 * itself is declared u32 and truncated at the call, matching
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md's family of reach-driven
 * tells. Declaring it u16 outright produces an extra `adds` to reach the
 * offset and is 4 bytes wrong.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014CB8.c \
 *       --addr 0x02014CB8 --thumb
 */
void sub_02014CB8(struct Sub02014CB8Obj *o, u32 x)
{
    if (o->f00 == 0) {
        o->f04 = x;
        o->f00 = func_020490F4(x, (u16)o->f40);
    }
}

void sub_02014CD4(struct Sub02014CB8Obj *o)
{
    if (o->f00 != 0) {
        ENV_SetResourceSet_2(o->f00);
        o->f04 = 0;
        o->f00 = 0;
    }
}
