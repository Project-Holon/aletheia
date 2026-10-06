/*
 * function: func_02184584
 * address:  0x02184584
 * packet:   pkt_ov020_02184584
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_0218403C  0x0218403C  thumb  ov020
 *   func_02184360  0x02184360  thumb  ov020
 *   func_021BE89C  0x021BE89C  thumb  ov021
 *   func_021BE8B8  0x021BE8B8  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 */
#include "../include/Obj00082.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct Evt;
extern void *func_02161824(void *a, void *b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_0218403C(u8 *p);
extern void *func_02184360(u8 *p, int value);
typedef unsigned int   u32;
extern int func_021BE89C(int a, u32 b);
extern int func_021BE8B8(int a, int b);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int func_02184584(int ctx, int *state, u8 *p)
{
    int x;
    int z;

    x = *(int *)&((struct Obj00082 *)p)->f0;
    z = *(int *)&((struct Obj00082 *)p)->f8;

    switch (*state) {
    case 0:
        func_0218403C(p);
        func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        if (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 0, 0));
        } else {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, func_021BE89C(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14), 0));
        }
        (*state)++;
        break;
    case 2:
        func_02012374((struct Evt *)ctx, func_02184360(p, ((struct Obj00082 *)p)->f30));
        (*state)++;
        break;
    case 3:
        if (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 3, 0, 0, (u8)((struct Obj00082 *)p)->f48, (u8)((struct Obj00082 *)p)->f4A));
        } else {
            func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, func_021BE8B8(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14), 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
