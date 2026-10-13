/*
 * function: GAME_BEACON_SEARCH_StartConnectEvent
 * address:  0x02164FD0
 * packet:   pkt_ov010_02164FD0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies a 6-byte record out of the object, and when no flag / busy
 * checks trip allocates a 0x10-byte record holding it and registers it.
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_020307B0  0x020307B0  arm
 *   GAMESYSTEM_CanStartAutoComm  0x02012164  thumb
 *   GAME_COMM_GetNotifyFlag  0x020264AC  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   func_02026454  0x02026454  thumb
 *   func_02030734  0x02030734  arm
 *   GAME_COMM_Start  0x020263D8  thumb
 *   GAME_BEACON_SEARCH_FileName     0x021729BC  data  ov010  a1
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12364.h"
#include "../include/Obj18989.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_02082D44(void *src, void *dst, int n);
struct Ctx;
extern u32   GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern u32 func_020307B0(void *p);
struct Comm;
struct IcaAnime;
extern u32 GAMESYSTEM_CanStartAutoComm(struct IcaAnime *p);
extern u32 GAME_COMM_GetNotifyFlag(void *obj);
extern int   GFL_NET_GetRunState(void);
extern u32 func_02026454(void *obj);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void GAME_COMM_Start(struct Comm *p, u32 a1, u32 a2);
extern const char GAME_BEACON_SEARCH_FileName[];

void GAME_BEACON_SEARCH_StartConnectEvent(u8 *obj, int flag)
{
    u8 buf[6];
    u32 o = ((struct Obj18989 *)obj)->f0;
    u32 w;
    u8 *p;
    func_02082D44(obj + 4, buf, 6);
    w = GAMESYSTEM_GetGameComm((const struct Ctx *)o);
    func_020307B0(obj);
    if (flag == 0 && GAMESYSTEM_CanStartAutoComm((struct IcaAnime *)o) == 1 && GAME_COMM_GetNotifyFlag((void *)w) == 0
        && GFL_NET_GetRunState() == 0 && func_02026454((void *)w) == 0) {
        p = func_02030734(5, 0x10, 1, GAME_BEACON_SEARCH_FileName, 0x287);
        ((struct Obj12364 *)p)->f0 = o;
        ((struct Obj12364 *)p)->f4 = GAMESYSTEM_GetGameComm((const struct Ctx *)o);
        func_02082D44(buf, p + 8, 6);
        GAME_COMM_Start((struct Comm *)w, 2, (u32)p);
    }
}
