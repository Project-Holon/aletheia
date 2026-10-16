/*
 * function: ISS_3DS_SYS_OnZoneChangeImpl
 * address:  0x0202BB40
 * packet:   pkt_0202B90C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ISS_3DS_SYS_ResetSources  0x0202BA24  thumb
 *
 * iss_3ds_sys.c: a bare tail-call thunk to ISS_3DS_SYS_ResetSources (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BA25), the target of the thunk at 0x0202B90C.  Not a
 * seeded start yet (integrator: seed 0x0202BB40 thumb); filed so that
 * ISS_3DS_SYS_OnZoneChange's pool word has a matched witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_3DS_SYS_OnZoneChangeImpl.c \
 *       --func ISS_3DS_SYS_OnZoneChangeImpl --addr 0x0202BB40 --thumb --cc 1.1p1
 */

typedef unsigned char u8;

extern void ISS_3DS_SYS_ResetSources(u8 *p);

void ISS_3DS_SYS_OnZoneChangeImpl(u8 *p)
{
    ISS_3DS_SYS_ResetSources(p);
}
