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
