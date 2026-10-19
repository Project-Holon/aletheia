/*
 * file:     nns_gfd_lnk_vram_man.c
 * unit:     yes
 * function: NNSi_GfdAllocLnkVram, NNSi_GfdMergeFreeBlockList, NNSi_GfdFreeLnkVram, NNSi_GfdSizeToGranuleTex, NNSi_GfdInitTexVramManager, NNS_GfdAllocTexVram, NNS_GfdFreeTexVram, NNSi_GfdInitTexVramHeap, NNSi_GfdSizeToGranulePltt, NNSi_GfdInitPlttVramManager, NNS_GfdAllocPlttVram, NNS_GfdFreePlttVram, NNSi_GfdInitPlttVramHeap
 * address:  0x02061EB8
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Own object: EXACT only with ../2.0/sp2; DIFF with 1.1p1 and dsi/1.2 (the
 * builds of nns_gfd_vram_transfer.c before it) and with ../1.2/sp2.  Not one file with
 * nns_gfd_vram_load_3.c: nns_gfd_vram_transfer.c lies between them.
 * One struct Cfg for g_02146B94 (two symbols at one address kept, the image has
 * two pool words), one struct HeapB for g_02146BB0.
 *
 * symbols:
 *   NNSi_GfdMergeAdjacentFreeBlocks  0x02061D0C  arm
 *   g_02146B94   0x02146B94  data
 *   NNS_GfdDefaultFuncAllocTexVram   0x020A8140  data
 *   NNS_GfdDefaultFuncFreeTexVram   0x020A8144  data
 *   g_02146B98     0x02146B98  data
 *   g_02146B9C     0x02146B9C  data
 *   NNSi_GfdAllocBlockUnaligned  0x02061EA4  arm
 *   g_02146B94_blk  0x02146B94  data
 *   g_020A17A8      0x020A17A8  data
 *   NNSi_GfdClearBlockListHead   0x02061DF0  arm
 *   NNSi_GfdInitBlockPool   0x02061DFC  arm
 *   NNSi_GfdAddBlock   0x02061E48  arm
 *   g_02146BB0       0x02146BB0  data
 *   NNS_GfdDefaultFuncAllocPlttVram       0x020A8148  data
 *   NNS_GfdDefaultFuncFreePlttVram       0x020A814C  data
 *   g_02146BB4      0x02146BB4  data
 *   g_02146BB0_blk  0x02146BB0  data
 */

struct Node;
struct Range;
struct Node02061DFC;
struct List02061E48;
struct Pool02061E48;
struct Blk;
typedef unsigned int u32;

typedef int BOOL;

typedef struct Blk {
    u32 addr;
    u32 size;
    struct Blk *prev;
    struct Blk *next;
} Blk;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Node02061FF8 {
    u32 addr;
    u32 szByte;
    struct Node02061FF8 *pBlkPrev;
    struct Node02061FF8 *pBlkNext;
} Node02061FF8;

typedef struct Node0206207C {
    u32 addr;
    u32 szByte;
    struct Node0206207C *pBlkPrev;
    struct Node0206207C *pBlkNext;
} Node0206207C;

struct Cfg
{
  u32 head_a;
  u32 head_b;
  u32 pool;
  u32 szByte;
  u32 szByteFor4x4;
  u32 pManagementWork;
  u32 szByteManagementWork;
};

struct Rgn
{
  u32 avail;
  u32 acc4;
  u32 acc8;
};

struct Rgns
{
  struct Rgn r[4];
};

struct HeapB
{
  u32 head;
  u32 pool;
  u32 szByte;
  u32 pManagementWork;
  u32 szByteManagementWork;
};
struct GfdLnkRange;
struct GfdLnkBlock;

