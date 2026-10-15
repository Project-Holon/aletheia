/*
 * function: NNSi_GfdAllocLnkVram
 * address:  0x02061EB8
 * packet:   pkt_02061D0C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * First-fit allocate with alignment from the free-list engine of
 * docs/families/cluster_02061D0C.h (NitroSystem NNSi_GfdAllocLnkVram shape):
 * walk the free list for the first block that holds size plus the alignment
 * padding, push the padding back as its own block (a pool node, failing when
 * the pool is empty), carve the request off the front of the found block and
 * move an emptied block to the pool.  *pRet gets the aligned address.
 *
 * Closed wave 12 from the 320/137 source in docs/notes/pkt_02061EB8.c.txt.
 * What changed, each measured:
 *   - the alignment test is `if (alignment > 1) { align } else { plain }`:
 *     2.0/sp2 predicates the ELSE arm (ldrls/movls/movls, then bls) ahead of
 *     the THEN arm.  `if (alignment <= 1)` first branches instead.
 *   - pad / aligned / need carry NO initialisers (the image zeroes only
 *     `found`), and the shared failure exit is one `fail:` label.
 *   - the helpers are the NitroSystem inline set (GetNewBlock_, InitBlock_,
 *     InsertBlock_, RemoveBlock_), written as static inline.
 *   - permuter hill: the mask is spelled `alignment - 1` in place (no const
 *     local), then declaration order aligned, need, pad, found (brute-forced
 *     over the 24 orders; this is the only EXACT one).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_GfdAllocLnkVram.c \
 *       --func NNSi_GfdAllocLnkVram --addr 0x02061EB8 --arm --cc ../2.0/sp2
 *   EXACT, 320 bytes, no relocations (sp2p2 EXACT too, 1.1p1 312 DIFF).
 */
typedef unsigned int u32;
typedef int BOOL;

typedef struct Blk {
    u32 addr;
    u32 size;
    struct Blk *prev;
    struct Blk *next;
} Blk;

static inline Blk *GetNewBlock_(Blk **pool)
{
    Blk *b = *pool;
    if (b != 0)
        *pool = b->next;
    return b;
}

static inline void InitBlock_(Blk *b, u32 addr, u32 size)
{
    b->addr = addr;
    b->size = size;
    b->prev = 0;
    b->next = 0;
}

static inline void InsertBlock_(Blk **list, Blk *b)
{
    if (*list != 0)
        (*list)->prev = b;
    b->next = *list;
    b->prev = 0;
    *list = b;
}

static inline void RemoveBlock_(Blk **list, Blk *b)
{
    Blk *prev = b->prev;
    Blk *next = b->next;
    if (prev != 0)
        prev->next = next;
    else
        *list = next;
    if (next != 0)
        next->prev = prev;
}

BOOL NNSi_GfdAllocLnkVram(Blk **list, Blk **pool, u32 *pRet, u32 size, u32 alignment)
{
    u32 aligned;
    u32 need;
    u32 pad;
    Blk *found = 0;
    {
        Blk *b = *list;

        while (b) {
            if (alignment > 1) {
                aligned = (b->addr + (alignment - 1)) & ~(alignment - 1);
                pad = aligned - b->addr;
                need = size + pad;
            } else {
                aligned = b->addr;
                pad = 0;
                need = size;
            }
            if (b->size >= need) {
                found = b;
                break;
            }
            b = b->next;
        }
    }

    if (found) {
        if (pad > 0) {
            Blk *nb = GetNewBlock_(pool);
            if (nb) {
                InitBlock_(nb, found->addr, pad);
                InsertBlock_(list, nb);
            } else {
                goto fail;
            }
        }
        found->size -= need;
        found->addr += need;
        if (found->size == 0) {
            RemoveBlock_(list, found);
            InsertBlock_(pool, found);
        }
        *pRet = aligned;
        return 1;
    }
fail:
    *pRet = 0;
    return 0;
}
