/*
 * function: BTLV_BG_ApplyScrollTask
 * address:  0x02209A54
 * packet:   pkt_ov094_02209A54
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Task callback passed to func_020056A0 by BTLV_BG_SetScroll (leaf of that
 * caller: its pool word 0x02209A55 names this unlabelled Thumb function).
 *
 * symbols:
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 */
struct S02030EE8;
extern unsigned int TCBL_IsDeletePending(struct S02030EE8 *p);
typedef unsigned int   u32;
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_BG_ApplyScrollTask(void *h)
{
    int *p = (int *)TCBL_IsDeletePending(h);

    BG_SYS_ChangeScrollImmediate(3, 0, p[0]);
    BG_SYS_ChangeScrollImmediate(3, 3, p[1]);
    BTLV_EFFECT_DeleteTask(h);
}
