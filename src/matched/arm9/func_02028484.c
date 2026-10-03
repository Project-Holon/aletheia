/*
 * unit:     no
 * function: func_02028484
 * address:  0x02028484
 * packet:   pkt_02028484
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_020284F4  0x020284F4  thumb
 *   func_02028528  0x02028528  thumb
 *   func_0202855C  0x0202855C  thumb
 *
 * Per-frame service step for one handle attached to a state block: reads
 * the handle's state word with func_0201CE30 and dispatches on it as a
 * switch. State 1 finishes the handle (func_020284F4 on the block's flags
 * word, then a fixed-id notify through func_020061E4 and a teardown call);
 * state 0 runs a two-phase step, gated on bit 10 of the same flags word,
 * where func_0202855C latches the block's first byte and func_02028528
 * later releases the handle. Both state-0 callees take the flags word in
 * r0, which is what pins it there across the whole arm and pushes the mask
 * and the byte test into r1. State 2, and a null handle, return 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02028484.c \
 *       --func func_02028484 --addr 0x02028484 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct Blk {
    u8  first;
    u8  pad[3];
    u32 flags;
} Blk;

extern u32 func_0201CE30(void *h);
extern void func_0201CE38(void *h);
struct Rec;
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_020061E4(u32 id);
extern u32 func_020284F4(u32 a);
extern u32 func_02028528(u32 a);
extern u32 func_0202855C(u32 a);

s32 func_02028484(Blk *blk, void *h)
{
    u32 mask;

    if (h != 0) {
        switch (func_0201CE30(h)) {
        case 2:
            return 1;
        case 1:
            if (func_020284F4(blk->flags) != 0) {
                func_020061E4(0x547);
                func_0201CE38(h);
            }
            break;
        case 0:
            mask = 1 << 10;
            if ((mask & blk->flags) == 0) {
                if (blk->first == 0) {
                    if (func_0202855C(blk->flags) != 0) {
                        blk->first = 1;
                    }
                } else {
                    if (func_02028528(blk->flags) != 0) {
                        func_0201CE5C(h, 0);
                    }
                }
            }
            break;
        }
        return 0;
    }
    return 1;
}
