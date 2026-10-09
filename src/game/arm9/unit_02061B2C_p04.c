/*
 * file:     unit_02061B2C_p04.c
 * unit:     yes
 * function: func_0206216C, func_020621FC, func_02062270, func_0206246C, func_02062474, func_020624C8
 * address:  0x0206216C
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
 *   g_02146B94     0x02146B94  data
 *   g_02146B98     0x02146B98  data
 *   g_02146B9C     0x02146B9C  data
 *   func_02061EA4  0x02061EA4  arm
 *   func_0206207C  0x0206207C  arm
 *   g_02146B94_blk  0x02146B94  data
 *   g_020A17A8      0x020A17A8  data
 *   func_02061DF0   0x02061DF0  arm
 *   func_02061DFC   0x02061DFC  arm
 *   func_02061E48   0x02061E48  arm
 *   func_02061FF8   0x02061FF8  arm
 *   g_02146BB0       0x02146BB0  data
 *   g_020A8148       0x020A8148  data
 *   g_020A814C       0x020A814C  data
 *   func_020625D8    0x020625D8  arm
 *   func_02062594    0x02062594  arm
 *   g_02146BB4      0x02146BB4  data
 *   func_02061EB8   0x02061EB8  arm
 */
struct Node02061DFC;
struct List02061E48;
struct Pool02061E48;
struct Blk;
typedef unsigned int u32;

typedef unsigned char u8;

struct Cfg
{
  u32 head_a;
  u32 head_b;
  u32 pool;
  u32 f0c;
  u32 f10;
  u32 f14;
  u32 f18;
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

typedef unsigned short u16;

struct Hdr02062474 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
};

extern u32 func_02061EA4(u32 a, u32 b, u32 *out, u32 size);
extern int func_0206207C(void *headp, void *freep, int a2, int a3);
extern void func_02061DF0(u32 *head);
extern struct Node02061DFC *func_02061DFC(struct Node02061DFC *arr, u32 count);
extern u32 func_02061E48(struct List02061E48 *list, struct Pool02061E48 *pool, u32 d0, u32 d1);
extern void func_02061FF8(u32 *head, u32 *pool);
extern void func_020625D8(void);
extern int func_02062594(u32 id);
extern int func_02061EB8(struct Blk **list, struct Blk **pool, u32 *pRet, u32 size, u32 alignment);
u32 func_0206216C(u32 size, u32 flag);
u32 func_020621FC(u32 h);
void func_02062270(u32 a, u32 b, u32 c, u32 d);
int func_0206246C(int v);
void func_02062474(u32 a, u32 b, u32 c, u32 d);
u32 func_020624C8(u32 size, u32 flag);
extern u32 g_02146B94, g_02146B98, g_02146B9C;
extern struct Cfg g_02146B94_blk;
extern u32 g_02146B94;
extern u32 g_02146B98;
extern const struct Rgns g_020A17A8;
extern struct Hdr02062474 g_02146BB0;
extern u32 g_020A8148;
extern u32 g_020A814C;
extern u32 g_02146BB4;





/*
 * The heap-handle builder that pairs with the validator func_020621FC.
 * Round the request up to sixteen (0x10 for zero), refuse 0x7FFF0 and above,
 * ask func_02061EA4 for the block through the 0x02146B9x heap pair the flag
 * selects, and pack the answer: bits 3..18 of the returned address in the low
 * half, size/16 in bits 16..30, the caller's flag in bit 31.
 *
 * Two spelling details are load-bearing:
 *   - ../2.0/sp2, not dsi/1.1p1, exactly as its sibling func_020624C8: on
 *     1.1p1 the same C does not reproduce the two-arm call shape.
 *   - the packed handle is written size-high FIRST,
 *     `((n >> 4) << 16) | ((local << 13) >> 16) | (flag << 31)`; the other
 *     order swaps r0 and r1 through the final four instructions, the
 *     accumulator naming its second operand.
 */
u32 func_0206216C(u32 size, u32 flag)
{
    u32 n = (size == 0) ? 0x10 : (size + 0xf) & ~0xf;
    u32 local, r;

    if (n >= 0x7fff0) return 0;
    if (flag != 0) r = func_02061EA4((u32)&g_02146B98, (u32)&g_02146B9C, &local, n);
    else           r = func_02061EA4((u32)&g_02146B94, (u32)&g_02146B9C, &local, n);
    if (r == 0) return 0;
    return ((n >> 4) << 16) | ((local << 13) >> 16) | (flag << 31);
}





u32 func_020621FC(u32 h)
{
    u32 a2 = (h << 16) >> 13;
    u32 a3 = ((h & 0x7fff0000) >> 16) << 4;
    u32 flag = (h & 0x80000000) >> 31;
    u32 r;

    if (a3 != 0) {
        if (flag != 0) {
            r = func_0206207C((void *)((u32)&g_02146B98), (void *)((u32)&g_02146B9C), a2, a3);
        } else {
            r = func_0206207C((void *)((u32)&g_02146B94), (void *)((u32)&g_02146B9C), a2, a3);
        }
        if (r != 0) return 0;
        return 1;
    }
    return 2;
}



