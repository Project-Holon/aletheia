/*
 * function: SBServerGetFloatValueA
 * address:  0x0219E1B8
 * packet:   pkt_ov009_0219E1B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerGetFloatValueA (sb_server.o)
 *
 * symbols:
 *   SBServerGetStringValueA  0x0219E0C0  arm
 *   atof                     0x02095B2C  arm
 */

struct _SBServer;

extern char *SBServerGetStringValueA(struct _SBServer *server, char *keyname,
                                     char *def);
extern double atof(char *s);

double SBServerGetFloatValueA(struct _SBServer *server, char *key,
                              double fdefault)
{
    char *s = SBServerGetStringValueA(server, key, 0);

    if (s != 0)
        fdefault = atof(s);
    return fdefault;
}
