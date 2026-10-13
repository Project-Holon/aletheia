/*
 * function: ISS_SWITCH_SET_Delete
 * address:  0x0202C308
 * packet:   pkt_0202C2EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_SWITCH_SET_Free  0x0202C3A0  thumb
 *   ISS_SWITCH_SET_DeleteSwitches  0x0202C3C4  thumb
 */

typedef unsigned int u32;

struct Obj0202C360;
extern void ISS_SWITCH_SET_DeleteSwitches(struct Obj0202C360 *p);
extern u32 ISS_SWITCH_SET_Free(void *p);

void ISS_SWITCH_SET_Delete(void *p)
{
    ISS_SWITCH_SET_DeleteSwitches(p);
    ISS_SWITCH_SET_Free(p);
}
