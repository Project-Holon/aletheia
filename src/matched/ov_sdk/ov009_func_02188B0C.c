/*
 * function: gpiBuddyHandleKeyRequest
 * address:  0x02188B0C
 * packet:   pkt_ov009_02188B0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiBuddyHandleKeyRequest (gpibuddy.o)
 *
 * symbols:
 *   gpiSaveKeysToBuffer  0x0218DA40  arm   ov009
 *   gpiSendBuddyMessage  0x021889A0  arm   ov009
 *   strcmp  0x020948E0  arm  
 *   gsifree  0x0217EAE0  arm   ov009
 *   g_021A4468     0x021A4468  data  ov009
 */

typedef struct GPIPeer {
    unsigned char pad[0x10];
    int profile;
} GPIPeer;

extern int gpiSaveKeysToBuffer(void **connection, char **buffer);
extern int gpiSendBuddyMessage(void **connection, int profileid, int type, char *message,
                         int sendOption, void *peerOp);
extern int strcmp(const char *s1, const char *s2);
extern void gsifree(void *ptr);
extern char g_021A4468[];

int gpiBuddyHandleKeyRequest(void **connection, GPIPeer *peer)
{
    char *message;
    int result;

    if ((result = gpiSaveKeysToBuffer(connection, &message)) != 0)
        return result;
    if (message == 0)
        message = g_021A4468;
    if ((result = gpiSendBuddyMessage(connection, peer->profile, 0x69, message, 0xB00, 0)) != 0)
        return result;
    {
        char *m = message;
        if (strcmp(m, g_021A4468) != 0)
            gsifree(m);
    }
    return 0;
}
