/*
 * function: func_021BEE8C
 * address: 0x021BEE8C
 * packet: pkt_ov203_021BEE8C
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021BEEF8 0x021BEEF8 thumb ov203
 */
#include "../include/Obj03917.h"
typedef struct Task {char *owner;unsigned reserved;unsigned char done,a,b,mode;int channel,start,end;} Task;
struct Tcbl;struct TcblNode;struct S02030FB4;
extern struct TcblNode *TCBL_AddTask(struct Tcbl *,void (*)(struct TcblNode *,void *),unsigned,unsigned);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern void GFL_USE_FadeOutBgm(u32 a);
extern void func_021BEEF8(struct TcblNode *node, struct Task *t);
void func_021BEE8C(char *p,int channel,int start,int end,unsigned mode)
{
    Task *t;
    int flag=0;
    t=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(struct TcblNode *,void *))func_021BEEF8,24,0));
    MI_CpuFill8(t,0,24);
    t->owner=p;t->mode=mode;
    if(mode==3)flag=1;
    t->a=flag;
    if(mode==4)t->b=1;else t->b=0;
    t->channel=channel;t->start=start;t->end=end;
    if(start!=0)GFL_USE_FadeOutBgm((unsigned short)start);else t->done=1;
}
