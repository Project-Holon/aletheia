/*
 * function: BTLV_MCSS_IsAnySpriteBusy
 * address:  0x021FFD6C
 * packet:   pkt_ov094_021FFD6C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *   BTLV_MCSS_IsSpriteBusy  0x021FFCB0  thumb  ov094
 */
typedef enum { KEY_0 } Key;

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

extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern int BTLV_MCSS_IsSpriteBusy(Work *w, int key);

int BTLV_MCSS_IsAnySpriteBusy(Work *w)
{
    Key i;

    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded((char *)w, i) && BTLV_MCSS_IsSpriteBusy(w, i))
            return 1;
    }
    return 0;
}
