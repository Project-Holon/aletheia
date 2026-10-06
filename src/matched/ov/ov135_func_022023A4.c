/*
 * function: func_022023A4
 * address: 0x022023A4
 * packet: pkt_ov135_022023A4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: func_0200CDE0 receives the entry r1 Pokemon pointer; fifth parameter is reassigned in its incoming stack slot.
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017F50 0x02017F50 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_022026BC 0x022026BC thumb ov135
 *   func_0220246C 0x0220246C thumb ov135
 */
#include "../include/Obj02864.h"
#include "../include/Obj23476.h"
#include "../include/Obj23477.h"
#include "../include/Obj23478.h"
#include "../include/Obj23479.h"
#include "../include/Obj23480.h"
#include "../include/Obj23481.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern void func_0200CDE0(struct Blk37 *, void *);
extern u32 func_0201AA18(void *p);
extern void func_02017E40(void *,u32,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern u8 func_02017F50(u32 a, u16 b, u32 c);
struct Party;
struct PartyMon;
extern u32 func_0201A98C(struct Party *,const struct PartyMon *);
extern int func_020076D0(void *save, int *pbox, int *pslot);
struct Sub02007454Entry;
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern u32 func_022026BC(void *);
extern void func_0220246C(void *,int);
void func_022023A4(u8 *p,void *mon,void *unused2,void *unused3,u32 index)
{
    u32 species, form, pos;
    func_0200CDE0(*(struct Blk37 * *)&((struct Obj23476 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f10,mon);
    index=0xFF;
    if(func_0201AA18(((struct Obj23477 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8)==6) index=0;
    func_02017E40(mon,9,0x46);
    species=func_02017E1C(mon,5,0);
    form=func_02017E1C(mon,0x6F,0);
    func_02017E40(mon,0x6E,func_02017F50((u16)species,form,func_02017E1C(mon,0,0)));
    if(index==0xFF) {
        func_0201A98C(*(struct Party * *)&((struct Obj23478 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8,(const struct PartyMon *)mon);
        pos=func_0201AA18(((struct Obj23479 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8);
        ((struct Obj02864 *)p)->fDC=0xFF;
        pos--;
    } else {
        u32 slot=0;
        func_020076D0(((struct Obj23480 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->fC,(int *)(&index),(int *)(&slot));
        func_0200752C(((struct Obj23481 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->fC,index,(const struct Sub02007454Entry *)func_022026BC(mon));
        ((struct Obj02864 *)p)->fDC=index;
        pos=slot;
    }
    ((struct Obj02864 *)p)->fE0=pos;
    func_0220246C(*(void **)*(u8 * *)&((struct Obj02864 *)p)->f0,1);
}
