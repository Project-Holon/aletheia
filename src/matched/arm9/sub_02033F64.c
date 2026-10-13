/*
 * Previously parked at MATCH.  Same shape as src/matched/unit_02033CA8.c:
 * the two dispatch arms 0x02033FB0 and 0x020340D0 have exactly one caller
 * each image-wide, this function, so `label` had no outside witness.  Both
 * now close on the `matched` class (src/matched/AREAMAN_AllocShortDown.c and
 * src/matched/AREAMAN_AllocLongDown.c); nothing in this file had to change.
 *
 * function: AREAMAN_AllocDown
 * address:  0x02033F64
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   AREAMAN_AllocShortDown  0x02033FB0  arm
 *   AREAMAN_AllocLongDown  0x020340D0  arm
 *   AREAMAN_TraceAlloc  0x02034508  arm
 *
 * areaman.c.  The second front door of the allocator, the mirror of
 * AREAMAN_AllocUp: same short-run / long-run dispatch on eight bits, but the
 * result is reported to the assert sink at 0x02034508 (line 0x230) before
 * being returned, so both arms have to land in one named local instead of
 * returning directly.  That is the whole difference in code shape between
 * this function and AREAMAN_AllocUp.
 *
 * All four arguments reach both callees untouched, which is why neither
 * `bl` is preceded by any argument move.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/AREAMAN_AllocDown.c \
 *       --func AREAMAN_AllocDown --addr 0x02033F64 --cc 1.1p1 --arm
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

extern s32 AREAMAN_AllocShortDown(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern s32 AREAMAN_AllocLongDown(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern void AREAMAN_TraceAlloc(struct AreaMan *p, s32 pos, u32 len, u32 line);

s32 AREAMAN_AllocDown(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 pos;

    if (limit < len) {
        return -1;
    }

    if (len < 8) {
        pos = AREAMAN_AllocShortDown(p, start, limit, len);
    } else {
        pos = AREAMAN_AllocLongDown(p, start, limit, len);
    }

    AREAMAN_TraceAlloc(p, pos, len, 0x230);
    return pos;
}
