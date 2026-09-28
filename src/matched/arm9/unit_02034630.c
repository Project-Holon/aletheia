/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02034630
 * packet:   pkt_020345F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02034630, sub_02034640
 *
 * The packet's first function, sub_020345F8 (a five-entry linear search
 * over two small tables, neither of which has a witness anywhere else in
 * the ARM9 image), matches byte for byte but keeps two wildcarded ABS32
 * sites, so it is MATCH rather than EXACT and lives at
 * src/pending/sub_020345F8.c instead of in this file.
 *
 * sub_02034630/sub_02034640 are a sentinel pair on a two-word struct:
 * sub_02034630 marks it invalid (both words 0xFFFFFFFF) and sub_02034640
 * reports whether it currently is.
 *
 * The rest of this packet (sub_02034660, sub_020346B8, sub_020346D8,
 * sub_020346EC) is a separate, non-contiguous piece of this same small
 * file; see unit_020346D8.c and unit_020346EC.c for the two of those four
 * that matched cleanly. sub_02034660 (calls sub_0209C2B0 twice and
 * sub_02033CA8) and sub_020346B8 (calls sub_0203422C then this file's own
 * sub_02034630) are left open: both reach into the array/table subsystem
 * around pkt_020339D0 whose argument shapes are not pinned down yet.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020345F8.c \
 *       --addr 0x02034630 --arm
 */

typedef unsigned int u32;

struct Sentinel {
    u32 lo;
    u32 hi;
};

void sub_02034630(struct Sentinel *p)
{
    p->lo = 0xFFFFFFFFu;
    p->hi = 0xFFFFFFFFu;
}

u32 sub_02034640(struct Sentinel *p)
{
    return p->lo == 0xFFFFFFFFu && p->hi == 0xFFFFFFFFu;
}
