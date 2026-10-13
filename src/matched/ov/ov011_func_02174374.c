/*
 * function: INTRUDE_CMD_SendProfile
 * address:  0x02174374
 * packet:   pkt_ov011_02174374
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 */

typedef unsigned short u16;

unsigned int GAME_COMM_GetGameData(void *obj);
void *GAME_DATA_GetLastBattleRecSlot(void *p);
int INTRUDE_COMM_IsLinked(void);
typedef unsigned int   u32;
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

int INTRUDE_CMD_SendProfile(int *a)
{
    int r;

    r = (int)GAME_DATA_GetLastBattleRecSlot((void *)GAME_COMM_GetGameData((void *)a[1]));
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x21c, 0x10, r);
}
