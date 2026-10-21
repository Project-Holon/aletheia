/*
 * file:     sta_act_button.c
 * unit:     yes
 * function: STA_ACT_BUTTON_Create, STA_ACT_BUTTON_Delete, STA_ACT_BUTTON_Update, STA_ACT_BUTTON_CreateActors, STA_ACT_BUTTON_LoadCharacter, STA_ACT_BUTTON_SetVisible
 * address:  0x021FA5B0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_acting.c, script_command.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   STA_ACT_BUTTON_Create 0x021FA5B0 thumb ov132
 *   STA_ACT_BUTTON_Delete 0x021FA64C thumb ov132
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STA_ACT_BUTTON_Update 0x021FA6CC thumb ov132
 *   STA_ACT_BUTTON_SetVisible  0x021FAAB8  thumb
 *   d_021FDCD8 0x021FDCD8 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   d_021FDC20 0x021FDC20 data a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   STA_ACTING_RequestAction 0x021F9730 thumb ov132
 *   STA_ACTING_GetCurrentAction 0x021F9768 thumb ov132
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   STA_ACTING_GetActorCount 0x021F9E0C thumb ov132
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_GetElemSizeFlags 0x021F4F70 thumb ov112
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   DC_FlushRange 0x020862F0 arm
 *   GXS_LoadOBJPltt 0x0207E5D0 arm
 *   GXS_LoadOBJ 0x0207E804 arm
 */
#include "ov132_types.h"
#include "../sdk_ioreg.h"
#include "sta_acting_shared_types.h"
#include "sta_act_effect_shared_types.h"

#include "../arm9/arc_tool.h"

struct Bank;

struct Actor;

struct Vec2;


typedef enum { FLAG_ZERO, FLAG_ONE } Flag;

typedef struct {u8 bytes[12];} Key;

typedef struct {short x,y;} StaActButtonPos;


typedef struct {short x,y,index;u8 a,b;} StaActButtonParams;

#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/clact.h"





#include "../arm9/touchpanel.h"

#include "../arm9/g2.h"

#include "sta_acting.h"




#include "../arm9/ui.h"





#include "../ov112/mus_item_data.h"






extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);


#include "../arm9/arc_util.h"

#include "../arm9/nns_g3d_res.h"


#include "../arm9/os_cache.h"

#include "../arm9/gx_load2d.h"


char *STA_ACT_BUTTON_Create(unsigned heap, void *a, char *b);

void STA_ACT_BUTTON_Delete(char *p);

void STA_ACT_BUTTON_Update(char *p);

void STA_ACT_BUTTON_CreateActors(char *p);

void STA_ACT_BUTTON_LoadCharacter(u8 *p,u16 slot,int resource,u32 type);

void STA_ACT_BUTTON_SetVisible(char *p, unsigned flag);

extern const char d_021FDCD8[];

extern const Key d_021FDC20;

static inline void inside(int wnd, int effect)
{
    unsigned tmp = (*(volatile u16 *)REG_DB_WININ_ADDR & ~63) | (unsigned)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x04001048 = tmp;
}

static inline void outside(int wnd, int effect)
{
    unsigned tmp = (*(volatile u16 *)REG_DB_WINOUT_ADDR & ~63) | (unsigned)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400104a = tmp;
}

/*
 * volatile: hardware register reads and writes at 021FA5FA..021FA634.
 */
char *STA_ACT_BUTTON_Create(unsigned heap, void *scene, char *playerRecord)
{
    char *p = GFL_HEAP_Alloc(heap, 0x60, 0, d_021FDCD8, 87);
    ((struct StaActTaskObj *)p)->heapId = heap;
    ((struct StaActTaskObj *)p)->scene = scene;
    *(char * *)&((struct StaActTaskObj *)p)->playerRecord = playerRecord;
    ((struct StaActTaskObj *)p)->enabled.s = 0;
    ((struct StaActTaskObj *)p)->actionPending = 0;
    ((struct StaActTaskObj *)p)->pressedIndex = 2;
    ((struct StaActTaskObj *)p)->actorIds[0] = ((struct ActingRecord *)playerRecord)->leftActorId;
    ((struct StaActTaskObj *)p)->actorIds[1] = ((struct ActingRecord *)(*(char * *)&((struct StaActTaskObj *)p)->playerRecord))->rightActorId;
    ((struct StaActTaskObj *)p)->pressed[0] = 0;
    ((struct StaActTaskObj *)p)->pressed[1] = 0;
    STA_ACT_BUTTON_CreateActors(p);
    *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xe000) | 0x2000;
    inside(31, 1);
    outside(31, 0);
    *(volatile u16 *)0x04001040 = 255;
    *(volatile u16 *)0x04001044 = 0x80c0;
    return p;
}

