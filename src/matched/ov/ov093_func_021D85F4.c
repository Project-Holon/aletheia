/*
 * function: HAND_TOKUSEI_IntimidateOnEnter
 * address:  0x021D85F4
 * packet:   pkt_ov093_021D85F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * lever: -1 is a signed store (subs from the shared 1); p is declared last.
 * symbols:
 *   HAND_TOKUSEI_IntimidateOnEnter  0x021D85F4  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer  0x021C8120  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07807.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *p, int b);
u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_IntimidateOnEnter(void *a, int b, int c)
{
    void *r;
    void *v;
    int w;
    u32 i;
    u8 *p;

    if (c != BTL_EVENT_GetVar(2))
        return;
    r = (void *)BTL_SERVER_FLOW_GetFrontPosOfPoke((u8 *)b, c);
    v = (void *)BTL_SERVER_FLOW_GetScratchBuffer((u8 *)b, 6);
    w = BTL_SERVER_FLOW_CollectAlivePokeIds((int *)b, (u16)((u32)r | 0x100), (u8 *)((int)v));
    if (w == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord((void *)b, 2, c);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
    ((struct Obj07807 *)p)->f4 = 1;
    ((struct Obj07807 *)p)->fC = -1;
    ((struct Obj07807 *)p)->fE = 1;
    ((struct Obj07807 *)p)->fF = w;
    for (i = 0; i < (u32)w; i++)
        *(u8 *)(p + 0x10 + i) = ((u8 *)v)[i];
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    BTL_SERVER_FLOW_PushCmdRecord((void *)b, 3, c);
}
