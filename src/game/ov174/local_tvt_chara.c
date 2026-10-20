/*
 * file:     local_tvt_chara.c
 * unit:     yes
 * function: LOCAL_TVT_CHARA_Create, LOCAL_TVT_CHARA_Delete, LOCAL_TVT_CHARA_Update, LOCAL_TVT_CHARA_SetActive, LOCAL_TVT_CHARA_IsDone, LOCAL_TVT_CHARA_SetupPalette, LOCAL_TVT_CHARA_SetupActors, LOCAL_TVT_CHARA_LoadPalette, LOCAL_TVT_CHARA_CopyTiles, LOCAL_TVT_CHARA_DrawLabel, LOCAL_TVT_CHARA_ShowWindow, LOCAL_TVT_CHARA_GetState, LOCAL_TVT_CHARA_SetState, LOCAL_TVT_CHARA_ClearState
 * address:  0x021B6C70
 * region:   ov174
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from local_tvt_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_USE_GetRandomBelow 0x02005728 thumb
 *   BG_SYS_PushTile 0x020409B4 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   d_021B7380 0x021B7380 data a1
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021B74BC 0x021B74BC data
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   CLACT_StartActorAnim 0x0204B95C arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_GetActorAnimSeqCount 0x0204B918 arm
 *   CLACT_StopActorAnim 0x0204B974 arm
 *   d_021B7485 0x021B7485 data a1
 *   d_021B7481 0x021B7481 data a1
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   d_021B7484 0x021B7484 data a1
 *   d_021B7480 0x021B7480 data a1
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */

#include "local_tvt_sys_shared_types.h"
#include "../arm9/bg_sys.h"

/* Opaque CLACT sprite actor, shared with the actor library. */
struct ClactActor;
/* Opaque helpers owned by other modules. */
struct Sub0200852CObj;
struct Bmp;
struct BmpWin;
struct Cfg;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct PrintSys;
struct StrObj;

/* Label anchor pair (d_021B7380), one entry per character slot. */
typedef struct { u8 x, y; } LabelPos;


/*
 * One character slot of the TVT system, 0x3C bytes, allocated in
 * LOCAL_TVT_CHARA_Create. The union at 0x08 and 0x10 covers the views that
 * disagreed on signedness and on int versus pointer at the same offset.
 */
struct LocalTvtChara {
    u8 index;                   /* 0x00, slot index */
    u8 step;                    /* 0x01, palette copy step counter */
    u8 charId;                  /* 0x02, character id, 0 or 5 for the player */
    u8 subId;                   /* 0x03, secondary palette/anim index */
    u8 paletteA;                /* 0x04, toggling palette page */
    u8 paletteB;                /* 0x05, toggling palette page */
    u8 timer;                   /* 0x06, counts to 40 before the pages swap */
    u8 labelWidth;              /* 0x07, returned by LOCAL_TVT_CHARA_GetState */
    union { int value; unsigned int valueU; } state; /* 0x08 */
    void *tileSrc;              /* 0x0C, tile source record, filled by ARC_UTIL_LoadBgCharDataFromHandle */
    union { int handle; void *handlePtr; } gfx;      /* 0x10, freed by GFL_HEAP_Free */
    int flag;                   /* 0x14, label transfer pending */
    struct BmpWin *window;      /* 0x18, label window */
    u32 paletteHandle;          /* 0x1C, CLACT palette handle */
    u32 charHandle;             /* 0x20, CLACT character handle */
    u32 cellHandle;             /* 0x24, CLACT cell anim handle */
    struct ClactActor *actorA;  /* 0x28, label actor */
    struct ClactActor *actorB;  /* 0x2C, secondary actor */
    u16 animTimer;              /* 0x30, counts to 150 before actorA replays */
    int active;                 /* 0x34, drives actorB */
    u16 counter;                /* 0x38, pause counter for actorB */
};

/* Actor spawn record passed to CLACT_CreateActor. */
typedef struct {
    short x;        /* 0x00 screen x */
    short y;        /* 0x02 screen y */
    u16 id;         /* 0x04 actor selector: 0 or 1 */
    u8 mode;        /* 0x06 */
    u8 space;       /* 0x07 */
} LocalTvtCharaRequest;

