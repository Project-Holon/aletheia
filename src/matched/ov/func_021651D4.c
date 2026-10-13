/*
 * function: func_021651D4
 * address:  0x021651D4
 * packet:   pkt_021650F4
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   GAME_BEACON_ResetDetails  0x0202744C  thumb

 *
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into GAME_BEACON_ResetDetails, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021651D4.c \
 *       --func func_021651D4 --addr 0x021651D4 --region ov010 --cc dsi/1.1p1 --thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void GAME_BEACON_ResetDetails(void *);

void func_021651D4(void *a0, unsigned a1)
{
    ((struct Obj00121 *)a0)->f30 = 7;
    ((struct Obj00121 *)a0)->f34 = a1;
    GAME_BEACON_ResetDetails(a0);
}
