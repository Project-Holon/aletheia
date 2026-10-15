/*
 * function: TH_AWARD_GRAPHIC_Task
 * address:  0x021BA1EC
 * packet:   pkt_021BA1EC
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Constructor pair: builds the head then the tail field.
 *
 * symbols:
 *   TH_AWARD_GRAPHIC_DrawObjects  0x021BA29C  thumb  ov220
 *   TH_AWARD_GRAPHIC_VBlank  0x021BA308  thumb  ov220
 *
 * Addresses are Black-image addresses.
 */

extern void TH_AWARD_GRAPHIC_DrawObjects(void *);
extern void TH_AWARD_GRAPHIC_VBlank(void *);

void TH_AWARD_GRAPHIC_Task(void *unused, char *p)
{
    TH_AWARD_GRAPHIC_DrawObjects(p);
    TH_AWARD_GRAPHIC_VBlank(p + 4);
}
