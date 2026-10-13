/*
 * function: EVENT_ENTRANCE_OUT_StartBgmFadeIn
 * address:  0x021BDC0C
 * packet:   pkt_ov021_021BDC0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb  arm9
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StartFadeInTask  0x020294C0  thumb  arm9
 */

typedef struct {
    int pad0;
    void *f4;
    void *f8;
} Inner;

typedef struct {
    Inner *f0;
} Obj;

typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
typedef unsigned char  u8;
struct Evt;
extern u8 *FIELD_SOUND_SYSTEM_StartFadeInTask(u8 *p, u32 a);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void EVENT_ENTRANCE_OUT_StartBgmFadeIn(Obj *p, void *b)
{
    Inner *q = p->f0;
    void *r = q->f4;

    GAME_DATA_GetBgmInfo(q->f8);
    GAME_EVENT_CallEvent(b, (struct Evt **)FIELD_SOUND_SYSTEM_StartFadeInTask(r, 6));
}