/*
 * volatile: hardware control read at 021FA652 and store 021FA658.
 */
void STA_ACT_BUTTON_Delete(char *p)
{
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    if (((struct StaActTaskObj *)p)->actorIds[0] != 255) CLACT_DeleteActor(((struct StaActTaskObj *)p)->frameActors[0]);
    if (((struct StaActTaskObj *)p)->actorIds[1] != 255) CLACT_DeleteActor(((struct StaActTaskObj *)p)->frameActors[1]);
    CLACT_DeleteActor(((struct StaActTaskObj *)p)->pressActor);
    CLACT_ReleasePalette((uptr)(((struct StaActTaskObj *)p)->framePalette.p));
    CLACT_ReleaseCharacter((uptr)(((struct StaActTaskObj *)p)->frameCharacter.p));
    CLACT_ReleaseCellAnim((uptr)(((struct StaActTaskObj *)p)->frameCellAnim.p));
    CLACT_ReleasePalette((uptr)(((struct StaActTaskObj *)p)->iconPalette.p));
    CLACT_ReleaseCharacter((uptr)(((struct StaActTaskObj *)p)->iconCharacter.p));
    CLACT_ReleaseCellAnim((uptr)(((struct StaActTaskObj *)p)->iconCellAnim.p));
    CLACT_ReleasePalette((uptr)(((struct StaActTaskObj *)p)->pressPalette.p));
    CLACT_ReleaseCharacter((uptr)(((struct StaActTaskObj *)p)->pressCharacter.p));
    CLACT_ReleaseCellAnim((uptr)(((struct StaActTaskObj *)p)->pressCellAnim.p));
    CLACT_DeleteUnit(((struct StaActTaskObj *)p)->clactUnit);
    GFL_HEAP_Free(p);
}

/*
 * checks: 1 fresh 9730/9768 show and 25EA4/23F60/B3DC/B9A0/B98C bodies confirm arities; 2 fresh A5B0/A64C/A7E0 no full twin; 3 u8/const-char pointer unchanged; 4 struct-field, chained-assignment and enum-zero idioms; 5 fresh directory/neighbours.
 * spelling: enum-typed one/zero locals retain separate constant webs; literals and enum-typed stores alone left six differing bytes. Prior permuter300 was not repeated.
 */
void STA_ACT_BUTTON_Update(char *p)
{
    Key key;
    StaActButtonPos pos;
    int hit;
    Flag one,zero;
    if(((struct StaActTaskObj *)p)->enabled.s==1) {
        key=d_021FDC20;
        hit=TOUCHPANEL_HitTrg((const TouchHitTable *)&key);
        G2x_SetBlendBrightness_(REG_DB_BLDCNT_ADDR,16,0);
        if(hit!=-1 && *(u16 *)(p+0x48+hit*2)!=255 && *(int *)(p+0x40+hit*4)==0) {
            if(hit==0) STA_ACTING_RequestAction(((struct StaActTaskObj *)p)->scene,7);
            else STA_ACTING_RequestAction(((struct StaActTaskObj *)p)->scene,8);
            G2x_SetBlendBrightness_(REG_DB_BLDCNT_ADDR,16,-8);
            one=FLAG_ONE;
            zero=FLAG_ZERO;
            *(u32 *)(p+0x40+hit*4)=one;
            *(u32 *)&((struct StaActTaskObj *)p)->actionPending=one;
            *(u32 *)&((struct StaActTaskObj *)p)->enabled=zero;
            ((struct StaActTaskObj *)p)->pressedIndex=hit;
            pos.x=hit==0?32:224;
            pos.y=128;
            CLACT_RestartActorAnim((struct ClactActor *)(((struct StaActTaskObj *)p)->pressActor));
            CLACT_SetActorDrawEnable((struct ClactActor *)(((struct StaActTaskObj *)p)->pressActor),1);
            CLACT_AddActorSurfacePos((struct ClactActor *)(((struct StaActTaskObj *)p)->pressActor),(const struct ClactVec2 *)((const struct Vec2 *)(&pos)),1);
            UI_SetInputMode(1);
        }
    }
    if(((struct StaActTaskObj *)p)->pressedIndex!=2) {
        if(STA_ACTING_GetCurrentAction(((struct StaActTaskObj *)p)->scene)==0) {
            if(((struct StaActTaskObj *)p)->actionPending==0) {
                ((struct StaActTaskObj *)p)->enabled.s=1;
                CLACT_SetActorDrawEnable(*(void **)(p+0x4c+((struct StaActTaskObj *)p)->pressedIndex*4),0);
                CLACT_SetActorDrawEnable(*(void **)(p+0x54+((struct StaActTaskObj *)p)->pressedIndex*4),0);
                ((struct StaActTaskObj *)p)->pressedIndex=2;
            }
        } else {
            if(((struct StaActTaskObj *)p)->actionPending==1) ((struct StaActTaskObj *)p)->actionPending=0;
        }
    }
    if(CLACT_GetActorDrawEnable(((struct StaActTaskObj *)p)->pressActor)==1) {
        if(CLACT_IsActorAnimActive(((struct StaActTaskObj *)p)->pressActor)==0) CLACT_SetActorDrawEnable(((struct StaActTaskObj *)p)->pressActor,0);
    }
}

