/*
 * file:     mystery_album.c
 * unit:     yes
 * function: MYSTERY_ALBUM_Delete, MYSTERY_ALBUM_StepIntro, MYSTERY_ALBUM_SetBlendMain, MYSTERY_ALBUM_SetBlendSub, MYSTERY_ALBUM_LoadBgWithTilemap, MYSTERY_ALBUM_LoadBgPalette, MYSTERY_ALBUM_SetupIcons, MYSTERY_ALBUM_StartIntro, MYSTERY_ALBUM_ResetIntro, MYSTERY_ALBUM_IsIntroIdle, MYSTERY_ALBUM_SetupTask, MYSTERY_ALBUM_RequestSetup, MYSTERY_ALBUM_HideScreen, MYSTERY_ALBUM_PathAnimInit, MYSTERY_ALBUM_PathAnimStep
 * address:  0x021DD980
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from mystery_net.c at 0x021DE2A0 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021DA3C0 0x021DA3C0 thumb ov121
 *   func_021DBEE4 0x021DBEE4 thumb ov121
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   func_021DAB50 0x021DAB50 thumb ov121
 *   PM_VOICE_Play 0x02006984 thumb
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_GetActorRotation 0x0204B5FC arm
 *   MYSTERY_ALBUM_PathAnimInit 0x021DE128 thumb ov121
 *   MYSTERY_ALBUM_PathAnimStep 0x021DE154 thumb ov121
 *   func_0204B404 0x0204B404 arm
 *   func_02006BD0 0x02006BD0 thumb
 *   MYSTERY_ALBUM_SetBlendMain 0x021DDC30 arm ov121
 *   MYSTERY_ALBUM_SetBlendSub 0x021DDC44 arm ov121
 *   func_021DC064 0x021DC064 thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_021DBF10 0x021DBF10 thumb ov121
 *   func_021DBF40 0x021DBF40 thumb ov121
 *   func_021DBF9C 0x021DBF9C thumb ov121
 *   func_021DBF70 0x021DBF70 thumb ov121
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_02049E74 0x02049E74 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   func_02082A48 0x02082A48 arm
 *   CLACT_SetActorRotation 0x0204B5F4 arm
 *   CLACT_GetPaletteVramAddress 0x0204AEF4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_02082A60 0x02082A60 arm
 *   func_021DA4A8 0x021DA4A8 thumb ov121
 *   func_021DA318 0x021DA318 thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_020414EC 0x020414EC arm
 *   func_02082BCC 0x02082BCC arm
 *   MYSTERY_ALBUM_PathFrameIds 0x021DF858 data a2
 *   MYSTERY_ALBUM_PathDirections 0x021DF822 data a1
 *   MYSTERY_ALBUM_PathDurations 0x021DF82D data a1
 *   MYSTERY_ALBUM_PathWaypoints 0x021DF944 data a4
 *   _s32_div_f 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 */

#include "mystery_album_types.h"

struct Node;
struct Actor;
struct PtS;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short s16;

typedef signed char s8;



typedef struct { s16 frameId,x,y; } MysteryAlbumPathOut;



extern void func_02030EAC(struct Node *task);
extern unsigned int func_020307B0(void *mem);
extern void func_021DA3C0(void *cardView);
extern void func_021DBEE4(u32 album);
extern void CLACT_SetActorBgPriority(void *actor,u8 animId);
extern void func_021DAB50(void *fadeLayer, u16 *out, u16 angle, int bank, const u16 *from, const u16 *to);
extern u32 PM_VOICE_Play(u32 soundId,u32 playerId,u32 volume,u32,u32,u32,u32,u32);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern u16 CLACT_GetActorRotation(const struct Actor *actor);
extern void MYSTERY_ALBUM_PathAnimInit(MysteryAlbumPathAnim *anim, u16 frameId, int x, int y);
extern void func_0204B404(void *actor,const MysteryAlbumPoint16 *pos,u16 space);
extern u32 func_02006BD0(u32 soundHandle);
#pragma thumb off
extern void MYSTERY_ALBUM_SetBlendMain(int eva,int evb);
extern void MYSTERY_ALBUM_SetBlendSub(int eva,int evb);
#pragma thumb on
void MYSTERY_ALBUM_Delete(MysteryAlbum *album);
void MYSTERY_ALBUM_StepIntro(MysteryAlbum *album);

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_ALBUM_Delete(MysteryAlbum *album)
{
    if (album->setupTask) {
        func_02030EAC(album->setupTask);
        album->setupTask=0;
    }
    if (album->paletteBuffer) func_020307B0(album->paletteBuffer);
    if (album->bgDataBuffer) func_020307B0(album->bgDataBuffer);
    func_021DA3C0(album->cardView);
    func_021DBEE4((u32)album);
    func_020307B0(album);
}

