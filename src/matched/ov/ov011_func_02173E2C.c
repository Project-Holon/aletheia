/*
 * function: INTRUDE_CMD_SendJoinRequest
 * address:  0x02173E2C
 * packet:   pkt_ov011_02173E2C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   INTRUDE_COMM_ClearJoinReply  0x02176200  thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 */

typedef unsigned short u16;

int INTRUDE_COMM_IsLinked(void);
void INTRUDE_COMM_ClearJoinReply(char *a);
typedef unsigned int   u32;
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

int INTRUDE_CMD_SendJoinRequest(char *a, int b)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    INTRUDE_COMM_ClearJoinReply(a + 0x1AC);
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x210, 0x30, b);
}
