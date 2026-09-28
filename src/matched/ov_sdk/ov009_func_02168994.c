/*
 * function: func_02168994
 * address:  0x02168994
 * packet:   pkt_ov009_02168994
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SetBuddyFriendCallback (dwc_friend.o)
 *
 * symbols:
 *   g_021AA860  0x021AA860  data
 */

extern char g_021AA860[];

int func_02168994(void (*callback)(int, void *), void *param)
{
    if (*(char **)(g_021AA860 + 0xc) == 0) return 0;
    *(void **)(*(char **)(g_021AA860 + 0xc) + 0x44) = (void *)callback;
    *(void **)(*(char **)(g_021AA860 + 0xc) + 0x48) = param;
    return 1;
}