/*
 * verdict: 612-byte lead; the rest of the 652-byte extent is the two ARM
 *   followers 021DDC30 and 021DDC44 (20 bytes each), filed as their own
 *   ARM leaves (pkt_ov121_021DDC30, pkt_ov121_021DDC44, W82 R11), which
 *   also resolve the ABS32 blend callbacks at +0x258/+0x25C.
 * lever: case 5 seeds the result flag with its own constant and ANDs the
 *   call in (done = 1; done &= f(...)); "f(...) & 1" or "1 & f(...)" CSEs
 *   the 1 with ok's r6 (11 bytes).
 */
void MYSTERY_ALBUM_StepIntro(MysteryAlbum *album)
{
    MysteryAlbumUi *ui=album->ui;
    int fadeLayer,blendEva,blendEvb,done,soundDone;
    u16 tick;
    void (*setBlend)(int,int);
    MysteryAlbumPoint16 cursorStart;
    int position[2];
    MysteryAlbumPathOut pathOut;
    if(ui->isMainScreen) { fadeLayer=14; setBlend=MYSTERY_ALBUM_SetBlendMain; }
    else { setBlend=MYSTERY_ALBUM_SetBlendSub; fadeLayer=30; }
    switch(album->introPhase) {
    case 1:
        CLACT_SetActorBgPriority(ui->cursorActor,ui->introAnimId);
        album->introPhase=2;
        break;
    case 2:
        func_021DAB50((void *)fadeLayer,ui->palFade,(album->introTick*0x7fff)/60,(u8)(ui->paletteBank),ui->palImage,ui->palBlack);
        tick=album->introTick;
        blendEva=tick*14/60;
        blendEvb=tick*-12/60;
        setBlend(blendEva+2,blendEvb+12);
        if(album->introTick++>60) {
            album->introTick=0;
            album->introPhase=3;
        }
        break;
    case 3: album->introPhase=4; break;
    case 4:
        if(!album->skipSound)
            album->soundHandle=PM_VOICE_Play(album->soundId,album->soundPlayerId,64,0,0,0,0,0);
        CLACT_GetActorSurfacePos(ui->cursorActor,(struct PtS *)(&cursorStart),ui->screenId);
        MYSTERY_ALBUM_PathAnimInit(&album->pathAnim,CLACT_GetActorRotation(ui->cursorActor),cursorStart.x,cursorStart.y);
        album->introPhase=5;
        break;
    case 5:
        soundDone=1;
        done=1;
        done&=MYSTERY_ALBUM_PathAnimStep(&album->pathAnim,&pathOut,position);
        pathOut.x=position[0];
        pathOut.y=position[1];
        func_0204B404(ui->cursorActor,(MysteryAlbumPoint16 *)&pathOut.x,ui->screenId);
        if(!album->skipSound) {
            if(func_02006BD0(album->soundHandle)) soundDone=0;
            done &= soundDone;
        }
        if(done) album->introPhase=6;
        break;
    case 6:
        func_021DAB50((void *)fadeLayer,ui->palFade,0x7fff-(album->introTick*0x7fff)/60,(u8)(ui->paletteBank),ui->palImage,ui->palBlack);
        tick=album->introTick;
        blendEva=tick*-14/60;
        blendEvb=tick*12/60;
        setBlend(blendEva+16,blendEvb);
        if(album->introTick++>60) {
            album->introTick=0;
            album->introPhase=7;
        }
        break;
    case 7: album->introPhase=8; break;
    case 8:
        CLACT_SetActorBgPriority(ui->cursorActor,ui->idleAnimId);
        album->introPhase=0;
        break;
    }
}

#pragma thumb off



void MYSTERY_ALBUM_SetBlendMain(int eva, int evb);
void MYSTERY_ALBUM_SetBlendSub(int eva, int evb);

/*
 * Unlabelled ARM follower of MYSTERY_ALBUM_StepIntro, referenced by its ABS32 pool
 * word at +0x258: main-screen blend callback writing BLDALPHA (0x04000052)
 * as eva | evb << 8.
 */
void MYSTERY_ALBUM_SetBlendMain(int eva, int evb)
{
    *(volatile u16 *)0x04000052 = eva | (evb << 8);
}

