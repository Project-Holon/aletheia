/*
 * file:     musical_shot_sys_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F3970, func_021F3A08, func_021F3A54, func_021F3AE0, func_021F3AF0
 * address:  0x021F36C0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0203630C 0x0203630C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F4284 0x021F4284 thumb ov112
 *   func_0202208C 0x0202208C thumb
 *   d_021F836C 0x021F836C data a4
 *   func_020221A4 0x020221A4 thumb
 *   func_0207D534 0x0207D534 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021F4300 0x021F4300 thumb ov112
 *   func_021F3BF0 0x021F3BF0 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   func_02034A5C 0x02034A5C arm
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   ov_abs_84 0x00000084 data
 *   func_021F3C50 0x021F3C50 thumb ov112
 *   func_021F4350 0x021F4350 thumb ov112
 *   func_021F44E8 0x021F44E8 thumb ov112
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_020434DC 0x020434DC arm
 *   d_021F816C 0x021F816C data a4
 *   d_021F815C 0x021F815C data a4
 *   d_020A1448 0x020A1448 data a4
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_021F67E0  0x021F67E0  thumb  ov112
 *   func_021F3CA4  0x021F3CA4  thumb  ov112
 *   func_021F3F00  0x021F3F00  thumb  ov112
 *   func_021F40F4  0x021F40F4  thumb  ov112
 *   func_021F6F24  0x021F6F24  thumb  ov112
 *   func_021F6FB0  0x021F6FB0  thumb  ov112
 *   func_021F75DC  0x021F75DC  thumb  ov112
 *   func_021F7098  0x021F7098  thumb  ov112
 *   d_021F8380     0x021F8380  data  ov112  a1
 */
#include "../../matched/include/Obj00587.h"
#include "../../matched/include/Obj08019.h"
#include "../../matched/include/Obj10295.h"
#include "../../matched/include/Obj05308.h"
#include "../../matched/include/Obj22509.h"
#include "../../matched/include/Obj22510.h"
#include "../../matched/include/Obj08020.h"
#include "../../matched/include/Obj10296.h"

struct Obj0203159C;
struct RtcDate;
struct Node;
struct S020315D4;
struct Cfg;
struct DispConfig;
struct DispVram;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 a:5,b:4,c:7,d:5,e:6,f:5;} Settings;

typedef struct {u32 x,y,z,week;} Options;

typedef struct {u32 a,b;u8 *config;u32 c,d;} Save;

typedef struct {u16 heap,pad;void *task;Save *save;void *scene,*actors;} State;

typedef enum {ConfigSize=432} AllocSize;

typedef short s16;

struct F5 { u32 v : 5; };

