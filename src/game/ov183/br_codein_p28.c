/*
 * file:     br_codein_p28.c
 * unit:     yes
 * function: func_021E2028, func_021E20A4, func_021E20F8, func_021E214C, func_021E2194
 * address:  0x021E2028
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E39B4 0x021E39B4 data a4
 *   func_02034714 0x02034714 arm
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_0201C440 0x0201C440 thumb
 *   func_021E23C8 0x021E23C8 thumb ov183
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021E24AC 0x021E24AC thumb ov183
 *   func_021E24C4 0x021E24C4 thumb ov183
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_020315D4 0x020315D4 arm
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021E21E0 0x021E21E0 thumb ov183
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 */
#include "../../matched/include/Obj01567.h"
#include "../../matched/include/Obj04580.h"
#include "../../matched/include/Obj10757.h"
#include "../../matched/include/Obj24648.h"
#include "../../matched/include/Obj06612.h"
#include "../../matched/include/Obj14442.h"
#include "../../matched/include/Obj24649.h"
#include "../../matched/include/Obj24650.h"
#include "../../matched/include/Obj10760.h"
#include "../../matched/include/Obj24651.h"
#include "../../matched/include/Obj24652.h"
#include "../../matched/include/Obj24653.h"

struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,int);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern u32 func_0201C440(void *p);
extern void func_021E23C8(char *,char *);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FD820(char *r5);
extern void func_021E24AC(char *,char *);
extern void func_021E24C4(char *,char *);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021FD714(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD1BC(void *p);
extern int func_021FC830(u8 *p);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern int *func_021FD73C(int *p, int v);
extern void func_021E21E0(int task, int *state, char *p);
extern int func_021FD744(int *a);
extern void func_021F9BA0(unsigned *ctx);
int func_021E2028(struct Obj0203159C *obj,int unused,char *arg);
int func_021E20A4(int obj,int b,char *arg,char *p);
int func_021E20F8(int a,int b,int c,char *p);
void func_021E214C(int *task,int *state,char *p);
void func_021E2194(int *task,int *state,char *p);
extern char d_021E39B4[];

int func_021E2028(struct Obj0203159C *obj,int unused,char *arg)
{
    char *p;
    int i;
    if (*(int *)&((struct Obj01567 *)arg)->f0>=4) func_02034714(d_021E39B4,0,d_021E39B4);
    p=func_0203159C(obj,40,func_021F9B9C((struct Obj24810 *)(((struct Obj01567 *)arg)->f10)));
    func_02082BCC(p,0,40);
    *(char * *)&((struct Obj04580 *)p)->f20=arg;
    ((struct Obj04580 *)p)->f1C=func_021F9B9C((struct Obj24810 *)(((struct Obj01567 *)arg)->f10));
    ((struct Obj04580 *)p)->f8=(int)func_021FD6D8((int)p,(int)func_021E214C,((struct Obj04580 *)p)->f1C);
    ((struct Obj04580 *)p)->f0=func_0201C440((void *)(((struct Obj04580 *)p)->f1C));
    func_021E23C8(p,arg);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x14)=(int)func_021FD760(((struct Obj01567 *)arg)->f8,(char *)(*(int *)&((struct Obj01567 *)arg)->fC),i,((struct Obj04580 *)p)->f1C);
    return 1;
}

/*
 * Extent remainder: zero alignment halfword at 021E20F6.
 */
int func_021E20A4(int obj,int b,char *arg,char *p)
{
    int i;
    for (i=0;i<2;i++) func_021FD820((char *)(*(int *)(p+i*4+0x14)));
    if (((struct Obj24648 *)(*(char * *)&((struct Obj10757 *)p)->f20))->f1C) func_021E24AC(p,arg);
    else { func_021E24AC(p,arg); func_021E24C4(p,arg); }
    func_0201C4C0((struct PrintSys *)(((struct Obj10757 *)p)->f0));
    func_021FD714((void *)(((struct Obj10757 *)p)->f8));
    func_020315D4((struct S020315D4 *)obj);
    return 1;
}

int func_021E20F8(int a,int b,int c,char *p)
{
    int i;
    func_021FD71C((u8 *)(((struct Obj06612 *)p)->f8));
    if (func_021FD72C((int *)(((struct Obj06612 *)p)->f8))) return 1;
    for (i=0;i<2;i++) func_021FD854((char *)(*(int *)(p+i*4+0x14)));
    func_0201C4E4((struct PrintSys *)(((struct Obj06612 *)p)->f0));
    if (((struct Obj06612 *)p)->f4) func_021FD1BC((void *)(((struct Obj06612 *)p)->f4));
    for (i=0;i<2;i++) if (*(int *)(p+i*4+0xc)) func_021FC830((u8 *)(*(int *)(p+i*4+0xc)));
    return 0;
}

void func_021E214C(int *task,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(((struct Obj24649 *)(*(char * *)&((struct Obj14442 *)p)->f20))->f4,2,3,0); *state=1; break;
    case 1: if (func_021FE7B0(*(int * *)&((struct Obj24650 *)(*(char * *)&((struct Obj14442 *)p)->f20))->f4)) *state=2; break;
    case 2: func_021FD73C(task,(int)func_021E21E0); break;
    }
}

void func_021E2194(int *task,int *state,char *p)
{
    switch (*state) {
    case 0: func_021FE784(((struct Obj24651 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f4,2,3,1); *state=1; break;
    case 1: if (func_021FE7B0(*(int * *)&((struct Obj24652 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f4)) *state=2; break;
    case 2: func_021F9BA0((unsigned int *)(((struct Obj24653 *)(*(char * *)&((struct Obj10760 *)p)->f20))->f10)); func_021FD744(task); break;
    }
}
