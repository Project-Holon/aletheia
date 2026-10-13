/*
 * function: func_02075698
 * address:  0x02075698
 * packet:   pkt_02075404
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * Sibling of src/matched/func_02075794.c (same open / bind / release shape):
 * open a handle with func_02073344, bind a slot through func_02074CD0 (kind
 * 6) and a block through func_02074BEC (kind 1, keyed by the sixth argument),
 * releasing the handle on either failure; then attach the block's +0x18
 * payload to the handle and apply the descriptor's bytes 6 and 7.  Called by
 * func_02075560 and func_020755A8 with the record pointer as s0 and the
 * record id as s1.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02075698.c \
 *       --func func_02075698 --addr 0x02075698 --arm --cc ../2.0/sp2
 *   EXACT, 252 bytes, 10 of 10 relocation sites resolved (sp2p2 EXACT too,
 *   dsi/1.1p1 260 bytes DIFF).
 *
 * symbols:
 *   func_02073344  0x02073344  arm
 *   func_020734AC  0x020734AC  arm
 *   func_02074CD0  0x02074CD0  arm
 *   func_02074BEC  0x02074BEC  arm
 *   func_020733DC  0x020733DC  arm
 *   func_020733E8  0x020733E8  arm
 *   NNS_SndHandleSetPlayerPriority  0x02072F48  arm
 *   NNS_SndHandlePause  0x02072F88  arm
 *   func_020730B8  0x020730B8  arm
 */
#include "../include/Obj16686.h"
typedef unsigned char u8;
typedef unsigned int  u32;

typedef signed int     s32;
struct Node;
struct Obj;
extern struct Node *func_02073344(struct Obj *o, s32 idx, s32 pri);
extern void *func_020734AC(s32 idx, void *owner);
extern u32   func_02074CD0(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern u32 func_02074BEC(u32 a, u32 b, u32 c, u32 d, u32 *out);
extern void  func_020733DC(void *h);
extern void func_020733E8(struct Obj *o, const void *seqBase, u32 seqOffset, const void *bankData);
extern void NNS_SndHandleSetPlayerPriority(struct Obj *o, u8 v);
extern void NNS_SndHandlePause(struct Obj *o, u32 v);
extern void  func_020730B8(u32 a, u32 b);

u32 func_02075698(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u32 s1)
{
    void *h;
    u32 v;
    u8 *blk;
    u32 slot;

    h = func_02073344((struct Obj *)a0, a1, a3);
    if (h == 0) {
        return 0;
    }
    v = (u32)func_020734AC(a1, h);
    if (func_02074CD0(a2, 6, v, 0, &slot) != 0) {
        func_020733DC(h);
        return 0;
    }
    if (func_02074BEC(s1, 1, v, 0, (u32 *)(&blk)) != 0) {
        func_020733DC(h);
        return 0;
    }
    func_020733E8(h, (u32 *)(blk + ((struct Obj16686 *)blk)->f18), 0, (const void *)slot);
    NNS_SndHandleSetPlayerPriority((struct Obj *)a0, s0[6]);
    NNS_SndHandlePause((struct Obj *)a0, s0[7]);
    func_020730B8(a0, s1);
    return 1;
}
