/*
 * function: UN_SELECT_GRAPHIC_Task
 * address:  0x021BA96C
 * packet:   pkt_021BA96C
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Constructor pair, parameter arrives in r1.
 *
 * symbols:
 *   UN_SELECT_GRAPHIC_DrawObjects  0x021BAA1C  thumb  ov218
 *   UN_SELECT_GRAPHIC_VBlank  0x021BAA88  thumb  ov218
 *
 * Addresses are Black-image addresses.
 */

extern void UN_SELECT_GRAPHIC_DrawObjects(void *);
extern void UN_SELECT_GRAPHIC_VBlank(void *);

void UN_SELECT_GRAPHIC_Task(void *unused, char *p)
{
    UN_SELECT_GRAPHIC_DrawObjects(p);
    UN_SELECT_GRAPHIC_VBlank(p + 4);
}
