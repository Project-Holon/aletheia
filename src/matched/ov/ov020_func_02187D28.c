/*
 * function: EL_SCOREBOARD_RequestFinish
 * address:  0x02187D28
 * packet:   pkt_ov020_02187D28
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
typedef unsigned int u32;

void EL_SCOREBOARD_RequestFinish(u32 *p)
{
    p[4] = 1;
}
