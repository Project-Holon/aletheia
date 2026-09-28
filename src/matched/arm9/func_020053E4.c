/*
 * function: func_020053E4
 * address:  0x020053E4
 * packet:   pkt_020053E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * An eight-byte ARM linker veneer, `ldr pc, [pc, #-4]; .word 0x0273154C`, the
 * long-branch stub a Thumb caller reaches with blx.  No C spelling produces
 * it (docs/idioms/an-arm-stub-pointing-outside-every-region-cannot-be-attested.md),
 * so it is written as an asm function, the same way the other hand-written
 * bodies under src/matched are; the pointer word is a plain constant, not a
 * relocation, because 0x0273154C lies outside every region of layout/layout.json.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020053E4.c  *       --func func_020053E4 --addr 0x020053E4 --cc 1.1p1 --arm
 */

asm void func_020053E4(void)
{
    ldr pc, [pc, #-4]
    dcd 0x0273154C
}
