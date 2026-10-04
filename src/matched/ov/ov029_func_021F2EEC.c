/*
 * function: func_021F2EEC
 * address:  0x021F2EEC
 * packet:   pkt_ov029_021F2EEC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021F0194  0x021F0194  thumb  ov029
 *   func_021F2F60  0x021F2F60  thumb  ov029
 */
#include "../include/Obj00042.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_021F0194(u8 *p);
extern void func_021F2F60(void);

int func_021F2EEC(char *p, int k)
{
    int r = (int)func_020122C0((void *)(*(int *)&((struct Obj00042 *)p)->f1C), 0, func_021F2F60, 8);
    int *w = func_020124E8((struct Obj *)r);

    w[0] = (int)p;
    w[1] = k;
    switch (k) {
    case 1:
    case 5:
    case 6:
        func_021F0194((u8 *)w[0]);
        break;
    case 11:
        ((struct Obj00042 *)p)->f416 = 4;
        break;
    case 7:
        ((struct Obj00042 *)p)->f416 = 3;
        break;
    case 12:
        ((struct Obj00042 *)p)->f416 = 8;
        break;
    case 13:
        ((struct Obj00042 *)p)->f416 = 10;
        break;
    }
    return r;
}
