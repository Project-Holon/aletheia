/*
 * function: BTL_SERVER_FLOW_IsPokeAfflictedByStatus
 * address: 0x021C8374
 * packet: pkt_ov093_021C8374
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_HasMajorStatus 0x021C8348 thumb ov093
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
struct Unk021D62A8;
extern int BTL_SERVER_FLOW_HasMajorStatus(u8 *, int);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *, int);
int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(u8 *p, int i)
{
    if (BTL_SERVER_FLOW_HasMajorStatus(p, i)) return 1;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, i), 33)) return 1;
    return 0;
}
