/*
 * function: BTLV_EFFECT_DeleteAllTasks
 * address:  0x021F8B6C
 * packet:   pkt_ov094_021F8B6C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs BTLV_EFFECT_DeleteTask on each of the 32 live objects at 8 of the global work block.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 */
extern char *gBtlvEff;
extern void BTLV_EFFECT_DeleteTask(void *);

void BTLV_EFFECT_DeleteAllTasks(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (((void **)(gBtlvEff + 8))[i] != 0)
            BTLV_EFFECT_DeleteTask(((void **)(gBtlvEff + 8))[i]);
    }
}
