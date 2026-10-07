/*
 * file:     guru2_main_p17.c
 * unit:     yes
 * function: func_021E0C08, func_021E0C70, func_021E0CA4, func_021E0CCC
 * address:  0x021E0C08
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   d_021E22B8 0x021E22B8 data
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   d_021E1CB8 0x021E1CB8 data a4
 *   func_021E078C 0x021E078C thumb ov137
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj06537.h"
#include "../../matched/include/Obj23785.h"
#include "../../matched/include/Obj23786.h"
#include "../../matched/include/Obj08224.h"
#include "../../matched/include/Obj08225.h"

struct Node;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,unsigned);
extern void func_02030DA8(void *,void (*)(void *,void *),void *,int);
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *);
extern void func_021E078C(char *,char *);
extern void func_020061E4(u32 a);
void func_021E0C08(char *p,int a,int b,int c,int d,int e,int *q);
void func_021E0C70(struct Node *task,char *p);
int func_021E0CA4(char *p);
int func_021E0CCC(int *p);
extern const char d_021E22B8[];

void func_021E0C08(char *p,int a,int b,int c,int d,int e,int *q)
{
    int *r;
    q[3]=a;
    q[4]=b;
    q[5]=c;
    q[6]=b;
    q[7]=d<<12;
    q[8]=e<<12;
    q[0]=1;
    q[2]=0;
    r=func_02030734(0x8072,24,0,d_021E22B8,0x130e);
    func_02082BCC(r,0,24);
    r[5]=(int)p;
    r[4]=(int)q;
    func_02030DA8(((struct Obj06537 *)p)->fD98,(void (*)(void *, void *))func_021E0C70,r,0);
}

extern int (*const d_021E1CB8[])(char *);

void func_021E0C70(struct Node *task,char *p) { int result; do { result=d_021E1CB8[*(int *)p](p); } while(result==1); if(result==2) { ((struct Obj23786 *)(*(char * *)&((struct Obj23785 *)p)->f10))->f8=1; func_020307B0(p); func_02030EAC(task); } }

int func_021E0CA4(char *p) { char *q; q=*(char * *)&((struct Obj08224 *)p)->f10; ((struct Obj08225 *)q)->f38=4096; ((struct Obj08225 *)q)->f3C=4096; ((struct Obj08225 *)q)->f40=4096; ((struct Obj08225 *)q)->f54=0xc0000; func_021E078C(*(char * *)&((struct Obj08224 *)p)->f14,q); ((struct Obj08224 *)p)->fC=0x8000; ((struct Obj08224 *)p)->f0=1; return 0; }

int func_021E0CCC(int *p)
{
    int *q = (int *)p[4];
    q[21] -= p[3];
    if (p[2] == 0 && q[21] <= 0x68000) {
        p[2] = 1;
        func_020061E4(0x725);
    }
    if (q[21] <= 0x20000) {
        q[21] = 0x20000;
        p[0] = 2;
    }
    return 0;
}
