/*
 * function: INTRUDE_COMM_RecvPairMessage
 * address: 0x02174630
 * packet: pkt_ov011_02174630
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: existing follower ov011_func_02174660.c stays separate.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GAME_COMM_PushPairMessage 0x020266AC thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
u32 GFL_NET_GetHandleNetID(struct Link *p);
void GAME_COMM_PushPairMessage(u32 a, u32 b, u32 c);
void INTRUDE_COMM_RecvPairMessage(int a, int b, u8 *c, u8 *p)
{
    if (a != GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) && (p[0x8fb] & (1 << a))) {
        GAME_COMM_PushPairMessage(((u32 *)p)[1], a, *c);
    }
}
