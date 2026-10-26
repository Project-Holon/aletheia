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
#include "../ov010/musical_event_shared_types.h"
#include "mus_poke_draw_shared_types.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/arc_tool.h"

struct ArcFile;

struct Blk2C;

struct MusicalDist;



struct PokemonParam;

#include "../arm9/poke_tool.h"


#include "../arm9/musical_dist_save.h"




#include "../arm9/arc_util.h"
struct ArcHandle;




char *MUSICAL_MCSS_CreateMon(void *a,u16 heap);

char *MUSICAL_MCSS_AllocMon(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap);

MusicalSystemHead *MUSICAL_MCSS_AllocDistSave(u32 heap);

void MUSICAL_MCSS_FreeDistSave(MusicalSystemHead *p);

void MUSICAL_MCSS_LoadDistSave(MusicalSystemHead *m, void *unused, void *sys, u8 kind, u16 heap);

extern const char d_021F83E4[];

char *MUSICAL_MCSS_CreateMon(void *a,u16 heap)
{
    char *p;
    int i;
    p=GFL_HEAP_Alloc(heap,124,1,d_021F83E4,141);
    ((McssMon *)p)->kind=4;
    ((McssMon *)p)->source=a;
    ((McssMon *)p)->reserved4A=0;
    for(i=0;i<9;i++) { ((McssMon *)p)->slots[i][0]=255; ((McssMon *)p)->slots[i][1]=0; ((McssMon *)p)->values[i]=0; }
    ((McssMon *)p)->species=POKE_TOOL_GetPartyValue(a,5,0);
    ((McssMon *)p)->sex=POKE_TOOL_GetPartyValue(a,110,0);
    ((McssMon *)p)->form=POKE_TOOL_GetPartyValue(a,111,0);
    ((McssMon *)p)->isShiny=POKE_TOOL_IsShiny(a);
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
    for(i=0;i<9;i++) { ((McssMon *)p)->slots[i][0]=255; ((McssMon *)p)->slots[i][1]=0; ((McssMon *)p)->values[i]=0; }
    for(j=0;j<4;j++) ((McssMon *)p)->reserved4C[j]=0;
    ((McssMon *)p)->reserved78=0;
    ((McssMon *)p)->species=a; ((McssMon *)p)->sex=b; ((McssMon *)p)->form=c; ((McssMon *)p)->isShiny=d; ((McssMon *)p)->personalRnd=e;
    return p;
}

MusicalSystemHead *MUSICAL_MCSS_AllocDistSave(u32 heap) {MusicalSystemHead *p;void *z;z=0;p=GFL_HEAP_Alloc(heap,sizeof(*p),0,d_021F83E4,194);p->programs=z;p->msgFile=z;p->member2=z;p->payload=z;p->section0=z;p->section1=z;p->section2=z;return p;}

void MUSICAL_MCSS_FreeDistSave(MusicalSystemHead *p) {if(p->programs)GFL_HEAP_Free(p->programs);if(p->msgFile)GFL_HEAP_Free(p->msgFile);if(p->member2)GFL_HEAP_Free(p->member2);if(p->payload)GFL_HEAP_Free(p->payload);GFL_HEAP_Free(p);}

void MUSICAL_MCSS_LoadDistSave(MusicalSystemHead *m, void *unused, void *sys, u8 kind, u16 heap)
{
    void *x;
    void *arc;
    u32 c, d, e;
    u8 *q;
    m->kind = kind;
    if (kind >= 4) {
        x = MUSICAL_DIST_SAVE_Create(sys, heap);
        arc = ARC_TOOL_CreateHandleFromMemory(MUSICAL_DIST_SAVE_GetPayload(x), MUSICAL_DIST_SAVE_GetPayloadSize(x), (u16)((heap & 0x7fff) | 0x8000));
    } else {
        arc = ARC_TOOL_CreateHandle(kind + 0x6f, (u16)((heap & 0x7fff) | 0x8000));
    }
    m->programs = ARC_UTIL_LoadHandleMemberWithSize(arc, 0, 0, heap, &m->size0);
    m->msgFile = ARC_UTIL_LoadHandleMemberWithSize(arc, 1, 0, heap, &m->size1);
    m->member2 = ARC_UTIL_LoadHandleMemberWithSize(arc, 2, 0, heap, &m->size2);
    c = ARC_TOOL_GetHandleMemberSize(arc, 4);
    d = ARC_TOOL_GetHandleMemberSize(arc, 3);
    e = ARC_TOOL_GetHandleMemberSize(arc, 5);
    m->payloadSize = c + 0xc + d + e;
    q = GFL_HEAP_Alloc(heap, m->payloadSize, 1, d_021F83E4, 0x104);
    m->payload = q;
    m->section0 = q + 0xc;
    m->section1 = q + 0xc + c;
    m->section2 = (u8 *)(d + (uptr)m->section1);
    *(u32 *)q = c;
    *(u32 *)(q + 4) = d;
    *(u32 *)(q + 8) = e;
    ARC_TOOL_ReadHandleMember(arc, 4, m->section0);
    ARC_TOOL_ReadHandleMember(arc, 3, m->section1);
    ARC_TOOL_ReadHandleMember(arc, 5, m->section2);
    ARC_TOOL_DeleteHandle(arc);
    if (kind >= 4) MUSICAL_DIST_SAVE_Delete(x);
}