extern u32 NNSi_GfdMergeAdjacentFreeBlocks(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, struct GfdLnkRange *range);
extern int NNSi_GfdAllocBlockUnaligned(struct GfdLnkBlock **ppList, struct GfdLnkBlock **ppPool, unsigned int *pAddr, unsigned int size);
extern void NNSi_GfdClearBlockListHead(struct GfdLnkBlock **ppHead);
struct GfdLnkBlock;
extern struct GfdLnkBlock *NNSi_GfdInitBlockPool(struct GfdLnkBlock *blocks, u32 count);
struct GfdLnkBlockPool;
struct GfdLnkBlockList;
extern u32 NNSi_GfdAddBlock(struct GfdLnkBlockList *list, struct GfdLnkBlockPool *pool, u32 start, u32 size);
BOOL NNSi_GfdAllocLnkVram(Blk **list, Blk **pool, u32 *pRet, u32 size, u32 alignment);
void NNSi_GfdMergeFreeBlockList(u32 *pp, u32 *arg);
int NNSi_GfdFreeLnkVram(void *headp, void *freep, int addr, int szByte);
int NNSi_GfdSizeToGranuleTex(int v);
void NNSi_GfdInitTexVramManager(u32 szByte, u32 szByteFor4x4, u32 pManagementWork, u32 szByteManagementWork, u32 useAsDefault);
u32 NNS_GfdAllocTexVram(u32 size, u32 flag);
u32 NNS_GfdFreeTexVram(u32 h);
void NNSi_GfdInitTexVramHeap(u32 szByte, u32 szByteFor4x4, u32 pManagementWork, u32 szByteManagementWork);
int NNSi_GfdSizeToGranulePltt(int v);
void NNSi_GfdInitPlttVramManager(u32 szByte, u32 pManagementWork, u32 szByteManagementWork, u32 useAsDefault);
u32 NNS_GfdAllocPlttVram(u32 size, u32 flag);
int NNS_GfdFreePlttVram(u32 id);
void NNSi_GfdInitPlttVramHeap(void);
extern struct Cfg g_02146B94;
extern struct Cfg g_02146B94_blk;
extern u32 g_02146B98;
extern u32 g_02146B9C;
extern const struct Rgns g_020A17A8;
extern struct HeapB g_02146BB0;
extern u32 NNS_GfdDefaultFuncAllocPlttVram;
extern u32 NNS_GfdDefaultFuncFreePlttVram;
extern u32 g_02146BB4;
extern struct HeapB g_02146BB0_blk;





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





/*
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







void NNSi_GfdMergeFreeBlockList(u32 *pp, u32 *arg)
{
    Node02061FF8 *n = *(Node02061FF8 **)pp;

    while (n != 0) {
        u32 buf[2];
        buf[0] = n->addr;
        buf[1] = n->addr + n->szByte;
        if (NNSi_GfdMergeAdjacentFreeBlocks((struct GfdLnkBlock **)pp, (struct GfdLnkBlock **)arg, (struct GfdLnkRange *)buf) != 0) {
            n->addr = buf[0];
            n->szByte = buf[1] - buf[0];
            n = *(Node02061FF8 **)pp;
        } else {
            n = n->pBlkNext;
        }
    }
}








int NNSi_GfdFreeLnkVram(void *headp, void *freep, int addr, int szByte)
{
    u32 buf[2];
    Node0206207C *x;

    buf[0] = addr;
    buf[1] = addr + szByte;
    NNSi_GfdMergeAdjacentFreeBlocks(headp, freep, (struct GfdLnkRange *)buf);
    x = *(Node0206207C **)freep;
    if (x != 0) {
        *(Node0206207C **)freep = x->pBlkNext;
    }
    if (x == 0) {
        return 0;
    }
    x->addr = buf[0];
    x->szByte = buf[1] - buf[0];
    x->pBlkPrev = 0;
    x->pBlkNext = 0;
    if (*(Node0206207C **)headp != 0) {
        (*(Node0206207C **)headp)->pBlkPrev = x;
    }
    x->pBlkNext = *(Node0206207C **)headp;
    x->pBlkPrev = 0;
    *(Node0206207C **)headp = x;
    return 1;
}







int NNSi_GfdSizeToGranuleTex(int v){ return v << 4; }






extern void (*NNS_GfdDefaultFuncAllocTexVram)(void);





extern void (*NNS_GfdDefaultFuncFreeTexVram)(void);






/*
 * Closed 2026-09-22 (wave 7, pseudo-family pkt_02061D0C).  The two sites that
 * blocked it are both resolved now: NNS_GfdAllocTexVram was filed EXACT this lane
 * (../2.0/sp2) and the PC24 to NNSi_GfdInitTexVramHeap carries on sole-ref/code, the
 * class widened 2026-09-21.  The two callback globals 0x020A8140 / 0x020A8144
 * were simply missing from the symbols: block and resolve as literal x20 each.
 *
 * Register-argument save hook: park r0-r3 in the 0x02146B94 block, run the
 * real body NNSi_GfdInitTexVramHeap (which is handed the same four values), and when
 * the fifth (stack) argument is non-zero also install the two callbacks in
 * the clact.c handler slots 0x020A8140 / 0x020A8144.
 *
 * The 0x02146B94 block is written through its own address - a plain global
 * struct, not a pointer variable - so there is exactly one pool word for it.
 * The fifth argument is read at [sp, #8], the caller's first stack slot, past
 * the 8-byte {r3, lr} frame.
 */
