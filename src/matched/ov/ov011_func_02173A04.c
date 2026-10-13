/*
 * function: func_02173A04
 * address: 0x02173A04
 * packet: pkt_ov011_02173A04
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: Two zero alignment bytes follow the compiled 38-byte body.
 * symbols:
 *   INTRUDE_COMM_TryStartRequest 0x021753D0 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Rec { u32 words[14]; } Rec;
int INTRUDE_COMM_TryStartRequest(u8 *p, int i, u8 v);

void func_02173A04(int a, int b, Rec *c, u8 *d)
{
    if (INTRUDE_COMM_TryStartRequest(d, a, ((u8 *)c)[1]) == 1) *(Rec *)(d + 0x11c) = *c;
}
