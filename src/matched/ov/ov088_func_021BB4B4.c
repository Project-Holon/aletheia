/*
 * function: func_021BB4B4
 * address:  0x021BB4B4
 * packet:   pkt_ov088_021BB4B4
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020071EC  0x020071EC  thumb
 *   func_0200C308  0x0200C308  thumb
 */
#include "../include/Obj00014.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Blk34;
struct Sub020071E4Ctrl;
extern u8 func_020071EC(const struct Sub020071E4Ctrl *ctrl);
extern u8 func_0200C308(struct Blk34 *p, u32 i);

void func_021BB4B4(char *p)
{
    unsigned i = 0;
    if (func_020071EC(((struct Obj00014 *)p)->f0) == 1) {
        p[0x120] = 0;
        i++;
    }
    (p + i)[0x120] = 1;
    (p + i)[0x121] = 2;
    i += 2;
    if (func_0200C308(((struct Obj00014 *)p)->f8, 1)) {
        (p + i)[0x120] = 3;
        i++;
    }
    if (func_0200C308(((struct Obj00014 *)p)->f8, 2)) {
        (p + i)[0x120] = 4;
        i++;
    }
    (p + i)[0x120] = 5;
    (p + i)[0x121] = 6;
    i += 2;
    if (func_0200C308(((struct Obj00014 *)p)->f8, 3)) {
        (p + i)[0x120] = 7;
        i++;
    }
    while (i < 8) {
        (p + i)[0x120] = 8;
        i++;
    }
}
