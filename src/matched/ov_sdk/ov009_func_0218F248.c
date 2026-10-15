/*
 * function: gpiPeerStartConnect
 * address:  0x0218F248
 * packet:   pkt_ov009_0218F248
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerStartConnect (libdwcgsgp.TWL.HYB.a gpipeer.o)
 *
 * symbols:
 *   func_0218FD9C  0x0218fd9c  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gsUdpEngineGetPeerState  0x02181010  arm   ov009
 *   gsUdpEngineStartTalkingToPeer  0x021810cc  arm   ov009
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189d78  arm   ov009
 *   gGpiPeerErrorConnecting     0x021a4e7c  data
 *   gGpiPeerErrorStartingComm     0x021a4f8c  data
 */

typedef struct {
    int state;
    int initiated;
    unsigned int ip;
    unsigned short port;
    int profile;
} GPIPeer;
typedef struct {
    char pad[0x1c];
    unsigned int ip;
    unsigned short port;
} GPIProfileInfo;
typedef struct {
    char pad[0xc];
    GPIProfileInfo *buddyStatusInfo;
} GPIProfile;
typedef struct {
    char pad[0x220];
    char initMsg[1];
} GPIConnection;
extern int func_0218FD9C(void *connection, int profileid, GPIProfile **pProfile);
extern void gpiSetErrorString(int *p, int b);
extern int gsUdpEngineGetPeerState(unsigned int ip, unsigned short port, int *state);
extern int gsUdpEngineStartTalkingToPeer(unsigned int ip, unsigned short port, char *msg, int timeOut);
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern char gGpiPeerErrorConnecting[];
extern char gGpiPeerErrorStartingComm[];

int gpiPeerStartConnect(void **connection, GPIPeer *peer)
{
    GPIProfile *profile;
    GPIConnection *iconnection;
    int anError;
    int result;
    int aPeerState;

    iconnection = (GPIConnection *)*connection;
    if (!func_0218FD9C(connection, peer->profile, &profile)) {
        gpiSetErrorString((int *)connection, (int)gGpiPeerErrorConnecting);
        return 3;
    }
    if (profile->buddyStatusInfo) {
        gsUdpEngineGetPeerState(profile->buddyStatusInfo->ip, profile->buddyStatusInfo->port, &aPeerState);
        if (aPeerState != 1 || aPeerState != 0) {
            anError = gsUdpEngineStartTalkingToPeer(profile->buddyStatusInfo->ip, profile->buddyStatusInfo->port,
                                    iconnection->initMsg, 10000);
            if (anError != 5) {
                gpiSetError((int *)connection, 5, (int)gGpiPeerErrorStartingComm);
                result = 3;
                gpiCallErrorCallback((int *)connection, result, 0);
                return result;
            }
        }
        peer->ip = profile->buddyStatusInfo->ip;
        peer->port = profile->buddyStatusInfo->port;
    }
    peer->state = 0x67;
    return 0;
}
