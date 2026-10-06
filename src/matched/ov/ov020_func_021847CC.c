/*
 * function: func_021847CC
 * address:  0x021847CC
 * packet:   pkt_ov020_021847CC
 * region:   ov020
 * compiler: dsi/1.1p1
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
 *   func_0218403C  0x0218403C  thumb  ov020
 *   func_02184360  0x02184360  thumb  ov020
 *   func_02185F48  0x02185F48  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BF5B4  0x021BF5B4  thumb  ov021
 *   func_021BFD70  0x021BFD70  thumb  ov021
 */
#include "../include/Obj00082.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
struct Evt;
extern void *func_02161824(void *a, void *b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern void func_02029D44(u32 a, u32 b, u32 c, u32 d);
extern void func_02029D7C(int a, int b);
extern void func_0218403C(u8 *p);
extern void *func_02184360(u8 *p, int value);
extern void func_02185F48(void *p);
extern u32 func_02188D20(u8 *p);
extern void func_021BC550(void *p, int v);
extern void *func_021BF5B4(int a, int b, int c, int d, int e, int f);
extern void *func_021BFD70(int a0, void *p, int a2, int a3);

int func_021847CC(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = *(int *)&((struct Obj00082 *)p)->f0;
    y = ((struct Obj00082 *)p)->f4;
    z = *(int *)&((struct Obj00082 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_021BFD70(ctx, (void *)x, z, ((struct Obj00082 *)p)->f44));
        (*state)++;
        break;
    case 2:
        func_02185F48((void *)y);
        func_02029D44(v, y, ((struct Obj00082 *)p)->f14, (u8)((struct Obj00082 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 2));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, func_021BF5B4(ctx, x, z, ((struct Obj00082 *)p)->f44,
                                         ((struct Obj00082 *)p)->f48, ((struct Obj00082 *)p)->f4A));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj00082 *)p)->f14);
        return 1;
    }
    return 0;
}
