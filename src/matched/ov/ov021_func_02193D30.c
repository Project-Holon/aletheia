/*
 * function: FIELD_WFBC_SetUpPeople
 * address:  0x02193D30
 * packet:   pkt_ov021_02193D30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_IsDataComplete  0x0218625C  thumb  ov020
 *   FIELD_WFBC_Clear  0x02193CBC  thumb  ov021
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid  0x02161ECC  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_LoadNpcData  0x02186818  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetPositionPair  0x02186844  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetNpcRecord  0x0218682C  thumb  ov020
 *   FIELD_WFBC_PEOPLE_SetUp  0x02193F80  thumb  ov021
 *   FIELD_WFBC_BLOCK_InitRand  0x02194084  thumb  ov021
 *   FIELD_WFBC_BLOCK_BuildGrid  0x02194128  thumb  ov021
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   sBlockTableMemberIds     0x021D3F58  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00485.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 a; u8 b; u8 rest[0x16]; } E18;
typedef struct { u16 h0; u16 h1; u32 w4; E18 A[10]; E18 B[10]; } Src;

extern int sBlockTableMemberIds[];
struct E50;
extern int FIELD_WFBC_DATA_LOCAL_IsDataComplete(unsigned short *p);
extern void FIELD_WFBC_Clear(u8 *o);
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(E18 *p);
struct ArcFile;
extern void FIELD_WFBC_DATA_LOCAL_LoadNpcData(u32 *p, u32 member);
extern u8 *FIELD_WFBC_DATA_LOCAL_GetPositionPair(u8 *t, int i);
extern char *FIELD_WFBC_DATA_LOCAL_GetNpcRecord(char *p);
extern void FIELD_WFBC_PEOPLE_SetUp(struct E50 *e, void *a, u8 *b, void *c);
extern void FIELD_WFBC_BLOCK_InitRand(u8 *p, Src *s, int h);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern void FIELD_WFBC_BLOCK_BuildGrid(u8 *p, int a, u8 *b);

void FIELD_WFBC_SetUpPeople(u8 *o, Src *s, int which)
{
    int i;
    int off;
    u8 *pair;

    FIELD_WFBC_DATA_LOCAL_IsDataComplete((short unsigned int *)s);
    FIELD_WFBC_Clear(o);
    o[0] = s->h1;
    o[1] = which;
    for (i = 0; i < 10; i++) {
        if (which == 0) {
            off = i * 0x18;
            if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((E18 *)((u8 *)s->A + off))) {
                FIELD_WFBC_DATA_LOCAL_LoadNpcData((u32 *)(((struct Obj00485 *)o)->fC), s->A[i].b);
                FIELD_WFBC_PEOPLE_SetUp((struct E50 *)(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50), (E18 *)((u8 *)s->A + off),
                              FIELD_WFBC_DATA_LOCAL_GetPositionPair(*(u8 * *)&((struct Obj00485 *)o)->f118, i),
                              (u16 *)FIELD_WFBC_DATA_LOCAL_GetNpcRecord((char *)(((struct Obj00485 *)o)->fC)));
            }
        } else {
            off = i * 0x18;
            if (EVENT_FIELD_PROCLINK_IsReturnEntryValid((E18 *)((u8 *)s->B + off))) {
                FIELD_WFBC_DATA_LOCAL_LoadNpcData((u32 *)(((struct Obj00485 *)o)->fC), s->B[i].b);
                pair = FIELD_WFBC_DATA_LOCAL_GetPositionPair(*(u8 * *)&((struct Obj00485 *)o)->f118, i);
                FIELD_WFBC_DATA_LOCAL_GetNpcRecord((char *)(((struct Obj00485 *)o)->fC));
                FIELD_WFBC_PEOPLE_SetUp((struct E50 *)(*(u8 * *)&((struct Obj00485 *)o)->f4 + i * 0x50), (E18 *)((u8 *)s->B + off),
                              pair, (u16 *)FIELD_WFBC_DATA_LOCAL_GetNpcRecord((char *)(((struct Obj00485 *)o)->fC)));
            }
        }
    }
    FIELD_WFBC_BLOCK_InitRand(o + 0x11c, s, ((struct Obj00485 *)o)->fC);
    if (which == 0)
        *(Src * *)&((struct Obj00485 *)o)->f8 = s;
    else
        *(Src * *)&((struct Obj00485 *)o)->f8 = 0;
    ARC_TOOL_GetHandleMemberSize((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), sBlockTableMemberIds[o[0]]);
    ARC_TOOL_ReadHandleMember((struct ArcFile *)(*(int *)&((struct Obj00485 *)o)->f10), sBlockTableMemberIds[o[0]], (void *)(*(int *)&((struct Obj00485 *)o)->f14));
    FIELD_WFBC_BLOCK_BuildGrid(o + 0x11c, *(int *)&((struct Obj00485 *)o)->f14, o + 0x18);
}
