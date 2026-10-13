/*
 * function: C_GEAR_OnCommEvent
 * address:  0x021F24FC
 * packet:   pkt_ov029_021F24FC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
void C_GEAR_OnCommEvent(unsigned char *p)
{
    p[0x451] = 2;
}
