/*
 * function: func_02187508
 * address:  0x02187508
 * packet:   pkt_ov020_02187508
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02191388  0x02191388  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_021912D8  0x021912D8  thumb  ov021
 *   func_021912F8  0x021912F8  thumb  ov021
 */
#include "../include/Obj00128.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Handle;
extern u32 func_02191388(u32 *a);
extern u32 func_020362DC(void);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_02190C78(struct Handle *h);
extern int func_021909BC(void *a);
extern int func_021912D8(u32 a);
extern int func_021912F8(int);

int func_02187508(char *p)
{
    int r;

    switch (((struct Obj00128 *)p)->f52) {
    case 0:
        if (func_02191388((u32 *)(*(int *)&((struct Obj00128 *)p)->f10)) == 0)
            break;
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 1:
        if ((func_020362DC() & 0xf3) == 0)
            break;
        if (((struct Obj00128 *)p)->f55 == 0)
            ((struct Obj00128 *)p)->f52 = 4;
        else
            ((struct Obj00128 *)p)->f52 = 2;
        break;
    case 2:
        *(int *)&((struct Obj00128 *)p)->f14 = (int)func_02190BE4((u16 *)(((struct Obj00128 *)p)->fC), 0);
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 3:
        r = func_02190C78((struct Handle *)(*(int *)&((struct Obj00128 *)p)->f14));
        if (r == 2)
            break;
        if (r == 0)
            ((struct Obj00128 *)p)->f54 = 1;
        else
            ((struct Obj00128 *)p)->f54 = 0;
        ((struct Obj00128 *)p)->f52 = 4;
        func_021909BC((void *)(*(int *)&((struct Obj00128 *)p)->f14));
        *(int *)&((struct Obj00128 *)p)->f14 = 0;
        break;
    case 4:
        func_021912D8(*(int *)&((struct Obj00128 *)p)->f10);
        ((struct Obj00128 *)p)->f52 = ((struct Obj00128 *)p)->f52 + 1;
        break;
    case 5:
        if (func_021912F8(*(int *)&((struct Obj00128 *)p)->f10) != 0) {
            *(int *)&((struct Obj00128 *)p)->f10 = 0;
            return 1;
        }
        break;
    }
    return 0;
}
