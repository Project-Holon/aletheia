/*
 * function: func_021689BC
 * address:  0x021689BC
 * packet:   pkt_021689BC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_FriendInit (dwc_friend.o): install the friend control block at
 * 0x021AA860+0xc, zero the whole descriptor, seed +0x04/+0x14/+0x18/+0x28
 * from the arguments and run DWCi_SetSentBuddyReqFlag over the n records of
 * the +0x18 table.  The +0x0c..+0x14 triple is written through one cached
 * pointer load (a local), every other field re-reads the global slot.
 *
 * symbols:
 *   g_021AA860     0x021AA860  data  ov009
 *   func_020592A0  0x020592A0  arm
 */

extern char g_021AA860[];
extern void func_020592A0(int, int);

void func_021689BC(char *p, int a1, int a2, int a3, int n)
{
    int i;
    char *q;

    *(char **)(g_021AA860 + 0xc) = p;
    *(int *)p = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 4) = a1;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 8) = 0;
    q = *(char **)(g_021AA860 + 0xc);
    *(int *)(q + 0xc) = 0;
    *(int *)(q + 0x10) = 0;
    *(int *)(q + 0x14) = n;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x18) = a3;
    *(char *)(*(char **)(g_021AA860 + 0xc) + 0x1c) = 0;
    *(char *)(*(char **)(g_021AA860 + 0xc) + 0x1d) = 0;
    *(char *)(*(char **)(g_021AA860 + 0xc) + 0x1e) = 0;
    *(char *)(*(char **)(g_021AA860 + 0xc) + 0x1f) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x20) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x24) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x28) = a2;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x2c) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x30) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x34) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x38) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x3c) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x40) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x44) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x48) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x4c) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x50) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x54) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x58) = 0;
    *(int *)(*(char **)(g_021AA860 + 0xc) + 0x5c) = 0;

    for (i = 0; i < n; i++)
        func_020592A0(*(int *)(*(char **)(g_021AA860 + 0xc) + 0x18) + i * 12, 0);
}
