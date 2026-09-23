/*
 * function: func_02005B6C
 * address:  0x02005B6C
 * packet:   pkt_02005B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * An eight-byte ARM linker veneer, `ldr pc, [pc, #-4]; .word 0x02704364`, the
 * long-branch stub a Thumb caller reaches with blx.  No C spelling produces
 * it (docs/idioms/an-arm-stub-pointing-outside-every-region-cannot-be-attested.md),
 * so it is written as an asm function, the same way the other hand-written
 * bodies under src/matched are; the pointer word is a plain constant, not a
 * relocation, because 0x02704364 lies outside every region of layout/layout.json.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02005B6C.c  *       --func func_02005B6C --addr 0x02005B6C --cc 1.1p1 --arm
 */

asm void func_02005B6C(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02704364
}
