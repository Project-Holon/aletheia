/*
 * function: func_021D3C70
 * address: 0x021D3C70
 * packet: pkt_ov093_021D3C70
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SLOT_UpdateIllusion 0x021B9D10 thumb ov093
 */
#include "../include/Obj13426.h"
typedef unsigned char u8;
struct Arr;
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
extern void BTL_SLOT_UpdateIllusion(char *, struct Arr *, int);
int func_021D3C70(char *p, int unused, unsigned int *a)
{
    u8 index = a[0];
    struct Arr *obj = (struct Arr *)BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj13426 *)p)->f4, index);
    BTL_SLOT_UpdateIllusion(*(char * *)&((struct Obj13426 *)p)->f0, obj, index);
    return 1;
}
