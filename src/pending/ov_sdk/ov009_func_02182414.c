/*
 * function: func_02182414
 * address:  0x02182414
 * packet:   pkt_ov009_02182414
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gsiXmlUtilParseName (libdwcgscommon.TWL.HYB.a gsxml.o)
 *
 * symbols:
 *   func_02181E28  0x02181e28  arm   ov009
 *   strchr         0x02094a28  arm
 *   g_020A61DC     0x020a61dc  data
 *   g_021A3F14     0x021a3f14  data
 *
 * notes: DIFF, 7 words: original loads the first char into r3 and the pointer
 *   buffer+*pos into r2, ours swaps r2/r3 (rest of the function is identical,
 *   loop shaped as while (*pos < len && strchr(...) == 0)). Tried: c var vs block
 *   var vs int, no c var, pointer temp first/after, &buffer[*pos], two ifs,
 *   declaration order, mLen store first.
 *
 * lane T5 (2026-09-30).  Pin sweep (all 9 dsi compilers x -O4,p/-O4,s/-inline off
 * /-ipa function): 1.1p1 -O4,p is the unique best, 7 concrete bytes, unchanged by
 * every other pin.  Residue is one register pair swapped over seven instructions
 * (+0038..+0088): image keeps the character in r3 and `buffer + *pos` in r2, this
 * build has them the other way round
 *   +0038  image `ldrsb r3, [sl, r0]`  | ours `ldrsb r2, [sl, r0]`.
 * Measured flat: `&buffer[*pos]` as the mData operand, a named `char *` pointer
 * local in three declaration positions, an `int idx = *pos` local, mLen written
 * before mData, the guard split into two ifs, and a `char *` cast on the base
 * (that one re-colours the entry block, 67 bytes).
 */

typedef struct GSIXmlString {
    char *mData;
    int mLen;
} GSIXmlString;

extern int func_02181E28(void *, char *, int, int *);
extern char *strchr(const char *, int);
extern const unsigned short g_020A61DC[];
extern char g_021A3F14[];

#define isalnum(c) (((c) < 0 || (c) >= 0x80) ? 0 : (g_020A61DC[c] & 0x9))
#define isdigit(c) (((c) < 0 || (c) >= 0x80) ? 0 : (g_020A61DC[c] & 0x8))

int func_02182414(void *stream, char *buffer, int len, int *pos, GSIXmlString *strOut)
{
    int haveNamespace = 0;
    char c;

    if (!func_02181E28(stream, buffer, len, pos))
        return 0;
    if (*pos >= len)
        return 0;
    c = buffer[*pos];
    if (!isalnum(c) || isdigit(c))
        return 0;
    strOut->mData = buffer + *pos;
    strOut->mLen = 1;
    (*pos)++;
    while (*pos < len && strchr(g_021A3F14, c = buffer[*pos]) == 0) {
        if (c == ':') {
            if (haveNamespace)
                return 0;
            haveNamespace = 1;
        } else if (c != '_' && c != '-' && !isalnum(c)) {
            return 1;
        }
        strOut->mLen++;
        (*pos)++;
    }
    return 1;
}
