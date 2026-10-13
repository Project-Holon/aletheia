/*
 * function: FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain
 * address:  0x021871F8
 * packet:   pkt_ov020_021871F8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The step callback FIELD_WFBC_DATA_LOCAL_CreatePersonTalkEvent registers (func_020122C0's third
 * argument) for the 0x58-byte work block it fills.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending  0x021620A0  thumb  ov010
 *   EVENT_FIELD_PROCLINK_RequestReturn  0x02162048  thumb  ov010
 *   EVENT_FIELD_PROCLINK_HasReturnDefaultSlot  0x0216208C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType  0x0216209C  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_StartTalkMessage  0x0218741C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CountPeople  0x02186278  thumb  ov020
 *   EVENT_FIELD_PROCLINK_HasEventdataEntry  0x02161E4C  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice  0x0218748C  thumb  ov020
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   EVENT_FIELD_PROCLINK_ApplyReturnEntry  0x02161F90  thumb  ov010
 *   FIELD_WFBC_RemovePeople  0x02193B20  thumb  ov021
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage  0x02187508  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_FreeTalkMessage  0x021875B8  thumb  ov020
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Ctx;
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending(int a0);
typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct Rec;
struct U16Vec;
struct WordSet;
void EVENT_FIELD_PROCLINK_RequestReturn(u16 *a, int b, int c);
int EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(char *p, int unused);
u16 EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(char *p);
void FIELD_WFBC_DATA_LOCAL_StartTalkMessage(char *p, int a1, int *out, int a3);
int FIELD_WFBC_DATA_LOCAL_CountPeople(char *p, int which);
int EVENT_FIELD_PROCLINK_HasEventdataEntry(void *a0, int id, unsigned mode);
void FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice(char *p, int a1, int *out, int a3, u16 a4);
void FADE_Start(u32 a, s32 b, s32 c, s32 d);
int FADE_IsActive(void);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u8 *GAME_DATA_GetMyStatus(void *p);
void EVENT_FIELD_PROCLINK_ApplyReturnEntry(int unused, u16 *x, char *y, int z, u16 w, u16 v);
int FIELD_WFBC_RemovePeople(u32 a, u32 b);
void FLDMMDL_DeleteMmdl(void *a);
int FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage(char *p);
int FIELD_WFBC_DATA_LOCAL_FreeTalkMessage(char *p);
void STRBUF_Delete(struct U16Vec *vec);
u32 MSGDATA_Delete(struct Rec *rec);
u32 func_0201ED04(struct WordSet *p);

#define P(o)  (*(void **)(o))
#define P18   (*(void **)(o + 0x18))
#define P1C   (*(void **)(o + 0x1c))
#define P20   (*(void **)(o + 0x20))
#define P24   (*(void **)(o + 0x24))
#define P28   (*(void **)(o + 0x28))
#define P30   (*(void **)(o + 0x30))
#define P40   (*(void **)(o + 0x40))
#define P44   (*(void **)(o + 0x44))
#define P48   (*(void **)(o + 0x48))
#define H08   (*(u16 *)(o + 0x08))
#define H4C   (*(u16 *)(o + 0x4c))
#define H4E   (*(u16 *)(o + 0x4e))
#define H50   (*(u16 *)(o + 0x50))
#define B54   (*(u8 *)(o + 0x54))
#define B56   (*(u8 *)(o + 0x56))

int FIELD_WFBC_DATA_LOCAL_PersonTalkEventMain(void *a, int *st, char *o)
{
    if (INTRUDE_COMM_GetWorkIfRunning((int)((void *)GAMESYSTEM_GetGameComm(P(o)))) == 0 && B56 != 0)
        *st = 0x11;

    switch (*st) {
    case 0:
        EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending((int)P40);
        EVENT_FIELD_PROCLINK_RequestReturn(P40, H4C, 0);
        *st = 1;
        break;
    case 1:
        if (EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(P40, H4C) == 0)
            break;
        if (EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(P40) == 0)
            *st = 3;
        else
            *st = 2;
        break;
    case 2:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(o, 0, st, 0x11);
        break;
    case 3:
        if (((u16 *)P44)[1] != ((u16 *)P48)[1])
            *st = 5;
        else
            *st = 4;
        break;
    case 4:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(o, 1, st, 0x11);
        break;
    case 5:
        if ((unsigned int)FIELD_WFBC_DATA_LOCAL_CountPeople(P44, 0) >= 10) {
            *st = 6;
            break;
        }
        if (EVENT_FIELD_PROCLINK_HasEventdataEntry(P44, H4C, 2) != 0)
            *st = 6;
        else
            *st = 7;
        break;
    case 6:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(o, 2, st, 0x11);
        break;
    case 7:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice(o, 3, st, 9, 8);
        break;
    case 8:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(o, 4, st, 0x11);
        break;
    case 9:
        EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending((int)P40);
        EVENT_FIELD_PROCLINK_RequestReturn(P40, H4C, 1);
        *st = 10;
        break;
    case 10:
        if (EVENT_FIELD_PROCLINK_HasReturnDefaultSlot(P40, H4C) == 0)
            break;
        if (EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType(P40) == 2)
            *st = 12;
        else
            *st = 11;
        break;
    case 11:
        B56 = 0;
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(o, 5, st, 0x11);
        break;
    case 12:
        FIELD_WFBC_DATA_LOCAL_StartTalkMessage(o, 7, st, 0xd);
        EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending((int)P40);
        EVENT_FIELD_PROCLINK_RequestReturn(P40, H4C, 2);
        B56 = 0;
        break;
    case 13:
        FADE_Start(1, 0, 0x10, 0);
        *st = 14;
        break;
    case 14:
        if (FADE_IsActive() != 0)
            break;
        EVENT_FIELD_PROCLINK_ApplyReturnEntry((int)P40, P44, P48, (int)GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(P(o))), H4C, H08);
        FIELD_WFBC_RemovePeople((u32)P28, H4C);
        FLDMMDL_DeleteMmdl(P30);
        FADE_Start(1, 0x10, 0, 0);
        *st = 15;
        break;
    case 15:
        if (FADE_IsActive() != 0)
            break;
        *st = 0x11;
        break;
    case 16:
        if (FIELD_WFBC_DATA_LOCAL_UpdateTalkMessage(o) == 0)
            break;
        if (B54)
            *st = H4E;
        else
            *st = H50;
        break;
    case 17:
        if (FIELD_WFBC_DATA_LOCAL_FreeTalkMessage(o) == 0)
            break;
        STRBUF_Delete(P20);
        STRBUF_Delete(P24);
        MSGDATA_Delete(P18);
        func_0201ED04(P1C);
        return 1;
    }
    return 0;
}
