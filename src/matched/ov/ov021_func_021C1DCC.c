/*
 * function: func_021C1DCC
 * address:  0x021C1DCC
 * packet:   pkt_ov021_021C1DCC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   abs_id_4A      0x0000004A  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F54E0  0x021F54E0  thumb  ov075
 *   func_021C1CB0  0x021C1CB0  thumb  ov021
 *   func_020124E8  0x020124E8  thumb
 *   func_021C313C  0x021C313C  thumb  ov021
 *   func_021C2D68  0x021C2D68  thumb  ov021
 *   func_021C2CF4  0x021C2CF4  thumb  ov021
 */
#include "../include/Obj01213.h"
#include "../include/Obj07558.h"

typedef unsigned char u8;

extern unsigned char abs_id_4A[];
int func_02034AC4(signed int id);
void func_02034A5C(int id);
int *func_021F54E0(int a);
int func_021C1CB0(int a, char *b, int c);
typedef unsigned int   u32;
struct Obj;
void *func_020124E8(struct Obj *p);
void func_021C313C(u32 a, u32 *p);
int func_021C2D68(int a, int *b);
int func_021C2CF4(void *a, u8 *p);

int func_021C1DCC(int a, char *b, int c, int d)
{
    int *q;
    int r;
    int x;
    int *s;

    func_02034AC4((int)abs_id_4A);
    q = func_021F54E0(c);
    r = func_021C1CB0(a, b, (u8)(*q));
    if (r == 0) {
        func_02034A5C((int)abs_id_4A);
        return 0;
    }
    x = (int)func_020124E8((struct Obj *)r);
    func_021C313C((u32)b, (u32 *)x);
    *(int *)&((struct Obj07558 *)x)->f3C = d;
    if (q[4] != 0)
        ((struct Obj01213 *)b)->f128 = func_021C2D68;
    else
        ((struct Obj01213 *)b)->f128 = 0;
    ((struct Obj01213 *)b)->f12C = func_021C2CF4;
    *(int *)&((struct Obj01213 *)b)->fC = 2;
    s = (int *)(b + 0x9c);
    ((struct Obj01213 *)b)->f9C = q[3];
    s[1] = q[1];
    s[2] = q[2];
    if (q[4] == 1)
        s[3] = 1;
    else
        s[3] = 0;
    if (q[0] == 0xd && s[3] != 0)
        s[4] = 1;
    else
        s[4] = 0;
    func_02034A5C((int)abs_id_4A);
    return r;
}
