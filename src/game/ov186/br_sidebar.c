/*
 * file:     br_sidebar.c
 * unit:     yes
 * function: BR_SIDEBAR_Create, BR_SIDEBAR_Destroy, BR_SIDEBAR_Update, BR_SIDEBAR_StartBounce, BR_SIDEBAR_StartWobble, BR_SIDEBAR_StartSlide, BR_SIDEBAR_ResetPositions, BR_SIDEBAR_SetVisibleBySpace, BR_SIDEBAR_InitSlot, BR_SIDEBAR_DestroySlot, BR_SIDEBAR_UpdateSlot, BR_SIDEBAR_IsSlotActive, BR_SIDEBAR_SetSlotVisible, BR_SIDEBAR_SetSlotMode, BR_SIDEBAR_ResetSlot, BR_SIDEBAR_UpdateBounce, BR_SIDEBAR_UpdateWobble, BR_SIDEBAR_UpdateSlide
 * address:  0x021FED50
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, ov186_func_02200228.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_SIDEBAR_Create 0x021FED50 thumb ov186
 *   BR_SIDEBAR_ResetPositions 0x021FEE9C thumb ov186
 *   BR_SIDEBAR_StartWobble 0x021FEE4C thumb ov186
 *   BR_SIDEBAR_Destroy 0x021FEDC4 thumb ov186
 *   BR_SIDEBAR_Update 0x021FEE00 thumb ov186
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_SIDEBAR_InitSlot 0x021FEEF4 thumb ov186
 *   gBrSidebarSourceFile 0x02200D78 data a1
 *   gBrSidebarConfigTable 0x02200B74 data a4
 *   BR_SIDEBAR_IsSlotActive 0x021FF028 thumb ov186
 *   BR_SIDEBAR_DestroySlot 0x021FF004 thumb ov186
 *   BR_SIDEBAR_UpdateSlot 0x021FF01C thumb ov186
 *   BR_SIDEBAR_SetSlotMode 0x021FF038 thumb ov186
 *   BR_SIDEBAR_ResetSlot 0x021FF074 thumb ov186
 *   BR_SIDEBAR_SetSlotVisible 0x021FF02C thumb ov186
 *   SAVEDATA_PanicFail 0x02034714 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorScaleAxis 0x0204B5D4 arm
 *   gBrSidebarAssertString 0x02200D88 data a4
 *   CLACT_SetActorSurfacePosAxis 0x0204B49C arm
 *   CLACT_GetActorSurfacePosAxis 0x0204B4EC arm
 *   GF_STANDARD_Get_F684 0x0203F684 arm
 *   CLACT_GetActorScaleAxis 0x0204B5E4 arm
 */
#include "br_types.h"

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *p);

extern void CLACT_DeleteActor(struct Actor *actor);

extern void * MI_CpuFill8(void *,u32,u32);

extern void BR_RES_LoadSprite(struct BrRes *res, u32 spriteIndex, u32 heapId);

extern int BR_RES_GetSprite(struct BrRes *res, unsigned spriteIndex, struct BrResSprite *outSprite);

extern void BR_RES_ReleaseSprite(struct BrRes *res, unsigned spriteIndex);

extern void SAVEDATA_PanicFail(const char *,u32,const char *);

extern struct Actor *CLACT_CreateActor(struct Bank *unit, u32 charId, u32 paletteId, u32 cellAnimId, const struct BrActorPos *pos, u16 space, u16 heapId);

extern void CLACT_SetActorAffineMode(struct Actor *,u32);

extern void CLACT_SetActorScaleAxis(struct Actor *actor, u32 scale, u32 axis);

extern void CLACT_SetActorObjMode(struct Actor *,u32);

extern void CLACT_SetActorDrawEnable(struct Actor *,u32);

extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);

extern s16 CLACT_GetActorSurfacePosAxis(struct Actor *actor, u32 space, u32 axis);

extern s16 GF_STANDARD_Get_F684(u16);

extern u32 CLACT_GetActorScaleAxis(const struct Actor *actor, u32 which);

extern const char gBrSidebarSourceFile[];

extern const struct BrSidebarConfig gBrSidebarConfigTable[BR_SIDEBAR_SLOT_COUNT];

extern const char gBrSidebarAssertString[];

struct BrSidebar *BR_SIDEBAR_Create(struct Bank *unit, int unused, struct BrRes *res, u16 heapId);

void BR_SIDEBAR_Destroy(struct BrSidebar *sidebar, struct BrRes *res);

void BR_SIDEBAR_Update(struct BrSidebar *sidebar);

void BR_SIDEBAR_StartBounce(struct BrSidebar *sidebar);

void BR_SIDEBAR_StartWobble(struct BrSidebar *sidebar);

void BR_SIDEBAR_StartSlide(struct BrSidebar *sidebar);

