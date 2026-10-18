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
 *   STA_ACTING_GetCameraTarget 0x021F9E04 thumb ov132
 *   STA_ACTING_GetSelection 0x021F9E18 thumb ov132
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 */
#include "sta_act_light_shared_types.h"

struct Bank;

struct Obj;

/* One character slot of the light unit (32 bytes). value is the actor id
   (0 when the slot is free), color/alpha the RGB555 tint SetElemA writes,
   x/y/z the position in 20.12 fixed point and actor the CLACT handle. */
typedef struct {
    u32 value;            /* 0x00 actor id, 0 when free */
    u16 color;            /* 0x04 RGB555 tint */
    u8 alpha;             /* 0x06 tint alpha */
    u8 pad_07;            /* 0x07 */
    int x;                /* 0x08 position, 20.12 fixed point */
    int y;                /* 0x0C */
    int z;                /* 0x10 */
    int paramA;           /* 0x14 set by SetElemB, never read in decompiled code */
    int paramB;           /* 0x18 set by SetElemB, never read in decompiled code */
    void *actor;          /* 0x1C CLACT actor handle */
} LightActor;

typedef struct { u16 heap,pad; void *a; LightActor entries[4]; u32 flag; u8 pad_8C[0x18]; void *actor; void *bank; u32 palette,character,cellAnim; } Object;

/* The billboard element manager the STA_ACT_OBJ_* functions operate on
   (148 bytes). sta_act_obj.c defines the same object privately. */
typedef struct {
    u32 active;          /* 0x00 */
    u32 dirty;           /* 0x04 */
    int x;               /* 0x08 */
    int y;               /* 0x0C */
    int z;               /* 0x10 */
    int id;              /* 0x14 */
    int index;           /* 0x18 billboard slot index */
} StaActObjEntry;

typedef struct {
    u16 heap;            /* 0x00 */
    u16 count;           /* 0x02 */
    void *board;         /* 0x04 BILLBOARD board */
    StaActObjEntry entries[5]; /* 0x08 */
} StaActObjObject;

extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern signed int CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_ReleasePalette(u32);

extern void CLACT_ReleaseCharacter(u32);

extern void CLACT_ReleaseCellAnim(u32);

extern void CLACT_DeleteUnit(void *);

extern void GFL_HEAP_Free(void *);

extern u16 STA_ACTING_GetCameraTarget(u8 *p);

extern int STA_ACTING_GetSelection(char *p);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const Vec2 *delta, u32 which);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern void *STA_ACTING_GetActorSystem(char *p);

extern void *STA_ACTING_GetActor(char *p, u32 i);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_DeleteActor(struct Obj *p);

void STA_ACT_LIGHT_SetElemVisible(char *p,u32 *q,u32 flag);

Object *STA_ACT_LIGHT_CreateUnit(u16 heap,void *a);

void STA_ACT_LIGHT_DeleteUnit(char *p);

void STA_ACT_LIGHT_UpdateElemActors(char *p);

void STA_ACT_LIGHT_PlaceActor(char *p, char *q);

void STA_ACT_LIGHT_UpdateActor(char *p);

void STA_ACT_LIGHT_NoOp(void);

u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v);

void STA_ACT_LIGHT_DeleteActor(void *unused,u8 *p);

void STA_ACT_LIGHT_CopyElemA(void *unused,u32 *p,const u32 *q);

void STA_ACT_LIGHT_GetElemPos(void *ctx,char *p,Vec3 *out);

void STA_ACT_LIGHT_SetElemA(void *a,char *p,u16 b,u8 c);

void STA_ACT_LIGHT_SetElemB(void *a,char *p,u32 b,u32 c);

void STA_ACT_LIGHT_CopyActorPos(void *unused,u32 *p,u32 *q);

extern const char d_021F8408[];

/*
 * note: True entry includes push {r0-r3}; handed 021F6BC2 is an interior prologue label.
 */
void STA_ACT_LIGHT_SetElemVisible(char *p,u32 *q,u32 flag) {BILLBOARD_SetElemVisible(((StaActObjObject *)p)->board,((StaActObjEntry *)q)->index,&flag);}

