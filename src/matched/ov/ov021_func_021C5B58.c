/*
 * function: SCRCMD_NicknameEventMain
 * address:  0x021C5B58
 * packet:   pkt_ov021_021C5B58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_CreateNameInEvent  0x021C5A28  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   NAMEIN_SETUP_FreeArgs  0x0216C0C0  thumb  ov010
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Ctx;
struct Evt;
struct Sub02008C20Obj;
extern void *SCRCMD_CreateNameInEvent(void *a, u32 b, u32 c, u32 d);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int NAMEIN_SETUP_FreeArgs(int a0);

int SCRCMD_NicknameEventMain(int a, int *st, int *c)
{
    int *q;
    int f;

    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)a, SCRCMD_CreateNameInEvent((void *)c[0], c[1], c[2], c[5]));
        (*st)++;
        break;
    case 1:
        q = (int *)c[2];
        if (q[7] != 1) {
            POKE_TOOL_SetPartyValue((void *)c[3], 0x73, q[8]);
        }
        f = 1;
        if (((int *)c[2])[7] == 1) {
            f = 0;
        }
        *(u16 *)c[4] = f;
        if (*(u16 *)c[4] == 1) {
            func_02008DF0(GAME_DATA_GetTrainerRecord(GAMESYSTEM_GetGameData((const struct Ctx *)c[0])), 0x1e);
        }
        NAMEIN_SETUP_FreeArgs(c[2]);
        return 1;
    }
    return 0;
}