/*
 * extent: 021FA99A zero halfword is alignment padding before labelled 021FA99C.
 * ABI: B294 forwards an address-valued u32 payload and returns the actor in r0; ABF0 tail-forwards AC18's index despite void declaration.
 */
void STA_ACT_BUTTON_CreateActors(char *p)
{
    StaActButtonParams configs[2];
    u8 *table;
    void *narc;
    u8 i=0;
    int format;
    table=(u8 *)STA_ACTING_GetActorCount((u8 *)(*(char * *)&((struct StaActTaskObj *)p)->scene));
    ((struct StaActTaskObj *)p)->clactUnit=CLACT_CreateUnit(5,0,((struct StaActTaskObj *)p)->heapId);
    CLACT_SetUnitDefaultRenderer(((struct StaActTaskObj *)p)->clactUnit);
    narc=ARC_TOOL_CreateHandle(47,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->framePalette=CLACT_RegisterPaletteEx(narc,0,1,0,0,2,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->frameCharacter=CLACT_RegisterCharacter(narc,6,0,1,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->frameCellAnim=CLACT_RegisterCellAnim(narc,18,21,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->iconPalette=CLACT_RegisterPaletteEx(narc,1,1,64,0,1,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->iconCharacter=CLACT_RegisterCharacter(narc,7,0,1,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->iconCellAnim=CLACT_RegisterCellAnim(narc,19,22,((struct StaActTaskObj *)p)->heapId);
    ARC_TOOL_DeleteHandle(narc);
    narc=ARC_TOOL_CreateHandle(46,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->pressPalette=CLACT_RegisterPalette(narc,0,1,96,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->pressCharacter=CLACT_RegisterCharacter(narc,26,0,1,((struct StaActTaskObj *)p)->heapId);
    *(int *)&((struct StaActTaskObj *)p)->pressCellAnim=CLACT_RegisterCellAnim(narc,18,22,((struct StaActTaskObj *)p)->heapId);
    ARC_TOOL_DeleteHandle(narc);
    for(i=0;i<2;i++) {
        if(*(u16 *)(p+i*2+0x48)!=255) {
            format=MUSICAL_MCSS_GetElemSizeFlags((int *)MUSICAL_MCSS_GetElemPtr(table,*(u16 *)(p+i*2+0x48)));
            if(i==0) configs[1].x=32;
            else configs[1].x=224;
            configs[1].y=160;
            configs[1].index=i;
            configs[1].a=10;
            configs[1].b=0;
            *(void **)(p+i*4+0x4c)=CLACT_CreateActor((struct Unit *)(*(void **)&((struct StaActTaskObj *)p)->clactUnit),((struct StaActTaskObj *)p)->frameCharacter.u,((struct StaActTaskObj *)p)->framePalette.u,((struct StaActTaskObj *)p)->frameCellAnim.u,(const struct ActorInitParam *)&configs[1],1,((struct StaActTaskObj *)p)->heapId);
            configs[1].index=0;
            *(void **)(p+i*4+0x54)=CLACT_CreateActor((struct Unit *)(*(void **)&((struct StaActTaskObj *)p)->clactUnit),((struct StaActTaskObj *)p)->iconCharacter.u,((struct StaActTaskObj *)p)->iconPalette.u,((struct StaActTaskObj *)p)->iconCellAnim.u,(const struct ActorInitParam *)&configs[1],1,((struct StaActTaskObj *)p)->heapId);
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x4c),0);
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x54),0);
            STA_ACT_BUTTON_LoadCharacter((u8 *)p,i,*(u16 *)(p+i*2+0x48),format);
        }
    }
    configs[0].x=128; configs[0].y=96; configs[0].index=0;configs[0].a=0;configs[0].b=0;
    ((struct StaActTaskObj *)p)->pressActor=CLACT_CreateActor((struct Unit *)(*(void **)&((struct StaActTaskObj *)p)->clactUnit),((struct StaActTaskObj *)p)->pressCharacter.u,((struct StaActTaskObj *)p)->pressPalette.u,((struct StaActTaskObj *)p)->pressCellAnim.u,(const struct ActorInitParam *)&configs[0],1,((struct StaActTaskObj *)p)->heapId);
    CLACT_SetActorDrawEnable(((struct StaActTaskObj *)p)->pressActor,0);
    CLACT_SetActorAutoAnim(((struct StaActTaskObj *)p)->pressActor,1);
}

/*
 * note 2026-10-05: copies a tile sheet into VRAM in 4-byte pieces (block x line x column).
 * CLACT_GetCharacterVramAddress returns a pointer (the matched ov119 021E6E7C and ov131 021DBCF4 use it so),
 * which removed the old prototype blocker. Levers: locals declared in the order of the
 * frame slots (dst, block, height, line, y, x, src), u16 slot (puts its entry spill first),
 * u8 height, case 50 reads x = y, and y = 0 written after the blob call (literal 0 in it).
 */
void STA_ACT_BUTTON_LoadCharacter(u8 *p,u16 slot,int resource,u32 type)
{
    sptr blob;
    u32 charSize,palSize;
    u8 *dst;
    u8 block;
    u8 height;
    u8 line;
    u32 y;
    u32 x;
    u8 *src;
    u8 *tex;
    u32 palOffset;
    u8 col;
    blob=(sptr)ARC_UTIL_LoadMember(45,resource,0,*(u16 *)p);
    y=0;
    tex=(u8 *)NNS_G3dGetTex((NNSG3dResFileHeader *)blob);
    src=tex+*(u32 *)(tex+20);
    charSize=*(u16 *)(tex+12)*8;
    palOffset=*(u32 *)(tex+0x38);
    palSize=*(u16 *)(tex+0x30)*8;
    dst=(u8 *)CLACT_GetCharacterVramAddress(*(u32 *)(p+0x28),1);
    dst+=(slot<<11);
    DC_FlushRange(tex+palOffset,palSize);
    GXS_LoadOBJPltt(tex+palOffset,slot*32,palSize);
    DC_FlushRange(src,charSize);
    switch(type) {
    case 34: x=2; y=2; type=4; height=4; break;
    case 35: x=2; type=4; height=8; break;
    case 50: x=y; y=2; type=8; height=4; break;
    default: x=2; y=2; type=4; height=4; break;
    }
    for(block=0;block<height;block++) {
        for(line=0;line<8;line++) {
            for(col=0;col<type;col++) {
                GXS_LoadOBJ(src+(col*4+(block*32*type+line*type*4)),(uptr)(dst+(line*4+((col+x)*32+((block+y)*256)))),4);
            }
        }
    }
    GFL_HEAP_Free((void *)blob);
}

void STA_ACT_BUTTON_SetVisible(char *p, unsigned flag)
{
    if (((struct StaActTaskObj *)p)->actorIds[0] != 255) {
        CLACT_SetActorDrawEnable(((struct StaActTaskObj *)p)->frameActors[0], flag);
        CLACT_SetActorDrawEnable(((struct StaActTaskObj *)p)->iconActors[0], flag);
    }
    if (((struct StaActTaskObj *)p)->actorIds[1] != 255) {
        CLACT_SetActorDrawEnable(((struct StaActTaskObj *)p)->frameActors[1], flag);
        CLACT_SetActorDrawEnable(((struct StaActTaskObj *)p)->iconActors[1], flag);
    }
    ((struct StaActTaskObj *)p)->enabled.u = flag;
}
