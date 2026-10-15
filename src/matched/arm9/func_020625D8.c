/*
 * function: NNSi_GfdInitPlttVramHeap
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
 *   NNSi_GfdInitBlockPool   0x02061DFC  arm
 *   NNSi_GfdAddBlock   0x02061E48  arm
 *   NNSi_GfdMergeFreeBlockList   0x02061FF8  arm
 *
 * The layer-3 (8-byte granule) INITIALISER of docs/families/
 * cluster_02061D0C.h, the analogue of src/matched/NNSi_GfdInitTexVramHeap.c.
 * Builds the node pool from f0c / f10 >> 4, clears the list head, pushes
 * one { 0, f08 } block and sweeps the list.
 *
 * THE DUPLICATE POOL WORD IS TWO SYMBOLS, exactly as in NNSi_GfdInitTexVramHeap:
 * 0x02062628 is the base of every field access (config block
 * g_02146BB0_blk) and 0x0206262C is every list-head argument (u32
 * g_02146BB0).  docs/notes/NNSi_GfdInitPlttVramHeap.c.txt swept nine front ends with
 * one symbol; the two-symbol declaration is EXACT on its first compile.
 *
 * Pin evidence (2.0): the same C under dsi/1.1p1 is 92 bytes but pushes
 * {r4, r5, r6, lr} against the image's {r3, lr}, caching the two list
 * addresses in callee-saved registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdInitPlttVramHeap.c \
 *       --func NNSi_GfdInitPlttVramHeap --addr 0x020625D8 --arm --cc ../2.0/sp2
 */

#include "../include/G_Hdr02062474.h"

typedef unsigned int u32;
extern struct Hdr02062474 g_02146BB0_blk;
extern struct Hdr02062474 g_02146BB0;
extern u32 g_02146BB4;
extern void func_02061DF0(u32 *head);
struct Node02061DFC;
extern struct Node02061DFC *NNSi_GfdInitBlockPool(struct Node02061DFC *arr, u32 count);
struct List02061E48;
struct Pool02061E48;
extern u32 NNSi_GfdAddBlock(struct List02061E48 *list, struct Pool02061E48 *pool, u32 d0, u32 d1);
extern void NNSi_GfdMergeFreeBlockList(void *pp, int arg);
void NNSi_GfdInitPlttVramHeap(void)
{
    g_02146BB0_blk.pool = (u32)NNSi_GfdInitBlockPool((struct Node02061DFC *)g_02146BB0_blk.f0c, g_02146BB0_blk.f10 >> 4);
    func_02061DF0(&(*(u32 *)&g_02146BB0));
    NNSi_GfdAddBlock((struct List02061E48 *)(&(*(u32 *)&g_02146BB0)), (struct Pool02061E48 *)(&g_02146BB4), 0, g_02146BB0_blk.f08);
    NNSi_GfdMergeFreeBlockList(&(*(u32 *)&g_02146BB0), (int)(&g_02146BB4));
}
