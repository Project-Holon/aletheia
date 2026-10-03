/*
 * function: func_021D94B8
 * address: 0x021D94B8
 * packet: pkt_ov121_021D94B8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: named the callee's boolean return; the tail jump forwards it unchanged.
 * symbols:
 *   func_021DA9F8 0x021DA9F8 thumb ov121
 */
typedef unsigned char  u8;
extern int func_021DA9F8(u8 *p);
int func_021D94B8(char *p)
{
    return func_021DA9F8(*(void **)(p+4));
}
