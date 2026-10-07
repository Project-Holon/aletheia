/*
 * file:     demo3d_cmdsys_p01.c
 * unit:     yes
 * function: func_021BEE1C, func_021BEE40, func_021BEE8C, func_021BEEF8, func_021BEF84, func_021BEFC4, func_021BF0B4, func_021BF128
 * address:  0x021BEE1C
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
 *   func_021BF7AC 0x021BF7AC thumb ov203
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02005E50 0x02005E50 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_02031194 0x02031194 arm
 *   func_02023F60 0x02023F60 thumb
 *   sub_020311B8 0x020311B8 arm
 *   sub_02031290 0x02031290 arm
 *   sub_0207C768 0x0207C768 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021BF168 0x021BF168 thumb ov203
 */
#include "../../matched/include/Obj03917.h"

struct Owner;
struct TcblNode;
struct Tcbl;
struct S02030FB4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Config {unsigned words[11];} Config;

typedef struct Task {char *owner;unsigned reserved;unsigned char done,a,b,mode;int channel,start,end;} Task;

struct Owner { char pad[0x20]; struct Tcbl *manager; };

struct Work { struct Owner *owner; int state,mask,kind,duration,start,end,current,step; int *counter; };

extern int func_021BF7AC(char *,int);
extern void func_02005DF8(u32 a);
extern void func_02005E30(u32 a);
extern void func_02005D90(int,int);
extern struct TcblNode *func_020311B8(struct Tcbl *,void (*)(struct TcblNode *,void *),unsigned,unsigned);
extern void *func_02031290(struct S02030FB4 *);
extern void func_02082BCC(void *,int,int);
extern int func_02005E50(void);
extern void func_02005DE4(void *);
extern int func_02005E64(void),func_02005E9C(void);
extern void func_02005D28(void);
extern void func_02031194(struct TcblNode *);
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern struct TcblNode *sub_020311B8(struct Tcbl *,void (*)(struct TcblNode *,void *),u32,u32);
extern void *sub_02031290(struct S02030FB4 *);
extern u32 sub_0207C768(u32,u32);
extern void func_021BF168(char *,unsigned char,signed char,signed char,signed char,int,int);
void func_021BEE1C(char *p,int unused,int *s);
void func_021BEE40(char *p,int unused,int *s);
void func_021BEE8C(char *p,int channel,int start,int end,unsigned mode);
void func_021BEEF8(struct TcblNode *node,Task *t);
void func_021BEF84(char *p,int unused,int *s);
void func_021BEFC4(struct Owner *owner,int mask,int kind,int start,int end,int duration,int *counter);
void func_021BF0B4(struct TcblNode *node,int *s);
void func_021BF128(char *p,int unused,int *s);

void func_021BEE1C(char *p,int unused,int *s) { int x;x=func_021BF7AC(p,s[1]);if(s[0]==0)func_02005DF8((u16)x);else func_02005E30((u16)x); }

void func_021BEE40(char *p,int unused,int *s)
{
    int channel,a,b;
    channel=s[0];a=func_021BF7AC(p,s[1]);b=func_021BF7AC(p,s[2]);
    if(s[3]==0){func_02005D90(channel,0xffff);func_02005DF8((unsigned short)b);}
    else {func_021BEE8C(p,channel,a,b,s[3]);}
}

void func_021BEE8C(char *p,int channel,int start,int end,unsigned mode)
{
    Task *t;
    int flag=0;
    t=func_02031290((struct S02030FB4 *)func_020311B8(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(struct TcblNode *,void *))func_021BEEF8,24,0));
    func_02082BCC(t,0,24);
    t->owner=p;t->mode=mode;
    if(mode==3)flag=1;
    t->a=flag;
    if(mode==4)t->b=1;else t->b=0;
    t->channel=channel;t->start=start;t->end=end;
    if(start!=0)func_02005E30((unsigned short)start);else t->done=1;
}

void func_021BEEF8(struct TcblNode *node,Task *t)
{
    switch(t->done){
    case 0:
        if(func_02005E50()!=0)return;
        ++t->done;
    case 1:
        if(t->a){
            if((unsigned char)t->owner[25]==0){func_02005DE4((void *)1);func_02005E64();t->owner[25]=1;}
        }else {func_02005D28();if(t->mode==1)break;}
        if(t->b){
            if((unsigned char)t->owner[25]!=0){func_02005E9C();func_02005DE4(0);t->owner[25]=0;}
        }else {func_02005D90(t->channel,0xffff);}
        if(t->end!=0)func_02005DF8((unsigned short)t->end);
        break;
    }
    func_02031194(node);
}

/*
 * trailing: two-byte zero alignment padding at 021BEFC2.
 */
void func_021BEF84(char *p,int unused,int *s)
{
    if(s[1]==0){func_02023F60((short)s[2],0x3f,s[0]);}
    else {func_021BEFC4((struct Owner *)p,s[0],0x3f,s[2],s[3],func_021BF7AC(p,s[1]),0);}
}

void func_021BEFC4(struct Owner *owner,int mask,int kind,int start,int end,int duration,int *counter)
{
    struct Work *work;
    float a,b,c;
    int final;
    work=sub_02031290((struct S02030FB4 *)sub_020311B8(owner->manager,(void (*)(struct TcblNode *, void *))func_021BF0B4,0x28,0));
    func_02082BCC(work,0,0x28);
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
    work->step=sub_0207C768(final-work->current,(int)b);
    if(counter != 0) (*counter)++;
    func_02023F60((short)work->start,work->kind,work->mask);
}

void func_021BF0B4(struct TcblNode *node,int *s)
{
    if(*(int *)((char *)s[0]+12)!=0){
        func_02023F60((short)s[6],s[3],s[2]);
        if(s[9]!=0)--*(int *)s[9];
        func_02031194(node);return;
    }
    if(s[4]-->0){func_02023F60((short)(s[7]>>12),s[3],s[2]);s[7]+=s[8];}
    else {func_02023F60((short)s[6],s[3],s[2]);if(s[9]!=0)--*(int *)s[9];func_02031194(node);}
}

void func_021BF128(char *p,int unused,int *s)
{
    int a,b;
    a=func_021BF7AC(p,s[4]);b=func_021BF7AC(p,s[5]);
    func_021BF168(p,s[0],s[1],s[2],s[3],a,b);
}
