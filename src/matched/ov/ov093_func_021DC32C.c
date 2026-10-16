/*
 * unit: yes
 * function: HAND_TOKUSEI_Moody_RaiseAndLowerStat, HAND_TOKUSEI_GetMoodyHandlers
 * address: 0x021DC32C
 * packet: pkt_ov093_021DC32C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   BTL_POKEPARAM_CanChangeStatStage 0x021D5D14 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord 0x021C88B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gMoodyHandlers 0x021F0658 data a4
 * Pointer-sum grouping preserves both candidate-list load sequences.
 * Signed byte storage of -1 preserves the subtraction from the live one.
 */
#include "../include/Obj03701.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *p, int b);
extern int BTL_POKEPARAM_CanChangeStatStage(s8 *p, int i, int sign);
extern u32 BTL_CALC_Random(u32 k);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
void HAND_TOKUSEI_Moody_RaiseAndLowerStat(int a, void *b, u8 c)
{
    u8 *buf;
    void *m;
    u8 n1;
    u8 n2;
    u32 i;
    u8 n;
    u32 j;
    u8 first;
    u8 second;
    u16 pair;
    u8 *r;
    if (c == BTL_EVENT_GetVar(2)) {
        buf = BTL_SERVER_FLOW_GetScratchBuffer(b, 0xb6);
        m = BTL_SERVER_FLOW_GetPokeParam(b, c);
        n2 = 0;
        n1 = 0;
        for (i = 0; i < 7; i++) {
            if (BTL_POKEPARAM_CanChangeStatStage(m, i + 1, 1)) buf[0xa8 + n1++] = i + 1;
            if (BTL_POKEPARAM_CanChangeStatStage(m, i + 1, -1)) buf[0xaf + n2++] = i + 1;
        }
        second = 0;
        first = 0;
        if (n1 == 0 && n2 != 0) {
            second = (buf + BTL_CALC_Random(n2))[0xaf];
        } else if (n1 != 0 && n2 == 0) {
            first = (buf + BTL_CALC_Random(n1))[0xa8];
        } else if (n1 != 0 && n2 != 0) {
            n = 0;
            for (i = 0; i < n1; i++) {
                for (j = 0; j < n2; j++) {
                    if (buf[0xa8 + i] != buf[0xaf + j]) {
                        ((u16 *)buf)[n++] = (buf[0xa8 + i] << 8) | buf[0xaf + j];
                        if (n >= 0x54) break;
                    }
                }
            }
            pair = ((u16 *)buf)[BTL_CALC_Random(n)];
            first = pair >> 8;
            second = pair;
        }
        BTL_SERVER_FLOW_PushCmdRecord(b, 2, c);
        if (first) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 14, c);
            r[15] = 1;
            r[16] = c;
            ((struct Obj03701 *)r)->f4 = first;
            r[12] = 2;
            BTL_SERVER_FLOW_CommitCmdRecord(b, r);
        }
        if (second) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 14, c);
            r[15] = 1;
            r[16] = c;
            ((struct Obj03701 *)r)->f4 = second;
            *(s8 *)&((struct Obj03701 *)r)->fC = -1;
            BTL_SERVER_FLOW_CommitCmdRecord(b, r);
        }
        BTL_SERVER_FLOW_PushCmdRecord(b, 3, c);
    }
}
extern u8 gMoodyHandlers[];
void *HAND_TOKUSEI_GetMoodyHandlers(int *p) { *p = 1; return gMoodyHandlers; }
