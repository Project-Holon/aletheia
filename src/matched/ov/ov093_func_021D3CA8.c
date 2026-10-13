/*
 * function: func_021D3CA8
 * address: 0x021D3CA8
 * packet: pkt_ov093_021D3CA8
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
 *   BTL_POKEPARAM_CureSickBySource 0x021D6264 thumb ov093
 */
#include "../include/Obj21200.h"
typedef unsigned char u8;
struct UtilSlots;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_CureSickBySource(struct UtilSlots *p, int v);
int func_021D3CA8(char *p, int unused, unsigned int *a)
{
    u8 *obj = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj21200 *)p)->f4, (u8)a[0]);
    BTL_POKEPARAM_CureSickBySource((struct UtilSlots *)obj, (u8)a[1]);
    return 1;
}
