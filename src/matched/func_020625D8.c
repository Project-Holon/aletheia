/*
 * function: func_020625D8
 * address:  0x020625D8
 * packet:   pkt_020625D8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146BB0_blk  0x02146BB0  data
 *   g_02146BB0      0x02146BB0  data
 *   g_02146BB4      0x02146BB4  data
 *   func_02061DF0   0x02061DF0  arm
 *   func_02061DFC   0x02061DFC  arm
 *   func_02061E48   0x02061E48  arm
 *   func_02061FF8   0x02061FF8  arm
 *
 * The layer-3 (8-byte granule) INITIALISER of docs/families/
 * cluster_02061D0C.h, the analogue of src/matched/func_02062270.c.
 * Builds the node pool from f0c / f10 >> 4, clears the list head, pushes
 * one { 0, f08 } block and sweeps the list.
 *
 * THE DUPLICATE POOL WORD IS TWO SYMBOLS, exactly as in func_02062270:
 * 0x02062628 is the base of every field access (config block
 * g_02146BB0_blk) and 0x0206262C is every list-head argument (u32
 * g_02146BB0).  docs/notes/func_020625D8.c.txt swept nine front ends with
 * one symbol; the two-symbol declaration is EXACT on its first compile.
 *
 * Pin evidence (2.0): the same C under dsi/1.1p1 is 92 bytes but pushes
 * {r4, r5, r6, lr} against the image's {r3, lr}, caching the two list
 * addresses in callee-saved registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020625D8.c \
 *       --func func_020625D8 --addr 0x020625D8 --arm --cc ../2.0/sp2
 */
typedef unsigned int u32;
struct Cfg
{
  u32 head;
  u32 pool;
  u32 f08;
  u32 f0c;
  u32 f10;
};
extern struct Cfg g_02146BB0_blk;
extern u32 g_02146BB0;
extern u32 g_02146BB4;
extern void func_02061DF0(u32 *head);
extern u32 func_02061DFC(u32 arr, u32 count);
extern u32 func_02061E48(u32 *head, u32 *pool, u32 addr, u32 size);
extern void func_02061FF8(u32 *head, u32 *pool);
void func_020625D8(void)
{
    g_02146BB0_blk.pool = func_02061DFC(g_02146BB0_blk.f0c, g_02146BB0_blk.f10 >> 4);
    func_02061DF0(&g_02146BB0);
    func_02061E48(&g_02146BB0, &g_02146BB4, 0, g_02146BB0_blk.f08);
    func_02061FF8(&g_02146BB0, &g_02146BB4);
}
