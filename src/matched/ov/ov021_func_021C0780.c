/*
 * function: EVENT_COMM_ERROR_RunCommExit
 * address:  0x021C0780
 * packet:   pkt_ov021_021C0780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   func_0200FBA0  0x0200FBA0  thumb
 *   GAMESYSTEM_SetFieldMapState  0x02012124  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_BEACON_SEARCH_SetStartDelay  0x02164FC4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Obj;
struct Ctx;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *a);
extern int GFL_NET_GetRunState(void);
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IsSessionNull(void);
extern void func_0200FBA0(void);
struct IcaAnime;
extern void GAMESYSTEM_SetFieldMapState(struct Ctx *p, u32 v);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern u32 GAME_COMM_GetWork(void *obj);
extern u32 GAME_COMM_GetKind(void *obj);
extern void GAME_BEACON_SEARCH_SetStartDelay(char *p);

int EVENT_COMM_ERROR_RunCommExit(u32 a, int *st)
{
    u32 x;
    u32 y;
    u32 z;

    x = (u32)GAME_EVENT_GetGameSystem((struct Obj *)a);
    y = GAMESYSTEM_GetGameComm((const struct Ctx *)x);
    switch (*st) {
    case 0:
        if (GFL_NET_GetRunState()) {
            GFL_NET_Exit(0);
        }
        *st = *st + 1;
        break;
    case 1:
        if (GFL_NET_IsSessionNull() == 1) {
            func_0200FBA0();
            GAMESYSTEM_SetFieldMapState((struct Ctx *)x, 0);
            *st = *st + 1;
        }
        break;
    case 2:
        if (GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)x) == 1) {
            *st = *st + 1;
            break;
        }
        return 1;
    case 3:
        z = GAME_COMM_GetWork((void *)y);
        if (z && GAME_COMM_GetKind((void *)y)) {
            GAME_BEACON_SEARCH_SetStartDelay((char *)z);
            return 1;
        }
        break;
    }
    return 0;
}
