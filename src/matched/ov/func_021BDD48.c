/*
 * function: WIFICLUB_GetStatusKind
 * address:  0x021BDD48
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUB_GetStatusActionState  0x021C27D0  thumb
 *
 * Tail call onto the byte getter WIFICLUB_GetStatusActionState on the second argument.
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

extern u8 WIFICLUB_GetStatusActionState(S *s);

u8 WIFICLUB_GetStatusKind(int unused, S *s)
{
    return WIFICLUB_GetStatusActionState(s);
}
