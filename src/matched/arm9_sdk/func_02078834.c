/*
 * function: FSi_DecrementSjisPositionToSlash
 * address:  0x02078834
 * packet:   pkt_02078834
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_DecrementSjisPositionToSlash (libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
 *   FSi_DecrementSjisPosition  0x020787A0  arm
 */

extern int FSi_DecrementSjisPosition(const char *str, int pos);

int FSi_DecrementSjisPositionToSlash(const char *str, int pos)
{
    for (;;)
    {
        pos = FSi_DecrementSjisPosition(str, pos);
        if ((pos < 0) || ((unsigned char)str[pos] == '/') || ((unsigned char)str[pos] == 0x5C))
        {
            break;
        }
    }
    return pos;
}
