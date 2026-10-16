/*
 * file:     mus_item_draw.c
 * unit:     yes
 * function: MUSICAL_MCSS_CreateActorPool, MUSICAL_MCSS_DeleteActorPool, MUSICAL_MCSS_UpdateObject, MUSICAL_MCSS_NoOp3, MUSICAL_MCSS_GetArcFileCount, MUSICAL_MCSS_SetupObject, MUSICAL_MCSS_SetIndexA, MUSICAL_MCSS_SetIndexB, MUSICAL_MCSS_SetIndexC, MUSICAL_MCSS_GetFlagA, MUSICAL_MCSS_GetFlagB, MUSICAL_MCSS_CreateResourceArc, MUSICAL_MCSS_FreeResourceArc, MUSICAL_MCSS_NoOp4, MUSICAL_MCSS_AddImage, MUSICAL_MCSS_AddImageNoVram, MUSICAL_MCSS_AddElem, MUSICAL_MCSS_FreeElem, MUSICAL_MCSS_FreeElemImage, MUSICAL_MCSS_TransferVram, MUSICAL_MCSS_CopyElem, MUSICAL_MCSS_SetElemVisible, MUSICAL_MCSS_SetElemPos, MUSICAL_MCSS_SetElemScale, MUSICAL_MCSS_SetElemRotZ, MUSICAL_MCSS_SetElemRot, MUSICAL_MCSS_SetElemField, MUSICAL_MCSS_GetElemField, MUSICAL_MCSS_SetElemFlag, MUSICAL_MCSS_GetElemFlag, MUSICAL_MCSS_GetElemOffset, MUSICAL_MCSS_NoOp5
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
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
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
 *   MUSICAL_MCSS_NoOp6 0x021F4F70 thumb ov112
 *   MUSICAL_MCSS_SetModeA 0x021F4F74 thumb ov112
 *   MUSICAL_MCSS_SetModeB 0x021F4FF4 thumb ov112
 *   MUSICAL_MCSS_SetModeC 0x021F5064 thumb ov112
 *   MUSICAL_MCSS_GetStateA 0x021F50D0 thumb ov112
 *   MUSICAL_MCSS_GetStateB 0x021F50E0 thumb ov112
 */
#include "musical_shot_sys_shared_types.h"
#include "mus_shot_photo_shared_types.h"
#include "mus_shot_info_shared_types.h"
#include "mus_item_draw_shared_types.h"

extern u32 func_020307B0(void *p);

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

typedef struct { u8 x,y; } Pair;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void NNS_GfdResetVramTransferTaskQueue(void);

extern void BILLBOARD_SetElemPos(u8 *,int,struct Trip *);

extern void BILLBOARD_SetElemScale(struct Manager0204F684 *,int,const s16 *,const s16 *);

extern void BILLBOARD_SetElemRotZ(u8 *,int,u16 *);

extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);

extern void BILLBOARD_GetImageSizeFromFlags(int,u16 *,u16 *);

extern void *G3D_SYSTEM_CreateResourceArc(u32,u32);

extern void func_02046EFC(struct Tagged *p);

extern u32 BILLBOARD_AddImage(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);

extern s32 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);

extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);

extern void BILLBOARD_FreeElem(void *,u32);

extern void BILLBOARD_ReleaseImageVramIfUsed(struct BbBoard *a0, u32 a1);

extern void BILLBOARD_SetElemId(void *,u32,u16 *);

extern void BILLBOARD_GetImagePlttVramOffset(int p0, int p1, int p2);

extern void BILLBOARD_GetImagePlttKey(int p0, int p1, int p2);

extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);

McssActorPool *MUSICAL_MCSS_CreateActorPool(u32 owner,int count,u16 heap);

void MUSICAL_MCSS_DeleteActorPool(u8 *p);

void MUSICAL_MCSS_UpdateObject(McssActorPool *p);

void MUSICAL_MCSS_NoOp3(void *a0);

u16 MUSICAL_MCSS_GetArcFileCount(int i);

void MUSICAL_MCSS_SetupObject(u8 *p,u8 *a,u8 *b);

int MUSICAL_MCSS_SetIndexA(u8 *p, int index);

