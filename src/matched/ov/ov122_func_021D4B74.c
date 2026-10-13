/*
 * unit: yes
 * function: func_021D4B74, func_021D4BDC, func_021D4BF0
 * address: 0x021D4B74
 * packet: pkt_ov122_021D4B74
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: unlabelled ov014 Thumb setter 0x02178118 is filed separately.
 * extent: unit includes tail-call stub 0x021D4BDC and return stub 0x021D4BF0;
 *   two zero padding bytes at 0x021D4BF2 follow the intended code.
 * symbols:
 *   func_021D4B74  0x021D4B74  thumb  ov122
 *   NET_WHPIPE_SetNotifyCallback 0x02178118 thumb ov014
 *   func_021D4B30 0x021D4B30 thumb ov122
 *   func_021D4244 0x021D4244 thumb ov122
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb  arm9
 */
#include "../include/Obj06457.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
struct Comm;
extern void NET_WHPIPE_SetNotifyCallback(u32 callback, u32 value);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *);
extern u32 func_02026454(void *obj);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void func_021D4244(void *p, u32 a, int a2);
extern void func_021D4B30(char *p);
void func_021D4B74(char *p)
{
    ((struct Obj06457 *)p)->f38C = 1;
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((struct Obj06457 *)p)->fC);
    NET_WHPIPE_SetNotifyCallback(0, 0);
    if (((struct Obj06457 *)p)->f8 == 1 && func_02026454((void *)GAMESYSTEM_GetGameComm(((struct Obj06457 *)p)->f354)))
        GAME_COMM_RequestExitNoCallback((struct Comm *)GAMESYSTEM_GetGameComm(((struct Obj06457 *)p)->f354));
    func_021D4244(p, (u32)func_021D4B30, 0x35e);
}
void func_021D4BDC(char *p)
{
    func_021D4244(p, (u32)func_021D4B74, 0x36f);
}
void func_021D4BF0(void)
{
}
