/*
 * function: BTL_CLIENT_StepAdvanceTurn
 * address: 0x021D3CFC
 * packet: pkt_ov093_021D3CFC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_AdvanceTurn 0x021D6408 thumb ov093
 *   BTL_POKEPARAM_ClearStoredPokeMove 0x021D6E88 thumb ov093
 */
#include "../include/Obj21202.h"
typedef unsigned char u8;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_AdvanceTurn(u8 *);
extern void BTL_POKEPARAM_ClearStoredPokeMove(u8 *);
int BTL_CLIENT_StepAdvanceTurn(char *p, int unused, unsigned int *a)
{
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj21202 *)p)->f4, (u8)a[0]);
    BTL_POKEPARAM_AdvanceTurn(obj);
    BTL_POKEPARAM_ClearStoredPokeMove(obj);
    return 1;
}
