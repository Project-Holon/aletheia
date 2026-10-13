/*
 * function: func_021D8F58
 * address: 0x021D8F58
 * packet: pkt_ov123_021D8F58
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return.
 * symbols:
 *   func_02009290 0x02009290 thumb
 *   func_020092F8 0x020092F8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   POKE_TOOL_ClearPartyParam  0x02017528  thumb  arm9
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 */
#include "../include/Obj02476.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Sav;
struct Sub020075B0Entry;
struct Sub02009210Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u32 func_02009228(void);
extern void func_02082D44(void *, void *, int);
extern u32 func_020307B0(void *p);
extern u8 *func_02009290(struct Sub02009210Obj *obj);
extern void *POKE_TOOL_GetBoxParam(void *);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void POKE_TOOL_ClearPartyParam(struct Sav *p);
extern void func_020092F8(struct Sub02009210Obj *obj, u8 value);
void func_021D8F58(char *p)
{
    void *v;
    void *q;
    v=func_02009448(((struct Obj02476 *)p)->f28);
    if (((struct Obj02476 *)p)->f34) {
        func_02082D44(((struct Obj02476 *)p)->f34,v,func_02009228());
        func_020307B0(((struct Obj02476 *)p)->f34);
        ((struct Obj02476 *)p)->f34=0;
    }
    if (((struct Obj02476 *)p)->fAA) {
        q=func_02009290(v);
        func_020075B0(((struct Obj02476 *)p)->f24,((struct Obj02476 *)p)->f48,((struct Obj02476 *)p)->f4C,POKE_TOOL_GetBoxParam(q));
        POKE_TOOL_ClearPartyParam(q);
        func_020092F8(v,0);
        ((struct Obj02476 *)p)->fAA=0;
    }
}
