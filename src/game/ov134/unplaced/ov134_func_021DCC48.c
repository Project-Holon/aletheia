/*
 * function: func_021DCC48
 * address: 0x021DCC48
 * packet: pkt_ov134_021DCC48
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: body ends at 021DCC9C; callback table and zero data follow.
 */
#include "../../../matched/include/Obj01742.h"
#include "../../../matched/include/Obj02198.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Blk37;
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern void *func_0200CA1C(void *);
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
void func_021DCC48(u8 *p, void *unused, u8 *out)
{
    void *a;
    void *b;
    a = func_02012EBC(((struct Obj02198 *)p)->f14);
    func_02012944(((struct Obj02198 *)p)->f14);
    b = func_0200CA1C(((struct Obj02198 *)p)->f14);
    ((struct Obj01742 *)out)->f0 = *(u32 *)&((struct Obj02198 *)p)->f4;
    ((struct Obj01742 *)out)->f8 = *(u32 *)&((struct Obj02198 *)p)->f14;
    ((struct Obj01742 *)out)->f4 = (u32)func_0200873C(a);
    out[12] = 1;
    out[13] = 1;
    out[14] = func_0201AA18(((struct Obj02198 *)p)->f4);
    out[15] = 0;
    out[16] = 0;
    out[17] = 0;
    out[18] = 0;
    ((struct Obj01742 *)out)->f14 = 0;
    ((struct Obj01742 *)out)->f18 = func_0200CA38(b);
    ((struct Obj01742 *)out)->f20 = 0;
    ((struct Obj01742 *)out)->f24 = 0;
}
