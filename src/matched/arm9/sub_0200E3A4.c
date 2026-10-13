/*
 * function: sub_0200E3A4
 * address:  0x0200E3A4
 * packet:   pkt_0200E3A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 16: promoted.  0x02167380 and 0x02167358 are unlabelled ov010
 *           leaves matched in src/matched/func_02167380.c and QUESTIONNAIRE_GetAnswerBitWidth.c
 *           (ov010/pkt_02167358); both attest as `matched, overlay`.
 *
 * symbols:
 *   func_02167380  0x02167380  thumb  ov010
 *   QUESTIONNAIRE_GetAnswerBitWidth  0x02167358  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 func_02167380(u32 id);
extern u8 QUESTIONNAIRE_GetAnswerBitWidth(u32 id);

u32 sub_0200E3A4(const u8 *bits, int id)
{
    u32 bit  = func_02167380(id);
    u32 n    = QUESTIONNAIRE_GetAnswerBitWidth(id);
    u32 byte = bit >> 3;
    u32 b    = bit & 7;
    u32 out  = 0;
    u32 i    = 0;

    while (n != 0) {
        out |= (u32)((bits[byte] >> b) & 1) << i;
        if (++b > 7) {
            byte++;
            b = 0;
        }
        i++;
        n--;
    }
    return out;
}
