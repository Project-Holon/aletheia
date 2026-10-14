/*
 * function: BTLV_EFFECT_DamageTintTaskMain
 * address:  0x021F8BAC
 * packet:   pkt_ov094_021F8BAC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gBtlvEff 0x0220AF20 data ov094 a4
 *   BTLV_MCSS_SetPaletteFade 0x021FFDB4 thumb ov094
 *   BTLV_MCSS_SetVanishMode 0x021FF374 thumb ov094
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
extern char *gBtlvEff;
extern void BTLV_MCSS_SetPaletteFade(void *, int, u8, u8, s8, u32);
extern void BTLV_MCSS_SetVanishMode(void *, int, int);
extern void BTLV_EFFECT_DeleteTask(void *);

void BTLV_EFFECT_DamageTintTaskMain(void *h, int *p)
{
    if (p[3] != 0) {
        p[3]--;
        return;
    }
    switch (p[1]) {
    case 0:
        if (p[5] == 0)
            BTLV_MCSS_SetPaletteFade(*(void **)(gBtlvEff + 0x190), p[0], 16, 16, 0, p[4]);
        p[3] = 3;
        p[1] = 1;
        break;
    case 1:
        if (p[5] == 0)
            BTLV_MCSS_SetVanishMode(*(void **)(gBtlvEff + 0x190), p[0], 1);
        p[3] = 3;
        p[1] = 2;
        break;
    case 2:
        p[1] = 0;
        if (p[5] == 0) {
            BTLV_MCSS_SetVanishMode(*(void **)(gBtlvEff + 0x190), p[0], 0);
            BTLV_MCSS_SetPaletteFade(*(void **)(gBtlvEff + 0x190), p[0], 0, 0, 0, 0x7fff);
        }
        p[3] = 3;
        if (--p[2] == 0)
            BTLV_EFFECT_DeleteTask(h);
        break;
    }
}
