/*
 * function: BTLV_BG_ScrollTask
 * address:  0x022099E8
 * packet:   pkt_ov094_022099E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   BTLV_BG_SetScroll  0x02209784  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 */
typedef unsigned char u8;

typedef struct {
    void *w;                /* 0x00 */
    int x;                  /* 0x04 */
    int y;                  /* 0x08 */
    int pad0c;
    int mv[4];              /* 0x10 */
    int dx;                 /* 0x20 */
    int dy;                 /* 0x24 */
    char pad28[0x38 - 0x28];
    int n;                  /* 0x38 */
} S;

extern int BTLV_EFFECT_StepMover(void *m, int *out);
extern void BTLV_BG_SetScroll(void *w, int x, int y);
extern void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_BG_ScrollTask(void *h, S *s)
{
    void *w = s->w;
    int done;

    if (s->mv[0] == 4) {
        s->x += s->dx;
        s->y += s->dy;
        if (s->n == 0) {
            done = 1;
        } else {
            s->n--;
            done = 0;
        }
    } else {
        done = BTLV_EFFECT_StepMover(s->mv, &s->x);
    }
    BTLV_BG_SetScroll(w, s->x >> 12, s->y >> 12);
    if (done == 1)
        BTLV_EFFECT_DeleteTask(h);
}
