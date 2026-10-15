/*
 * function: NNSi_FndGetMBlockAttribute
 * address:  0x02060F98
 * packet:   pkt_02060F98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 12-byte ARM leaf right after NNSi_FndGetMBlockSize (its sibling getter on the
 * same header, p - 0xc): "ldrh r0, [r0, #-0xe]; and r0, r0, #0xff; bx lr".
 * It saves nothing, so the prologue sweep prints it as .word data.  The
 * only call site in the image is the blx at ov009 0x02156FE4
 * (DWC_RAPCOMMON_Free), which needs this entry as its matched witness.
 */

typedef unsigned char u8;
typedef unsigned short u16;

u8 NNSi_FndGetMBlockAttribute(char *p)
{
    return *(u16 *)(p - 0xe);
}
