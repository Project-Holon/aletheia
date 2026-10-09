/*
 * file:     unit_020911D4_p02.c
 * unit:     yes
 * function: func_020911D8, func_020911F0, func_02091200, func_02091220, func_02091230, func_0209124C, func_0209125C
 * address:  0x020911D8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thumb wrappers over the ARM-side entries, each followed by the Thumb-to-ARM
 * linker veneer it tail calls.  The wrappers abort when the check fails, then
 * hand their arguments across the veneer.  func_020911D8 takes one argument,
 * func_02091200 three, func_02091230 two and func_0209125C five (the fifth is
 * spilled back to [sp] for the ARM-side callee, which is why that frame
 * carries one extra word).
 *
 * Each veneer is 16 bytes: Thumb `bx pc; nop`, then ARM `ldr ip, [pc]; bx ip`
 * and a pointer word (0x02731755, 0x02731761, 0x02731765) that lies in the TWL
 * autoload block of arm9i, outside every region of layout/layout.json.  No C
 * spelling produces it; each is an asm function.  The ARM half is written as
 * dcd words because a Thumb asm function cannot switch mnemonics set; the
 * pointer word is a plain constant, not a relocation.  The veneers carry the
 * parameter list of the wrapper's call so that one prototype serves both.
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
asm void func_020911F0(u32 a);
asm void func_02091220(u32 a, u32 b, u32 c);
asm void func_0209124C(u32 a, u32 b);
void func_020911D8(u32 a);
void func_02091200(u32 a, u32 b, u32 c);
void func_02091230(u32 a, u32 b);
void func_0209125C(u32 a, u32 b, u32 c, u32 d, u32 e);


/*
 * Thumb wrapper over the ARM-side entry: aborts when the check fails, then
 * hands the argument across the Thumb/ARM stub at 0x020911F0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020911D8.c \
 *       --func func_020911D8 --addr 0x020911D8 --cc 1.1p1 --thumb
 */
void func_020911D8(u32 a)
{
    if (func_02085D88() == 0) {
        func_02088234();
    }
    func_020911F0(a);
}


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
asm void func_020911F0(u32 a)
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
asm void func_02091220(u32 a, u32 b, u32 c)
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
asm void func_0209124C(u32 a, u32 b)
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
