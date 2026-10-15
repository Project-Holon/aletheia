/*
 * function: CARD_SPI_SetControl
 * address:  0x02180914
 * packet:   pkt_02180914
 * region:   ov231
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void CARD_SPI_SetControl(u16 v)
{
    *(volatile u16 *)0x040001A0 = v | 0xA000;
}
