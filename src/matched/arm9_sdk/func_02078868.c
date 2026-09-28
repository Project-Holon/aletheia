/*
 * function: func_02078868
 * address:  0x02078868
 * packet:   pkt_02078868
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_TrimSjisTrailingSlash (libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
 *   STD_GetStringLength  0x0208CC78  arm
 *   FSi_DecrementSjisPosition  0x020787A0  arm
 */

extern int STD_GetStringLength(const char *str);
extern int FSi_DecrementSjisPosition(const char *str, int pos);

int func_02078868(char *str)
{
    int length = STD_GetStringLength(str);
    int lastpos = FSi_DecrementSjisPosition(str, length);

    if ((lastpos >= 0) && (((unsigned char)str[lastpos] == '/') || ((unsigned char)str[lastpos] == 0x5C)))
    {
        length = lastpos;
        str[length] = '\0';
    }
    return length;
}
