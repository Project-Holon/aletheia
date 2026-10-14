/*
 * function: WORLDTRADE_LIST_Exit
 * address: 0x021FCED4
 * packet: pkt_ov135_021FCED4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_LIST_DeleteActors 0x021FD0F4 thumb ov135
 *   WORLDTRADE_LIST_DeleteStrings 0x021FD2FC thumb ov135
 *   WORLDTRADE_LIST_DeleteWindows 0x021FD1E0 thumb ov135
 *   WORLDTRADE_LIST_ExitBgPlanes 0x021FCFC8 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   WORLDTRADE_ClearBusyFlag 0x021F4EC8 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj03069.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char  u8;
extern void WORLDTRADE_LIST_DeleteActors(u8 *p);
extern void WORLDTRADE_LIST_DeleteStrings(u8 *p);
extern void WORLDTRADE_LIST_DeleteWindows(u8 *p);
extern void WORLDTRADE_LIST_ExitBgPlanes(void);
extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);
extern void WORLDTRADE_ClearBusyFlag(u8 *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
int WORLDTRADE_LIST_Exit(unsigned char *p)
{
    ((struct Obj03069 *)p)->fEC0 = 0;
    WORLDTRADE_LIST_DeleteActors(p);
    WORLDTRADE_LIST_DeleteStrings(p);
    WORLDTRADE_LIST_DeleteWindows(p);
    WORLDTRADE_LIST_ExitBgPlanes();
    WORLDTRADE_TITLE_ExitBgPlanes((char *)p);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj03069 *)p)->fD38, 0);
    WORLDTRADE_ClearBusyFlag(p);
    if (*(int *)&((struct Obj03069 *)p)->f12FC == 0)
        GFL_NET_RestartWithDefaultTimeout(0, 0x48);
    return 0;
}
