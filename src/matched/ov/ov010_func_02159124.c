/*
 * function: SCRIPT_WORK_GetTrainerEntry
 * address:  0x02159124
 * packet:   pkt_02159124
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

char *SCRIPT_WORK_GetTrainerEntry(char *p, int i)
{
    return p + 0x44 + i * 0x1c;
}
