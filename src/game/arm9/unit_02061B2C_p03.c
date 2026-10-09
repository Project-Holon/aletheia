/*
 * file:     unit_02061B2C_p03.c
 * unit:     yes
 * function: func_02061EB8, func_02061FF8, func_0206207C, func_0206210C, func_02062114
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
 * symbols:
 *   func_02061D0C  0x02061D0C  arm
 *   g_02146B94   0x02146B94  data
 *   g_020A8140   0x020A8140  data
 *   g_020A8144   0x020A8144  data
 *   func_02062270   0x02062270  arm
 *   func_0206216C   0x0206216C  arm
 *   func_020621FC   0x020621FC  arm
 */
#include "../../matched/include/Obj03022.h"
#include "../../matched/include/Obj03466.h"

struct Node;
struct Range;
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
    u32 f00;
    u32 f04;
    u32 f08;
    struct Node02061FF8 *f0c;
} Node02061FF8;

typedef struct Node0206207C {
    u32 f00;
    u32 f04;
    struct Node0206207C *f08;
    struct Node0206207C *f0c;
} Node0206207C;

struct Save {
    u8  pad_00[0xc];
    u32 f0c;    /* 0x0c */
    u32 f10;    /* 0x10 */
    u32 f14;    /* 0x14 */
    u32 f18;    /* 0x18 */
};

extern u32 func_02061D0C(struct Node **head1, struct Node **head2, struct Range *range);
extern void func_02062270(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0206216C(u32 size, u32 flag);
extern u32 func_020621FC(u32 h);
BOOL func_02061EB8(Blk **list, Blk **pool, u32 *pRet, u32 size, u32 alignment);
void func_02061FF8(void *pp, int arg);
int func_0206207C(void *headp, void *freep, int a2, int a3);
int func_0206210C(int v);
void func_02062114(u32 a, u32 b, u32 c, u32 d, u32 e);
extern struct Save g_02146B94;


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
 *   python3 tools/match.py one --src src/matched/func_02061EB8.c \
 *       --func func_02061EB8 --addr 0x02061EB8 --arm --cc ../2.0/sp2
 *   EXACT, 320 bytes, no relocations (sp2p2 EXACT too, 1.1p1 312 DIFF).
 */
BOOL func_02061EB8(Blk **list, Blk **pool, u32 *pRet, u32 size, u32 alignment)
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




void func_02061FF8(void *pp, int arg)
{
    Node02061FF8 *n = *(Node02061FF8 * *)&((struct Obj03022 *)pp)->f0;

    while (n != 0) {
        u32 buf[2];
        buf[0] = n->f00;
        buf[1] = n->f00 + n->f04;
        if (func_02061D0C(pp, (struct Node **)arg, (struct Range *)buf) != 0) {
            n->f00 = buf[0];
            n->f04 = buf[1] - buf[0];
            n = *(Node02061FF8 * *)&((struct Obj03022 *)pp)->f0;
        } else {
            n = n->f0c;
        }
    }
}





int func_0206207C(void *headp, void *freep, int a2, int a3)
{
    u32 buf[2];
    Node0206207C *x;

    buf[0] = a2;
    buf[1] = a2 + a3;
    func_02061D0C(headp, freep, (struct Range *)buf);
    x = *(Node0206207C * *)&((struct Obj03466 *)freep)->f0;
    if (x != 0) {
        *(Node0206207C * *)&((struct Obj03466 *)freep)->f0 = x->f0c;
    }
    if (x == 0) {
        return 0;
    }
    x->f00 = buf[0];
    x->f04 = buf[1] - buf[0];
    x->f08 = 0;
    x->f0c = 0;
    if (*(Node0206207C * *)&((struct Obj03022 *)headp)->f0 != 0) {
        (*(Node0206207C * *)&((struct Obj03022 *)headp)->f0)->f08 = x;
    }
    x->f0c = *(Node0206207C * *)&((struct Obj03022 *)headp)->f0;
    x->f08 = 0;
    *(Node0206207C * *)&((struct Obj03022 *)headp)->f0 = x;
    return 1;
}




int func_0206210C(int v){ return v << 4; }



extern void (*g_020A8140)(void);


extern void (*g_020A8144)(void);



/*
 * Closed 2026-09-22 (wave 7, pseudo-family pkt_02061D0C).  The two sites that
 * blocked it are both resolved now: func_0206216C was filed EXACT this lane
 * (../2.0/sp2) and the PC24 to func_02062270 carries on sole-ref/code, the
 * class widened 2026-09-21.  The two callback globals 0x020A8140 / 0x020A8144
 * were simply missing from the symbols: block and resolve as literal x20 each.
 *
 * Register-argument save hook: park r0-r3 in the 0x02146B94 block, run the
 * real body func_02062270 (which is handed the same four values), and when
 * the fifth (stack) argument is non-zero also install the two callbacks in
 * the clact.c handler slots 0x020A8140 / 0x020A8144.
 *
 * The 0x02146B94 block is written through its own address - a plain global
 * struct, not a pointer variable - so there is exactly one pool word for it.
 * The fifth argument is read at [sp, #8], the caller's first stack slot, past
 * the 8-byte {r3, lr} frame.
 */
void func_02062114(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    g_02146B94.f0c = a;
    g_02146B94.f10 = b;
    g_02146B94.f14 = c;
    g_02146B94.f18 = d;

    func_02062270(a, b, c, d);

    if (e != 0) {
        g_020A8140 = (void (*)(void))func_0206216C;
        g_020A8144 = (void (*)(void))func_020621FC;
    }
}
