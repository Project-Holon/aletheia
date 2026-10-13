/*
 * function: EVENT_COMM_COMMON_MissionInfoEventMain
 * address:  0x0217F95C
 * packet:   pkt_ov018_0217F95C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   EVENT_COMM_COMMON_InitMsgBox  0x0217F2B4  thumb  ov018
 *   EVENT_COMM_COMMON_GetMissionState  0x0217F5A0  thumb  ov018
 *   EVENT_COMM_COMMON_PrintListWindow  0x0217F4A0  thumb  ov018
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   INTRUDE_FIELD_CreateOfferInfoEvent  0x0217C458  thumb  ov018
 *   EVENT_COMM_COMMON_FreeMissionInfoWork  0x0217FA1C  thumb  ov018
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 */

typedef unsigned char u8;

struct Desc;

typedef unsigned int   u32;
struct Ctx;
struct Obj;
void *GAME_EVENT_GetGameSystem(struct Obj *p);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void EVENT_COMM_COMMON_InitMsgBox(void *a0, void *a1);
int EVENT_COMM_COMMON_GetMissionState(void *p);
void EVENT_COMM_COMMON_PrintListWindow(void **p, unsigned int index, int a, int b);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
struct Desc *INTRUDE_FIELD_CreateOfferInfoEvent(void *a0, void *a1, u8 *a2, int a3);
void EVENT_COMM_COMMON_FreeMissionInfoWork(void *p);
struct S0201235C;
void GAME_EVENT_ChangeEvent(struct S0201235C *o, u32 *out);

int EVENT_COMM_COMMON_MissionInfoEventMain(void *a0, int *state, void *a2)
{
    void *h;
    u8 *w;
    struct Desc *r;

    h = GAME_EVENT_GetGameSystem(a0);
    w = (u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(h));
    if (w == 0 && *state < 3) {
        *state = 3;
    }
    switch (*state) {
    case 0:
        w[0x93F] |= 8;
        EVENT_COMM_COMMON_InitMsgBox(a2, h);
        if (EVENT_COMM_COMMON_GetMissionState(w + 0x1AC) == 3) {
            *state = 2;
        } else {
            EVENT_COMM_COMMON_PrintListWindow(a2, 0x1A, 0, 0);
            (*state)++;
        }
        break;
    case 1:
        switch (EVENT_COMM_COMMON_GetMissionState(w + 0x1AC)) {
        case 2:
            break;
        case 3:
        default:
            (*state)++;
            break;
        }
        break;
    case 2:
        r = INTRUDE_FIELD_CreateOfferInfoEvent(h, GAMESYSTEM_GetFieldMap(h), w, 0x15);
        EVENT_COMM_COMMON_FreeMissionInfoWork(a2);
        GAME_EVENT_ChangeEvent(a0, (u32 *)r);
        return 0;
    case 3:
        EVENT_COMM_COMMON_FreeMissionInfoWork(a2);
        return 1;
    }
    return 0;
}
