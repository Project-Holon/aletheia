/*
 * function: COMM_ENTRY_MENU_ProcessMemberQueues
 * address:  0x021CE12C
 * packet:   pkt_ov021_021CE12C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_SendJoinAccept  0x021CF220  thumb  ov021
 *   COMM_ENTRY_SendJoinRedirect  0x021CF288  thumb  ov021
 *   COMM_ENTRY_MENU_CollectMemberNames  0x021CE1F4  thumb  ov021
 *   COMM_ENTRY_SendRoster  0x021CF3FC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u32 COMM_ENTRY_SendJoinAccept(u32 a, u32 flag, u32 c);
extern u32 COMM_ENTRY_SendJoinRedirect(u32 a, u32 flag, u32 c);
extern u8 COMM_ENTRY_MENU_CollectMemberNames(u8 *p);
extern u32 COMM_ENTRY_SendRoster(u32 a, u32 b, int c);

void COMM_ENTRY_MENU_ProcessMemberQueues(u8 *p)
{
    u8 i;
    int bit;
    u8 n;

    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        if (p[0x521] & bit) {
            if (COMM_ENTRY_SendJoinAccept(i, p[0x51B], (u32)(p + 0x30)) == 1)
                p[0x521] ^= (u8)bit;
        } else if (p[0x522] & bit) {
            if (COMM_ENTRY_SendJoinRedirect(i, p[0x51B], (u32)(p + 0x30)) == 1)
                p[0x522] ^= (u8)bit;
        }
    }
    if (p[0x523] == 1 && p[0x525] == 0) {
        n = COMM_ENTRY_MENU_CollectMemberNames(p);
        if (n > 1) {
            if (COMM_ENTRY_SendRoster((u32)(p + 0x494), n, p[0x51B]) == 1) {
                p[0x523] = 0;
                p[0x525] = 1;
            }
        }
    }
}
