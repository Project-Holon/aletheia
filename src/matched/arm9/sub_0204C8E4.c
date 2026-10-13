/*
 * unit:     no
 * function: CLACT_GetFreeActor
 * address:  0x0204C8E4
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02034714  0x02034714  arm
 *   s_FileName    0x020A7F74  data
 *
 * The slot allocator for the 0xe4-byte display object: walk the owner's
 * array of `count` records and return the first whose word 0 is zero, or
 * fail the GF_ASSERT(0) at calct.c:5204 and return NULL.
 *
 * 0xe4 is not a power of two, so the index is a real `mul` against a
 * materialised element size rather than a shift; the size constant lands in
 * r0 on top of the owner pointer because the count and the array base are
 * both hoisted out of the loop before the first iteration and the owner is
 * dead from there on.  The `ble` guard is signed, which is what a plain
 * `int i` compared against a `u16` field gives: the field zero-extends into
 * an int and the comparison stays signed.
 *
 * The two `__FILE__`/expression strings are one object here, not two.  The
 * file-name string 0x020A7F74 has 92 pool witnesses image-wide, but the
 * expression string "0" at 0x020A7F7C is pooled only by this function, and
 * it is one character long, below the string class's minimum run, so
 * `string` cannot fix it from the preceding terminator either (which is
 * what docs/idioms/a-string-after-a-data-table-has-no-witness.md describes
 * from the other side).  Declaring this translation unit's string area as
 * a single object whose second member starts at +8, the length of
 * "calct.c" including its terminator, puts both relocations on the attested
 * base and takes the +8 from the C.  Same bytes, same two pool words.  See
 * docs/idioms/an-assert-expression-string-rides-the-file-name-symbol.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_GetFreeActor.c \
 *       --func CLACT_GetFreeActor --addr 0x0204C8E4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj {
    u32 unk_00;
    u8  pad_04[0xe0];
};

struct Owner {
    struct Obj *objs;
    u8          pad_04[8];
    u16         count;
};

struct AssertStrings {
    char file[8];
    char expr0[4];
};

extern const struct AssertStrings s_FileName;

extern void sub_02034714(const char *file, u32 line, const char *expr);

struct Obj *CLACT_GetFreeActor(struct Owner *ow)
{
    int i;

    for (i = 0; i < ow->count; i++) {
        if (ow->objs[i].unk_00 == 0) {
            return &ow->objs[i];
        }
    }

    sub_02034714(s_FileName.file, 5204, s_FileName.expr0);
    return 0;
}
