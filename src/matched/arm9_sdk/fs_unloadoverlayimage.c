/*
 * function: FS_UnloadOverlayImage
 * address:  0x02079254
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FS_EndOverlay  0x02079164  arm
 *
 * Original (16 bytes):
 *   push {r3, lr}
 *   bl   #0x02079164
 *   mov  r0, #1
 *   pop  {r3, pc}
 *
 * One call, then TRUE.
 */

typedef int BOOL;

extern void FS_EndOverlay(void);

BOOL FS_UnloadOverlayImage(void)
{
    FS_EndOverlay();
    return 1;
}
