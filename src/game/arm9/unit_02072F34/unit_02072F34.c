/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: func_02072F34, func_02072F48
 * address:  0x02072F34
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The pointer at offset 0 of the object is `volatile`: the guard's load and the
 *  * store's load are then two loads of the same word, where a plain field is
 *  * common-subexpression-eliminated to one load and comes out four bytes short.
 *  *
 *  * Verified with:
 *  *   python tools/match.py tu --src src/matched/unit_02072F34.c --addr 0x02072F34 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub { u8 pad00[0x40]; u8 b40; u8 b41; };
struct Obj { struct Sub * volatile p; };

void func_02072F34(struct Obj *o, u8 v)
{
    if (o->p) o->p->b41 = v;
}

void func_02072F48(struct Obj *o, u8 v)
{
    if (o->p) o->p->b40 = v;
}
