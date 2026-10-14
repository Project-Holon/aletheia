/*
 * function: BTLV_EFFECT_StartIntroEffect
 * address:  0x021F8A78
 * packet:   pkt_ov094_021F8A78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   BTLV_EFFECT_PauseVm  0x021F7BEC  thumb  ov094
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   BTLV_EFFECT_StartEffect  0x021F7998  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x1E4];
    void *battle;       /* 0x1E4 */
    char pad2[0x50];
    int state;          /* 0x238 */
} Work;

extern Work *gBtlvEff;

extern void BTLV_EFFECT_PauseVm(void);
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern void BTLV_EFFECT_StartEffect(u32 a);

void BTLV_EFFECT_StartIntroEffect(void)
{
    BTLV_EFFECT_PauseVm();
    if (gBtlvEff->state == 3 && BTL_MAIN_CheckSetupStatusFlag(gBtlvEff->battle, 0x400))
        BTLV_EFFECT_StartEffect(0x251);
    else
        BTLV_EFFECT_StartEffect(0x236);
    gBtlvEff->state = 0;
}
