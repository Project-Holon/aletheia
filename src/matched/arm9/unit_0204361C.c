/*
 * unit:     yes
 * function: BG_SYS_ResetSubDisplay
 * address:  0x0204361C
 * packet:   pkt_0204361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Three display-control leaves, 0x0204361C-0x02043668.  The two after the
 * first save no lr, so disasm.py does not label them and they print as a
 * run of `.word`s between literal pools; neither has a branch reference
 * anywhere in the image, so folding them into this unit costs no witness.
 *
 *   0x0204361C  reset the sub engine, then turn on bit 16 of GXS_DISPCNT
 *   0x0204363C  write the LCD-swap bit (bit 15) of POWCNT1 from bit 0 of
 *               the argument; the plain `orr ..., lsl #15` with no
 *               narrowing says this is arithmetic on the register word, not
 *               a one-bit bitfield (which would carry an `lsr #16` shifter
 *               operand, see the bitfield-cast idiom)
 *   0x02043658  read back gVisiblePlane[1], the engine-B software copy
 *
 * symbols:
 *   GX_DispOn  0x0207D46C  arm
 *   gVisiblePlane  0x02146A48  data
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204361C.c \
 *       --addr 0x0204361C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 gVisiblePlane[2];

extern void GX_DispOn(void);

void BG_SYS_ResetSubDisplay(void)
{
    GX_DispOn();
    *(volatile u32 *)0x04001000 |= 0x10000;
}

void BG_SYS_SetLcdSwap(u32 swap)
{
    *(volatile u16 *)0x04000304 =
        (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
}

u32 BG_SYS_GetMainVisiblePlanes(void)
{
    return gVisiblePlane[1];
}
