/*
 * function: BTLV_EFFECT_UpdateIntroInput
 * address:  0x021F903C
 * packet:   pkt_ov094_021F903C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * lever: Assign table lookups to a shared local before the call; duplicated
 * calls cross-jump the indexed load and shorten the function by four bytes.
 * symbols:
 *   gBtlvEff 0x0220AF20 data ov094 a4
 *   gBtlvIntroPickTableA 0x0220AC70 data a4
 *   gBtlvIntroPickTableB 0x0220AC78 data a4
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BTLV_EFFECT_PauseVm 0x021F7BEC thumb ov094
 *   BTLV_EFFECT_StartEffect 0x021F7998 thumb ov094
 *   BTLV_EFFECT_IsBusy 0x021F7EB4 thumb ov094
 *   BTL_MAIN_CheckSetupStatusFlag 0x021BA1A8 thumb ov093
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned int u32;
typedef unsigned long long u64;
extern char *gBtlvEff;
extern u32 gBtlvIntroPickTableA[];
extern u32 gBtlvIntroPickTableB[];
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void BTLV_EFFECT_PauseVm(void);
extern void BTLV_EFFECT_StartEffect(u32);
extern int BTLV_EFFECT_IsBusy(void);
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern u32 GF_STANDARD_Rand(void);
#define WORD(k) (*(int *)(gBtlvEff + (k)))

void BTLV_EFFECT_UpdateIntroInput(void)
{
    int a, b;
    u32 n, value;
    a = KEY_GetTrg();
    b = TOUCHPANEL_GetTrg();
    if (WORD(0x238) == 0)
        return;
    if (WORD(0x238) != 2 && WORD(0x238) != 3 && (a != 0 || b != 0)) {
        BTLV_EFFECT_PauseVm();
        BTLV_EFFECT_StartEffect(0x252);
        WORD(0x23c) = 0;
        WORD(0x240) = 0;
    }
    switch (WORD(0x23c)) {
    case 0:
        if (WORD(0x240) < WORD(0x244)) {
            WORD(0x240)++;
            return;
        }
        WORD(0x23c) = 1;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            if (WORD(0x238) == 3 && BTL_MAIN_CheckSetupStatusFlag(*(void **)(gBtlvEff + 0x1e4), 0x400)) {
                do {
                    n = (u32)(((u64)GF_STANDARD_Rand() * 2) >> 32);
                } while (WORD(0x248) == n);
                WORD(0x248) = n;
                value = gBtlvIntroPickTableA[WORD(0x248)];
            } else {
                do {
                    n = (u32)(((u64)GF_STANDARD_Rand() * 6) >> 32);
                } while (WORD(0x248) == n);
                WORD(0x248) = n;
                value = gBtlvIntroPickTableB[WORD(0x248)];
            }
            BTLV_EFFECT_StartEffect(value);
            WORD(0x1e8) = 1;
        }
        break;
    }
}
