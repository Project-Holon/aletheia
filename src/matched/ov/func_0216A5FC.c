/*
 * function: SCRCMD_TRIALHOUSE_GetRank
 * address:  0x0216A5FC
 * packet:   pkt_0216A5FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_02008E78  0x02008E78  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Big;
struct Sub02008C20Obj;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u8 func_02008E78(struct Sub02008C20Obj *obj);

int SCRCMD_TRIALHOUSE_GetRank(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *p;
    struct Sub02008C20Obj *obj;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = SCRCMD_WORK_GetScriptWork((void *)a0);
loc_0216A608:
a0 = t4 + 0;
    v1 = SCRCMD_WORK_GetGameSystem((void *)a0);
loc_0216A60E:
    t6 = GAMESYSTEM_GetGameData((const struct Ctx *)v1);
loc_0216A612:
a0 = t5 + 0;
a1 = t4 + 0;
    q = SCRIPT_WORK_ReadWorkPointer((void *)a0, (void *)a1);
loc_0216A61C:
    p = GAME_DATA_GetSaveControl(t6);
loc_0216A624:
    obj = func_02008C58(p);
loc_0216A628:
    a0 = func_02008E78(obj);
loc_0216A62C:
*q = a0;
a0 = 0;
    return a0;}
