/*
 * function: WIFICLUBACTOR_TickBlink
 * address:  0x021B9B64
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_TickBlinkAll  0x021BA660  thumb  ov099
 *
 * When bit 0 of the register at 0x02FFFC3C is set, hands the block 0x574 in to the setup pair.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_TickBlinkAll(int unused, void *p);

void WIFICLUBACTOR_TickBlink(char *p)
{
    if (*(u32 *)0x02FFFC3C & 1) {
        WIFICLUBACTOR_TickBlinkAll((int)p, p + 0x574);
    }
}
