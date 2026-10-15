/*
 * function: gpiPeerStartTransferMessage
 * address:  0x0218F4BC
 * packet:   pkt_ov009_0218F4BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerStartTransferMessage (gpipeer.o)
 *
 * symbols:
 *   OS_SPrintf             0x02084F40  arm
 *   gpiSendOrBufferString  0x02189750  arm
 *   gGpiPeerXferFmt             0x021A4FD8  data
 */

struct GPIPeer_s;

struct GPITransferID_s {
    int          profileid;  /* +0x00 */
    unsigned int count;      /* +0x04 */
    unsigned int time;       /* +0x08 */
};

extern int  OS_SPrintf(char *dst, char *fmt, ...);
extern int  gpiSendOrBufferString(void **connection, struct GPIPeer_s *peer,
                                  char *string);
extern char gGpiPeerXferFmt[];

int gpiPeerStartTransferMessage(void **connection, struct GPIPeer_s *peer,
                                int type, struct GPITransferID_s *transferID)
{
    char buffer[64];
    int profileid;
    unsigned int count;
    unsigned int time;

    profileid = transferID->profileid;
    count = transferID->count;
    time = transferID->time;
    if (transferID == 0)
        return 3;
    OS_SPrintf(buffer, gGpiPeerXferFmt, type, profileid, count, time);
    return gpiSendOrBufferString(connection, peer, buffer);
}
