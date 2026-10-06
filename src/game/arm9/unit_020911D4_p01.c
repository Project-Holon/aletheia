/*
 * file:     unit_020911D4_p01.c
 * unit:     yes
 * function: func_020911F0, func_02091200
 * address:  0x020911F0
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
 *   func_02091220    0x02091220  thumb
 */
typedef unsigned int u32;

extern int func_02085D88(void);
extern void func_02088234(void);
extern void func_02091220(u32 a, u32 b, u32 c);
asm void func_020911F0(void);
void func_02091200(u32 a, u32 b, u32 c);

/*
 * A 16-byte Thumb-to-ARM linker veneer, the tail call target of the Thumb
 * wrapper at 0x020911D8: Thumb `bx pc; nop`, then ARM `ldr ip, [pc]; bx ip` and the
 * pointer word 0x02731755, which lies in the TWL autoload block of arm9i (outside
 * every region of layout/layout.json).  No C spelling produces it; filed as an
 * asm function exactly as the precedent src/matched/func_02091284.c (the ARM
 * veneer of the same packet, docs/notes/pkt_020911D8.c.txt).  The ARM half is
 * written as dcd words because a Thumb asm function cannot switch mnemonics
 * set; the pointer word is a plain constant, not a relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020911F0.c  *       --func func_020911F0 --addr 0x020911F0 --cc 1.1p1 --thumb
 */
asm void func_020911F0(void)
{
    bx pc
    nop
    dcd 0xE59FC000
    dcd 0xE12FFF1C
    dcd 0x02731755
}


/*
 * Three-argument flavour of func_020911D8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091200.c \
 *       --func func_02091200 --addr 0x02091200 --cc 1.1p1 --thumb
 */
void func_02091200(u32 a, u32 b, u32 c)
{
    if (func_02085D88() == 0) {
        func_02088234();
    }
    func_02091220(a, b, c);
}
