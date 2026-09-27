/*
 * function: G3X_GetBoxTestResult
 * address:  0x0207DEA4
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
 * Original (40 bytes, no relocation):
 *   ldr   r2, [pc, #0x1c]   ; 0x04000600
 *   ldr   r1, [r2]
 *   tst   r1, #1
 *   ldreq r1, [r2]
 *   mvnne r0, #0
 *   andeq r1, r1, #2
 *   streq r1, [r0]
 *   moveq r0, #0
 *   bx    lr
 */

typedef unsigned int u32;

int G3X_GetBoxTestResult(u32 *out)
{
    volatile u32 *p = (volatile u32 *)0x04000600;
    if (*p & 1)
        return -1;
    *out = *p & 2;
    return 0;
}
