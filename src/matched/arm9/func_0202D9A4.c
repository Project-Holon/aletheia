/*
 * function: func_0202D9A4
 * address:  0x0202D9A4
 * packet:   pkt_0202D7D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Collects five properties off the handle (func_02017E88 with selectors 5,
 * 0x6f, 0x6e and 0x4c, plus func_02017EB4) and forwards them into
 * func_0202D898 together with this function's own three trailing words and
 * its u16 key, tail-position, returning what func_0202D898 returns.
 *
 * Arity note (this is what the earlier note was blocked on): func_0202D898
 * itself is written with a by-value `volatile struct Args` trailing
 * parameter, because that is the only shape that reproduces ITS body -- but
 * the caller must NOT be written that way. Declaring the extern with the
 * aggregate, and building it in a named local (volatile or not), makes the
 * front end materialise the struct in the frame and copy it out with
 * ldm/stm: `sub sp` grows 0x24 -> 0x38 and 49 bytes differ. A C99 compound
 * literal at the call site is worse still (zero-fills first, 77 bytes).
 * Spelling the same five trailing words as plain scalars in this
 * translation unit's own prototype writes them straight into the outgoing
 * block and is EXACT. The two spellings agree on the ABI, so both files are
 * correct about the boundary; only the callee's side needs the aggregate.
 *
 * EXACT* only: the follower at 0x0202DA04 is unlabelled, so the inferred
 * extent runs over the trailing alignment halfword. Never a byte difference.
 * symbols:
 *   func_02017E88   0x02017E88  thumb
 *   func_02017EB4   0x02017EB4  thumb
 *   func_0202D898   0x0202D898  thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02017EB4(void *p);
extern u32 func_0202D898(u32 a0, u32 a1, u32 a2, u32 a3,
                         u32 w0, u32 w1, u32 w2, u32 w3, u32 key);

u32 func_0202D9A4(u32 h, u32 b1, u32 b2, u32 b3, u16 key)
{
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;

    v1 = func_02017E88((void *)h, 5, 0);
    v2 = func_02017E88((void *)h, 0x6f, 0);
    v3 = func_02017E88((void *)h, 0x6e, 0);
    v4 = func_02017EB4((void *)h);

    return func_0202D898(v1, v2, v3, v4,
                         b1, func_02017E88((void *)h, 0x4c, 0), b2, b3, key);
}
