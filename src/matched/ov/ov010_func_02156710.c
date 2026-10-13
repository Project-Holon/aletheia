/*
 * function: MUSICAL_EVENT_RunLeaveSequence
 * address:  0x02156710
 * packet:   pkt_ov010_02156710
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_StartPopTask  0x02029690  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb  arm9
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
extern void *FIELD_SOUND_SYSTEM_StartPopTask(void *a, u32 b, u32 c);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *a);

int MUSICAL_EVENT_RunLeaveSequence(void *evt, Seq *s)
{
    GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(s->f00));
    switch (s->state) {
    case 0:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPopTask(s->f00, 0, 0x3C));
        s->state++;
        break;
    case 1:
        GAME_EVENT_CallEvent(evt, FIELD_STATUS_CreateFieldOpenEvent(s->f00));
        s->state++;
        break;
    case 2:
        s->state++;
        break;
    case 3:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(s->f00));
        s->state++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
