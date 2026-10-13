/*
 * function: SCRCMD_WORK_GetWindowKind
 * address:  0x0215A66C
 * packet:   pkt_ov010_0215A66C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the byte at +0x105 of the object at +0x20.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char u8;

u8 SCRCMD_WORK_GetWindowKind(u8 *p)
{
    return (*(u8 **)(p + 0x20))[0x105];
}
