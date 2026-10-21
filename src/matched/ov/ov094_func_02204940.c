/*
 * function: BTLV_INPUT_PaletteFlashTaskEnd
 * address:  0x02204940
 * packet:   pkt_ov094_02204940
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_GetOwnedWork  0x02030EE8  arm  arm9
 */
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
typedef unsigned int   u32;
struct S02030EE8;
extern u32 TCBL_GetOwnedWork(struct S02030EE8 *p);

void BTLV_INPUT_PaletteFlashTaskEnd(void *h)
{
    char *p = *((char **)TCBL_GetOwnedWork(h));
    ((Bits *)(p + 0x68))->n--;
}
