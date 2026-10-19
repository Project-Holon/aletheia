/*
 * function: WORLDTRADE_DEPOSIT_Exit
 * address: 0x021F74F8
 * packet: pkt_ov135_021F74F8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_DEPOSIT_DeleteActors 0x021F7964 thumb ov135
 *   WORLDTRADE_INPUT_MenuDelete 0x021F99D0 thumb ov135
 *   WORLDTRADE_DEPOSIT_DeleteStrings 0x021F79EC thumb ov135
 *   WORLDTRADE_DEPOSIT_DeleteWindows 0x021F7840 thumb ov135
 *   WORLDTRADE_DEPOSIT_ExitBgPlanes 0x021F76BC thumb ov135
 *   WORLDTRADE_TITLE_ExitBgPlanes 0x022000E4 thumb ov135
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WORLDTRADE_AdvanceScreenId 0x021F4EC8 thumb ov135
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
extern void WORLDTRADE_DEPOSIT_DeleteActors(u8 *p);
extern void WORLDTRADE_INPUT_MenuDelete(u8 *p);
extern void WORLDTRADE_DEPOSIT_DeleteStrings(char *p);
extern void WORLDTRADE_DEPOSIT_DeleteWindows(char *p);
extern void WORLDTRADE_DEPOSIT_ExitBgPlanes(void);
extern void WORLDTRADE_TITLE_ExitBgPlanes(char *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void WORLDTRADE_AdvanceScreenId(u8 *p);
int WORLDTRADE_DEPOSIT_Exit(u8 *p)
{
    WORLDTRADE_DEPOSIT_DeleteActors(p);
    WORLDTRADE_INPUT_MenuDelete(((struct Obj00287 *)p)->fDE4);
    WORLDTRADE_DEPOSIT_DeleteStrings((char *)p);
    WORLDTRADE_DEPOSIT_DeleteWindows((char *)p);
    WORLDTRADE_DEPOSIT_ExitBgPlanes();
    WORLDTRADE_TITLE_ExitBgPlanes((char *)p);
    CLACT_SetActorDrawEnable((struct Obj *)*(unsigned *)&((struct Obj00287 *)p)->fD38, 0);
    WORLDTRADE_AdvanceScreenId(p);
    return 0;
}
