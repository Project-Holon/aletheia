/*
 * function: BTLV_MCSS_Delete
 * address:  0x021FEB78
 * packet:   pkt_ov094_021FEB78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *   BTLV_MCSS_RemoveSprite  0x021FF0F8  thumb  ov094
 *   MCSS_Exit  0x02014BA8  thumb
 *   func_020307B0  0x020307B0  arm
 */
typedef enum { KEY_0 } Key;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern void BTLV_MCSS_RemoveSprite(Work *w, int key);
typedef unsigned char  u8;
extern void MCSS_Exit(u8 *a0);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BTLV_MCSS_Delete(Work *w)
{
    Key i;

    for (i = 0; i < 14; i++) {
        if (BTLV_MCSS_IsSpriteLoaded((char *)w, i))
            BTLV_MCSS_RemoveSprite(w, i);
    }
    MCSS_Exit(w->obj);
    func_020307B0(w);
}
