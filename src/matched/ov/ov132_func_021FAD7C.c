/*
 * function: STA_ACT_SCRIPT_CountScripts
 * address: 0x021FAD7C
 * packet: pkt_ov132_021FAD7C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: unlabelled follower in 021FAD2C extent; counts ten nonnull slots.
 */
typedef unsigned char u8;
u8 STA_ACT_SCRIPT_CountScripts(char *p)
{
    u8 i;
    u8 count;
    count = 0;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) != 0) count++;
    return count;
}
