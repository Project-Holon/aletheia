/*
 * function: VCT_SESSION_AdvancePhase
 * address:  0x021B2894
 * packet:   pkt_ov013_021B2894
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctSession  0x021B60D8  data  ov013  a4
 *   gVctHostPhaseTable  0x021B3BC8  data  ov013  a1
 *   gVctClientPhaseTable  0x021B3AFC  data  ov013  a1
 *   VCT_SESSION_SendReply  0x021B25B0  arm  ov013
 */

typedef unsigned char u8;
typedef signed char s8;

typedef struct Ctx {
    int f0;
    int f4;
    int f8;
    int fC;
} Ctx;

typedef struct Msg {
    int f0;
    u8 b4;
    u8 b5;
    u8 b6;
} Msg;

typedef struct St {
    char pad[0x10];
    int state;
} St;

extern St gVctSession;
extern s8 gVctHostPhaseTable[][11];
extern s8 gVctClientPhaseTable[][11];
extern int VCT_SESSION_SendReply(int a, int b);

int VCT_SESSION_AdvancePhase(Ctx *c, Msg *m)
{
    int i;
    int r;

    i = m->b6;
    if (m->b4 == 0)
        i += 5;
    if ((unsigned int)i >= 0xb)
        i = -1;
    if (i < 0)
        return -1;
    if (gVctSession.state == 1)
        r = gVctHostPhaseTable[c->fC][i];
    else
        r = gVctClientPhaseTable[c->fC][i];
    switch (r) {
    case -1:
        return r;
    case -2:
        VCT_SESSION_SendReply((int)c, 1);
        c->fC = 0;
        c->f0 = 0;
        return r;
    case -3:
        VCT_SESSION_SendReply((int)c, 3);
        c->fC = 0;
        c->f0 = 0;
        return r;
    default:
        return r;
    }
}
