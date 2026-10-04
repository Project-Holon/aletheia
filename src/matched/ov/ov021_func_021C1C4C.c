/*
 * function: func_021C1C4C
 * address:  0x021C1C4C
 * packet:   pkt_ov021_021C1C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02048AD0  0x02048AD0  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02047A60  0x02047A60  arm
 */
#include "../include/Obj03141.h"

typedef unsigned char u8;
typedef unsigned short u16;

struct Arg;
struct Light;
void func_02048AD0(struct Light *l);
int func_020489F4(int a, u16 b);
int func_02048A00(int a, u16 b);
int func_02048A18(int a, u16 b);
void func_02047A60(void *a0, struct Arg *a1);

void func_021C1C4C(char *p)
{
    int a;
    int n;
    int i;
    u8 k;

    if (((struct Obj03141 *)p)->fC == 0)
        func_02048AD0((struct Light *)(((struct Obj03141 *)p)->f4));
    else
        func_02048AD0((struct Light *)(((struct Obj03141 *)p)->f8));
    if (((struct Obj03141 *)p)->f18 != -1) {
        a = func_020489F4(((struct Obj03141 *)p)->f14, ((struct Obj03141 *)p)->f18);
        n = func_02048A00(((struct Obj03141 *)p)->f14, ((struct Obj03141 *)p)->f18);
        for (k = 0; k < n; k++) {
            i = func_02048A18(((struct Obj03141 *)p)->f14, a + k);
            func_02047A60((void *)i, (struct Arg *)(p + 0x1c));
        }
    }
}
