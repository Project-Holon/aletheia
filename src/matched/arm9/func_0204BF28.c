/*
 * function: CLACT_SetSurfaceType
 * address:  0x0204BF28
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 24 concrete bytes are correct (20 code + the pool
 * word), but the ABS32 at +0x0014 has no witness of any class.  0x020A1388
 * is plain data, so only the `literal` class could attest it, and the pool
 * word inside this function is that address's only occurrence image wide.
 * The escape that unblocked 0x0204C83C in this same region (decompile the
 * target to EXACT and cite it as a `matched` witness) does not exist here:
 * nothing compiles a data table.  Same wall as src/matched/CLACT_ExecuteTransfer.c
 * and docs/notes/clact_c_fan_in_1_blockers.c.txt describe for 0x020A138C.
 *
 * Store the u16 entry `idx` of the table at 0x020A1388 into the caller's
 * word at +0x14, zero-extended.
 *
 * symbols:
 *   g_ClactSurfaceTypeTable     0x020A1388  data
 */
#include "../include/Obj16091.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 g_ClactSurfaceTypeTable[];

void CLACT_SetSurfaceType(u8 *p, u32 idx)
{
    ((struct Obj16091 *)p)->f14 = g_ClactSurfaceTypeTable[idx];
}
