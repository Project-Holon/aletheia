/*
 * function: INTRUDE_COMM_UpdateMemberLeave
 * address:  0x02174B7C
 * packet:   pkt_ov011_02174B7C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   INTRUDE_COMM_SendPeerLeft  0x021738E4  thumb ov011
 */

typedef unsigned int   u32;
u32 GFL_NET_IsParentAid(void);
u32 GFL_NET_IsConnectMember(u32 index);
int INTRUDE_COMM_SendPeerLeft(void *a, int b);

void INTRUDE_COMM_UpdateMemberLeave(unsigned char *p)
{
    int i;

    if (GFL_NET_IsParentAid() != 0) {
        for (i = 0; i < p[0x902]; i++) {
            if ((int)GFL_NET_IsConnectMember((unsigned char)i) == 0 && (p[0x8FB] & (1 << i))) {
                INTRUDE_COMM_SendPeerLeft(p, i);
            }
        }
    }
}
