/*
 * function: MYSTERY_DATA_Delete
 * address:  0x0200A338
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0200A3D0 - the documented unattestable function (no func_ label in any of the seven overlays that hold the address, and this call is the only branch to it).  All 16 bytes right; the 020307B0 call resolves.
 *
 * symbols:
 *   MYSTERY_DATA_Unload  0x0200A3D0  thumb
 */

extern void MYSTERY_DATA_Unload(void *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void MYSTERY_DATA_Delete(void *a0)
{
    MYSTERY_DATA_Unload(a0);
    func_020307B0(a0);
}
