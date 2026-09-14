/*
 * unit:     yes
 * address:  0x02011330
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02011330, func_0201134C, func_0201137C, func_02011398,
 *           func_020113B0, func_020113B4, func_020113C4
 *
 * Seven functions, no external calls at all, over two small structs read and
 * written by cursor.  Two of the seven carry no label in the generated
 * listing at all: func_0201134C and func_020113B0, both leaves whose
 * prologue (or total absence of one) saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * func_020113B0 is four bytes, `str r1, [r0, #0x14]; bx lr`: the plain
 * setter of the +0x14 field that func_020113B4 and func_020113C4 reach only
 * through a history ring.
 *
 * func_02011330 and func_0201134C are a matched pair, a little-endian u16
 * and u32 read off a byte cursor at +0x14, advancing it by 2 and by 4.
 * func_0201134C carries no label in the generated listing: it opens with
 * `push {r4, r5}`, which saves no `lr`, so disasm.py's prologue sweep never
 * fires on it and its 48 bytes print as a `.word` run between func_02011330
 * and func_0201137C (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Its four byte reads are built MSB-first through a Horner chain
 * (((0 + b3) << 8 + b2) << 8 + b1) << 8 + b0, which is what the register
 * allocator does with a `for` loop counting down; the two-byte version is
 * small enough that the same loop unrolls into the flat expression used
 * below.
 *
 * func_0201137C and func_02011398 are a fixed-capacity ring: a byte count at
 * +0xC bounded by a halfword capacity at +0x0, backed by a `u32` array
 * pointed to by +0x18.  func_0201137C pushes if there is room and returns
 * whether it did; func_02011398 pops the oldest entry, or 0 if the ring is
 * empty (and leaves the count at 0 rather than going negative).
 *
 * func_020113B4 and func_020113C4 are a different struct's accessors for a
 * plain u32 field at +0x14, the same offset func_020113B0 sets directly:
 * func_020113B4 pushes the field's old value onto a func_0201137C ring
 * before overwriting it with the new one, and func_020113C4 pops a
 * func_02011398 ring back into the field.  Both take the ring struct
 * pointer as the same first argument as the field's owner, so the two
 * structs are declared distinctly here (Ring and Cur) even though nothing
 * in this file proves they are not the same struct in the original; only
 * the offsets that are read are declared.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011330.c \
 *       --addr 0x02011330 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Stream {
    u8 unk00[0x14];
    u8 *cursor;
};

u16 func_02011330(struct Stream *s)
{
    u8  b0, b1;
    u16 t;

    b0 = *s->cursor;
    s->cursor = s->cursor + 1;
    b1 = *s->cursor;
    s->cursor = s->cursor + 1;
    t = (u16)(b1 << 8);
    return b0 + t;
}

u32 func_0201134C(struct Stream *s)
{
    u8  b0, b1, b2, b3;
    u32 v;

    b0 = *s->cursor;
    s->cursor = s->cursor + 1;
    b1 = *s->cursor;
    s->cursor = s->cursor + 1;
    b2 = *s->cursor;
    s->cursor = s->cursor + 1;
    b3 = *s->cursor;
    s->cursor = s->cursor + 1;

    v = 0;
    v = v + b3;
    v = v << 8;
    v = v + b2;
    v = v << 8;
    v = v + b1;
    v = v << 8;
    v = v + b0;
    return v;
}

struct Ring {
    u16 cap;
    u8  unk02[0xA];
    u8  count;
    u8  unk0D[0xB];
    u32 *buf;
};

void func_0201137C(struct Ring *r, u32 v)
{
    if (r->count + 1 < r->cap) {
        r->buf[r->count] = v;
        r->count = r->count + 1;
    }
}

u32 func_02011398(struct Ring *r)
{
    if (r->count == 0) {
        return 0;
    }
    r->count = r->count - 1;
    return r->buf[r->count];
}

struct Cur {
    u8  unk00[0x14];
    u32 unk14;
};

void func_020113B0(struct Cur *c, u32 v)
{
    c->unk14 = v;
}

void func_020113B4(struct Ring *r, u32 v)
{
    struct Cur *c = (struct Cur *)r;
    u32 old = c->unk14;
    func_0201137C(r, old);
    c->unk14 = v;
}

void func_020113C4(struct Ring *r)
{
    struct Cur *c = (struct Cur *)r;
    c->unk14 = func_02011398(r);
}