Object *STA_ACT_LIGHT_CreateUnit(u16 heap,void *a)
{
    u8 i;
    Object *p;
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
    p->character=CLACT_RegisterCharacter((void *)((u32)q),10,0,0,p->heap);
    p->cellAnim=CLACT_RegisterCellAnim((void *)((u32)q),20,23,p->heap);
    ARC_TOOL_DeleteHandle(q);
    return p;
}

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
void STA_ACT_LIGHT_DeleteUnit(char *p) {CLACT_ReleasePalette(((Object *)p)->palette);CLACT_ReleaseCharacter(((Object *)p)->character);CLACT_ReleaseCellAnim(((Object *)p)->cellAnim);CLACT_DeleteUnit(((Object *)p)->bank);GFL_HEAP_Free(p);}

void STA_ACT_LIGHT_UpdateElemActors(char *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*32+8)) STA_ACT_LIGHT_PlaceActor(p,p+8+i*32); if(*(int *)&((Object *)p)->a) STA_ACT_LIGHT_UpdateActor(p); }

void STA_ACT_LIGHT_PlaceActor(char *p, char *q) {
    u16 n;
    int tmp;
    Vec2 point;
    if (*(int *)&((Object *)p)->a == 0) tmp = 0x80;
    else tmp = STA_ACTING_GetCameraTarget((u8 *)(*(int *)&((Object *)p)->a));
    n = tmp;
    if (((LightActor *)q)->value == 1) {
        point.x = (short)((float)((LightActor *)q)->x / 4096.0f - (float)(unsigned)n);
        point.y = (short)((float)((LightActor *)q)->y / 4096.0f);
        CLACT_AddActorSurfacePos((struct Obj *)((LightActor *)q)->actor, (const Vec2 *)(&point), 0);
        if (*(int *)&((Object *)p)->a != 0 && STA_ACTING_GetSelection((char *)(*(int *)&((Object *)p)->a)) != 4) {
            CLACT_SetActorDrawEnable((struct Obj *)((LightActor *)q)->actor, 0);
            return;
        }
        CLACT_SetActorDrawEnable((struct Obj *)((LightActor *)q)->actor, 1);
    }
}

/*
 * ABI: B294 leaves live r0 which the original stores and passes to B3DC despite its legacy void declaration.
 */
void STA_ACT_LIGHT_UpdateActor(char *p)
{
    Vec3 v;
    Desc d;
    void *a;
    char *ctx;
    char *model;
    u16 n;
    if(((Object *)p)->flag==0 && STA_ACTING_GetSelection(*(char * *)&((Object *)p)->a)!=4) {
        ((Object *)p)->flag=1;
        d.shape.x=128;
        d.shape.y=96;
        d.shape.z=0;
        d.shape.a=0;
        d.shape.b=2;
        a=CLACT_CreateActor(((Object *)p)->bank,((Object *)p)->character,((Object *)p)->palette,((Object *)p)->cellAnim,&d.shape.x,0,((Object *)p)->heap);
        ((Object *)p)->actor=a;
        CLACT_SetActorDrawEnable(a,1);
    }
    if(((Object *)p)->flag==1) {
        if(STA_ACTING_GetSelection(*(char * *)&((Object *)p)->a)==4) {
            CLACT_DeleteActor(((Object *)p)->actor);
            ((Object *)p)->flag=0;
            return;
        }
        ctx=STA_ACTING_GetActorSystem(((Object *)p)->a);
        model=STA_ACTING_GetActor(((Object *)p)->a,STA_ACTING_GetSelection(*(char * *)&((Object *)p)->a));
        n=STA_ACTING_GetCameraTarget(((Object *)p)->a);
        STA_ACT_LIGHT_CopyActorPos(ctx,(u32 *)model,(u32 *)(&v));
        d.pos.x=(short)((float)v.x/4096.0f-(float)(unsigned)n);
        d.pos.y=(short)((float)v.y/4096.0f-32.0f);
        CLACT_AddActorSurfacePos(((Object *)p)->actor,(const Vec2 *)(&d.pos),0);
    }
}

void STA_ACT_LIGHT_NoOp(void) { }

u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v)
{
    u8 i = 0;
    u8 *q;
    Pos pos;
    struct Obj *o;
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
    o = CLACT_CreateActor(*(void **)(p + 0xa8), *(u32 *)(p + 0xb0), *(u32 *)(p + 0xac), *(u32 *)(p + 0xb4), &pos, 0, *(u16 *)p);
    *(struct Obj **)(q + 0x1c) = o;
    CLACT_SetActorDrawEnable(o, 1);
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
void STA_ACT_LIGHT_GetElemPos(void *ctx,char *p,Vec3 *out)
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
