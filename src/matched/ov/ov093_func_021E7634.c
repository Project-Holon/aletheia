/*
 * unit: yes
 * function: HAND_WAZA_SmackDownGroundTarget, HAND_WAZA_AddShellSmash
 * address: 0x021E7634
 * packet: pkt_ov093_021E7634
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: BTLV_CORE_MakeSlotKind1Empty returns a one-word aggregate, reserving its frame temporary.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_IsPokeAfflictedByStatus 0x021C8374 thumb ov093
 *   BTL_SERVER_FLOW_IsPokeGroundedById 0x021C8234 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 *   BTLV_CORE_MakeSlotKind1Empty 0x021E89C0 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   d_021F274C 0x021F274C data a4
 */
#include "../include/Obj02139.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(u8 *p, int i);
extern int BTL_SERVER_FLOW_IsPokeGroundedById(u8 *p, int i);
struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern Word BTLV_CORE_MakeSlotKind1Empty(u32);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int d_021F274C[];
void HAND_WAZA_SmackDownGroundTarget(int a, int b, int c)
{
    u8 k;
    void *x;
    int flag;
    u8 *p;
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        x = BTL_SERVER_FLOW_GetPokeParam((int *)b, k);
        flag = 0;
        if (BTL_SERVER_FLOW_IsPokeAfflictedByStatus((u8 *)b, k) == 0) {
            if (BTL_SERVER_FLOW_IsPokeGroundedById((u8 *)b, k) != 0 && BTL_POKEPARAM_HasSick(x, 0x21) == 0) {
                p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 12, c);
                p[15] = k;
                ((struct Obj02139 *)p)->f4 = 0x1f;
                *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind1Empty(0x1f);
                BTL_SERVER_FLOW_InitMsgRecord(p + 20, 2, 0x468);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 20), k);
                BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                flag = 1;
                if (BTL_POKEPARAM_HasSick(x, 0x1e) != 0) {
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 11, c);
                    p[20] = 1;
                    p[8] = k;
                    p[21] = 1;
                    ((struct Obj02139 *)p)->f4 = 0x1e;
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
                if (BTL_POKEPARAM_HasSick(x, 0x20) != 0) {
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 11, c);
                    p[20] = 1;
                    p[8] = k;
                    p[21] = 1;
                    ((struct Obj02139 *)p)->f4 = 0x20;
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
            }
            if (BTL_POKEPARAM_TestContFlag(x, 3) != 0) {
                p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x36, c);
                p[4] = k;
                *(int *)(p + 8) = 3;
                if (flag == 0) {
                    BTL_SERVER_FLOW_InitMsgRecord(p + 12, 2, 0x468);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), k);
                }
                BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
            }
        }
    }
}

int *HAND_WAZA_AddShellSmash(int *p)
{
    *p = 1;
    return d_021F274C;
}
