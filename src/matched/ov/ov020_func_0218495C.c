/*
 * function: func_0218495C
 * address:  0x0218495C
 * packet:   pkt_ov020_0218495C
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02184360  0x02184360  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_021BF61C  0x021BF61C  thumb  ov021
 *   func_021BFDD0  0x021BFDD0  thumb  ov021
 */
#include "../include/Obj04977.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *a);
struct Evt;
struct SaveBlock;
extern void *func_02161824(void *a, void *b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern void func_02029D44(u32 a, u32 b, u32 c, u32 d);
extern void func_02029D7C(int a, int b);
extern void *func_02184360(u8 *p, int value);
extern int func_02188D20(int a);
extern void func_021BC550(void *p, int v);
extern void *func_020127A4(struct SaveBlock *p);
extern void func_02012B2C(int a, int b);
extern void *func_021BF61C(int a, int b, int c);
extern void *func_021BFDD0(int a0, void *p, int a2, int a3);

int func_0218495C(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04977 *)p)->f0;
    y = ((struct Obj04977 *)p)->f4;
    z = ((struct Obj04977 *)p)->f8;
    v = func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        func_02012374((struct Evt *)ctx, func_021BFDD0(ctx, (void *)x, z, 1));
        (*state)++;
        break;
    case 2:
        func_02012B2C((int)func_020127A4((struct SaveBlock *)y), 0);
        func_02029D44(v, y, ((struct Obj04977 *)p)->f14, (u8)((struct Obj04977 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, func_02184360(p, 3));
        (*state)++;
        break;
    case 4:
        func_02012374((struct Evt *)ctx, func_021BF61C(ctx, x, z));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20(z), *(s16 *)&((struct Obj04977 *)p)->f14);
        return 1;
    }
    return 0;
}