void MYSTERY_ALBUM_SetBlendSub(int eva, int evb)
{
    *(volatile u16 *)0x04001052 = eva | (evb << 8);
}

#pragma thumb on

struct Obj;
struct Actor;









extern int func_021DC064(void *album);
extern void *func_020490F4(unsigned int arcId, unsigned int heapId);
extern void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 fileId, u32 bgLayer, u32 offset, u32 palOffset, u32 size, u16 heapId);
extern u32 func_02049658(void *arc, u32 fileId, u32 bgLayer, u32 offset, u32 x, u32 y, u16 heapId);
extern void func_020498F4(void *arc, u32 fileId, u32 bgLayer, u32 offset, u32 x, u32 y, u16 heapId);
extern void func_020413B0(u8 bgLayer, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 bgLayer);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void *func_021DBF10(void *album,u16 heapId);
extern u32 func_021DBF40(void *album);
extern int func_021DBF9C(void *album);
extern u32 func_021DBF70(void *album);
extern int func_021DC024(void *album);
extern void *func_02049F78(void *arc, u32 fileId, u32 res, u32 heapId);
extern void func_02082D44(const void *src,void *dst,int size);
extern u32 func_020307B0(void *mem);
extern void *func_02049E74(void *arc, u32 fileId, u32 compressed, u32 res, u16 heapId);
extern void CLACT_TransferCharacterPart(int,void *,u32,int,int);
extern void func_0204B6F4(struct Obj *actor, u32 animId, u32 flag);
extern void func_0204B3DC(struct Obj *actor, u32 visible);
extern void CLACT_TransferPalette(u32,void *,u32);
extern void func_02082A48(u32 value,void *dst,u32 size);
extern void CLACT_SetActorRotation(struct Actor *actor, u16 frame);
extern int CLACT_GetPaletteVramAddress(u32 paletteHandle, u32 screenId);
extern void func_0207D63C(void *reg,int,int,int,int);
extern void CLACT_SetActorBgPriority(void *actor,u8 animId);
#pragma thumb off
extern void MYSTERY_ALBUM_SetBlendMain(int eva,int evb);
extern void MYSTERY_ALBUM_SetBlendSub(int eva,int evb);
#pragma thumb on
extern void func_02082A60(void *dst,const void *src,int size);
extern void func_021DA4A8(void *cardView);
extern void func_021DA318(void *albumData);
extern void func_02040588(unsigned char plane, unsigned char enable);
extern void *func_020056A0(u32 func,u32 arg,u32 priority);
extern void func_020414EC(unsigned bgLayer);
extern void func_02082BCC(void *dst,int value,u32 size);
extern int _s32_div_f(int, int);
extern u32 _u32_div_f(u32, u32);
void MYSTERY_ALBUM_LoadBgWithTilemap(const MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId);
void MYSTERY_ALBUM_LoadBgPalette(MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId);
void MYSTERY_ALBUM_SetupIcons(MysteryAlbum *album,MysteryAlbumUi *ui,u16 heapId);
void MYSTERY_ALBUM_StartIntro(MysteryAlbum *album);
void MYSTERY_ALBUM_ResetIntro(MysteryAlbum *album);
int MYSTERY_ALBUM_IsIntroIdle(MysteryAlbum *album);
void MYSTERY_ALBUM_SetupTask(void *unused,MysteryAlbum *album);
void MYSTERY_ALBUM_RequestSetup(MysteryAlbum *album,u32 mode);
void MYSTERY_ALBUM_HideScreen(MysteryAlbumUi *ui);
void MYSTERY_ALBUM_PathAnimInit(MysteryAlbumPathAnim *anim,u16 frameId,int x,int y);
int MYSTERY_ALBUM_PathAnimStep(MysteryAlbumPathAnim *anim, u16 *outFrameId, MysteryAlbumPathPoint *outPosition);
extern u16 MYSTERY_ALBUM_PathFrameIds[];
extern const s8 MYSTERY_ALBUM_PathDirections[];
extern s8 MYSTERY_ALBUM_PathDurations[];
extern const MysteryAlbumPathPoint MYSTERY_ALBUM_PathWaypoints[];





/*
 * extent: two bytes of zero alignment padding after the return.
 * lever: initialize resource after the first guard; const source orders loads before stack argument stores.
 */
