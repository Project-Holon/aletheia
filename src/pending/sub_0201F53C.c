/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * unit:     yes
 * address:  0x0201F53C
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: func_0201F53C, func_0201F548
 *
 * Two unchecked byte-table lookups, six bytes of code each plus the pool word
 * that names the table.  Both are byte correct and both are held at MATCH by
 * the same thing: 0x0209E8C8 and 0x0209E8CA are each named by exactly one
 * word in the whole image, the pool word of the function that loads it, so
 * the `literal` class discards its only witness under the honesty rule and no
 * cut helps.  The two tables are two symbols rather than one at an offset:
 * the load is `ldrb r0, [r1, r0]`, a register-offset form with no immediate,
 * so the pool word has to be the exact base and there is no addend for the
 * resolver to compute
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md
 * is the case that does allow it).
 *
 * They are reached from src/matched/unit_0201F554.c, which is EXACT: the call
 * sites attest fine, it is the data that does not.  Promote this file if the
 * tables ever acquire a second reference.
 *
 * symbols:
 *   func_0201F53C_Table  0x0209E8C8  data
 *   func_0201F548_Table  0x0209E8CA  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201F53C.c \
 *       --addr 0x0201F53C --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 func_0201F53C_Table[];
extern const u8 func_0201F548_Table[];

u8 func_0201F53C(u32 i)
{
    return func_0201F53C_Table[i];
}

u8 func_0201F548(u32 i)
{
    return func_0201F548_Table[i];
}
