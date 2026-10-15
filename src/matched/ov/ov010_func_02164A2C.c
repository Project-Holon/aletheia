/*
 * function: CALENDER_OverlaySequenceEvent
 * address:  0x02164A2C
 * packet:   pkt_ov010_02164A2C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sub-process sequence of the ov010 program: eight steps, each starting
 * one child process (two from ov021, the ov216 one through
 * GAMESYSTEM_CallProc with a 12-byte hand-off), then done. Step 2 falls
 * through into step 3.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is the
 * pooled 0x021BDB40, the ov216 process template, which has no other
 * reference in the image (ov216_id itself resolves by the overlay_id
 * class).
 *
 * symbols:
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_SOUND_SYSTEM_StartPushAndChangeTask  0x020297AC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_SOUND_SYSTEM_StartPopTask  0x02029690  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   FIELD_SUBSCREEN_ChangeModeNow  0x021A0F40  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   ov216_id       0x000000D8  data
 *   d_021BDB40     0x021BDB40  data  a1 ov216
 
 * 2026-10-05 (D8 lane 15): the process template d_021BDB40 lives in ov216; the data line now carries the ov216 token and the relocation resolves.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SubArgs {
    void *sys;          /* 0x0C */
    u32 f04;            /* 0x10 */
    u8 f08;             /* 0x14 */
    u8 flag;            /* 0x15 */
    u8 pad[2];
} SubArgs;

typedef struct SeqWork2 {
    void *sys;          /* 0x00 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    SubArgs sub;        /* 0x0C */
    u8 f18;             /* 0x18 */
} SeqWork2;

struct Ctx;
struct Evt;
struct IcaAnime;
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *ICA_ANIME_GetField20(const struct Ctx *p);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_SOUND_SYSTEM_StartPushAndChangeTask(void *sys, u32 a, u32 b, u32 c);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void *FIELD_SOUND_SYSTEM_StartPopTask(void *sys, u32 a, u32 b);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *sys);
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern void FIELD_SUBSCREEN_ChangeModeNow(u32 *p, u32 v);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *sys);
extern u8 ov216_id[];
extern const u8 d_021BDB40[];

int CALENDER_OverlaySequenceEvent(void *evt, u32 *seq, SeqWork2 *w)
{
    void *sys;
    void *p;

    sys = w->sys;
    ICA_ANIME_GetField1C(sys);
    p = ICA_ANIME_GetField20(sys);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(evt, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut(sys, (int)p, 0, 0));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)sys, (int)p));
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPushAndChangeTask(sys, 0x483, 6, 0));
        (*seq)++;
    case 3:
        MI_CpuFill8(&w->sub, 0, sizeof(SubArgs));
        w->sub.sys = w->sys;
        w->sub.f04 = w->f04;
        w->sub.f08 = w->f18;
        GAMESYSTEM_CallProc(sys, (u32)ov216_id, (void *)d_021BDB40, &w->sub);
        (*seq)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(sys) == 0) {
            GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartPopTask(sys, 6, 0x3C));
            (*seq)++;
        }
        break;
    case 5:
        GAME_EVENT_CallEvent(evt, FIELD_STATUS_CreateFieldOpenEvent(sys));
        (*seq)++;
        break;
    case 6:
        if (w->sub.flag != 0)
            FIELD_SUBSCREEN_ChangeModeNow((u32 *)FIELDMAP_GetSubscreen(p), 0);
        GAME_EVENT_CallEvent(evt, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn(sys, (int)p, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(evt, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(sys));
        (*seq)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}
