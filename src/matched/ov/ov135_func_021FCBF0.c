/*
 * function: WORLDTRADE_DETAIL_DrawRequestWindow
 * address: 0x021FCBF0
 * packet: pkt_ov135_021FCBF0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_DEPOSIT_GetConditionIndex 0x021F886C thumb ov135
 *   WORLDTRADE_DEPOSIT_DrawRequestWindowAlt 0x021F8290 thumb ov135
 */
#include "../include/Obj04529.h"
typedef signed short s16;
extern int WORLDTRADE_DEPOSIT_GetConditionIndex(int key, int val, int which);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(void *bank, void *names, int unused, u8 *win, u32 index, int mode, int place, void *g);
void WORLDTRADE_DETAIL_DrawRequestWindow(char *p)
{
    int n;
    n = WORLDTRADE_DEPOSIT_GetConditionIndex(p[0x1d7], p[0x1d8], 0);
    WORLDTRADE_DEPOSIT_DrawRequestWindowAlt(((struct Obj04529 *)p)->fB6C, ((struct Obj04529 *)p)->fB70, (int)(((struct Obj04529 *)p)->fB68), (u8 *)(p + 0xdb4), ((struct Obj04529 *)p)->f1D4, p[0x1d6], n, p + 0xfa0);
}
