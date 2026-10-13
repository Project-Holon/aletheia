/*
 * unit:     yes
 * function: func_021E732C, func_021E737C
 * address:  0x021E732C
 * packet:   pkt_ov093_021E732C
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
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   d_021F27F4     0x021F27F4  data   ov093  a4
 */
#include "../include/Obj13541.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTLV_CORE_PackByteTwice(int a);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int d_021F27F4[];

void func_021E732C(int a, int b, int c)
{
    u32 i;
    u32 n;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        n = BTL_EVENT_GetVar(5);
        for (i = 0; i < n; i++) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x14, c);
            ((struct Obj13541 *)p)->f4 = BTLV_CORE_PackByteTwice(10);
            ((struct Obj13541 *)p)->f6 = BTL_EVENT_GetVar(i + 6);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        }
    }
}

int *func_021E737C(int *p)
{
    *p = 1;
    return d_021F27F4;
}
