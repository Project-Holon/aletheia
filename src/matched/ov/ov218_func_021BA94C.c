/*
 * function: UN_SELECT_GRAPHIC_Update
 * address:  0x021BA94C
 * packet:   pkt_021BA94C
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Destructor pair: tears down the tail field then the head.
 *
 * symbols:
 *   UN_SELECT_GRAPHIC_Draw  0x021BAA80  thumb  ov218
 *   UN_SELECT_GRAPHIC_Noop  0x021BAA18  thumb  ov218
 *
 * Addresses are Black-image addresses.
 */

extern void UN_SELECT_GRAPHIC_Draw(void *);
extern void UN_SELECT_GRAPHIC_Noop(void *);

void UN_SELECT_GRAPHIC_Update(char *p)
{
    UN_SELECT_GRAPHIC_Draw(p + 4);
    UN_SELECT_GRAPHIC_Noop(p);
}
