/*
 * function: WIFICLUBACTOR_ApplyActorMode
 * address:  0x021BA5F0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_SetIdleState  0x021BA264  thumb  ov099
 *   WIFICLUBACTOR_SetBounceState  0x021BA2A4  thumb  ov099
 *
 * Dispatches on the class byte: case 0 runs WIFICLUBACTOR_SetIdleState, case 1 runs
 * WIFICLUBACTOR_SetBounceState, then the class is recorded at +0x0B of the object.  The pair
 * is a switch, not an if/else-if chain: only the switch form lays the case
 * bodies out of line the way the image does.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void WIFICLUBACTOR_SetIdleState(void *a, void *b);
extern void WIFICLUBACTOR_SetBounceState(void *w, u8 *s);

void WIFICLUBACTOR_ApplyActorMode(void *a, char *b, u8 c)
{
    switch (c) {
    case 0:
        WIFICLUBACTOR_SetIdleState(a, b);
        break;
    case 1:
        WIFICLUBACTOR_SetBounceState(a, (u8 *)b);
        break;
    }

    b[0xB] = c;
}