int MUSICAL_MCSS_SetIndexB(u8 *p,int index,int mode);

int MUSICAL_MCSS_SetIndexC(u8 *p,int index,int mode);

int MUSICAL_MCSS_GetFlagA(u8 *p);

int MUSICAL_MCSS_GetFlagB(u8 *p);

void *MUSICAL_MCSS_CreateResourceArc(int type);

void MUSICAL_MCSS_FreeResourceArc(struct Tagged *a0);

u16 MUSICAL_MCSS_NoOp4(u32 p);

McssActorElem *MUSICAL_MCSS_AddImage(McssActorPool *p,int type,u32 id,int *v);

McssActorElem *MUSICAL_MCSS_AddImageNoVram(McssActorPool *p, int type, u32 id, int *v);

McssActorElem *MUSICAL_MCSS_AddElem(McssActorPool *p, u16 index, int *v, s16 a, s16 b);

void MUSICAL_MCSS_FreeElem(u8 *p,u8 *e);

void MUSICAL_MCSS_FreeElemImage(u8 *p, u8 *e, int type, u16 id);

void MUSICAL_MCSS_TransferVram(char *p, char *e, void *a2);

void MUSICAL_MCSS_CopyElem(void *unused, u8 *s, u8 *d);

void MUSICAL_MCSS_SetElemVisible(u8 *p,u8 *e,u32 value);

void MUSICAL_MCSS_SetElemPos(u32 unused,McssActorElem *p,const int *q);

void MUSICAL_MCSS_SetElemScale(u32 unused,u32 p,u32 q);

void MUSICAL_MCSS_SetElemRotZ(u32 unused,u32 p,s16 a,s16 b);

void MUSICAL_MCSS_SetElemRot(u32 unused,u32 p,s16 *a,s16 *b);

void MUSICAL_MCSS_SetElemField(u32 unused,u32 p,u16 v);

void MUSICAL_MCSS_GetElemField(int unused, u16 *p, u16 *out);

void MUSICAL_MCSS_SetElemFlag(int unused,McssActorElem *s,int flag);

int MUSICAL_MCSS_GetElemFlag(int unused, McssActorElem *p);

void MUSICAL_MCSS_GetElemOffset(u8 *p, McssOffset *out);

u32 MUSICAL_MCSS_NoOp5(u8 *p);

u32 *MUSICAL_MCSS_LoadActorData(int heap);

void MUSICAL_MCSS_FreeActorData(void **p);

u8 *MUSICAL_MCSS_GetElemPtr(u8 *p, int i);

void MUSICAL_MCSS_GetOffset(u8 *p, McssOffset *out);

int MUSICAL_MCSS_NoOp6(int *p);

int MUSICAL_MCSS_SetModeA(u16 *p, int mode);

int MUSICAL_MCSS_SetModeB(u16 *p, int mode);

int MUSICAL_MCSS_SetModeC(u8 *p, int mode);

int MUSICAL_MCSS_GetStateA(const unsigned char *p);

int MUSICAL_MCSS_GetStateB(const unsigned char *p);

extern char d_021F83A4[];

extern s16 FX_SinCosTable_[];

extern u32 d_021F8300;

McssActorPool *MUSICAL_MCSS_CreateActorPool(u32 owner,int count,u16 heap)
{
    int i=0;
    McssActorPool *p;
    int j;
    p=func_02030734(heap,0x34,0,d_021F83A4,0x55);
    p->entries=func_02030734(heap,count*0x24,0,d_021F83A4,0x57);
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
    MUSICAL_MCSS_FreeActorData(*(void **)(p+0xc));
    for(i=0;i<*(u16 *)(p+0x10);i++) {
        if ((*(McssActorElem **)(p+8))[i].bits.active==1)
            MUSICAL_MCSS_FreeElem(p,(u8 *)(&(*(McssActorElem **)(p+8))[i]));
    }
    func_020307B0(*(void **)(p+8));
    func_020307B0(p);
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
            BILLBOARD_SetElemPos(p->board,e->index,&v);
            MUSICAL_MCSS_SetupObject((u8 *)e,&scale.y,&scale.x);
            scale.a=e->a*scale.y;
            scale.b=e->b*scale.x;
            BILLBOARD_SetElemScale((struct Manager0204F684 *)p->board,e->index,&scale.a,&scale.b);
            BILLBOARD_SetElemRotZ(p->board,e->index,&e->angle);
            p->entries[i].bits.dirty=0;
        }
    }
}

