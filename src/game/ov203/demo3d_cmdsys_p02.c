/*
 * file:     demo3d_cmdsys_p02.c
 * unit:     yes
 * function: func_021BF168, func_021BF1CC, func_021BF248, func_021BF26C
 * address:  0x021BF168
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
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BEFC4 0x021BEFC4 thumb ov203
 *   func_02023F60 0x02023F60 thumb
 *   func_02031194 0x02031194 arm
 *   func_021BDF74 0x021BDF74 thumb ov203
 *   func_021BDF88 0x021BDF88 thumb ov203
 */
#include "../../matched/include/Obj03917.h"
#include "../../matched/include/Obj01291.h"
#include "../../matched/include/Obj25324.h"

struct Tcbl;
struct TcblNode;
struct S02030FB4;
struct Owner;
typedef struct Task {char *owner;unsigned reserved;unsigned char done;signed char a,b,c;int start,end,count;unsigned index,mask;} Task;

typedef unsigned int   u32;

struct Triple{unsigned short x,y,z;};

extern struct TcblNode *func_020311B8(struct Tcbl *,void (*)(struct TcblNode *,void *),unsigned,unsigned);
extern void *func_02031290(struct S02030FB4 *);
extern void func_02082BCC(void *,int,int);
extern void func_021BEFC4(struct Owner *owner, int mask, int kind, int start, int end, int duration, int *counter);
extern void func_02023F60(u32 a0, u32 a1, u32 mask);
extern void func_02031194(struct TcblNode *n);
extern void func_021BDF74(char *p, unsigned i, unsigned short val);
extern void func_021BDF88(char *p, int a, int b);
void func_021BF168(char *p,unsigned char index,signed char a,signed char b,signed char c,int start,int end);
void func_021BF1CC(void *task,char *work);
void func_021BF248(unsigned unused,char **q,unsigned *v);
void func_021BF26C(unsigned unused,char **q,unsigned *v);

void func_021BF168(char *p,unsigned char index,signed char a,signed char b,signed char c,int start,int end)
{
    Task *t;
    t=func_02031290((struct S02030FB4 *)func_020311B8(*(struct Tcbl * *)&((struct Obj03917 *)p)->f20,(void (*)(struct TcblNode *,void *))func_021BF1CC,32,1));
    func_02082BCC(t,0,32);
    t->owner=p;t->a=a;t->b=b;t->c=c;t->index=index;t->mask=63;t->start=start;t->end=end;
    func_021BEFC4((struct Owner *)p,t->index,t->mask,a,b,start,&t->count);
}

void func_021BF1CC(void *task,char *work)
{
    if(((struct Obj25324 *)(*(char * *)&((struct Obj01291 *)work)->f0))->fC) {
        func_02023F60(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
        func_02031194(task);return;
    }
    switch(((struct Obj01291 *)work)->f8) {
    case 0:
        if(((struct Obj01291 *)work)->f14==0) {
            func_021BEFC4((struct Owner *)(*(char * *)&((struct Obj01291 *)work)->f0),*(int *)&((struct Obj01291 *)work)->f18,*(int *)&((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->fA,((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f10,(int *)(work+0x14));
            (((struct Obj01291 *)work)->f8)++;
        }
        break;
    case 1:
        if(((struct Obj01291 *)work)->f14) return;
        break;
    }
    func_02023F60(((struct Obj01291 *)work)->fB,((struct Obj01291 *)work)->f1C,((struct Obj01291 *)work)->f18);
    func_02031194(task);
}

void func_021BF248(unsigned unused,char **q,unsigned *v){func_021BDF74(*q,(unsigned char)v[0],v[1]|(v[2]<<5)|(v[3]<<10));}

void func_021BF26C(unsigned unused,char **q,unsigned *v){struct Triple t;t.x=v[1];t.y=v[2];t.z=v[3];func_021BDF88(*q,(unsigned char)v[0],(int)&t);}
