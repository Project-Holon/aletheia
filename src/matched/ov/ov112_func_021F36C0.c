/*
 * function: func_021F36C0
 * address: 0x021F36C0
 * packet: pkt_ov112_021F36C0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: retry rederived allocator, RTC, callback and final seven-argument call signatures; prior permuter 300 retained.
 * match: unsigned 88U*i and signed 88*i keep both row computations; a block slot pointer fixes the inner loop colouring; u32 allocation length fixes the final instruction schedule.
 * ABI: 3159C stores the allocation but leaves r0 live, used here as the State pointer. RTC copies four words.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0203630C 0x0203630C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F3A4C 0x021F3A4C thumb ov112
 *   func_021F3A54 0x021F3A54 thumb ov112
 *   func_021F3AF0 0x021F3AF0 thumb ov112
 *   func_021F4284 0x021F4284 thumb ov112
 *   func_0202208C 0x0202208C thumb
 *   ov132_id 0x84 data
 *   d_021F836C 0x021F836C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 a:5,b:4,c:7,d:5,e:6,f:5;} Settings;
typedef struct {u32 x,y,z,week;} Options;
typedef struct {u32 a,b;u8 *config;u32 c,d;} Save;
typedef struct {u16 heap,pad;void *task;Save *save;void *scene,*actors;} State;
typedef enum {ConfigSize=432} AllocSize;
extern void func_0203064C(u32,u32,u32);
extern State *func_0203159C(void *,u32,u32);
extern int func_02034AC4(int);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_0203F4E4(Options *);
extern u16 func_02045A98(void);
extern u32 func_0203630C(void);
extern void *func_020056A0(u32,u32,u32);
extern void func_021F3A4C(void *,State *),func_021F3A54(u8 *);
extern void *func_021F3AF0(u8 *,u16),*func_021F4284(u8 *,u32,u32,u32,u16);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern char ov132_id[];
extern const char d_021F836C[];
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
  func_0203F4E4(&options);
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
  *(u16 *)(cfg+4)=643;*(u16 *)(cfg+0x5C)=643;*(u16 *)(cfg+0xB4)=643;*(u16 *)(cfg+0x10C)=643;
  for(i=0;i<4;i++){
   u8 *q;
   q=cfg+88U*i;
   *(u16 *)(q+12)=0x30C8;*(u16 *)(q+14)=0x30EC;*(u16 *)(q+16)=0x30FC;*(u16 *)(q+18)=0x30CA;*(u16 *)(q+20)=0xFF11+i;*(u16 *)(q+22)=0;
   for(j=0;j<8;j++){u8 *slot;slot=q+8*j;*(u16 *)(slot+28)=255;*(u16 *)(slot+30)=0;*(u8 *)(slot+32)=10;}
   q=cfg+88*i;
   *(u16 *)(q+28)=11;*(u16 *)(q+30)=0;q[32]=7;
   *(u16 *)(q+36)=11;*(u16 *)(q+38)=0;q[40]=8;
   *(u16 *)(q+44)=11;*(u16 *)(q+46)=0;q[48]=6;
   *(u16 *)(q+52)=11;*(u16 *)(q+54)=0;q[56]=4;
   *(u16 *)(q+60)=11;*(u16 *)(q+62)=0;q[64]=2;
   *(u16 *)(q+68)=11;*(u16 *)(q+70)=0;q[72]=1;
   *(u16 *)(q+76)=11;*(u16 *)(q+78)=0;q[80]=0;
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
