/*
 * file:     unit_021B7560_p02.c
 * unit:     yes
 * function: func_021B80E8,func_021B8340, func_021B8348, func_021B83E0, func_021B8434, func_021B8438, func_021B8440, func_021B84B4, func_021B8598, func_021B85A4, func_021B8734, func_021B87E8, func_021B8840
 * address:  0x021B80E8
 * region:   ov105
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7EEC 0x021B7EEC thumb ov105
 *   func_021B658C 0x021B658C thumb ov101
 *   func_021B8860 0x021B8860 thumb ov105
 *   func_021B8008 0x021B8008 thumb ov105
 *   func_021B7DE4 0x021B7DE4 thumb ov105
 *   func_021B728C 0x021B728C thumb ov101
 *   func_021B80BC 0x021B80BC thumb ov105
 *   func_021B80CC 0x021B80CC thumb ov105
 *   func_021B7250 0x021B7250 thumb ov101
 *   func_02035C60 0x02035C60 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B78C8 0x021B78C8 thumb ov105
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021B8974 0x021B8974 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02049F34 0x02049F34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_020061E4 0x020061E4 thumb
 *   d_021B8984 0x021B8984 data a1
 */
#include "../../matched/include/Obj01709.h"
#include "../../matched/include/Obj07990.h"
#include "../../matched/include/Obj22250.h"

#define CTX (*(u8 **)(p+0x1a4))
#define W(off) (*(unsigned *)(p+(off)))
#define H(off) (*(u16 *)(p+(off)))
struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16_021B80E8;

typedef unsigned int u32;

typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; u8 low:4,high:4; u8 tail[32]; } Data;

typedef struct {u32 objects[3]; u8 pad[0x24];u8 digits[3];u8 pad1;int state[3];} Display_021B80E8;

typedef short s16_021B8348;

typedef struct {u32 objects[3]; u16 current[3]; u16 bound[3]; int step[3]; u8 pad[12]; u8 digits[3];u8 pad1;int state[3];} Display_021B8348;

typedef struct {s16_021B8348 x,y;} Pair;

typedef struct { u32 objects[3]; u8 pad[0x24]; u8 digits[3]; u8 pad1; int state[3]; } Display_021B83E0;

typedef signed char s8;

typedef int s32;

typedef signed int     s32_021B84B4;

typedef int s32_021B8598;

typedef struct { u8 index[2]; u8 count; } Row;

typedef signed int     s32_021B8734;

extern void func_021B7EEC(u8 *,void *,u8,u16,u16);
extern void func_021B658C(void *,Data *);
extern int func_021B8860(u8 *);
extern void func_021B8008(u8 *,void *,u8 *,u8,int);
extern void func_021B7DE4(u8 *,void *,int,int,s16_021B80E8);
extern void func_021B728C(int,int);
extern void func_021B80BC(unsigned char *p, unsigned int v);
extern void func_021B80CC(u8 *);
extern int func_021B7250(int *);
extern int func_02035C60(void);
extern void func_020061E4(u32);
extern void func_02005D90(int,int);
extern int func_02005F38(void);
extern void func_02082BCC(void *,int,int);
extern u32 func_021B78C8(u8 *p, int i);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049658(void *,int,int,int,int,int,int);
extern void func_020498F4(void *,int,int,int,int,int,int);
extern void func_02049238(void *);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern s32_021B84B4 func_02061CA4(void *p, u32 a, u32 b, s32_021B84B4 size);
void func_021B80E8(u8 *p,u16 *state);
void func_021B8340(u8 *p,u16 *state);
void func_021B8348(Display_021B8348 *p,void *a,int n);
void func_021B83E0(Display_021B83E0 *p, int i);
int func_021B8434(void *a0);
int func_021B8438(u8 *p,int i);
void func_021B8440(Display_021B8348 *p, unsigned n);
void func_021B84B4(u8 *p,int id,int choice,int heap);
void func_021B8598(void *p);
void func_021B85A4(u8 *p);
void func_021B871C(u8 *p);
unsigned func_021B8730(u8 *p);
void func_021B8734(u16 *p,int n,u8 div,u8 offset,u8 index,u16 a,u16 b);
int func_021B87E8(unsigned a, int *p);
unsigned int func_021B8840(unsigned int x,int y);
extern const unsigned d_021B8974[];
extern const Row d_021B8984[];

/*
 * lever: unsigned word ratio retains repeated u8 narrowing; duplicate 0 and 1/2/3 sound calls retain the branch-to-branch switch arm.
 * function_starts: 0x021B8340 callback stub included in this unit.
 */
