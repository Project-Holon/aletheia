/*
 * function: BTL_HANDLER_ITEM_CureSickOnEaten
 * address: 0x021DD19C
 * packet: pkt_ov093_021DD19C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_HANDLER_ITEM_CheckHasSick 0x021DD1D8 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj10066.h"
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int);
extern int BTL_HANDLER_ITEM_CheckHasSick(u8 *, int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *, void *);
void BTL_HANDLER_ITEM_CureSickOnEaten(void *a, u8 *b, int c, int d)
{
    u8 *p;
    if (c == BTL_EVENT_GetVar(2) && BTL_HANDLER_ITEM_CheckHasSick(b, c, d)) {
        p = func_021C88A4((char *)b, 11, c);
        ((struct Obj10066 *)p)->f4 = d;
        p[0x14] = 1;
        p[8] = c;
        func_021C88C8(b, p);
    }
}
