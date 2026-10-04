/*
 * function: func_021D2040
 * address:  0x021D2040
 * packet:   pkt_ov021_021D2040
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02103.h"

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
} Pt;

struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *a, struct PtS *p, unsigned int b);
extern void func_0204B404(u32 a, Pt *p, u32 b);

int func_021D2040(u8 *w)
{
    Pt pt;

    if (w[0x4c] == 0) {
        ((struct Obj02103 *)w)->f4D = -4;
    }
    if (((struct Obj02103 *)w)->f4D == -4) {
        ((struct Obj02103 *)w)->f4D = 3;
        w[0x4c] = w[0x4c] + 1;
        if (w[0x4c] == 3) {
            return 0;
        }
    }
    func_0204B454((struct Actor *)((struct Obj02103 *)w)->f3C, (struct PtS *)&pt, 0);
    pt.y = pt.y - ((struct Obj02103 *)w)->f4D;
    func_0204B404(((struct Obj02103 *)w)->f3C, &pt, 0);
    ((struct Obj02103 *)w)->f4D = ((struct Obj02103 *)w)->f4D - 1;
    return 1;
}
