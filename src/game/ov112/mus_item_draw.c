/*
 * file:     mus_item_draw.c
 * unit:     yes
 * function: MUSICAL_MCSS_CreateActorPool, MUSICAL_MCSS_DeleteActorPool, MUSICAL_MCSS_UpdateObject, MUSICAL_MCSS_NoOp3, MUSICAL_MCSS_GetArcFileCount, MUSICAL_MCSS_SetupObject, MUSICAL_MCSS_IsElemModeSupportedA, MUSICAL_MCSS_IsElemModeSupportedB, MUSICAL_MCSS_IsElemModeSupportedC, MUSICAL_MCSS_ElemHasAltDepth, MUSICAL_MCSS_ElemKeepsFlippedHeight, MUSICAL_MCSS_CreateResourceArc, MUSICAL_MCSS_FreeResourceArc, MUSICAL_MCSS_FindFreeActorIndex, MUSICAL_MCSS_AddImage, MUSICAL_MCSS_AddImageNoVram, MUSICAL_MCSS_AddElem, MUSICAL_MCSS_FreeElem, MUSICAL_MCSS_FreeElemImage, MUSICAL_MCSS_TransferVram, MUSICAL_MCSS_CopyElem, MUSICAL_MCSS_SetElemVisible, MUSICAL_MCSS_SetElemPos, MUSICAL_MCSS_SetElemScale, MUSICAL_MCSS_SetElemRotZ, MUSICAL_MCSS_SetElemRot, MUSICAL_MCSS_SetElemField, MUSICAL_MCSS_GetElemField, MUSICAL_MCSS_SetElemFlag, MUSICAL_MCSS_GetElemFlag, MUSICAL_MCSS_GetElemOffset, MUSICAL_MCSS_GetActorPoolResource
 * address:  0x021F48C0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from musical_shot_sys.c, musical_mcss.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MUSICAL_MCSS_DeleteActorPool 0x021F4948 thumb ov112
 *   MUSICAL_MCSS_CreateActorPool 0x021F48C0 thumb ov112
 *   d_021F83A4 0x021F83A4 data a1
 *   NNS_GfdResetVramTransferTaskQueue 0x02061C30 arm
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   BILLBOARD_SetElemScale 0x0204F684 arm
 *   BILLBOARD_SetElemRotZ 0x0204F7C4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   ARC_TOOL_GetArchiveFileCount 0x02049030 arm
 *   BILLBOARD_GetImageSizeFromFlags 0x0204EDD0 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   BILLBOARD_AddImage 0x0204EF58 arm
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   d_021F8300 0x021F8300 data a4
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_ReleaseImageVramIfUsed 0x0204F1A0 arm
 *   BILLBOARD_SetElemId 0x0204F604 arm
 *   BILLBOARD_GetImagePlttVramOffset 0x0204F2CC arm
 *   BILLBOARD_GetImagePlttKey 0x0204F32C arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   MUSICAL_MCSS_LoadActorData 0x021F4F14 thumb ov112
 *   MUSICAL_MCSS_FreeActorData 0x021F4F40 thumb ov112
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_GetOffset 0x021F4F60 thumb ov112
 *   MUSICAL_MCSS_GetElemSizeFlags 0x021F4F70 thumb ov112
 *   MUSICAL_MCSS_IsModeSupportedA 0x021F4F74 thumb ov112
 *   MUSICAL_MCSS_IsModeSupportedB 0x021F4FF4 thumb ov112
 *   MUSICAL_MCSS_IsModeSupportedC 0x021F5064 thumb ov112
 *   MUSICAL_MCSS_ElemDataHasAltDepth 0x021F50D0 thumb ov112
 *   MUSICAL_MCSS_ElemDataKeepsFlippedHeight 0x021F50E0 thumb ov112
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm  arm9
 */
#include "musical_shot_sys_shared_types.h"
#include "mus_shot_photo_shared_types.h"
#include "mus_shot_info_shared_types.h"
#include "mus_item_draw_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

struct Manager0204F684;

struct Tagged;

struct BbBoard;

