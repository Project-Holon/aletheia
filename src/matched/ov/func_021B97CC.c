/*
 * function: WIFICLUBACTOR_UpdatePickRequests
 * address:  0x021B97CC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_UpdatePickRequest  0x021B9788  thumb  ov099
 *
 * Feeds every occupied one of the 0x30 records at +0x30 to the pair handler.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUBACTOR_UpdatePickRequest(int a, int *b);

void WIFICLUBACTOR_UpdatePickRequests(char *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32 *)(p + i * 0x1C + 0x30) != 0) {
            WIFICLUBACTOR_UpdatePickRequest((int)p, (int *)(p + 0x30 + i * 0x1C));
        }
    }
}