void NNSi_GfdInitTexVramManager(u32 szByte, u32 szByteFor4x4, u32 pManagementWork, u32 szByteManagementWork, u32 useAsDefault)
{
    g_02146B94.szByte = szByte;
    g_02146B94.szByteFor4x4 = szByteFor4x4;
    g_02146B94.pManagementWork = pManagementWork;
    g_02146B94.szByteManagementWork = szByteManagementWork;

    NNSi_GfdInitTexVramHeap(szByte, szByteFor4x4, pManagementWork, szByteManagementWork);

    if (useAsDefault != 0) {
        NNS_GfdDefaultFuncAllocTexVram = (void (*)(void))NNS_GfdAllocTexVram;
        NNS_GfdDefaultFuncFreeTexVram = (void (*)(void))NNS_GfdFreeTexVram;
    }
}








/*
 * The heap-handle builder that pairs with the validator NNS_GfdFreeTexVram.
 * Round the request up to sixteen (0x10 for zero), refuse 0x7FFF0 and above,
 * ask NNSi_GfdAllocBlockUnaligned for the block through the 0x02146B9x heap pair the flag
 * selects, and pack the answer: bits 3..18 of the returned address in the low
 * half, size/16 in bits 16..30, the caller's flag in bit 31.
 *
 * Two spelling details are load-bearing:
 *   - ../2.0/sp2, not dsi/1.1p1, exactly as its sibling NNS_GfdAllocPlttVram: on
 *     1.1p1 the same C does not reproduce the two-arm call shape.
 *   - the packed handle is written size-high FIRST,
 *     `((n >> 4) << 16) | ((local << 13) >> 16) | (flag << 31)`; the other
 *     order swaps r0 and r1 through the final four instructions, the
 *     accumulator naming its second operand.
 */
u32 NNS_GfdAllocTexVram(u32 size, u32 flag)
{
    u32 n = (size == 0) ? 0x10 : (size + 0xf) & ~0xf;
    u32 local, r;

    if (n >= 0x7fff0) return 0;
    if (flag != 0) r = NNSi_GfdAllocBlockUnaligned((struct GfdLnkBlock **)(&g_02146B98), (struct GfdLnkBlock **)(&g_02146B9C), &local, n);
    else           r = NNSi_GfdAllocBlockUnaligned((struct GfdLnkBlock **)(&g_02146B94), (struct GfdLnkBlock **)(&g_02146B9C), &local, n);
    if (r == 0) return 0;
    return ((n >> 4) << 16) | ((local << 13) >> 16) | (flag << 31);
}








