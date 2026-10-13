/*
 * function: WIFICLUB_GetSlotState
 * address:  0x021C2050
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte getter at index i of the 0x8CB table.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

u8 WIFICLUB_GetSlotState(char *p, int i)
{
    return *(u8 *)(p + i + 0x8CB);
}
