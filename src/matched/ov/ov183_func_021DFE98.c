/*
 * function: func_021DFE98
 * address: 0x021DFE98
 * packet: pkt_ov183_021DFE98
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: A const record array indexed at zero, rather than a scalar record, keeps the final halfword load in place (224 B DIFF to EXACT).
 * abi: F878 fifth heap word retained because the caller writes it to sp before bl.
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   d_021E3758 0x021E3758 data a4
 *   d_021E3728 0x021E3728 data a4
 */
#include "../include/Obj02523.h"
#include "../include/Obj04571.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct {u32 words[10];} Config;
typedef struct {int a,b,c;} Triple;
typedef struct {u16 a,b,c;u8 flag,pad;} Params;
typedef struct {u8 a,b,c,d;u16 file,pad;} Record;
typedef struct Slot Slot;
extern const Config d_021E3758;
extern const Record d_021E3728[];
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern Slot *BMP_MENUWORK_Create(u32,u32);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *func_021FC8C8(Config *,u32);
extern void MI_CpuFill8(void *,u32,u32);
extern int func_021FC124(int,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
int func_021DFE98(char *p,char *q)
{
    int first,second,i;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&((struct Obj04571 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj04571 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj04571 *)q)->f8),27,((struct Obj02523 *)p)->f54);
    *(Slot * *)&((struct Obj02523 *)p)->f14=BMP_MENUWORK_Create(19,((struct Obj02523 *)p)->f54);
    for(i=0;i<19;i++)BMP_MENUWORK_AddMsgItem((Slot *)((u32)*(Slot * *)&((struct Obj02523 *)p)->f14+i*8),second,i+205,i,((struct Obj02523 *)p)->f54);
    cfg=d_021E3758;
    cfg.words[0]=*(u32 *)&((struct Obj02523 *)p)->f14;cfg.words[1]=19;
    cfg.words[5]=*(u32 *)&((struct Obj04571 *)q)->f8;cfg.words[6]=((struct Obj04571 *)q)->f4;
    ((struct Obj02523 *)p)->f18=func_021FC8C8(&cfg,((struct Obj02523 *)p)->f54);
    MI_CpuFill8(&params,0,8);
    func_021FC124(*(int *)&((struct Obj04571 *)q)->f8,6,&triple);
    params.a=d_021E3728[0].a;params.b=d_021E3728[0].b;params.c=d_021E3728[0].c;params.flag=1;
    ((struct Obj02523 *)p)->fC=func_021FB378(&params,d_021E3728[0].file,96,1,*(int *)&((struct Obj04571 *)q)->f4,((struct Obj02523 *)p)->f44,first,second,&triple,((struct Obj02523 *)p)->f54);
    return 1;
}