/* One actor-pool element (0x24 bytes; the stride passed to the pool allocator).
   MUSICAL_MCSS_AddElem fills it, MUSICAL_MCSS_UpdateObject consumes it. */
typedef struct McssActorElem {
    union {
        u16 flags;
        struct {
            u16 active : 1;
            u16 dirty : 1;
            u16 rotate : 1;
            u16 vramTransferred : 1;
            u16 vramInUse : 1;
            u16 rest : 11;
        } bits;
    };
    u16 angle;              /* 0x02 rotation angle (generic field for SetElemField) */
    u32 id;                 /* 0x04 billboard image id */
    u32 index;              /* 0x08 billboard element index */
    u32 type;               /* 0x0C archive file index */
    int x;                  /* 0x10 */
    int y;                  /* 0x14 */
    int z;                  /* 0x18 */
    s16 a;                  /* 0x1C rotation component */
    s16 b;                  /* 0x1E rotation component */
    u8 *data;               /* 0x20 elem data table row */
} McssActorElem;

/* The actor pool built by MUSICAL_MCSS_CreateActorPool (0x34-byte header plus
   count elements of 0x24 bytes). owner/board and the element array are read
   through different views at the same offsets. */
typedef struct McssActorPool {
    u16 heap;               /* 0x00 */
    u16 pad_2;              /* 0x02 */
    union {
        u32 owner;
        void *board;
    };                      /* 0x04 */
    McssActorElem *entries; /* 0x08 count elements of 0x24 bytes */
    void *resource;         /* 0x0C elem data table wrapper */
    u16 count;              /* 0x10 */
    u16 slots[16];          /* 0x12 */
} McssActorPool;

typedef struct { u8 x,y; s16 b,a; } Scale;

struct Trip { u32 a,b,c; };

typedef struct { u8 x,y; } MusItemDrawPair;


#include "../arm9/nns_gfd_vram_load.h"

#include "../arm9/billboard.h"



#include "../arm9/arc_tool.h"

struct G3dResource;

#include "../arm9/g3d_system.h"










#include "../arm9/nns_gfd_vram_transfer.h"

McssActorPool *MUSICAL_MCSS_CreateActorPool(u32 owner,int count,u16 heap);

void MUSICAL_MCSS_DeleteActorPool(u8 *p);

void MUSICAL_MCSS_UpdateObject(McssActorPool *p);

void MUSICAL_MCSS_NoOp3(void *unused);

u16 MUSICAL_MCSS_GetArcFileCount(int i);

void MUSICAL_MCSS_SetupObject(u8 *p,u8 *a,u8 *b);

int MUSICAL_MCSS_IsElemModeSupportedA(u8 *p, int index);

int MUSICAL_MCSS_IsElemModeSupportedB(u8 *p,int index,int mode);

int MUSICAL_MCSS_IsElemModeSupportedC(u8 *p,int index,int mode);

int MUSICAL_MCSS_ElemHasAltDepth(u8 *p);

int MUSICAL_MCSS_ElemKeepsFlippedHeight(u8 *p);

void *MUSICAL_MCSS_CreateResourceArc(int type);

void MUSICAL_MCSS_FreeResourceArc(struct Tagged *resourceArc);

u16 MUSICAL_MCSS_FindFreeActorIndex(McssActorPool *p);

McssActorElem *MUSICAL_MCSS_AddImage(McssActorPool *p,int type,struct G3dResource *id,int *v);

McssActorElem *MUSICAL_MCSS_AddImageNoVram(McssActorPool *p, int type, u32 id, int *v);

McssActorElem *MUSICAL_MCSS_AddElem(McssActorPool *p, u16 index, int *v, s16 a, s16 b);

void MUSICAL_MCSS_FreeElem(u8 *p,u8 *e);

void MUSICAL_MCSS_FreeElemImage(u8 *p, u8 *e, int type, u16 id);

void MUSICAL_MCSS_TransferVram(char *p, char *e, void *unused);

void MUSICAL_MCSS_CopyElem(void *unused, u8 *s, u8 *d);

void MUSICAL_MCSS_SetElemVisible(u8 *p,u8 *e,u32 value);

