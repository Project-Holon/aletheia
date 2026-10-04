/*
 * function: func_02062270
 * address:  0x02062270
 * packet:   pkt_02061D0C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146B94_blk  0x02146B94  data
 *   g_02146B94      0x02146B94  data
 *   g_02146B98      0x02146B98  data
 *   g_02146B9C      0x02146B9C  data
 *   g_020A17A8      0x020A17A8  data
 *   func_02061DF0   0x02061DF0  arm
 *   func_02061DFC   0x02061DFC  arm
 *   func_02061E48   0x02061E48  arm
 *   func_02061FF8   0x02061FF8  arm
 *
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
typedef unsigned char u8;
typedef unsigned int u32;
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
extern struct Cfg g_02146B94_blk;
extern u32 g_02146B94;
extern u32 g_02146B98;
extern u32 g_02146B9C;
extern const struct Rgns g_020A17A8;
extern void func_02061DF0(u32 *head);
struct Node02061DFC;
extern struct Node02061DFC *func_02061DFC(struct Node02061DFC *arr, u32 count);
extern u32 func_02061E48(u32 *head, u32 *pool, u32 addr, u32 size);
extern void func_02061FF8(u32 *head, u32 *pool);
void func_02062270(void)
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
        func_02061E48(&g_02146B98, &g_02146B9C, 0, t.r[0].acc8);
    {
        u32 a = t.r[0].acc8;
        if (t.r[0].acc4 != 0)
            func_02061E48(&g_02146B94, &g_02146B9C, a, t.r[0].acc4);
    }
    if (t.r[2].acc8 != 0)
        func_02061E48(&g_02146B98, &g_02146B9C, 0x40000, t.r[2].acc8);
    {
        u32 a = t.r[2].acc8;
        if (t.r[2].acc4 != 0)
            func_02061E48(&g_02146B94, &g_02146B9C, 0x40000 + a, t.r[2].acc4);
    }
    if (t.r[3].acc4 != 0)
        func_02061E48(&g_02146B94, &g_02146B9C, 0x60000, t.r[3].acc4);
    if (t.r[1].acc4 != 0)
        func_02061E48(&g_02146B94, &g_02146B9C, 0x20000 + half, t.r[1].acc4);

    func_02061FF8(&g_02146B94, &g_02146B9C);
    func_02061FF8(&g_02146B98, &g_02146B9C);
}
