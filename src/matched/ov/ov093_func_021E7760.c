/*
 * unit:     yes
 * function: HAND_WAZA_ShellSmashChangeStats, HAND_WAZA_AddReflectType
 * address:  0x021E7760
 * packet:   pkt_ov093_021E7760
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   d_021F2714     0x021F2714  data   ov093  a4
 */
#include "../include/Obj00663.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int d_021F2714[];

void HAND_WAZA_ShellSmashChangeStats(int a, int b, int c)
{
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 2;
        ((struct Obj00663 *)p)->fC = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 4;
        ((struct Obj00663 *)p)->fC = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 1;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 3;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
        ((struct Obj00663 *)p)->f4 = 5;
        ((struct Obj00663 *)p)->fC = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    }
}

int *HAND_WAZA_AddReflectType(int *p)
{
    *p = 1;
    return d_021F2714;
}
