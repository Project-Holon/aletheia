/*
 * function: func_021FC380
 * address: 0x021FC380
 * packet: pkt_ov132_021FC380
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F9DD4 0x021F9DD4 thumb ov132
 *   func_021F9DDC 0x021F9DDC thumb ov132
 *   func_021F9DA0 0x021F9DA0 thumb ov132
 *   func_021F9DA4 0x021F9DA4 thumb ov132
 *   func_021F9DF4 0x021F9DF4 thumb ov132
 *   func_021F8044 0x021F8044 thumb ov112
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_02030734 0x02030734 arm
 *   func_021FADA0 0x021FADA0 thumb ov132
 *   func_021FC490 0x021FC490 thumb ov132
 *   d_021FDD00 0x021FDD00 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x,y,z; } Vec;
extern u32 func_0201134C(void *);
extern int func_021FB1F4(char *,int);
extern void *func_021F9DD4(void *);
extern void *func_021F9DDC(void *,u8);
extern void *func_021F9DA0(void *);
extern void *func_021F9DA4(void *,int);
extern void func_021F9DF4(void *);
extern void func_021F8044(void *,void *,Vec *);
extern void func_021F6EF4(void *,void *,const Vec *);
extern void func_0207C9D0(const Vec *,const Vec *,Vec *);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void *func_021FADA0(char *,u32,u32,u32);
extern void func_021FC490(int,char *);
extern const char d_021FDD00[];
int func_021FC380(int unused,char *p)
{
 char *owner,*q;
 Vec pos,delta;
 u16 duration;
 u32 f,e,d,b,c,a;
 void *ctx,*target,*scene,*obj;
 u8 i;
 owner=*(char **)p;
 a=func_0201134C(*(void **)(p+4));
 b=func_021FB1F4(p,func_0201134C(*(void **)(p+4)));
 c=func_0201134C(*(void **)(p+4));
 d=func_0201134C(*(void **)(p+4));
 e=func_0201134C(*(void **)(p+4));
 f=func_0201134C(*(void **)(p+4));
 ctx=func_021F9DD4(*(void **)(owner+0x34));
 target=func_021F9DDC(*(void **)(owner+0x34),a);
 scene=func_021F9DA0(*(void **)(owner+0x34));
 duration=c;
 for(i=0;i<4;i++) {
  obj=func_021F9DA4(*(void **)(owner+0x34),i);
  if(b&(1<<i)) {
   if(c==0) {
    func_021F8044(scene,obj,&pos);
    delta.x=d;delta.y=e;delta.z=f;
    func_0207C9D0(&pos,&delta,&pos);
    func_021F6EF4(ctx,target,&pos);
   } else {
    func_021F9DF4(*(void **)(owner+0x34));
    q=func_02030734(*(u16 *)owner,0x30,0,d_021FDD00,0x74D);
    *(char **)(q+0x28)=owner;
    *(u8 *)q=i;
    *(void **)(q+4)=target;
    *(void **)(q+8)=*(void **)(owner+0x34);
    *(void **)(q+0xC)=obj;
    *(u16 *)(q+0x1E)=0;
    *(u32 *)(q+0x10)=d;*(u32 *)(q+0x14)=e;*(u32 *)(q+0x18)=f;
    *(u16 *)(q+0x1C)=duration;
    *(void **)(q+0x2C)=func_021FADA0(owner,(u32)func_021FC490,(u32)q,7);
   }
  }
 }
 return 0;
}
