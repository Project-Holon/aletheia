/*
 * function: SCRCMD_MUSICAL_TaskStartMusical
 * address: 0x0215DE58
 * packet: pkt_ov010_0215DE58
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Padding: two zero alignment bytes after the 150-byte function.
 * Lever: context remains live in r0 across the switch for GAME_DATA_GetBgmInfo(p).
 * symbols:
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_EVENT_CallEvent 0x02012374 thumb
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   SCRCMD_MUSICAL_CloseCommSession 0x0215DE44 thumb ov010
 *   SCRCMD_MUSICAL_DeleteLinkWork 0x0215DE0C thumb ov010
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GAMESYSTEM_TryStartAutoComm 0x020121CC thumb
 */
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; } Ctx;
struct BigObj;
struct Ctx;
struct IcaAnime;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void SCRCMD_MUSICAL_CloseCommSession(int a0);
extern void SCRCMD_MUSICAL_DeleteLinkWork(void *w, void *h);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *);
extern u32 GAME_COMM_GetKind(void *obj);
extern int GFL_NET_IsSessionNull(void);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
int SCRCMD_MUSICAL_TaskStartMusical(void *a, u32 *st, Ctx *c)
{
    void *p;
    p = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(a));
    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent(a, (struct Evt **)c->f0);
        (*st)++;
        break;
    case 1:
        GAME_DATA_GetBgmInfo(p);
        SCRCMD_MUSICAL_CloseCommSession(c->f4);
        (*st)++;
        break;
    case 2:
        {
            void *q = (void *)GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(a));
            if (c->f8 != 0) {
                if (GAME_COMM_GetKind(q) != 0)
                    break;
            }
        }
        (*st)++;
        break;
    case 3:
        if (GFL_NET_IsSessionNull() != 1) {
            if (c->f8 != 0)
                break;
        }
        if (c->f8 == 1) {
            GAMESYSTEM_TryStartAutoComm(GAME_EVENT_GetGameSystem(a));
        }
        SCRCMD_MUSICAL_DeleteLinkWork((void *)c->f4, p);
        (*st)++;
        return 1;
    }
    return 0;
}