void MUSICAL_MCSS_NoOp3(void *a0)
{
}

u16 MUSICAL_MCSS_GetArcFileCount(int i)
{
    u32 n = (u16)ARC_TOOL_GetArchiveFileCount(45) - 2;
    if (i >= (int)n) return 100;
    return (u16)i;
}

void MUSICAL_MCSS_SetupObject(u8 *p,u8 *a,u8 *b) { u16 x,y; BILLBOARD_GetImageSizeFromFlags(MUSICAL_MCSS_NoOp6(*(int * *)&((McssActorElem *)p)->data),&x,&y); *a=(u32)x>>5; *b=(u32)y>>5; }

int MUSICAL_MCSS_SetIndexA(u8 *p, int index)
{
    return MUSICAL_MCSS_SetModeA(*(u16 * *)&((McssActorElem *)p)->data, index);
}

int MUSICAL_MCSS_SetIndexB(u8 *p,int index,int mode) { return MUSICAL_MCSS_SetModeB((u16 *)MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((McssActorPool *)p)->resource,index),mode); }

int MUSICAL_MCSS_SetIndexC(u8 *p,int index,int mode) { return MUSICAL_MCSS_SetModeC(MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((McssActorPool *)p)->resource,index),mode); }

int MUSICAL_MCSS_GetFlagA(u8 *p) { return MUSICAL_MCSS_GetStateA((const unsigned char *)(((McssActorElem *)p)->data)); }

int MUSICAL_MCSS_GetFlagB(u8 *p) { return MUSICAL_MCSS_GetStateB((const unsigned char *)(((McssActorElem *)p)->data)); }

void *MUSICAL_MCSS_CreateResourceArc(int type) { return G3D_SYSTEM_CreateResourceArc(45,MUSICAL_MCSS_GetArcFileCount(type)); }

void MUSICAL_MCSS_FreeResourceArc(struct Tagged *a0) { func_02046EFC(a0); }

u16 MUSICAL_MCSS_NoOp4(u32 p) { u16 n; int i; n=((McssActorPool *)p)->count; for (i=0;i<n;i++) { if (((McssActorPool *)p)->entries[i].bits.active==0) break; } if (i==n) return 0; return i; }

