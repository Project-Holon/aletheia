/*
 * function: VCT_SESSION_BuildGroupCommand
 * address:  0x021B2010
 * packet:   pkt_ov013_021B2010
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

extern struct Sess g_021B60D8;
extern void VCT_SESSION_InitPacketHeader(void *a, void *b, unsigned int c);
typedef unsigned char  u8;
extern int VCT_SESSION_CheckCommandAllowed(int *obj, const u8 *q);
struct N;
extern int VCT_SESSION_HasNoOtherTalker(struct N *p);

int VCT_SESSION_BuildGroupCommand(void *a, unsigned int b, unsigned char *buf, unsigned int c)
{
    int r = 0xff;

    if (a == 0)
        return -1;
    if (c < 0x10)
        return -1;
    if (g_021B60D8.fc == 1)
        return -3;
    if (b >= 5)
        return -3;
    buf[4] = r;
    VCT_SESSION_InitPacketHeader(a, buf, b & 0xff);
    if (VCT_SESSION_CheckCommandAllowed(a, buf) == 0)
        return 0xfc - r;
    if (g_021B60D8.f10 == 1 && b == 0) {
        if (VCT_SESSION_HasNoOtherTalker(a) == 0)
            return 0xfc - r;
    }
    return 0;
}
