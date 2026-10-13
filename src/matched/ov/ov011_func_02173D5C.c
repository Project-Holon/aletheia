/*
 * function: INTRUDE_CMD_RecvMemberEntry
 * address:  0x02173D5C
 * packet:   pkt_ov011_02173D5C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   INTRUDE_COMM_StoreSessionEntry  0x02175938  thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GAME_DATA_GetBattleRecSlot  0x020127AC  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../include/Obj19172.h"

typedef unsigned int   u32;
struct Link;
struct SaveBlock;
u32 GAME_COMM_GetGameData(void *obj);
typedef unsigned short u16;
typedef unsigned char  u8;
void INTRUDE_COMM_StoreSessionEntry(u8 *p, const u16 *src, int index);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
u32 GFL_NET_GetHandleNetID(struct Link *p);
void *GAME_DATA_GetBattleRecSlot(struct SaveBlock *p, u32 idx);
void MI_CpuCopy8(void *d, int s, int n);

void INTRUDE_CMD_RecvMemberEntry(int a, int b, char *c, char *d)
{
    int v;
    int t;

    v = GAME_COMM_GetGameData((void *)(((struct Obj19172 *)d)->f4));
    t = (unsigned char)c[0x24];
    INTRUDE_COMM_StoreSessionEntry((u8 *)(d + 0x1AC), (const u16 *)c, t);
    if (t != GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {
        MI_CpuCopy8(c, (int)GAME_DATA_GetBattleRecSlot((struct SaveBlock *)v, t), 0x10);
    }
}
