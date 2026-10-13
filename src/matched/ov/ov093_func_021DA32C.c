/*
 * function: HAND_TOKUSEI_DownloadOnMemberIn
 * address:  0x021DA32C
 * packet:   pkt_ov093_021DA32C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_CollectOpponentPokeIds   0x021C7D54  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 */
#include "../include/Obj06255.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_EVENT_GetVar(int a);
extern u8 BTL_SERVER_FLOW_CollectOpponentPokeIds(u8 *p, u8 *k, u8 *out);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
/* lo/hi sums are u16 accumulators; a u8 third parameter keeps its reload
   after the +0xf store. */
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_DownloadOnMemberIn(int a, int b, u8 c)
{
    u8 buf[4];
    u8 n;
    u16 lo;
    u16 hi;
    u8 i;
    int k;
    void *q;
    u8 *p;

    if (c != BTL_EVENT_GetVar(2))
        return;
    n = BTL_SERVER_FLOW_CollectOpponentPokeIds((u8 *)b, (u8 *)c, buf);
    if (n == 0)
        return;
    lo = 0;
    hi = 0;
    for (i = 0; i < n; i++) {
        q = BTL_SERVER_FLOW_GetPokeParam((int *)b, buf[i]);
        lo = lo + (u16)func_021D59B4(q, 9);
        hi = hi + (u16)func_021D59B4(q, 0xb);
    }
    if (lo >= hi)
        k = 3;
    else
        k = 1;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
    ((struct Obj06255 *)p)->f0 |= 2 << 22;
    p[0xf] = 1;
    p[0x10] = c;
    ((struct Obj06255 *)p)->f4 = k;
    p[0xc] = 1;
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