McssActorElem *MUSICAL_MCSS_AddImage(McssActorPool *p,int type,u32 id,int *v)
{
    int index;
    int data;
    Pair pair;
    index=MUSICAL_MCSS_NoOp4((u32)p);
    p->entries[index].type=MUSICAL_MCSS_GetArcFileCount(type);
    p->entries[index].data=MUSICAL_MCSS_GetElemPtr(p->resource,type);
    data=MUSICAL_MCSS_NoOp6((int *)p->entries[index].data);
    MUSICAL_MCSS_SetupObject((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=BILLBOARD_AddImage(p->board,id,0,data,pair.y<<5,pair.x<<5);
    p->entries[index].flags |= 16;
    MUSICAL_MCSS_AddElem((McssActorPool *)p, index, (int *)v, pair.y, pair.x);
    return &p->entries[index];
}

McssActorElem *MUSICAL_MCSS_AddImageNoVram(McssActorPool *p, int type, u32 id, int *v)
{
    int index;
    Pair pair;
    index=MUSICAL_MCSS_NoOp4((u32)p);
    p->entries[index].type=MUSICAL_MCSS_GetArcFileCount(type);
    p->entries[index].data=MUSICAL_MCSS_GetElemPtr(p->resource,type);
    MUSICAL_MCSS_NoOp6((int *)p->entries[index].data);
    MUSICAL_MCSS_SetupObject((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=id;
    p->entries[index].flags=p->entries[index].flags & ~16;
    MUSICAL_MCSS_AddElem((McssActorPool *)p, index, (int *)v, pair.y, pair.x);
    return &p->entries[index];
}

McssActorElem *MUSICAL_MCSS_AddElem(McssActorPool *p, u16 index, int *v, s16 a, s16 b)
{
    p->entries[index].index = BILLBOARD_AddElem(p->board,p->entries[index].id,4096,4096,(struct Vec3 *)v,31,0,0);
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

void MUSICAL_MCSS_FreeElem(u8 *p,u8 *e) { BILLBOARD_FreeElem(((McssActorPool *)p)->board,((McssActorElem *)e)->index); if (((McssActorElem *)e)->bits.vramInUse==1) BILLBOARD_ReleaseImageVramIfUsed(((McssActorPool *)p)->board,((McssActorElem *)e)->id); ((McssActorElem *)e)->flags=((McssActorElem *)e)->flags & ~1; ((McssActorElem *)e)->flags=((McssActorElem *)e)->flags & ~2; }

void MUSICAL_MCSS_FreeElemImage(u8 *p, u8 *e, int type, u16 id)
{
    ((McssActorElem *)e)->type = MUSICAL_MCSS_GetArcFileCount(type);
    *(u8 * *)&((McssActorElem *)e)->data = MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((McssActorPool *)p)->resource,type);
    ((McssActorElem *)e)->flags = ((McssActorElem *)e)->flags & ~8;
    BILLBOARD_SetElemId(((McssActorPool *)p)->board,((McssActorElem *)e)->index,&id);
    if (((McssActorElem *)e)->bits.vramInUse == 1) BILLBOARD_ReleaseImageVramIfUsed(((McssActorPool *)p)->board,((McssActorElem *)e)->id);
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
void MUSICAL_MCSS_TransferVram(char *p, char *e, void *a2)
{
    u32 first, second;
    if (!((McssActorElem *)e)->bits.vramTransferred) {
        BILLBOARD_GetImagePlttVramOffset((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&first));
        BILLBOARD_GetImagePlttKey((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&second));
        NNS_GfdRegisterNewVramTransferTask((void *)1,first,(u32)(p+18),((second & 0xffff0000) >> 16) * 8);
        *(u16 *)e |= 8;
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

void MUSICAL_MCSS_SetElemVisible(u8 *p,u8 *e,u32 value) { BILLBOARD_SetElemVisible(((McssActorPool *)p)->board,((McssActorElem *)e)->index,&value); ((McssActorElem *)e)->flags |=2; }

void MUSICAL_MCSS_SetElemPos(u32 unused,McssActorElem *p,const int *q) { p->x=q[0]; p->y=q[1]; p->z=q[2]; p->flags |=2; }

void MUSICAL_MCSS_SetElemScale(u32 unused,u32 p,u32 q) { ((struct Vec3 *)q)->x=((McssActorElem *)p)->x; ((struct Vec3 *)q)->y=((McssActorElem *)p)->y; ((struct Vec3 *)q)->z=((McssActorElem *)p)->z; }

void MUSICAL_MCSS_SetElemRotZ(u32 unused,u32 p,s16 a,s16 b) { u16 flags; ((McssActorElem *)p)->a=a; flags=((McssActorElem *)p)->flags; ((McssActorElem *)p)->b=b; ((McssActorElem *)p)->flags=flags|2; }

void MUSICAL_MCSS_SetElemRot(u32 unused,u32 p,s16 *a,s16 *b) { *a=((McssActorElem *)p)->a; *b=((McssActorElem *)p)->b; }

void MUSICAL_MCSS_SetElemField(u32 unused,u32 p,u16 v) { ((McssActorElem *)p)->angle=v; ((McssActorElem *)p)->flags |=2; }

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
void MUSICAL_MCSS_SetElemFlag(int unused,McssActorElem *s,int flag)
{
    s->bits.rotate=flag;
}

int MUSICAL_MCSS_GetElemFlag(int unused, McssActorElem *p)
{
    return p->bits.rotate;
}

void MUSICAL_MCSS_GetElemOffset(u8 *p, McssOffset *out)
{
    MUSICAL_MCSS_GetOffset(*(u8 * *)&((McssActorElem *)p)->data, out);
}

u32 MUSICAL_MCSS_NoOp5(u8 *p) { return (u32)((McssActorPool *)p)->resource; }
