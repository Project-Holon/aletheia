/*
 * function: BTLV_EFFECT_StartEffectWithValue
 * address:  0x021F7D44
 * packet:   pkt_ov094_021F7D44
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Queues request 0x23d with value b on the handle at 0x188, then sets the word at 0x1e8 to 1.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTLV_EFFVM_InitParams 0x021F9844 thumb ov094
 *   BTLV_EFFVM_StartScript 0x021F94F8 thumb ov094
 */
typedef struct {
    int w[3];
    unsigned short v;
} Req;

extern char *gBtlvEff;
extern void BTLV_EFFVM_InitParams(Req *);
extern void BTLV_EFFVM_StartScript(void *, int, int, int, Req *);

void BTLV_EFFECT_StartEffectWithValue(int a, unsigned short b)
{
    Req req;

    BTLV_EFFVM_InitParams(&req);
    req.v = b;
    BTLV_EFFVM_StartScript(*(void **)(gBtlvEff + 0x188), 0, a, 0x23d, &req);
    *(int *)(gBtlvEff + 0x1e8) = 1;
}
