/*
 * function: WIFICLUBACTOR_RegisterResources
 * address:  0x021B9DE4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_RegisterClactResources  0x021B9E50  thumb
 *
 * Tail call thunk onto WIFICLUBACTOR_RegisterClactResources.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_RegisterClactResources(void *a, int b, u32 c);

void WIFICLUBACTOR_RegisterResources(void *a, int b, u32 c)
{
    WIFICLUBACTOR_RegisterClactResources(a, b, c);
}