/* Compile-time check of the allocation size used in LOCAL_TVT_CHARA_Create. */
typedef char LocalTvtChara_size_check[(sizeof(struct LocalTvtChara)==0x3C)?1:-1];
struct ClactActor;





#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/gfl_use.h"
struct GameData;
struct MyStatus;

#include "../arm9/game_data.h"




#include "../arm9/mystatus.h"





struct Strbuf;

#include "../arm9/strbuf.h"

#include "../arm9/wordset.h"

#include "../arm9/bmp_win.h"


typedef short s16_p07;
#include "../arm9/bmp.h"






#include "../arm9/msgdata.h"


#include "../arm9/gf_font.h"


struct PrintQueue;

#include "../arm9/printsys.h"






#include "../arm9/arc_util.h"


#include "../arm9/clact.h"
extern void MIi_CpuCopy32(int, int, int);
struct GfFont;



char *LOCAL_TVT_CHARA_Create(char *p,int index);

void LOCAL_TVT_CHARA_Delete(unsigned char *unused,char *p);

void LOCAL_TVT_CHARA_Update(u8 *p,u8 *q);

void LOCAL_TVT_CHARA_SetActive(u8 *unused,u8 *q,int unused2);

int LOCAL_TVT_CHARA_IsDone(u8 *unused, char *p);

void LOCAL_TVT_CHARA_SetupPalette(char *p,u8 *q);

void LOCAL_TVT_CHARA_SetupActors(u8 *p, u8 *q);

void LOCAL_TVT_CHARA_LoadPalette(char *p, char *q, int id);

void LOCAL_TVT_CHARA_CopyTiles(int a, int *b, int c, int d, int e);

void LOCAL_TVT_CHARA_DrawLabel(u8 *p,u8 *q);

void LOCAL_TVT_CHARA_ShowWindow(int a, int *p);

unsigned LOCAL_TVT_CHARA_GetState(unsigned char *p);

void LOCAL_TVT_CHARA_SetState(char *p, int v);

void LOCAL_TVT_CHARA_ClearState(char *p);

extern const LabelPos d_021B7380[];

extern char d_021B74BC[];

extern const u8 d_021B7485[],d_021B7481[];

extern const u8 d_021B7484[],d_021B7480[];

char *LOCAL_TVT_CHARA_Create(char *p,int index)
{
    char *q;
    if(((u8 *)((struct LocalTvtSys *)p)->menuCharaTable)[index]==0xff) return 0;
    q=GFL_HEAP_Alloc(((struct LocalTvtSys *)p)->heapId,0x3c,0,d_021B74BC,0x7a);
    ((struct LocalTvtChara *)q)->index=index;
    ((struct LocalTvtChara *)q)->charId=((u8 *)((struct LocalTvtSys *)p)->menuCharaTable)[index];
    ((struct LocalTvtChara *)q)->subId=(*(u8 * *)&((struct LocalTvtSys *)p)->menuCharaTable+index)[4];
    ((struct LocalTvtChara *)q)->paletteA=0;
    ((struct LocalTvtChara *)q)->paletteB=0;
    ((struct LocalTvtChara *)q)->flag=0;
    ((struct LocalTvtChara *)q)->active=0;
    ((struct LocalTvtChara *)q)->animTimer=GFL_USE_GetRandomBelow(0x4b);
    if(((struct LocalTvtChara *)q)->charId==0 && MYSTATUS_GetSex((struct MyStatus *)GAME_DATA_GetMyStatus(((struct LocalTvtSysMode *)((struct LocalTvtSys *)p)->modeData)->gameData))==1) ((struct LocalTvtChara *)q)->charId=5;
    LOCAL_TVT_CHARA_SetupActors((u8 *)p,(u8 *)q);
    LOCAL_TVT_CHARA_SetupPalette(p,(u8 *)q);
    LOCAL_TVT_CHARA_DrawLabel((u8 *)p,(u8 *)q);
    ((struct LocalTvtChara *)q)->state.value=0;
    ((struct LocalTvtChara *)q)->gfx.handle=0;
    ((struct LocalTvtChara *)q)->timer=GFL_USE_GetRandomBelow(40);
    ((struct LocalTvtChara *)q)->counter=0;
    return q;
}

