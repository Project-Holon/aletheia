/*
 * function: BTLV_EFFVM_SetShadowVanishIfLoaded
 * address:  0x021FE520
 * packet:   pkt_ov094_021FE520
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *   BTLV_MCSS_SetShadowVanish  0x021FF470  thumb  ov094
 */
typedef enum { KEY_0 } Key;

extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
typedef unsigned char u8;

extern void BTLV_MCSS_SetShadowVanish(char *p, int key, void *v);

void BTLV_EFFVM_SetShadowVanishIfLoaded(void)
{
    Key i;

    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded((char *)BTLV_EFFECT_GetMcss(), i) == 1)
            BTLV_MCSS_SetShadowVanish((char *)BTLV_EFFECT_GetMcss(), i, 0);
    }
}
