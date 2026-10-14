/*
 * function: UNION_ONESELF_ConnectParentMain
 * address:  0x0217BE64
 * packet:   pkt_ov019_0217BE64
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_ONESELF_CheckNetError  0x0217BB04  thumb  ov019
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   UNION_MSG_GetNoReplyMsg  0x0217EC04  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_COMM_RequestRestart  0x02172D20  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   UNION_COMM_SetSituationParam  0x021734A8  thumb  ov012
 *   UNION_COMMAND_SendPartnerMode  0x02173AFC  thumb  ov012
 *   GFL_NET_SetChangeoverModeWrapper  0x0203D14C  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   GFL_NET_NotifyUserEvent  0x0203D1E8  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   memcmp         0x0203EFC8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef short          s16;
typedef unsigned int   u32;

typedef struct Obj {
    u8   pad00[0x18];
    u8  *p18;
    u8   pad1C[0x24 - 0x1C];
    u8   addr[6];
    u8   b2A;
    u8   pad2B[0x6C - 0x2B];
    s16  s6C;
} Obj;

typedef unsigned short u16;
extern int UNION_ONESELF_CheckNetError(char *p);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern u16 UNION_MSG_GetNoReplyMsg(void ***ctx);
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern void UNION_COMM_RequestRestart(u8 *p);
extern int UNION_COMM_IsResetting(u8 *p);
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
extern int  UNION_COMMAND_SendPartnerMode(int v);
extern void GFL_NET_SetChangeoverModeWrapper(int a, int b, void *c);
extern int  GFL_NET_GetNegotiationNum(void);
extern u32 GFL_NET_IsConnectMember(u32 index);
extern void GFL_NET_NotifyUserEvent(u32 unused, void *arg);
extern void GFL_NET_SetLoginOption(u8 a0);
extern int  GFL_NET_SYSTEM_GetConnectNum(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern int  memcmp(const void *a, const void *b, u32 n);

int UNION_ONESELF_ConnectParentMain(void *w, Obj *obj, u8 *a2, u8 *state)
{
    int i;

    if (UNION_ONESELF_CheckNetError(w) == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        GFL_NET_SetChangeoverModeWrapper(1, 1, 0);
        obj->s6C = 0;
        (*state)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(w) == 0) {
            break;
        }
        if (GFL_NET_GetNegotiationNum() > 1) {
            for (i = 2; i < 5; i++) {
                if ((int)GFL_NET_IsConnectMember((u8)i) == 1) {
                    break;
                }
            }
            if (i < 5 || GFL_NET_SYSTEM_GetConnectNum() > 2) {
                UNION_MSG_SetupPrintTalkMsg(w, a2, UNION_MSG_GetNoReplyMsg(w));
                UNION_ONESELF_SetNextPlayCategory(w, 0);
                UNION_COMM_RequestRestart(w);
                *state = 4;
            } else {
                GFL_NET_SetLoginOption(1);
                GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
                *state = 2;
            }
        } else {
            obj->s6C++;
            if (obj->s6C > 600 || (KEY_GetTrg() & 2)) {
                UNION_COMM_RequestRestart(w);
                UNION_ONESELF_SetNextPlayCategory(w, 0);
                UNION_COMM_SetSituationParam(w, 1, 0);
                if (obj->s6C > 600) {
                    UNION_MSG_SetupPrintTalkMsg(w, a2, UNION_MSG_GetNoReplyMsg(w));
                } else {
                    UNION_MSG_SetupPrintTalkMsg(w, a2, 10);
                }
                *state = 5;
            }
        }
        break;
    case 2:
        if (obj->b2A == 1) {
            if (memcmp(obj->addr, obj->p18 + 0x64, 6) != 0) {
                if (UNION_COMMAND_SendPartnerMode(2) == 1) {
                    GFL_NET_SetLoginOption(0);
                    *state = 6;
                }
            } else {
                if (UNION_COMMAND_SendPartnerMode(1) == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x806);
                    UNION_ONESELF_SetNextPlayCategory(w, 7);
                    UNION_COMM_SetSituationParam(w, 3, (u32)obj->p18);
                    UNION_COMM_SetSituationParam(w, 1, 0);
                    *state = 3;
                }
            }
        }
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(w) == 1) {
            return 1;
        }
        break;
    case 4:
        if (UNION_MSG_CheckTalkPrintEnd(w) == 1 && (KEY_GetTrg() & 0xF3)) {
            return 1;
        }
        break;
    case 5:
        if (UNION_COMM_IsResetting(w) == 0) {
            *state = 4;
        }
        break;
    case 6:
        if (GFL_NET_SYSTEM_GetConnectNum() <= 1) {
            UNION_COMM_RequestRestart(w);
            (*state)++;
        }
        break;
    case 7:
        if (UNION_COMM_IsResetting(w) == 0) {
            obj->b2A = 0;
            *state = 0;
        }
        break;
    }
    return 0;
}
