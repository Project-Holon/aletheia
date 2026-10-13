/*
 * function: BTL_CLIENT_StepPassEffects
 * address: 0x021D3BE0
 * packet: pkt_ov093_021D3BE0
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
 *   BTL_POKEPARAM_PassEffects 0x021D65C8 thumb ov093
 */
#include "../include/Obj13422.h"
typedef unsigned char u8;
struct Work;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_PassEffects(struct Work *, struct Work *);
int BTL_CLIENT_StepPassEffects(char *p, int unused, unsigned int *a)
{
    u8 *first = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj13422 *)p)->f4, (u8)a[0]);
    u8 *second = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj13422 *)p)->f4, (u8)a[1]);
    BTL_POKEPARAM_PassEffects((struct Work *)second, (struct Work *)first);
    return 1;
}
