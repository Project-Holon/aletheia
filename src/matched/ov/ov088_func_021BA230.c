/*
 * function: func_021BA230
 * address:  0x021BA230
 * packet:   pkt_ov088_021BA230
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB840  0x021BB840  thumb  ov088
 *   func_021BB810  0x021BB810  thumb  ov088
 */
#include "../include/Obj01369.h"

extern int func_021BB840(char *p, int y);
extern void func_021BB810(void *, int, int, int);

int func_021BA230(char *p)
{
    switch (((struct Obj01369 *)p)->f12D) {
    case 0:
    case 2:
        if (((struct Obj01369 *)p)->f12E == 0) {
            func_021BB810(p, *(unsigned char *)(p + ((struct Obj01369 *)p)->f128 + 0x120),
                          func_021BB840(p, ((struct Obj01369 *)p)->f12F), 3);
            ((struct Obj01369 *)p)->f12E = 4;
            ((struct Obj01369 *)p)->f12D = ((struct Obj01369 *)p)->f12D + 1;
        } else {
            ((struct Obj01369 *)p)->f12E -= 1;
        }
        break;
    case 1:
    case 3:
        if (((struct Obj01369 *)p)->f12E == 0) {
            func_021BB810(p, *(unsigned char *)(p + ((struct Obj01369 *)p)->f128 + 0x120),
                          func_021BB840(p, ((struct Obj01369 *)p)->f12F), 1);
            ((struct Obj01369 *)p)->f12E = 4;
            ((struct Obj01369 *)p)->f12D = ((struct Obj01369 *)p)->f12D + 1;
        } else {
            ((struct Obj01369 *)p)->f12E -= 1;
        }
        break;
    case 4:
        return ((struct Obj01369 *)p)->f140;
    }
    return 3;
}
