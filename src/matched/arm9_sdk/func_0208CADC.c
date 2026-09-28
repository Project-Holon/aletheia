/*
 * function: func_0208CADC
 * address:  0x0208CADC
 * packet:   pkt_0208CADC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      STD_CopyString (std_string.o)
 */

char *func_0208CADC(char *destp, const char *srcp)
{
    char *retval = destp;

    while (*srcp != '\0') {
        *destp++ = *srcp++;
    }
    *destp = '\0';
    return retval;
}
