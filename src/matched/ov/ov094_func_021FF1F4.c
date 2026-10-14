/*
 * function: BTLV_MCSS_EnableBillboard
 * address:  0x021FF1F4
 * packet:   pkt_ov094_021FF1F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   MCSS_SetOrthoBillboardFlag  0x02015C0C  thumb
 *   BTLV_MCSS_ApplySlotScale  0x022006B4  thumb  ov094
 */

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_SetOrthoBillboardFlag(void *h);
extern void BTLV_MCSS_ApplySlotScale(Work *w, int key);

void BTLV_MCSS_EnableBillboard(Work *w, int key)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return;
    w->e[idx].flip = 1;
    MCSS_SetOrthoBillboardFlag(w->e[idx].h);
    BTLV_MCSS_ApplySlotScale(w, key);
}
