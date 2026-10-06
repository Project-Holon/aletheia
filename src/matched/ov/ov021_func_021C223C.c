/*
 * function: func_021C223C
 * address:  0x021C223C
 * packet:   pkt_ov021_021C223C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   func_0204779C  0x0204779C  arm
 *   func_020478B8  0x020478B8  arm
 */
#include "../include/Obj05076.h"

typedef unsigned char u8;
typedef unsigned short u16;

unsigned int func_020489F4(u8 *a0, int i);
typedef unsigned int   u32;
u32 func_02048A18(u8 *a0, int i);
int func_0204779C(int *p);
int func_020478B8(void *a, int idx, int amount);

int func_021C223C(char *p)
{
    int a;
    u8 k;
    int r;
    int n;

    if (((struct Obj05076 *)p)->f80 == 0)
        return 1;
    if (((struct Obj05076 *)p)->f60 != 0) {
        (((struct Obj05076 *)p)->f60)--;
    } else {
        a = func_02048A18((u8 *)(((struct Obj05076 *)p)->f14), (int)func_020489F4((u8 *)(((struct Obj05076 *)p)->f14), (u16)(((struct Obj05076 *)p)->f18)));
        n = func_0204779C((int *)a);
        for (k = 0; k < n; k++)
            r = func_020478B8((void *)a, k, 0x1000);
        if (r == 0)
            return 1;
    }
    return 0;
}
