/*
 * function: WIFICLUBACTOR_InitSprites
 * address:  0x021B9DC0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_RegisterResources  0x021B9DE4  thumb  ov099
 *   WIFICLUBACTOR_CreateCursorActors  0x021B9DF4  thumb  ov099
 *
 * Two registered setup steps.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_RegisterResources(void *a, int b, u32 c);
extern void WIFICLUBACTOR_CreateCursorActors(void *a, int b);

void WIFICLUBACTOR_InitSprites(void *a, u32 b, u32 c)
{
    WIFICLUBACTOR_RegisterResources(a, b, c);
    WIFICLUBACTOR_CreateCursorActors(a, b);
}
