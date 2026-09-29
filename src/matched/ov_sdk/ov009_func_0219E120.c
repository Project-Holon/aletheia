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
 *   func_020948E0  0x020948E0  arm
 *   func_0219E8F8  0x0219E8F8  arm  ov009
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   g_021A8158  0x021A8158  data
 *   g_020A61DC  0x020A61DC  data
 */

struct SBServer;

extern int func_020948E0(const char *a, const char *b);
extern int func_0219E8F8(struct SBServer *server);
extern char *func_0219E0C0(struct SBServer *server, char *key, char *def);
extern int func_020964E0(const char *s);
extern char g_021A8158[];
extern const unsigned short g_020A61DC[];

static inline int isdigit(unsigned int c) { return (c >= 0x80) ? 0 : (g_020A61DC[c] & 8); }

int func_0219E120(struct SBServer *server, char *key, int idefault)
{
    char *s;

    if (server == 0)
        return idefault;
    if (func_020948E0(key, g_021A8158) == 0)
        return func_0219E8F8(server);
    s = func_0219E0C0(server, key, 0);
    if (s == 0)
        return idefault;
    if (!isdigit(*(unsigned char *)(*s != 0x2d ? s : s + 1)))
        return idefault;
    return func_020964E0(s);
}
