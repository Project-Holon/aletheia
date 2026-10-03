/*
 * unit:     yes
 * address:  0x020181A0
 * packet:   pkt_02017FB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020181A0, func_020181F4, func_020181FC
 *
 * Two move-slot writers over the record's ids 0x36..0x39 (the four move ids),
 * 0x3A..0x3D (their current PP) and 0x3E..0x41 (their PP-up counts), the same
 * three groups func_02018E34 reads.  func_020181A0 refills every non-empty
 * slot's PP to the maximum func_0201C158 computes from the move and its PP-up
 * count; func_020181FC writes one slot outright, clearing the PP-up count and
 * setting the PP to the fresh maximum, or to zero when the move is zero.
 * func_020181F4 in front of it is an eight byte
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk, `local` because its
 * target is the next function in this unit.
 *
 * func_020181FC is what makes this unit and src/matched/unit_02018094.c-shaped
 * callers attest each other: its two call sites in the image are the thunk
 * here and one inside func_02018094, so neither range can hold both.
 *
 * Two spellings are load bearing.  func_020181A0's loop counter is unsigned,
 * because the bound test is `blo` and not `blt`; the counter of the otherwise
 * identical loop in func_02018094 and func_02018240 is signed and those use
 * `blt`.  And the two truncations in func_020181A0 sit at the call, `(u16)m`
 * and `(u8)u` on word locals, rather than on narrower locals, which is the
 * same shape as src/matched/unit_02018430.c.
 *
 * Nothing here is version specific: 0x36, 0x3A and 0x3E are field selectors.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_020181A0.c \
 *       --addr 0x020181A0 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void func_02017E64(void *p, u32 id, u32 v);
extern u8 func_0201C158(u16 move, u32 ppUp);

void func_020181FC(void *p, u16 move, u32 slot);

void func_020181A0(void *p)
{
    u32 t = func_02017DBC(p);
    u32 i;

    for (i = 0; i < 4; i++) {
        u32 m = func_02017E88(p, 0x36 + i, 0);

        if (m != 0) {
            u32 u = func_02017E88(p, 0x3E + i, 0);

            func_02017E64(p, 0x3A + i, func_0201C158((u16)m, (u8)u));
        }
    }
    func_02017DE4(p, t);
}

void func_020181F4(void *p, u16 move, u32 slot)
{
    func_020181FC(p, move, slot);
}

void func_020181FC(void *p, u16 move, u32 slot)
{
    u32 pp = 0;

    func_02017E64(p, 0x36 + slot, move);
    func_02017E64(p, 0x3E + slot, 0);
    if (move != 0) {
        pp = func_0201C158(move, 0);
    }
    func_02017E64(p, 0x3A + slot, pp);
}
