/*
 * A whole translation unit, matched as one byte range.
 *
 * Previously parked at MATCH: the two dispatch arms 0x02033CFC and
 * 0x02033E30 are each reached by exactly one branch in the whole image, the
 * one in AREAMAN_AllocUp itself, so neither had an outside witness.  Both now
 * close on the `matched` class (src/matched/AREAMAN_AllocShortUp.c and
 * src/matched/AREAMAN_AllocLongUp.c); nothing in this file had to change.
 *
 * unit:     yes
 * address:  0x02033CA8
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: AREAMAN_Alloc, AREAMAN_AllocUp
 *
 * symbols:
 *   AREAMAN_AllocShortUp  0x02033CFC  arm
 *   AREAMAN_AllocLongUp  0x02033E30  arm
 *
 * areaman.c, the front door of the variable length record allocator built on
 * the 0x02033C00 object.  AREAMAN_Alloc is the "search the whole bitmap" entry
 * point: it forwards to the ranged form with a start of zero and a limit of
 * the object's bit count.  AREAMAN_AllocUp validates the request against the
 * bitmap extent and then dispatches on the run length: runs shorter than
 * eight bits go to the bit-at-a-time scanner at 0x02033CFC, longer runs to
 * the word-at-a-time scanner at 0x02033E30.  Both dispatch arms are written
 * out as their own return so that each gets its own `bl`/`pop` pair, which is
 * what the original has.
 *
 * The forwarding tail call in AREAMAN_Alloc is the pool-word-and-bx idiom
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

extern s32 AREAMAN_AllocShortUp(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern s32 AREAMAN_AllocLongUp(struct AreaMan *p, u32 start, u32 limit, u32 len);

s32 AREAMAN_AllocUp(struct AreaMan *p, u32 start, u32 limit, u32 len);

s32 AREAMAN_Alloc(struct AreaMan *p, u32 len)
{
    return AREAMAN_AllocUp(p, 0, p->unk00, len);
}

s32 AREAMAN_AllocUp(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    if (limit < len || start + len > p->unk00) {
        return -1;
    }

    if (len < 8) {
        return AREAMAN_AllocShortUp(p, start, limit, len);
    }

    return AREAMAN_AllocLongUp(p, start, limit, len);
}
