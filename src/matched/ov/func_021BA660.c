/*
 * function: WIFICLUBACTOR_TickBlinkAll
 * address:  0x021BA660
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUBACTOR_TickBlinkFrame  0x021BA674  thumb
 *   WIFICLUBACTOR_TickBlinkScript  0x021BA6DC  thumb
 *
 * Runs the two arm9 setup routines on the second argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_TickBlinkFrame(void *a);
extern void WIFICLUBACTOR_TickBlinkScript(void *a);

void WIFICLUBACTOR_TickBlinkAll(int unused, void *p)
{
    WIFICLUBACTOR_TickBlinkFrame(p);
    WIFICLUBACTOR_TickBlinkScript(p);
}
