/*
 * function: func_021A8324
 * address:  0x021A8324
 * packet:   pkt_ov021_021A8324
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int pad10[10];
    int f38;
    int f3c;
    int f40;
} R;

struct Evt;
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void func_021A8324(int a, R **r)
{
    R *p = *r;
    int t;
    if (p->f40 != 0) {
        t = EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)p->f4, p->fc, 0, 0);
    } else {
        t = EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)p->f4, p->fc, p->f38, 0);
    }
    GAME_EVENT_CallEvent((struct Evt *)a, (struct Evt **)t);
}