struct BF { u16 a : 2; u16 c : 1; u16 b : 5; };

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern int func_02034AC4(int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0203F4E4(struct RtcDate *date);
extern u16 func_02045A98(void);
extern u32 func_0203630C(void);
extern void *func_020056A0(u32,u32,u32);
extern void *func_021F4284(u8 *,u32,u32,u32,u16);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern unsigned func_020221A4(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021F4300(u8 *);
extern void func_021F3BF0(u8 *);
extern void func_02030EAC(struct Node *n);
extern void func_02034A5C(int);
extern u32 func_020307B0(void *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_021F3C50(u8 *);
extern void func_021F4350(u8 *p);
extern int func_021F44E8(u32 *p);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0202223C(u32 a, u32 color);
extern u32 func_02022224(void *win);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0204A5AC(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern char *func_021F67E0(u16 a, u8 b, u8 c, u8 d, u32 e, u16 heap);
extern void func_021F3CA4(char *p);
extern void func_021F3F00(void *o);
extern void func_021F40F4(u8 *p);
extern u8 *func_021F6F24(u32 heap, u32 v);
extern void func_021F6FB0(void *a, u8 b);
extern void func_021F75DC(u8 *p, u16 v);
extern void func_021F7098(u8 *p, u16 v);
int func_021F36C0(void *owner,int unused,const Save *save);
int func_021F3970(void *owner,void *arg,int flag,u8 *p);
int func_021F3A08(int a,int b,int c,u8 *p);
void func_021F3A4C(void);
void func_021F3A54(u8 *p);
void func_021F3AE0(void *a0);
u8 *func_021F3AF0(u8 *src, u16 heap);
extern char ov132_id[];
extern const char d_021F836C[];
extern u8 ov_abs_84[];
extern char d_021F816C[],d_021F815C[],d_020A1448[];
extern char d_021F8380[];

int func_021F36C0(void *owner,int unused,const Save *save)
{
 State *p;u8 *cfg;u8 i,j;Options options;u32 length;
 func_0203064C(1,74,1<<19);
 p=func_0203159C(owner,20,74);p->heap=74;
 if(save==0){
  func_02034AC4((u32)ov132_id);
  p->save=func_02030734(74,20,0,d_021F836C,110);
  length=ConfigSize;
  p->save->config=func_02030734(74,length,1,d_021F836C,111);
  p->save->b=0;
  cfg=p->save->config;
  func_0203F4E4((struct RtcDate *)(&options));
  ((Settings *)cfg)->a=3;((Settings *)cfg)->b=(u8)2;
  ((Settings *)cfg)->c=options.x;((Settings *)cfg)->d=options.y;((Settings *)cfg)->e=options.z;
  *(u16 *)((u32)cfg+(length-0x4C))=0x30DD;
  *(u16 *)((u32)cfg+(length-0x4A))=0x30B1;
  *(u16 *)((u32)cfg+(length-0x48))=0x30C3;
  *(u16 *)((u32)cfg+(length-0x46))=0x30BF;
  *(u16 *)((u32)cfg+(length-0x44))=0x30FC;
  *(u16 *)((u32)cfg+(length-0x42))=0x30EA;
  *(u16 *)((u32)cfg+(length-0x40))=0x30E2;
  *(u16 *)((u32)cfg+(length-0x3E))=0x30F3;
  *(u16 *)((u32)cfg+(length-0x3C))=0x30B9;
  *(u16 *)((u32)cfg+(length-0x3A))=0x30BF;
  *(u16 *)((u32)cfg+(length-0x38))=0x30FC;
  *(u16 *)((u32)cfg+(length-0x36))=0x30EA;
  *(u16 *)((u32)cfg+(length-0x34))=func_02045A98();
  ((struct Obj08019 *)cfg)->f4=643;((struct Obj08019 *)cfg)->f5C=643;((struct Obj08019 *)cfg)->fB4=643;((struct Obj08019 *)cfg)->f10C=643;
  for(i=0;i<4;i++){
   u8 *q;
   q=cfg+88U*i;
   ((struct Obj00587 *)q)->fC=0x30C8;((struct Obj00587 *)q)->fE=0x30EC;((struct Obj00587 *)q)->f10=0x30FC;((struct Obj00587 *)q)->f12=0x30CA;((struct Obj00587 *)q)->f14=0xFF11+i;((struct Obj00587 *)q)->f16=0;
   for(j=0;j<8;j++){u8 *slot;slot=q+8*j;((struct Obj10295 *)slot)->f1C=255;((struct Obj10295 *)slot)->f1E=0;((struct Obj10295 *)slot)->f20=10;}
   q=cfg+88*i;
   ((struct Obj00587 *)q)->f1C=11;((struct Obj00587 *)q)->f1E=0;q[32]=7;
   ((struct Obj00587 *)q)->f24=11;((struct Obj00587 *)q)->f26=0;q[40]=8;
   ((struct Obj00587 *)q)->f2C=11;((struct Obj00587 *)q)->f2E=0;q[48]=6;
   ((struct Obj00587 *)q)->f34=11;((struct Obj00587 *)q)->f36=0;q[56]=4;
   ((struct Obj00587 *)q)->f3C=11;((struct Obj00587 *)q)->f3E=0;q[64]=2;
   ((struct Obj00587 *)q)->f44=11;((struct Obj00587 *)q)->f46=0;q[72]=1;
   ((struct Obj00587 *)q)->f4C=11;((struct Obj00587 *)q)->f4E=0;q[80]=0;
  }
  if(func_0203630C()&256)p->save->a=1;else p->save->a=0;
  p->save->c=0;
 }else p->save=(Save *)save;
 if(p->save->b==1)func_02034AC4((u32)ov132_id);
 p->task=func_020056A0((u32)func_021F3A4C,(u32)p,64);
 func_021F3A54((u8 *)p);
 p->scene=func_021F3AF0(p->save->config,p->heap);
 p->actors=func_021F4284(p->save->config,p->save->c,p->save->a,p->save->d,p->heap);
 func_0202208C(0,1,1,0,6,1,p->heap);return 1;
}

int func_021F3970(void *owner,void *arg,int flag,u8 *p) {
    if (!func_020221A4()) return 0;
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    func_0207D63C((void *)0x04000050,0,0,31,31);
    func_021F4300(*(u8 * *)&((struct Obj05308 *)p)->f10);
    func_021F3BF0(*(u8 * *)&((struct Obj05308 *)p)->fC);
    func_021F3AE0(p);
    func_02030EAC(((struct Obj05308 *)p)->f4);
    if (((struct Obj22509 *)(*(u8 * *)&((struct Obj05308 *)p)->f8))->f4==1) func_02034A5C((int)ov_abs_84);
    if (flag==0) {
        func_020307B0(((struct Obj22510 *)(*(u8 * *)&((struct Obj05308 *)p)->f8))->f8);
        func_020307B0(((struct Obj05308 *)p)->f8);
        func_02034A5C((int)ov_abs_84);
    }
    func_020315D4(owner);
    func_020306F0(74);
    return 1;
}

int func_021F3A08(int a,int b,int c,u8 *p)
{
    func_021F3C50(*(u8 * *)&((struct Obj08020 *)p)->fC);
    func_021F4350(((struct Obj08020 *)p)->f10);
    func_0204A600();
    if(func_021F44E8(((struct Obj08020 *)p)->f10)==1) {
        func_0202208C(0,0,0,0,6,1,((struct Obj08020 *)p)->f0);
        return 1;
    }
    return 0;
}

/*
 * follower: tail stub at 0x021F3A4C; function_starts seed.
 */
void func_021F3A4C(void) { func_0204A648(); }

/*
 * volatile: hardware read-modify-writes at 0x021F3A64, 0x021F3A6E,
 *   0x021F3A94 (0x04000000, 0x04001000, 0x04000304).
 */
void func_021F3A54(u8 *p)
{
    func_020434CC();
    func_02043588();
    *(volatile unsigned *)0x04000000 &= 0xffffe0ff;
    *(volatile unsigned *)0x04001000 &= 0xffffe0ff;
    func_0202223C(0,0);
    func_0202223C(1,0);
    func_02022224(0);
    func_02022224((void *)1);
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_020433E0((const struct DispVram *)d_021F816C);
    func_0203F8F4(((struct Obj10296 *)p)->f0);
    func_02045088(((struct Obj10296 *)p)->f0);
    func_0203FC28((struct DispConfig *)d_021F815C);
    func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021F816C,((struct Obj10296 *)p)->f0);
    func_020434DC(16,1);
}

void func_021F3AE0(void *a0) { func_0204A5AC(); func_020450C8(); func_0203F9B4(); }

u8 *func_021F3AF0(u8 *src, u16 heap)
{
    u8 i;
    u8 *o;
    u8 j;
    o = func_02030734(heap, 100, 1, d_021F8380, 0x85);
    *(u16 *)o = heap;
    *(u8 **)(o + 4) = src;
    for (i = 0; i < 4; i++) {
        u32 off = i * 0x58;
        u8 *row;
        *(u32 *)(o + i * 4 + 8) = (u32)func_021F67E0(*(u16 *)(src + off + 4), (u8)((struct BF *)(src + 6 + off))->a, (u8)((struct BF *)(src + 6 + off))->b, (u8)((struct BF *)(src + 6 + off))->c, *(u32 *)(src + off + 8), heap);
        row = (u8 *)((u32)src + off);
        for (j = 0; j < 8; j++) {
            u8 k = row[j * 8 + 0x20];
            if (k != 10) {
                *(u16 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x14) = *(u16 *)(row + j * 8 + 0x1c);
                *(s16 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x16) = *(s16 *)(row + j * 8 + 0x1e);
                *(u8 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x18) = j;
            }
        }
    }
    func_021F3CA4((char *)o);
    func_021F3F00(o);
    func_021F40F4(o);
    *(void **)(o + 0x28) = func_021F6F24(*(u16 *)o, 0);
    func_021F6FB0(*(void **)(o + 0x28), (u8)((struct F5 *)*(u8 **)(o + 4))->v);
    func_021F75DC(*(void **)(o + 0x2c), 0x80);
    func_021F7098(*(void **)(o + 0x28), 0x80);
    return o;
}
