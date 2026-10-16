/*
 * function: P_STA_SUB_Refresh
 * address: 0x021D6A38
 * packet: pkt_ov131_021D6A38
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: block-local Vec zero initializers materialize addresses before
 *   stores; explicit visibility if/else calls retain original branch shape;
 *   mask update before i++ retains the original loop scheduling.
 * output: 49F34/49DB4 call 4A1BC, whose returned allocation is nonzero:
 *   30734 null failure calls 88234 -> 882C0 -> 882C8 halt loop (882CC
 *   branches back). Both 62A98 and 62A4C assign *out on every returning
 *   path, including absent block. No output default or success assumption.
 * interface: 785C receives the visibly loaded third mon word even though
 *   its own body ignores it. 4ADEC's fourth legacy parameter is overwritten
 *   before use, original sets only r0-r2; 276C4 reads only r0 and replaces
 *   r1-r3 before each call, so unused legacy trailing inputs are omitted.
 * arithmetic: local u8 i=0..5 and mask truncates modulo256; all vectors
 *   assigned from three-word ROM templates or all three explicit zeros.
 * symbols:
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_GetPokeParaSource 0x021D60A4 thumb ov131
 *   P_STA_SUB_CreateMcss 0x021D785C thumb ov131
 *   P_STA_SUB_ApplyMcssOffset 0x021D7A1C thumb ov131
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   ARC_UTIL_LoadBgCharDataFromArchive 0x02049DB4 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   d_021DC204 0x021DC204 data a4
 *   d_021DC21C 0x021DC21C data a4
 *   d_021DC1B0 0x021DC1B0 data a4
 *   d_021DC1A4 0x021DC1A4 data a4
 *   d_021DC18C 0x021DC18C data a4
 *   d_021DC1BC 0x021DC1BC data a4
 *   MCSS_SetOfsPosition  0x02015C78  thumb  arm9
 *   MCSS_SetOfsScale  0x02015D30  thumb  arm9
 *   POKE_TOOL_IsBoxShiny  0x02017EB4  thumb  arm9
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb  arm9
 *   POKERUS_IsBoxInfected  0x0201B268  thumb  arm9
 *   POKERUS_IsBoxCured  0x0201B28C  thumb  arm9
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 *   APP_ICON_GetStatusIconAnim  0x020276C4  thumb  arm9
 *   APP_ICON_GetBallThrowCellFileId  0x02027720  thumb  arm9
 *   APP_ICON_GetBallThrowAnimFileId  0x0202772C  thumb  arm9
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */
#include "../include/Obj00112.h"
#include "../include/Obj00472.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 x,y,z;} Vec;
extern const Vec d_021DC204,d_021DC21C,d_021DC1B0,d_021DC1A4,d_021DC18C,d_021DC1BC;
extern void *P_STATUS_GetPokePara(u8 *);
extern int P_STATUS_GetPokeParaSource(char *p);
struct Cfg;
struct Descriptor;
struct Light;
struct Obj;
struct Sub0204A9D0;
extern void P_STA_SUB_CreateMcss(u8 *p, u8 *q, void *mon);
extern void P_STA_SUB_ApplyMcssOffset(void *,void *,Vec *);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u32 POKE_TOOL_GetBoxValue(void *,u32,u32);
extern u32 APP_ICON_GetArchiveId(void);
extern int APP_ICON_GetBallThrowCellFileId(int);
extern int APP_ICON_GetBallThrowAnimFileId(int);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32,u32,u32,u32);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32,u32,u32,u32,u16);
extern void CLACT_TransferPalette(u32,void *,u32);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 POKERUS_IsBoxCured(void *);
extern u32 POKE_TOOL_IsBoxShiny(void *);
extern u32 POKE_TOOL_GetStatusCondition(void *);
extern int APP_ICON_GetStatusIconAnim(int a0);
extern u32 POKERUS_IsBoxInfected(void *);
extern void MCSS_SetOfsPosition(void *,u32 *);
extern void MCSS_SetOfsScale(void *,u32 *);
extern void G3D_CAMERA_SetEye(void *,const Vec *);
extern void G3D_CAMERA_Reset(struct Light *l);
void P_STA_SUB_Refresh(u8 *p,u8 *q)
{
    void *pal,*chr;
    void *mon,*other,*window,*loaded;
    u32 form,archive,status;
    u8 i,mask;
    mon=P_STATUS_GetPokePara(p);
    other=(void *)P_STATUS_GetPokeParaSource((char *)p);
    P_STA_SUB_CreateMcss(p,q,mon);
    window=((struct Obj00472 *)q)->f18;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
    window=((struct Obj00472 *)q)->f1C;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
    form=POKE_TOOL_GetBoxValue(mon,0x98,0);
    archive=APP_ICON_GetArchiveId();
    loaded=ARC_UTIL_LoadPaletteBlockFromArchive(archive,APP_ICON_GetBallThrowCellFileId(form),(u32)&pal,((struct Obj00112 *)p)->f0);
    CLACT_TransferPalette(((struct Obj00112 *)p)->f9C,pal,1);
    func_020307B0(loaded);
    archive=APP_ICON_GetArchiveId();
    loaded=ARC_UTIL_LoadBgCharDataFromArchive(archive,APP_ICON_GetBallThrowAnimFileId(form),0,(u32)&chr,((struct Obj00112 *)p)->f0);
    CLACT_TransferCharacter(((struct Obj00112 *)p)->fD0,chr);
    func_020307B0(loaded);
    CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f20,1);
    status=POKE_TOOL_GetBoxValue(mon,11,0);
    for(i=0,mask=1;i<6;mask=(u8)(mask<<1),i++) {
        if(status & mask) CLACT_SetActorAnimSeq(*(void **)(q+0x24+i*4),i*2+1);
        else CLACT_SetActorAnimSeq(*(void **)(q+0x24+i*4),i*2);
    }
    if(POKERUS_IsBoxCured(mon)==1) CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f40,1);
    else CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f40,0);
    if(POKE_TOOL_IsBoxShiny(mon)==1 && ((struct Obj00112 *)p)->f38==0)
        CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f3C,1);
    else CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f3C,0);
    if(((struct Obj00472 *)q)->fC==1) {
        Vec a=d_021DC204;
        Vec b=d_021DC21C;
        Vec c={0,0,0};
        Vec d=d_021DC1B0;
        MCSS_SetOfsPosition(((struct Obj00472 *)q)->f0,&c.x);
        P_STA_SUB_ApplyMcssOffset(p,q,&d);
        MCSS_SetOfsScale(((struct Obj00472 *)q)->f0,&b.x);
        G3D_CAMERA_SetEye(((struct Obj00112 *)p)->f70,&a);
        G3D_CAMERA_Reset(((struct Obj00112 *)p)->f70);
        ((struct Obj00472 *)q)->f8=0;
    } else {
        Vec e=d_021DC1A4;
        Vec f=d_021DC18C;
        Vec g={0,0,0};
        Vec h=d_021DC1BC;
        MCSS_SetOfsPosition(((struct Obj00472 *)q)->f0,&g.x);
        P_STA_SUB_ApplyMcssOffset(p,q,&h);
        MCSS_SetOfsScale(((struct Obj00472 *)q)->f4,&f.x);
        G3D_CAMERA_SetEye(((struct Obj00112 *)p)->f70,&e);
        G3D_CAMERA_Reset(((struct Obj00112 *)p)->f70);
        ((struct Obj00472 *)q)->f8=2;
    }
    if((u8)POKE_TOOL_GetStatusCondition(other)!=0) {
        CLACT_SetActorAnimSeq(((struct Obj00472 *)q)->f48,APP_ICON_GetStatusIconAnim((int)other));
        CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f48,1);
        CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f44,0);
    } else {
        CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f48,0);
        if(POKERUS_IsBoxInfected(mon)==1) CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f44,1);
        else CLACT_SetActorDrawEnable(((struct Obj00472 *)q)->f44,0);
    }
    {
    Vec zero={0,0,0};
    MCSS_SetOfsPosition(((struct Obj00472 *)q)->f0,&zero.x);
    MCSS_SetOfsPosition(((struct Obj00472 *)q)->f4,&zero.x);
    q[0x78]=0;q[0x79]=0;q[0x80]=0;q[0x81]=0;
    ((struct Obj00472 *)q)->f6C=0;((struct Obj00472 *)q)->f5C=0;
    q[0x88]=0;q[0x89]=0;
    }
}
