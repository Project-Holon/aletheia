/*
 * function: BTLV_MCSS_StartPaletteCopy
 * address:  0x021FFE24
 * packet:   pkt_ov094_021FFE24
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   MCSS_CreatePaletteCopyTask  0x0201624C  thumb
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
typedef unsigned char  u8;
extern void MCSS_CreatePaletteCopyTask(u8 *a0, u8 *a1);

void BTLV_MCSS_StartPaletteCopy(Work *w, int key)
{
    int idx = BTLV_MCSS_FindSpriteIndex((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_CreatePaletteCopyTask(w->obj, w->e[idx].h);
}
