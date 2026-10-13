/*
 * function: GAME_DATA_GetSaveBlock3A
 * address:  0x02012EF0
 * packet:   pkt_02012EF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb tail-call thunk: SAVE_CONTROL_GetBlock(*p, 0x3a).
 *
 * symbols:
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

void *GAME_DATA_GetSaveBlock3A(void **p)
{
    return SAVE_CONTROL_GetBlock(*p, 0x3a);
}
