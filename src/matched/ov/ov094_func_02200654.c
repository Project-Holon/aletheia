/*
 * function: BTLV_MCSS_RestoreVanishStates
 * address:  0x02200654
 * packet:   pkt_ov094_02200654
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_MCSS_SetVanishMode  0x021FF374  thumb  ov094
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 */
typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 5;    /* 0x4c */
    unsigned int f5 : 1;
    unsigned int mid : 4;
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern void BTLV_MCSS_SetVanishMode(Work *w, int key, int kind);

void BTLV_MCSS_RestoreVanishStates(Work *w)
{
    Slot i;
    int j;

    for (i = 0; i < 8; i++) {
        if (BTLV_MCSS_IsSpriteLoaded((char *)w, i)) {
            j = BTLV_MCSS_FindSpriteIndex((char *)w, i);
            BTLV_MCSS_SetVanishMode(w, i, w->e[j].f10);
            w->e[j].f5 = 0;
        }
    }
}
