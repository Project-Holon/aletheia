/*
 * file:     br_btn_p04.c
 * unit:     yes
 * function: func_021FA210, func_021FA21C, func_021FA274, func_021FA284, func_021FA444, func_021FA500, func_021FA6A8, func_021FA758, func_021FA7FC, func_021FA920, func_021FAA34
 * address:  0x021FA210
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FAFC0 0x021FAFC0 thumb
 *   func_021FD73C 0x021FD73C thumb
 *   func_02035D20 0x02035D20 arm
 *   func_021FAD04 0x021FAD04 thumb ov186
 *   func_021FAF24 0x021FAF24 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FAFCC 0x021FAFCC thumb ov186
 *   func_021FAFA0 0x021FAFA0 thumb ov186
 *   func_021FAA74 0x021FAA74 thumb ov186
 *   func_021FAB7C 0x021FAB7C thumb ov186
 *   func_021FAEE4 0x021FAEE4 thumb
 *   func_021FAD18 0x021FAD18 thumb
 *   func_021FAD74 0x021FAD74 thumb
 *   func_021FA020 0x021FA020 thumb ov186
 *   func_021FA1DC 0x021FA1DC thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FA0FC 0x021FA0FC thumb ov186
 *   func_021FA0A8 0x021FA0A8 thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_021FB7B0 0x021FB7B0 thumb ov186
 *   func_021FACE0 0x021FACE0 thumb ov186
 *   d_02200D18 0x02200D18 data a1
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   d_02200358 0x02200358 data a4
 */
#include "../../matched/include/Obj14451.h"
#include "../../matched/include/Obj06627.h"
#include "../../matched/include/Obj00313.h"
#include "../../matched/include/Obj03890.h"
#include "../../matched/include/Obj00684.h"
#include "../../matched/include/Obj06628.h"
#include "../../matched/include/Obj06629.h"
#include "../../matched/include/Obj01278.h"
#include "../../matched/include/Obj02234.h"

typedef struct {int x,y;} Pair;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {unsigned words[17];} Record;

