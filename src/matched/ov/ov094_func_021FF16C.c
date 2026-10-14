/*
 * function: BTLV_MCSS_EnableOrthoMode
 * address:  0x021FF16C
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_SetOrthoMode   0x02015BF0  thumb
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   BTLV_MCSS_ApplySlotScale  0x022006B4  thumb  ov094
 */
typedef unsigned int u32;
typedef int fx32;
typedef long long s64;

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
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work;

extern void MCSS_SetOrthoMode(void *obj);
extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void BTLV_MCSS_ApplySlotScale(Work *w, int i);

void BTLV_MCSS_EnableOrthoMode(Work *w)
{
    int i;
    int idx;

    MCSS_SetOrthoMode(w->obj);
    w->active = 1;
    for (i = 0; i < 14; i++) {
        idx = BTLV_MCSS_FindSpriteIndex((char *)w, i);
        if (idx != -1) {
            w->e[idx].flip = 1;
            BTLV_MCSS_ApplySlotScale(w, i);
        }
    }
}
