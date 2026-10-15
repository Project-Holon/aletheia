/*
 * function: STD_SearchString
 * address:  0x0208CC14
 * packet:   pkt_0208CC14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      STD_SearchString (std_string.o)
 */

char *STD_SearchString(const char *srcp, const char *str)
{
    int i;
    int n;

    for (i = 0; srcp[i] != '\0'; i++) {
        n = 0;
        while (str[n] != '\0' && srcp[i + n] == str[n]) {
            n++;
        }
        if (str[n] == '\0') {
            return (char *)&srcp[i];
        }
    }
    return 0;
}
