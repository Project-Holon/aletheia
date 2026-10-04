/*
 * function: func_021D4FBC
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
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D62E4 0x021D62E4 thumb ov131
 *   func_021D6810 0x021D6810 thumb ov131
 *   func_021D8938 0x021D8938 thumb ov131
 *   func_021D9A4C 0x021D9A4C thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bytes { u8 v[8]; };
struct Desc {u16 x,y,z;u8 kind,flag;};
struct Context {u8 prefix[0x100];u8 rest[0x74];void *bank;void *actors[8];};
extern struct Bytes g_BFA0[3];
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_021D62E4(char *);
extern void func_021D6810(void *,void *);
extern void func_021D8938(void *,void *);
extern void func_021D9A4C(void *,void *);
void func_021D4FBC(struct Context *ctx)
{
    char *p=(char *)ctx;
    struct Bytes z=g_BFA0[2];
    struct Bytes x=g_BFA0[0];
    struct Desc d;
    u8 i,j;
    u32 a,b;
    d.kind=10;d.flag=0;
    for(i=0;i<8;i++){
        if(i<=2){a=*(u32 *)(p+0xc8);b=*(u32 *)(p+0xfc);}
        else{a=*(u32 *)(p+0xcc);b=*(u32 *)(p+0x100);}
        d.x=x.v[i];d.y=(i==3)?172:168;d.z=z.v[i];
        ctx->actors[i]=func_0204B294(ctx->bank,a,*(u32 *)(p+0x98),b,&d,0,*(u16 *)p);
        func_0204B92C(ctx->actors[i],1);
        func_0204B3DC(ctx->actors[i],1);
    }
    d.x=0;d.y=0;d.z=0;
    *(void **)(p+0x198)=func_0204B294((void *)*(u32 *)(p+0x174),*(u32 *)(p+0x130),*(u32 *)(p+0xa4),*(u32 *)(p+0x10c),&d,0,*(u16 *)p);
    *(void **)(p+0x19c)=func_0204B294((void *)*(u32 *)(p+0x174),*(u32 *)(p+0x130),*(u32 *)(p+0xa4),*(u32 *)(p+0x10c),&d,0,*(u16 *)p);
    for(j=0;j<2;j++)func_0204B3DC(*(void **)(p+0x198+j*4),0);
    if((*(u8 **)(p+8))[13]==2)for(i=0;i<8;i++)if(i!=7)func_0204B3DC(*(void **)(p+0x178+i*4),0);
    if(func_021D62E4(p)==0){func_0204B3DC(*(void **)(p+0x190),0);func_0204B3DC(*(void **)(p+0x184),0);}
    func_021D6810(p,*(void **)(p+0x88));
    func_021D8938(p,*(void **)(p+0x94));
    func_021D9A4C(p,*(void **)(p+0x90));
}
