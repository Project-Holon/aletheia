/*
 * function: BTL_MAIN_UpdateFriendshipUseItem
 * address:  0x021BA250
 * packet:   pkt_ov093_021BA250
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SIDE_GetPokeById  0x021B9940  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTL_MAIN_GetFieldSituation  0x021B8714  thumb  ov093
 *   NATSUKI_CalcUseItem  0x0201B7B4  thumb
 */
#include "../include/Obj13284.h"
#include "../include/Obj13285.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 *BTL_SIDE_GetPokeById(char *, u8);
extern void *BTL_POKEPARAM_GetMon(void *);
extern char *BTL_MAIN_GetFieldSituation(char **);
extern void NATSUKI_CalcUseItem(void *, int, u16, u16);

void BTL_MAIN_UpdateFriendshipUseItem(char *p, u8 *a, int b)
{
    u8 i;
    void *x;
    void *y;
    void *xv;
    void *yv;
    char *q;

    i = BTL_POKEPARAM_GetPokeId(a);
    x = BTL_SIDE_GetPokeById(p + 0x1b0, i);
    y = BTL_SIDE_GetPokeById(p + 0xc8, i);
    xv = BTL_POKEPARAM_GetMon(x);
    yv = BTL_POKEPARAM_GetMon(y);
    q = BTL_MAIN_GetFieldSituation((char **)p);
    NATSUKI_CalcUseItem(xv, b, ((struct Obj13285 *)q)->fA, (((struct Obj13284 *)p)->f468 & 0x7fff) | 0x8000);
    NATSUKI_CalcUseItem(yv, b, ((struct Obj13285 *)q)->fA, (((struct Obj13284 *)p)->f468 & 0x7fff) | 0x8000);
}
