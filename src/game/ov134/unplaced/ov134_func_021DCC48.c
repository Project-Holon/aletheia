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
 *
 * symbols:
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 */
#include "../../../matched/include/Obj01742.h"
#include "../../../matched/include/Obj02198.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Blk37;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *func_0200CA1C(void *);
struct Sub02008700Obj;
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 POKEPARTY_GetCount(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
void func_021DCC48(u8 *p, void *unused, u8 *out)
{
    void *a;
    void *b;
    a = GAME_DATA_GetSaveControl(((struct Obj02198 *)p)->f14);
    GAME_DATA_GetMyStatus(((struct Obj02198 *)p)->f14);
    b = func_0200CA1C(((struct Obj02198 *)p)->f14);
    ((struct Obj01742 *)out)->f0 = *(u32 *)&((struct Obj02198 *)p)->f4;
    ((struct Obj01742 *)out)->f8 = *(u32 *)&((struct Obj02198 *)p)->f14;
    ((struct Obj01742 *)out)->f4 = (u32)func_0200873C(a);
    out[12] = 1;
    out[13] = 1;
    out[14] = POKEPARTY_GetCount(((struct Obj02198 *)p)->f4);
    out[15] = 0;
    out[16] = 0;
    out[17] = 0;
    out[18] = 0;
    ((struct Obj01742 *)out)->f14 = 0;
    ((struct Obj01742 *)out)->f18 = func_0200CA38(b);
    ((struct Obj01742 *)out)->f20 = 0;
    ((struct Obj01742 *)out)->f24 = 0;
}
