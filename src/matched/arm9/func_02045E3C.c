/*
 * function: MSGDATA_DecryptUnits
 * address:  0x02045E3C
 * packet:   pkt_02045C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetEosChar  0x02045A98  arm
 *
 * The message-bank string cipher, decrypting a raw UTF-16-code-unit run in
 * place. This is the routine the asset lane's tools/assets/text.py was
 * reverse-engineering; the code states the scheme exactly:
 *
 *   key = (u16)((msgIndex + 3) * 0x2983)
 *   for each code unit: unit ^= key, then key = rotate_left_16(key, 3)
 *
 * The seed is derived forward from the entry's own descriptor index in the
 * message file, so no brute force or terminator-anchored back-solve is
 * needed. Decryption stops at the first unit that equals the global
 * end-of-string code STRBUF_GetEosChar() returns (0xFFFF in this build), and the
 * function returns the index of that unit, i.e. the decoded length; if no
 * terminator is found inside count units it returns count.
 *
 * Note for the asset side: there is no compression layer on top of this
 * cipher. Decoded streams are plain code units plus in-band control codes
 * (0xFFFF terminator, 0xFFFE line break, 0xF000 escape introducer followed
 * by a kind word, an argument count and that many argument words).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSGDATA_DecryptUnits.c \
 *       --func MSGDATA_DecryptUnits --addr 0x02045E3C --cc 1.1p1
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 STRBUF_GetEosChar(void);

u32 MSGDATA_DecryptUnits(u16 *str, u32 count, u32 msgIndex)
{
    u16 eos = STRBUF_GetEosChar();
    u16 key = (u16)((msgIndex + 3) * 0x2983);
    u32 i;

    for (i = 0; i < count; i++) {
        *str ^= key;
        if (*str == eos) {
            return i;
        }
        str++;
        key = (u16)(((key & 0xE000) >> 13) | (u16)(key << 3));
    }

    return count;
}
