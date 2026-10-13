/*
 * function: UNION_ONESELF_TalkParentAnswerWaitMain
 * address:  0x0217C450
 * packet:   pkt_ov019_0217C450
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_CheckNetError  0x0217BB04  thumb ov019
 *   UNION_COMMAND_SendPartnerSelectA  0x02173A04  thumb ov012
 *   UNION_ONESELF_SetNextPlayCategory  0x0217B8E4  thumb ov019
 *   func_0217EC40  0x0217EC40  thumb ov019
 *   func_0217EC54  0x0217EC54  thumb ov019
 *   UNION_MSG_SetupPrintTalkMsg  0x0217F210  thumb ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb ov019
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[7];
    u8 lo : 3;
    u8 flag : 1;
} Sub;

typedef struct {
    u8 pad00[0x14];
    Sub *f14;
    u8 pad18[0x2d - 0x18];
    u8 f2d;
    u8 f2e;
} Obj;

typedef unsigned short u16;
typedef unsigned int   u32;
int UNION_ONESELF_CheckNetError(char *p);
int UNION_COMMAND_SendPartnerSelectA(int a, ...);
int UNION_ONESELF_SetNextPlayCategory(char *p, int v);
u16 func_0217EC40(int i, int j);
u16 func_0217EC54(int i, int j);
void UNION_MSG_SetupPrintTalkMsg(u8 *p, u8 *a, u32 b);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);

int UNION_ONESELF_TalkParentAnswerWaitMain(void *ctx, Obj *obj, u8 *a2, u8 *state)
{
    if (UNION_ONESELF_CheckNetError(ctx) == 1)
        return 1;

    switch (*state) {
    case 0:
        if (UNION_COMMAND_SendPartnerSelectA(obj->f2d) == 1) {
            if (obj->f2d == 0) {
                UNION_ONESELF_SetNextPlayCategory(ctx, 0x27);
                return 1;
            }
            UNION_MSG_SetupPrintTalkMsg(ctx, a2, func_0217EC40(obj->f2d, obj->f14->flag));
            (*state)++;
        }
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) != 0) {
            if (obj->f2e == 1) {
                UNION_ONESELF_SetNextPlayCategory(ctx, obj->f2d + 11);
                (*state)++;
            } else if (obj->f2e == 0) {
                UNION_ONESELF_SetNextPlayCategory(ctx, 0x27);
                UNION_MSG_SetupPrintTalkMsg(ctx, a2, func_0217EC54(obj->f2d, obj->f14->flag));
                return 1;
            }
        }
        break;
    case 2:
        if (UNION_MSG_CheckTalkPrintEnd(ctx) == 1)
            return 1;
        break;
    }
    return 0;
}
