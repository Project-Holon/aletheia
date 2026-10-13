/*
 * function: func_021D3B9C
 * address: 0x021D3B9C
 * packet: pkt_ov093_021D3B9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   BTL_FIELD_RemoveHolderFromSlots 0x021EFB34 thumb ov093
 */
#include "../include/Obj21193.h"
typedef unsigned char u8;
struct S;
extern void BTL_FIELD_RemoveHolderFromSlots(struct S *, u8);
int func_021D3B9C(char *p, int unused, unsigned int *a)
{
    BTL_FIELD_RemoveHolderFromSlots(*(struct S * *)&((struct Obj21193 *)p)->f34, a[0]);
    return 1;
}
