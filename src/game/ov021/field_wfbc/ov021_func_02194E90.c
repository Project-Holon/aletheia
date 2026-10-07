/*
 * function: func_02194E90
 * address:  0x02194E90
 * packet:   pkt_ov021_02194E90
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_0206E0C4  0x0206E0C4  arm
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj07453.h"
#include "../../../matched/include/Obj07454.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern void func_0206E0C4(int x, int y, void *c, int z);

void func_02194E90(u8 *e, u8 *ent, int *b, int *c, void *d)
{
    int x1;
    int y1;
    int w1;
    int h1;
    int x2;
    int y2;
    int w2;
    int h2;

    x1 = (func_02045758((struct Descriptor *)(((struct Obj07453 *)e)->fC)) - 1) << 3;
    y1 = (func_02045760((struct Descriptor *)(((struct Obj07453 *)e)->fC)) - 1) << 3;
    w1 = (func_02045748((struct Descriptor *)(((struct Obj07453 *)e)->fC)) + 2) << 3;
    h1 = (func_02045750((struct Descriptor *)(((struct Obj07453 *)e)->fC)) + 2) << 3;
    x2 = (func_02045758((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) - 1) << 3;
    y2 = (func_02045760((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) - 1) << 3;
    w2 = (func_02045748((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) + 2) << 3;
    h2 = (func_02045750((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) + 2) << 3;
    if (x1 + w1 < x2) {
        *b = x2;
    } else if (x1 > x2 + w2) {
        *b = x2 + w2;
    } else {
        *b = x2 + w2 / 2;
    }
    if (y1 + h1 < y2) {
        *c = y2;
    } else if (y1 > y2 + h2) {
        *c = y2 + h2;
    } else {
        *c = y2 + h2 / 2;
    }
    func_0206E0C4(*b, *c, d, 0);
}
