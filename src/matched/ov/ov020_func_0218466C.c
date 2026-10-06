/*
 * function: func_0218466C
 * address:  0x0218466C
 * packet:   pkt_ov020_0218466C
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
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */
#include "../include/Obj04190.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *a);
struct Evt;
extern void *func_02161824(void *a, void *b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern void func_02029D44(u32 a, u32 b, u32 c, u32 d);
extern void func_02029D7C(int a, int b);
extern void *func_02184360(u8 *p, int value);
extern u32 func_02188D20(u8 *p);
extern void func_021BC550(void *p, int v);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int func_0218466C(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04190 *)p)->f0;
    y = ((struct Obj04190 *)p)->f4;
    z = ((struct Obj04190 *)p)->f8;
    v = (int)func_02012A30((const struct BigObj *)y);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 8:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 2, 0));
        (*state)++;
        break;
    case 9:
        func_02029D44(v, y, ((struct Obj04190 *)p)->f14, (u8)((struct Obj04190 *)p)->f4A);
        func_02029D7C(v, y);
        (*state)++;
        break;
    case 10:
        func_02012374((struct Evt *)ctx, func_02184360(p, ((struct Obj04190 *)p)->f30));
        (*state)++;
        break;
    case 11:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 2, 0, 0, 0, 0));
        (*state)++;
        break;
    case 12:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)&((struct Obj04190 *)p)->f14);
        return 1;
    default:
        (*state)++;
        break;
    }
    return 0;
}
