/*
 * function: func_0215E068
 * address:  0x0215E068
 * packet:   pkt_0215E068
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 72 compiled 70
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_021FCE00  0x021FCE00  thumb
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern int func_02012F80(char *base);
extern void func_02156BAC(void *p);
extern u32 func_02156BCC(void *p);
extern int func_021FCE00();

int func_0215E068(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215E072:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215E078:
    a0 = func_02012F80(v1);
loc_0215E07C:
t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    if (a0 == 0) goto loc_0215E096;
loc_0215E084:
    func_02156BAC((void *)a0);
loc_0215E088:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    a0 = func_02156BCC((void *)a0);
loc_0215E08E:
    if (a0 != 1) goto loc_0215E096;
loc_0215E092:
a0 = 1;
    return a0;
loc_0215E096:
a1 = ((struct Obj00005 *)t4)->f34;
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
a1 = a1 << 0x18;
a1 = (unsigned)a1 >> 0x18;
    a0 = func_021FCE00(a0, a1);
loc_0215E0A2:
    if (a0 != 1) goto loc_0215E0AA;
loc_0215E0A6:
a0 = 1;
    return a0;
loc_0215E0AA:
a0 = 0;
    return a0;}
