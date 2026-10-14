/*
 * function: WORLDTRADE_LIST_Main
 * address: 0x021FCE64
 * packet: pkt_ov135_021FCE64
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   tbl_02203D14 0x02203D14 data a4
 *   WORLDTRADE_SetActorSurfacePos 0x021F4EA0 thumb ov135
 *   WORLDTRADE_SetActorPos 0x021F4FF4 thumb ov135
 *   WORLDTRADE_SUBLCD_MoveArrowToSlot 0x021FFD1C thumb ov135
 */
#include "../include/Obj06515.h"
typedef signed short s16;
extern int (*const tbl_02203D14[])(void *);
extern void WORLDTRADE_SetActorSurfacePos(void *, int, int);
extern void WORLDTRADE_SetActorPos(unsigned, unsigned, unsigned);
extern void WORLDTRADE_SUBLCD_MoveArrowToSlot(void *, int, int);
int WORLDTRADE_LIST_Main(char *p)
{
    int r;
    int i;
    r = tbl_02203D14[*(int *)(p + 0x28)](p);
    for (i = 0; i < 8; i++) {
        WORLDTRADE_SetActorSurfacePos(*(void **)(p + i * 4 + 0xd0c), *(s16 *)(p + i * 4 + 0xec4), *(s16 *)(p + i * 4 + 0xec6) + ((struct Obj06515 *)p)->fD3C + 0x20);
    }
    WORLDTRADE_SetActorPos(((struct Obj06515 *)p)->fD08, 0xd0, 0x3a - ((struct Obj06515 *)p)->fD3C);
    WORLDTRADE_SUBLCD_MoveArrowToSlot(p, ((struct Obj06515 *)p)->fD4, ((struct Obj06515 *)p)->fD3C);
    return r;
}
