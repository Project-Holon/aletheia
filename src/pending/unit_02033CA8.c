/*
 * PARKED AT MATCH.  Every concrete byte is right, padding included, and the
 * self-attesting tail call inside the unit closes as `local`.  The two open
 * sites are the dispatch arms, 0x02033CFC and 0x02033E30: each is reached by
 * exactly one branch in the whole image, the one in sub_02033CC0 itself, so
 * neither can be attested from outside this range.  Both close as soon as
 * the two scanners are EXACT manifest entries, at which point the `matched`
 * class carries them; nothing about this file has to change.
 *
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02033CA8
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * function: sub_02033CA8, sub_02033CC0
 *
 * symbols:
 *   func_02033CFC  0x02033CFC  arm
 *   func_02033E30  0x02033E30  arm
 *
 * areaman.c, the front door of the variable length record allocator built on
 * the 0x02033C00 object.  sub_02033CA8 is the "search the whole bitmap" entry
 * point: it forwards to the ranged form with a start of zero and a limit of
 * the object's bit count.  sub_02033CC0 validates the request against the
 * bitmap extent and then dispatches on the run length: runs shorter than
 * eight bits go to the bit-at-a-time scanner at 0x02033CFC, longer runs to
 * the word-at-a-time scanner at 0x02033E30.  Both dispatch arms are written
 * out as their own return so that each gets its own `bl`/`pop` pair, which is
 * what the original has.
 *
 * The forwarding tail call in sub_02033CA8 is the pool-word-and-bx idiom
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): one section per function
 * means the call to the very next function in the same file still costs a
 * pool word.  Keeping the two in one unit makes that site `local`, which is
 * what closes it without an outside witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/unit_02033CA8.c \
 *       --addr 0x02033CA8 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct AreaMan {
    u16 unk00;
    u16 unk02;
    u32 *guard;
    u32 unk08;
    u8 bits[1];
};

extern s32 func_02033CFC(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern s32 func_02033E30(struct AreaMan *p, u32 start, u32 limit, u32 len);

s32 sub_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len);

s32 sub_02033CA8(struct AreaMan *p, u32 len)
{
    return sub_02033CC0(p, 0, p->unk00, len);
}

s32 sub_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    if (limit < len || start + len > p->unk00) {
        return -1;
    }

    if (len < 8) {
        return func_02033CFC(p, start, limit, len);
    }

    return func_02033E30(p, start, limit, len);
}
