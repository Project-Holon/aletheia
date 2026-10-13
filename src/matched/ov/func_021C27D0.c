/*
 * function: WIFICLUB_GetStatusActionState
 * address:  0x021C27D0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte getter at +0x18.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x18];
    u8 f18;
} S;

u8 WIFICLUB_GetStatusActionState(S *s)
{
    return s->f18;
}
