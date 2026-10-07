/*
 * file:     unit_0219DF30_p04.c
 * unit:     yes
 * function: func_0219E120, func_0219E1B8
 * address:  0x0219E120
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020948E0  0x020948E0  arm
 *   func_0219E8F8  0x0219E8F8  arm  ov009
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   g_021A8158  0x021A8158  data
 *   g_020A61DC  0x020A61DC  data
 *   SBServerGetStringValueA  0x0219E0C0  arm
 *   atof                     0x02095B2C  arm
 */
struct SBServer;
struct _SBServer;
typedef unsigned int   u32;

extern int func_020948E0(const char *a, const char *b);
extern int func_0219E8F8(const int *p);
extern char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def);
extern int func_020964E0(u32 a0);
extern char *SBServerGetStringValueA(struct _SBServer *server, char *keyname,
                                     char *def);
extern double atof(char *s);
int func_0219E120(struct SBServer *server, char *key, int idefault);
double SBServerGetFloatValueA(struct _SBServer *server, char *key, double fdefault);
extern char g_021A8158[];
extern const unsigned short g_020A61DC[];


static inline int isdigit(unsigned int c) { return (c >= 0x80) ? 0 : (g_020A61DC[c] & 8); }


/*
 * sdk:      SBServerGetIntValueA (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 */
int func_0219E120(struct SBServer *server, char *key, int idefault)
{
    char *s;

    if (server == 0)
        return idefault;
    if (func_020948E0(key, g_021A8158) == 0)
        return func_0219E8F8((const int *)server);
    s = func_0219E0C0((struct _SBServer *)server, key, 0);
    if (s == 0)
        return idefault;
    if (!isdigit(*(unsigned char *)(*s != 0x2d ? s : s + 1)))
        return idefault;
    return func_020964E0((u32)s);
}


double SBServerGetFloatValueA(struct _SBServer *server, char *key,
                              double fdefault)
{
    char *s = SBServerGetStringValueA(server, key, 0);

    if (s != 0)
        fdefault = atof(s);
    return fdefault;
}
