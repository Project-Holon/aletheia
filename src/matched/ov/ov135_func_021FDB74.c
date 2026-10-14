/*
 * function: WORLDTRADE_SEARCH_Exit
 * address: 0x021FDB74
 * packet: pkt_ov135_021FDB74
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_INPUT_MenuDelete 0x021F99D0 thumb ov135
 *   WORLDTRADE_SEARCH_DeleteActors 0x021FDEFC thumb ov135
 *   WORLDTRADE_SEARCH_DeleteStrings 0x021FE178 thumb ov135
 *   WORLDTRADE_SEARCH_DeleteWindows 0x021FE0BC thumb ov135
 *   WORLDTRADE_SEARCH_ExitBgPlanes 0x021FDCE4 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   WORLDTRADE_ClearBusyFlag 0x021F4EC8 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00287.h"
typedef unsigned int u32;
typedef unsigned char  u8;
extern void WORLDTRADE_INPUT_MenuDelete(u8 *p);
extern void WORLDTRADE_SEARCH_DeleteActors(char *p);
extern void WORLDTRADE_SEARCH_DeleteStrings(char *p);
extern void WORLDTRADE_SEARCH_DeleteWindows(unsigned char *p);
extern void WORLDTRADE_SEARCH_ExitBgPlanes(void);
extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);
extern void WORLDTRADE_ClearBusyFlag(u8 *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
int WORLDTRADE_SEARCH_Exit(unsigned char *p)
{
    ((struct Obj00287 *)p)->fEC0 = 0;
    WORLDTRADE_INPUT_MenuDelete(((struct Obj00287 *)p)->fDE4);
    WORLDTRADE_SEARCH_DeleteActors((char *)p);
    WORLDTRADE_SEARCH_DeleteStrings((char *)p);
    WORLDTRADE_SEARCH_DeleteWindows(p);
    WORLDTRADE_SEARCH_ExitBgPlanes();
    if (*(int *)&((struct Obj00287 *)p)->f14 == 1)
        *(int *)&((struct Obj00287 *)p)->f12E4 = 1;
    WORLDTRADE_TITLE_ExitBgPlanes((char *)p);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    WORLDTRADE_ClearBusyFlag(p);
    return 0;
}
