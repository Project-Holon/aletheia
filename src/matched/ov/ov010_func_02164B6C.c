/*
 * function: GAME_BEACON_SEARCH_Init
 * address:  0x02164B6C
 * packet:   pkt_ov010_02164B6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates and initialises an 0x84-byte work record.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202647C  0x0202647C  thumb
 *   func_0202648C  0x0202648C  thumb
 *   GAME_BEACON_SEARCH_SetStartDelay  0x02164FC4  thumb ov010
 *   GAME_BEACON_SEARCH_FileName     0x021729BC  data  ov010  a1
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12361.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0202647C(void *obj);
extern u32 func_0202648C(void *obj);
extern void GAME_BEACON_SEARCH_SetStartDelay(char *p);
extern const char GAME_BEACON_SEARCH_FileName[];

u8 *GAME_BEACON_SEARCH_Init(void *unused, void *arg)
{
    u32 v = (u32)GAMESYSTEM_GetGameData(arg);
    void *w = (void *)GAMESYSTEM_GetGameComm(arg);
    u8 *p = func_02030734(5, 0x84, 1, GAME_BEACON_SEARCH_FileName, 0x9c);
    ((struct Obj12361 *)p)->f0 = v;
    ((struct Obj12361 *)p)->fA = 0x1ab;
    if (func_0202647C(w) == 2 && func_0202648C(w) == 5) {
        GAME_BEACON_SEARCH_SetStartDelay((char *)p);
    }
    return p;
}
