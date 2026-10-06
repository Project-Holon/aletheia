/*
 * file:     unit_020911D4_p03.c
 * unit:     yes
 * function: func_0209124C, func_0209125C
 * address:  0x0209124C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02085D88    0x02085D88  arm
 *   func_02088234    0x02088234  arm
 *   func_02091284    0x02091284  arm
 */
typedef unsigned int u32;

extern int func_02085D88(void);
extern void func_02088234(void);
extern void func_02091284(u32 a, u32 b, u32 c, u32 d, u32 e);
asm void func_0209124C(void);
void func_0209125C(u32 a, u32 b, u32 c, u32 d, u32 e);

/*
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


/*
 * Five-argument flavour: the fifth parameter is spilled back to [sp] for the
 * ARM-side callee, which is why the frame carries one extra word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0209125C.c \
 *       --func func_0209125C --addr 0x0209125C --cc 1.1p1 --thumb
 */
void func_0209125C(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if (func_02085D88() == 0) {
        func_02088234();
    }
    func_02091284(a, b, c, d, e);
}