extern void func_021FAFC0(char *p, unsigned value);
extern int *func_021FD73C(int *p, int v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021FAD04(int *,int,int),func_021FAF24(char *,int);
extern void func_021FD15C(void *p, int a1);
extern void func_020061E4(u32 a);
extern void func_021FD860(char *,unsigned,const Pair *);
extern void func_021FAFCC(char *p, unsigned value);
extern int func_021FAFA0(void *,int);
extern void func_021FAA74(void *,int *,unsigned *);
extern void func_021FAB7C(void *,int *,unsigned char *);
extern void func_021FAEE4(char *p, int *out);
extern void func_021FAD18(char *ctx, int mode, const int *target);
extern int func_021FAD74(char *ctx);
extern void func_021FA020(u8 *,int,int);
extern void func_021FA1DC(char *p, int x, int y);
extern void func_02082BCC(void *,int,unsigned);
extern void func_021FA0FC(u8 *,int,const int *);
extern int func_021FA0A8(u8 *,Record *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_021FB7B0(void *p, int i);
extern void func_021FACE0(char *p);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
void func_021FA210(char *p);
void func_021FA21C(unsigned char *ctx, int mode);
void func_021FA274(void *p);
void func_021FA284(void *p,int *state,unsigned char *ctx);
void func_021FA444(void *p, int *state, unsigned char *ctx);
void func_021FA500(void *p,int *state,u8 *ctx);
void func_021FA6A8(void *p, int *state, unsigned char *ctx);
void func_021FA758(void *p, int *state, unsigned char *ctx);
void func_021FA7FC(void *p,int *state,unsigned char *ctx);
void func_021FA920(int *task,int *state,u8 *ctx);
void func_021FAA34(void *p, int *state, int *ctx);
extern char d_02200D18[];
extern const int d_02200358[];

void func_021FA210(char *p) { if (((struct Obj14451 *)p)->f18!=0) (((struct Obj14451 *)p)->f18)--; }

void func_021FA21C(unsigned char *ctx, int mode)
{
    int i, selected;
    for (i = 0; i < ctx[0x3b]; i++) {
        switch (mode) {
        case 0: selected = (i == ctx[0x3b] - 1); break;
        case 1: selected = (i >= ctx[0x3b] - 2); break;
        }
        if (selected)
            func_021FAFC0(*(char * *)&((struct Obj06627 *)ctx)->f3C + i * 0x44, 0);
        else
            func_021FAFC0(*(char * *)&((struct Obj06627 *)ctx)->f3C + i * 0x44, 1);
    }
}

void func_021FA274(void *p)
{
    func_021FD73C(p, (int)func_021FA284);
}

void func_021FA284(void *p,int *state,unsigned char *ctx)
{
 int found,i,x,y,kind;
 found=0;((struct Obj00313 *)ctx)->f18=0;((struct Obj00313 *)ctx)->f14=0;
 if(func_02035D20((u32 *)(&x),(u32 *)(&y))){
  for(i=0;i<ctx[0x38];i++){
   if(func_021FAD04((int *)(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44),x,y)){
    if(func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,3)){
     if(((struct Obj00313 *)ctx)->f50){
      func_021FD15C((void *)(((struct Obj00313 *)ctx)->f50),((struct Obj00313 *)ctx)->f4);
      ((struct Obj00313 *)ctx)->f50=0;
     }
     func_020061E4(0x703);
     ((struct Obj00313 *)ctx)->f2C=i;
     found=1;
     ((struct Obj00313 *)ctx)->f30=x;((struct Obj00313 *)ctx)->f34=y;
     func_021FD860(*(char * *)&((struct Obj00313 *)ctx)->f58,7,(Pair *)(ctx+0x30));
     func_021FAFCC(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,(unsigned int)((Pair *)(ctx+0x30)));
     ((struct Obj00313 *)ctx)->f54=0;
    }else{
     kind=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,5);
     func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,6);
     func_020061E4(0x704);
     if(kind==1){((struct Obj00313 *)ctx)->f2C=i;func_021FD73C(p,(int)func_021FAA74);}
    }
    break;
   }
  }
 }
 if(found){
  ((struct Obj00313 *)ctx)->f14=1;
  *(int *)&((struct Obj00313 *)ctx)->f1C=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,0);
  ((struct Obj00313 *)ctx)->f20=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,3);
  ((struct Obj00313 *)ctx)->f24=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,1);
  ((struct Obj00313 *)ctx)->f28=func_021FAF24(*(char * *)&((struct Obj00313 *)ctx)->f40+((struct Obj00313 *)ctx)->f2C*0x44,2);
  for(i=0;i<ctx[0x39];i++){
   if(i==((struct Obj00313 *)ctx)->f2C)func_021FAFA0(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,1);
   else func_021FAFA0(*(char * *)&((struct Obj00313 *)ctx)->f40+i*0x44,3);
  }
  switch(((struct Obj00313 *)ctx)->f1C){
  case 2:func_021FD73C(p,(int)func_021FA758);break;
  case 0:case 1:case 4:func_021FD73C(p,(int)func_021FA444);break;
  case 3:func_021FD73C(p,(int)func_021FAB7C);break;
  default:func_021FD73C(p,(int)func_021FAA34);break;
  }
 }
}

void func_021FA444(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            if (((struct Obj03890 *)ctx)->f2C != i) {
                func_021FAEE4(*(char * *)&((struct Obj03890 *)ctx)->f40 + ((struct Obj03890 *)ctx)->f2C * 0x44, values);
                func_021FAD18(*(char * *)&((struct Obj03890 *)ctx)->f40 + i * 0x44, 0, values);
            }
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char * *)&((struct Obj03890 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2:
        if (((struct Obj03890 *)ctx)->f1C == 4) {
            func_021FD73C(p, (int)func_021FA500);
            return;
        } else {
            func_021FD73C(p, (int)func_021FA500);
        }
        break;
    }
}

/*
 * lever: unsigned mode <= 1 range guard retains the original compare chain; switch(0,1,2) differs.
 */
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

void func_021FA6A8(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++)
            func_021FAD18(*(char * *)&((struct Obj06628 *)ctx)->f40 + i * 0x44, 1, 0);
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char * *)&((struct Obj06628 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2:
        switch (((struct Obj06628 *)ctx)->f1C) {
        case 0: case 1: func_021FD73C(p, (int)func_021FAA34); break;
        case 4: func_021FD73C(p, (int)func_021FA7FC); break;
        default: func_021FD73C(p, (int)func_021FAA34); break;
        }
        break;
    }
}

