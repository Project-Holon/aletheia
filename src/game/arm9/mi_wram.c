/*
 * file:     mi_wram.c
 * function: MI_SetWramBank
 * address:  0x020821B0
 * packet:   pkt_020821B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

void MI_SetWramBank(u32 bank)
{
    *(volatile unsigned char *)0x04000247 = (unsigned char)bank;
}
