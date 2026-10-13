/*
 * function: BTL_CLIENT_StepRemoveFieldSlot
 * address: 0x021D3BB0
 * packet: pkt_ov093_021D3BB0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 14 bytes followed by 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   BTL_FIELD_RemoveSlot 0x021EFA94 thumb ov093
 */
#include "../include/Obj21195.h"
extern int BTL_FIELD_RemoveSlot(void *, int);
int BTL_CLIENT_StepRemoveFieldSlot(char *p, int unused, unsigned int *a)
{
    BTL_FIELD_RemoveSlot(((struct Obj21195 *)p)->f34, a[0]);
    return 1;
}
