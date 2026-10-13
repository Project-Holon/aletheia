/*
 * function: WIFICLUBACTOR_RequestBlinkRestart
 * address:  0x021BA78C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sets the byte at +0x10 to 1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x10];
    u8 f10;
} S;

void WIFICLUBACTOR_RequestBlinkRestart(S *s)
{
    s->f10 = 1;
}
