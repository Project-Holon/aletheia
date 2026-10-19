/*
 * function: EVENT_COMM_COMMON_ReturnPalaceEventMain
 * address:  0x0217FA38
 * packet:   pkt_ov018_0217FA38
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   INTRUDE_COMM_GetRequesterNetId  0x02176230  thumb  ov011
 *   INTRUDE_SUBDISP_CreateTownWarpEvent  0x0217CE08  thumb  ov018
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   EVENT_COMM_COMMON_CreateMissionInfoEvent  0x0217F938  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
struct Ctx;
struct Evt;
struct Obj;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
u8 INTRUDE_COMM_GetRequesterNetId(u8 *p, u8 *q);
void *INTRUDE_SUBDISP_CreateTownWarpEvent(void *a, void *b, int c, int d);
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
u32 ZONEDATA_IsEntralink(u32 id);
void *EVENT_COMM_COMMON_CreateMissionInfoEvent(void *);

int EVENT_COMM_COMMON_ReturnPalaceEventMain(void *a, int *state)
{
    void *s;
    u32 h;
    void *p2;
    void *p3;
    u8 *w;
    void *r;

    s = GAME_EVENT_GetGameSystem(a);
    h = GAMESYSTEM_GetGameComm(s);
    p2 = GAMESYSTEM_GetGameData(s);
    p3 = GAMESYSTEM_GetFieldMap(s);
    w = (u8 *)INTRUDE_COMM_GetWorkIfRunning(h);
    switch (*state) {
    case 0:
        if (w == 0) {
            GAME_DATA_GetOwnNetId(p2);
        } else {
            INTRUDE_COMM_GetRequesterNetId(w, w + 0x1AC);
        }
        r = INTRUDE_SUBDISP_CreateTownWarpEvent(s, p3, 0x117, 1);
        if (r == 0) {
            return 1;
        }
        GAME_EVENT_CallEvent(a, r);
        (*state)++;
        break;
    case 1:
        if (ZONEDATA_IsEntralink(GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork(s))) == 1) {
            GAME_EVENT_CallEvent(a, EVENT_COMM_COMMON_CreateMissionInfoEvent(s));
        }
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