void BR_SIDEBAR_ResetPositions(struct BrSidebar *sidebar);

void BR_SIDEBAR_SetVisibleBySpace(struct BrSidebar *sidebar, int space, u32 visible);

void BR_SIDEBAR_InitSlot(struct BrSidebarSlot *slot, struct Bank *unit, struct BrRes *res, const struct BrSidebarConfig *config, u16 heapId);

void BR_SIDEBAR_DestroySlot(struct BrSidebarSlot *slot);

void BR_SIDEBAR_UpdateSlot(struct BrSidebarSlot *slot);

int BR_SIDEBAR_IsSlotActive(struct BrSidebarSlot *slot);

void BR_SIDEBAR_SetSlotVisible(struct BrSidebarSlot *slot, u32 visible);

void BR_SIDEBAR_SetSlotMode(struct BrSidebarSlot *slot, u32 mode);

void BR_SIDEBAR_ResetSlot(struct BrSidebarSlot *slot);

void BR_SIDEBAR_UpdateBounce(struct BrSidebarSlot *slot);

void BR_SIDEBAR_UpdateWobble(struct BrSidebarSlot *slot);

void BR_SIDEBAR_UpdateSlide(struct BrSidebarSlot *slot);

typedef char BrSidebarCheckSlot[sizeof(struct BrSidebarSlot) == 0x4C ? 1 : -1];
typedef char BrSidebarCheckConfig[sizeof(struct BrSidebarConfig) == 24 ? 1 : -1];

struct BrSidebar *BR_SIDEBAR_Create(struct Bank *unit, int unused, struct BrRes *res, u16 heapId)
{
    struct BrSidebar *sidebar = GFL_HEAP_Alloc(heapId, sizeof(struct BrSidebar), 0, gBrSidebarSourceFile, 0x132);
    int i;
    MI_CpuFill8(sidebar, 0, sizeof(struct BrSidebar));
    BR_RES_LoadSprite(res, 4, heapId);
    BR_RES_LoadSprite(res, 5, heapId);
    for (i = 0; i < BR_SIDEBAR_SLOT_COUNT; i++)
        BR_SIDEBAR_InitSlot(&sidebar->slot[i], unit, res, &gBrSidebarConfigTable[i], heapId);
    return sidebar;
}

void BR_SIDEBAR_Destroy(struct BrSidebar *sidebar, struct BrRes *res)
{
    int i;
    for(i=0;i<BR_SIDEBAR_SLOT_COUNT;i++)
        if(BR_SIDEBAR_IsSlotActive(&sidebar->slot[i]))
            BR_SIDEBAR_DestroySlot(&sidebar->slot[i]);
    BR_RES_ReleaseSprite(res,4);
    BR_RES_ReleaseSprite(res,5);
    GFL_HEAP_Free(sidebar);
}

void BR_SIDEBAR_Update(struct BrSidebar *sidebar)
{
    int i;
    for(i=0;i<BR_SIDEBAR_SLOT_COUNT;i++)
        if(BR_SIDEBAR_IsSlotActive(&sidebar->slot[i]))
            BR_SIDEBAR_UpdateSlot(&sidebar->slot[i]);
}

/*
 * extent: two zero alignment bytes at 0x021FEE4A follow; no follower.
 */
void BR_SIDEBAR_StartBounce(struct BrSidebar *sidebar)
{
    int i;
    for(i=0;i<BR_SIDEBAR_SLOT_COUNT;i++)
        if(BR_SIDEBAR_IsSlotActive(&sidebar->slot[i]))
            BR_SIDEBAR_SetSlotMode(&sidebar->slot[i],1);
}

/*
 * extent: two zero alignment bytes at 0x021FEE72 follow; no follower.
 */
void BR_SIDEBAR_StartWobble(struct BrSidebar *sidebar)
{
    int i;
    for(i=0;i<BR_SIDEBAR_SLOT_COUNT;i++)
        if(BR_SIDEBAR_IsSlotActive(&sidebar->slot[i]))
            BR_SIDEBAR_SetSlotMode(&sidebar->slot[i],2);
}

/*
 * extent: two zero alignment bytes at 0x021FEE9A follow; no follower.
 */
void BR_SIDEBAR_StartSlide(struct BrSidebar *sidebar)
{
    int i;
    for(i=0;i<BR_SIDEBAR_SLOT_COUNT;i++)
        if(BR_SIDEBAR_IsSlotActive(&sidebar->slot[i]))
            BR_SIDEBAR_SetSlotMode(&sidebar->slot[i],3);
}

void BR_SIDEBAR_ResetPositions(struct BrSidebar *sidebar)
{
    int i;
    for(i=0;i<BR_SIDEBAR_SLOT_COUNT;i++)
        if(BR_SIDEBAR_IsSlotActive(&sidebar->slot[i]))
            BR_SIDEBAR_ResetSlot(&sidebar->slot[i]);
}

