/*
 * function: BR_BTN_UpdatePress
 * address: 0x021FA500
 * packet: pkt_ov186_021FA500
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned mode <= 1 range guard retains the original compare chain; switch(0,1,2) differs.
 * symbols:
 *   BR_BTN_GetPos 0x021FAEE4 thumb ov186
 *   BR_BTN_PushRecord 0x021FA020 thumb ov186
 *   BR_BTN_GetRowField 0x021FAF24 thumb ov186
 *   BR_BTN_PushPosPair 0x021FA1DC thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_BTN_BuildSection 0x021FA0FC thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_BTN_PopPosPair 0x021FA210 thumb ov186
 *   BR_BTN_Init 0x021FA0A8 thumb ov186
 *   func_02034714 0x02034714 arm
 *   BR_BTN_DATA_GetRowField 0x021FB7B0 thumb ov186
 *   BR_BTN_SetDrawPriority 0x021FAFA0 thumb ov186
 *   BR_BTN_DeleteRecord 0x021FACE0 thumb ov186
 *   BR_BTN_UpdateExpand 0x021FA7FC thumb ov186
 *   BR_BTN_UpdateRestore 0x021FA6A8 thumb ov186
 *   d_02200D18 0x02200D18 data a1
 */
#include "../include/Obj00684.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {unsigned words[17];} Record;
extern void BR_BTN_GetPos(char *p, int *out);
extern void BR_BTN_PushRecord(u8 *,int,int);
extern int BR_BTN_GetRowField(char *,int);
extern void BR_BTN_PushPosPair(char *p, int x, int y);
extern void BR_BTN_PopPosPair(char *p);
extern void MI_CpuFill8(void *,int,unsigned);
extern void BR_BTN_BuildSection(u8 *,int,const int *);
extern int BR_BTN_Init(u8 *,Record *);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern char d_02200D18[];
extern int BR_BTN_DATA_GetRowField(void *p, int i);
extern int BR_BTN_SetDrawPriority(void *,int);
extern void BR_BTN_DeleteRecord(char *p);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_BTN_UpdateExpand(void *,int *,u8 *),BR_BTN_UpdateRestore(void *,int *,u8 *);
void BR_BTN_UpdatePress(void *p,int *state,u8 *ctx)
{
 int section,index,value,i,y;
 int pos[2],other[2];
 Record record;
 if(((struct Obj00684 *)ctx)->f1C<=1){
  section=((struct Obj00684 *)ctx)->f24;
  BR_BTN_GetPos(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,pos);
  BR_BTN_PushRecord(ctx,(int)(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44),1);
  index=((struct Obj00684 *)ctx)->f2C;
  value=BR_BTN_GetRowField(*(char * *)&((struct Obj00684 *)ctx)->f40+index*0x44,4);
  BR_BTN_PushPosPair(((struct Obj00684 *)ctx)->f5C,(u16)value,(u16)index);
  MI_CpuFill8(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,0,0x44);
  pos[1]=-32;
  BR_BTN_BuildSection(ctx,section,pos);
  BR_UTIL_SetTaskStep(p,(int)BR_BTN_UpdateExpand);
 }else if(((struct Obj00684 *)ctx)->f1C==2){
  BR_BTN_PopPosPair(((struct Obj00684 *)ctx)->f5C);
  if(BR_BTN_Init(ctx,&record)){
   section=BR_BTN_GetRowField((char *)&record,4);
   if(!record.words[0])func_02034714(d_02200D18,0,d_02200D18);
   other[0]=BR_BTN_DATA_GetRowField((void *)record.words[3],0);
   other[1]=BR_BTN_DATA_GetRowField((void *)record.words[3],1);
   BR_BTN_BuildSection(ctx,section,other);
   y=BR_BTN_DATA_GetRowField((void *)record.words[3],1);
   for(i=0;i<ctx[0x39];i++){
    if(y==BR_BTN_DATA_GetRowField((void *)(*(int *)(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44+0xc)),1))
     BR_BTN_SetDrawPriority(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44,1);
   }
   BR_BTN_DeleteRecord((char *)(&record));
   BR_UTIL_SetTaskStep(p,(int)BR_BTN_UpdateRestore);
  }
 }else{
  BR_BTN_PushRecord(ctx,(int)(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44),1);
  index=((struct Obj00684 *)ctx)->f2C;
  value=BR_BTN_GetRowField(*(char * *)&((struct Obj00684 *)ctx)->f40+index*0x44,4);
  BR_BTN_PushPosPair(((struct Obj00684 *)ctx)->f5C,(u16)value,(u16)index);
  MI_CpuFill8(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,0,0x44);
  for(i=0;i<ctx[0x39];i++)BR_BTN_DeleteRecord(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44);
  BR_UTIL_SetTaskStep(p,(int)BR_BTN_UpdateExpand);
 }
}
