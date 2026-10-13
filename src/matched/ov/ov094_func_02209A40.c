/*
 * function: BTLV_BG_OnScrollJobEnd
 * address:  0x02209A40
 * packet:   pkt_ov094_02209A40
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_GetTaskUserData  0x02030EE8  arm  arm9
 */

typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

void BTLV_BG_OnScrollJobEnd(void *h)
{
    int *w = *((int **)TCBL_GetTaskUserData(h));
    w[1] &= ~1;
}
