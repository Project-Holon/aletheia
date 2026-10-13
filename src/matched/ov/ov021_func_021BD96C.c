/*
 * function: EVENT_ENTRANCE_IN_StartBgmFadeOut
 * address:  0x021BD96C
 * packet:   pkt_ov021_021BD96C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StartFadeOutTask  0x0202952C  thumb  arm9
 */

typedef struct {
    char pad[4];
    void *f4;
    char pad2[0x44];
    int f4C;
} Inner;

typedef struct {
    char pad[8];
    Inner *f8;
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
extern u8 *FIELD_SOUND_SYSTEM_StartFadeOutTask(u8 *p, u32 a);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void EVENT_ENTRANCE_IN_StartBgmFadeOut(Obj *p, void *b)
{
    Inner *q = p->f8;

    GAME_EVENT_CallEvent(b, (struct Evt **)FIELD_SOUND_SYSTEM_StartFadeOutTask(q->f4, 0x1E));
    q->f4C = 1;
}
