/*
 * file:     mus_item_data.c
 * unit:     yes
 * function: MUSICAL_MCSS_LoadActorData, MUSICAL_MCSS_FreeActorData, MUSICAL_MCSS_GetElemPtr, MUSICAL_MCSS_GetOffset, MUSICAL_MCSS_NoOp6, MUSICAL_MCSS_SetModeA, MUSICAL_MCSS_SetModeB, MUSICAL_MCSS_SetModeC, MUSICAL_MCSS_GetStateA, MUSICAL_MCSS_GetStateB, MUSICAL_MCSS_GetIndex, MUSICAL_MCSS_GetElemA, MUSICAL_MCSS_GetElemB, MUSICAL_MCSS_GetElemC
 * address:  0x021F4F14
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
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   d_021F83B4 0x021F83B4 data a1
 */
#include "musical_shot_sys_shared_types.h"
#include "mus_item_draw_shared_types.h"

extern u32 GFL_HEAP_Free(void *p);

typedef signed char s8;

/* A 12-byte element data record (MUSICAL_MCSS_GetElemPtr stride 0x0C). */
typedef struct McssElemData {
    u32 field0;             /* 0x00 */
    s8 offsetX;             /* 0x04 MUSICAL_MCSS_GetOffset x */
    s8 offsetY;             /* 0x05 MUSICAL_MCSS_GetOffset y */
    u16 flags;              /* 0x06 MUSICAL_MCSS_GetStateA/B bits */
    u8 textGroup;   /* 0x08 MUSICAL_MCSS_GetElemC */
    u8 category;    /* 0x09 MUSICAL_MCSS_GetElemA */
    u8 animKind;    /* 0x0A MUSICAL_MCSS_GetElemB */
    u8 fieldB;              /* 0x0B */
} McssElemData;

/* The 8-byte actor data wrapper returned by MUSICAL_MCSS_LoadActorData; both
   words hold the loaded elem table. */
typedef struct McssActorData {
    void *handle;           /* 0x00 */
    void *table;            /* 0x04 MUSICAL_MCSS_GetElemPtr base */
} McssActorData;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern int ARC_UTIL_LoadMember(int archiveID, int memberIdx, int decompress, int heapID);

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

int MUSICAL_MCSS_GetIndex(unsigned index);

unsigned char MUSICAL_MCSS_GetElemA(void *p, int i);

unsigned char MUSICAL_MCSS_GetElemB(void *p, int i);

unsigned char MUSICAL_MCSS_GetElemC(void *p, int i);

extern char d_021F83B4[];

u32 *MUSICAL_MCSS_LoadActorData(int heap)
{
    u32 *p = GFL_HEAP_Alloc(heap, 8, 0, d_021F83B4, 0x47);
    int r = ARC_UTIL_LoadMember(45, 0x65, 0, heap);
    p[0] = r;
    p[1] = r;
    return p;
}

void MUSICAL_MCSS_FreeActorData(void **p) { GFL_HEAP_Free(*p); GFL_HEAP_Free(p); }

u8 *MUSICAL_MCSS_GetElemPtr(u8 *p, int i) { return *(u8 * *)&((McssActorData *)p)->table + i * 0xc; }

void MUSICAL_MCSS_GetOffset(u8 *elemData, McssOffset *out)
{
    out->x = ((McssElemData *)elemData)->offsetX;
    out->y = ((McssElemData *)elemData)->offsetY;
}

/*
 * follower: MUSICAL_MCSS_SetModeA filed separately.
 */
int MUSICAL_MCSS_NoOp6(int *p) { return *p; }

int MUSICAL_MCSS_SetModeA(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 4) return 1; break;
    case 4: if (p[3] & 8) return 1; break;
    case 5: if (p[3] & 16) return 1; break;
    case 6: if (p[3] & 32) return 1; break;
    case 7: case 8: if (p[3] & 64) return 1; break;
    case 9: return 0;
    }
    return 0;
}

int MUSICAL_MCSS_SetModeB(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 12) return 1; break;
    case 4: if (p[3] & 16) return 1; break;
    case 5: if (p[3] & 32) return 1; break;
    case 6: case 7: if (p[3] & 64) return 1; break;
    case 8: return 0;
    }
    return 0;
}

int MUSICAL_MCSS_SetModeC(u8 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[8] == 0) return 1; break;
    case 2: if (p[8] == 1) return 1; break;
    case 3: if ((u8)(p[8] + 254) <= 1) return 1; break;
    case 4: if (p[8] == 4) return 1; break;
    case 5: if (p[8] == 5) return 1; break;
    case 6: case 7: if (p[8] == 6) return 1; break;
    case 8: return 0;
    }
    return 0;
}

int MUSICAL_MCSS_GetStateA(const unsigned char *elemData)
{
    if (*(const unsigned short *)&((McssElemData *)elemData)->flags & 0x80)
        return 1;
    return 0;
}

int MUSICAL_MCSS_GetStateB(const unsigned char *elemData)
{
    if (*(const unsigned short *)&((McssElemData *)elemData)->flags & 0x200)
        return 1;
    return 0;
}

/*
 * leaf: Sole unresolved ov112 mapper for concrete-correct ov133 DUP_FITTING_MoveElem; root reserved ownership.
 */
int MUSICAL_MCSS_GetIndex(unsigned index)
{
    switch (index) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3:
    case 4: return 3;
    case 5: return 4;
    case 6: return 5;
    case 7: return 6;
    case 8: return 7;
    case 9: return 8;
    default: return 9;
    }
}

unsigned char MUSICAL_MCSS_GetElemA(void *p, int i)
{
    return *(unsigned char *)(MUSICAL_MCSS_GetElemPtr(p, i) + 9);
}

unsigned char MUSICAL_MCSS_GetElemB(void *p, int i)
{
    return *(unsigned char *)(MUSICAL_MCSS_GetElemPtr(p, i) + 10);
}

unsigned char MUSICAL_MCSS_GetElemC(void *p, int i)
{
    return *(MUSICAL_MCSS_GetElemPtr(p, i) + 8);
}
