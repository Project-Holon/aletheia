/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005C3C
 * packet:   pkt_02005924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GFL_USE_GetBgmHandle, GFL_USE_GetBgmNo
 *
 * symbols:
 *   GFL_USE_GetCurrentBgmId  0x020058D0  thumb
 *   GFL_USE_GetCurrentSndHandle  0x0200590C  thumb
 *
 * Two eight byte forwarders, one `ldr r3, [pc]` and one `bx r3` each.  Both
 * targets are Thumb and both are reached from elsewhere in the image, so the
 * two pool words resolve with the Thumb bit set and the ranges are EXACT.
 * The pair is worth keeping as a unit because it is the cheapest possible
 * demonstration that a tail call to a function in another section is always
 * a pool word: there is nothing else in either function.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16  GFL_USE_GetCurrentBgmId(void);
extern u32 *GFL_USE_GetCurrentSndHandle(void);

u32 *GFL_USE_GetBgmHandle(void)
{
    return GFL_USE_GetCurrentSndHandle();
}

u16 GFL_USE_GetBgmNo(void)
{
    return GFL_USE_GetCurrentBgmId();
}