void MUSICAL_MCSS_SetElemPos(void *unused, McssActorElem *p, const int *q);

void MUSICAL_MCSS_SetElemScale(u32 unused,McssActorElem *p,void *q);

void MUSICAL_MCSS_SetElemRotZ(void *unused, u8 *p, s16 a, s16 b);

void MUSICAL_MCSS_SetElemRot(void *unused, u8 *p, s16 *a, s16 *b);

void MUSICAL_MCSS_SetElemField(void *unused, u8 *p, u16 v);

void MUSICAL_MCSS_GetElemField(int unused, u16 *p, u16 *out);

void MUSICAL_MCSS_SetElemFlag(u8 *unused, McssActorElem *s, int flag);

int MUSICAL_MCSS_GetElemFlag(int unused, McssActorElem *p);

void MUSICAL_MCSS_GetElemOffset(u8 *p, McssOffset *out);

void *MUSICAL_MCSS_GetActorPoolResource(McssActorPool *p);

#include "mus_item_data.h"










extern char d_021F83A4[];

extern s16 FX_SinCosTable_[];

extern u32 d_021F8300;

McssActorPool *MUSICAL_MCSS_CreateActorPool(u32 owner,int count,u16 heap)
{
    int i=0;
    McssActorPool *p;
    int j;
    p=GFL_HEAP_Alloc(heap,sizeof(*p),0,d_021F83A4,0x55);
    p->entries=GFL_HEAP_Alloc(heap,count * sizeof(*p->entries),0,d_021F83A4,0x57);
    p->heap=heap;
    p->count=count;
    p->owner=owner;
    for(;i<p->count;i++) {
        p->entries[i].bits.active=0;
        p->entries[i].bits.dirty=0;
    }
    p->resource=MUSICAL_MCSS_LoadActorData(heap);
    for(j=0;j<16;j++) p->slots[j]=0x5a56;
    return p;
}

void MUSICAL_MCSS_DeleteActorPool(u8 *p)
{
    int i;
    NNS_GfdResetVramTransferTaskQueue();
    MUSICAL_MCSS_FreeActorData(((McssActorPool *)p)->resource);
    for(i=0;i<((McssActorPool *)p)->count;i++) {
        if (((McssActorPool *)p)->entries[i].bits.active==1)
            MUSICAL_MCSS_FreeElem(p,(u8 *)(&((McssActorPool *)p)->entries[i]));
    }
    GFL_HEAP_Free(((McssActorPool *)p)->entries);
    GFL_HEAP_Free(p);
}

/*
 * extent: 276-byte lead plus 4AA4 two-byte return stub; 4AA6 is zero alignment padding.
 * function_starts: 0x021F4AA4
 * lever: bitfield dirty clear retains the hoisted mask; named offset.x keeps trig load order.
 */
void MUSICAL_MCSS_UpdateObject(McssActorPool *p)
{
    int i;
    McssActorElem *e;
    McssOffset offset;
    Scale scale;
    struct Trip v;
    int x,y,s,c,ox;
    for(i=0;i<p->count;i++) {
        e=&p->entries[i];
        if(e->bits.active==1 && e->bits.dirty==1) {
            if(e->bits.rotate==1) {
                MUSICAL_MCSS_GetOffset((u8 *)e->data, (McssOffset *)&offset);
                if(e->a<0) offset.x *= -1;
                ox=offset.x;
                s=FX_SinCosTable_[(e->angle>>4)*2];
                c=FX_SinCosTable_[(e->angle>>4)*2+1];
                x=ox*c-offset.y*s;
                y=ox*s+offset.y*c;
            } else { x=0; y=0; }
            v.a=(e->x-x)/16;
            v.b=(0xC0000-(e->y-y))/16;
            v.c=e->z;
            BILLBOARD_SetElemPos((struct BbBoard *)p->board,e->index,(VecFx32 *)&v);
            MUSICAL_MCSS_SetupObject((u8 *)e,&scale.y,&scale.x);
            scale.a=e->a*scale.y;
            scale.b=e->b*scale.x;
            BILLBOARD_SetElemScale((struct BbBoard *)p->board,e->index,&scale.a,&scale.b);
            BILLBOARD_SetElemRotZ(p->board,e->index,&e->angle);
            p->entries[i].bits.dirty=0;
        }
    }
}

