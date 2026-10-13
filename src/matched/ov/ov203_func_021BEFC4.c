/*
 * function: func_021BEFC4
 * address: 0x021BEFC4
 * packet: pkt_ov203_021BEFC4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BF0B4 0x021BF0B4 thumb
 *   FX_Div 0x0207C768 arm
 *   BRIGHTNESS_Set 0x02023F60 thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned int u32;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
struct Owner { char pad[0x20]; struct Tcbl *manager; };
struct Work { struct Owner *owner; int state,mask,kind,duration,start,end,current,step; int *counter; };
extern struct TcblNode *TCBL_AddTask(struct Tcbl *,void (*)(struct TcblNode *,void *),u32,u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *,u32,u32);
extern void func_021BF0B4(struct TcblNode *node, int *s);
extern u32 FX_Div(u32,u32);
extern void BRIGHTNESS_Set(u32,u32,u32);
void func_021BEFC4(struct Owner *owner,int mask,int kind,int start,int end,int duration,int *counter)
{
    struct Work *work;
    float a,b,c;
    int final;
    work=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(owner->manager,(void (*)(struct TcblNode *, void *))func_021BF0B4,0x28,0));
    MI_CpuFill8(work,0,0x28);
    work->owner=owner;
    work->mask=mask;
    work->kind=kind;
    work->start=start;
    work->end=end;
    work->duration=duration;
    work->counter=counter;
    if(start>0) a=0.5f+(float)(start<<12);
    else a=(float)(start<<12)-0.5f;
    work->current=(int)a;
    if(duration>0) b=0.5f+(float)(duration<<12);
    else b=(float)(duration<<12)-0.5f;
    if(end>0) c=0.5f+(float)(end<<12);
    else c=(float)(end<<12)-0.5f;
    final=(int)c;
    work->step=FX_Div(final-work->current,(int)b);
    if(counter != 0) (*counter)++;
    BRIGHTNESS_Set((short)work->start,work->kind,work->mask);
}
