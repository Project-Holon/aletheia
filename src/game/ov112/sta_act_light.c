/*
 * file:     sta_act_light.c
 * unit:     yes
 * function: STA_ACT_LIGHT_SetElemVisible, STA_ACT_LIGHT_CreateUnit, STA_ACT_LIGHT_DeleteUnit, STA_ACT_LIGHT_UpdateElemActors, STA_ACT_LIGHT_PlaceActor, STA_ACT_LIGHT_UpdateActor, STA_ACT_LIGHT_NoOp, STA_ACT_LIGHT_CreateActor, STA_ACT_LIGHT_DeleteActor, STA_ACT_LIGHT_CopyElemA, STA_ACT_LIGHT_GetElemPos, STA_ACT_LIGHT_SetElemA, STA_ACT_LIGHT_SetElemB
 * address:  0x021F6BC0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_act_light.c by tools/splitfile.py.
 *
 * symbols:
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021F8408 0x021F8408 data a4
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STA_ACTING_GetCameraScrollX 0x021F9E04 thumb ov132
 *   STA_ACTING_GetSelection 0x021F9E18 thumb ov132
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _ffltu                       0x0209BE04  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "sta_act_types.h"
#include "sta_act_light_shared_types.h"

struct Bank;

struct ClactActor;

struct BbBoard;

#include "../arm9/billboard.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/clact.h"


#include "../arm9/arc_tool.h"










#include "../ov132/sta_acting.h"


struct Actor;






void STA_ACT_LIGHT_SetElemVisible(char *p,u32 *q,u32 flag);

StaActLightObject *STA_ACT_LIGHT_CreateUnit(u16 heap,void *a);

void STA_ACT_LIGHT_DeleteUnit(char *p);

void STA_ACT_LIGHT_UpdateElemActors(char *p);

void STA_ACT_LIGHT_PlaceActor(char *p, char *q);

void STA_ACT_LIGHT_UpdateActor(char *p);

void STA_ACT_LIGHT_NoOp(void *unit);

u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v);

void STA_ACT_LIGHT_DeleteActor(void *unused,u8 *p);

void STA_ACT_LIGHT_CopyElemA(void *unused,u32 *p,const u32 *q);

void STA_ACT_LIGHT_GetElemPos(void *ctx,char *p,StaActLightVec3 *out);

void STA_ACT_LIGHT_SetElemA(void *a,char *p,u16 b,u8 c);

void STA_ACT_LIGHT_SetElemB(void *a,char *p,u32 b,u32 c);

#include "sta_act_poke.h"

extern const char d_021F8408[];

/*
 * note: True entry includes push {r0-r3}; handed 021F6BC2 is an interior prologue label.
 */
void STA_ACT_LIGHT_SetElemVisible(char *p,u32 *q,u32 flag) {BILLBOARD_SetElemVisible(((StaActObjObject *)p)->board,((StaActObjEntry *)q)->index,&flag);}

StaActLightObject *STA_ACT_LIGHT_CreateUnit(u16 heap,void *a)
{
    u8 i;
    StaActLightObject *p;
    void *q;
    i=0;
    p=GFL_HEAP_Alloc(heap,184,0,d_021F8408,87);
    p->heap=heap; p->a=a;
    for(;i<4;i++) p->entries[i].value=0;
    p->flag=0;
    p->bank=CLACT_CreateUnit(5,0,p->heap);
    CLACT_SetUnitDefaultRenderer(p->bank);
    q=ARC_TOOL_CreateHandle((unsigned int)47,p->heap);
    p->palette=CLACT_RegisterPalette((void *)q,4,0,0,p->heap);
    p->character=CLACT_RegisterCharacter((void *)((uptr)q),10,0,0,p->heap);
    p->cellAnim=CLACT_RegisterCellAnim((void *)((uptr)q),20,23,p->heap);
    ARC_TOOL_DeleteHandle(q);
    return p;
}

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
void STA_ACT_LIGHT_DeleteUnit(char *p) {CLACT_ReleasePalette(((StaActLightObject *)p)->palette);CLACT_ReleaseCharacter(((StaActLightObject *)p)->character);CLACT_ReleaseCellAnim(((StaActLightObject *)p)->cellAnim);CLACT_DeleteUnit(((StaActLightObject *)p)->bank);GFL_HEAP_Free(p);}

void STA_ACT_LIGHT_UpdateElemActors(char *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*32+8)) STA_ACT_LIGHT_PlaceActor(p,p+8+i*32); if(*(int *)&((StaActLightObject *)p)->a) STA_ACT_LIGHT_UpdateActor(p); }

