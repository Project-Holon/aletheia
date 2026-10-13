/*
 * function: MOVE_POKEMON_SweetScentEventMain
 * address:  0x0215EF60
 * packet:   pkt_ov010_0215EF60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   SCRIPT_SYS_ChangeScriptEvent  0x021587B0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *SCRIPT_SYS_CallScriptEvent(void *a, u32 id, u32 b, u32 c, u32 d);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);
extern int SCRIPT_SYS_ChangeScriptEvent(int a0, int a1, int a2, int a3);

int MOVE_POKEMON_SweetScentEventMain(void *a, int *st, struct C *c)
{
    u32 h;
    u32 x;
    void *t;

    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(c->f8));
    x = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(c->f8));
    switch (*st) {
    case 0:
        h = c->fc;
        t = SCRIPT_SYS_CallScriptEvent(a, 0x271e, 0, 0, x);
        SCRIPT_WORK_SetParams((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        SCRIPT_SYS_ChangeScriptEvent((int)a, 0x28e3, 0, 0);
        break;
    }
    return 0;
}
