/*
 * function: func_021655F8
 * address:  0x021655F8
 * packet:   pkt_021655F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Short thunk: stamp the id halfword on the record and hand it
 * straight to the shared submitter.
 *
 * symbols:
 *   func_0202744C   0x0202744C  thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0202744C(void *dst);

void func_021655F8(void *a0)
{
    ((struct Obj00121 *)a0)->f30 = 0x27;
    func_0202744C(a0);
}