void func_021B80E8(u8 *p,u16 *state) {
 Data data; int value; u32 ratio; u8 score;
 switch(*state) {
 case 0:
  if((((struct Obj01709 *)p)->f198)++>30) {((struct Obj01709 *)p)->f198=0;*state=1;} break;
 case 1:func_021B871C(p+0x128);*state=2;break;
 case 2:
  if(func_021B8730(p+0x128)) {
   func_020061E4(0x653);
   func_021B83E0((Display_021B83E0 *)(p+0xe8),0);func_021B83E0((Display_021B83E0 *)(p+0xe8),1);func_021B83E0((Display_021B83E0 *)(p+0xe8),2);*state=3;
  } break;
 case 3:
  if(func_021B8438((u8 *)(p+0xe8),0) && func_021B8438((u8 *)(p+0xe8),1) && func_021B8438((u8 *)(p+0xe8),2)) *state=4;
  break;
 case 4:
  score=CTX[12];ratio=(u8)(score/10+2);
  if(ratio>12)ratio=12;else if(ratio<2)ratio=2;
  func_021B7EEC(p+0xc0,p+0xb0,ratio,score,2);*state=5;break;
 case 5:
  if((((struct Obj01709 *)p)->f198)++>50) {
   ((struct Obj01709 *)p)->f198=0;
   switch(func_021B87E8(CTX[12],0)) {
   case 5:func_02005D90(0x527,65535);break;
   case 4:func_02005D90(0x528,65535);break;
   case 1:case 2:case 3:func_02005D90(0x529,65535);break;
   case 0:func_02005D90(0x529,65535);break;
   default:break;
   }
   *state=6;
  } break;
 case 6:
  if(!func_02005F38() && (((struct Obj01709 *)p)->f198)++>30) {((struct Obj01709 *)p)->f198=0;*state=7;}
  break;
 case 7:
  if(func_02035C60()) {
   if(*(void **)CTX)func_021B658C(*(void **)CTX,&data);
   value=func_021B8860(p);
   if(value==0) {
    if(((struct Obj01709 *)p)->f19C==0)func_021B8008(p+0xc0,p+0xb0,(u8 *)&data,((struct Obj01709 *)p)->f1A0,13);
    else func_021B8008(p+0xc0,p+0xb0,(u8 *)&data,((struct Obj01709 *)p)->f1A0,14);
    *state=8;
   } else if(value==2) {func_021B7DE4(p+0xc0,p+0xb0,15,0,0);*state=8;}
   else *state=9;
  } break;
 case 8:
  if((((struct Obj01709 *)p)->f198)++>30) {func_021B728C(*(int *)&((struct Obj01709 *)p)->f188,1);((struct Obj01709 *)p)->f198=0;*state=9;}break;
 case 9:func_021B728C(*(int *)&((struct Obj01709 *)p)->f188,1);*state=10;break;
 case 10:if(func_02035C60())func_021B80BC(p,(unsigned int)func_021B8340);break;
 }
 if(func_021B7250(*(int * *)&((struct Obj01709 *)p)->f188)==1)func_021B80CC(p);
 func_021B8434(p+0xe8);
}

void func_021B8340(u8 *p,u16 *state) {func_021B80CC(p);}




void func_021B8348(Display_021B8348 *p,void *a,int n)
{
 int i; Pair pos;
 func_02082BCC(p,0,64);
 for(i=0;i<3;i++) {
  p->objects[i]=func_021B78C8(a,i);
  if(n<100) pos.x=74+i*36;
  else if(n>=0 && n<10) pos.x=56+i*36;
  else pos.x=92+i*36;
  pos.y=84;
  func_0204B404((struct Obj *)p->objects[i],(const struct Vec2 *)(&pos),0);
  func_0204B3DC((struct Obj *)p->objects[i],0);
  p->current[i]=0;p->bound[i]=60;
  p->step[i]=4079/p->bound[i];
 }
 func_021B8440((Display_021B8348 *)p, n);
}




void func_021B83E0(Display_021B83E0 *p, int i)
{
    if (p->state[i] == 0) {
        if (i == 0 && p->digits[2 - i] == 0) {
            p->state[i] = 1;
            return;
        }
        if (i == 0 && p->digits[2 - i] == 0 && i == 1 && p->digits[2 - i] == 0) {
            p->state[i] = 1;
            return;
        }
        p->state[i] = 1;
        func_0204B3DC((struct Obj *)p->objects[i], 1);
    }
}





int func_021B8434(void *a0) { return 0; }




/*
 * extent: unowned follower at 021B8440 is outside this getter.
 */
int func_021B8438(u8 *p,int i) {return *(int *)(p+0x34+i*4);}




