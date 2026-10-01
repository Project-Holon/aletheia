/*
 * function: func_021DBFA4
 * address: 0x021DBFA4
 * packet: pkt_ov175_021DBFA4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DB6A8 0x021DB6A8 thumb ov175
 * leaf: reset request step then prepare four database fields.
 */
extern void func_021DB6A8(char *);
void func_021DBFA4(char *ctx)
{
    *(int *)(ctx + 0x12c) = 0;
    func_021DB6A8(ctx);
}
