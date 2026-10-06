/*
 * function: func_0215850C
 * address:  0x0215850C
 * packet:   pkt_0215850C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0200855C  0x0200855C  thumb
 *   func_02008530  0x02008530  thumb
 *   func_021584F4  0x021584F4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
struct Sub24;
struct Rec44;
struct Sub02014444Obj;
extern int func_02158344(int a0);
extern void *func_02012B38(const struct BigObj *p);
extern u32 func_0201444C(struct Sub02014444Obj *o);
struct Sub0200852CObj;
extern u8 func_0215841C(void *p);
extern u8 func_02012B58(const struct BigObj *p);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int func_021584F4(int a0, int a1);

int func_0215850C(int a0, int a1)
{
    int t4;
    int t5;
    void *p;
    struct Rec44 *rec;

t5 = a1 + 0;
    a0 = func_02158344(a0);
loc_02158514:
a0 = t5 + 0;
    p = func_02012B38((const struct BigObj *)a0);
loc_0215851A:
    a0 = func_0201444C(p);
loc_0215851E:
    if (a0 == 1) goto loc_02158526;
loc_02158522:
a0 = 0;
    return a0;
loc_02158526:
a0 = t5 + 0;
    a0 = func_0215841C((void *)a0);
loc_0215852C:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B58((const struct BigObj *)a0);
loc_02158534:
    if (t4 != a0) goto loc_0215853C;
loc_02158538:
a0 = 0;
    return a0;
loc_0215853C:
a0 = t5 + 0;
a1 = t4 + 0;
    rec = func_02012950((struct Sub24 *)a0, a1);
loc_02158544:
    a0 = func_0200855C((const struct Sub0200852CObj *)rec);
loc_0215854A:
t4 = a0 + 0;
    a0 = func_02008530((const struct Sub0200852CObj *)rec);
loc_02158552:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_021584F4(a0, a1);
loc_0215855A:
    if (a0 == 0x14) goto loc_02158564;
loc_0215855E:
    if (a0 == 0x15) goto loc_02158568;
loc_02158562:
    goto loc_0215856C;
loc_02158564:
a0 = 1;
    return a0;
loc_02158568:
a0 = 2;
    return a0;
loc_0215856C:
a0 = 3;
    return a0;}
