/*
 * function: HAND_WAZA_PledgeApplyCombinedEffect
 * address: 0x021E84FC
 * packet: pkt_ov093_021E84FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: byte locals plus declaration order restore the spill/register assignment.
 * permuter: rejected added return target; transferred only declarations and two temporaries.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTLV_CORE_MakeSlotKind2Index 0x021E8940 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtPos 0x021C7D34 thumb ov093
 */
#include "../include/Obj07838.h"
#include "../include/Obj21548.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int BTL_EVENT_GetVar(int);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern Word BTLV_CORE_MakeSlotKind2Index(int);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_SERVER_FLOW_GetPokeIdAtPos(char *p, int i);
void HAND_WAZA_PledgeApplyCombinedEffect(int a, int b, int c, const int *d)
{
    int tmp;
    u8 *p;
    u8 selected;
    int code;
    u8 own;
    u8 other;
    int target;
    int slot;
    u8 message;
    u8 mode;
    u8 *tmp1;
    if (c == BTL_EVENT_GetVar(3) && d[0] != 0) {
        mode = 14;
        own = BTL_MAIN_IsPokeIdInSecondPair(c);
        other = BTL_MAIN_IsPokeIdInSecondPair((u8)BTL_EVENT_GetVar(6));
        code = 0;
        message = 0;
        target = 31;
        switch (d[1]) {
        case 1:
            message = 0xa4;
            mode = 11;
            selected = own;
            code = 0x28d;
            target = c;
            break;
        case 2:
            message = 0xa8;
            selected = other;
            mode = 12;
            code = 0x28e;
            target = (u8)BTL_EVENT_GetVar(6);
            break;
        case 3:
            message = 0xac;
            selected = other;
            mode = 13;
            code = 0x28f;
            target = (u8)BTL_EVENT_GetVar(6);
            break;
        }
        if (mode != 14) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 25, c);
            ((struct Obj07838 *)p)->f4 = mode;
            p[12] = selected;
            *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind2Index(4);
            BTL_SERVER_FLOW_InitMsgRecord(p + 16, 1, message);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 16), selected);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
            if (target != 31) {
                tmp = BTL_SERVER_FLOW_GetPokeIdAtPos((char *)b, target);
                slot = tmp;
                if (slot != 6) {
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x37, c);
                    p[6] = slot;
                    p[7] = 6;
                    tmp1 = p + 4;
                    ((struct Obj21548 *)tmp1)->f0 = code;
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
            }
        }
    }
}
