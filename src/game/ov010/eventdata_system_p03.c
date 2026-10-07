/*
 * file:     eventdata_system_p03.c
 * unit:     yes
 * function: func_02161F14, func_02161F54
 * address:  0x02161F14
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021867C4  0x021867C4  thumb ov023
 *   func_0218682C  0x0218682C  thumb
 *   func_02186804  0x02186804  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02039338  0x02039338  arm
 */
#include "../../matched/include/Obj12331.h"
#include "../../matched/include/Obj17711.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021867C4(int, int);
extern u16 *func_0218682C(int h);
extern void func_02186804(int);
extern int func_02082BCC();
extern u16 func_02039338(void);
void func_02161F14(u16 *out, u8 *in, int c);
int func_02161F54(int a0);


void func_02161F14(u16 *out, u8 *in, int c)
{
    int h;
    u16 *q;
    if (((struct Obj12331 *)in)->f2 == 1) {
        h = func_021867C4(in[9], (u16)((c & 0x7FFF) | 0x8000));
        q = func_0218682C(h);
        out[0] = q[0x24 / 2];
        out[1] = q[8 / 2];
        func_02186804(h);
    } else {
        out[0] = 0;
        out[1] = 10;
    }
}


int func_02161F54(int a0)
{
    int a1;
    int a2;
    int t4;

a1 = 0;
a2 = 0x48;
t4 = a0 + 0;
    a0 = func_02082BCC(a0, a1, a2);
loc_02161F60:
    a0 = func_02039338();
loc_02161F64:
((struct Obj17711 *)((char *)t4))->f0 = a0;
    return a0;}
