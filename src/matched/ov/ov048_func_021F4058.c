/*
 * function: GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage
 * address:  0x021F4058
 * packet:   pkt_ov048_021F4058
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_ENCOUNT_GetSwarmZoneId  0x021A9810  thumb  ov021
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   GIMMICK_OBJ_ELBOARD_AddMessage  0x021F3D38  thumb
 *   gElboardLayout     0x021F50C0  data  a4
 */
#include "../include/Obj00270.h"
#include "../include/G_T.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct WordSet;
extern u16 FIELD_ENCOUNT_GetSwarmZoneId(int a);
struct BigObj;
struct MsgBank;
struct Rec;
struct U16Vec;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void GIMMICK_OBJ_ELBOARD_AddMessage(int *p, int unused, int b, int *c);
extern struct T gElboardLayout;

void GIMMICK_OBJ_ELBOARD_AddLastPlaceMessage(int *p)
{
    struct { u16 a; int b, c, d, e, f, g; } s;
    int k;
    void *h;
    u32 r7, r6;

    k = FIELD_ENCOUNT_GetSwarmZoneId(p[2]);
    if (k == 0xFFFF)
        return;
    if (k == 0x159 && GAME_DATA_GetSeason((const struct BigObj *)p[2]) == 3)
        return;
    h = GF_FONT_Create_EC64(((struct Obj00270 *)p)->f0);
    r7 = (u32)func_02045B38(0, 2, 0x59, ((struct Obj00270 *)p)->f0);
    r6 = (u32)func_02045EC0((struct MsgBank *)r7, ZONEDATA_GetPlaceNameId(k));
    WORDSET_SetSlotTag(h, 0, (const void *)r6, 0, 1, 0);
    STRBUF_Delete((struct U16Vec *)r6);
    MSGDATA_Delete((struct Rec *)r7);
    s.a = *(u16 *)(((u8 *)&gElboardLayout) + 8);
    s.b = *(int *)(((u8 *)&gElboardLayout) + 0x34);
    s.c = *(int *)(((u8 *)&gElboardLayout) + 0x50);
    s.d = 2;
    s.e = 0x26;
    s.f = *(int *)(p[7] + 0x20);
    s.g = (int)h;
    GIMMICK_OBJ_ELBOARD_AddMessage(p, (int)&s, 3, 0);
    WORDSET_DeleteStrbufED04(h);
}
