/*
 * file:     guru2_main_p15.c
 * unit:     yes
 * function: func_021E073C, func_021E078C, func_021E07A4, func_021E0848
 * address:  0x021E073C
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
 *   func_020480E4 0x020480E4 arm
 *   func_021E0B14 0x021E0B14 thumb ov137
 *   func_021E0BA4 0x021E0BA4 thumb ov137
 *   func_021E09C0 0x021E09C0 thumb ov137
 *   func_021E0B38 0x021E0B38 thumb ov137
 *   func_021E0BC0 0x021E0BC0 thumb ov137
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 *   func_0207ADC4 0x0207ADC4 arm
 */
#include "../../matched/include/Obj10629.h"
#include "../../matched/include/Obj14237.h"
#include "../../matched/include/Obj23777.h"
#include "../../matched/include/Obj08221.h"
#include "../../matched/include/Obj02873.h"
#include "../../matched/include/Obj02874.h"
#include "../../matched/include/Obj08222.h"
#include "../../matched/include/Obj08223.h"
#include "../../matched/include/Obj14238.h"

struct Ctx;
struct Arg;
struct Mtx33;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef enum { COUNT_ZERO=0, COUNT_NEGATIVE=-1 } Count;

typedef struct { int active; char rest[0xb0]; } RecordA;

typedef struct { int active; char rest[0x78]; } RecordB;

typedef struct { int active; char rest[0x64]; } RecordC;

typedef struct {
    char pad[0x140];
    RecordA a[5];
    RecordB b[5];
    RecordC c[5];
} Block;

typedef struct {int x,y,z;} Vec;

typedef struct {int m[9];} Mtx;

typedef struct {Vec pos,scale;Mtx rot;} Transform;

typedef enum {INDEX_ZERO=0} Index;

extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_021E0B14(char *,char *);
extern void func_021E0BA4(char *,char *);
extern void func_021E09C0(char *,int *,int,int);
extern void func_021E0B38(char *,char *,int);
extern void func_021E0BC0(char *,char *,int);
extern u32 func_02048A18(u8 *a0, int i);
extern void func_020520FC(int,int,int,struct Mtx33 *);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_0207ADC4(Mtx *);
void func_021E073C(char *p);
void func_021E078C(char *p,char *q);
void func_021E07A4(char *p);
void func_021E0848(u8 *p);

void func_021E073C(char *p)
{
    int i;
    char *q = p+0x1a0;
    for (i=0;i<5;i++) func_020480E4(((struct Obj10629 *)p)->fAF4,(u16)(*(int *)(q+0x940+i*4)));
    func_020480E4(((struct Obj10629 *)p)->fAF4,(u16)(((struct Obj14237 *)q)->f938));
    func_020480E4(((struct Obj10629 *)p)->fAF4,(u16)(((struct Obj14237 *)q)->f93C));
}

void func_021E078C(char *p,char *q) { ((struct Obj23777 *)q)->f4=1; func_021E0B14(p,q); func_021E0BA4(p,q); }

void func_021E07A4(char *p)
{
    Count count;
    int i=0;
    Block *base;
    count=((struct Obj08221 *)p)->f30;
    base=(Block *)(p+0x1a0);
    for (;i<count;i++) {
        if (base->a[i].active)
            func_021E09C0((char *)&base->a[i],(int *)(p+0x110),*(u16 *)(p+0x60+i*2)<<12,((struct Obj08221 *)p)->f5C);
        if (base->b[i].active)
            func_021E0B38(p,(char *)&base->b[i],((struct Obj08221 *)p)->f5C);
        if (base->c[i].active)
            func_021E0BC0(p,(char *)&base->c[i],i);
    }
}

static inline void VecSet(Vec *v,int x,int y,int z){v->x=x;v->y=y;v->z=z;}

void func_021E0848(u8 *p)
{
    int i=0;
    int count=((struct Obj08222 *)p)->f30;
    u8 *base=p+0x1a0;
    u8 *first=base+0x140,*second=base+0x4c4,*third=base+0x730;
    for(;i<count;i=i+1) {
        if(((struct Obj02873 *)first)->f4) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Obj08222 *)p)->fAF4,(u16)(((struct Obj14238 *)base)->f938));
            VecSet(&t.pos,((struct Obj02873 *)first)->f44,((struct Obj02873 *)first)->f48,((struct Obj02873 *)first)->f4C);
            VecSet(&t.scale,((struct Obj02873 *)first)->f38,((struct Obj02873 *)first)->f3C,((struct Obj02873 *)first)->f40);
            func_020520FC(((struct Obj02873 *)first)->f24,((struct Obj02873 *)first)->f26,((struct Obj02873 *)first)->f28,(struct Mtx33 *)&t.rot);
            func_02047A60(object,(struct Arg *)(&t));
        }
        if(((struct Obj02874 *)second)->f0) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Obj08222 *)p)->fAF4,(u16)(((struct Obj14238 *)base)->f93C));
            VecSet(&t.pos,((struct Obj02874 *)second)->f18,((struct Obj02874 *)second)->f1C,((struct Obj02874 *)second)->f20);
            VecSet(&t.scale,((struct Obj02874 *)second)->fC,((struct Obj02874 *)second)->f10,((struct Obj02874 *)second)->f14);
            func_020520FC(((struct Obj02874 *)second)->f4,((struct Obj02874 *)second)->f6,((struct Obj02874 *)second)->f8,(struct Mtx33 *)&t.rot);
            func_02047A60(object,(struct Arg *)(&t));
        }
        if(((struct Obj08223 *)third)->f0) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Obj08222 *)p)->fAF4,(u16)(*(int *)((unsigned)(base+i*4)+0x940)));
            VecSet(&t.pos,((struct Obj08223 *)third)->f4,((struct Obj08223 *)third)->f8,((struct Obj08223 *)third)->fC);
            VecSet(&t.scale,4096,4096,4096);
            func_0207ADC4(&t.rot);
            func_02047A60(object,(struct Arg *)(&t));
        }
        first+=0xb4;second+=0x7c;third+=0x68;
    }
}
