/*
 * file:     br_util_p07.c
 * unit:     yes
 * function: func_021FD714, func_021FD71C, func_021FD72C, func_021FD73C, func_021FD744, func_021FD750, func_021FD760, func_021FD820, func_021FD854, func_021FD860, func_021FD938
 * address:  0x021FD714
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
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD964 0x021FD964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B688 0x0204B688 arm
 *   d_02200D5C 0x02200D5C data a4
 *   d_02200D68 0x02200D68 data a4
 *   func_0204B3B4   0x0204B3B4  arm
 *   func_021FC0C8   0x021FC0C8  thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021FDE88 0x021FDE88 thumb ov186
 *   func_021FD9A0 0x021FD9A0 thumb ov186
 *   func_021FDA7C 0x021FDA7C thumb ov186
 *   func_021FDBF4 0x021FDBF4 thumb ov186
 *   func_021FDF40 0x021FDF40 thumb ov186
 *   func_021FDFF0 0x021FDFF0 thumb ov186
 *   func_021FDFF4 0x021FDFF4 thumb ov186
 *   func_021FE1C4 0x021FE1C4 thumb ov186
 */
#include "../../matched/include/Obj14467.h"
#include "../../matched/include/Obj10793.h"
#include "../../matched/include/Obj24845.h"
#include "../../matched/include/Obj02236.h"
#include "../../matched/include/Obj24846.h"

struct Actor;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef void (*Callback)(u8 *,int *,u32);

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { int x,y; } Pair;

typedef struct { int x,y,z; } Triple;

typedef struct { char pad[0xC];int index;int task;char *resources;char pad18[0x1E0];int handles[12]; } Handles;

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,unsigned);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern int func_021FC124(char *,int,Triple *);
extern void func_021FD964(void *unused, int *state, u8 *p);
extern void func_021FBE54(char *,unsigned,unsigned);
extern int func_0204B294(unsigned,unsigned,unsigned,unsigned,Pair *,unsigned short,int);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_020061E4(u32 a);
extern void func_021FDE88(void);
extern void func_021FD9A0(void);
extern void func_021FDA7C(void);
extern void func_021FDBF4(void);
extern void func_021FDF40(void);
extern void func_021FDFF0(void);
extern void func_021FDFF4(void);
extern void func_021FE1C4(int *task, int *state, char *p);
void func_021FD714(void *p);
void func_021FD71C(u8 *p);
int func_021FD72C(int *p);
int *func_021FD73C(int *p, int v);
int func_021FD744(int *a);
int func_021FD750(int *p, int v);
char *func_021FD760(unsigned owner,char *resources,int index,int heap);
void func_021FD820(char *r5);
void func_021FD854(char *p);
void func_021FD860(char *p,u32 mode,const Pair *pair);
int func_021FD938(char *p);
extern const char d_02200D5C[],d_02200D68[];

void func_021FD714(void *p)
{
    func_020307B0(p);
}

void func_021FD71C(u8 *p)
{
    if(*(Callback *)&((struct Obj14467 *)p)->f0!=0)(*(Callback *)p)(p,(int *)(p+4),((struct Obj14467 *)p)->f8);
}

/*
 * Blocker leaf for ov183 021E1D48 and 021E20F8, parent cleared.
 */
int func_021FD72C(int *p)
{
    if (*p==0) return 1;
    return 0;
}

int *func_021FD73C(int *p, int v)
{
    p[0] = v;
    p[1] = 0;
    return p;
}


int func_021FD744(int *a)
{
    return (int)func_021FD73C(a, 0);
}


int func_021FD750(int *p, int v)
{
    return *p == v;
}

char *func_021FD760(unsigned owner,char *resources,int index,int heap)
{
    Triple triple;
    Pair pair;
    unsigned short res;
    char *p;
    int i;
    p=func_02030734(heap,0x264,0,d_02200D5C,0x7CA);
    func_02082BCC(p,0,0x264);
    ((Handles *)p)->resources=resources;((Handles *)p)->index=index;
    ((Handles *)p)->task=(int)func_021FD6D8((int)p,(int)func_021FD964,heap);
    func_021FBE54(((Handles *)p)->resources,index+9,heap);
    func_02082BCC(&pair,0,8);
    if(!func_021FC124(((Handles *)p)->resources,index+9,&triple)) func_02034714(d_02200D68,0,d_02200D68);
    i=0;
    res=index;
    for(;i<12;i++) {
        ((Handles *)p)->handles[i]=func_0204B294(owner,triple.y,triple.z,triple.x,&pair,res,heap);
        func_0204B3DC((struct Obj *)((Handles *)p)->handles[i],0);
        func_0204B688((struct Actor *)(((Handles *)p)->handles[i]),1);
    }
    return p;
}


/*
 * Release the twelve handles at r5+0x1F8, then tear the object down.
 */
void func_021FD820(char *r5)
{
    int i;
    for (i = 0; i < 0xC; i++)
        func_0204B3B4((struct Obj *)(*(int *)(r5 + 0x1F8 + i * 4)));
    func_021FC0C8((char *)(((struct Obj10793 *)r5)->f14), ((struct Obj10793 *)r5)->fC + 9);
    func_021FD714((void *)(((struct Obj10793 *)r5)->f10));
    func_020307B0((int *)r5);
}

void func_021FD854(char *p)
{
    func_021FD71C((u8 *)(((struct Obj24845 *)p)->f10));
}

/*
 * follower: 021FD938 already filed separately; lead excludes that existing accessor.
 */
void func_021FD860(char *p,u32 mode,const Pair *pair)
{
    if(pair) {
        *(Pair *)p=*pair;
        *(const Pair * *)&((struct Obj02236 *)p)->f8=pair;
    }
    ((struct Obj02236 *)p)->f22C=0;
    if(mode==0 && func_021FD750(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDE88)) func_020061E4(0x701);
    switch(mode) {
    case 0: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FD964);break;
    case 1: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FD9A0);break;
    case 2: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDA7C);break;
    case 3: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDBF4);break;
    case 4: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDE88);break;
    case 5: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDF40);break;
    case 6: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDFF0);break;
    case 7: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDFF4);break;
    case 8: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FE1C4);break;
    }
}

int func_021FD938(char *p){return ((struct Obj24846 *)p)->f22C;}
