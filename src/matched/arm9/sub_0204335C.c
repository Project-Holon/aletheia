/*
 * function: BG_SYS_ClearGraphicsMemory
 * address:  0x0204335C
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   func_0208068C  0x0208068C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_02080B98  0x02080B98  arm
 *
 * Blank the graphics state: disable every VRAM bank the caller's mask does
 * not name, then zero main VRAM (0x06800000, 0xa4000 bytes), both OAM
 * halves (0x07000000 and 0x07000400, filled with 0xc0 so every sprite sits
 * off-screen) and both palette halves (0x05000000 and 0x05000400).
 * func_02082AC0 is the four-byte-granular clear helper, taking the fill
 * word first and the destination second.
 *
 * The 0x1ff mask is never pooled: the compiler already has 0xffff in a
 * register for the complement and rematerialises 0x1ff from it with
 * `sub r0, r1, #0xfe00`
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 */

typedef unsigned int u32;

extern void func_0208068C(u32 banks);
extern void func_02082AC0(u32 data, void *dest, u32 size);
extern void func_02080B98(void);

void BG_SYS_ClearGraphicsMemory(u32 keep)
{
    func_0208068C((keep ^ 0xffff) & 0x1ff);

    func_02082AC0(0, (void *)0x06800000, 0xa4000);
    func_02080B98();

    func_02082AC0(0xc0, (void *)0x07000000, 0x400);
    func_02082AC0(0, (void *)0x05000000, 0x400);
    func_02082AC0(0xc0, (void *)0x07000400, 0x400);
    func_02082AC0(0, (void *)0x05000400, 0x400);
}
