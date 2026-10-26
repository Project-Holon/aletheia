/*
 * file:     sta_act_obj.c
 * unit:     yes
 * function: STA_ACT_OBJ_Create, STA_ACT_OBJ_Delete, STA_ACT_OBJ_Update, STA_ACT_OBJ_UpdateEntry, STA_ACT_OBJ_SetCount, STA_ACT_OBJ_AddEntry, STA_ACT_OBJ_FreeEntry, STA_ACT_OBJ_SetEntryTarget, STA_ACT_OBJ_GetEntryTarget
 * address:  0x021F69E4
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F83F8 0x021F83F8 data a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   d_021F8328 0x021F8328 data a4
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_DeleteImage 0x0204F150 arm
 */
struct Trip;
struct Board;
struct Vec3;
#include "sta_act_types.h"
#include "../types.h"


#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/billboard.h"
struct BbBoard;
StaActObjObject *STA_ACT_OBJ_Create(u16 heap, void *board);
void STA_ACT_OBJ_Delete(char *p);
void STA_ACT_OBJ_Update(char *p);
void STA_ACT_OBJ_UpdateEntry(char *o, StaActObjEntry *entry);
void STA_ACT_OBJ_SetCount(StaActObjObject *o, u16 n);
StaActObjEntry *STA_ACT_OBJ_AddEntry(StaActObjObject *o, u32 unused);
void STA_ACT_OBJ_FreeEntry(u32 *o, StaActObjEntry *entry);
void STA_ACT_OBJ_SetEntryTarget(void *a, StaActObjEntry *entry, u32 *target);
void STA_ACT_OBJ_GetEntryTarget(void *a, StaActObjEntry *entry, u32 *target);
extern const char d_021F83F8[];
extern u32 d_021F8328;

StaActObjObject *STA_ACT_OBJ_Create(u16 heap, void *board)
{
    StaActObjObject *o;
    u8 i;
    i=0;
    o=GFL_HEAP_Alloc(heap,sizeof(*o),0,d_021F83F8,79);
    o->heap=heap;
    o->board=board;
    o->count=0;
    for (;i<5;i++) { o->entries[i].active=0; o->entries[i].dirty=0; }
    return o;
}

void STA_ACT_OBJ_Delete(char *p) {u8 i;for(i=0;i<5;i++)if(((StaActObjObject *)p)->entries[i].active==1)STA_ACT_OBJ_FreeEntry((u32 *)p,&((StaActObjObject *)p)->entries[i]);GFL_HEAP_Free(p);}

/*
 * lever: Load adds the index before offset eight; the call adds offset eight before the index.
 */
void STA_ACT_OBJ_Update(char *p) {int i;for(i=0;i<5;i++)if(((StaActObjObject *)p)->entries[i].active==1)STA_ACT_OBJ_UpdateEntry(p,&((StaActObjObject *)p)->entries[i]);}

/*
 * extent: Padding then separately verified follower STA_ACT_OBJ_SetCount.
 */
void STA_ACT_OBJ_UpdateEntry(char *o, StaActObjEntry *entry)
{
    StaActObjVec v;
    float f;
    if(entry->dirty==1) {
        if(((StaActObjObject *)o)->count!=0) f=0.5f+(float)(((StaActObjObject *)o)->count<<12);
        else f=(float)(((StaActObjObject *)o)->count<<12)-0.5f;
        v.x=((int)entry->x-(int)f)/16;
        v.y=(786432-(int)entry->y)/16;
        v.z=entry->z;
        BILLBOARD_SetElemPos((struct BbBoard *)(((StaActObjObject *)o)->board),entry->index,(VecFx32 *)((struct Trip *)(&v)));
        entry->dirty=0;
    }
}

void STA_ACT_OBJ_SetCount(StaActObjObject *o, u16 count)
{
    u8 i;
    o->count=count;
    for(i=0;i<5;i++) if(o->entries[i].active==1) o->entries[i].dirty=1;
}

StaActObjEntry *STA_ACT_OBJ_AddEntry(StaActObjObject *o, u32 unused)
{
    u8 i;
    StaActObjEntry *entry;
    for(i=0;i<5;i++) if(o->entries[i].active==0) break;
    entry=&o->entries[i];
    entry->active=1; entry->dirty=1; entry->x=0; entry->y=0; entry->z=0;
    entry->index=BILLBOARD_AddElem((struct BbBoard *)o->board,entry->id,4096,4096,(VecFx32 *)((struct Vec3 *)(&entry->x)),31,0,0);
    BILLBOARD_SetElemVisible(o->board,entry->index,&d_021F8328);
    return entry;
}

void STA_ACT_OBJ_FreeEntry(u32 *o, StaActObjEntry *entry)
{
    BILLBOARD_FreeElem(((StaActObjObject *)o)->board, entry->index);
    BILLBOARD_DeleteImage(((StaActObjObject *)o)->board, entry->id);
    entry->active=0;
}

void STA_ACT_OBJ_SetEntryTarget(void *a, StaActObjEntry *entry, u32 *target)
{
    entry->x=target[0]; entry->y=target[1]; entry->z=target[2]; entry->dirty=1;
}

void STA_ACT_OBJ_GetEntryTarget(void *a, StaActObjEntry *entry, u32 *target)
{
    target[0]=entry->x; target[1]=entry->y; target[2]=entry->z;
}
