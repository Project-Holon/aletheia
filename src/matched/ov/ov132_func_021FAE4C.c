/*
 * function: func_021FAE4C
 * address: 0x021FAE4C
 * packet: pkt_ov132_021FAE4C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_0207CEE4 0x0207CEE4 arm
 */
#include "../include/Obj03288.h"
typedef unsigned short u16;
extern void func_0207CEE4(int, void *, void *, void *);
int func_021FAE4C(char *p, int *out)
{
    int v;
    (((struct Obj03288 *)p)->f2A)++;
    if (((struct Obj03288 *)p)->f2A >= ((struct Obj03288 *)p)->f28) {
        out[0] = ((struct Obj03288 *)p)->f10;
        out[1] = ((struct Obj03288 *)p)->f14;
        out[2] = ((struct Obj03288 *)p)->f18;
        return 1;
    }
    if (((struct Obj03288 *)p)->f2A != 0) v = (int)(0.5f + (float)(((struct Obj03288 *)p)->f2A << 12));
    else v = (int)((float)(((struct Obj03288 *)p)->f2A << 12) - 0.5f);
    func_0207CEE4(v, p + 0x1c, p + 4, out);
    return 0;
}
