/*
 * function: WIFICLUBACTOR_SetMode
 * address:  0x021B98F8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the word at +0xC.  A leaf that saves nothing.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    u32 f00, f04, f08, f0C;
} S;

void WIFICLUBACTOR_SetMode(S *s, u32 v)
{
    s->f0C = v;
}
