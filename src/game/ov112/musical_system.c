/*
 * file:     musical_system.c
 * unit:     yes
 * function: MUSICAL_MCSS_CreateMon, MUSICAL_MCSS_AllocMon, MUSICAL_MCSS_AllocDistSave, MUSICAL_MCSS_FreeDistSave, MUSICAL_MCSS_LoadDistSave
 * address:  0x021F675C
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
 *   MUSICAL_MCSS_AllocMon  0x021F67E0  thumb  ov112
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   d_021F83E4 0x021F83E4 data a4
 *   MUSICAL_DIST_SAVE_Create 0x0200C52C thumb
 *   MUSICAL_DIST_SAVE_GetPayload 0x0200C6D8 thumb
 *   MUSICAL_DIST_SAVE_GetPayloadSize 0x0200C6DC thumb
 *   MUSICAL_DIST_SAVE_Delete 0x0200C5A4 thumb
 *   ARC_TOOL_CreateHandleFromMemory 0x0204913C arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 */
#include "musical_shot_sys_shared_types.h"
#include "mus_poke_draw_shared_types.h"

extern u32 GFL_HEAP_Free(void *p);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

struct ArcFile;

struct Blk2C;

struct MusicalDist;

/* The MUSICAL_MCSS_LoadDistSave object: four loaded ARC members at 0x04..0x10. */
typedef struct McssDistSave {
    u8 kind;                /* 0x00 */
    u8 pad_1[3];            /* 0x01 */
    void *member0;          /* 0x04 */
    void *member1;          /* 0x08 */
    void *member2;          /* 0x0C */
    void *member3;          /* 0x10 */
} McssDistSave;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);

extern u32 POKE_TOOL_IsShiny(void *);

extern struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *sys, u32 heap);

extern u32 MUSICAL_DIST_SAVE_GetPayload(struct Blk2C *p);

extern u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct Blk2C *p);

extern void *ARC_TOOL_CreateHandleFromMemory(void *buf, u32 size, u32 heap);

extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);

extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);

extern void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *p);

char *MUSICAL_MCSS_CreateMon(void *a,u16 heap);

char *MUSICAL_MCSS_AllocMon(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap);

void *MUSICAL_MCSS_AllocDistSave(u32 heap);

void MUSICAL_MCSS_FreeDistSave(char *p);

void MUSICAL_MCSS_LoadDistSave(u8 *p, u32 unused, void *sys, u8 kind, u16 heap);

extern const char d_021F83E4[];

char *MUSICAL_MCSS_CreateMon(void *a,u16 heap)
{
    char *p;
    int i;
    p=GFL_HEAP_Alloc(heap,124,1,d_021F83E4,141);
    ((McssMon *)p)->kind=4;
    ((McssMon *)p)->source=a;
    ((McssMon *)p)->reserved4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    ((McssMon *)p)->species=POKE_TOOL_GetPartyValue(a,5,0);
    p[10]=POKE_TOOL_GetPartyValue(a,110,0);
    p[11]=POKE_TOOL_GetPartyValue(a,111,0);
    p[12]=POKE_TOOL_IsShiny(a);
    ((McssMon *)p)->personalRnd=POKE_TOOL_GetPartyValue(a,0,0);
    return p;
}

char *MUSICAL_MCSS_AllocMon(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap)
{
    int i;
    char *p;
    int j;
    p=GFL_HEAP_Alloc(heap,124,1,d_021F83E4,165);
    ((McssMon *)p)->kind=4; ((McssMon *)p)->source=0; ((McssMon *)p)->reserved4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    for(j=0;j<4;j++) *(u16 *)(p+76+2*j)=0;
    ((McssMon *)p)->reserved78=0;
    ((McssMon *)p)->species=a; p[10]=b; p[11]=c; p[12]=d; ((McssMon *)p)->personalRnd=e;
    return p;
}

void *MUSICAL_MCSS_AllocDistSave(u32 heap) {u32 *p;int z;z=0;p=GFL_HEAP_Alloc(heap,48,0,d_021F83E4,194);p[1]=z;p[2]=z;p[3]=z;p[4]=z;p[5]=z;p[6]=z;p[7]=z;return p;}

void MUSICAL_MCSS_FreeDistSave(char *p) {if(((McssDistSave *)p)->member0)GFL_HEAP_Free(((McssDistSave *)p)->member0);if(((McssDistSave *)p)->member1)GFL_HEAP_Free(((McssDistSave *)p)->member1);if(((McssDistSave *)p)->member2)GFL_HEAP_Free(((McssDistSave *)p)->member2);if(((McssDistSave *)p)->member3)GFL_HEAP_Free(((McssDistSave *)p)->member3);GFL_HEAP_Free(p);}

void MUSICAL_MCSS_LoadDistSave(u8 *p, u32 unused, void *sys, u8 kind, u16 heap)
{
    void *x;
    void *arc;
    u32 c, d, e;
    u8 *q;
    *p = kind;
    if (kind >= 4) {
        x = MUSICAL_DIST_SAVE_Create(sys, heap);
        arc = ARC_TOOL_CreateHandleFromMemory((void *)MUSICAL_DIST_SAVE_GetPayload(x), MUSICAL_DIST_SAVE_GetPayloadSize(x), (u16)((heap & 0x7fff) | 0x8000));
    } else {
        arc = ARC_TOOL_CreateHandle(kind + 0x6f, (u16)((heap & 0x7fff) | 0x8000));
    }
    *(void **)(p + 4) = ARC_UTIL_LoadHandleMemberWithSize(arc, 0, 0, heap, (u32 *)(p + 0x20));
    *(void **)(p + 8) = ARC_UTIL_LoadHandleMemberWithSize(arc, 1, 0, heap, (u32 *)(p + 0x24));
    *(void **)(p + 0xc) = ARC_UTIL_LoadHandleMemberWithSize(arc, 2, 0, heap, (u32 *)(p + 0x28));
    c = ARC_TOOL_GetHandleMemberSize(arc, 4);
    d = ARC_TOOL_GetHandleMemberSize(arc, 3);
    e = ARC_TOOL_GetHandleMemberSize(arc, 5);
    *(u32 *)(p + 0x2c) = c + 0xc + d + e;
    q = GFL_HEAP_Alloc(heap, *(u32 *)(p + 0x2c), 1, d_021F83E4, 0x104);
    *(u8 **)(p + 0x10) = q;
    *(u8 **)(p + 0x14) = q + 0xc;
    *(u8 **)(p + 0x18) = q + 0xc + c;
    *(u32 *)(p + 0x1c) = d + *(u32 *)(p + 0x18);
    *(u32 *)q = c;
    *(u32 *)(q + 4) = d;
    *(u32 *)(q + 8) = e;
    ARC_TOOL_ReadHandleMember(arc, 4, *(void **)(p + 0x14));
    ARC_TOOL_ReadHandleMember(arc, 3, *(void **)(p + 0x18));
    ARC_TOOL_ReadHandleMember(arc, 5, *(void **)(p + 0x1c));
    ARC_TOOL_DeleteHandle(arc);
    if (kind >= 4) MUSICAL_DIST_SAVE_Delete(x);
}