void MYSTERY_ALBUM_LoadBgWithTilemap(const MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId)
{
    int screenOffset=0;
    int tilemapFile;
    u16 imageId;
    void *arc;
    if (bgSetup->bgLayer>=4) screenOffset=4;
    tilemapFile=26;
    if (bgSetup->bgLayer<=3) tilemapFile=27;
    imageId=func_021DC064(album);
    arc=func_020490F4(34,heapId);
    ARC_UTIL_UploadPaletteFromHandle(arc,4,screenOffset,imageId*32,bgSetup->paletteNumber*32,32,heapId);
    func_02049658(arc,13,bgSetup->bgLayer,0,0,0,heapId);
    func_020498F4(arc,(u16)tilemapFile,bgSetup->bgLayer,0,0,0,heapId);
    func_020413B0((u8)bgSetup->bgLayer,0,0,34,24,bgSetup->paletteNumber);
    func_020409B4((u8)bgSetup->bgLayer);
    ARC_TOOL_DeleteHandle(arc);
}





/*
 * extent: two bytes of zero alignment padding after the return.
 */
void MYSTERY_ALBUM_LoadBgPalette(MysteryAlbumBgSetup *bgSetup,MysteryAlbum *album,u16 heapId)
{
    int screenOffset=0;
    u16 imageId;
    void *arc;
    if (bgSetup->bgLayer>=4) screenOffset=4;
    imageId=func_021DC064(album);
    arc=func_020490F4(34,heapId);
    ARC_UTIL_UploadPaletteFromHandle(arc,4,screenOffset,imageId*32,bgSetup->paletteNumber*32,32,heapId);
    func_020413B0((u8)bgSetup->bgLayer,0,0,34,24,bgSetup->paletteNumber);
    func_020409B4((u8)bgSetup->bgLayer);
    ARC_TOOL_DeleteHandle(arc);
}





static inline void *MYSTERY_ALBUM_GetPaletteRam(u32 byteOffset, int screenId)
{
    if (screenId==0) return (void *)(byteOffset+0x05000200);
    else return (void *)(byteOffset+0x05000600);
}





/*
 * lever (wave 82, lane R10, retry): the palette base is an inline that adds
 *   the byte offset inside each arm (`if (mode==0) return off+0x05000200;
 *   else return off+0x05000600;`); the shared add cross-jumps into the
 *   `adds r1,r0,r1` join. A base-only inline plus `+ offset` at the call site,
 *   or a ternary on the base, if-converts to a default load plus override and
 *   misschedules the q+0xb0/q+0x98 loads (431 B). The heap stays u16 as in
 *   matched ov121 func_021DBF10 and matched caller MYSTERY_ALBUM_SetupTask: the earlier
 *   u32-heap owner gate does not apply.
 */
void MYSTERY_ALBUM_SetupIcons(MysteryAlbum *album,MysteryAlbumUi *ui,u16 heapId)
{
    void *arc;
    void *iconPalAlloc;
    void *iconGfxAlloc;
    void *iconPalRes;
    void *iconGfxRes;
    MysteryAlbumPoint16 iconPos;
    u16 *paletteRam;
    u32 offset;
    int i;
    arc=func_021DBF10(album,heapId);
    iconPalAlloc=func_02049F78(arc,(int)func_021DBF40(album),(u32)(&iconPalRes),(u16)(album->heapId));
    offset=ui->iconPaletteNumber*32;
    func_02082D44(*(void **)((char *)iconPalRes+12),MYSTERY_ALBUM_GetPaletteRam(offset,ui->screenId),96);
    func_020307B0(iconPalAlloc);
    iconGfxAlloc=func_02049E74(arc,(int)func_021DBF9C(album),(int)0,(u32)(&iconGfxRes),album->heapId);
    CLACT_TransferCharacterPart(ui->bgHandleA,*(void **)((char *)iconGfxRes+20),512,0,ui->screenId);
    func_020307B0(iconGfxAlloc);
    ARC_TOOL_DeleteHandle(arc);
    iconPos.x=216; iconPos.y=22;
    if (func_021DC024(album)==2) {iconPos.x+=4;iconPos.y+=8;}
    func_0204B6F4(ui->iconActor,(u8)func_021DBF70(album),0);
    func_0204B404(ui->iconActor, (const MysteryAlbumPoint16 *)&iconPos, ui->screenId);
    func_0204B3DC(ui->iconActor,1);
    if (func_021DC024(album)==1) {
        CLACT_TransferPalette(ui->paletteHandle,*(void **)((char *)album->paletteRes+12),1);
        func_02082D44(*(void **)((char *)album->paletteRes+12),ui->palImage,32);
        func_02082A48(0,ui->palBlack,32);
        CLACT_TransferCharacterPart(ui->bgHandleB,*(void **)((char *)album->bgDataRes+20),0x1200,0,ui->screenId);
        CLACT_SetActorRotation(ui->cursorActor,0);
        func_0204B3DC(ui->cursorActor,1);
        if (ui->bgSetup.bgLayer<4) paletteRam=(u16 *)((u32)CLACT_GetPaletteVramAddress(ui->paletteHandle,ui->screenId)+0x05000200);
        else paletteRam=(u16 *)((u32)CLACT_GetPaletteVramAddress(ui->paletteHandle,ui->screenId)+0x05000600);
        for(i=0;i<16;i++) paletteRam[i]=ui->palBlack[i];
        if (ui->bgSetup.bgLayer<4)
            func_0207D63C((void *)0x04000050,0,(1<<(u8)ui->bgSetup.bgLayer)|(1<<(u8)ui->bgSetup.overlayLayer),2,12);
        else
            func_0207D63C((void *)0x04001050,0,(1<<(u8)(ui->bgSetup.bgLayer-4))|(1<<(u8)(ui->bgSetup.overlayLayer-4)),2,12);
    } else func_0204B3DC(ui->cursorActor,0);
}





