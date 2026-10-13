/*
 * function: COMM_ENTRY_IsOtherMemberConnected
 * address:  0x021CF12C
 * packet:   pkt_ov021_021CF12C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern u32 GFL_NET_IsConnectMember(u32 index);

int COMM_ENTRY_IsOtherMemberConnected(int mask)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (i != GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())) && ((1 << i) & mask) && GFL_NET_IsConnectMember(i) == 1) {
            return 1;
        }
    }
    return 0;
}
