/*
 * function: INTRUDE_COMM_SendTally
 * address: 0x021743B4
 * packet: pkt_ov011_021743B4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_COMM_GetGameData 0x02026478 thumb
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Entry;
u32 GAME_COMM_GetGameData(void *obj);
int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int INTRUDE_COMM_SendTally(char *p)
{
    GAME_COMM_GetGameData((void *)(((int *)p)[1]));
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendToHandle((struct Entry *)((u32)GFL_NET_HANDLE_GetCurrentHandle()), 0x21d, 4, (u32)(p + 0x354));
}
