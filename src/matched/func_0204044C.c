/*
 * function: func_0204044C
 * address:  0x0204044C
 * packet:   pkt_0204044C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *
 * Set the two low bits of DISPCNT (0x04000008) to the incoming mode, after
 * asking func_020434DC for the display to be brought up in mode 1.  The
 * register is a cast constant, not a relocation: its address is the pool
 * word at the end of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204044C.c \
 *       --func func_0204044C --addr 0x0204044C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020434DC(int a, int b);

void func_0204044C(u32 mode)
{
    func_020434DC(1, 1);
    *(volatile u16 *)0x04000008 =
        (*(volatile u16 *)0x04000008 & ~3) | mode;
}
