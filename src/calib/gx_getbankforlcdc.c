/*
 * Calibration target, written from the disassembly only.
 *
 * function: GX_GetBankForLCDC
 * address:  0x0207D41C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Original:
 *   ldr  r0, [pc, #4]   ; &sVramLcdcMask
 *   ldrh r0, [r0]
 *   bx   lr
 *   .word <sVramLcdcMask>
 *
 * One halfword read of a file-scope u16, returned widened.  ldrh already
 * zero-extends, so the return type has to be a 16-bit unsigned one for the
 * compiler to omit any further masking.  The literal is an ABS32
 * relocation and is wildcarded.
 */

typedef unsigned short u16;

extern u16 sVramLcdcMask;

u16 GX_GetBankForLCDC(void)
{
    return sVramLcdcMask;
}
