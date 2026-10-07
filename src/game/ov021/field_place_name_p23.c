/*
 * file:     field_place_name_p23.c
 * unit:     yes
 * function: func_021BDB1C, func_021BDB5C, func_021BDB9C
 * address:  0x021BDB1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BF644  0x021BF644  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_021A7B20  0x021A7B20  thumb  ov021
 *   func_021BDBF8  0x021BDBF8  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */
#include "../../matched/include/Obj12894.h"
#include "../../matched/include/Obj09653.h"

struct Evt;
struct Args;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_021BF644(int a, int b, int c);
extern void func_021BDC80(u32 *);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02188C58(void *p);
extern void *func_021A7B20(struct Args *a);
extern int func_021BDBF8(u32 a);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
u32 func_021BDB1C(u32 a, int *st, u32 *ctx);
u32 func_021BDB5C(u32 a, int *st, u32 *ctx);
u32 func_021BDB9C(u32 a, int *st, u32 *ctx);


u32 func_021BDB1C(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = ((struct Obj12894 *)p)->f4;
    u32 y = ((struct Obj12894 *)p)->fC;

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BF644(0, x, y));
        (*st)++;
        break;
    case 1:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}


u32 func_021BDB5C(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[0];

    func_02188C58((void *)p[3]);
    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7B20((struct Args *)((u32)p)));
        (*st)++;
        break;
    case 1:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}


/*
 * Addresses are Black-image addresses.
 */
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
