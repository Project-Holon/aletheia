/*
 * function: func_0215B028
 * address:  0x0215B028
 * packet:   pkt_0215B028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02008428  0x02008428  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Big;
struct Sub02008700Obj;
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02008428(unsigned short *p);

int func_0215B028(int a0, int a1)
{
    int t5;
    int t6;
    void *p;
    void *q;
    struct Sub02008700Obj *t4;
    u16 *dst;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215B034:
    p = func_020120F4((const struct Ctx *)v0);
loc_0215B038:
    q = func_02012EBC(p);
loc_0215B03C:
    t4 = func_0200873C(q);
loc_0215B040:
a0 = t5 + 0;
a1 = t6 + 0;
    dst = func_02159AE8((void *)a0, (void *)a1);
loc_0215B04A:
    a0 = func_02008428((short unsigned int *)t4);
loc_0215B052:
    if (a0 == 0) goto loc_0215B05C;
loc_0215B056:
    if (a0 == 1) goto loc_0215B060;
loc_0215B05A:
    goto loc_0215B064;
loc_0215B05C:
a0 = 0;
    goto loc_0215B062;
loc_0215B060:
a0 = 1;
loc_0215B062:
*dst = a0;
loc_0215B064:
a0 = 0;
    return a0;}
