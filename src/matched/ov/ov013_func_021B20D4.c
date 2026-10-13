/*
 * function: VCT_SESSION_BuildPeerReply
 * address:  0x021B20D4
 * packet:   pkt_ov013_021B20D4
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021B60D8  0x021B60D8  data  a4
 *   VCT_SESSION_InitPacketHeader  0x021B2848  arm  ov013
 *   VCT_SESSION_CheckCommandAllowed  0x021B29A4  arm  ov013
 *   VCT_SESSION_HasNoOtherTalker  0x021B2958  arm  ov013
 */

#include "../include/G_Sess.h"

struct Chan {
    unsigned char pad[4];
    unsigned char f4;
    unsigned char pad5[3];
    unsigned int f8;
    int fc;
};

extern struct Sess g_021B60D8;
typedef unsigned char  u8;
struct Msg;
extern int VCT_SESSION_InitPacketHeader(u8 *o, struct Msg *p, int n);
struct N;
extern int VCT_SESSION_CheckCommandAllowed(int *obj, const u8 *q);
extern int VCT_SESSION_HasNoOtherTalker(struct N *p);

int VCT_SESSION_BuildPeerReply(struct Chan *a, unsigned int b, unsigned char *buf, unsigned int c)
{
    int z = 0;

    if (a == 0)
        return -1;
    if (c < 0x10)
        return -1;
    if (b >= 6)
        return -3;
    buf[4] = z;
    VCT_SESSION_InitPacketHeader((u8 *)a, (struct Msg *)buf, b & 0xff);
    if (b == 0) {
        if (g_021B60D8.f10 == 1 && a->fc == 4) {
            if (VCT_SESSION_HasNoOtherTalker((struct N *)a) == 0)
                return z - 3;
        }
        a->f8 = a->f4 ? 1 << a->f4 : 1;
    }
    if (VCT_SESSION_CheckCommandAllowed((int *)a, buf) == 0)
        return -3;
    return 0;
}