void MUSICAL_MCSS_NoOp3(void *unused)
{
}

u16 MUSICAL_MCSS_GetArcFileCount(int i)
{
    u32 n = (u16)ARC_TOOL_GetArchiveFileCount(45) - 2;
    if (i >= (int)n) return 100;
    return (u16)i;
}

void MUSICAL_MCSS_SetupObject(u8 *elem,u8 *a,u8 *b) { u16 x,y; BILLBOARD_GetImageSizeFromFlags(MUSICAL_MCSS_GetElemSizeFlags(*(int * *)&((McssActorElem *)elem)->data),&x,&y); *a=(u32)x>>5; *b=(u32)y>>5; }

int MUSICAL_MCSS_IsElemModeSupportedA(u8 *elem, int index)
{
    return MUSICAL_MCSS_IsModeSupportedA(*(u16 * *)&((McssActorElem *)elem)->data, index);
}

int MUSICAL_MCSS_IsElemModeSupportedB(u8 *pool,int index,int mode) { return MUSICAL_MCSS_IsModeSupportedB((u16 *)MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((McssActorPool *)pool)->resource,index),mode); }

int MUSICAL_MCSS_IsElemModeSupportedC(u8 *pool,int index,int mode) { return MUSICAL_MCSS_IsModeSupportedC(MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((McssActorPool *)pool)->resource,index),mode); }

int MUSICAL_MCSS_ElemHasAltDepth(u8 *elem) { return MUSICAL_MCSS_ElemDataHasAltDepth((const unsigned char *)(((McssActorElem *)elem)->data)); }

int MUSICAL_MCSS_ElemKeepsFlippedHeight(u8 *elem) { return MUSICAL_MCSS_ElemDataKeepsFlippedHeight((const unsigned char *)(((McssActorElem *)elem)->data)); }

void *MUSICAL_MCSS_CreateResourceArc(int type) { return G3D_SYSTEM_CreateResourceArc(45,MUSICAL_MCSS_GetArcFileCount(type)); }

void MUSICAL_MCSS_FreeResourceArc(struct Tagged *resourceArc) { G3D_SYSTEM_DeleteResource((struct G3dResource *)resourceArc); }

u16 MUSICAL_MCSS_FindFreeActorIndex(McssActorPool *pool) { u16 n; int i; n=(pool)->count; for (i=0;i<n;i++) { if ((pool)->entries[i].bits.active==0) break; } if (i==n) return 0; return i; }

McssActorElem *MUSICAL_MCSS_AddImage(McssActorPool *pool,int type,struct G3dResource *id,int *v)
{
    int index;
    int data;
    MusItemDrawPair pair;
    index=MUSICAL_MCSS_FindFreeActorIndex(pool);
    pool->entries[index].type=MUSICAL_MCSS_GetArcFileCount(type);
    pool->entries[index].data=MUSICAL_MCSS_GetElemPtr(pool->resource,type);
    data=MUSICAL_MCSS_GetElemSizeFlags((int *)pool->entries[index].data);
    MUSICAL_MCSS_SetupObject((u8 *)(&pool->entries[index]),&pair.y,&pair.x);
    pool->entries[index].id=BILLBOARD_AddImage(pool->board,id,0,data,pair.y<<5,pair.x<<5);
    pool->entries[index].flags |= 16;
    MUSICAL_MCSS_AddElem((McssActorPool *)pool, index, (int *)v, pair.y, pair.x);
    return &pool->entries[index];
}

