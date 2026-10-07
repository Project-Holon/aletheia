/*
 * file:     unit_021BE9B8_p04.c
 * unit:     yes
 * function: func_021BEBC8, func_021BEC24, func_021BEC3C, func_021BEC60, func_021BEC84, func_021BECA8, func_021BED94, func_021BEDCC
 * address:  0x021BEBC8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200616C 0x0200616C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02006148 0x02006148 thumb
 *   func_020062BC 0x020062BC thumb
 *   func_02006268 0x02006268 thumb
 *   sub_020311B8 0x020311B8 arm
 *   sub_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BF7AC 0x021BF7AC thumb
 *   sub_0207C768 0x0207C768 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_02031194 0x02031194 arm
 *   func_02005D90 0x02005D90 thumb
 *   func_02005D28 0x02005D28 thumb
 */
#include "../../matched/include/Obj02919.h"

struct Owner;
struct TcblNode;
struct Tcbl;
struct S02030FB4;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Config {unsigned words[11];} Config;

struct Owner { u8 pad[0x20]; struct Tcbl *manager; };

struct Work { struct Owner *owner; u8 state,kind,target,pad; int duration,start,end,current,step; };

extern void func_0200616C(void *,int);
extern void func_020061E4(unsigned);
extern int func_02006148(unsigned);
extern void func_020062BC(int,unsigned);
extern void func_02006268(int,unsigned,unsigned,unsigned);
extern void func_020061F8(int);
extern struct TcblNode *sub_020311B8(struct Tcbl *,void (*)(struct TcblNode *,void *),u32,u32);
extern void *sub_02031290(struct S02030FB4 *);
extern void func_02082BCC(void *,u32,u32);
extern int func_021BF7AC(char *p, int v);
extern u32 sub_0207C768(u32,u32);
extern void func_02031194(struct TcblNode *);
extern void func_02005D90(int,int);
extern void func_02005D28(void);
void func_021BEBC8(void *unused,int ignored,int *s);
void func_021BEC24(u32 a, u32 b, int *c);
void func_021BEC3C(int a0, int a1, int *src);
void func_021BEC60(struct Owner *p,int unused,int *v);
void func_021BEC84(struct Owner *p,int unused,int *s);
void func_021BECA8(struct Owner *owner,u8 kind,u16 target,int start,int end,int duration,int flag);
void func_021BED94(struct TcblNode *p,char *q);
void func_021BEDCC(int mode,int channel,int value);
void func_021BEE04(int a,int b,int *s);
void func_021BEE14(void);

void func_021BEBC8(void *unused,int ignored,int *s)
{
    int channel;
    if(s[4]!=-1){func_0200616C((void *)s[0],s[4]);channel=s[4];}
    else {func_020061E4(s[0]);channel=func_02006148(s[0]);}
    if(s[1]!=-1)func_020062BC(channel,s[1]);
    if(s[2]!=-1)func_02006268(channel,-1,-1,s[2]);
    if(s[3]!=-1)func_02006268(channel,-1,s[3],-1);
}


void func_021BEC24(u32 a, u32 b, int *c)
{
    int ch = c[1];
    if (ch == -1) {
        ch = func_02006148(c[0]);
    }
    func_020061F8(ch);
}


void func_021BEC3C(int a0, int a1, int *src)
{
    func_021BECA8((struct Owner *)a0, 0, (unsigned short)src[0], src[1], src[2], src[3], src[4]);
}

void func_021BEC60(struct Owner *p,int unused,int *v) {func_021BECA8(p,1,(u16)v[0],v[1],v[2],v[3],v[4]);}

void func_021BEC84(struct Owner *p,int unused,int *s) { func_021BECA8(p,2,s[0],s[1],s[2],s[3],s[4]); }

/*
 * The u16 target parameter fixes the otherwise swapped home stores at +6/+8.
 */
void func_021BECA8(struct Owner *owner,u8 kind,u16 target,int start,int end,int duration,int flag)
{
    struct Work *work;
    float a,b,c;
    int final;
    work=sub_02031290((struct S02030FB4 *)sub_020311B8(owner->manager,(void (*)(struct TcblNode *, void *))func_021BED94,0x1c,0));
    func_02082BCC(work,0,0x1c);
    work->owner=owner;
    work->kind=kind;
    work->start=start;
    work->end=end;
    work->duration=func_021BF7AC((char *)owner,duration);
    if(flag == -1) work->target=flag;
    else work->target=func_02006148(target);
    if(start>0) a=0.5f+(float)(start<<12);
    else a=(float)(start<<12)-0.5f;
    work->current=(int)a;
    if(duration>0) b=0.5f+(float)(duration<<12);
    else b=(float)(duration<<12)-0.5f;
    if(end>0) c=0.5f+(float)(end<<12);
    else c=(float)(end<<12)-0.5f;
    final=(int)c;
    work->step=sub_0207C768(final-work->current,(int)b);
}

void func_021BED94(struct TcblNode *p,char *q) { int old;old=((struct Obj02919 *)q)->f8;((struct Obj02919 *)q)->f8=old-1;if(old>0){func_021BEDCC(((struct Obj02919 *)q)->f5,((struct Obj02919 *)q)->f6,((struct Obj02919 *)q)->f14>>12);((struct Obj02919 *)q)->f14+=((struct Obj02919 *)q)->f18;}else {func_021BEDCC(((struct Obj02919 *)q)->f5,((struct Obj02919 *)q)->f6,((struct Obj02919 *)q)->f10);func_02031194(p);} }

void func_021BEDCC(int mode,int channel,int value)
{
    switch(mode){case 0:func_020062BC(channel,value);break;case 1:func_02006268(channel,-1,-1,value);break;case 2:func_02006268(channel,-1,value,-1);break;}
}

void func_021BEE04(int a,int b,int *s){func_02005D90(s[0],0xffff);}

void func_021BEE14(void){func_02005D28();}
