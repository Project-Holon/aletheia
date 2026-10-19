/*
 * function: UNION_ONESELF_TalkChildStart
 * address:  0x0217C518
 * packet:   pkt_ov019_0217C518
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_HandleNetError  0x0217BB04  thumb  ov019
 *   UNION_COMM_ClearPartnerSelects  0x02173518  thumb  ov012
 *   UNION_COMM_SetSituationParam  0x021734A8  thumb  ov012
 *   UNION_COMM_AddMemberFromBeaconPc  0x021735FC  thumb  ov012
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   UNION_COMMAND_SendMyStatus  0x02173B4C  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 */
#include "../include/Obj12524.h"

typedef unsigned char u8;

extern int UNION_ONESELF_HandleNetError(char *p);
extern void UNION_COMM_ClearPartnerSelects(u8 *a);
typedef unsigned int   u32;
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
struct Entry;
extern int UNION_COMM_AddMemberFromBeaconPc(u8 *self, const struct Entry *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *a, u32 b, u32 c);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *a, u32 b, u32 c);
extern int UNION_COMMAND_SendMyStatus(u8 *a);
extern unsigned int func_02080D24(int a);

int UNION_ONESELF_TalkChildStart(u8 *a, u8 *b, int c, u8 *d)
{
    int r;
    if (UNION_ONESELF_HandleNetError((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        UNION_COMM_ClearPartnerSelects(b + 0x14);
        UNION_COMM_SetSituationParam(a, 4, 1);
        UNION_COMM_AddMemberFromBeaconPc(b + 0x14, (const struct Entry *)(((struct Obj12524 *)b)->f20));
        r = (int)GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)r, 2, 0x14);
        (*d)++;
        break;
    case 1:
        r = (int)GFL_NET_HANDLE_GetCurrentHandle();
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)r, 2, 0x14) == 1)
            (*d)++;
        break;
    case 2:
        if (UNION_COMMAND_SendMyStatus(a) == 1)
            (*d)++;
        break;
    case 3:
        if (func_02080D24(b[0x5b]) > 1)
            return 1;
        break;
    }
    return 0;
}
