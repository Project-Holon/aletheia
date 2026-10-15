/*
 * function: TH_AWARD_GRAPHIC_Update
 * address:  0x021BA1CC
 * packet:   pkt_ov220_021BA1CC
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Destructor pair: tears down the tail field then the head.  This address is
 * also matched as TH_AWARD_GRAPHIC_Update in ov217; the ov220 copy is a distinct
 * function and gets its own shard.
 *
 * symbols:
 *   TH_AWARD_GRAPHIC_Draw  0x021BA300  thumb  ov220
 *   TH_AWARD_GRAPHIC_Noop  0x021BA298  thumb  ov220
 *
 * Addresses are Black-image addresses.
 */

extern void TH_AWARD_GRAPHIC_Draw(void *);
extern void TH_AWARD_GRAPHIC_Noop(void *);

void TH_AWARD_GRAPHIC_Update(char *p)
{
    TH_AWARD_GRAPHIC_Draw(p + 4);
    TH_AWARD_GRAPHIC_Noop(p);
}
