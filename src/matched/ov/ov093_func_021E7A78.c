/*
 * unit: yes
 * function: func_021E7A78, func_021E7B34
 * address: 0x021E7A78
 * packet: pkt_ov093_021E7A78
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the byte-valued count remains u8; +7 is a one-bit field assignment.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeIdAtPos 0x021C7D34 thumb ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds 0x021C7F68 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   d_021F2634 0x021F2634 data a4
 */
#include "../include/Obj10101.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern int BTL_SERVER_FLOW_GetPokeIdAtPos(char *p, int i);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *, int, u8 *);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int d_021F2634[];

void func_021E7A78(int a, int b, int c)
{
    u8 list[4];
    u8 k, i;
    u8 n;
    int slot;
    u8 *x;
    u8 *p;
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(4);
        slot = BTL_SERVER_FLOW_GetPokeIdAtPos((char *)b, k);
        if (slot != 6) {
            n = BTL_SERVER_FLOW_CollectAlivePokeIds((int *)b, (u16)(0x900 | slot), list);
            for (i = 0; i < n; i++) {
                if (list[i] != k) {
                    x = BTL_SERVER_FLOW_GetPokeParam((int *)b, list[i]);
                    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 7, c);
                    p[6] = list[i];
                    ((struct Obj10101 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(x, 16);
                    ((struct Flag { u8 bit : 1; } *)(p + 7))->bit = 1;
                    BTL_SERVER_FLOW_InitMsgRecord(p + 12, 2, 0x451);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), p[6]);
                    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
                }
            }
        }
    }
}

int *func_021E7B34(int *p)
{
    *p = 1;
    return d_021F2634;
}
