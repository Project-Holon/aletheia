/*
 * function: BTLV_MCSS_TakeSpriteRefreshedFlag
 * address:  0x022005C4
 * packet:   pkt_ov094_022005C4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 */
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 9;    /* 0x4c */
    unsigned int f9 : 1;
    unsigned int hi : 22;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);

int BTLV_MCSS_TakeSpriteRefreshedFlag(Work *w, int key)
{
    int i = BTLV_MCSS_FindSpriteIndex((char *)w, key);
    int r;

    if (i == -1)
        return 0;
    if (w->e[i].h == 0)
        return 0;
    if (w->e[i].f9)
        r = 1;
    else
        r = 0;
    w->e[i].f9 = 0;
    return r;
}
