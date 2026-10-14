/*
 * function: BTLV_MCSS_GetStopCellFlags
 * address:  0x021FFFAC
 * packet:   pkt_ov094_021FFFAC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   MCSS_GetStopCellFlags  0x02015F24  thumb
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
extern int MCSS_GetStopCellFlags(void *h);

int BTLV_MCSS_GetStopCellFlags(Work *w, int key)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return MCSS_GetStopCellFlags(w->e[idx].h);
}