McssActorElem *MUSICAL_MCSS_AddImageNoVram(McssActorPool *pool, int type, u32 id, int *v)
{
    int index;
    MusItemDrawPair pair;
    index=MUSICAL_MCSS_FindFreeActorIndex(pool);
    pool->entries[index].type=MUSICAL_MCSS_GetArcFileCount(type);
    pool->entries[index].data=MUSICAL_MCSS_GetElemPtr(pool->resource,type);
    MUSICAL_MCSS_GetElemSizeFlags((int *)pool->entries[index].data);
    MUSICAL_MCSS_SetupObject((u8 *)(&pool->entries[index]),&pair.y,&pair.x);
    pool->entries[index].id=id;
    pool->entries[index].flags=pool->entries[index].flags & ~16;
    MUSICAL_MCSS_AddElem((McssActorPool *)pool, index, (int *)v, pair.y, pair.x);
    return &pool->entries[index];
}

McssActorElem *MUSICAL_MCSS_AddElem(McssActorPool *p, u16 index, int *v, s16 a, s16 b)
{
    p->entries[index].index = BILLBOARD_AddElem((struct BbBoard *)p->board,p->entries[index].id,4096,4096,(VecFx32 *)v,31,0,0);
    BILLBOARD_SetElemVisible(p->board,p->entries[index].index,&d_021F8300);
    p->entries[index].flags = (p->entries[index].flags & ~1) | 1;
    p->entries[index].flags |= 2;
    p->entries[index].flags |= 4;
    p->entries[index].flags = p->entries[index].flags & ~8;
    p->entries[index].x = v[0];
    p->entries[index].y = v[1];
    p->entries[index].z = v[2];
    p->entries[index].a = a;
    p->entries[index].b = b;
    p->entries[index].angle = 0;
    return &p->entries[index];
}

void MUSICAL_MCSS_FreeElem(u8 *pool,u8 *e) { BILLBOARD_FreeElem(((McssActorPool *)pool)->board,((McssActorElem *)e)->index); if (((McssActorElem *)e)->bits.vramInUse==1) BILLBOARD_ReleaseImageVramIfUsed(((McssActorPool *)pool)->board,((McssActorElem *)e)->id); ((McssActorElem *)e)->flags=((McssActorElem *)e)->flags & ~1; ((McssActorElem *)e)->flags=((McssActorElem *)e)->flags & ~2; }

void MUSICAL_MCSS_FreeElemImage(u8 *pool, u8 *e, int type, u16 id)
{
    ((McssActorElem *)e)->type = MUSICAL_MCSS_GetArcFileCount(type);
    *(u8 * *)&((McssActorElem *)e)->data = MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((McssActorPool *)pool)->resource,type);
    ((McssActorElem *)e)->flags = ((McssActorElem *)e)->flags & ~8;
    BILLBOARD_SetElemId(((McssActorPool *)pool)->board,((McssActorElem *)e)->index,&id);
    if (((McssActorElem *)e)->bits.vramInUse == 1) BILLBOARD_ReleaseImageVramIfUsed(((McssActorPool *)pool)->board,((McssActorElem *)e)->id);
    ((McssActorElem *)e)->flags = ((McssActorElem *)e)->flags & ~16;
    ((McssActorElem *)e)->id = id;
    ((McssActorElem *)e)->flags = (((McssActorElem *)e)->flags & ~1) | 1;
    ((McssActorElem *)e)->flags |= 2;
}

/*
 * Note: when the address 0x0204F32C is registered this should resolve to EXACT. Scratch blocker.log EXACT.
 *   typedef unsigned int u32;
 *   void BILLBOARD_GetImagePlttKey(char *p,u32 i,u32 *out) {
 *       *out = *(u32 *)(*(char **)(p+4)+i*40+36);
 *   }
 * follower: 0x021F4E2C vector/flags leaf left unfiled while ARM9 blocks.
 */
/*
 *   once 0x0204F32C is registered (manifest/label) this should resolve to EXACT*. Scratch blocker.log EXACT.
 *   typedef unsigned int u32;
 *   void BILLBOARD_GetImagePlttKey(char *p,u32 i,u32 *out) {
 *       *out = *(u32 *)(*(char **)(p+4)+i*40+36);
 *   }
 * follower: 0x021F4E2C vector/flags leaf left unfiled while ARM9 blocks.
 */
