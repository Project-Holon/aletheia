/*
 * function: DEMO3D_DATA_CreateSeFade
 * address: 0x021BECA8
 * packet: pkt_ov203_021BECA8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The u16 target parameter fixes the otherwise swapped home stores at +6/+8.
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   DEMO3D_DATA_UpdateSeFade 0x021BED94 thumb
 *   func_021BF7AC 0x021BF7AC thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   FX_Div 0x0207C768 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
struct Owner { u8 pad[0x20]; struct Tcbl *manager; };
struct Work { struct Owner *owner; u8 state,kind,target,pad; int duration,start,end,current,step; };
extern struct TcblNode *TCBL_AddTask(struct Tcbl *,void (*)(struct TcblNode *,void *),u32,u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *,u32,u32);
extern void DEMO3D_DATA_UpdateSeFade(struct TcblNode *p, char *q);
extern int func_021BF7AC(char *p, int v);
extern int GFL_USE_GetSeSlot(u32);
extern u32 FX_Div(u32,u32);
void DEMO3D_DATA_CreateSeFade(struct Owner *owner,u8 kind,u16 target,int start,int end,int duration,int flag)
{
    struct Work *work;
    float a,b,c;
    int final;
    work=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(owner->manager,(void (*)(struct TcblNode *, void *))DEMO3D_DATA_UpdateSeFade,0x1c,0));
    MI_CpuFill8(work,0,0x1c);
    work->owner=owner;
    work->kind=kind;
    work->start=start;
    work->end=end;
    work->duration=func_021BF7AC((char *)owner,duration);
    if(flag == -1) work->target=flag;
    else work->target=GFL_USE_GetSeSlot(target);
    if(start>0) a=0.5f+(float)(start<<12);
    else a=(float)(start<<12)-0.5f;
    work->current=(int)a;
    if(duration>0) b=0.5f+(float)(duration<<12);
    else b=(float)(duration<<12)-0.5f;
    if(end>0) c=0.5f+(float)(end<<12);
    else c=(float)(end<<12)-0.5f;
    final=(int)c;
    work->step=FX_Div(final-work->current,(int)b);
}
