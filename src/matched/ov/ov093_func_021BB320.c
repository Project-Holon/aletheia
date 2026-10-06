/*
 * function: func_021BB320
 * address:  0x021BB320
 * packet:   pkt_ov093_021BB320
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B9114  0x021B9114  thumb  ov093
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 */
#include "../include/Obj21033.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 func_021B9114(u8 **);
extern u32 func_020362DC(void);
extern int func_02035C60(void);

int func_021BB320(u8 *p, int *s)
{
    switch (*s) {
    case 0: {
        int r = 0;
        if (func_021B9114(*(u8 ** *)&((struct Obj21033 *)p)->fC) == 0) {
            if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) r = 1;
        } else {
            r = 1;
        }
        if (r != 0) {
            (*s)++;
            return 1;
        }
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}
