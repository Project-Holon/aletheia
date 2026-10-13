/*
 * function: GAME_BEACON_SEARCH_InitWait
 * address:  0x02164BC4
 * packet:   pkt_ov010_02164BC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-step state machine on *st: step 0 registers a callback, step 1 polls.
 *
 * symbols:
 *   func_02030B50  0x02030B50  arm
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GAME_BEACON_SEARCH_NetInit     0x02171C30  data  ov010  a4
 *   GAME_BEACON_SEARCH_OnSessionStarted  0x02164C04  thumb ov010
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Req;
extern void func_02030B50(void *p);
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern u8 GAME_BEACON_SEARCH_NetInit[];
extern void GAME_BEACON_SEARCH_OnSessionStarted(u8 *p);

int GAME_BEACON_SEARCH_InitWait(int *st, int unused, int *q)
{
    switch (*st) {
    case 0:
        func_02030B50((void *)12);
        GFL_NET_StartSession((struct Req *)GAME_BEACON_SEARCH_NetInit, (u32)GAME_BEACON_SEARCH_OnSessionStarted, (u32)q);
        (*st)++;
        break;
    case 1:
        if (q[1] >= 1) {
            return 1;
        }
        break;
    }
    return 0;
}
