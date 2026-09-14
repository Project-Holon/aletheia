/*
 * PARKED AT MATCH.  Every concrete byte is right.  Same shape as
 * src/pending/unit_02033CA8.c: the two dispatch arms 0x02033FB0 and
 * 0x020340D0 have exactly one caller each image-wide, this function, so
 * `label` has no outside witness.  Both close once those two scanners are
 * EXACT manifest entries.
 *
 * function: sub_02033F64
 * address:  0x02033F64
 * packet:   pkt_02033CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02033FB0  0x02033FB0  arm
 *   func_020340D0  0x020340D0  arm
 *   func_02034508  0x02034508  arm
 *
 * areaman.c.  The second front door of the allocator, the mirror of
 * sub_02033CC0: same short-run / long-run dispatch on eight bits, but the
 * result is reported to the assert sink at 0x02034508 (line 0x230) before
 * being returned, so both arms have to land in one named local instead of
 * returning directly.  That is the whole difference in code shape between
 * this function and sub_02033CC0.
 *
 * All four arguments reach both callees untouched, which is why neither
 * `bl` is preceded by any argument move.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02033F64.c \
 *       --func sub_02033F64 --addr 0x02033F64 --cc 1.1p1 --arm
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

extern s32 func_02033FB0(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern s32 func_020340D0(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern void func_02034508(struct AreaMan *p, s32 pos, u32 len, u32 line);

s32 sub_02033F64(struct AreaMan *p, u32 start, u32 limit, u32 len)
{
    s32 pos;

    if (limit < len) {
        return -1;
    }

    if (len < 8) {
        pos = func_02033FB0(p, start, limit, len);
    } else {
        pos = func_020340D0(p, start, limit, len);
    }

    func_02034508(p, pos, len, 0x230);
    return pos;
}
