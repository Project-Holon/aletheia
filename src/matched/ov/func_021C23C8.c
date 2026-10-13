/*
 * function: WIFICLUB_AddNetCommandsAndCheckFriend
 * address:  0x021C23C8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_AddNetCommands  0x021BA7D8  thumb
 *   sub_0203C2B0  0x0203C2B0  arm
 *
 * Two arm9/overlay calls, the first on the first argument and the second on the second.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_AddNetCommands(void *a);
extern int sub_0203C2B0(int a);

int WIFICLUB_AddNetCommandsAndCheckFriend(void *a, void *b)
{
    WIFICLUBACTOR_AddNetCommands(a);
    return sub_0203C2B0((int)b);
}