void LOCAL_TVT_CHARA_Delete(unsigned char *unused,char *p) {CLACT_DeleteActor((struct ClactActor *)(((struct LocalTvtChara *)p)->actorA));CLACT_DeleteActor((struct ClactActor *)(((struct LocalTvtChara *)p)->actorB));CLACT_ReleasePalette(((struct LocalTvtChara *)p)->paletteHandle);CLACT_ReleaseCharacter(((struct LocalTvtChara *)p)->charHandle);CLACT_ReleaseCellAnim(((struct LocalTvtChara *)p)->cellHandle);BMP_WIN_Delete(((struct LocalTvtChara *)p)->window);if(((struct LocalTvtChara *)p)->gfx.handlePtr)GFL_HEAP_Free(((struct LocalTvtChara *)p)->gfx.handlePtr);GFL_HEAP_Free(p);}

void LOCAL_TVT_CHARA_Update(u8 *p,u8 *q)
{
    unsigned size;
    unsigned pal;
    unsigned base;
    unsigned step;
    if(((struct LocalTvtSys *)p)->charaCount==2) size=0x6000; else size=0x3000;
    if(((struct LocalTvtSys *)p)->highBase==0) pal=0;else pal=0xC000;
    if(((struct LocalTvtSys *)p)->charaCount==2) base=0;else base=0x1C00;
    switch(((struct LocalTvtChara *)q)->state.valueU) {
    case 1:
        ((struct LocalTvtChara *)q)->step=0;
        LOCAL_TVT_CHARA_LoadPalette((char *)p,(char *)q,((struct LocalTvtChara *)q)->paletteA+d_021B7485[((struct LocalTvtChara *)q)->charId*3]);
        ((struct LocalTvtChara *)q)->state.valueU=2;
        break;
    case 2:
        step=((struct LocalTvtChara *)q)->step*0x3000u;
        LOCAL_TVT_CHARA_CopyTiles((int)p,(int *)q,base+step,pal+(step+(size*((struct LocalTvtChara *)q)->index+0x10000)),0x3000);
        ((struct LocalTvtChara *)q)->step++;
        if(((struct LocalTvtChara *)q)->step*0x3000u>=size) {
            ((struct LocalTvtChara *)q)->state.valueU=3;
            GFL_HEAP_Free(((struct LocalTvtChara *)q)->gfx.handlePtr);
            ((struct LocalTvtChara *)q)->gfx.handlePtr=0;
        }
        break;
    case 3:
        ((struct LocalTvtChara *)q)->step=0;
        LOCAL_TVT_CHARA_LoadPalette((char *)p,(char *)q,(((struct LocalTvtChara *)q)->paletteB+d_021B7481[((struct LocalTvtChara *)q)->subId*2])+(((struct LocalTvtSys *)p)->timeSlot*2));
        ((struct LocalTvtChara *)q)->state.valueU=4;
        break;
    case 4:
        step=((struct LocalTvtChara *)q)->step*0x3000u;
        LOCAL_TVT_CHARA_CopyTiles((int)p,(int *)q,base+step,pal+(step+(size*((struct LocalTvtChara *)q)->index+0x28000)),0x3000);
        ((struct LocalTvtChara *)q)->step++;
        if(((struct LocalTvtChara *)q)->step*0x3000u>=size) {
            ((struct LocalTvtChara *)q)->state.valueU=5;
            GFL_HEAP_Free(((struct LocalTvtChara *)q)->gfx.handlePtr);
            ((struct LocalTvtChara *)q)->gfx.handlePtr=0;
        }
        break;
    case 0:
        break;
    }
    if(((struct LocalTvtChara *)q)->timer<40) ((struct LocalTvtChara *)q)->timer++;
    else if(((struct LocalTvtChara *)q)->state.valueU==5 || ((struct LocalTvtChara *)q)->state.valueU==0) {
        ((struct LocalTvtChara *)q)->timer=0;
        ((struct LocalTvtChara *)q)->paletteA=((struct LocalTvtChara *)q)->paletteA==0?1:0;
        ((struct LocalTvtChara *)q)->paletteB=((struct LocalTvtChara *)q)->paletteB==0?1:0;
    }
    if(((struct LocalTvtChara *)q)->flag==1 && PRINTSYS_QUE_IsFinished(((struct LocalTvtSys *)p)->printQueue.ptr)==1) {
        BMP_WIN_TransferChars(((struct LocalTvtChara *)q)->window);
        ((struct LocalTvtChara *)q)->flag=0;
    }
    ((struct LocalTvtChara *)q)->animTimer+=(u16)(GFL_USE_GetRandom(2)+1);
    if(((struct LocalTvtChara *)q)->animTimer>=150) {
        CLACT_StartActorAnim((struct ClactActor *)(((struct LocalTvtChara *)q)->actorA));
        CLACT_RestartActorAnim((struct ClactActor *)(((struct LocalTvtChara *)q)->actorA));
        ((struct LocalTvtChara *)q)->animTimer=0;
    }
    if(((struct LocalTvtChara *)q)->active==1 || ((struct LocalTvtChara *)q)->counter!=0) {
        if(CLACT_IsActorAnimActive((struct ClactActor *)(((struct LocalTvtChara *)q)->actorB))==0) CLACT_StartActorAnim((struct ClactActor *)(((struct LocalTvtChara *)q)->actorB));
    } else {
        if(CLACT_IsActorAnimActive((struct ClactActor *)(((struct LocalTvtChara *)q)->actorB))==1 && CLACT_GetActorAnimSeqCount((struct ClactActor *)(((struct LocalTvtChara *)q)->actorB))==0)
            CLACT_StopActorAnim((struct ClactActor *)(((struct LocalTvtChara *)q)->actorB));
    }
    if(((struct LocalTvtChara *)q)->counter!=0) (((struct LocalTvtChara *)q)->counter)--;
}

