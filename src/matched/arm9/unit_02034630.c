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
 * function: VMAN_InvalidateHandle, VMAN_IsHandleInvalid
 *
 * The packet's first function, VMAN_GetUnitSize (a five-entry linear search
 * over two small tables, neither of which has a witness anywhere else in
 * the ARM9 image), matches byte for byte but keeps two wildcarded ABS32
 * sites, so it is MATCH rather than EXACT and lives at
 * src/pending/VMAN_GetUnitSize.c instead of in this file.
 *
 * VMAN_InvalidateHandle/VMAN_IsHandleInvalid are a sentinel pair on a two-word struct:
 * VMAN_InvalidateHandle marks it invalid (both words 0xFFFFFFFF) and VMAN_IsHandleInvalid
 * reports whether it currently is.
 *
 * The rest of this packet (sub_02034660, VMAN_Free, VMAN_GetOffset,
 * sub_020346EC) is a separate, non-contiguous piece of this same small
 * file; see unit_020346D8.c and unit_020346EC.c for the two of those four
 * that matched cleanly. sub_02034660 (calls sub_0209C2B0 twice and
 * AREAMAN_Alloc) and VMAN_Free (calls AREAMAN_Free then this file's own
 * VMAN_InvalidateHandle) are left open: both reach into the array/table subsystem
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

void VMAN_InvalidateHandle(struct Sentinel *p)
{
    p->lo = 0xFFFFFFFFu;
    p->hi = 0xFFFFFFFFu;
}

int VMAN_IsHandleInvalid(struct Sentinel *p)
{
    return p->lo == 0xFFFFFFFFu && p->hi == 0xFFFFFFFFu;
}
