/*
 * unit:     yes
 * address:  0x0201AB48
 * packet:   pkt_0201AB48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201AB48, sub_0201AB8C
 *
 * pokeparty.c: the store-at-index and swap-two-indices operations on the
 * party container, an array of 0xDC byte records eight bytes into the object
 * with a running count at +0x04.  The file name is the image's own: the debug
 * allocator call in sub_0201AB8C passes 0x020A7304, which spells
 * "pokeparty.c", and its neighbours in the string area are
 * "poke_regulation.c" and "poke_personal.c".
 *
 * Both functions copy a whole record with a plain struct assignment, which
 * this front end inlines as a counted `ldm`/`stm` loop of 27 eight-byte steps
 * plus a trailing word rather than as a call
 * (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md).  The record is
 * declared as an array of `u32` and not of `u8` for exactly that reason: a
 * one-aligned declaration gives a byte loop of 0xDC iterations, the same
 * shape with completely different bytes.
 *
 * sub_0201AB48 reads field 0xA9 (the "slot is occupied" derived id, see
 * src/pending/sub_02018E34.c) out of the destination slot before the copy and
 * out of the source after it, and adds the difference to the count, so the
 * count stays right whether the write fills an empty slot or overwrites a
 * full one.
 *
 * Two spellings in sub_0201AB48 are load bearing and neither is obvious.  The
 * destination of the copy is written as byte arithmetic,
 * `(u8 *)p + idx * sizeof(rec) + 8`, while the getter's argument is the
 * ordinary `&p->mon[idx]`: written the same way twice the compiler common
 * subexpression eliminates them and keeps the finished address in a
 * callee-saved register across both calls, which is four bytes short.  What
 * the original keeps alive across the calls is the *product*, and only two
 * differently associated address expressions produce that.  And the second
 * getter's result is not bound to a local: `a - func_02017E1C(...)` puts the
 * `subs` at the call, where the original has it, while a named `b` sinks it
 * past the copy loop (the mirror of
 * docs/idioms/cmp-operand-order-names-the-temporary.md).
 *
 * sub_0201AB8C swaps two slots through a heap-allocated temporary of exactly
 * one record, then swaps the two slots' 0x1B-keyed side values through
 * sub_0201ACC4 / sub_0201ACDC (src/matched/unit_0201AC2C.c).  It returns 0
 * unconditionally.
 *
 * symbols:
 *   sub_0201AB8C_File  0x020A7304  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AB48.c \
 *       --addr 0x0201AB48 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct PartyMon {
    u32 w[0x37];
};

struct Party {
    u32 unk00;
    u32 count;
    struct PartyMon mon[6];
};

extern u32  func_02017E1C(const void *entry, u32 id, u32 v);
extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file, u32 line);
extern void func_020307B0(void *p);
extern u32  sub_0201ACC4(struct Party *p, u32 idx);
extern void sub_0201ACDC(struct Party *p, u32 idx, u32 v);

extern const char sub_0201AB8C_File[];

void sub_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src)
{
    u32 a = func_02017E1C(&p->mon[idx], 0xA9, 0);
    u32 d = a - func_02017E1C(src, 0xA9, 0);

    *(struct PartyMon *)((u8 *)p + idx * sizeof(struct PartyMon) + 8) = *src;
    p->count += d;
}

u32 sub_0201AB8C(struct Party *p, u32 i, u32 j, u32 heap)
{
    u32 a;
    u32 b;
    struct PartyMon *tmp = (struct PartyMon *)func_02030734(heap, sizeof(struct PartyMon), 0,
                                                           sub_0201AB8C_File, 382);

    *tmp = p->mon[i];
    p->mon[i] = p->mon[j];
    p->mon[j] = *tmp;
    func_020307B0(tmp);
    a = sub_0201ACC4(p, i);
    b = sub_0201ACC4(p, j);
    sub_0201ACDC(p, i, b);
    sub_0201ACDC(p, j, a);
    return 0;
}
