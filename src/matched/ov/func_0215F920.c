/*
 * function: func_0215F920
 * address:  0x0215F920
 * packet:   pkt_0215F920
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008700Obj;

extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int func_020083E4();

int func_0215F920(int a0)
{
    int t4;
    void *big;
    struct Sub02008700Obj *obj;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 8);
    if (a0 != 1) goto loc_0215F92E;
loc_0215F92A:
a0 = 1;
    goto loc_0215F930;
loc_0215F92E:
a0 = 0;
loc_0215F930:
*(int *)((char *)t4 + 0x28) = a0;
a0 = *(int *)((char *)t4 + 4);
    big = func_02012EBC((struct Big *)a0);
loc_0215F938:
    obj = func_0200873C(big);
loc_0215F93C:
    a0 = func_020083E4(obj);
loc_0215F940:
*(int *)((char *)t4 + 0x2c) = a0;
*(int *)((char *)t4 + 0x30) = a0;
    return a0;}
