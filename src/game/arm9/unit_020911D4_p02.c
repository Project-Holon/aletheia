/*
 * file:     unit_020911D4_p02.c
 * unit:     yes
 * function: func_02091220, func_02091230
 * address:  0x02091220
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
 *   func_0209124C    0x0209124C  thumb
 */
typedef unsigned int u32;

extern int func_02085D88(void);
extern void func_02088234(void);
extern void func_0209124C(u32 a, u32 b);
asm void func_02091220(void);
void func_02091230(u32 a, u32 b);

/*
 * A 16-byte Thumb-to-ARM linker veneer, the tail call target of the Thumb
 * wrapper at 0x02091200: Thumb `bx pc; nop`, then ARM `ldr ip, [pc]; bx ip` and the
 * pointer word 0x02731761, which lies in the TWL autoload block of arm9i (outside
 * every region of layout/layout.json).  No C spelling produces it; filed as an
 * asm function exactly as the precedent src/matched/func_02091284.c (the ARM
 * veneer of the same packet, docs/notes/pkt_020911D8.c.txt).  The ARM half is
 * written as dcd words because a Thumb asm function cannot switch mnemonics
 * set; the pointer word is a plain constant, not a relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091220.c  *       --func func_02091220 --addr 0x02091220 --cc 1.1p1 --thumb
 */
asm void func_02091220(void)
{
    bx pc
    nop
    dcd 0xE59FC000
    dcd 0xE12FFF1C
    dcd 0x02731761
}


/*
 * Two-argument flavour of func_020911D8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091230.c \
 *       --func func_02091230 --addr 0x02091230 --cc 1.1p1 --thumb
 */
void func_02091230(u32 a, u32 b)
{
    if (func_02085D88() == 0) {
        func_02088234();
    }
    func_0209124C(a, b);
}
