/*
 * function: VCT_SESSION_HandlePacket
 * address:  0x021B2488
 * packet:   pkt_ov013_021B2488
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSession  0x021B60D8  data  ov013  a4
 *   VCT_SESSION_HandleUnknownProtocolPacket  0x021B2D54  arm  ov013
 *   func_021B2AA0  0x021B2AA0  arm  ov013
 *   VCT_SESSION_HandleSharedPacket  0x021B2BE0  arm  ov013
 */

typedef unsigned char u8;

typedef struct Ctx {
    u8 b0;
    u8 pad[11];
    int fC;
} Ctx;

extern Ctx gVctSession;
struct Event;
struct Pkt;
extern int VCT_SESSION_HandleUnknownProtocolPacket(u8 *p, int *out);
extern int func_021B2AA0(struct Pkt *pkt, struct Event *ev);
extern int VCT_SESSION_HandleSharedPacket(struct Pkt *pkt, struct Event *ev);

int VCT_SESSION_HandlePacket(int a, u8 *p, int len, int x)
{
    if (len != 0x10)
        return 0;
    if (p[8] != a || p[9] != gVctSession.b0)
        return 0;
    if (p[5] != 0x10)
        return VCT_SESSION_HandleUnknownProtocolPacket(p, (int *)x);
    if (gVctSession.fC == 0)
        return func_021B2AA0((struct Pkt *)p, (struct Event *)x);
    return VCT_SESSION_HandleSharedPacket((struct Pkt *)p, (struct Event *)x);
}
