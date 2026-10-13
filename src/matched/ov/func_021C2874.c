/*
 * function: WIFICLUB_GetStatusChangeCount
 * address:  0x021C2874
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte getter at +0x1C.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x1C];
    u8 f1C;
} S;

u8 WIFICLUB_GetStatusChangeCount(S *s)
{
    return s->f1C;
}