void BR_SIDEBAR_SetVisibleBySpace(struct BrSidebar *sidebar, int space, u32 visible)
{
    int i;
    for(i=0;i<BR_SIDEBAR_SLOT_COUNT;i++)
        if(space==gBrSidebarConfigTable[i].space)
            BR_SIDEBAR_SetSlotVisible(&sidebar->slot[i],visible);
}

static inline int toFixed12(int x)
{
    float f;
    if(x>0)f=0.5f+(float)(x<<12);
    else f=(float)(x<<12)-0.5f;
    return (int)f;
}

/*
 * ABI: CLACT_CreateActor returns the allocated object pointer in r0.
 */
void BR_SIDEBAR_InitSlot(struct BrSidebarSlot *slot, struct Bank *unit, struct BrRes *res, const struct BrSidebarConfig *config, u16 heapId)
{
    struct BrResSprite sprite;
    struct BrActorPos pos;
    int spriteIndex;
    MI_CpuFill8(slot,0,sizeof(struct BrSidebarSlot));
    slot->config=*config;
    spriteIndex=4;
    if(config->space)spriteIndex=5;
    if(!BR_RES_GetSprite(res,spriteIndex,&sprite))SAVEDATA_PanicFail(gBrSidebarAssertString,0,gBrSidebarAssertString);
    MI_CpuFill8(&pos,0,sizeof(pos));
    pos.x=config->x;
    pos.y=config->y;
    pos.bgPriority=1;
    slot->baseX=toFixed12(pos.x);
    slot->baseY=toFixed12(pos.y);
    slot->scale=config->scale;
    slot->actor=CLACT_CreateActor(unit,sprite.charId,sprite.paletteId,sprite.cellAnimId,&pos,slot->config.space,heapId);
    CLACT_SetActorAffineMode(slot->actor,2);
    CLACT_SetActorScaleAxis(slot->actor,slot->scale,0);
    CLACT_SetActorObjMode(slot->actor,0);
    CLACT_SetActorDrawEnable(slot->actor,0);
    slot->active=1;
}

void BR_SIDEBAR_DestroySlot(struct BrSidebarSlot *slot)
{
    CLACT_DeleteActor(slot->actor);
    MI_CpuFill8(slot,0,76);
}

void BR_SIDEBAR_UpdateSlot(struct BrSidebarSlot *slot)
{
    BrSidebarUpdateFunc update;
    update=slot->update;
    if(update)update(slot);
}

int BR_SIDEBAR_IsSlotActive(struct BrSidebarSlot *slot)
{
    return slot->active;
}

void BR_SIDEBAR_SetSlotVisible(struct BrSidebarSlot *slot, u32 visible)
{
    CLACT_SetActorDrawEnable(slot->actor,visible);
}

void BR_SIDEBAR_SetSlotMode(struct BrSidebarSlot *slot, u32 mode)
{
    switch(mode){
    case 0:slot->update=0;break;
    case 1:slot->update=BR_SIDEBAR_UpdateBounce;break;
    case 2:slot->update=BR_SIDEBAR_UpdateWobble;break;
    case 3:slot->update=BR_SIDEBAR_UpdateSlide;break;
    }
    slot->state=0;
}

/* Space is explicitly truncated to u16 at the original call. */
void BR_SIDEBAR_ResetSlot(struct BrSidebarSlot *slot)
{
    slot->scale=410;
    CLACT_SetActorSurfacePosAxis(slot->actor,slot->config.restX,(u16)(slot->config.space),0);
    CLACT_SetActorScaleAxis(slot->actor,slot->scale,0);
}

