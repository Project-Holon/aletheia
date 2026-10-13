/*
 * function: P_STATUS_CreateButtonActors
 * address: 0x021D4FBC
 * packet: pkt_ov131_021D4FBC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: real far bank/actor struct fields retain four offset spills.
 * interface: owner 0204B294 legacy void prototype tail-forwards allocator
 *   0204CFDC, whose full body returns an object pointer; caller consumes r0.
 *   All seven arguments preserve owner's full-word ids and u16 stack args.
 *   Descriptor x/y/z/kind/flag all initialize before any consumer call.
 *   Byte tables are consecutive records at witnessed base 021DBFA0.
 * symbols:
 *   g_BFA0 0x021DBFA0 data ov131
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   P_STATUS_CanUseButtons 0x021D62E4 thumb ov131
 *   P_STA_SUB_CreateObjects 0x021D6810 thumb ov131
 *   P_STA_RIBBON_CreateObjects 0x021D8938 thumb ov131
 *   P_STA_SKILL_CreateObjects 0x021D9A4C thumb ov131
 */
#include "../include/Obj00591.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bytes { u8 v[8]; };
struct Desc {u16 x,y,z;u8 kind,flag;};
struct Context {u8 prefix[0x100];u8 rest[0x74];void *bank;void *actors[8];};
extern struct Bytes g_BFA0[3];
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int P_STATUS_CanUseButtons(char *);
extern void P_STA_SUB_CreateObjects(u8 *a, u8 *p);
extern void P_STA_RIBBON_CreateObjects(u8 *a, u8 *p);
extern void P_STA_SKILL_CreateObjects(u8 *a, u8 *p);
void P_STATUS_CreateButtonActors(struct Context *ctx)
{
    char *p=(char *)ctx;
    struct Bytes z=g_BFA0[2];
    struct Bytes x=g_BFA0[0];
    struct Desc d;
    u8 i,j;
    u32 a,b;
    d.kind=10;d.flag=0;
    for(i=0;i<8;i++){
        if(i<=2){a=((struct Obj00591 *)p)->fC8;b=((struct Obj00591 *)p)->fFC;}
        else{a=((struct Obj00591 *)p)->fCC;b=((struct Obj00591 *)p)->f100;}
        d.x=x.v[i];d.y=(i==3)?172:168;d.z=z.v[i];
        ctx->actors[i]=CLACT_CreateActor(ctx->bank,a,((struct Obj00591 *)p)->f98,b,&d,0,((struct Obj00591 *)p)->f0);
        func_0204B92C(ctx->actors[i],1);
        func_0204B3DC(ctx->actors[i],1);
    }
    d.x=0;d.y=0;d.z=0;
    ((struct Obj00591 *)p)->f198=CLACT_CreateActor((void *)*(u32 *)&((struct Obj00591 *)p)->f174,((struct Obj00591 *)p)->f130,((struct Obj00591 *)p)->fA4,((struct Obj00591 *)p)->f10C,&d,0,((struct Obj00591 *)p)->f0);
    ((struct Obj00591 *)p)->f19C=CLACT_CreateActor((void *)*(u32 *)&((struct Obj00591 *)p)->f174,((struct Obj00591 *)p)->f130,((struct Obj00591 *)p)->fA4,((struct Obj00591 *)p)->f10C,&d,0,((struct Obj00591 *)p)->f0);
    for(j=0;j<2;j++)func_0204B3DC(*(void **)(p+0x198+j*4),0);
    if((*(u8 **)(p+8))[13]==2)for(i=0;i<8;i++)if(i!=7)func_0204B3DC(*(void **)(p+0x178+i*4),0);
    if(P_STATUS_CanUseButtons(p)==0){func_0204B3DC(((struct Obj00591 *)p)->f190,0);func_0204B3DC(((struct Obj00591 *)p)->f184,0);}
    P_STA_SUB_CreateObjects((u8 *)p,((struct Obj00591 *)p)->f88);
    P_STA_RIBBON_CreateObjects((u8 *)p,((struct Obj00591 *)p)->f94);
    P_STA_SKILL_CreateObjects((u8 *)p,((struct Obj00591 *)p)->f90);
}
