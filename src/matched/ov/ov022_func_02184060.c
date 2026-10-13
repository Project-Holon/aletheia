/*
 * function: UNION_APP_QueueJoinConfirm
 * address:  0x02184060
 * packet:   pkt_ov022_02184060
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern u32 GFL_NET_IsParentAid(void);

void UNION_APP_QueueJoinConfirm(u8 *s, int i)
{
    if (GFL_NET_IsParentAid() == 1) {
        if ((s[0xe] & (1 << i)) && (s[4] & (1 << i))) {
            s[7] |= (u8)(1 << i);
        }
    } else {
        s[4] |= (u8)(1 << i);
        s[7] |= (u8)(1 << i);
    }
}
