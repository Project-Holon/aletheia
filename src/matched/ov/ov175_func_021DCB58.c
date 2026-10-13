/*
 * function: func_021DCB58
 * address: 0x021DCB58
 * packet: pkt_ov175_021DCB58
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   func_021B9800 0x021B9800 thumb ov114
 *   func_021B98A0 0x021B98A0 thumb ov114
 *   func_021B98D8 0x021B98D8 thumb ov114
 */
#include "../include/Obj01956.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *GAME_DATA_GetMyStatus(void *);
struct Sub0200852CObj;
extern unsigned int func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned POKE_TOOL_GetPartyParamSize(void);
extern unsigned POKEPARTY_GetCount(void *p);
typedef unsigned int   u32;
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u8 *func_021B9800(int,int,int);
extern void func_021B98A0(u8 *,int,int,int);
extern void func_021B98D8(u8 *,int,int);
void func_021DCB58(char *p,void *q,int mode)
{
    int i;
    unsigned size;
    void *mon;
    i=0;
    ((struct Obj01956 *)p)->f12C=0;
    *(u8 * *)&((struct Obj01956 *)p)->f121C=func_021B9800(((struct Obj01956 *)p)->f124,(int)func_0200853C((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct Obj01956 *)p)->f8)),((struct Obj01956 *)p)->f10);
    switch(mode) {
    case 0:
        func_021B98A0(*(u8 * *)&((struct Obj01956 *)p)->f121C,((struct Obj01956 *)p)->f124,POKE_TOOL_GetPartyParamSize(),0);
        func_021B98D8(*(u8 * *)&((struct Obj01956 *)p)->f121C,(int)q,POKE_TOOL_GetPartyParamSize());
        ((struct Obj01956 *)p)->f174=1;
        break;
    case 1:
        size=POKE_TOOL_GetPartyParamSize();
        func_021B98A0(*(u8 * *)&((struct Obj01956 *)p)->f121C,((struct Obj01956 *)p)->f124,size*POKEPARTY_GetCount(q),0);
        for(i=0;i<(int)POKEPARTY_GetCount(q);i++) {
            mon=POKEPARTY_GetMember(q,i);
            func_021B98D8(*(u8 * *)&((struct Obj01956 *)p)->f121C,(int)mon,POKE_TOOL_GetPartyParamSize());
        }
        ((struct Obj01956 *)p)->f174=POKEPARTY_GetCount(q);
        break;
    }
}
