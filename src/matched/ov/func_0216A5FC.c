/*
 * function: func_0216A5FC
 * address:  0x0216A5FC
 * packet:   pkt_0216A5FC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_02008E78  0x02008E78  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Big;
struct Sub02008C20Obj;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern int func_02008E78();

int func_0216A5FC(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *p;
    struct Sub02008C20Obj *obj;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A608:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A60E:
    t6 = func_020120F4((const struct Ctx *)v1);
loc_0216A612:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A61C:
    p = func_02012EBC(t6);
loc_0216A624:
    obj = func_02008C58(p);
loc_0216A628:
    a0 = func_02008E78(obj);
loc_0216A62C:
*q = a0;
a0 = 0;
    return a0;}
