/*
 * function: G3X_GetMtxStackLevelPV
 * address:  0x0207DE30
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
 * Original (44 bytes, no relocation):
 *   ldr   r2, [pc, #0x20]   ; 0x04000600
 *   ldr   r1, [r2]
 *   tst   r1, #0x4000
 *   ldreq r1, [r2]
 *   mvnne r0, #0
 *   andeq r1, r1, #0x1f00
 *   lsreq r1, r1, #8
 *   streq r1, [r0]
 *   moveq r0, #0
 *   bx    lr
 */

typedef unsigned int u32;

int G3X_GetMtxStackLevelPV(u32 *out)
{
    volatile u32 *p = (volatile u32 *)0x04000600;
    if (*p & 0x4000)
        return -1;
    *out = (*p & 0x1f00) >> 8;
    return 0;
}
