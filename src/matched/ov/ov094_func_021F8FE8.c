/*
 * function: BTLV_EFFECT_DelayedStartEffectTaskMain
 * address:  0x021F8FE8
 * packet:   pkt_ov094_021F8FE8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   BTLV_EFFVM_StartScript  0x021F94F8  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x188];
    void *h;            /* 0x188 */
    char pad2[0x5C];
    int flag;           /* 0x1E8 */
} Work;

typedef struct {
    int pad0;
    int a;              /* 4 */
    u32 b;              /* 8 */
    u32 c;              /* 0xC */
    void *d;            /* 0x10 */
} Arg;

extern Work *gBtlvEff;

extern int BTLV_EFFECT_IsBusy(void);
extern void BTLV_EFFVM_StartScript(void *h, int a, u32 b, u16 c, void *d);
extern void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_EFFECT_DelayedStartEffectTaskMain(void *h, Arg *p)
{
    if (BTLV_EFFECT_IsBusy() == 0) {
        BTLV_EFFVM_StartScript(gBtlvEff->h, p->a, p->b, p->c, p->d);
        gBtlvEff->flag = 1;
        BTLV_EFFECT_DeleteTask(h);
    }
}
