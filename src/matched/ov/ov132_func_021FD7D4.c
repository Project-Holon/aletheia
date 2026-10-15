/*
 * unit: yes
 * function: STA_NET_SendSlot3Command, STA_NET_SetSlot3Done, STA_NET_GetSlot3Value
 * address: 0x021FD7D4
 * packet: pkt_ov132_021FD7D4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_SLOT_Noop 0x021FDA74 thumb ov132
 *   GFL_NET_HANDLE_GetNetHandle 0x0203996C arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
#include "../include/Obj14141.h"
#include "../include/Obj23297.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void STA_SLOT_Noop(int a0, int a1, int a2);
typedef signed int     s32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern u32 GFL_NET_SendData(u32, u32, u32, u32, u32, u32, u32, u32);
int STA_NET_SendSlot3Command(u8 *p)
{
    u32 *q = *(u32 * *)&((struct Obj23297 *)p)->f140;
    u32 id;
    STA_SLOT_Noop(q[3], q[10], 0);
    id = (u32)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData(id, 255, 0x1108, (*(u32 **)(p + 0x140))[10], (*(u32 **)(p + 0x140))[3], 1, 0, 1);
}
void STA_NET_SetSlot3Done(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct Obj14141 *)p)->f178 = 1;
    q = *(u32 * *)&((struct Obj14141 *)p)->f140;
    STA_SLOT_Noop(q[3], q[10], 10);
}
u32 STA_NET_GetSlot3Value(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[3];
}
