/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * unit:     yes
 * address:  0x0201F4A0
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: func_0201F4A0
 *
 * symbols:
 *   func_0201F4A0_Table  0x0209E864  data
 *
 * The nine-bit unpacker.  A string whose first character is 0xF100
 * (func_0201F47C, src/matched/unit_0201F47C.c) carries its text as a run of
 * nine-bit codes packed into the halfwords after the marker; this walks them
 * and appends one character at a time to the destination.  0x1FF is the
 * terminator as well as the field mask, codes 0x100..0x131 are translated
 * through a 16-bit table and anything at or above 0x132 becomes 0x3F, '?'.
 *
 * Every concrete byte is reproduced.  The one unresolved relocation is the
 * table address 0x0209E864, and the pool word inside this function is the
 * only word in the image that holds it, so the `literal` class discards its
 * only witness and no cut helps.  Expressing the address as an offset from
 * func_0201F35C's nearby table would resolve it, but that is a claim that the
 * two are one object and the image does not say so.
 *
 * Three details cost time and are worth keeping:
 *
 *  - the bit cursor is signed.  `cmp r5, #0x10` / `blt` is a signed compare
 *    even though the value is never negative, so the local is `s32`; `u32`
 *    gives `blo` and one wrong byte.
 *  - the two range limits and the table bias live in a local aggregate, not
 *    in scalars.  Each of the two limits is stored twice, once as 0x1FF and
 *    once as 0x1FF - 0xCD, because mwccarm's value numbering follows a scalar
 *    local but stops at a member of an aggregate; written as scalars the
 *    constants fold and six instructions disappear.  That is
 *    docs/idioms/a-guard-on-a-struct-member-survives-constant-folding.md seen
 *    from the assignment side rather than the test side.
 *  - the unpacking loop is the fall-through arm and the plain-string copy is
 *    the `else`.  Written as an early return for the plain case the copy is
 *    emitted first and every branch in the function moves
 *    (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201F4A0.c  *       --addr 0x0201F4A0 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern const u16 func_0201F4A0_Table[];
extern u32  func_0201F47C(void *s);
extern u16 *func_02045A90(void *s);
extern void func_02045AA8(void *dst, void *src);
extern void func_02045AFC(void *dst, u16 c);

struct Lim {
    u32 hi;
    u32 bias;
    u32 hi2;
};

void func_0201F4A0(void *dest, void *src)
{
    u32 mask = 0x1FF;
    struct Lim lim;
    const u16 *p;
    s32 bit;
    u16 v;

    if (func_0201F47C(src) != 0) {
        p = func_02045A90(src) + 1;
        lim.hi = mask;
        lim.hi -= 0xCD;
        lim.hi2 = mask;
        lim.hi2 -= 0xCD;
        lim.bias = mask + 1;
        bit = 0;
        for (;;) {
            v = (*p >> bit) & mask;
            bit += 9;
            if (bit >= 16) {
                p++;
                bit -= 16;
                if (bit != 0) {
                    v |= (*p << (9 - bit)) & mask;
                }
            }
            if (v == mask) {
                return;
            }
            if (v >= 0x100 && v < lim.hi) {
                v = *(const u16 *)((const u8 *)&func_0201F4A0_Table[v]
                                   - lim.bias);
            } else if (v >= lim.hi2) {
                v = 0x3F;
            }
            func_02045AFC(dest, v);
        }
    } else {
        func_02045AA8(dest, src);
    }
}
