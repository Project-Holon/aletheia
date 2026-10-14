/*
 * function: BTLV_MCSS_StartPaletteTrans
 * address:  0x021FFDF8
 * packet:   pkt_ov094_021FFDF8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   MCSS_CreatePaletteTransTask  0x020160D4  thumb
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
extern void MCSS_CreatePaletteTransTask(void *obj, void *h, int a, int b);

void BTLV_MCSS_StartPaletteTrans(Work *w, int key, int a, int b)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_CreatePaletteTransTask(w->obj, w->e[idx].h, a, b);
}
