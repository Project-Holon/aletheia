/*
 * function: GAME_BEACON_PopQuestionnaireUpdated
 * address:  0x020270E0
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_Work  0x02146940  data
 */

typedef unsigned char u8;

extern void *GAME_BEACON_Work;

u8 GAME_BEACON_PopQuestionnaireUpdated(void)
{
    u8 *ptr = *(u8 **)&GAME_BEACON_Work;
    u8 ret;

    if (ptr == 0) {
        return 0;
    }

    ret = ptr[0xbaf];
    ptr[0xbaf] = 0;
    return ret;
}
