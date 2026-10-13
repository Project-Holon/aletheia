/*
 * function: UNION_ONESELF_JoinMain
 * address:  0x0217D314
 * packet:   pkt_ov019_0217D314
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_CHARA_GetBeaconIndex  0x0217AEFC  thumb  ov019
 *   UNION_ONESELF_CheckNetError  0x0217BB04  thumb  ov019
 *   UNION_COMM_SetGameKindByStatus  0x021736E0  thumb  ov012
 *   GFL_NET_SetChangeoverModeWrapper  0x0203D14C  arm
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   UNION_MSG_GetCategoryTableValue  0x0217F060  thumb  ov019
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   UNION_COMM_SetSituationParam  0x021734A8  thumb  ov012
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb  ov019
 *   func_02034714  0x02034714  arm
 *   func_020362DC  0x020362DC  arm
 *   func_0217EE40  0x0217EE40  thumb  ov019
 *   func_0217EE1C  0x0217EE1C  thumb  ov019
 *   func_0217EDF8  0x0217EDF8  thumb  ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb  ov019
 *   UNION_COMM_RequestRestart  0x02172D20  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   gUnionEmptyString1     0x021807E4  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad00[7];
    u8 x0 : 3;
    u8 b3 : 1;
} Sub;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 pad2e[0x58 - 0x2e];
    u16 f58;
    u8 b0 : 1;
    u8 b1 : 1;
    u8 pad5b[0x6c - 0x5b];
    s16 f6c;
} Obj;

extern u16 UNION_CHARA_GetBeaconIndex(unsigned int x);
struct Link;
extern int UNION_ONESELF_CheckNetError(char *p);
extern void UNION_COMM_SetGameKindByStatus(unsigned int x);
extern void GFL_NET_SetChangeoverModeWrapper(int a, int b, u8 *c);
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
extern int GFL_NET_GetNegotiationNum(void);
extern void GFL_NET_SetLoginOption(u8 a0);
extern int UNION_MSG_GetCategoryTableValue(int i);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
extern int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020362DC(void);
extern u16 func_0217EE40(int i);
extern u16 func_0217EE1C(int i);
extern u16 func_0217EDF8(int i);
extern void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
extern void UNION_COMM_RequestRestart(u8 *a);
extern int UNION_COMM_IsResetting(u8 *a);
extern u8 gUnionEmptyString1[];

int UNION_ONESELF_JoinMain(u8 *a, Obj *b, u8 *c, u8 *d)
{
    int idx;
    int n;
    idx = UNION_CHARA_GetBeaconIndex(b->f58);
    if (UNION_ONESELF_CheckNetError((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        b->b0 = 1;
        UNION_COMM_SetGameKindByStatus(b->f2d);
        GFL_NET_SetChangeoverModeWrapper(2, 1, a + 0x2974 + idx * 0x8c);
        b->f6c = 0;
        (*d)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(a) == 0)
            break;
        if (GFL_NET_GetNegotiationNum() > 1) {
            GFL_NET_SetLoginOption(1);
            n = UNION_MSG_GetCategoryTableValue(b->f2d);
            if (n <= (int)GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {
                *d = 4;
            } else {
                UNION_COMM_SetSituationParam(a, 3, (u32)(a + 0x2910 + idx * 0x8c));
                b->b1 = 1;
                switch (b->f2d) {
                case 0x14:
                    UNION_ONESELF_SetNextPlayCategory((char *)a, (int)0x1f);
                    break;
                case 0x15:
                    UNION_ONESELF_SetNextPlayCategory((char *)a, (int)0x20);
                    break;
                case 0x16:
                    UNION_ONESELF_SetNextPlayCategory((char *)a, (int)0x21);
                    break;
                case 0x17:
                    UNION_ONESELF_SetNextPlayCategory((char *)a, (int)0x22);
                    break;
                case 3:
                    UNION_ONESELF_SetNextPlayCategory((char *)a, (int)0xe);
                    break;
                case 0x19:
                    UNION_ONESELF_SetNextPlayCategory((char *)a, (int)0x24);
                    break;
                default:
                    func_02034714((const char *)gUnionEmptyString1, (int)0, (const char *)gUnionEmptyString1);
                    break;
                }
                *d = 3;
            }
        } else {
            b->f6c++;
            if (b->f6c > 600 || (func_020362DC() & 2)) {
                b->b0 = 0;
                UNION_ONESELF_SetNextPlayCategory((char *)a, (int)0);
                *d = 4;
            }
        }
        break;
    case 2:
        switch (b->f2d) {
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            UNION_MSG_SetupPrintTalkMsg(a, c, func_0217EE40(b->f14->b3));
            break;
        case 3:
            UNION_MSG_SetupPrintTalkMsg(a, c, func_0217EE1C(b->f14->b3));
            break;
        case 0x19:
            UNION_MSG_SetupPrintTalkMsg(a, c, func_0217EDF8(b->f14->b3));
            break;
        }
        *d = 3;
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(a) == 1)
            return 1;
        break;
    case 4:
        UNION_COMM_RequestRestart(a);
        (*d)++;
        break;
    case 5:
        if (UNION_COMM_IsResetting(a) == 0)
            *d = 2;
        break;
    }
    return 0;
}
