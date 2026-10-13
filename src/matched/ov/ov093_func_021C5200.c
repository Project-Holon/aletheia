/*
 * function: BTL_SERVER_FLOW_ProcFaintRewards
 * address: 0x021C5200
 * packet: pkt_ov093_021C5200
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_CheckEventOverlayAllowed 0x021B85EC thumb ov093
 *   func_021C52C8 0x021C52C8 thumb ov093
 *   func_021C52D8 0x021C52D8 thumb ov093
 *   func_021C52E8 0x021C52E8 thumb ov093
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   BTL_SERVER_FLOW_CheckShowdown 0x021BC2B0 thumb ov093
 *   BTL_SERVER_FLOW_CheckPlayerSideAlive 0x021BC310 thumb ov093
 *   BTL_MAIN_GetWinBgm 0x021B86DC thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_ProcExpForFaintedPoke 0x021C5308 thumb ov093
 *   func_021C52F8 0x021C52F8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Flags { u8 a:1; u8 b:1; u8 rest:6; };
typedef unsigned short u16;
extern int BTL_MAIN_CheckEventOverlayAllowed(u32 **p);
extern u32 func_021C52C8(u8 *, int);
extern int func_021C52D8(u8 *, int, u8);
extern int func_021C52E8(u8 *, int, u8);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *);
extern int BTL_SERVER_FLOW_CheckPlayerSideAlive(u8 *);
extern u16 BTL_MAIN_GetWinBgm(void **p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_SERVER_FLOW_ProcExpForFaintedPoke(u8 *, u8 *);
extern void func_021C52F8(u8 *, int, u8);
int BTL_SERVER_FLOW_ProcFaintRewards(u8 *p)
{
    int result = 0;
    u32 i;
    u32 count;
    u8 *a;
    if (BTL_MAIN_CheckEventOverlayAllowed(((struct Obj00003 *)p)->f4)) {
        count = func_021C52C8(p + 0x3e0, 0);
        for (i = 0; i < count; i++) {
            if (!func_021C52D8(p + 0x3e0, 0, i)) {
                a = BTL_SIDE_GetPokeByIdThunk((char *)(*(u8 * *)&((struct Obj00003 *)p)->f8), func_021C52E8(p + 0x3e0, 0, i));
                if (!BTL_MAIN_GetCompetitor(((struct Obj00003 *)p)->f4) && !((struct Flags *)(p + 0x78a))->b && BTL_SERVER_FLOW_CheckShowdown(p) && BTL_SERVER_FLOW_CheckPlayerSideAlive(p)) {
                    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x55, BTL_MAIN_GetWinBgm(((struct Obj00003 *)p)->f4));
                    ((struct Flags *)(p + 0x78a))->b = 1;
                }
                if (BTL_SERVER_FLOW_ProcExpForFaintedPoke(p, a)) result = 1;
                func_021C52F8(p + 0x3e0, 0, i);
            }
        }
    }
    return result;
}
