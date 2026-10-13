/*
 * function: EVENT_MENUPROC_Create
 * address:  0x0215437C
 * packet:   pkt_0215437C
 * region:   ov003
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator + guard + three-field link setup.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_MENUPROC_Main  0x021542C0  thumb  ov003
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
struct Comm;
u32 GAME_COMM_GetKind(void *obj);
void GAME_COMM_RequestExitNoCallback(struct Comm *p);
void *func_020124E8(struct Obj *p);
u32 EVENT_MENUPROC_Main(void *obj, u32 *mode, u32 *args);

void *EVENT_MENUPROC_Create(void *p, int a, int b)
{
    void *r7 = func_020122C0(p, 0, EVENT_MENUPROC_Main, 0x1C);
    int *obj;

    if (GAME_COMM_GetKind((void *)GAMESYSTEM_GetGameComm(p)))
        GAME_COMM_RequestExitNoCallback((struct Comm *)GAMESYSTEM_GetGameComm(p));
    obj = func_020124E8(r7);
    obj[1] = (int)p;
    obj[2] = a;
    obj[5] = b;
    return r7;
}
