/*
 * function: func_0219E120
 * address:  0x0219E120
 * packet:   pkt_ov009_0219E120
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerGetIntValueA (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 *
 * symbols:
 *   strcmp  0x020948E0  arm
 *   SBServerGetPing  0x0219E8F8  arm  ov009
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   atoi  0x020964E0  arm
 *   g_021A8158  0x021A8158  data
 *   g_020A61DC  0x020A61DC  data
 */

struct SBServer;

extern int strcmp(const char *a, const char *b);
struct _SBServer;
extern int SBServerGetPing(const int *p);
extern char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def);
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern char g_021A8158[];
extern const unsigned short g_020A61DC[];

static inline int isdigit(unsigned int c) { return (c >= 0x80) ? 0 : (g_020A61DC[c] & 8); }

int func_0219E120(struct SBServer *server, char *key, int idefault)
{
    char *s;

    if (server == 0)
        return idefault;
    if (strcmp(key, g_021A8158) == 0)
        return SBServerGetPing((const int *)server);
    s = func_0219E0C0((struct _SBServer *)server, key, 0);
    if (s == 0)
        return idefault;
    if (!isdigit(*(unsigned char *)(*s != 0x2d ? s : s + 1)))
        return idefault;
    return atoi((u32)s);
}
