/*
 * function: BTLV_MCSS_SetMosaic
 * address:  0x02200108
 * packet:   pkt_ov094_02200108
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   MCSS_TOOL_SetSpindaSpotHook  0x020172AC  thumb
 *   MCSS_SetMosaic  0x02016078  thumb
 */

typedef struct {
    int w[9];
} Rec;

typedef struct {
    void *h;                /* 0x00 */
    Rec rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1);
extern void MCSS_SetMosaic(void *obj, void *h, int v);

void BTLV_MCSS_SetMosaic(Work *w, int key, int v)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_TOOL_SetSpindaSpotHook((int)w->obj, w->e[idx].k34);
    MCSS_SetMosaic(w->obj, w->e[idx].h, v);
}
