/*
 * function: FLDMMDL_BLACT_GetAnimeTable
 * address:  0x0219D3E4
 * packet:   pkt_0219D3E4
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexes an array of 8-byte records based at 0x021D7F68.
 *
 * symbols:
 *   sBlactAnimeTable  0x021D7F68  data  ov021
 */

extern char sBlactAnimeTable[];

char *FLDMMDL_BLACT_GetAnimeTable(int i)
{
    return sBlactAnimeTable + i * 8;
}
