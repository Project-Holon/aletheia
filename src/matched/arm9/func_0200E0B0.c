/*
 * function: SYMBOL_SAVE_GetBlock
 * address:  0x0200E0B0
 * packet:   pkt_0200E0B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: tail-calls func_020071CC(p, 0x3d).
 *
 * symbols:
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   func_020071CC  0x020071CC  thumb
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *SYMBOL_SAVE_GetBlock(void *p)
{
    return func_020071CC(p, 0x3d);
}
