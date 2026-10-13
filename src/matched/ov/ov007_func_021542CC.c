/*
 * function: EVENT_BSUBWAY_COMM_CreateEvent
 * address:  0x021542CC
 * packet:   pkt_021542CC
 * region:   ov007
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field touch on the argument, then allocator + guard + three-field link setup.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_BSUBWAY_COMM_EventMain  0x02154310  thumb  ov007
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct Comm;
u32 func_02026454(void *obj);
void GAME_COMM_RequestExitNoCallback(struct Comm *p);
void *func_020124E8(struct Obj *p);
u32 EVENT_BSUBWAY_COMM_EventMain(void *obj, u32 *mode, u32 *args);

void *EVENT_BSUBWAY_COMM_CreateEvent(void *p, int a, int b)
{
    void *r7;
    int *obj;

    GAMESYSTEM_GetGameData(p);
    r7 = func_020122C0(p, 0, EVENT_BSUBWAY_COMM_EventMain, 0x10);
    obj = func_020124E8(r7);
    obj[0] = a;
    obj[1] = (int)p;
    obj[3] = b;
    if (func_02026454((void *)GAMESYSTEM_GetGameComm(p)))
        GAME_COMM_RequestExitNoCallback((struct Comm *)GAMESYSTEM_GetGameComm(p));
    return r7;
}
