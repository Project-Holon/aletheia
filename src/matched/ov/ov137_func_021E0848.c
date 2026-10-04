/*
 * function: func_021E0848
 * address: 0x021E0848
 * packet: pkt_ov137_021E0848
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   func_020520FC 0x020520FC arm
 *   func_02047A60 0x02047A60 arm
 *   func_0207ADC4 0x0207ADC4 arm
 */
#include "../include/Obj02873.h"
#include "../include/Obj02874.h"
#include "../include/Obj08222.h"
#include "../include/Obj08223.h"
#include "../include/Obj14238.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {int x,y,z;} Vec;
typedef struct {int m[9];} Mtx;
typedef struct {Vec pos,scale;Mtx rot;} Transform;
typedef enum {INDEX_ZERO=0} Index;
extern void *func_02048A18(void *,u16);
struct Mtx33;
extern void func_020520FC(int,int,int,struct Mtx33 *);
extern void func_02047A60(void *,Transform *);
extern void func_0207ADC4(Mtx *);
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
            void *object=func_02048A18(((struct Obj08222 *)p)->fAF4,((struct Obj14238 *)base)->f938);
            VecSet(&t.pos,((struct Obj02873 *)first)->f44,((struct Obj02873 *)first)->f48,((struct Obj02873 *)first)->f4C);
            VecSet(&t.scale,((struct Obj02873 *)first)->f38,((struct Obj02873 *)first)->f3C,((struct Obj02873 *)first)->f40);
            func_020520FC(((struct Obj02873 *)first)->f24,((struct Obj02873 *)first)->f26,((struct Obj02873 *)first)->f28,(struct Mtx33 *)&t.rot);
            func_02047A60(object,&t);
        }
        if(((struct Obj02874 *)second)->f0) {
            Transform t;
            void *object=func_02048A18(((struct Obj08222 *)p)->fAF4,((struct Obj14238 *)base)->f93C);
            VecSet(&t.pos,((struct Obj02874 *)second)->f18,((struct Obj02874 *)second)->f1C,((struct Obj02874 *)second)->f20);
            VecSet(&t.scale,((struct Obj02874 *)second)->fC,((struct Obj02874 *)second)->f10,((struct Obj02874 *)second)->f14);
            func_020520FC(((struct Obj02874 *)second)->f4,((struct Obj02874 *)second)->f6,((struct Obj02874 *)second)->f8,(struct Mtx33 *)&t.rot);
            func_02047A60(object,&t);
        }
        if(((struct Obj08223 *)third)->f0) {
            Transform t;
            void *object=func_02048A18(((struct Obj08222 *)p)->fAF4,*(int *)((unsigned)(base+i*4)+0x940));
            VecSet(&t.pos,((struct Obj08223 *)third)->f4,((struct Obj08223 *)third)->f8,((struct Obj08223 *)third)->fC);
            VecSet(&t.scale,4096,4096,4096);
            func_0207ADC4(&t.rot);
            func_02047A60(object,&t);
        }
        first+=0xb4;second+=0x7c;third+=0x68;
    }
}
