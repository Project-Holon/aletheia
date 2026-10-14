/*
 * function: BTLV_EFFECT_RegisterTask
 * address:  0x021F896C
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_EFFECT_FindFreeTaskSlot  0x021F8B40  thumb  ov094
 */
typedef struct {
    char pad[8];
    void *handle[32];      /* 0x008 */
    void (*cb[32])(void *); /* 0x088 */
    int arg[32];           /* 0x108 */
} Work;

extern Work *gBtlvEff;

extern int BTLV_EFFECT_FindFreeTaskSlot(void);

void BTLV_EFFECT_RegisterTask(void *h, void (*cb)(void *), int arg)
{
    int i = BTLV_EFFECT_FindFreeTaskSlot();

    gBtlvEff->handle[i] = h;
    gBtlvEff->cb[i] = cb;
    gBtlvEff->arg[i] = arg;
}
