/*
 * function: FIELD_PLACE_NAME_LoadMessage
 * address:  0x021BCAB0
 * packet:   pkt_ov021_021BCAB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_GetZoneId  0x021BD118  thumb  ov021
 *   func_02013E4C  0x02013E4C  thumb
 *   FIELD_PLACE_NAME_Cancel  0x021BC5BC  thumb  ov021
 *   FIELD_PLACE_NAME_UsesIntrudeTemplate  0x021BCB48  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_GetLength  0x020458F8  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern u16 FIELD_PLACE_NAME_GetZoneId(u8 *p);
extern unsigned int func_02013E4C(unsigned int id);
extern int FIELD_PLACE_NAME_Cancel(u8 *a);
extern int FIELD_PLACE_NAME_UsesIntrudeTemplate(int *p, int b);
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *a);
extern int INTRUDE_COMM_GetWorkIfRunning(int a);
extern int GAME_DATA_GetIntrudeIdByte(int a);
extern int GAME_DATA_GetMyStatusByNetId(int a, int b);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);

void FIELD_PLACE_NAME_LoadMessage(int *p)
{
    int r6, r7;
    unsigned int r4;

    r6 = FIELD_PLACE_NAME_GetZoneId((u8 *)((int)p));
    r4 = func_02013E4C((unsigned int)r6);
    if (r4 >= 0x75) {
        r4 = 0;
    }
    if (r4 == 0) {
        FIELD_PLACE_NAME_Cancel((u8 *)p);
        return;
    }
    if (FIELD_PLACE_NAME_UsesIntrudeTemplate((int *)((int)p), r6) != 0) {
        INTRUDE_COMM_GetWorkIfRunning((int)GAMESYSTEM_GetGameComm((const struct Ctx *)p[0]));
        r7 = GAME_DATA_GetMyStatusByNetId(p[1], GAME_DATA_GetIntrudeIdByte(p[1]));
        r6 = (int)func_02045EC0((struct MsgBank *)p[5], 3);
        MSGDATA_ReadString((struct MsgBank *)p[5], r4, (void *)p[7]);
        func_0201F02C((struct WordSet *)p[2], 0, (void *)r7);
        func_0201F158((struct WordSet *)p[2], 1, r4);
        func_0201F250((struct WordSet *)p[2], (void *)p[7], (void *)r6);
        STRBUF_Delete((struct U16Vec *)r6);
    } else {
        MSGDATA_ReadString((struct MsgBank *)p[5], r4, (void *)p[7]);
    }
    *((unsigned char *)p + 0x20) = STRBUF_GetLength((struct U16Vec *)p[7]);
}