void MUSICAL_MCSS_TransferVram(char *p, char *e, void *unused)
{
    u32 first, second;
    if (!((McssActorElem *)e)->bits.vramTransferred) {
        BILLBOARD_GetImagePlttVramOffset((struct BbBoard *)((McssActorPool *)p)->board,((McssActorElem *)e)->id,(s32 *)(&first));
        BILLBOARD_GetImagePlttKey((struct BbBoard *)((McssActorPool *)p)->board,((McssActorElem *)e)->id,(u32 *)(&second));
        NNS_GfdRegisterNewVramTransferTask(1,first,((McssActorPool *)p)->slots,((second & 0xffff0000) >> 16) * 8);
        ((McssActorElem *)e)->flags |= 8;
    }
}

/*
 * lever: Three-shift single-bit extraction is a halfword bitfield copy.
 */
void MUSICAL_MCSS_CopyElem(void *unused, u8 *s, u8 *d)
{
    ((McssActorElem *)d)->x = ((McssActorElem *)s)->x + 8192;
    ((McssActorElem *)d)->y = ((McssActorElem *)s)->y + 8192;
    ((McssActorElem *)d)->z = ((McssActorElem *)s)->z - 2048;
    ((McssActorElem *)d)->a = ((McssActorElem *)s)->a;
    ((McssActorElem *)d)->b = ((McssActorElem *)s)->b;
    ((McssActorElem *)d)->angle = ((McssActorElem *)s)->angle;
    ((McssActorElem *)d)->bits.rotate = ((McssActorElem *)s)->bits.rotate;
}

void MUSICAL_MCSS_SetElemVisible(u8 *pool,u8 *e,u32 value) { BILLBOARD_SetElemVisible(((McssActorPool *)pool)->board,((McssActorElem *)e)->index,&value); ((McssActorElem *)e)->flags |=2; }

void MUSICAL_MCSS_SetElemPos(void *unused, McssActorElem *p, const int *q) { p->x=q[0]; p->y=q[1]; p->z=q[2]; p->flags |=2; }

void MUSICAL_MCSS_SetElemScale(u32 unused,McssActorElem *elem,void *q) { ((struct MusItemDrawVec3 *)q)->x=(elem)->x; ((struct MusItemDrawVec3 *)q)->y=(elem)->y; ((struct MusItemDrawVec3 *)q)->z=(elem)->z; }

void MUSICAL_MCSS_SetElemRotZ(void *unused, u8 *elem, s16 a, s16 b) { u16 flags; ((McssActorElem *)elem)->a=a; flags=((McssActorElem *)elem)->flags; ((McssActorElem *)elem)->b=b; ((McssActorElem *)elem)->flags=flags|2; }

void MUSICAL_MCSS_SetElemRot(void *unused, u8 *elem, s16 *a, s16 *b) { *a=((McssActorElem *)elem)->a; *b=((McssActorElem *)elem)->b; }

void MUSICAL_MCSS_SetElemField(void *unused, u8 *elem, u16 v) { ((McssActorElem *)elem)->angle=v; ((McssActorElem *)elem)->flags |=2; }

/*
 * extent: six-byte body, two zero alignment bytes before separately filed 021F4EE8.
 */
void MUSICAL_MCSS_GetElemField(int unused, u16 *p, u16 *out)
{
    *out = p[1];
}

/*
 * lever: wide int argument into u16 bitfield preserves the redundant
 * halfword narrowing pair; a u16 argument produced 16 bytes, DIFF10.
 * leaf: sole overlay blocker of handed ov133 021B8140; explicit unused r0
 * retained from the caller. Twenty-byte body; following getter omitted.
 */
void MUSICAL_MCSS_SetElemFlag(u8 *unused, McssActorElem *s, int flag)
{
    s->bits.rotate=flag;
}

int MUSICAL_MCSS_GetElemFlag(int unused, McssActorElem *p)
{
    return p->bits.rotate;
}

void MUSICAL_MCSS_GetElemOffset(u8 *elem, McssOffset *out)
{
    MUSICAL_MCSS_GetOffset(*(u8 * *)&((McssActorElem *)elem)->data, out);
}

void *MUSICAL_MCSS_GetActorPoolResource(McssActorPool *pool) { return pool->resource; }
