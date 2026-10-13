/*
 * function: func_0220BB94
 * address:  0x0220BB94
 * packet:   pkt_0220BB94
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_CopyToSlot 0x020215BC thumb
 */
#include "../include/Obj25127.h"

typedef unsigned short u16;
typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);

void func_0220BB94(unsigned char *p, u32 a1)
{
    PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj25127 *)p)->f1D8), p + 0x1e78, 1, 0xc0, 0x20);
}
