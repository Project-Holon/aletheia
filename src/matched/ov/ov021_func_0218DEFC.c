/*
 * function: func_0218DEFC
 * address:  0x0218DEFC
 * packet:   pkt_ov021_0218DEFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02169598  0x02169598  thumb ov010
 *   func_021694FC  0x021694FC  thumb ov010
 *   func_02169538  0x02169538  thumb ov010
 */
#include "../include/Obj02689.h"

typedef unsigned char  u8;

typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_02169598(u8 *p);
extern u16 func_021694FC(u8 *p);
extern void func_02169538(unsigned char *a, int *out);

void func_0218DEFC(char *p, int o, int v)
{
    int a;
    int b;
    int t;
    int c;
    int i;

    if (func_02169598((u8 *)o) == 0)
        return;
    if (func_021694FC((u8 *)o) == 0)
        return;
    func_02169538((unsigned char *)o, &a);
    t = ((struct Obj02689 *)p)->f48 - a;
    for (i = ((struct Obj02689 *)p)->f41; i > 0; i--) {
        func_02169538((unsigned char *)(*(int *)(*(char * *)&((struct Obj02689 *)p)->f24 + *(u8 *)(((struct Obj02689 *)p)->f44 + i - 1) * 0x28)), &b);
        c = ((struct Obj02689 *)p)->f48 - b;
        if (c >= 0 && t >= c)
            break;
        if (t < 0)
            break;
        *(u8 *)(((struct Obj02689 *)p)->f44 + i) = *(u8 *)(((struct Obj02689 *)p)->f44 + i - 1);
    }
    *(u8 *)(((struct Obj02689 *)p)->f44 + i) = v;
    ((struct Obj02689 *)p)->f41 = ((struct Obj02689 *)p)->f41 + 1;
}
