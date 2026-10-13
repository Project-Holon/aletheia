/*
 * function: HAND_WAZA_MementoOnUncategorizedMove
 * address:  0x021E4A70
 * packet:   pkt_ov093_021E4A70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_NextSerialNumberThunk  0x021C83CC  thumb  ov093
 */
#include "../include/Obj01898.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u32 BTL_SERVER_FLOW_NextSerialNumberThunk(u8 *p);

void HAND_WAZA_MementoOnUncategorizedMove(int u, int a, int b)
{
    u8 k;
    u32 w;
    enum { E_ONE = 1 } e;
    int t;
    u8 *s;

    if (b == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        w = BTL_SERVER_FLOW_NextSerialNumberThunk((u8 *)a);
        e = E_ONE;
        s = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xe, b);
        s[0xf] = e;
        s[0x10] = k;
        ((struct Obj01898 *)s)->f4 = e;
        t = e - 3;
        s[0xc] = t;
        ((struct Obj01898 *)s)->f8 = w;
        s[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)a, s);
        s = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xe, b);
        s[0xf] = e;
        s[0x10] = k;
        ((struct Obj01898 *)s)->f4 = 3;
        s[0xc] = t;
        ((struct Obj01898 *)s)->f8 = w;
        s[0xe] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)a, s);
        s = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0x13, b);
        s[4] = b;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)a, s);
    }
}
