/*
 * function: WIFICLUBACTOR_AddNetCommands
 * address:  0x021BA7D8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUBACTOR_GetCommandTable  0x021BA7CC  thumb  ov099
 *   WIFICLUBACTOR_GetCommandCount  0x021BA7D4  thumb  ov099
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *
 * Plays the 0x0A00 sound with the two constants and the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 *WIFICLUBACTOR_GetCommandTable(void);
extern int WIFICLUBACTOR_GetCommandCount(void);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);

void WIFICLUBACTOR_AddNetCommands(void *p)
{
    GFL_NET_COMMAND_AddCommandTable(0x0A00, (u32)WIFICLUBACTOR_GetCommandTable(), WIFICLUBACTOR_GetCommandCount(), (u32)p);
}
