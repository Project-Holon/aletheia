/*
 * function: BTL_CLIENT_StepAskSwitchBeforeSendOut
 * address: 0x021D10B8
 * packet: pkt_ov093_021D10B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: sole-ref/code and veneer evidence cannot resolve 021D121C and
 * 021D122C; their bx-pc veneers point outside known image regions to
 * 0x0689CB14 and 0x0689CB1C. All concrete bytes in the 356-byte body match.
 * follower: 021D121C and 021D122C are bx-pc interworking veneers, not C.
 * symbols:
 *   BTL_ADAPTER_GetRecvData 0x021EEC20 thumb ov093
 *   BTLV_SCU_InitMessage 0x021EAF18 thumb ov093
 *   BTLV_SCU_AppendMessageArg 0x021EAF50 thumb ov093
 *   BTLV_SCU_SetMessageParam 0x021EAF78 thumb ov093
 *   BTLV_CORE_BuildAndPrintMessage 0x021EA614 thumb ov093
 *   BTLV_CORE_WaitMessage 0x021EA710 thumb ov093
 *   BTLV_CORE_ConsumeMessageFlag 0x021EA720 thumb ov093
 *   BTLV_CORE_StartYesNoMenu 0x021EABC4 thumb ov093
 *   BTLV_CORE_PollYesNoMenu 0x021EAC54 thumb ov093
 *   BTL_CLIENT_BuildSlotChoices 0x021D0B10 thumb ov093
 *   BTLV_CORE_StartPartyMenu 0x021E9A78 thumb ov093
 *   BTLV_CORE_PollPartyMenu 0x021E9B20 thumb ov093
 *   func_021D121C 0x021D121C thumb ov093
 *   func_021D122C 0x021D122C thumb ov093
 *   BTL_ACTION_SetChange 0x021D8394 thumb ov093
 *   BTL_CALC_ActionSetNone 0x021D8434 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_ADAPTER_GetRecvData(int, u8 **);
typedef unsigned short u16;
struct H;
struct L;
extern void BTLV_SCU_InitMessage(struct L *p, int kind, int id);
extern void BTLV_SCU_AppendMessageArg(struct L *p, u32 val);
extern void BTLV_SCU_SetMessageParam(u8 *p, u8 v);
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
extern int BTLV_CORE_WaitMessage(u32 *p);
extern int BTLV_CORE_ConsumeMessageFlag(u32 *p);
extern void BTLV_CORE_StartYesNoMenu(u8 *a, u32 x, u32 y, u32 z);
extern int BTLV_CORE_PollYesNoMenu(void *, int *);
extern void BTL_CLIENT_BuildSlotChoices(u8 *p, u32 a, u32 b, void *q, void *out);
extern void BTLV_CORE_StartPartyMenu(char *p, const u8 *q, int x, int y, u8 *r);
extern int BTLV_CORE_PollPartyMenu(u8 *p);
extern int func_021D121C(void *);
extern u32 func_021D122C(void *);
extern void BTL_ACTION_SetChange(void *, u8, u32);
extern void BTL_CALC_ActionSetNone(u32 *p);
int BTL_CLIENT_StepAskSwitchBeforeSendOut(u8 *p, int *state)
{
    u8 *args;
    int choice;
    u32 count;
    switch (*state) {
    case 0:
        BTL_ADAPTER_GetRecvData(*(int *)(p + 0x50), &args);
        if (args[0] != 0x1F) {
            BTLV_SCU_InitMessage((struct L *)(p + 0x58), 1, 0x14);
            BTLV_SCU_AppendMessageArg((struct L *)(p + 0x58), 1);
            BTLV_SCU_AppendMessageArg((struct L *)(p + 0x58), args[0]);
            BTLV_SCU_SetMessageParam(p + 0x58, 0xFF);
            BTLV_CORE_BuildAndPrintMessage(*(void **)(p + 0x54), (struct H *)(p + 0x58));
            *state = 1;
        } else *state = 4;
        break;
    case 1:
        BTLV_CORE_WaitMessage(*(void **)(p + 0x54));
        if (BTLV_CORE_ConsumeMessageFlag(*(void **)(p + 0x54)) != 0) {
            BTLV_SCU_InitMessage((struct L *)(p + 0x58), 3, 6);
            BTLV_SCU_InitMessage((struct L *)(p + 0x7C), 3, 7);
            BTLV_CORE_StartYesNoMenu(*(void **)(p + 0x54), (u32)(p + 0x58), (u32)(p + 0x7C), 1);
            *state = 2;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage(*(void **)(p + 0x54)) != 0) {
            if (BTLV_CORE_PollYesNoMenu(*(void **)(p + 0x54), &choice) != 0) {
                if (choice == 0) {
                    BTL_CLIENT_BuildSlotChoices(p, 0, 1, p + 0x184, p + 0x190);
                    BTLV_CORE_StartPartyMenu(*(void **)(p + 0x54), p + 0x184, 0, 0, p + 0x190);
                    *state = 3;
                } else *state = 4;
            }
        }
        break;
    case 3:
        if (BTLV_CORE_PollPartyMenu(*(void **)(p + 0x54)) != 0) {
            if (func_021D121C(p + 0x190) == 0) {
                count = func_021D122C(p + 0x190);
                if (count != 0 && count < 6) {
                    BTL_ACTION_SetChange(p + 0x124, 0, count);
                    *state = 5;
                } else {
invalid:
                    *state = 4;
                }
            } else goto invalid;
        }
        break;
    case 4:
        BTL_CALC_ActionSetNone((u32 *)(p + 0x124));
        *state = 5;
    case 5:
        *(u8 **)(p + 0xD8) = p + 0x124;
        *(int *)(p + 0xDC) = 4;
        return 1;
    }
    return 0;
}
