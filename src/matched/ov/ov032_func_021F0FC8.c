/*
 * function: BEACON_VIEW_LoadEntryStatus
 * address: 0x021F0FC8
 * packet: pkt_ov032_021F0FC8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 */

typedef unsigned char u8;
struct Sub0204A9D0;
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
void BEACON_VIEW_LoadEntryStatus(char *p, u8 *q, int r)
{
    CLACT_TransferCharacter((*(int **)(p + 0x170))[q[0]], (struct Sub0204A9D0 *)(*(int *)(p + r * 8 + 0x2d8)));
}
