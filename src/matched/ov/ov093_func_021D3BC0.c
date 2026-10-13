/*
 * function: func_021D3BC0
 * address: 0x021D3BC0
 * packet: pkt_ov093_021D3BC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_SetCounter 0x021D69A0 thumb ov093
 */
#include "../include/Obj21197.h"
typedef unsigned char u8;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_SetCounter(u8 *, int, u8);
int func_021D3BC0(char *p, int unused, unsigned int *a)
{
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj21197 *)p)->f4, (u8)a[0]);
    BTL_POKEPARAM_SetCounter(obj, a[1], a[2]);
    return 1;
}
