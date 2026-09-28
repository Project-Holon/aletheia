/*
 * function: func_0209124C
 * address:  0x0209124C
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A 16-byte Thumb-to-ARM linker veneer, the tail call target of the Thumb
 * wrapper at 0x02091230: Thumb `bx pc; nop`, then ARM `ldr ip, [pc]; bx ip` and the
 * pointer word 0x02731765, which lies in the TWL autoload block of arm9i (outside
 * every region of layout/layout.json).  No C spelling produces it; filed as an
 * asm function exactly as the precedent src/matched/func_02091284.c (the ARM
 * veneer of the same packet, docs/notes/pkt_020911D8.c.txt).  The ARM half is
 * written as dcd words because a Thumb asm function cannot switch mnemonics
 * set; the pointer word is a plain constant, not a relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0209124C.c  *       --func func_0209124C --addr 0x0209124C --cc 1.1p1 --thumb
 */

asm void func_0209124C(void)
{
    bx pc
    nop
    dcd 0xE59FC000
    dcd 0xE12FFF1C
    dcd 0x02731765
}
