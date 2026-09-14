/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02014444
 * packet:   pkt_02014444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02014444, sub_0201444C, sub_02014450, sub_02014454,
 *           sub_02014458, sub_0201445C, sub_02014460, sub_02014464,
 *           sub_02014468, sub_0201446C, sub_02014470, sub_02014474,
 *           sub_02014478, sub_0201447C, sub_02014484
 *
 * symbols:
 *   ENV_SetResourceSet  0x020307B0  arm
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void ENV_SetResourceSet(u32 a, u32 b, u32 c);

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

void sub_02014444(u32 a, u32 b, u32 c)
{
    ENV_SetResourceSet(a, b, c);
}

u32 sub_0201444C(struct Sub02014444Obj *o)
{
    return o->f00;
}

void sub_02014450(struct Sub02014444Obj *o, u32 v)
{
    o->f00 = v;
}

void sub_02014454(struct Sub02014444Obj *o, u8 v)
{
    o->f04 = v;
}

u8 sub_02014458(struct Sub02014444Obj *o)
{
    return o->f04;
}

void sub_0201445C(struct Sub02014444Obj *o, u8 v)
{
    o->f05 = v;
}

u8 sub_02014460(struct Sub02014444Obj *o)
{
    return o->f05;
}

void sub_02014464(struct Sub02014444Obj *o, u8 v)
{
    o->f06 = v;
}

u8 sub_02014468(struct Sub02014444Obj *o)
{
    return o->f06;
}

void sub_0201446C(struct Sub02014444Obj *o, u16 v)
{
    o->f08 = v;
}

u16 sub_02014470(struct Sub02014444Obj *o)
{
    return o->f08;
}

void sub_02014474(struct Sub02014444Obj *o, u16 v)
{
    o->f12 = v;
}

u16 sub_02014478(struct Sub02014444Obj *o)
{
    return o->f12;
}

u8 sub_0201447C(struct Sub02014444Obj *o, u8 v)
{
    u8 old = o->f11;
    o->f11 = v;
    return old;
}

u8 sub_02014484(struct Sub02014444Obj *o)
{
    return o->f11;
}
