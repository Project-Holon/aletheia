/*
 * unit:     no
 * function: PRINTSYS_CTRL_Update
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
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PRINTSYS_CTRL_IsInputTrg  0x020284F4  thumb
 *   PRINTSYS_CTRL_IsInputCont  0x02028528  thumb
 *   PRINTSYS_CTRL_IsInputIdle  0x0202855C  thumb
 *
 * Per-frame service step for one handle attached to a state block: reads
 * the handle's state word with PRINTSYS_PrintStreamGetState and dispatches on it as a
 * switch. State 1 finishes the handle (PRINTSYS_CTRL_IsInputTrg on the block's flags
 * word, then a fixed-id notify through GFL_USE_PlaySeDefaultVolume and a teardown call);
 * state 0 runs a two-phase step, gated on bit 10 of the same flags word,
 * where PRINTSYS_CTRL_IsInputIdle latches the block's first byte and PRINTSYS_CTRL_IsInputCont
 * later releases the handle. Both state-0 callees take the flags word in
 * r0, which is what pins it there across the whole arm and pushes the mask
 * and the byte test into r1. State 2, and a null handle, return 1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_CTRL_Update.c \
 *       --func PRINTSYS_CTRL_Update --addr 0x02028484 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

typedef struct Blk {
    u8  first;
    u8  pad[3];
    u32 flags;
} Blk;

extern u32 PRINTSYS_PrintStreamGetState(void *h);
extern void PRINTSYS_PrintStreamReleasePause(void *h);
struct Rec;
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern u32 PRINTSYS_CTRL_IsInputTrg(u32 a);
extern u32 PRINTSYS_CTRL_IsInputCont(u32 a);
extern u32 PRINTSYS_CTRL_IsInputIdle(u32 a);

s32 PRINTSYS_CTRL_Update(Blk *blk, void *h)
{
    u32 mask;

    if (h != 0) {
        switch (PRINTSYS_PrintStreamGetState(h)) {
        case 2:
            return 1;
        case 1:
            if (PRINTSYS_CTRL_IsInputTrg(blk->flags) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(h);
            }
            break;
        case 0:
            mask = 1 << 10;
            if ((mask & blk->flags) == 0) {
                if (blk->first == 0) {
                    if (PRINTSYS_CTRL_IsInputIdle(blk->flags) != 0) {
                        blk->first = 1;
                    }
                } else {
                    if (PRINTSYS_CTRL_IsInputCont(blk->flags) != 0) {
                        PRINTSYS_PrintStreamShortWait(h, 0);
                    }
                }
            }
            break;
        }
        return 0;
    }
    return 1;
}
