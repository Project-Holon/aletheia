/*
 * function: WIFICLUBACTOR_SetActorMode
 * address:  0x021B9B00
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFICLUBACTOR_IsNotWalkBobbing  0x021BA5DC  thumb  ov099
 *   WIFICLUBACTOR_ApplyActorMode  0x021BA5F0  thumb  ov099
 *
 * Stores the byte at +0x0B of b when b is not claimed, else hands it to the arm9 owner.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int WIFICLUBACTOR_IsNotWalkBobbing(void *b);
extern void WIFICLUBACTOR_ApplyActorMode(void *a, char *b, u8 c);

void WIFICLUBACTOR_SetActorMode(void *a, char *b, u8 c)
{
    if (WIFICLUBACTOR_IsNotWalkBobbing(b) == 0) {
        b[0xB] = c;
    } else {
        WIFICLUBACTOR_ApplyActorMode(a, b, c);
    }
}
