/*
 * function: UNION_APP_IsAllEntriesReceived
 * address: 0x0218402C
 * packet: pkt_ov022_0218402C
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Original truncates index to u8 at 0218403E..02184040 before call;
 * extern follows caller-observed width despite callee u32 definition.
 * symbols:
 *   GFL_NET_IsConnectMember 0x0203D1C0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 GFL_NET_IsConnectMember(u32 index);
int UNION_APP_IsAllEntriesReceived(u8 *p)
{
    int i;
    u32 m;
    for (i = 0; i < 5; i++) {
        m = 1 << i;
        if ((p[1] & m) && GFL_NET_IsConnectMember((u8)i) == 1 && !(p[14] & m)) return 0;
    }
    return 1;
}
