/*
 * unit: yes
 * function: BSUBWAY_COMM_GetBeaconData, BSUBWAY_COMM_GetBeaconSize, BSUBWAY_COMM_CheckConnectService
 * address: 0x02167AC4
 * packet: pkt_ov010_02167AC4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Trailing unlabelled constant getter and equality predicate are included.
 * symbols:
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   OS_GetMacAddress 0x02087C6C arm
 */
#include "../include/Obj19012.h"
#include "../include/Obj19013.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void MYSTATUS_Copy(void *, void *);
extern void OS_GetMacAddress(void *);
void *BSUBWAY_COMM_GetBeaconData(u8 *p)
{
    u8 *q;
    q = p + 0x6f4;
    MYSTATUS_Copy(GAME_DATA_GetMyStatus(((struct Obj19012 *)p)->f6C), q);
    OS_GetMacAddress(q + 0x20);
    ((struct Obj19013 *)q)->f26 = 0x3a0b;
    return q;
}
int BSUBWAY_COMM_GetBeaconSize(void)
{
    return 0x28;
}
int BSUBWAY_COMM_CheckConnectService(int a, int b)
{
    if (a == b) return 1;
    return 0;
}
