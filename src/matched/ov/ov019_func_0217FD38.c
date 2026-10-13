/*
 * function: UNION_EFF_DrawIconGroup
 * address:  0x0217FD38
 * packet:   pkt_ov019_0217FD38
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
 *   UNION_EFF_DrawIconObj    0x0217FCC4  thumb  ov019
 *   d_02180758       0x02180758  data   ov019 a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct B60 { u32 w[15]; };
struct E { u32 a, b, c, d; u16 h; };
extern void MTX_Identity33_(void *m);
extern int FLDMMDL_CheckStatusBitUse(u32 a);
extern void UNION_EFF_DrawIconObj(u32 *p, u32 *b);
extern struct B60 d_02180758;

void UNION_EFF_DrawIconGroup(struct E *p)
{
    struct B60 b = d_02180758;
    int i;

    MTX_Identity33_(&b.w[6]);
    for (i = 0; i < 10; i++) {
        struct E *e = &p[i];
        if (e->d != 0 && FLDMMDL_CheckStatusBitUse(e->a) == 1) {
            UNION_EFF_DrawIconObj((u32 *)e, (u32 *)(&b));
        }
    }
}
