/*
 * function: func_021FA500
 * address: 0x021FA500
 * packet: pkt_ov186_021FA500
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned mode <= 1 range guard retains the original compare chain; switch(0,1,2) differs.
 * symbols:
 *   func_021FAEE4 0x021FAEE4 thumb ov186
 *   func_021FA020 0x021FA020 thumb ov186
 *   func_021FAF24 0x021FAF24 thumb ov186
 *   func_021FA1DC 0x021FA1DC thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FA0FC 0x021FA0FC thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021FA210 0x021FA210 thumb ov186
 *   func_021FA0A8 0x021FA0A8 thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FACE0 0x021FACE0 thumb ov186
 *   func_021FA7FC 0x021FA7FC thumb ov186
 *   func_021FA6A8 0x021FA6A8 thumb ov186
 *   d_02200D18 0x02200D18 data a1
 */
#include "../include/Obj00684.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {unsigned words[17];} Record;
extern void func_021FAEE4(char *p, int *out);
extern void func_021FA020(u8 *,int,int);
extern int func_021FAF24(char *,int);
extern void func_021FA1DC(char *p, int x, int y);
extern void func_021FA210(char *p);
extern void func_02082BCC(void *,int,unsigned);
extern void func_021FA0FC(u8 *,int,const int *);
extern int func_021FA0A8(u8 *,Record *);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern char d_02200D18[];
extern int func_021FB7B0(void *p, int i);
extern int func_021FAFA0(void *,int);
extern void func_021FACE0(char *p);
extern int *func_021FD73C(int *p, int v);
extern void func_021FA7FC(void *,int *,u8 *),func_021FA6A8(void *,int *,u8 *);
void func_021FA500(void *p,int *state,u8 *ctx)
{
 int section,index,value,i,y;
 int pos[2],other[2];
 Record record;
 if(((struct Obj00684 *)ctx)->f1C<=1){
  section=((struct Obj00684 *)ctx)->f24;
  func_021FAEE4(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,pos);
  func_021FA020(ctx,(int)(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44),1);
  index=((struct Obj00684 *)ctx)->f2C;
  value=func_021FAF24(*(char * *)&((struct Obj00684 *)ctx)->f40+index*0x44,4);
  func_021FA1DC(((struct Obj00684 *)ctx)->f5C,(u16)value,(u16)index);
  func_02082BCC(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,0,0x44);
  pos[1]=-32;
  func_021FA0FC(ctx,section,pos);
  func_021FD73C(p,(int)func_021FA7FC);
 }else if(((struct Obj00684 *)ctx)->f1C==2){
  func_021FA210(((struct Obj00684 *)ctx)->f5C);
  if(func_021FA0A8(ctx,&record)){
   section=func_021FAF24((char *)&record,4);
   if(!record.words[0])func_02034714(d_02200D18,0,d_02200D18);
   other[0]=func_021FB7B0((void *)record.words[3],0);
   other[1]=func_021FB7B0((void *)record.words[3],1);
   func_021FA0FC(ctx,section,other);
   y=func_021FB7B0((void *)record.words[3],1);
   for(i=0;i<ctx[0x39];i++){
    if(y==func_021FB7B0((void *)(*(int *)(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44+0xc)),1))
     func_021FAFA0(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44,1);
   }
   func_021FACE0((char *)(&record));
   func_021FD73C(p,(int)func_021FA6A8);
  }
 }else{
  func_021FA020(ctx,(int)(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44),1);
  index=((struct Obj00684 *)ctx)->f2C;
  value=func_021FAF24(*(char * *)&((struct Obj00684 *)ctx)->f40+index*0x44,4);
  func_021FA1DC(((struct Obj00684 *)ctx)->f5C,(u16)value,(u16)index);
  func_02082BCC(*(char * *)&((struct Obj00684 *)ctx)->f40+((struct Obj00684 *)ctx)->f2C*0x44,0,0x44);
  for(i=0;i<ctx[0x39];i++)func_021FACE0(*(char * *)&((struct Obj00684 *)ctx)->f40+i*0x44);
  func_021FD73C(p,(int)func_021FA7FC);
 }
}
