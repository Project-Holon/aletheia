/*
 * function: func_021889A0
 * address:  0x021889A0
 * packet:   pkt_ov009_021889A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSendBuddyMessage (libdwcgsgp.TWL.HYB.a gpibuddy.o)
 *
 * symbols:
 *   gpiGetPeerByProfile  0x0218F0B8  arm   ov009
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   func_021888C0  0x021888C0  arm   ov009
 *   gpiAddPeer  0x0218F150  arm   ov009
 *   func_0218F1E0  0x0218F1E0  arm   ov009
 *   gpiPeerStartConnect  0x0218F248  arm   ov009
 *   func_0218F884  0x0218F884  arm   ov009
 *   gpiPeerAddMessage  0x0218F350  arm   ov009
 */

typedef enum { GP_NO_ERROR, GP_MEMORY_ERROR, GP_PARAMETER_ERROR, GP_NETWORK_ERROR } GPResult;

typedef struct GPIPeer {
    int state;
} GPIPeer;

typedef struct GPIPeerOp GPIPeerOp;

typedef struct GPIBuddyStatusInfo {
    char pad0[0x20];
    unsigned short f20;
} GPIBuddyStatusInfo;

typedef struct GPIProfile {
    char pad0[0xc];
    GPIBuddyStatusInfo *buddyStatus;
    char pad1[0x1c - 0x10];
    int f1C;
} GPIProfile;

extern char *gpiGetPeerByProfile(void **p, int v);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern GPResult func_021888C0(void **connection, int profileid, int type, char *message);
extern GPIPeer *gpiAddPeer(void **connection, int profileid, int initiate);
extern GPResult func_0218F1E0(void **connection, GPIPeer *peer);
extern GPResult gpiPeerStartConnect(void **connection, GPIPeer *peer);
extern void func_0218F884(GPIPeer *peer, GPIPeerOp *operation);
extern GPResult gpiPeerAddMessage(void **connection, GPIPeer *peer, int type, char *message);

GPResult func_021889A0(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp)
{
    GPResult result;
    GPIProfile *profile;
    GPIPeer *peer;

    peer = (GPIPeer *)gpiGetPeerByProfile(connection, profileid);
    if (peer == 0) {
        if (!func_0218FD9C(connection, profileid, &profile) || profile->buddyStatus == 0 || profile->buddyStatus->f20 == 0) {
            if (sendOption == 0xb00)
                return GP_NETWORK_ERROR;
            return func_021888C0(connection, profileid, type, message);
        }
        peer = gpiAddPeer(connection, profileid, 1);
        if (peer == 0)
            return GP_MEMORY_ERROR;
        if (profile->f1C == 0) {
            result = func_0218F1E0(connection, peer);
            if (result != GP_NO_ERROR)
                return result;
        } else {
            result = gpiPeerStartConnect(connection, peer);
            if (result != GP_NO_ERROR)
                return result;
        }
    } else if (peer->state == 0x6a) {
        if (func_0218FD9C(connection, profileid, &profile)) {
            if (profile->buddyStatus != 0)
                profile->buddyStatus->f20 = 0;
            if (sendOption == 0xb00)
                return GP_NETWORK_ERROR;
            if (type < 100)
                return func_021888C0(connection, profileid, type, message);
        }
    }
    if (peerOp != 0)
        func_0218F884(peer, peerOp);
    result = gpiPeerAddMessage(connection, peer, type, message);
    if (result != GP_NO_ERROR)
        return result;
    return GP_NO_ERROR;
}
