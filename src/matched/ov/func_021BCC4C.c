/*
 * function: WIFICLUB_LoadOwnRegulation
 * address:  0x021BCC4C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_LoadPickedRegulation  0x021BCBD8  thumb
 *
 * Tail call onto WIFICLUB_LoadPickedRegulation with a zero second argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u32 WIFICLUB_LoadPickedRegulation(char *p, int m);

void WIFICLUB_LoadOwnRegulation(void *a)
{
    WIFICLUB_LoadPickedRegulation(a, 0);
}
