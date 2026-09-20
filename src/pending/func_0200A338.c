/*
 * function: func_0200A338
 * address:  0x0200A338
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH*
 * note:     re-verified 2026-09-20: MATCH*; see verify output
 * blocker:  0200A3D0 - the documented unattestable function (no func_ label in any of the seven overlays that hold the address, and this call is the only branch to it).  All 16 bytes right; the 020307B0 call resolves.
 */

extern void func_0200A3D0(void *p);
extern void func_020307B0(void *p);

void func_0200A338(void *a0)
{
    func_0200A3D0(a0);
    func_020307B0(a0);
}