void MYSTERY_ALBUM_StartIntro(MysteryAlbum *album) { if(func_021DC024(album)==1 && album->introPhase==0) { album->introPhase=1; album->introTick=0; } }





void MYSTERY_ALBUM_ResetIntro(MysteryAlbum *album)
{
    char *paletteRam;
    void (*setBlend)(int,int);
    if (func_021DC024(album)==1) {
        album->introPhase=0;
        album->introTick=0;
        CLACT_SetActorBgPriority(album->ui->cursorActor,album->ui->idleAnimId);
        if (album->ui->isMainScreen) {
            paletteRam=(char *)(CLACT_GetPaletteVramAddress(album->ui->paletteHandle,album->ui->screenId)+0x05000200);
            setBlend=MYSTERY_ALBUM_SetBlendMain;
        } else {
            paletteRam=(char *)(CLACT_GetPaletteVramAddress(album->ui->paletteHandle,album->ui->screenId)+0x05000600);
            setBlend=MYSTERY_ALBUM_SetBlendSub;
        }
        setBlend(2,12);
        func_02082A48(0,album->ui->palBlack,32);
        func_02082A60(album->ui->palBlack,paletteRam,32);
    }
}





int MYSTERY_ALBUM_IsIntroIdle(MysteryAlbum *album)
{
    if (album->introPhase==0) return 1;
    return 0;
}





void MYSTERY_ALBUM_SetupTask(void *unused,MysteryAlbum *album)
{
    if (album->isSetupDone) return;
    album->isSetupDone=1;
    switch (album->setupMode) {
    case 0: MYSTERY_ALBUM_LoadBgWithTilemap(&album->ui->bgSetup,album,album->heapId); break;
    case 1: MYSTERY_ALBUM_LoadBgPalette(&album->ui->bgSetup,album,album->heapId); break;
    }
    MYSTERY_ALBUM_SetupIcons(album,album->ui,album->heapId);
    func_021DA4A8(album->cardView);
    func_021DA318(album->ui->albumData);
    func_02040588((u8)(album->ui->backPlane),(int)1);
    func_02040588((u8)(album->ui->frontPlane),(int)1);
}





void MYSTERY_ALBUM_RequestSetup(MysteryAlbum *album,u32 mode) { album->setupMode=mode; if(album->setupTask==0) album->setupTask=func_020056A0((u32)MYSTERY_ALBUM_SetupTask,(u32)album,0); else album->isSetupDone=0; }




void MYSTERY_ALBUM_HideScreen(MysteryAlbumUi *ui)
{
    MysteryAlbumPoint16 cursorPos;
    func_020414EC(4);
    func_020409B4(4);
    func_0204B3DC(ui->iconActor,0);
    cursorPos.x=184;
    cursorPos.y=112;
    func_0204B404(ui->cursorActor, (const MysteryAlbumPoint16 *)&cursorPos, ui->screenId);
    func_0204B3DC(ui->cursorActor,0);
    func_02040588(6,0);
}




