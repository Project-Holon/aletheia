/*
 * function: WORLDTRADE_BOX_Exit
 * address: 0x021F5204
 * packet: pkt_ov135_021F5204
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D55C 0x0207D55C arm
 *   WORLDTRADE_SUBLCD_SetSlotActorPositionsLower 0x021FFD74 thumb ov135
 *   WORLDTRADE_BOX_DeleteActors 0x021F577C thumb ov135
 *   WORLDTRADE_BOX_DeleteStrings 0x021F59E8 thumb ov135
 *   WORLDTRADE_BOX_DeleteWindows 0x021F5940 thumb ov135
 *   WORLDTRADE_BOX_ExitBgPlanes 0x021F5358 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_ClearBusyFlag 0x021F4EC8 thumb ov135
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0207D55C(volatile u16 *reg);
extern void WORLDTRADE_SUBLCD_SetSlotActorPositionsLower(char *p);
extern void WORLDTRADE_BOX_DeleteActors(u8 *);
extern void WORLDTRADE_BOX_DeleteStrings(char *p);
extern void WORLDTRADE_BOX_DeleteWindows(u8 *);
extern void WORLDTRADE_BOX_ExitBgPlanes(void);
extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void WORLDTRADE_ClearBusyFlag(u8 *);
int WORLDTRADE_BOX_Exit(u8 *p)
{
    if (func_0207D55C((u16 *)0x0400106c)) {
        WORLDTRADE_SUBLCD_SetSlotActorPositionsLower((char *)p);
    }
    WORLDTRADE_BOX_DeleteActors(p);
    WORLDTRADE_BOX_DeleteStrings((char *)p);
    WORLDTRADE_BOX_DeleteWindows(p);
    WORLDTRADE_BOX_ExitBgPlanes();
    WORLDTRADE_TITLE_ExitBgPlanes((char *)p);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    WORLDTRADE_ClearBusyFlag(p);
    return 0;
}
