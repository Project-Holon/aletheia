/*
 * function: BTLV_MCSS_BlinkTaskMain
 * address:  0x02200CD0
 * packet:   pkt_ov094_02200CD0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 *   BTLV_MCSS_SetBlinkMode  0x021FF260  thumb  ov094
 *   BTLV_MCSS_IsSpriteLoaded  0x021FFD9C  thumb  ov094
 *
 * Task callback.
 */
typedef unsigned char u8;

typedef struct {
    char pad000[0x588];
    u8 tag[1];              /* 0x588 */
} Work;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x3c];
    int wait;               /* 0x44 */
    int reload;             /* 0x48 */
    int count;              /* 0x4c */
    int tag;                /* 0x50 */
} Ctx;

extern void BTLV_EFFECT_DeleteTask(void *h);
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern void BTLV_MCSS_SetBlinkMode(Work *w, int key, int kind);

void BTLV_MCSS_BlinkTaskMain(void *h, Ctx *c)
{
    Work *w = c->w;

    if (BTLV_MCSS_IsSpriteLoaded((char *)w, c->key) == 0 || c->tag != w->tag[c->key]) {
        BTLV_EFFECT_DeleteTask(h);
        return;
    }
    if (c->wait == 0) {
        c->wait = c->reload;
        BTLV_MCSS_SetBlinkMode(c->w, c->key, 2);
        if (--c->count == 0) {
            BTLV_MCSS_SetBlinkMode(c->w, c->key, 0);
            BTLV_EFFECT_DeleteTask(h);
        }
    } else {
        c->wait--;
    }
}
