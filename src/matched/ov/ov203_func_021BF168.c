/*
 * function: DEMO3D_DATA_CreateBrightnessSeq
 * address: 0x021BF168
 * packet: pkt_ov203_021BF168
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   DEMO3D_DATA_BrightnessSeqMain 0x021BF1CC thumb ov203
 *   DEMO3D_DATA_CreateBrightnessFade 0x021BEFC4 thumb ov203
 */
#include "../include/Obj03917.h"
typedef struct Task {char *owner;unsigned reserved;unsigned char done;signed char a,b,c;int start,end,count;unsigned index,mask;} Task;
struct Tcbl;struct TcblNode;struct S02030FB4;
extern struct TcblNode *TCBL_AddTask(struct Tcbl *,void (*)(struct TcblNode *,void *),unsigned,unsigned);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *,int,int);
extern void DEMO3D_DATA_BrightnessSeqMain(void *task, char *work);
struct Owner;
extern void DEMO3D_DATA_CreateBrightnessFade(struct Owner *owner, int mask, int kind, int start, int end, int duration, int *counter);
void DEMO3D_DATA_CreateBrightnessSeq(char *p,unsigned char index,signed char a,signed char b,signed char c,int start,int end)
{
    Task *t;
    t=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(struct TcblNode *,void *))DEMO3D_DATA_BrightnessSeqMain,32,1));
    MI_CpuFill8(t,0,32);
    t->owner=p;t->a=a;t->b=b;t->c=c;t->index=index;t->mask=63;t->start=start;t->end=end;
    DEMO3D_DATA_CreateBrightnessFade((struct Owner *)p,t->index,t->mask,a,b,start,&t->count);
}
