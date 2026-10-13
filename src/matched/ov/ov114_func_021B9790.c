/*
 * function: func_021B9790
 * address: 0x021B9790
 * packet: pkt_ov114_021B9790
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021BF488 0x021BF488 arm ov114
 * func_021BF4B0 0x021BF4B0 arm ov114
 * func_021BE838 0x021BE838 arm ov114
 * func_021B9774 0x021B9774 thumb ov114
 * GFL_NET_STATE_SetError 0x0203C9AC arm
 */
#include "../include/Obj03763.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BF488(int a);
extern int func_021BF4B0(u32, int *, int *);
extern int func_021BE838(void *handle, char **value_pp);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern void func_021B9774(u8 *);
int func_021B9790(u8 *p)
{
    int a,b,c;
    int result;
    if (p == 0) return -1;
    if (((struct Obj03763 *)p)->fC == 0) return 0;
    result = func_021BF488(((struct Obj03763 *)p)->fC);
    if (result == 15) {
        func_021BF4B0(((struct Obj03763 *)p)->fC, &a, &b);
    } else {
        int x = func_021BF488(((struct Obj03763 *)p)->fC);
        if (x == 0) func_021BE838((void *)(((struct Obj03763 *)p)->fC), (char **)(&c));
        else GFL_NET_STATE_SetError(x, 2, x, 0x3f6);
        func_021B9774(p);
        return result;
    }
    return result;
}
