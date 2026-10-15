/*
 * function: SBServerParseKeyVals
 * address:  0x0219E33C
 * packet:   pkt_ov009_0219E33C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerParseKeyVals (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 *
 * symbols:
 *   func_0219E2D4  0x0219E2D4  arm  ov009
 *   CheckValidKey  0x0219E274  arm  ov009
 *   qr2_internal_is_master_only_key  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   g_021A8160  0x021A8160  data
 */

struct SBServer;

extern char *func_0219E2D4(char *instr, char delim);
extern int CheckValidKey(char *key);
extern int qr2_internal_is_master_only_key(char *keyname);
extern void func_0219E01C(struct SBServer *server, char *keyname, char *value);
extern char g_021A8160[];

void SBServerParseKeyVals(struct SBServer *server, char *keyvals)
{
    char *k;
    char *v;

    k = func_0219E2D4(keyvals + 1, 0x5c);
    while (k != 0) {
        v = func_0219E2D4(0, 0x5c);
        if (v == 0)
            v = g_021A8160;
        if (CheckValidKey(k) && !qr2_internal_is_master_only_key(k))
            func_0219E01C(server, k, v);
        k = func_0219E2D4(0, 0x5c);
    }
}
