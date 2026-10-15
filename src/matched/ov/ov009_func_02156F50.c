/*
 * function: DWC_RAPCOMMON_SetHeapTag
 * address:  0x02156F50
 * packet:   pkt_02156F50
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapHeap  0x021A8268  data  ov009
 *
 * Setter after the function ending at pool 0x02156F4C, which stores to the
 * same halfword: writes its argument to +0x20 of the object _pRapHeap
 * points to. Called from the ov175 root WIFIBATTLEMATCH_NET_CompStepF (0x021D85E0).
 */

#include "../include/G_Obj.h"

typedef unsigned short u16;

extern struct Obj *_pRapHeap;

void DWC_RAPCOMMON_SetHeapTag(int a)
{
    *(u16 *)(((char *)_pRapHeap) + 0x20) = a;
}
