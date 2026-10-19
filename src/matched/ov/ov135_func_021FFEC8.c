/*
 * function: WORLDTRADE_TITLE_Exit
 * address: 0x021FFEC8
 * packet: pkt_ov135_021FFEC8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_TITLE_DeleteActors 0x02200290 thumb ov135
 *   WORLDTRADE_TITLE_DeleteStrings 0x02200434 thumb ov135
 *   WORLDTRADE_TITLE_DeleteWindows 0x022003BC thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanesSub 0x02200118 thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   WORLDTRADE_AdvanceScreenId 0x021F4EC8 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void WORLDTRADE_TITLE_DeleteActors(u8 *);
extern void WORLDTRADE_TITLE_DeleteStrings(u8 *);
extern void WORLDTRADE_TITLE_DeleteWindows(u8 *);
extern void WORLDTRADE_TITLE_ExitBgPlanesSub(void);
extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);
extern void WORLDTRADE_AdvanceScreenId(u8 *);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
int WORLDTRADE_TITLE_Exit(u8 *p)
{
    WORLDTRADE_TITLE_DeleteActors(p);
    WORLDTRADE_TITLE_DeleteStrings(p);
    WORLDTRADE_TITLE_DeleteWindows(p);
    WORLDTRADE_TITLE_ExitBgPlanesSub();
    if (((struct Obj00287 *)p)->f14 == 4 || ((struct Obj00287 *)p)->f14 == 5) ((struct Obj00287 *)p)->f12E4 = 1;
    WORLDTRADE_TITLE_ExitBgPlanes((char *)p);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    WORLDTRADE_AdvanceScreenId(p);
    return 0;
}
