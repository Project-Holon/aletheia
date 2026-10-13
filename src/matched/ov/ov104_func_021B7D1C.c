/*
 * function: IRC_RHYTHM_GetActor
 * address:  0x021B7D1C
 * packet:   pkt_ov104_021B7968
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor, witness for the thunk IRC_RHYTHM_GetScreenActor.
 */

int IRC_RHYTHM_GetActor(unsigned char *p, int i)
{
    return *(int *)(p + i * 4 + 0x28);
}
