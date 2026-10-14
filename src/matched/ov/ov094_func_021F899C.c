/*
 * function: BTLV_EFFECT_FindTaskIndex
 * address:  0x021F899C
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 */
typedef struct {
    char pad[8];
    void *handle[32];      /* 0x008 */
    void (*cb[32])(void *); /* 0x088 */
    int arg[32];           /* 0x108 */
} Work;

extern Work *gBtlvEff;

int BTLV_EFFECT_FindTaskIndex(void *h)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (gBtlvEff->handle[i] == h)
            break;
    }
    return i;
}
