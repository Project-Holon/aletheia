/*
 * Calibration target, written from the disassembly only.  Bigger than the
 * three getters: a hardware register sequence plus a poll loop, so it also
 * exercises register allocation and loop shape rather than just addressing.
 *
 * function: FX_DivS32
 * address:  0x0207C958
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Original:
 *   ldr  r2, [pc, #0x2c]   ; 0x04000280
 *   mov  r3, #0
 *   strh r3, [r2]          ; DIVCNT = 0  (32 / 32 mode)
 *   str  r0, [r2, #0x10]   ; 0x04000290 numerator
 *   str  r1, [r2, #0x18]   ; 0x04000298 denominator, low word
 *   mov  r0, r3
 *   str  r0, [r2, #0x1c]   ; 0x0400029C denominator, high word
 *  .poll:
 *   ldrh r0, [r2]
 *   tst  r0, #0x8000
 *   bne  .poll
 *   ldr  r0, [pc, #8]      ; 0x040002A0
 *   ldr  r0, [r0]
 *   bx   lr
 *   .word 0x04000280
 *   .word 0x040002A0
 *
 * Everything here is a constant address, so no relocation is involved and a
 * correct reimplementation is EXACT rather than MATCH.
 *
 * The instruction that pins the source down is `mov r0, r3` at +0x14.  With
 * the denominator written as two separate 32-bit stores the compiler reuses
 * the zero already in r3 and the move disappears; the move only appears when
 * the denominator register is one 64-bit object assigned a 32-bit unsigned
 * value, because the zero-extended high word then has to be materialised as
 * the second half of a register pair.  That single instruction is the
 * difference between DIFF (31 concrete bytes) and EXACT.
 */

typedef signed int         s32;
typedef unsigned int       u32;
typedef unsigned short     u16;
typedef unsigned long long u64;

#define REG_DIVCNT      (*(volatile u16 *)0x04000280)
#define REG_DIV_NUMER   (*(volatile s32 *)0x04000290)
#define REG_DIV_DENOM   (*(volatile u64 *)0x04000298)
#define REG_DIV_RESULT  (*(volatile s32 *)0x040002A0)

#define DIVCNT_MODE_32_32 0x0000
#define DIVCNT_BUSY       0x8000

s32 FX_DivS32(s32 numer, s32 denom)
{
    REG_DIVCNT = DIVCNT_MODE_32_32;
    REG_DIV_NUMER = numer;
    REG_DIV_DENOM = (u32)denom;
    while (REG_DIVCNT & DIVCNT_BUSY) {
        /* wait for the divider */
    }
    return REG_DIV_RESULT;
}
