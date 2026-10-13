/*
 * function: func_0215AA90
 * address:  0x0215AA90
 * packet:   pkt_0215AA90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008700Obj;
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int CONFIG_GetAppliedFlag(unsigned short *p);

int func_0215AA90(int a0, int a1)
{
    int t5;
    int t6;
    void *p;
    struct Sub02008700Obj *t4;
    u16 *q;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AA9C:
    p = func_02012EBC((struct Big *)v0);
loc_0215AAA0:
    t4 = func_0200873C(p);
loc_0215AAA4:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AAAE:
    a0 = CONFIG_GetAppliedFlag((short unsigned int *)t4);
loc_0215AAB6:
*q = a0;
a0 = 0;
    return a0;}