void STA_ACT_LIGHT_PlaceActor(char *p, char *q) {
    u16 n;
    int tmp;
    StaActLightVec2 point;
    if (*(int *)&((StaActLightObject *)p)->a == 0) tmp = 0x80;
    else tmp = STA_ACTING_GetCameraScrollX((u8 *)(*(int *)&((StaActLightObject *)p)->a));
    n = tmp;
    if (((LightActor *)q)->value == 1) {
        point.x = (short)((float)((LightActor *)q)->x / 4096.0f - (float)(unsigned)n);
        point.y = (short)((float)((LightActor *)q)->y / 4096.0f);
        CLACT_AddActorSurfacePos((struct ClactActor *)((LightActor *)q)->actor, (const struct ClactVec2 *)((const StaActLightVec2 *)(&point)), 0);
        if (*(int *)&((StaActLightObject *)p)->a != 0 && STA_ACTING_GetSelection((char *)(*(int *)&((StaActLightObject *)p)->a)) != 4) {
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((LightActor *)q)->actor), 0);
            return;
        }
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Actor *)((LightActor *)q)->actor), 1);
    }
}

/*
 * ABI: B294 leaves live r0 which the original stores and passes to B3DC despite its legacy void declaration.
 */
void STA_ACT_LIGHT_UpdateActor(char *p)
{
    StaActLightVec3 v;
    StaActLightDesc d;
    void *a;
    char *ctx;
    char *model;
    u16 n;
    if(((StaActLightObject *)p)->flag==0 && STA_ACTING_GetSelection(*(char * *)&((StaActLightObject *)p)->a)!=4) {
        ((StaActLightObject *)p)->flag=1;
        d.shape.x=128;
        d.shape.y=96;
        d.shape.z=0;
        d.shape.a=0;
        d.shape.b=2;
        a=CLACT_CreateActor(((StaActLightObject *)p)->bank,((StaActLightObject *)p)->character,((StaActLightObject *)p)->palette,((StaActLightObject *)p)->cellAnim,(const struct ActorInitParam *)&d.shape.x,0,((StaActLightObject *)p)->heap);
        ((StaActLightObject *)p)->actor=a;
        CLACT_SetActorDrawEnable(a,1);
    }
    if(((StaActLightObject *)p)->flag==1) {
        if(STA_ACTING_GetSelection(*(char * *)&((StaActLightObject *)p)->a)==4) {
            CLACT_DeleteActor(((StaActLightObject *)p)->actor);
            ((StaActLightObject *)p)->flag=0;
            return;
        }
        ctx=STA_ACTING_GetActorSystem(((StaActLightObject *)p)->a);
        model=STA_ACTING_GetActor(((StaActLightObject *)p)->a,STA_ACTING_GetSelection(*(char * *)&((StaActLightObject *)p)->a));
        n=STA_ACTING_GetCameraScrollX(((StaActLightObject *)p)->a);
        STA_ACT_LIGHT_CopyActorPos(ctx,(u32 *)model,(u32 *)(&v));
        d.pos.x=(short)((float)v.x/4096.0f-(float)(unsigned)n);
        d.pos.y=(short)((float)v.y/4096.0f-32.0f);
        CLACT_AddActorSurfacePos((struct ClactActor *)(((StaActLightObject *)p)->actor),(const struct ClactVec2 *)((const StaActLightVec2 *)(&d.pos)),0);
    }
}

void STA_ACT_LIGHT_NoOp(void *unit) { }

u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v)
{
    u8 i = 0;
    u8 *q;
    StaActLightPos pos;
    struct ClactActor *o;
    do {
        if (*(u32 *)(p + i * 32 + 8) == 0) break;
        i++;
    } while (i < 4);
    *(u32 *)(p + 8 + i * 32) = v;
    q = p + 8 + i * 32;
    pos.x = 0x80;
    pos.y = 0x60;
    pos.z = 0;
    pos.a = 0;
    pos.b = 2;
    o = CLACT_CreateActor(*(void **)(p + 0xa8), *(u32 *)(p + 0xb0), *(u32 *)(p + 0xac), *(u32 *)(p + 0xb4), (const struct ActorInitParam *)&pos, 0, *(u16 *)p);
    *(struct ClactActor **)(q + 0x1c) = o;
    CLACT_SetActorDrawEnable((struct ClactActor *)o, 1);
    return q;
}

void STA_ACT_LIGHT_DeleteActor(void *unused,u8 *p) { CLACT_DeleteActor(((LightActor *)p)->actor); ((LightActor *)p)->value=0; }

/*
 * extent: two zero padding bytes then existing STA_ACT_LIGHT_GetElemPos, 021F6F14, 021F6F1C sources and shards.
 */
void STA_ACT_LIGHT_CopyElemA(void *unused,u32 *p,const u32 *q) { p[2]=q[0]; p[3]=q[1]; p[4]=q[2]; }

/*
 * extent: trailing zero halfword at 021F6F12 is alignment padding.
 */
void STA_ACT_LIGHT_GetElemPos(void *ctx,char *p,StaActLightVec3 *out)
{
    out->x=((LightActor *)p)->x;
    out->y=((LightActor *)p)->y;
    out->z=((LightActor *)p)->z;
}

void STA_ACT_LIGHT_SetElemA(void *a,char *p,u16 b,u8 c)
{
    ((LightActor *)p)->color=b;
    ((LightActor *)p)->alpha=c;
}

void STA_ACT_LIGHT_SetElemB(void *a,char *p,u32 b,u32 c)
{
    ((LightActor *)p)->paramA=b;
    ((LightActor *)p)->paramB=c;
}
