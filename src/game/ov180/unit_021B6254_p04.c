/*
 * file:     unit_021B6254_p04.c
 * unit:     yes
 * function: func_021B6750, func_021B675C, func_021B6764, func_021B6770, func_021B6778, func_021B67B4, func_021B67C4, func_021B67EC, func_021B681C, func_021B682C, func_021B6844, func_021B68A8, func_021B6914, func_021B692C, func_021B6984, func_021B699C, func_021B69E8
 * address:  0x021B6750
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E8C0 0x0204E8C0 arm
 *   func_0204EA0C 0x0204EA0C arm
 *   func_02050B80 0x02050B80 arm
 *   func_02050ED4 0x02050ED4 arm
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051230 0x02051230 arm
 *   d_021B8108 0x021B8108 data a4
 *   func_02050DB8  0x02050DB8  arm
 *   func_020515B4 0x020515B4 arm
 *   d_021B80CC 0x021B80CC data a4
 *   func_02051758 0x02051758 arm
 *   func_02051648 0x02051648 arm
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_02015BF0 0x02015BF0 thumb
 *   func_02048A24 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   d_021B8034 0x021B8034 data a4
 *   d_021B801C 0x021B801C data a4
 *   d_021B8028 0x021B8028 data a4
 *   func_02048AC4  0x02048AC4  arm
 *   func_02014BA8  0x02014BA8  thumb
 *   d_021B80C0 0x021B80C0 data a4
 *   func_02017100 0x02017100 thumb
 *   func_020159C8 0x020159C8 thumb
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015E04 0x02015E04 thumb
 *   func_02015BA4  0x02015BA4  thumb
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 *   _fflt 0x0209BDBC arm
 *   _fmul 0x0209C95C arm
 *   _fdiv 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../../matched/include/Obj10718.h"
#include "../../matched/include/Obj14399.h"
#include "../../matched/include/Obj24485.h"
#include "../../matched/include/Obj14400.h"
#include "../../matched/include/Obj14401.h"
#include "../../matched/include/Obj24486.h"
#include "../../matched/include/Obj00547.h"
#include "../../matched/include/Obj04569.h"
#include "../../matched/include/Obj06586.h"
#include "../../matched/include/Obj14402.h"
#include "../../matched/include/Obj14403.h"

struct Light;
struct Obj;
struct Rec;
struct Stats;
struct Sub150;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct {int a,b,c;} Triple;

typedef struct { int a,b,c,d,e,f,g,h; } Desc;

typedef struct { int x,y,z; } Vec;

typedef struct { unsigned words[9]; } Params;

extern void func_0204E8C0(u32 heap);
extern int func_0204EA0C(void);
extern void func_02050B80(u32);
extern void func_02050ED4(void);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern void func_02051230(void *,void *,int,int);
extern void func_02050DB8(u8 *p);
extern int func_020515B4(void *p, int b, int c);
extern int func_02051758(int a0);
extern void func_02051648(void *,Desc *,unsigned short,void *,void *,void *,unsigned);
extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *,unsigned);
extern void func_02015BF0(void *);
extern void *func_02048A24(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,void *,void *,void *,unsigned short);
extern void func_02048AD0(struct Light *l);
extern u32 func_02048AC4(void *ptr);
extern void func_02014BA8(u8 *a0);
extern void func_02017100(void *p, struct Stats *out, u32 lvl);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015CAC(void *p, u32 *src);
extern void func_02015E04(void *p);
extern void func_02015BA4(void *sys, void *obj);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
void func_021B6750(void);
void func_021B675C(void);
void func_021B6764(void);
void func_021B6770(void);
void func_021B6778(char *p);
void func_021B67B4(int *p);
void func_021B67C4(char *p,int a);
void func_021B67EC(char *p);
void func_021B681C(int *p);
void func_021B682C(int *p, int a);
void func_021B6844(char *p,void *q,int mode);
void func_021B68A8(char *p);
void func_021B6914(int *p);
void func_021B692C(char *p);
void func_021B6984(char *p);
void func_021B699C(char *p,int v);
void func_021B69E8(int *p);
extern int d_021B8108;
extern Triple d_021B80CC;
extern unsigned d_021B8034[];
extern unsigned d_021B801C[];
extern unsigned d_021B8028[];
extern const Vec d_021B80C0;

void func_021B6750(void) {func_0204E8C0(141);}

void func_021B675C(void) {func_0204EA0C();}

void func_021B6764(void) {func_02050B80(141);}

void func_021B6770(void) {func_02050ED4();}

void func_021B6778(char *p){((struct Obj10718 *)p)->f28=(void *)func_02050C04((int)(p+48),18432,1,141);func_02051230(((struct Obj10718 *)p)->f28,(void *)func_0205121C(216,*(int *)((u32)&d_021B8108+((struct Obj10718 *)p)->f915A*4),141),1,0);}


void func_021B67B4(int *p)
{
    func_02050DB8((u8 *)(((struct Obj14399 *)p)->f28));
    ((struct Obj14399 *)p)->f28 = 0;
}

void func_021B67C4(char *p,int a){Triple v;v=d_021B80CC;func_020515B4(((struct Obj24485 *)p)->f28,a,(int)((int *)&v));}

void func_021B67EC(char *p){((struct Obj14400 *)p)->f2C=(void *)func_02050C04((int)(p+18480),18432,1,141);func_02051230(((struct Obj14400 *)p)->f2C,(void *)func_0205121C(216,51,141),1,0);}


void func_021B681C(int *p)
{
    func_02050DB8((u8 *)(((struct Obj14401 *)p)->f2C));
    ((struct Obj14401 *)p)->f2C = 0;
}


void func_021B682C(int *p, int a)
{
    int buf[3] = {0, 0, 0};

    func_020515B4(((struct Obj24486 *)p)->f2C, a, (int)buf);
}

void func_021B6844(char *p,void *q,int mode) {
 Desc d;
 if(q!=0) {
  if(mode==1) { d.b=0x4000; d.c=-0x4000; } else { d.b=0xE000; d.c=0x6000; }
  d.d=-0x5548; d.e=0x5548; d.a=2; d.g=d.a<<21;
  d.f=0; d.h=0;
  func_02051758((int)q);
  func_02051648(q,&d,0x2000,0,0,0,141);
 }
}

void func_021B68A8(char *p) {
 ((struct Obj00547 *)p)->f18=func_02014B08(1,(void *)141); func_02016020(((struct Obj00547 *)p)->f18,0); func_02015BF0(((struct Obj00547 *)p)->f18);
 ((struct Obj00547 *)p)->f20=func_02048A24(2,0x60000,0xFFFA0000,0xFFF80000,0x80000,0x1000,0x400000,0,d_021B8034,d_021B801C,d_021B8028,141);
 func_02048AD0(((struct Obj00547 *)p)->f20);
}


void func_021B6914(int *p)
{
    func_021B6984((char *)p);
    func_02048AC4((void *)(((struct Obj04569 *)p)->f20));
    func_02014BA8((u8 *)(((struct Obj04569 *)p)->f18));
}

void func_021B692C(char *p) {
    Params params;
    Vec pos=d_021B80C0;
    func_02017100((void *)(*(int *)(p+0x9140+((struct Obj06586 *)p)->f915D*4)),(struct Stats *)(&params),0);
    ((struct Obj06586 *)p)->f1C=(int)func_020159C8((struct Obj *)(((struct Obj06586 *)p)->f18),0xb0000,-196608,0,(const struct Sub150 *)(&params));
    func_02015CAC((void *)(((struct Obj06586 *)p)->f1C),(u32 *)(&pos));
    func_02015E04((void *)(((struct Obj06586 *)p)->f1C));
}


/*
 * 2026-10-05: the callee func_02015BA4 takes a second argument (r1 = the field value tested); the caller passes it.
 */
void func_021B6984(char *p)
{
    int v = *(int *)(p + 0x1c);

    if (v != 0) {
        func_02015BA4((void *)(*(int *)(p + 0x18)), (void *)v);
        *(int *)(p + 0x1c) = 0;
    }
}

void func_021B699C(char *p,int v) {
    Vec pos;
    float delta;
    func_02015C30((void *)(((struct Obj14402 *)p)->f1C),(u32 *)(&pos));
    if(v>0) delta=0.5f*(float)(v<<12);
    else delta=(float)(v<<12)/0.5f;
    pos.x=pos.x+(int)delta;
    func_02015C48((void *)(((struct Obj14402 *)p)->f1C),(u32 *)(&pos));
}


/*
 *   func_02015E04 (0x02015E04) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_021B69E8(int *p)
{
    func_02015E04((void *)(((struct Obj14403 *)p)->f1C));
    ((struct Obj14403 *)p)->f24 = 1;
}
