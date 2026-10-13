/*
 * function: WIFICLUB_GetMessageIdByIndex
 * address:  0x021BA81C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWifiClubMessageIdTable  0x021C39E0  data  a4
 *
 * Word getter at index i of the table at 0x021C39E0.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u32 gWifiClubMessageIdTable[];

u32 WIFICLUB_GetMessageIdByIndex(int i)
{
    return gWifiClubMessageIdTable[i];
}
