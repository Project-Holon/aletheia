/*
 * function: EVENT_ENTRANCE_IN_CallFadeOut
 * address:  0x021BD988
 * packet:   pkt_ov021_021BD988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 */

typedef struct {
    int f0;
    void *f4;
    int f8;
    int fC;
    char pad10[0x28];
    int f38;
    int f3C;
    int f40;
} Sub;

typedef struct {
    int f0;
    int f4;
    Sub *f8;
} Obj;

extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void EVENT_ENTRANCE_IN_CallFadeOut(Obj *o, int b)
{
    Sub *s = o->f8;
    int sel = s->f40;
    void *p = s->f4;
    int c = s->fC;

    if (sel != 0) {
        GAME_EVENT_CallEvent((struct Evt *)b, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut(p, c, 0, 0));
    } else {
        GAME_EVENT_CallEvent((struct Evt *)b, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut(p, c, s->f38, 0));
    }
}
