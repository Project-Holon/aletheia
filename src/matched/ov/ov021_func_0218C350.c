/*
 * function: FIELD_BUILDMODEL_StopGroup
 * address:  0x0218C350
 * packet:   pkt_ov021_0218C350
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetModelAnimDefs  0x0218BCAC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8 *FIELD_BUILDMODEL_GetModelAnimDefs(u8 *p);

void FIELD_BUILDMODEL_StopGroup(u32 *st, int n)
{
    u8 *q = FIELD_BUILDMODEL_GetModelAnimDefs(*(u8 **)st[1]);
    int base = q[2] * n;
    int i;

    for (i = 0; i < q[2]; i++) {
        if ((st + base)[2 + i] != 0)
            (st + base)[2 + i] = 2;
    }
}
