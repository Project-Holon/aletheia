/*
 * function: FIELD_GROUND_ANIME_CallEnterEvent
 * address:  0x021A82D8
 * packet:   pkt_ov021_021A82D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef unsigned char u8;

typedef struct Src {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    u8 pad10[0x3C - 0x10];
    int f3C;
    int f40;
    u8 f44;
    u8 f45;
} Src;

extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void FIELD_GROUND_ANIME_CallEnterEvent(void *a, Src **pp)
{
    Src *s;
    void *r;

    s = *pp;
    if (s->f40 != 0) {
        r = (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(s->f04, (int)s->f0C, 3, 0, 0, s->f44, s->f45);
    } else {
        r = (void *)EVENT_FIELDMAP_CONTROL_StartFadeIn(s->f04, (int)s->f0C, s->f3C, 0, 1, 0, 0);
    }
    GAME_EVENT_CallEvent(a, r);
}
