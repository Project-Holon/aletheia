/*
 * file:     egg_demo_view_p04.c
 * unit:     yes
 * function: func_021F6D7C, func_021F6D90, func_021F6DB4, func_021F6E4C, func_021F6E5C, func_021F6EE4
 * address:  0x021F6D7C
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201600C 0x0201600C thumb
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015F50 0x02015F50 thumb
 *   func_02030734 0x02030734 arm
 *   func_02050B80 0x02050B80 arm
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051B04 0x02051B04 arm
 *   func_02051230 0x02051230 arm
 *   d_021F73F4 0x021F73F4 data a4
 *   d_021F7300 0x021F7300 data a4
 *   func_02050ED4 0x02050ED4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_020515B4 0x020515B4 arm
 *   func_02051620 0x02051620 arm
 *   d_021F73B4 0x021F73B4 data a4
 *   func_02050BE8 0x02050BE8 arm
 */
#include "../../matched/include/Obj25762.h"
#include "../../matched/include/Obj14713.h"
#include "../../matched/include/Obj03373.h"
#include "../../matched/include/Obj02263.h"

struct McssFade;
typedef unsigned char u8;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned short u16;

struct Pair { unsigned archive,member; };

typedef struct { int x,y,z; } Vec;

extern int func_0201600C(void *);
extern void func_02015EB0(void *);
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02050B80(unsigned);
extern int func_02050C04(int,int,int,int);
extern int func_0205121C(unsigned,unsigned,unsigned);
extern u16 func_02051B04(void *);
extern void func_02051230(void *,unsigned,unsigned,unsigned);
extern void func_02050ED4(void);
extern u32 func_020307B0(void *p);
extern int func_020515B4(void *p, int b, int c);
extern void func_02051620(void *);
extern void func_02050BE8(void);
int func_021F6D7C(char *p);
void func_021F6D90(char *p);
char *func_021F6DB4(unsigned heap,unsigned count,const void *table);
void func_021F6E4C(char *a);
void func_021F6E5C(char *p);
void func_021F6EE4(char *p);
extern const char d_021F73F4[];
extern const unsigned long long d_021F7300;
extern const Vec d_021F73B4;

int func_021F6D7C(char *p){if(func_0201600C(((struct Obj25762 *)p)->f34)==0)return 1;return 0;}

void func_021F6D90(char *p){func_02015EB0(((struct Obj14713 *)p)->f34);func_02015F50(*(struct McssFade * *)&((struct Obj14713 *)p)->f34,16,0,2,32767);}

char *func_021F6DB4(unsigned heap,unsigned count,const void *table)
{
    char *p;
    unsigned zero[3]={0};
    unsigned long long config;
    int resource;
    p=func_02030734(heap,0x481C,1,d_021F73F4,0x502);
    ((struct Obj03373 *)p)->f0=0;
    ((struct Obj03373 *)p)->f2=0;
    ((struct Obj03373 *)p)->f4=count;
    *(const void * *)&((struct Obj03373 *)p)->f8=table;
    ((struct Obj03373 *)p)->f4814=0;
    ((struct Obj03373 *)p)->f4818=-1;
    func_02050B80(heap);
    *(int *)&((struct Obj03373 *)p)->f480C=func_02050C04((int)(p+12),0x4800,1,heap);
    config=d_021F7300;
    resource=func_0205121C((unsigned)config,(unsigned)(config>>32),heap);
    ((struct Obj03373 *)p)->f4810=func_02051B04((void *)resource);
    func_02051230(((struct Obj03373 *)p)->f480C,resource,1,0);
    return p;
}


void func_021F6E4C(char *a)
{
    func_02050ED4();
    func_020307B0(a);
}

/*
 * prototype: 515B4 receives visibly loaded r1/r2 despite legacy one-argument callee.
 */
void func_021F6E5C(char *p)
{
    if (((struct Obj02263 *)p)->f4814) {
        Vec v=d_021F73B4;
        while (((struct Obj02263 *)p)->f2<((struct Obj02263 *)p)->f4) {
            const char *table=*(const char * *)&((struct Obj02263 *)p)->f8;
            unsigned index=((struct Obj02263 *)p)->f2;
            u16 frame=((struct Obj02263 *)p)->f0;
            u16 key=*(u16 *)(table+(int)index*4);
            if (frame!=key) break;
            func_020515B4(*(void **)(p+*(unsigned char *)(table+index*4+2)*0x4808+0x480c),*(unsigned char *)(table+index*4+3),(int)(&v));
            (((struct Obj02263 *)p)->f2)++;
        }
        (((struct Obj02263 *)p)->f0)++;
    }
    if (((struct Obj02263 *)p)->f4818>=0) {
        if (((struct Obj02263 *)p)->f4818==0) func_02051620(((struct Obj02263 *)p)->f480C);
        (((struct Obj02263 *)p)->f4818)--;
    }
}

void func_021F6EE4(char *p){func_02050BE8();}
