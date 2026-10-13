/*
 * function: BTL_DEADREC_StartTurn
 * address: 0x0689D134
 * packet: pkt_ov095_0689D134
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_DEADREC_ClearTurn 0x0689D0FC thumb ov095
 */
typedef unsigned char u8;
extern void BTL_DEADREC_ClearTurn(u8 *);
typedef struct { u8 b[0x31]; } E;
void BTL_DEADREC_StartTurn(u8 *p)
{
    E *e = (E *)p;
    unsigned int i;
    for (i = 3; i != 0; i--) {
        e[i] = e[i - 1];
    }
    BTL_DEADREC_ClearTurn(p);
}
