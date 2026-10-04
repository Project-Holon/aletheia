/*
 * function: func_021BDB9C
 * address:  0x021BDB9C
 * packet:   pkt_ov021_021BDB9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDBF8  0x021BDBF8  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09653.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
extern int func_021BDBF8(u32 a);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_021BDC80(u32 *);
extern void func_02012374(struct Evt *evt, struct Evt **out);

u32 func_021BDB9C(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj09653 *)p)->f4;
    u32 y = ((struct Obj09653 *)p)->fC;

    switch (*st) {
    case 0:
        if (((struct Obj09653 *)p)->f48 != 0)
            func_021BDBF8((u32)ctx);
        (*st)++;
        break;
    case 1:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE92C((void *)x, y, 2, 0, 0, 0, 0));
        (*st)++;
        break;
    case 2:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}
