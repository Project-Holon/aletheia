/*
 * function: func_021DE754
 * address: 0x021DE754
 * packet: pkt_ov119_021DE754
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Shared failure label; padded two-dimensional array members reproduce index scheduling.
 * symbols:
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D9468 0x021D9468 thumb ov119
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021D8F60 0x021D8F60 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDAD4 0x021DDAD4 thumb ov119
 *   func_021DE70C 0x021DE70C thumb ov119
 */
#include "../include/Obj00251.h"
extern unsigned POKE_TOOL_GetPartyValue(void *,unsigned,unsigned);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D9468(void *,int,void *);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void func_02082D44(void *,const void *,int);
extern void func_021D8F60(void *,int,int);
extern void func_021D8E84(void *,int);
extern void func_021DDAD4(char *p);
extern void func_021DE70C(void *);
typedef struct { char pad[0xfa4]; int entry[2][3]; char gap[0x1c]; void *mon[2][3]; int value[2][3]; } State;
int func_021DE754(char *p,int idx)
{
    int row,col,entry;
    void *mon;
    int value;
    State *s=(State *)p;
    row=idx/3;
    col=idx%3;
    if(idx==-1) goto fail;
    entry=s->entry[1-row][col];
    if(entry==-1) goto fail;
    mon=s->mon[1-row][col];
    value=s->value[1-row][col];
    if(mon==0 || POKE_TOOL_GetPartyValue(mon,169,0)==0) goto fail;
    ((struct Obj00251 *)p)->f10A0=idx;
    GFL_USE_PlaySeDefaultVolume(0x54c);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00251 *)p)->f9C0),1,0);
    if(row!=0) {
        func_021D8E84(p,(int)func_021DDAD4);
    } else {
        func_021D9468(p,row,mon);
        func_02082D44(mon,((struct Obj00251 *)p)->f106C,POKE_TOOL_GetPartyParamSize());
        func_021D8F60(p,0,value);
        func_021D8E84(p,(int)func_021DE70C);
    }
    return 1;
fail:
    return 0;
}
