/*
 * function: BTLV_EFFECT_DeleteTasksByArg
 * address:  0x021F8A10
 * packet:   pkt_ov094_021F8A10
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs BTLV_EFFECT_DeleteTask on each live object owned by a.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 */
typedef struct {
    char pad[8];
    void *obj[32];          /* 0x008 */
    char pad88[0x108 - 0x88];
    int owner[32];          /* 0x108 */
} Work;

extern Work *gBtlvEff;
extern void BTLV_EFFECT_DeleteTask(void *);

void BTLV_EFFECT_DeleteTasksByArg(int a)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (gBtlvEff->obj[i] != 0 && a == gBtlvEff->owner[i])
            BTLV_EFFECT_DeleteTask(gBtlvEff->obj[i]);
    }
}