u32 NNS_GfdFreeTexVram(u32 h)
{
    u32 addr = (h << 16) >> 13;
    u32 szByte = ((h & 0x7fff0000) >> 16) << 4;
    u32 flag = (h & 0x80000000) >> 31;
    u32 r;

    if (szByte != 0) {
        if (flag != 0) {
            r = NNSi_GfdFreeLnkVram((void *)((u32)&g_02146B98), (void *)((u32)&g_02146B9C), addr, szByte);
        } else {
            r = NNSi_GfdFreeLnkVram((void *)((u32)&g_02146B94), (void *)((u32)&g_02146B9C), addr, szByte);
        }
        if (r != 0) return 0;
        return 1;
    }
    return 2;
}






/*
 * The layer-2 (16-byte granule) INITIALISER of docs/families/
 * cluster_02061D0C.h, run by the save hook NNSi_GfdInitTexVramManager.  Copies the
 * four-record apportionment table at 0x020A17A8 to the stack, spreads
 * the configured extent szByteFor4x4 over records 0 and 2 (pass 1, into acc8) and
 * the remainder szByte - 1.5*szByteFor4x4 over all four (pass 2, into acc4), then
 * clears both list heads, builds the node pool from pManagementWork / szByteManagementWork >> 4, pushes
 * up to six blocks and sweeps both lists.
 *
 * THE DUPLICATE POOL WORD IS TWO SYMBOLS.  The cluster header recorded this
 * function (and NNSi_GfdInitPlttVramHeap) as unclosable: the pool holds 0x02146B94
 * twice, both live.  They are not one constant emitted twice: the copy at
 * 0x0206245C is the base every FIELD access uses (+0x0c, +0x10, +0x14,
 * +0x18, and the store of the pool head at +0x08), and the copy at
 * 0x02062460 is only ever passed as the LIST-HEAD argument.  Declaring
 * them as two externs pinned to the same address -- the config block
 * g_02146B94_blk and the list head g_02146B94 -- makes the front end emit
 * one pool word per symbol, which is the image.  Every single-symbol
 * spelling (`&blk.head_a`, `(u32 *)&blk`) still dedups to one word, 504
 * bytes.  Both relocations resolve as `literal` (x18 image-wide).
 *
 * The other two levers, found after the first 2.0 compile came out
 * size-exact at 75 bytes out (hill: 34 via decl-order(i<->rest)):
 *   - the second pass walks with its own cursor q (not p reused), which
 *     puts the cursor in r2 and the counter in r3;
 *   - the two blocks whose address argument is a previous record's acc8
 *     read it into a local BEFORE the guard; the image loads it ahead of
 *     the `cmp`.
 *
 * Pin evidence (2.0): the same C under dsi/1.1p1 pushes {r3, r4, r5, r6,
 * r7, lr} against the image's {r4, lr} -- the pool addresses are CSE'd
 * into callee-saved registers -- and splits the i == 0 || i == 2 guard
 * into two branches; 516 bytes, 398 out.  Same pin as the layer-2
 * allocator pair NNS_GfdAllocTexVram / NNS_GfdFreeTexVram.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdInitTexVramHeap.c \
 *       --func NNSi_GfdInitTexVramHeap --addr 0x02062270 --arm --cc ../2.0/sp2
 */
