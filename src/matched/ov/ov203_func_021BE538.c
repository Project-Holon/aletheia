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
 * note: 2026-10-05 wave P10 lane Y9: closed from the 54 B DIFF draft. (1) the ternary argument is written as a call in each if/else arm (the shared bl is cross-jumped back; this alone fixed ctx/frames colours and the events load before the branch, 54 to 13 B); (2) `long advance` (long colours apart from int, docs/idioms/a-long-index-colours-apart-from-an-int.md) fixed the advance/i swap, 13 to 4 B; (3) `unsigned long time` fixed the last two spill slots (time sp+8, obj sp+4). Callee types checked against matched definitions (ICA_ANIME_GetFrame u32, ICA_ANIME_IncFrameNoLoop u32, G3D_UTIL_GetObject u32, G3D_SYSTEM_LoopObjectAnimeFrame int, DEMO3D_CMDSYS_Update void). No constant locals. EXACT in c99 and c.
 * symbols:
 *   ICA_ANIME_GetFrame 0x0201160C thumb
 *   DEMO3D_CMDSYS_Update 0x021BF858 thumb
 *   ICA_ANIME_IncFrameNoLoop 0x020115C0 thumb
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   func_021BE508 0x021BE508 thumb
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   func_021BDF18 0x021BDF18 thumb
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   func_021BDF24 0x021BDF24 thumb
 *   DOUBLE3DDISP_SetDrawDone 0x0204EA4C arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct IcaAnime;
struct Light;
struct Arg;
struct Context { void *a0; u32 a4,a8,ac,a10,step; struct IcaAnime *anime; u8 *table; void *light; u32 a24,a28,count; u8 args[0x3c]; void *events; u16 *indices; void *a74; };
struct Obj11245;
extern u32 ICA_ANIME_GetFrame(struct Obj11245 *p);
extern void DEMO3D_CMDSYS_Update(void *,int,int);
extern u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *,int);
extern void ICA_ANIME_SetCameraStatus(void *,void *);
extern u32 G3D_UTIL_GetObject(u8 *,int);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *,int,int);
extern void func_021BE508(char *p, struct Light *q);
extern void G3D_CAMERA_Reset(struct Light *);
extern void func_021BDF18(char *p);
extern void G3D_SYSTEM_DrawObject(void *,struct Arg *);
extern void func_021BDF24(char *p);
extern void DOUBLE3DDISP_SetDrawDone(void);
int func_021BE538(const struct Context *ctx, u32 frames)
{
    u32 done;
    long advance = 0;
    unsigned long time = ICA_ANIME_GetFrame((struct Obj11245 *)ctx->anime);
    u32 i;
    for(i=0;i<frames+1;i++) {
        if(ctx->a8 == 0) DEMO3D_CMDSYS_Update(ctx->events,time+advance,i);
        else DEMO3D_CMDSYS_Update(ctx->events,-4096,i);
        advance += ctx->step;
    }
    done = ICA_ANIME_IncFrameNoLoop(ctx->anime,advance);
    ICA_ANIME_SetCameraStatus(ctx->light,ctx->anime);
    for(i=0;i<ctx->count;i++) {
        void *obj=(void *)G3D_UTIL_GetObject(ctx->table,ctx->indices[i]);
        int j, count=G3D_SYSTEM_GetObjectAnimeCount(obj);
        for(j=0;j<count;j++) G3D_SYSTEM_LoopObjectAnimeFrame(obj,(u16)j,advance);
    }
    if(ctx->a10 != 0) func_021BE508((char *)ctx,ctx->light);
    G3D_CAMERA_Reset(ctx->light);
    func_021BDF18(ctx->a0);
    for(i=0;i<ctx->count;i++) {
        G3D_SYSTEM_DrawObject((void *)G3D_UTIL_GetObject(ctx->table,ctx->indices[i]),(struct Arg *)ctx->args);
    }
    func_021BDF24(ctx->a0);
    if(ctx->a10 != 0) DOUBLE3DDISP_SetDrawDone();
    return done;
}
