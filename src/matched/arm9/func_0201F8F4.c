/*
 * function: func_0201F8F4
 * address:  0x0201F8F4
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases every live handle in an eight-byte-stride table and blanks its
 * slot.  The table is terminated by 0xFFFFFFFF and the walk also stops at the
 * first null slot.  0xFFFFFFFF is materialised as `movs`/`mvns`, not a pool
 * word.
 *
 * The first word is a union: the terminator test reads it as u32 and the
 * null test reads it as a pointer.  That is what keeps the second `ldr` in
 * the loop body alive, and it is the only spelling that does; with a single
 * u32 member the compiler forwards the guard's load into the body and the
 * function comes out two instructions short whether the loop is written as a
 * `while`, a `for`, or a guard plus `do`/`while`.  The call then has to take
 * the pointer member too, or the null test lands in r1 and the call argument
 * stays the stale guard value.  See
 * docs/idioms/a-sentinel-test-and-a-null-test-on-one-word-are-two-union-members.md.
 *
 * EXACT* is the extent walk running into the unlabelled leaf at 0x0201F91C.
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F8F4.c \
 *       --func func_0201F8F4 --addr 0x0201F8F4 --cc 1.1p1 --thumb
 */
typedef unsigned int u32;

struct Slot {
    union {
        u32   raw;
        void *ptr;
    } u;
    u32 tag;
};

struct U16Vec;
extern void func_02045808(struct U16Vec *vec);

void func_0201F8F4(struct Slot *s)
{
    if (s->u.raw == 0xFFFFFFFF)
        return;
    do {
        if (s->u.ptr == 0)
            return;
        func_02045808(s->u.ptr);
        s->u.raw = 0;
        s++;
    } while (s->u.raw != 0xFFFFFFFF);
}
