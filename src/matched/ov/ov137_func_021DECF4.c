/*
 * function: GURU2_MAIN_StateBroadcastPlayerData
 * address: 0x021DECF4
 * packet: pkt_ov137_021DECF4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GURU2_MAIN_GetUnionApp 0x021DEB10 thumb ov137
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 *   GFL_NET_SendDataMask 0x0203D4D0 arm
 */
#include "../include/Obj01753.h"
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern void *GURU2_MAIN_GetUnionApp(char *p);
extern unsigned char UNION_APP_GetJoinedBits(unsigned char *p);
extern u32 GFL_NET_SendDataMask(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int GURU2_MAIN_StateBroadcastPlayerData(u8 *p)
{
    void *q;
    q = GFL_NET_HANDLE_GetCurrentHandle();
    if ((int)GFL_NET_SendDataMask((u32)q, (u8)((int)UNION_APP_GetJoinedBits(GURU2_MAIN_GetUnionApp((char *)p))), (int)10255, (int)1428, (u32)(((struct Obj01753 *)p)->f24), (int)1, (int)1, (int)1))
        ((struct Obj01753 *)p)->f0 = 14;
    return 0;
}
