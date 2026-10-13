/*
 * function: TR_AI_CmdNop5
 * address: 0x021894F8
 * packet: pkt_ov096_021894F8
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov096/tr_ai.c and filed here.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad00[0x38];
    int f38;
    u8 pad3C[0x98 - 0x3c];
    int f98;
    int f9c;
    u8 padA0[0xc4 - 0xa0];
    int fc4;
} Conn_021892F8;

int TR_AI_CmdNop5(int a, Conn_021892F8 *b);

int TR_AI_CmdNop5(int a, Conn_021892F8 *b)
{
    return b->fc4;
}
