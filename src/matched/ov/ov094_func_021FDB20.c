/*
 * function: BTLV_EFFVM_RefreshMcssOrtho
 * address:  0x021FDB20
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_EnableOrthoMode  0x021FF16C  thumb  ov094
 *   BTLV_MCSS_DisableOrthoMode  0x021FF1B0  thumb  ov094
 */
typedef struct {
    char pad[0x244];
    int f244;
} State;

extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_EnableOrthoMode(void *w);
extern void BTLV_MCSS_DisableOrthoMode(void *w);

void BTLV_EFFVM_RefreshMcssOrtho(State *s)
{
    if (s->f244 == 1)
        BTLV_MCSS_DisableOrthoMode((void *)BTLV_EFFECT_GetMcss());
    else
        BTLV_MCSS_EnableOrthoMode((void *)BTLV_EFFECT_GetMcss());
}
