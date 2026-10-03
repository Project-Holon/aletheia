/*
 * function: SND_SetPlayerChannelPriority
 * address:  0x020893E8
 * packet:   pkt_020893E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020897B4 0x020897B4 arm
 */

typedef unsigned int   u32;
extern void func_020897B4(int playerNo, u32 offset, u32 data, int size);

asm void SND_SetPlayerChannelPriority(void)
{
    ldr ip, =func_020897B4
    mov	r2, r1
    mov	r1, #4
    mov	r3, #1
    bx	ip
}
