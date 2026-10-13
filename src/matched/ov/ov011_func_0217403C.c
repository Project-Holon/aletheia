/*
 * function: INTRUDE_CMD_RecvProposal
 * address: 0x0217403C
 * packet: pkt_ov011_0217403C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   INTRUDE_COMM_StoreResultRecord 0x02175C88 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
u32 func_0203D378(void);
typedef struct Rec { u32 w[13]; } Rec;
int INTRUDE_COMM_StoreResultRecord(u8 *a, Rec *b, int c);

void INTRUDE_CMD_RecvProposal(int a, int b, void *c, u8 *d)
{
    if (func_0203D378()) INTRUDE_COMM_StoreResultRecord(d + 0x1ac, c, a);
}
