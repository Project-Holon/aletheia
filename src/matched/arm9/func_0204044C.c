/*
 * function: BG_SYS_EnableBg0WithPriority
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
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *
 * Set the two low bits of DISPCNT (0x04000008) to the incoming mode, after
 * asking BG_SYS_SetMainPlaneVisible for the display to be brought up in mode 1.  The
 * register is a cast constant, not a relocation: its address is the pool
 * word at the end of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_EnableBg0WithPriority.c \
 *       --func BG_SYS_EnableBg0WithPriority --addr 0x0204044C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

void BG_SYS_EnableBg0WithPriority(u32 mode)
{
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile u16 *)0x04000008 =
        (*(volatile u16 *)0x04000008 & ~3) | mode;
}