void func_021B8440(Display_021B8348 *p, unsigned n)
{
    u8 t;
    int i, j;
    t = n;
    if (t) { for (;;) { if (!t) break; t = t / 10; } }
    for (i = 0; i < 3; i++) func_0204B878((struct Obj *)p->objects[i],0);
    for (j = 0; j < 3; j++) {
        p->digits[j] = n % d_021B8974[j+1] / d_021B8974[j];
        func_0204B878((struct Obj *)p->objects[2-j],p->digits[j]+1);
    }
}



void func_021B84B4(u8 *p,int id,int choice,int heap)
{
    void *archive, *data, *raw;
    u8 *pal;
    int i;
    func_02082BCC(p,0,0x60);
    ((struct Obj07990 *)p)->f0=id;
    ((struct Obj07990 *)p)->f54=func_021B87E8(choice,(int *)(p+0x5c));
    if (((struct Obj07990 *)p)->f5C) ++((struct Obj07990 *)p)->f54;
    archive=func_020490F4(0x5e,heap);
    func_02049658(archive,15,3,0,0,0,heap);
    func_020498F4(archive,17,3,0,0,0,heap);
    func_02049238(archive);
    data=func_02049F34(0x5e,16,(u32)(&raw),heap);
    pal=*(u8 * *)&((struct Obj22250 *)raw)->fC;
    func_02082D44(pal,p+8,32);
    func_02082D44(pal+0x100,p+8,32);
    func_020307B0(data);
    func_02082D44(p+8,p+0x28,32);
    for(i=0;i<13;++i) *(u16 *)(p+0x28+i*2)=0x7fff;
    for(i=0;i<16;++i) func_02061CA4((void *)15,0x100+i*2,(u32)(p+0x28+i*2),2);
}



void func_021B8598(void *p) { func_02082BCC(p, 0, 0x60); }



/*
 * extent: 376-byte lead,20-byte reset871C,4-byte getter8730; no tail data.
 * lever: 3-byte table rows unify index array and count field relocations.
 */
void func_021B85A4(u8 *p)
{
    int i;
    if (!W(0x50)) return;
    switch(W(0x58)) {
    case 0:
        if(H(0x56)>H(0x54)) {
            if(W(0x5c)) W(0x58)=1;
            else { W(0x4c)=1; W(0x50)=0; }
            return;
        }
        if(!W(0x48)) func_020061E4(2000+H(0x56));
        for(i=0;i<d_021B8984[H(0x56)].count;++i) {
            int index=d_021B8984[H(0x56)].index[i];
            func_021B8734((u16 *)(p+0x28)+index,(u16)W(0x48),40,8,index,0x7fff,((u16 *)(p+8))[index]);
        }
        if(W(0x48)++>=40) { W(0x48)=0; ++H(0x56); }
        break;
    case 1:
        if(W(0x48)++>=60) { W(0x48)=0; W(0x58)=2; }
        break;
    case 2:
        if(!W(0x48)) func_020061E4(1998+H(0x56));
        for(i=0;i<d_021B8984[H(0x56)-1].count;++i) {
            int index=d_021B8984[H(0x56)-1].index[i];
            func_021B8734((u16 *)(p+0x28)+index,(u16)W(0x48),40,8,index,((u16 *)(p+8))[index],0x7fff);
        }
        if(W(0x48)++>=40) { W(0x48)=0; W(0x4c)=1; W(0x50)=0; }
        break;
    }
}



void func_021B871C(u8 *p)
{
    W(0x50)=1; W(0x4c)=0; H(0x56)=1; W(0x58)=0; W(0x48)=0;
}



unsigned func_021B8730(u8 *p)
{
    return W(0x4c);
}



/*
 * extent: two-byte zero padding before func_021B87E8
 * lever: u8 div and offset pin their home stores to the prologue
 */
void func_021B8734(u16 *p,int n,u8 div,u8 offset,u8 index,u16 a,u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n/div;
 dr=((u8)(b&31)-r)*n/div;
 dg=((u8)((b&0x3E0)>>5)-g)*n/div;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
 func_02061CA4((void *)15,offset*32+index*2,(u32)p,2);
}



int func_021B87E8(unsigned a, int *p)
{
    int limit, result;
    if (a == 100) { limit = 65535; result = 5; }
    else if (a >= 80) { limit = 100; result = 4; }
    else if (a >= 60) { limit = 80; result = 3; }
    else if (a >= 30) { limit = 60; result = 2; }
    else if (a > 0) { limit = 30; result = 1; }
    else if (a == 0) { limit = 0; result = 0; }
    else { limit = 100; result = 1; }
    if (p) *p = (int)(a + 3) > limit ? 1 : 0;
    return result;
}



unsigned int func_021B8840(unsigned int x,int y) { unsigned int v; if(y) v=2; else v=1; if(x==100) return v*3; if(x>79) v*=2; return v; }
