/*
 * function: SBServerAddIntKeyValue
 * address:  0x0219E084
 * packet:   pkt_ov009_0219E084
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerAddIntKeyValue (sb_server.o)
 *
 * symbols:
 *   OS_SPrintf            0x02084F40  arm
 *   SBServerAddKeyValue   0x0219E01C  arm
 *   g_021A8154            0x021A8154  data
 */

struct _SBServer;

extern int OS_SPrintf(char *dst, char *fmt, ...);
extern void SBServerAddKeyValue(struct _SBServer *server, char *keyname,
                                char *value);
extern char g_021A8154[];

void SBServerAddIntKeyValue(struct _SBServer *server, char *keyname, int value)
{
    char stemp[20];

    OS_SPrintf(stemp, g_021A8154, value);
    SBServerAddKeyValue(server, keyname, stemp);
}
