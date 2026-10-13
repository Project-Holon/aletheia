/*
 * function: WIFICLUBACTOR_RestartBlink
 * address:  0x021B9B54
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_RestartBlinkScript  0x021BA7BC  thumb  ov099
 *
 * Tail call on the block 0x574 bytes in.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_RestartBlinkScript(char *p);

void WIFICLUBACTOR_RestartBlink(char *p)
{
    WIFICLUBACTOR_RestartBlinkScript(p + 0x574);
}