void func_021FA758(void *p, int *state, unsigned char *ctx)
{
    int i, ready;
    int values[2];
    switch (*state) {
    case 0:
        for (i = 0; i < ctx[0x39]; i++) {
            func_021FAEE4(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44, values);
            values[1] = 0xe0;
            func_021FAD18(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44, 4, values);
        }
        *state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < ctx[0x39]; i++)
            ready &= func_021FAD74(*(char * *)&((struct Obj06629 *)ctx)->f40 + i * 0x44);
        if (ready) *state = 2;
        break;
    case 2: func_021FD73C(p, (int)func_021FA920); break;
    }
}

void func_021FA7FC(void *p,int *state,unsigned char *ctx)
{
 int i,ready,kind;
 unsigned short value;
 char *entry;
 switch(*state){
 case 0:
  for(i=0;i<ctx[0x3b];i++){
   if(i==ctx[0x3b]-1)func_021FAD18(*(char * *)&((struct Obj01278 *)ctx)->f3C+i*0x44,2,d_02200358);
   else func_021FAD18(*(char * *)&((struct Obj01278 *)ctx)->f3C+i*0x44,4,d_02200358+(ctx[0x3b]-i-1)*2);
  }
  *state=1;break;
 case 1:
  ready=1;
  for(i=0;i<ctx[0x3b];i++)ready&=func_021FAD74(*(char * *)&((struct Obj01278 *)ctx)->f3C+i*0x44);
  if(ready){func_021FA21C(ctx,0);*state=2;}break;
 case 2:
  entry=*(char * *)&((struct Obj01278 *)ctx)->f3C+(ctx[0x3b]-1)*0x44;
  kind=func_021FAF24(entry,0);
  value=func_021FAF24(entry,2);
  if(kind==1){
   if(!((struct Obj01278 *)ctx)->f50)((struct Obj01278 *)ctx)->f50=func_021FD12C((int)(((struct Obj01278 *)ctx)->f4),(void *)(((struct Obj01278 *)ctx)->f4C),((struct Obj01278 *)ctx)->f0);
   func_021FD170(((struct Obj01278 *)ctx)->f50,((struct Obj01278 *)ctx)->f4,(void *)value);
  }
  *state=3;break;
 case 3:
  switch(((struct Obj01278 *)ctx)->f1C){
  case 0:case 1:func_021FD73C(p,(int)func_021FA6A8);break;
  default:func_021FD73C(p,(int)func_021FAA34);break;
  }
  break;
 }
}

void func_021FA920(int *task,int *state,u8 *ctx)
{
    int position[2];
    int i;
    int ready;
    switch(*state) {
    case 0:
        for(i=0;i<ctx[0x3B];i++) {
            if(i==ctx[0x3B]-1) {
                position[0]=func_021FB7B0(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),0);
                position[1]=func_021FB7B0(*(void **)(*(u8 * *)&((struct Obj02234 *)ctx)->f3C+i*0x44+0xC),1);
                func_021FAD18(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,3,position);
                func_021FAFA0(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,1);
            } else func_021FAD18(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44,4,(const int *)((unsigned)d_02200358+(ctx[0x3B]-i-2)*8));
        }
        for(i=0;i<ctx[0x39];i++)func_021FAFA0(*(char * *)&((struct Obj02234 *)ctx)->f40+i*0x44,3);
        *state=1;
        break;
    case 1:
        ready=1;
        for(i=0;i<ctx[0x3B];i++)ready&=func_021FAD74(*(char * *)&((struct Obj02234 *)ctx)->f3C+i*0x44);
        if(ready){func_021FA21C(ctx,1);*state=2;}
        break;
    case 2:func_021FD73C(task,(int)func_021FA500);break;
    }
}

void func_021FAA34(void *p, int *state, int *ctx)
{
    if (*state == 0) {
        if (ctx[8]) {
            switch (ctx[7]) {
            case 0: case 1: case 2: break;
            case 3: ctx[6] = 2; break;
            case 4: ctx[6] = 1; break;
            }
        }
        func_021FD73C(p, (int)func_021FA284);
    }
}
