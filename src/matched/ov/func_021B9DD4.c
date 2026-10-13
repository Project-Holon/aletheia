/*
 * function: WIFICLUBACTOR_ExitSprites
 * address:  0x021B9DD4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_DeleteCursorActors  0x021B9DFC  thumb
 *   WIFICLUBACTOR_ReleaseResources  0x021B9DEC  thumb
 *
 * Fires the two thunks WIFICLUBACTOR_DeleteCursorActors and WIFICLUBACTOR_ReleaseResources on the same argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void WIFICLUBACTOR_DeleteCursorActors(void *a);
extern void WIFICLUBACTOR_ReleaseResources(void *a);

void WIFICLUBACTOR_ExitSprites(void *a)
{
    WIFICLUBACTOR_DeleteCursorActors(a);
    WIFICLUBACTOR_ReleaseResources(a);
}
