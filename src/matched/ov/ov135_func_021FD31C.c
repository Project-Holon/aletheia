/*
 * function: WORLDTRADE_LIST_StateWaitWipeIn
 * address: 0x021FD31C
 * packet: pkt_ov135_021FD31C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj06517.h"
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int WORLDTRADE_LIST_StateWaitWipeIn(unsigned char *p)
{
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj06517 *)p)->fD38, 0);
    if (((struct Obj06517 *)p)->f20 == 16) {
        WIPE_SYS_Start(0, 1, 1, 0, 16, 1, 0x48);
        ((struct Obj06517 *)p)->f28 = 7;
    } else {
        ((struct Obj06517 *)p)->f28 = 1;
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj06517 *)p)->fD34, 1);
    }
    return 2;
}
