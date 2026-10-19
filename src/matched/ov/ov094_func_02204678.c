/*
 * function: BTLV_INPUT_PaletteCycleTaskEnd
 * address:  0x02204678
 * packet:   pkt_ov094_02204678
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_IsDeletePending  0x02030EE8  arm  arm9
 */
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);

void BTLV_INPUT_PaletteCycleTaskEnd(void *h)
{
    char *p = *((char **)TCBL_IsDeletePending(h));
    ((Bits *)(p + 0x68))->n--;
}
