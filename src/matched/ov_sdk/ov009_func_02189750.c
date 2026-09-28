/*
 * function: gpiSendOrBufferString
 * address:  0x02189750
 * packet:   pkt_ov009_02189750
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendOrBufferString (gpibuffer.o)
 *
 * The DWARF of the defining object names this subprogram
 * gpiAppendStringToBuffer, but the image symbol at 0x02189750 is
 * gpiSendOrBufferString; the body forwards to
 * gpiSendOrBufferStringLenToPeer (0x0218964C).
 *
 * symbols:
 *   strlen                          0x0209477C  arm
 *   gpiSendOrBufferStringLenToPeer  0x0218964C  arm
 */

struct GPIPeer_s;

extern int strlen(char *s);
extern int gpiSendOrBufferStringLenToPeer(void **connection,
                                          struct GPIPeer_s *peer,
                                          char *string, int stringLen);

int gpiSendOrBufferString(void **connection, struct GPIPeer_s *peer,
                          char *string)
{
    return gpiSendOrBufferStringLenToPeer(connection, peer, string,
                                          strlen(string));
}
