/*
 * file:     zonedata_p13.c
 * unit:     yes
 * function: func_0201441C, func_02014428, func_02014444, func_0201444C, func_02014450, func_02014454, func_02014458, func_0201445C, func_02014460, func_02014464, func_02014468, func_0201446C, func_02014470, func_02014474, func_02014478, func_0201447C, func_02014484, func_02014488
 * address:  0x0201441C
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
 *   sub_0209E050_Map  0x0209E050  data
 *   sBtlSetupFile  0x020A72BC  data
 *   func_02030734  0x02030734  arm
 *   ENV_SetResourceSet  0x020307B0  arm
 *   sub_020120F0   0x020120F0  thumb
 *   sub_02012A30   0x02012A30  thumb
 *   sub_020289B8   0x020289B8  thumb
 *   func_0215FA44  0x0215FA44  thumb  ov010
 *   func_02188BD8  0x02188BD8  thumb  ov021
 */
#include "../../matched/include/Obj15653.h"
#include "../../matched/include/Obj05792.h"

struct BigObj;
struct Ctx;
struct Sys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub02014444Obj {
    u32 f00;
    u8  f04;
    u8  f05;
    u8  f06;
    u16 f08;
    u8  pad0A[7];
    u8  f11;
    u16 f12;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void ENV_SetResourceSet(u32 a, u32 b, u32 c);
extern u32 sub_02012A30(const struct BigObj *p);
extern u32 sub_020120F0(const struct Ctx *p);
extern u32 sub_020289B8(struct Sys *s);
extern void func_0215FA44(void);
extern void func_02188BD8(u8 *obj);
u8 func_0201441C(int i);
void func_02014428(u32 heap);
void sub_02014444(u32 a, u32 b, u32 c);
int sub_02014488(void *a0, u32 *a1, u8 *a2);
extern u8 sub_0209E050_Map[];
extern u8    sBtlSetupFile;


u8 func_0201441C(int i)
{
    return sub_0209E050_Map[i];
}


/*
 * Heap-allocates a 0x14-byte block tagged with the file string at
 * 0x020A72BC and line 0x33, then clears the u16 at +0x12.  The earlier
 * near miss in docs/notes/pkt_0201441C.c.txt declared the string at
 * 0x020A729C, 0x20 too low: the pool word in the image is the little-endian
 * bc 72 0a 02 at 0x02014440, and the one "differing byte" was bit 5 of that
 * address, not a register choice.
 */
void func_02014428(u32 heap)
{
    u8 *p = func_02030734(heap, 0x14, 1, (const char *)&sBtlSetupFile, 0x33);

    ((struct Obj15653 *)p)->f12 = 0;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void sub_02014444(u32 a, u32 b, u32 c)
{
    ENV_SetResourceSet(a, b, c);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
u32 sub_0201444C(struct Sub02014444Obj *o)
{
    return o->f00;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void sub_02014450(struct Sub02014444Obj *o, u32 v)
{
    o->f00 = v;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void sub_02014454(struct Sub02014444Obj *o, u8 v)
{
    o->f04 = v;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
u8 sub_02014458(struct Sub02014444Obj *o)
{
    return o->f04;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void sub_0201445C(struct Sub02014444Obj *o, u8 v)
{
    o->f05 = v;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
u8 sub_02014460(struct Sub02014444Obj *o)
{
    return o->f05;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void sub_02014464(struct Sub02014444Obj *o, u8 v)
{
    o->f06 = v;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
u8 sub_02014468(struct Sub02014444Obj *o)
{
    return o->f06;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void sub_0201446C(struct Sub02014444Obj *o, u16 v)
{
    o->f08 = v;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
u16 sub_02014470(struct Sub02014444Obj *o)
{
    return o->f08;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
void sub_02014474(struct Sub02014444Obj *o, u16 v)
{
    o->f12 = v;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
u16 sub_02014478(struct Sub02014444Obj *o)
{
    return o->f12;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
u8 sub_0201447C(struct Sub02014444Obj *o, u8 v)
{
    u8 old = o->f11;
    o->f11 = v;
    return old;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * alias: sub_02014444 is a tail-call trampoline for the SDK's
 * ENV_SetResourceSet, forwarding up to three register arguments
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Everything after it is
 * fourteen accessors on one small object: a u32 field at +0, three u8 fields
 * at +4/+5/+6 (the last pair, sub_02014464/sub_02014468, are the only two
 * with real prologue-less labels; the rest hide in the listing as .word runs
 * between the two literal pools either side of them, per
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), a u16 at +8, a
 * u16 at +0x12, and a u8 at +0x11 reached two ways: a plain getter
 * (sub_02014484) and a set-and-return-old accessor (sub_0201447C) used by a
 * caller that wants the previous value in the same instruction that installs
 * the new one.
 *
 * The struct is otherwise opaque; nothing in this range or its callers names
 * it, so the seven-byte gap between +8 and +0x11 is left as padding rather
 * than guessed at.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02014444.c \
 *       --addr 0x02014444 --thumb
 */
u8 sub_02014484(struct Sub02014444Obj *o)
{
    return o->f11;
}


/*
 * promoted: seed round 9, EXACT (fresh match.py one) once the ov010 callees
 *           0x0215FA34 and 0x0215FA44 were seeded in layout/function_starts.txt
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * note:     re-verified 2026-09-22 (family wave 6, field_status.c) in a
 *           fresh process after the evidence rules widened twice: still
 *           MATCH*, 3 of 5 sites resolved, no change to the C.  The two
 *           blockers were re-checked against the overlay listings by hand
 *           and are CLOSED AT THE BOTTOM, not merely unfiled: neither
 *           0x02188BD8 nor 0x0215FA44 is a function start in ANY candidate
 *           overlay, so no `thumb ovNNN` region hint on the symbols: line
 *           can resolve them.  0x02188BD8 falls mid-instruction in ov009
 *           (inside `bl func_02193734`) and in ov096, and lands on plain
 *           .word data in ov021 and ov230; 0x0215FA44 falls inside a `str`
 *           in ov009 and on .word data in ov010.  A region hint only picks
 *           between labelled candidates; it cannot create a label.  This
 *           row therefore needs a decompiled overlay, not a better hint.
 *
 * blocking: unresolved: 02188BD8 (thumb, from header) has no witness outside 02014488..02014; unresolved: 0215FA44 (thumb, from header) has no witness outside 02014488..02014
 *
 * wave15:   overlay callees are unlabelled Thumb starts: 0x0215FA34 and
 *           0x0215FA44 in ov010 (.word 0x4B024801, ldr r0/ldr r3 thunks),
 *           0x02188BD8 in ov021; need seeds in those overlays' listings.
 */
int sub_02014488(void *a0, u32 *a1, u8 *a2)
{
    void *v = (void *)((struct Obj05792 *)a2)->f8;
    void *w = (void *)((struct Obj05792 *)a2)->f0;
    void *x = (void *)((struct Obj05792 *)a2)->f4;
    void *y;

    y = (void *)sub_02012A30(v);
    switch (*a1) {
    case 0:
        func_02188BD8(x);
        *a1 = *a1 + 1;
        break;
    case 1:
        if (sub_020120F0(w) != 0) {
            break;
        }
        if (sub_020289B8(y) == 1) {
            break;
        }
        if (((struct Obj05792 *)a2)->fC != 0) {
            func_0215FA44();
        }
        return 1;
    }
    return 0;
}
