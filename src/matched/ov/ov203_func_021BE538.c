/*
 * function: func_021BE538
 * address: 0x021BE538
 * packet: pkt_ov203_021BE538
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P10 lane Y9: closed from the 54 B DIFF draft. (1) the ternary argument is written as a call in each if/else arm (the shared bl is cross-jumped back; this alone fixed ctx/frames colours and the events load before the branch, 54 to 13 B); (2) `long advance` (long colours apart from int, docs/idioms/a-long-index-colours-apart-from-an-int.md) fixed the advance/i swap, 13 to 4 B; (3) `unsigned long time` fixed the last two spill slots (time sp+8, obj sp+4). Callee types checked against matched definitions (func_0201160C u32, func_020115C0 u32, sub_02048A18 u32, func_02047910 int, func_021BF858 void). No constant locals. EXACT in c99 and c.
 * symbols:
 *   func_0201160C 0x0201160C thumb
 *   func_021BF858 0x021BF858 thumb
 *   func_020115C0 0x020115C0 thumb
 *   func_02011B8C 0x02011B8C thumb
 *   sub_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_02047910 0x02047910 arm
 *   func_021BE508 0x021BE508 thumb
 *   func_02048AD0 0x02048AD0 arm
 *   func_021BDF18 0x021BDF18 thumb
 *   func_02047A60 0x02047A60 arm
 *   func_021BDF24 0x021BDF24 thumb
 *   func_0204EA4C 0x0204EA4C arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct IcaAnime;
struct Light;
struct Arg;
struct Context { void *a0; u32 a4,a8,ac,a10,step; struct IcaAnime *anime; u8 *table; void *light; u32 a24,a28,count; u8 args[0x3c]; void *events; u16 *indices; void *a74; };
extern u32 func_0201160C(void *);
extern void func_021BF858(void *,int,int);
extern u32 func_020115C0(struct IcaAnime *,int);
extern void func_02011B8C(void *,void *);
extern u32 sub_02048A18(u8 *,int);
extern int func_0204779C(int *);
extern int func_02047910(void *,int,int);
extern void func_021BE508(const struct Context *,void *);
extern void func_02048AD0(struct Light *);
extern void func_021BDF18(void *);
extern void func_02047A60(void *,struct Arg *);
extern void func_021BDF24(void *);
extern void func_0204EA4C(void);
u32 func_021BE538(const struct Context *ctx,u32 frames)
{
    u32 done;
    long advance = 0;
    unsigned long time = func_0201160C(ctx->anime);
    u32 i;
    for(i=0;i<frames+1;i++) {
        if(ctx->a8 == 0) func_021BF858(ctx->events,time+advance,i);
        else func_021BF858(ctx->events,-4096,i);
        advance += ctx->step;
    }
    done = func_020115C0(ctx->anime,advance);
    func_02011B8C(ctx->light,ctx->anime);
    for(i=0;i<ctx->count;i++) {
        void *obj=(void *)sub_02048A18(ctx->table,ctx->indices[i]);
        int j, count=func_0204779C(obj);
        for(j=0;j<count;j++) func_02047910(obj,(u16)j,advance);
    }
    if(ctx->a10 != 0) func_021BE508(ctx,ctx->light);
    func_02048AD0(ctx->light);
    func_021BDF18(ctx->a0);
    for(i=0;i<ctx->count;i++) {
        func_02047A60((void *)sub_02048A18(ctx->table,ctx->indices[i]),(struct Arg *)ctx->args);
    }
    func_021BDF24(ctx->a0);
    if(ctx->a10 != 0) func_0204EA4C();
    return done;
}
