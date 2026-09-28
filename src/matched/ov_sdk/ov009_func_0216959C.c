/*
 * function: func_0216959C
 * address:  0x0216959C
 * packet:   pkt_ov009_0216959C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_DeleteFriendFromList (dwc_friend.o)
 *
 * symbols:
 *   g_021AA860    0x021AA860  data
 *   func_02082BCC  0x02082BCC  arm
 */

extern char g_021AA860[];
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);

void func_0216959C(void *friendData, int deleteIndex, int otherIndex)
{
    if (*(char **)(g_021AA860 + 0xc) == 0) return;
    func_02082BCC((char *)friendData + deleteIndex * 0xc, 0, 0xc);
    if (*(int *)(*(char **)(g_021AA860 + 0xc) + 0x3c) == 0) return;
    (*(void (*)(int, int, int))(*(int *)(*(char **)(g_021AA860 + 0xc) + 0x3c)))(
        deleteIndex, otherIndex, *(int *)(*(char **)(g_021AA860 + 0xc) + 0x40));
}