/*
 * The layer-2 (16-byte granule) INITIALISER of docs/families/
 * cluster_02061D0C.h, run by the save hook func_02062114.  Copies the
 * four-record apportionment table at 0x020A17A8 to the stack, spreads
 * the configured extent f10 over records 0 and 2 (pass 1, into acc8) and
 * the remainder f0c - 1.5*f10 over all four (pass 2, into acc4), then
 * clears both list heads, builds the node pool from f14 / f18 >> 4, pushes
 * up to six blocks and sweeps both lists.
 *
 * THE DUPLICATE POOL WORD IS TWO SYMBOLS.  The cluster header recorded this
 * function (and func_020625D8) as unclosable: the pool holds 0x02146B94
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
 * allocator pair func_0206216C / func_020621FC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062270.c \
 *       --func func_02062270 --addr 0x02062270 --arm --cc ../2.0/sp2
 */
void func_02062270(u32 a, u32 b, u32 c, u32 d)
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

    n = g_02146B94_blk.f10;
    rest = g_02146B94_blk.f0c - (n + (n >> 1));
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

    func_02061DF0(&g_02146B94);
    func_02061DF0(&g_02146B98);
    g_02146B94_blk.pool = (u32)func_02061DFC((struct Node02061DFC *)g_02146B94_blk.f14, g_02146B94_blk.f18 >> 4);

    if (t.r[0].acc8 != 0)
        func_02061E48((struct List02061E48 *)(&g_02146B98), (struct Pool02061E48 *)(&g_02146B9C), 0, t.r[0].acc8);
    {
        u32 a = t.r[0].acc8;
        if (t.r[0].acc4 != 0)
            func_02061E48((struct List02061E48 *)(&g_02146B94), (struct Pool02061E48 *)(&g_02146B9C), a, t.r[0].acc4);
    }
    if (t.r[2].acc8 != 0)
        func_02061E48((struct List02061E48 *)(&g_02146B98), (struct Pool02061E48 *)(&g_02146B9C), 0x40000, t.r[2].acc8);
    {
        u32 a = t.r[2].acc8;
        if (t.r[2].acc4 != 0)
            func_02061E48((struct List02061E48 *)(&g_02146B94), (struct Pool02061E48 *)(&g_02146B9C), 0x40000 + a, t.r[2].acc4);
    }
    if (t.r[3].acc4 != 0)
        func_02061E48((struct List02061E48 *)(&g_02146B94), (struct Pool02061E48 *)(&g_02146B9C), 0x60000, t.r[3].acc4);
    if (t.r[1].acc4 != 0)
        func_02061E48((struct List02061E48 *)(&g_02146B94), (struct Pool02061E48 *)(&g_02146B9C), 0x20000 + half, t.r[1].acc4);

    func_02061FF8(&g_02146B94, &g_02146B9C);
    func_02061FF8(&g_02146B98, &g_02146B9C);
}



int func_0206246C(int v){ return v << 4; }




/*
 * Blocking class: evidence (`literal`/`label`).  Every concrete byte is right; the
 * one unresolved site is the ABS32 for the data object at 0x020624C8 at 0x020624B8
 * (the pool word that installs the descriptor's function pointer).  0x020624C8 is
 * named by this pool word only -- nothing branches to it and no other pool
 * repeats it -- so `literal` discards its only witness and `label` does not
 * apply.  Every other site of this file resolves: 0x02146BB0 `literal x20`,
 * 0x020A8148 `literal x15`, 0x02062594 `label x5` and 0x020A814C `literal x15`.
 */
void func_02062474(u32 a, u32 b, u32 c, u32 d)
{
    g_02146BB0.unk8 = a;
    g_02146BB0.unkC = b;
    g_02146BB0.unk10 = c;
    func_020625D8();
    if (d == 0) {
        return;
    }
    g_020A8148 = (u32)func_020624C8;
    g_020A814C = (u32)func_02062594;
}


/*
 * Promote-first callee of src/pending/func_02062474.c (parks lane 2).
 * Allocate `size` bytes rounded up to eight from the sub-64K heap pair at
 * 0x02146BB0/0x02146BB4 and return a packed handle:
 * (address >> 3) | ((size >> 3) << 16).  Size 0 asks for eight bytes, a
 * request at or past 0x7FFF8 is refused, and the flag argument picks the
 * 8-byte-flag heap or the 0x10-byte-flag one; on the latter a block that
 * would cross 0x10000 is handed back to func_0206207C and refused.
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
 *   python tools/match.py one --src src/matched/func_020624C8.c \
 *       --func func_020624C8 --addr 0x020624C8 --cc ../2.0/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
u32 func_020624C8(u32 size, u32 flag)
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
        r = func_02061EB8((struct Blk **)(&g_02146BB0), (struct Blk **)(&g_02146BB4), &addr, size, 8);
        if (addr + size > 0x10000) {
            func_0206207C(&g_02146BB0, &g_02146BB4, addr, size);
            return 0;
        }
    } else {
        r = func_02061EB8((struct Blk **)(&g_02146BB0), (struct Blk **)(&g_02146BB4), &addr, size, 0x10);
    }
    if (r == 0)
        return 0;
    return ((size >> 3) << 16) | ((addr << 13) >> 16);
}
