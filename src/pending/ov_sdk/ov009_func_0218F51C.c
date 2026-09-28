/*
 * function: func_0218F51C
 * address:  0x0218F51C
 * packet:   pkt_ov009_0218F51C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Byte-correct (216/216), 6 of 8 relocation sites resolved.
 * Blocker: g_021A4FF0 and g_021A4FEC (string literals) have no witness outside
 * this extent; the only other users are unmatched gpipeer.o/gpitransfer.o code.
 * Re-verify once another function referencing them is matched.
 *
 * sdk:      gpiPeerFinishTransferMessage (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_02084F40  0x02084F40  arm
 *   func_02189750  0x02189750  arm  ov009
 *   func_0218964C  0x0218964C  arm  ov009
 *   func_02189644  0x02189644  arm  ov009
 *   func_02184098  0x02184098  arm  ov009
 *   g_021A4FEC  0x021A4FEC  data
 *   g_021A4FF0  0x021A4FF0  data
 */

struct GPIPeer {
    char pad0[0x14];
    int timeout;
};

extern int func_0209477C(char *s);
extern int func_02084F40(char *dst, char *fmt, ...);
extern int func_02189750(void **connection, struct GPIPeer *peer, char *string);
extern int func_0218964C(void **connection, struct GPIPeer *peer, char *string, int stringLen);
extern int func_02189644();
extern long func_02184098(long *timer);
extern char g_021A4FEC[];
extern char g_021A4FF0[];

int func_0218F51C(void **connection, struct GPIPeer *peer, char *message, int len)
{
    char buffer[32];
    int result;

    if (peer == 0)
        return 3;
    if (message == 0)
        message = g_021A4FF0;
    if (len == -1)
        len = func_0209477C(message);
    func_02084F40(buffer, g_021A4FEC, len);
    result = func_02189750(connection, peer, buffer);
    if (result != 0)
        return result;
    result = func_0218964C(connection, peer, message, len);
    if (result != 0)
        return result;
    result = func_02189644(connection, peer, 0);
    if (result != 0)
        return result;
    peer->timeout = func_02184098(0) + 10000;
    return 0;
}
