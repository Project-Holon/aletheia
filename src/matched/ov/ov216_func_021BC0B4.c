/*
 * function: BEACON_DETAIL_GRA_Delete
 * address:  0x021BC0B4
 * packet:   pkt_021BC0B4
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOWNMAP_GRH_FreeTownInfo  0x021BBB34  thumb  ov072
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14715.h"

extern void TOWNMAP_GRH_FreeTownInfo(void *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BEACON_DETAIL_GRA_Delete(char *p)
{
    TOWNMAP_GRH_FreeTownInfo((void *)(((struct Obj14715 *)p)->f1C));
    func_020307B0((void *)(((struct Obj14715 *)p)->f28));
}
