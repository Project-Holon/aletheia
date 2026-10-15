/*
 * function: GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond
 * address:  0x02165C60
 * packet:   pkt_02165C60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SYMBOL_SAVE_GetQuestionnaireAnswer  0x0200E3A4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 SYMBOL_SAVE_GetQuestionnaireAnswer(const u8 *bits, int id);

int GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond(int a0)
{
    int a1;

a0 = a0 + 0x50;
a1 = 0x1a;
    a0 = SYMBOL_SAVE_GetQuestionnaireAnswer((const u8 *)a0, a1);
loc_02165C6A:
    if (a0 != 0) goto loc_02165C72;
loc_02165C6E:
a0 = 0xff;
    return a0;
loc_02165C72:
a0 = a0 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    return a0;}
