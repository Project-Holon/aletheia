/*
 * function: func_0218F51C
 * address:  0x0218F51C
 * packet:   pkt_ov009_0218F51C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte-correct (216/216), 8 of 8 relocation sites resolved.
 *
 * The two pool words at the end are in the order the code first names them:
 * the `ldreq` at +0028 (the `message == 0` default) addresses +00D0, which the
 * image fills with 0x021A4FEC -- the compiler's 1-byte empty string @15025 --
 * and the `ldr` at +0044 (OS_SPrintf's format) addresses +00D4 = 0x021A4FF0,
 * "\len\%d\msg\\\n", @15026.  Spelling them the other way round still
 * reproduces every instruction, because the pool slots are the same either
 * way, but the two words come out exchanged and `sole-ref/self`, which
 * compares the word it is about to write with the ROM word at the site,
 * refuses both.  Both literals are attested by the overlay's own image
 * (ov009 window, the only two candidate windows holding them are ov009 and
 * ov021 and only ov009's bytes are read, the function under test living there).
 *
 * The DWARF carries three separate `enum _GPResult __result__` locals, all in
 * r0, one per if-chain, so the original almost certainly declared a result in
 * each of three sibling blocks rather than reusing one.  The single `result`
 * below colours identically -- r0 in all three, r4 never live across a call --
 * and reproduces all 216 bytes, so the extra scopes buy nothing here.
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
extern char g_021A4FEC[];   /* "" -- the default when message is 0 */
extern char g_021A4FF0[];   /* "\len\%d\msg\\\n" -- OS_SPrintf's format */

int func_0218F51C(void **connection, struct GPIPeer *peer, char *message, int len)
{
    char buffer[32];
    int result;

    if (peer == 0)
        return 3;
    if (message == 0)
        message = g_021A4FEC;
    if (len == -1)
        len = func_0209477C(message);
    func_02084F40(buffer, g_021A4FF0, len);
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