/*
 * extent: trailing store-and-return follower 021B6F24 included in this unit; 021B6F2A..021B6F2C is alignment padding.
 */
void LOCAL_TVT_CHARA_SetActive(u8 *unused,u8 *q,int unused2)
{
    ((struct LocalTvtChara *)q)->state.value=1;
}

int LOCAL_TVT_CHARA_IsDone(u8 *unused, char *p)
{
    return ((struct LocalTvtChara *)p)->state.value == 5;
}

void LOCAL_TVT_CHARA_SetupPalette(char *p,u8 *q)
{
    u8 height=24;
    if(((struct LocalTvtSys *)p)->charaCount!=2) height=12;
    ARC_UTIL_UploadPaletteFromHandle(((struct LocalTvtSys *)p)->arcHandle,d_021B7484[((struct LocalTvtChara *)q)->charId*3],2,0,0x4000+((struct LocalTvtChara *)q)->index*0x200,0x200,((struct LocalTvtSys *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandle(((struct LocalTvtSys *)p)->arcHandle,((struct LocalTvtSys *)p)->timeSlot+d_021B7480[((struct LocalTvtChara *)q)->subId*2],2,0,0x6000+((struct LocalTvtChara *)q)->index*0x200,0x200,((struct LocalTvtSys *)p)->heapId);
    BG_SYS_FillTileMap(2,(((struct LocalTvtChara *)q)->index%2)*16,(((struct LocalTvtChara *)q)->index/2)*height,16,height,((struct LocalTvtChara *)q)->index);
    BG_SYS_FillTileMap(3,(((struct LocalTvtChara *)q)->index%2)*16,(((struct LocalTvtChara *)q)->index/2)*height,16,height,((struct LocalTvtChara *)q)->index);
    BG_SYS_MarkTileDirty(3);
    BG_SYS_MarkTileDirty(2);
}

/*
 * prototype: 0204B294 leaves its forwarder's result in r0, captured at
 *   021B712A and 021B715A; the returned object pointer is stored as a word.
 */
void LOCAL_TVT_CHARA_SetupActors(u8 *p, u8 *q)
{
    int step;
    int base;
    LocalTvtCharaRequest req;
    if (((struct LocalTvtSys *)p)->charaCount == 2) { step = 0x6000; base = 0; }
    else { step = 0x3000; base = 0x1c00; }
    LOCAL_TVT_CHARA_LoadPalette((char *)p, (char *)q, (d_021B7481 + 4)[((struct LocalTvtChara *)q)->charId * 3]);
    LOCAL_TVT_CHARA_CopyTiles((int)p, (int *)q, base, step * ((struct LocalTvtChara *)q)->index + 0x10000, step);
    GFL_HEAP_Free(((struct LocalTvtChara *)q)->gfx.handlePtr);
    LOCAL_TVT_CHARA_LoadPalette((char *)p, (char *)q, d_021B7481[((struct LocalTvtChara *)q)->subId * 2] + ((struct LocalTvtSys *)p)->timeSlot * 2);
    LOCAL_TVT_CHARA_CopyTiles((int)p, (int *)q, base, step * ((struct LocalTvtChara *)q)->index + 0x28000, step);
    GFL_HEAP_Free(((struct LocalTvtChara *)q)->gfx.handlePtr);
    ((struct LocalTvtChara *)q)->paletteHandle = CLACT_RegisterPaletteCompressed(((struct LocalTvtSys *)p)->arcHandle, (d_021B7481 + 5)[((struct LocalTvtChara *)q)->charId * 3], 0, (u16)((((struct LocalTvtChara *)q)->index * 2 + 4) << 5), ((struct LocalTvtSys *)p)->heapId);
    ((struct LocalTvtChara *)q)->charHandle = CLACT_RegisterCharacter(((struct LocalTvtSys *)p)->arcHandle, (d_021B7481 + 5)[((struct LocalTvtChara *)q)->charId * 3] + 1, 0, 0, ((struct LocalTvtSys *)p)->heapId);
    ((struct LocalTvtChara *)q)->cellHandle = CLACT_RegisterCellAnim(((struct LocalTvtSys *)p)->arcHandle, (d_021B7481 + 5)[((struct LocalTvtChara *)q)->charId * 3] + 2, (d_021B7481 + 5)[((struct LocalTvtChara *)q)->charId * 3] + 3, ((struct LocalTvtSys *)p)->heapId);
    req.mode = 10; req.space = 1;
    req.x = (((struct LocalTvtChara *)q)->index % 2) * 128 + 64;
    req.y = (((struct LocalTvtChara *)q)->index / 2) * 96 + 48;
    if (((struct LocalTvtSys *)p)->charaCount == 2) req.y += 56;
    req.id = 0;
    ((struct LocalTvtChara *)q)->actorA = CLACT_CreateActor(((struct LocalTvtSys *)p)->unit.ptr, ((struct LocalTvtChara *)q)->charHandle, ((struct LocalTvtChara *)q)->paletteHandle, ((struct LocalTvtChara *)q)->cellHandle, (const struct ActorInitParam *)&req, 0, ((struct LocalTvtSys *)p)->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)(((struct LocalTvtChara *)q)->actorA), 1);
    CLACT_SetActorAutoAnim((struct ClactActor *)(((struct LocalTvtChara *)q)->actorA), 1);
    CLACT_StopActorAnim((struct ClactActor *)(((struct LocalTvtChara *)q)->actorA));
    req.id = 1;
    ((struct LocalTvtChara *)q)->actorB = CLACT_CreateActor(((struct LocalTvtSys *)p)->unit.ptr, ((struct LocalTvtChara *)q)->charHandle, ((struct LocalTvtChara *)q)->paletteHandle, ((struct LocalTvtChara *)q)->cellHandle, (const struct ActorInitParam *)&req, 0, ((struct LocalTvtSys *)p)->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)(((struct LocalTvtChara *)q)->actorB), 1);
    CLACT_SetActorAutoAnim((struct ClactActor *)(((struct LocalTvtChara *)q)->actorB), 1);
    CLACT_StopActorAnim((struct ClactActor *)(((struct LocalTvtChara *)q)->actorB));
}

void LOCAL_TVT_CHARA_LoadPalette(char *p, char *q, int id) {((struct LocalTvtChara *)q)->gfx.handlePtr=ARC_UTIL_LoadBgCharDataFromHandle((void *)(((struct LocalTvtSys *)p)->arcHandle),(unsigned int)id,(unsigned int)0,(&((struct LocalTvtChara *)q)->tileSrc),((struct LocalTvtSys *)p)->heapId);}

void LOCAL_TVT_CHARA_CopyTiles(int a, int *b, int c, int d, int e)
{
    MIi_CpuCopy32(*(int *)((char *)(((struct LocalTvtChara *)b)->tileSrc) + 0x14) + c,
                  d + 0x06000000, e);
}

void LOCAL_TVT_CHARA_DrawLabel(u8 *p,u8 *q)
{
    void *s;
    void *dst;
    void *ws;
    u8 *save;
    ((struct LocalTvtChara *)q)->window=BMP_WIN_Create(0,(u8)(d_021B7380[((struct LocalTvtChara *)q)->index].x+2),(u8)(d_021B7380[((struct LocalTvtChara *)q)->index].y+1),12,2,12,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct LocalTvtChara *)q)->window),0);
    BMP_WIN_TransferChars(((struct LocalTvtChara *)q)->window);
    BMP_WIN_MakeScreen((struct BmpWin *)((struct LocalTvtChara *)q)->window);
    BG_SYS_PushTile(0);
    s=MSGDATA_AllocString(((struct LocalTvtSys *)p)->msgBankA.ptr, ((struct LocalTvtChara *)q)->charId);
    if(((struct LocalTvtChara *)q)->charId==0 || ((struct LocalTvtChara *)q)->charId==5){
        dst=STRBUF_Create(128,((struct LocalTvtSys *)p)->heapId);
        save=(unsigned char *)GAME_DATA_GetMyStatus(((struct LocalTvtSysMode *)((struct LocalTvtSys *)p)->modeData)->gameData);
        ws=WORDSET_CreateDefault(((struct LocalTvtSys *)p)->heapId);
        WORDSET_SetSlotMyStatus(ws,0,save);
        WORDSET_CopyTaggedText(ws,dst,s);
        STRBUF_Delete(s);
        WORDSET_Delete(ws);
        s=dst;
    }
    ((struct LocalTvtChara *)q)->labelWidth=PRINTSYS_MeasureWidestLine(s,(struct GfFont *)(((struct LocalTvtSys *)p)->font.value),0);
    PRINTSYS_PrintQueColor(((struct LocalTvtSys *)p)->printQueue.ptr,BMP_WIN_GetBmp(((struct LocalTvtChara *)q)->window),(short)((96-((struct LocalTvtChara *)q)->labelWidth)/2+1),1,s,(struct GfFont *)(((struct LocalTvtSys *)p)->font.value),0x3c00);
    PRINTSYS_PrintQueColor(((struct LocalTvtSys *)p)->printQueue.ptr,BMP_WIN_GetBmp(((struct LocalTvtChara *)q)->window),(short)((96-((struct LocalTvtChara *)q)->labelWidth)/2-1),1,s,(struct GfFont *)(((struct LocalTvtSys *)p)->font.value),0x3c00);
    PRINTSYS_PrintQueColor(((struct LocalTvtSys *)p)->printQueue.ptr,BMP_WIN_GetBmp(((struct LocalTvtChara *)q)->window),(short)((96-((struct LocalTvtChara *)q)->labelWidth)/2),2,s,(struct GfFont *)(((struct LocalTvtSys *)p)->font.value),0x3c00);
    PRINTSYS_PrintQueColor(((struct LocalTvtSys *)p)->printQueue.ptr,BMP_WIN_GetBmp(((struct LocalTvtChara *)q)->window),(short)((96-((struct LocalTvtChara *)q)->labelWidth)/2),0,s,(struct GfFont *)(((struct LocalTvtSys *)p)->font.value),0x3c00);
    PRINTSYS_PrintQueColor(((struct LocalTvtSys *)p)->printQueue.ptr,BMP_WIN_GetBmp(((struct LocalTvtChara *)q)->window),(short)((96-((struct LocalTvtChara *)q)->labelWidth)/2),1,s,(struct GfFont *)(((struct LocalTvtSys *)p)->font.value),0x400);
    STRBUF_Delete(s);
    ((struct LocalTvtChara *)q)->flag=1;
}

void LOCAL_TVT_CHARA_ShowWindow(int a, int *p)
{
    BMP_WIN_MakeScreen((struct BmpWin *)(((struct LocalTvtChara *)p)->window));
    BG_SYS_MarkTileDirty(0);
}

unsigned LOCAL_TVT_CHARA_GetState(unsigned char *p) {return ((struct LocalTvtChara *)p)->labelWidth;}

void LOCAL_TVT_CHARA_SetState(char *p, int v)
{
    if (((struct LocalTvtChara *)p)->active == 1 && v == 0)
        ((struct LocalTvtChara *)p)->counter = 0x46;
    ((struct LocalTvtChara *)p)->active = v;
}

void LOCAL_TVT_CHARA_ClearState(char *p)
{
    ((struct LocalTvtChara *)p)->counter = 0;
    ((struct LocalTvtChara *)p)->active = 0;
}