/*
 * note pass 2 2026-10-06 P2L16: closed from 7/44. The function returns void (the only
 *   caller, ov121 021DD9CC, declares it void) and the +0 halfword is a direct copy
 *   `*(u16 *)p = *(u16 *)(p+2)` at its store position; the scheduler hoists the ldrh.
 *   The 11 store after the two b stores gives the image colours (b r7, c r4, d r6).
 *   The earlier u16 t local and return form stayed at 7 for every variant.
 */
void MYSTERY_ALBUM_PathAnimInit(MysteryAlbumPathAnim *anim,u16 frameId,int x,int y)
{
    func_02082BCC(anim,0,44);
    anim->prevFrameId=frameId;
    anim->nextFrameId=frameId;
    anim->waypointCount=11;
    anim->startX=x;
    anim->startY=y;
    anim->target.x=x;
    anim->target.y=y;
    anim->frameId=anim->prevFrameId;
    anim->current.x=x;
    anim->current.y=y;
}




#pragma opt_propagation off




/*
 * prior-checks: 1 runtime quotient helpers take two full-word arguments; no residual call setup; 2 ov121 search found no interpolation twin; 3 const char table reduced 13 to 9 bytes, MysteryAlbumPathAnim mutable and widths decoded from loads; 4 aggregate/cast/struct-copy idioms did not resolve residue; 5 fresh directory and ov121/ov122 neighbours reread, no stack aggregate residue.
 * pass 3 2026-10-06 P3L10: EXACT. The direction table is read through a named const table pointer
 *   assigned after x = p->target.x and before the startx store, under opt_propagation off, with the
 *   direction table extern declared const. The live table pointer holds r1 at the startx store, so x
 *   takes r2 and the index*8 shift waits for the store. Non-const table or pointer: 8 B; no pointer: 9 B.
 *   (Earlier attempt logs, 40+ compiles that stayed at 9 B, were removed from this comment.)
 * division: explicit runtime quotient preserves admitted zero-delta division.
 */
int MYSTERY_ALBUM_PathAnimStep(MysteryAlbumPathAnim *anim, u16 *outFrameId, MysteryAlbumPathPoint *outPosition)
{
    int result = 0;
    switch (anim->phase) {
    case 0: {
        const s8 *directionTable;
        int x;
        anim->frame = 0;
        anim->prevFrameId = anim->nextFrameId;
        anim->nextFrameId = MYSTERY_ALBUM_PathFrameIds[anim->waypointIndex];
        x = anim->target.x;
        directionTable = MYSTERY_ALBUM_PathDirections;
        anim->startX = x;
        anim->direction = directionTable[anim->waypointIndex];
        anim->durationFrames = MYSTERY_ALBUM_PathDurations[anim->waypointIndex];
        anim->startY = anim->target.y;
        anim->target = MYSTERY_ALBUM_PathWaypoints[anim->waypointIndex];
        if (anim->direction > 0) {
            anim->prevFrameId = anim->prevFrameId == 0xffff ? 0 : anim->prevFrameId;
            anim->nextFrameId = anim->nextFrameId == 0 ? 0xffff : anim->nextFrameId;
        } else {
            anim->prevFrameId = anim->prevFrameId == 0 ? 0xffff : anim->prevFrameId;
            anim->nextFrameId = anim->nextFrameId == 0xffff ? 0 : anim->nextFrameId;
        }
        anim->phase++;
        break;
    }
    case 1: {
        int startX = anim->startX;
        int deltaX = anim->target.x - startX;
        int sign = _s32_div_f(deltaX < 0 ? -deltaX : deltaX, deltaX);
        int startY, deltaY;
        if (deltaX < 0) deltaX = -deltaX;
        anim->current.x = startX + sign * _u32_div_f(anim->frame * deltaX, anim->durationFrames);
        startY = anim->startY;
        deltaY = anim->target.y - startY;
        if (deltaY < 0) deltaY = -deltaY;
        anim->current.y = startY + sign * _u32_div_f(anim->frame * deltaY, anim->durationFrames);
        if (anim->frame++ >= anim->durationFrames) {
            anim->frameId = anim->nextFrameId;
            anim->current = anim->target;
            anim->phase++;
        }
        break;
    }
    case 2:
        anim->waypointIndex++;
        if (anim->waypointIndex < anim->waypointCount) anim->phase = 0;
        else anim->phase++;
        break;
    case 3:
        result = 1;
        break;
    }
    if (outFrameId) *outFrameId = anim->frameId;
    if (outPosition) *outPosition = anim->current;
    return result;
}




#pragma opt_propagation reset
