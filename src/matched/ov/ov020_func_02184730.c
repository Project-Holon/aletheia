/*
 * function: func_02184730
 * address:  0x02184730
 * packet:   pkt_ov020_02184730
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02184360  0x02184360  thumb  ov020
 *   func_021BF58C  0x021BF58C  thumb  ov021
 *   func_021BFD34  0x021BFD34  thumb  ov021
 */
#include "../include/Obj05964.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
struct Evt;
extern void *func_02161824(void *a, void *b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern void func_02029D44(u32 a, u32 b, u16 c, u8 d);
extern void func_02029D7C(int a, int b);
extern void *func_02184360(u8 *p, int value);
extern void *func_021BF58C(int a, void *p, int c);
extern int func_021BFD34(int ctx, int a, int b, u8 *p);

int func_02184730(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj05964 *)p)->f0;
    y = ((struct Obj05964 *)p)->f4;
    z = ((struct Obj05964 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BFD34(ctx, x, z, p + 0x34));
        (*state)++;
        break;
    case 2:
        func_02029D44(v, y, ((struct Obj05964 *)p)->f14, (u8)((struct Obj05964 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BF58C(ctx, (void *)x, z));
        (*state)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
