/*
 * function: THE_END_GRAPHIC_Update
 * address:  0x021B99E8
 * packet:   pkt_ov182_021B99E8
 * region:   ov182
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   THE_END_GRAPHIC_DrawActors  0x021B9B10  thumb  ov182
 *   THE_END_GRAPHIC_Dummy2  0x021B9AA8  thumb  ov182
 */

extern void THE_END_GRAPHIC_DrawActors(void *);
extern void THE_END_GRAPHIC_Dummy2(void *);

void THE_END_GRAPHIC_Update(char *p)
{
    THE_END_GRAPHIC_DrawActors(p + 4);
    THE_END_GRAPHIC_Dummy2(p);
}
