/*
 * file:     guru2_main_p14.c
 * unit:     yes
 * function: func_021E0698, func_021E06E0
 * address:  0x021E0698
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
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 *   func_02047E88 0x02047E88 arm
 *   d_021E1E60 0x021E1E60 data a4
 *   d_021E1E70 0x021E1E70 data a4
 *   d_021E212C 0x021E212C data a4
 */
#include "../../matched/include/Obj14235.h"
#include "../../matched/include/Obj10628.h"
#include "../../matched/include/Obj14236.h"

struct Arg;
struct Mtx33;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x,y,z; } Vec;

typedef struct { int m[9]; } Mtx;

typedef struct { Vec pos,scale; Mtx rot; } Transform;

typedef unsigned int   u32;

extern u32 func_02048A18(u8 *a0, int i);
extern void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst);
extern void func_02047A60(void *a0, struct Arg *a1);
extern int func_02047E88(void *,const void *);
void func_021E0698(u8 *p);
void func_021E06E0(char *p);
extern const char d_021E1E60[],d_021E1E70[],d_021E212C[];

static inline void VecSet(Vec *v,int x,int y,int z)
{
    v->x=x;
    v->y=y;
    v->z=z;
}

/*
 * lever: Position setter before scale setter keeps zero in r0 and scale in r1.
 */
void func_021E0698(u8 *p)
{
    Transform t;
    void *object;
    object = (void *)func_02048A18(((struct Obj14235 *)p)->fAF4,(u16)(((struct Obj14235 *)p)->fDA4));
    VecSet(&t.pos,0,0,0);
    VecSet(&t.scale,4096,4096,4096);
    func_020520FC(0,0,0,(struct Mtx33 *)&t.rot);
    func_02047A60(object,(struct Arg *)(&t));
}

void func_021E06E0(char *p)
{
    int i;
    char *q=p+0x1a0;
    ((struct Obj14236 *)q)->f938=func_02047E88(((struct Obj10628 *)p)->fAF4,d_021E1E60);
    ((struct Obj14236 *)q)->f93C=func_02047E88(((struct Obj10628 *)p)->fAF4,d_021E1E70);
    for (i=0;i<5;i++) *(int *)(q+0x940+i*4)=func_02047E88(((struct Obj10628 *)p)->fAF4,d_021E212C+i*16);
}
