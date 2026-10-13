/*
 * function: WIFICLUBACTOR_EndBlinkScript
 * address:  0x021BA770
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets bit f0C of the byte at +0x08, then clears the four fields from +0x0C.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[8];
    u8 f08;
    char pad2[3];
    u8 f0C;
    u8 f0D;
    u16 f0E;
    u8 f10;
} S;

void WIFICLUBACTOR_EndBlinkScript(S *s)
{
    s->f08 = (u8)(s->f08 | (u8)(1 << s->f0C));
    s->f0C = 0;
    s->f0D = 0;
    s->f0E = 0;
    s->f10 = 0;
}
