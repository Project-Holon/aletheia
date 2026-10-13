/*
 * function: UNION_APP_DropDisconnectedMembers
 * address:  0x02183CC0
 * packet:   pkt_ov022_02183CC0
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   INTRUDE_CMD_RecvResultRecord  0x0217410C  thumb  ov011
 *   UNION_APP_OnMemberDropped  0x021840A4  thumb  ov022
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 GFL_NET_IsConnectMember(u32 index);
extern int INTRUDE_CMD_RecvResultRecord(int a, int b);
extern void UNION_APP_OnMemberDropped(u8 *s, int i);

void UNION_APP_DropDisconnectedMembers(u8 *s)
{
    int i;
    u32 m;
    u32 r;
    u8 t;

    r = s[1];
    if (s[0x10] == 0xff) {
        for (i = 0; i < 5; i++) {
            m = 1 << i;
            if (s[1] & m) {
                if (GFL_NET_IsConnectMember((u8)i) == 0) {
                    r ^= m;
                }
            }
        }
        if (r != s[1]) {
            t = r;
            for (i = 0; i < 5; i++) {
                m = 1 << i;
                if (s[1] & m) {
                    if (!(r & m)) {
                        if (INTRUDE_CMD_RecvResultRecord(t, i & 0xff) == 1) {
                            UNION_APP_OnMemberDropped(s, (u8)i);
                            s[1] = s[1] ^ (u8)m;
                        }
                    }
                }
            }
        }
    }
}
