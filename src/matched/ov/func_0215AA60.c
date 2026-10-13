/*
 * function: func_0215AA60
 * address:  0x0215AA60
 * packet:   pkt_0215AA60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 48 compiled 46
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 *   CONFIG_SetAppliedFlag  0x020083EC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Sub02008700Obj;
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern int CONFIG_GetAppliedFlag(unsigned short *p);
extern int CONFIG_SetAppliedFlag();

int func_0215AA60(int a0, int a1)
{
    void *p;
    struct Sub02008700Obj *t4;
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215AA68:
    p = func_02012EBC((struct Big *)v0);
loc_0215AA6C:
    t4 = func_0200873C(p);
loc_0215AA70:
    a0 = CONFIG_GetAppliedFlag((short unsigned int *)t4);
loc_0215AA76:
a1 = a0 + 0;
    if (a1 != 0) goto loc_0215AA7E;
loc_0215AA7A:
a1 = 1;
    goto loc_0215AA84;
loc_0215AA7E:
    if (a1 != 1) goto loc_0215AA84;
loc_0215AA82:
a1 = 0;
loc_0215AA84:
    a0 = CONFIG_SetAppliedFlag(t4, a1);
loc_0215AA8A:
a0 = 0;
    return a0;}
