/*
 * function: WIPE_SUB_RequestLineMaskFlip
 * address:  0x02022EF4
 * packet:   pkt_02022EA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WIPE_SUB_FlipLineMaskTask 0x02022F34  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 */

typedef unsigned int u32;

struct WipeSubElem;
extern void WIPE_SUB_FlipLineMaskTask(void *p, struct WipeSubElem *elems);
extern u32 GFL_USE_AddMainTask(void *callback, void *arg, u32 mask);

u32 WIPE_SUB_RequestLineMaskFlip(void *arg)
{
    return GFL_USE_AddMainTask(WIPE_SUB_FlipLineMaskTask, arg, 0x3FF);
}
