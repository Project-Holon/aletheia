/*
 * function: BTLV_MCSS_IsSpriteLoaded
 * address:  0x021FFD9C
 * packet:   pkt_021F6560
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_MCSS_IsSpriteLoaded   0x021FFD9C  thumb
 *   BTLV_MCSS_FindSpriteIndex 0x022019F4 thumb ov094

 *
 * lane O10 candidate
 */

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);

int BTLV_MCSS_IsSpriteLoaded(char *p, int key)
{
    if (BTLV_MCSS_FindSpriteIndex(p, key) != -1)
        return 1;
    return 0;
}

