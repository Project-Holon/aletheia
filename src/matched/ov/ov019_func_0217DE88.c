/*
 * function: UNION_ONESELF_ColosseumFreeMoveStart
 * address: 0x0217DE88
 * packet: pkt_ov019_0217DE88
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UNION_MSG_CloseAllWindows 0x0217F074 thumb ov019
 *   UNION_ONESELF_SetFieldBusy 0x0217BAF0 thumb ov019
 */
extern void UNION_MSG_CloseAllWindows(void *ctx);
extern void UNION_ONESELF_SetFieldBusy(char *p, int x, unsigned int v);
int UNION_ONESELF_ColosseumFreeMoveStart(void *ctx, void *unused, int a)
{
    UNION_MSG_CloseAllWindows(ctx);
    UNION_ONESELF_SetFieldBusy(ctx, a, 0);
    return 1;
}
