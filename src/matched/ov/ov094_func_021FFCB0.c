/*
 * function: BTLV_MCSS_IsSpriteBusy
 * address:  0x021FFCB0
 * packet:   pkt_ov094_021FFCB0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_CheckPaletteFade  0x0201600C  thumb
 *   BTLV_EFFECT_GetBitMask  0x021F935C  thumb  ov094
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 */
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;              /* 0x514 */
    int m518;               /* 0x518 */
    int m51c;               /* 0x51c */
    int m520;               /* 0x520 */
    int m524;               /* 0x524 */
    int m528;               /* 0x528 */
    int m52c;               /* 0x52c */
    int m530;               /* 0x530 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern int MCSS_CheckPaletteFade(void *h);
extern int BTLV_EFFECT_GetBitMask(int x);

int BTLV_MCSS_IsSpriteBusy(Work *w, int key)
{
    int r = 0;

    if (BTLV_MCSS_IsSpriteLoaded((char *)w, key))
        r = MCSS_CheckPaletteFade(w->e[BTLV_MCSS_FindSpriteIndex((char *)w, key)].h);
    if (BTLV_EFFECT_GetBitMask(key) & w->m514
        || BTLV_EFFECT_GetBitMask(key) & w->m518
        || BTLV_EFFECT_GetBitMask(key) & w->m524
        || BTLV_EFFECT_GetBitMask(key) & w->m520
        || BTLV_EFFECT_GetBitMask(key) & w->m51c
        || BTLV_EFFECT_GetBitMask(key) & w->m528
        || BTLV_EFFECT_GetBitMask(key) & w->m52c
        || BTLV_EFFECT_GetBitMask(key) & w->m530
        || w->f510
        || r)
        return 1;
    return 0;
}
