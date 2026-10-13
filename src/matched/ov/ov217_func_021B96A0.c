/*
 * function: func_021B96A0
 * address:  0x021B96A0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIH_DWC_PollStatus  0x0201058C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   GAME_DATA_GetWifiList  0x0201283C  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *
 * Flushes the +4 handle through three sub-calls, then raises event 1 with
 * the record's leading halfword when the fourth sub-call reports busy.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10953.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 WIH_DWC_PollStatus(void *key);
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct IcaAnime;
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void func_021B96A0(u32 a0)
{
    WIH_DWC_PollStatus((void *)GAME_DATA_GetWifiList(GAMESYSTEM_GetGameData(((struct Obj10953 *)(((u8*)a0)))->f4)));
    if (GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)(*(u32 *)&((struct Obj10953 *)(((u8*)a0)))->f4)) != 0) {
    GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj10953 *)((u8*)a0))->f0);
    }
}