void NNSi_GfdInitTexVramHeap(u32 szByte, u32 szByteFor4x4, u32 pManagementWork, u32 szByteManagementWork)
{
    struct Rgns t;
    struct Rgn *p;
    u32 rest;
    u32 n;
    u32 i;
    u32 half;
    u32 take;
    struct Rgn *q;

    t = g_020A17A8;

    n = g_02146B94_blk.szByteFor4x4;
    rest = g_02146B94_blk.szByte - (n + (n >> 1));
    half = n >> 1;

    /* pass 1: records 0 and 2 absorb the 16-byte-granule extent */
    for (i = 0, p = t.r; i < 4; i++, p++) {
        if (i == 0 || i == 2) {
            if (p->avail != 0 && n != 0) {
                take = p->avail;
                if (take > n)
                    take = n;
                p->acc8 += take;
                n -= take;
                p->avail -= take;
            }
        }
    }

    t.r[1].avail -= half;

    /* pass 2: every record absorbs what is left of the other extent */
    for (i = 0, q = t.r; i < 4; i++, q++) {
        if (q->avail != 0 && rest != 0) {
            take = q->avail;
            if (take > rest)
                take = rest;
            q->acc4 += take;
            rest -= take;
            q->avail -= take;
        }
    }

    NNSi_GfdClearBlockListHead((struct GfdLnkBlock **)(&g_02146B94.head_a));
    NNSi_GfdClearBlockListHead((struct GfdLnkBlock **)(&g_02146B98));
    g_02146B94_blk.pool = (u32)NNSi_GfdInitBlockPool((struct GfdLnkBlock *)g_02146B94_blk.pManagementWork, g_02146B94_blk.szByteManagementWork >> 4);

    if (t.r[0].acc8 != 0)
        NNSi_GfdAddBlock((struct GfdLnkBlockList *)(&g_02146B98), (struct GfdLnkBlockPool *)(&g_02146B9C), 0, t.r[0].acc8);
    {
        u32 a = t.r[0].acc8;
        if (t.r[0].acc4 != 0)
            NNSi_GfdAddBlock((struct GfdLnkBlockList *)(&g_02146B94), (struct GfdLnkBlockPool *)(&g_02146B9C), a, t.r[0].acc4);
    }
    if (t.r[2].acc8 != 0)
        NNSi_GfdAddBlock((struct GfdLnkBlockList *)(&g_02146B98), (struct GfdLnkBlockPool *)(&g_02146B9C), 0x40000, t.r[2].acc8);
    {
        u32 a = t.r[2].acc8;
        if (t.r[2].acc4 != 0)
            NNSi_GfdAddBlock((struct GfdLnkBlockList *)(&g_02146B94), (struct GfdLnkBlockPool *)(&g_02146B9C), 0x40000 + a, t.r[2].acc4);
    }
    if (t.r[3].acc4 != 0)
        NNSi_GfdAddBlock((struct GfdLnkBlockList *)(&g_02146B94), (struct GfdLnkBlockPool *)(&g_02146B9C), 0x60000, t.r[3].acc4);
    if (t.r[1].acc4 != 0)
        NNSi_GfdAddBlock((struct GfdLnkBlockList *)(&g_02146B94), (struct GfdLnkBlockPool *)(&g_02146B9C), 0x20000 + half, t.r[1].acc4);

    NNSi_GfdMergeFreeBlockList(&g_02146B94.head_a, &g_02146B9C);
    NNSi_GfdMergeFreeBlockList(&g_02146B98, &g_02146B9C);
}






int NNSi_GfdSizeToGranulePltt(int v){ return v << 4; }







/*
 * Blocking class: evidence (`literal`/`label`).  Every concrete byte is right; the
 * one unresolved site is the ABS32 for the data object at 0x020624C8 at 0x020624B8
 * (the pool word that installs the descriptor's function pointer).  0x020624C8 is
 * named by this pool word only -- nothing branches to it and no other pool
 * repeats it -- so `literal` discards its only witness and `label` does not
 * apply.  Every other site of this file resolves: 0x02146BB0 `literal x20`,
 * 0x020A8148 `literal x15`, 0x02062594 `label x5` and 0x020A814C `literal x15`.
 */