void BR_SIDEBAR_UpdateBounce(struct BrSidebarSlot *slot)
{
    int direction;
    s16 x;
    float value;
    slot->tick=(slot->tick+1)%2;
    if(slot->tick!=0)return;
    switch(slot->state){
    case 0:
        CLACT_SetActorDrawEnable(slot->actor,1);
        slot->counter=0;
        slot->scale=slot->config.scale;
        slot->state=1;
        break;
    case 1:
        if(slot->counter==3){
            slot->state=2;
            if(CLACT_GetActorSurfacePosAxis(slot->actor,(u16)(slot->config.space),0)>0)
                value=0.5f+(float)(CLACT_GetActorSurfacePosAxis(slot->actor,(u16)(slot->config.space),0)<<12);
            else
                value=(float)(CLACT_GetActorSurfacePosAxis(slot->actor,(u16)(slot->config.space),0)<<12)-0.5f;
            slot->posFixed=(int)value;
            slot->counter=0;
        }else (slot->counter)++;
        break;
    case 2:
        direction=-1;
        if(slot->config.reverse!=0)direction=1;
        direction=(signed char)direction;
        if(slot->counter==4){
            slot->state=3;
            slot->counter=0;
        }else{
            slot->posFixed+=-direction*GF_STANDARD_Get_F684(slot->angle*65535/360);
            slot->angle+=32;
            slot->angle%=360;
            CLACT_SetActorSurfacePosAxis(slot->actor,slot->posFixed>>12,(u16)(slot->config.space),0);
            (slot->counter)++;
        }
        break;
    case 3:
        x=CLACT_GetActorSurfacePosAxis(slot->actor,(u16)(slot->config.space),0);
        if(slot->counter==0){
            slot->stepPos=slot->config.restX-x;
            slot->stepPos/=slot->config.duration;
            (slot->counter)++;
        }else if(slot->counter==slot->config.duration+1){
            x=slot->config.restX;
            slot->state=4;
        }else{
            x+=(s16)slot->stepPos;
            (slot->counter)++;
        }
        CLACT_SetActorSurfacePosAxis(slot->actor,x,(u16)(slot->config.space),0);
        break;
    case 4:BR_SIDEBAR_SetSlotMode(slot,2);break;
    }
    if(slot->state==3){
        if(slot->scale>410){
            slot->scale-=410;
            CLACT_SetActorScaleAxis(slot->actor,slot->scale,0);
        }
    }
}

/*
 * Lever: int direction with explicit signed-char cast at use retains the original lsls/asrs byte truncation; a signed-char local folds it away and compiles 232/236 bytes.
 * Width: original caller truncates space and sine arguments to u16; full callee signatures otherwise copied.
 */
void BR_SIDEBAR_UpdateWobble(struct BrSidebarSlot *slot)
{
    int direction;
    int position;
    float value;
    slot->tick=(slot->tick+1)%2;
    if(slot->tick!=0)return;
    switch(slot->state){
    case 0:
        CLACT_SetActorDrawEnable(slot->actor,1);
        CLACT_SetActorSurfacePosAxis(slot->actor,slot->config.restX,(u16)(slot->config.space),0);
        if(slot->config.restX>0)value=0.5f+(float)(slot->config.restX<<12);
        else value=(float)(slot->config.restX<<12)-0.5f;
        slot->posFixed=(int)value;
        slot->angle=slot->config.phase;
        slot->state=1;
        break;
    case 1:
        direction=-1;
        if(slot->config.reverse!=0)direction=1;
        position=slot->posFixed+-(signed char)direction*(GF_STANDARD_Get_F684((u16)(slot->angle*65535/360))*3);
        slot->angle+=slot->config.phaseStep;
        slot->angle%=360;
        CLACT_SetActorSurfacePosAxis(slot->actor,position>>12,(u16)(slot->config.space),0);
        break;
    }
    if(slot->scale>410){
        slot->scale-=410;
        CLACT_SetActorScaleAxis(slot->actor,slot->scale,0);
    }
}

/*
 * Verified blocker C: one --arm without region, fixed compiler/flags/lang, EXACT 16 (scratch b5e4.c and b5e4-verify.log).
 * typedef unsigned long u32;
 * typedef struct { char pad[0x14]; u32 a; u32 b; } Actor;
 * u32 CLACT_GetActorScaleAxis(const Actor *p,u32 which)
 * { if(which==0)return p->a; else return p->b; }
 * Width: space argument truncated by original caller to u16 despite callee u32.
 */
void BR_SIDEBAR_UpdateSlide(struct BrSidebarSlot *slot)
{
    s16 x;
    u32 y;
    slot->tick=(slot->tick+1)%2;
    if(slot->tick!=0)return;
    switch(slot->state){
    case 0:
        CLACT_SetActorDrawEnable(slot->actor,1);
        slot->counter=0;
        slot->state=1;
        break;
    case 1:
        x=CLACT_GetActorSurfacePosAxis(slot->actor,(u16)(slot->config.space),0);
        y=CLACT_GetActorScaleAxis(slot->actor,0);
        if(slot->counter==0){
            slot->stepPos=slot->config.x-x;
            slot->stepPos/=slot->config.duration;
            (slot->counter)++;
            slot->stepScale=slot->config.scale-y;
            slot->stepScale/=slot->config.duration;
        }else if(slot->counter==slot->config.duration+1){
            x=slot->config.x;
            y=slot->config.scale;
            slot->state=2;
        }else{
            x+=(s16)slot->stepPos;
            y+=slot->stepScale;
            (slot->counter)++;
        }
        CLACT_SetActorSurfacePosAxis(slot->actor,x,(u16)(slot->config.space),0);
        CLACT_SetActorScaleAxis(slot->actor,y,0);
        break;
    case 2:BR_SIDEBAR_SetSlotMode(slot,0);break;
    }
}
