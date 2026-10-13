/*
 * function: BTL_CLIENT_CollectOwnReceivedIds
 * address:  0x021D0C78
 * packet:   pkt_ov093_021D0C78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ADAPTER_GetRecvData  0x021EEC20  thumb  ov093
 *   BTL_MAIN_GetSlotClientIdThunk  0x021B8DE4  thumb  ov093
 */
#include "../include/Obj09995.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

extern int BTL_ADAPTER_GetRecvData(int, int *);
extern u8 BTL_MAIN_GetSlotClientIdThunk(char *p, int i);

u8 BTL_CLIENT_CollectOwnReceivedIds(BattleSeq *s, u8 *out)
{
    int arr;
    u8 n;
    u32 i;
    u32 cnt;

    n = BTL_ADAPTER_GetRecvData(((struct Obj09995 *)s)->f50, &arr);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        if (s->unk1A6 == BTL_MAIN_GetSlotClientIdThunk(s->battle, ((u8 *)arr)[i])) {
            out[cnt] = ((u8 *)arr)[i];
            cnt++;
        }
    }
    return cnt;
}
