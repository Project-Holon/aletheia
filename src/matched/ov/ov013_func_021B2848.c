/*
 * function: VCT_SESSION_InitPacketHeader
 * address: 0x021B2848
 * packet: pkt_ov013_021B2848
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: Returning zero keeps the clearing value in r0 and frees r2 for byte loads.
 * symbols:
 *   gVctSession 0x021B60D8 data ov013 a4
 */
typedef unsigned char u8;
typedef struct Msg {
    unsigned int magic;
    u8 b4, b5, b6, b7, b8, b9, b10, b11;
    int fC;
} Msg;
extern u8 gVctSession;
int VCT_SESSION_InitPacketHeader(u8 *o, Msg *p, int n)
{
    p->magic = 0x5f564354;
    p->b5 = 0x10;
    p->b6 = n;
    p->b8 = gVctSession;
    p->b9 = o[4];
    p->b10 = 0;
    p->b11 = gVctSession;
    p->fC = 0;
    return 0;
}
