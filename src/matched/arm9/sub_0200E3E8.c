/*
 * function: SYMBOL_SAVE_WriteBitField
 * address:  0x0200E3E8
 * packet:   pkt_0200E3E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 16: promoted.  0x02167380 and 0x02167358 are unlabelled ov010
 *           leaves matched in src/matched/QUESTIONNAIRE_GetAnswerBitOffset.c and QUESTIONNAIRE_GetAnswerBitWidth.c
 *           (ov010/pkt_02167358); both attest as `matched, overlay`.
 *
 * near miss resolved (wave 4, permuter): the note's 88-byte version was a
 * six-register permutation away. Two spellings closed it, neither of which
 * the permuter's mutation set can reach (both change the emitted
 * instruction kinds, not the allocation):
 *   - the clear mask is (u8)(0xFFu ^ (1u << b)), which emits
 *     `movs r6,#0xff; eors r6,r7`; the ~ spelling emits a single `mvns`
 *     and is the whole 2-byte size gap.
 *   - inside the wrap test, `byte++` must precede `b = 0`; the reverse
 *     order emits `movs #0` before the `adds` and shifts the allocation.
 *
 * symbols:
 *   QUESTIONNAIRE_GetAnswerBitOffset  0x02167380  thumb  ov010
 *   QUESTIONNAIRE_GetAnswerBitWidth  0x02167358  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 QUESTIONNAIRE_GetAnswerBitOffset(u32 id);
extern u8 QUESTIONNAIRE_GetAnswerBitWidth(u32 id);

void SYMBOL_SAVE_WriteBitField(u8 *bits, int id, u32 value)
{
    u32 bit = QUESTIONNAIRE_GetAnswerBitOffset(id);
    u32 n   = QUESTIONNAIRE_GetAnswerBitWidth(id);
    u32 byte = bit >> 3;
    u32 b    = bit & 7;

    while (n != 0) {
        bits[byte] &= (u8)(0xFFu ^ (1u << b));
        bits[byte] |= (u8)((value & 1) << b);
        b++;
        if (b > 7) {
            byte++;
            b = 0;
        }
        value >>= 1;
        n--;
    }
}
