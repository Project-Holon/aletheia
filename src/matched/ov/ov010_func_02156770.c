/*
 * function: MUSICAL_EVENT_RunEnterSequence
 * address:  0x02156770
 * packet:   pkt_ov010_02156770
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELD_SOUND_SYSTEM_StartPushTask  0x020295A4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitSettledTask  0x02029C64  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Seq {
    void *f00;          /* 0x00 */
    u8 pad04[0x10 - 0x04];
    u8 state;           /* 0x10 */
    u8 pad11[3];
    u32 f14;            /* 0x14 */
    u8 pad18[0x4C - 0x18];
    u8 f4C;             /* 0x4C */
} Seq;

struct BigObj;
struct Ctx;
struct Evt;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u8 *FIELD_SOUND_SYSTEM_StartPushTask(u8 *p, u32 a);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_SOUND_SYSTEM_StartWaitSettledTask(void *a);

int MUSICAL_EVENT_RunEnterSequence(void *evt, Seq *s)
{
    void *x;

    GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(s->f00));
    x = GAMESYSTEM_GetFieldMap(s->f00);
    switch (s->state) {
    case 0:
        s->state++;
        break;
    case 1:
        GAME_EVENT_CallEvent(evt, (struct Evt **)FIELD_SOUND_SYSTEM_StartPushTask(s->f00, 30));
        s->state++;
        break;
    case 2:
        GAME_EVENT_CallEvent(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)s->f00, (int)x));
        s->state++;
        break;
    case 3:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartWaitSettledTask(s->f00));
        s->state++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
