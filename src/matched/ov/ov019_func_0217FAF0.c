/*
 * function: UNION_EFF_DrawAnimGroup
 * address:  0x0217FAF0
 * packet:   pkt_ov019_0217FAF0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MTX_Identity33_  0x0207ADC4  arm
 *   FLDMMDL_CheckStatusBitUse    0x0216DA30  thumb  ov010
 *   UNION_EFF_DrawAnimObj    0x0217FA9C  thumb  ov019
 *   d_0218071C       0x0218071C  data   ov019 a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct B60 { u32 w[15]; };
extern void MTX_Identity33_(void *m);
extern int FLDMMDL_CheckStatusBitUse(u32 a);
extern void UNION_EFF_DrawAnimObj(u32 *p, u32 *b);
extern struct B60 d_0218071C;

void UNION_EFF_DrawAnimGroup(u32 *p)
{
    struct B60 b = d_0218071C;

    MTX_Identity33_(&b.w[6]);
    if (p[3] != 0 && FLDMMDL_CheckStatusBitUse(p[0]) == 1) {
        UNION_EFF_DrawAnimObj(p, (u32 *)(&b));
    }
}
