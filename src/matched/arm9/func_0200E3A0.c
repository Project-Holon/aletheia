/*
 * function: SYMBOL_SAVE_GetQuestionnaireBits
 * address:  0x0200E3A0
 * packet:   pkt_0200E024
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the argument plus 0xd2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SYMBOL_SAVE_GetQuestionnaireBits.c \
 *       --func SYMBOL_SAVE_GetQuestionnaireBits --addr 0x0200E3A0 --thumb --cc 1.1p1
 */

typedef unsigned char u8;

void *SYMBOL_SAVE_GetQuestionnaireBits(void *a)
{
    return (u8 *)a + 0xd2;
}
