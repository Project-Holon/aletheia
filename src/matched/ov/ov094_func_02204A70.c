/*
 * function: BTLV_INPUT_WaitFadeTaskEnd
 * address:  0x02204A70
 * packet:   pkt_ov094_02204A70
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_IsDeletePending  0x02030EE8  arm  arm9
 */
typedef struct Bits { unsigned lo:15; unsigned mode:2; unsigned hi:15; } Bits;
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

void BTLV_INPUT_WaitFadeTaskEnd(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits *)(p + 0x68))->mode = 0;
}