void NNSi_GfdInitPlttVramManager(u32 szByte, u32 pManagementWork, u32 szByteManagementWork, u32 useAsDefault)
{
    g_02146BB0.szByte = szByte;
    g_02146BB0.pManagementWork = pManagementWork;
    g_02146BB0.szByteManagementWork = szByteManagementWork;
    NNSi_GfdInitPlttVramHeap();
    if (useAsDefault == 0) {
        return;
    }
    NNS_GfdDefaultFuncAllocPlttVram = (u32)NNS_GfdAllocPlttVram;
    NNS_GfdDefaultFuncFreePlttVram = (u32)NNS_GfdFreePlttVram;
}





/*
 * Promote-first callee of src/pending/NNSi_GfdInitPlttVramManager.c (parks lane 2).
 * Allocate `size` bytes rounded up to eight from the sub-64K heap pair at
 * 0x02146BB0/0x02146BB4 and return a packed handle:
 * (address >> 3) | ((size >> 3) << 16).  Size 0 asks for eight bytes, a
 * request at or past 0x7FFF8 is refused, and the flag argument picks the
 * 8-byte-flag heap or the 0x10-byte-flag one; on the latter a block that
 * would cross 0x10000 is handed back to NNSi_GfdFreeLnkVram and refused.
 *
 * Three spelling details are load-bearing and were each measured:
 *   - the 2.0 front end, not dsi/1.1p1: on 1.1p1 this same C keeps the two
 *     heap addresses in callee-saved r5/r6 (frame 212 bytes, push
 *     {r4,r5,r6,lr}) where the original rematerialises them from the pool at
 *     every call site (204 bytes, push {r4,lr});
 *   - a separate local for the rounded size with `size = n;` after the
 *     if/else: assigning straight back gives `movs r4, r0` where the
 *     original has `cmp r0, #0` (4 bytes);
 *   - the two halves of the packed handle are written size-high first
 *     (`((size >> 3) << 16) | ((addr << 13) >> 16)`): the other order costs
 *     4 more bytes, the accumulator naming its second operand.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_GfdAllocPlttVram.c \
 *       --func NNS_GfdAllocPlttVram --addr 0x020624C8 --cc ../2.0/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
u32 NNS_GfdAllocPlttVram(u32 size, u32 flag)
{
    u32 addr;
    u32 r;
    u32 n;

    if (size == 0)
        n = 8;
    else
        n = (size + 7) & ~7;
    size = n;
    if (size >= 0x7FFF8)
        return 0;
    if (flag != 0) {
        r = NNSi_GfdAllocLnkVram((struct Blk **)(&g_02146BB0), (struct Blk **)(&g_02146BB4), &addr, size, 8);
        if (addr + size > 0x10000) {
            NNSi_GfdFreeLnkVram(&g_02146BB0, &g_02146BB4, addr, size);
            return 0;
        }
    } else {
        r = NNSi_GfdAllocLnkVram((struct Blk **)(&g_02146BB0), (struct Blk **)(&g_02146BB4), &addr, size, 0x10);
    }
    if (r == 0)
        return 0;
    return ((size >> 3) << 16) | ((addr << 13) >> 16);
}



int NNS_GfdFreePlttVram(u32 id)
{
    u32 lo = (id & 0xFFFFu) << 3;
    u32 hi = ((id & 0xFFFF0000u) >> 16) << 3;

    return NNSi_GfdFreeLnkVram(&g_02146BB0, &g_02146BB4, lo, hi) == 0;
}

void NNSi_GfdInitPlttVramHeap(void)
{
    g_02146BB0_blk.pool = (u32)NNSi_GfdInitBlockPool((struct GfdLnkBlock *)g_02146BB0_blk.pManagementWork, g_02146BB0_blk.szByteManagementWork >> 4);
    NNSi_GfdClearBlockListHead((struct GfdLnkBlock **)(&g_02146BB0.head));
    NNSi_GfdAddBlock((struct GfdLnkBlockList *)(&g_02146BB0), (struct GfdLnkBlockPool *)(&g_02146BB4), 0, g_02146BB0_blk.szByte);
    NNSi_GfdMergeFreeBlockList(&g_02146BB0.head, &g_02146BB4);
}
