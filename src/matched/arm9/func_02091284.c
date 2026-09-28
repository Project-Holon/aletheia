/*
 * function: func_02091284
 * address:  0x02091284
 * packet:   pkt_02091284
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * An eight-byte ARM linker veneer, `ldr pc, [pc, #-4]; .word 0x02731920`, the
 * long-branch stub reached from 0x0209125C.  No C spelling produces it
 * (docs/idioms/an-arm-stub-pointing-outside-every-region-cannot-be-attested.md),
 * so it is written as an asm function in the form of src/matched/func_02005B6C.c;
 * the pointer word is a plain constant, not a relocation, because 0x02731920
 * lies outside every region of layout/layout.json.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091284.c  *       --func func_02091284 --addr 0x02091284 --cc 1.1p1 --arm
 */

asm void func_02091284(void)
{
    ldr pc, [pc, #-4]
    dcd 0x02731920
}
