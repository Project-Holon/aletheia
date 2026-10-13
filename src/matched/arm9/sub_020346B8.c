/*
 * function: VMAN_Free
 * address:  0x020346B8
 * packet:   pkt_02034660
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   AREAMAN_Free  0x0203422C  arm
 *   VMAN_InvalidateHandle  0x02034630  arm
 *
 * Hand a two-word handle back to the owner it came from and then invalidate
 * it in place.  The owner's first word is the object AREAMAN_Free works on;
 * the handle's two words are its argument pair, which is what the `ldm r4,
 * {r1, r2}` is: one aggregate read of the Sentinel that
 * src/matched/unit_02034630.c pins.
 *
 * The handle is copied into a callee-saved register before the call because
 * it is needed again afterwards for VMAN_InvalidateHandle, and the owner load is not:
 * it is consumed by the first call and never referenced again.
 *
 * This is the function that unblocks src/matched/CLACT_ReleaseCharacter.c, which is its
 * only caller image-wide and therefore had no `label` witness for the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/VMAN_Free.c \
 *       --func VMAN_Free --addr 0x020346B8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Sentinel {
    u32 lo;
    u32 hi;
};

struct Owner {
    void *unk_00;
};

typedef signed int     s32;
struct AreaMan;
extern void AREAMAN_Free(struct AreaMan *p, u32 start, s32 len);
extern void VMAN_InvalidateHandle(struct Sentinel *p);

void VMAN_Free(struct Owner *owner, struct Sentinel *p)
{
    AREAMAN_Free(owner->unk_00, p->lo, p->hi);
    VMAN_InvalidateHandle(p);
}
