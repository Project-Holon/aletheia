/*
 * function: WIFICLUBACTOR_RemoveNetCommands
 * address:  0x021BA7F8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_0203A5E4  0x0203A5E4  arm
 *
 * Tail call onto the arm9 routine with 0xA00.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void sub_0203A5E4(u32 key);

void WIFICLUBACTOR_RemoveNetCommands(char *a0)
{
    sub_0203A5E4(0xA00);
}
