/*
 * function: SCRCMD_NETWORK_CreateCommProcEvent
 * address:  0x0215F6E8
 * packet:   pkt_0215F6E8
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, then two accessor stores and two teardown calls.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   GAMESYSTEM_SetCommBlocked  0x0201213C  thumb
 *   SCRCMD_NETWORK_HasSituationWarpChanged  0x0215F630  thumb  ov010
 *   SCRCMD_NETWORK_CommProcEventMain  0x0215F64C  thumb  ov010
 *   SYMBOL_MAP_DeleteLinkRecord  0x021666A4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Big;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u8 *GAME_DATA_GetMyStatus(void *p);
u8 *GAME_DATA_GetEventState(struct Big *p);
void GAMESYSTEM_SetCommBlocked(struct Ctx *p, u32 v);
int SCRCMD_NETWORK_HasSituationWarpChanged(void *p);
int SCRCMD_NETWORK_CommProcEventMain(int a0, int *st, int *a2);
void SYMBOL_MAP_DeleteLinkRecord(int a0);

void *SCRCMD_NETWORK_CreateCommProcEvent(void *p)
{
    int r4 = (int)GAMESYSTEM_GetGameData(p);
    void *r7 = func_020122C0(p, 0, SCRCMD_NETWORK_CommProcEventMain, 0xc);
    int *r6 = func_020124E8(r7);

    r6[0] = (int)p;
    r6[1] = (int)SCRCMD_NETWORK_HasSituationWarpChanged((void *)r4);
    r6[2] = (int)GAME_DATA_GetMyStatus((void *)r4);
    SYMBOL_MAP_DeleteLinkRecord((int)GAME_DATA_GetEventState((struct Big *)r4));
    GAMESYSTEM_SetCommBlocked(p, 0);
    return r7;
}
