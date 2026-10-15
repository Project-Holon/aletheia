/*
 * function: STD_CopyLString
 * address:  0x0208CB10
 * packet:   pkt_0208CB10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      STD_CopyLString (std_string.o)
 *
 * symbols:
 *   STD_GetStringLength  0x0208CC78  arm
 */

extern int STD_GetStringLength(const char *str);

int STD_CopyLString(char *destp, const char *srcp, int siz)
{
    const char *s;
    unsigned long y;
    unsigned long val32;
    int i;
    unsigned long dstalign;

    s = srcp;
    i = 0;
    dstalign = (unsigned long)destp & 3;

    if ((dstalign ^ ((unsigned long)srcp & 3)) == 0) {
        if (dstalign != 0) {
            for (; i + dstalign < 4 && i < siz - 1; s++, i++) {
                destp[i] = *s;
                if (*s == '\0') {
                    goto end;
                }
            }
        }
        for (; i < siz - 4; i += 4) {
            val32 = *(const unsigned long *)(srcp + i);
            y = ~(((val32 & 0x7f7f7f7f) + 0x7f7f7f7f) | val32 | 0x7f7f7f7f);
            if (y != 0) {
                break;
            }
            *(unsigned long *)(destp + i) = val32;
        }
        s = srcp + i;
    }

    for (; i < siz - 1; i++, s++) {
        destp[i] = *s;
        if (*s == '\0') {
            goto end;
        }
    }

end:
    if (i >= siz - 1 && siz > 0) {
        destp[i] = '\0';
    }
    if (*s != '\0') {
        i += STD_GetStringLength(s);
    }
    return i;
}
