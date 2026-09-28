/*
 * function: FSi_GetOverlayBinarySize
 * address:  0x02078CB0
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (28 bytes, no relocation):
 *   ldr   r1, [r0, #0x1c]
 *   lsr   r2, r1, #0x18
 *   tst   r2, #1
 *   lslne r0, r1, #8
 *   lsrne r0, r0, #8
 *   ldreq r0, [r0, #8]
 *   bx    lr
 *
 * A compressed overlay reports the low 24-bit size field; an uncompressed
 * one reports ramSize.  The lsl/lsr pair is a 24-bit bitfield read.
 */

typedef unsigned int u32;

typedef struct
{
    u32 id;
    u32 ramAddress;
    u32 ramSize;
    u32 bssSize;
    u32 sinitStart;
    u32 sinitEnd;
    u32 fileId;
    u32 size : 24;
    u32 compressed : 8;
} FSOverlayInfo;

u32 FSi_GetOverlayBinarySize(FSOverlayInfo *p)
{
    if (p->compressed & 1)
        return p->size;
    return p->ramSize;
}
