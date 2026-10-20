#ifndef GAME_OV009_GPIPEER_H
#define GAME_OV009_GPIPEER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpipeer.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpiProcessPeerInitiatingConnection(void **connection, GPIPeer *peer);
int gpiProcessPeerAcceptingConnection(void **connection, GPIPeer *peer);
int gpiPeerSendMessages(void **connection, GPIPeer *peer);
int gpiProcessPeerConnected(void **connection, GPIPeer *peer);
void gpiCheckTimedOutPeerOperations(void **connection, GPIPeer *peer);
void gpiDestroyPeer(void **connection, GPIPeer *peer);
void gpiRemovePeer(void **connection, GPIPeer *peer);
int gpiProcessPeers(void **connection);
GPIPeer *gpiGetPeerByProfile(void **connection, int profileid);
GPIPeer *gpiGetPeerByAddr(void **connection, unsigned int ip, unsigned short port);
void gpiFreeMessage(void **p);
GPIPeer *gpiAddPeer(void **connection, int profileid, int initiate);
int gpiPeerGetSig(void **connection, GPIPeer *peer);
int gpiPeerStartConnect(void **connection, GPIPeer *peer);
int gpiPeerAddMessage(void **connection, GPIPeer *peer, int type, char *message);
int gpiPeerStartTransferMessage(void **connection, GPIPeer *peer, int type, GPITransferID *transferID);
int gpiPeerFinishTransferMessage(void **connection, GPIPeer *peer, char *message, int len);
void gpiPeerLeftCallback(unsigned int ip, unsigned short port, void *unused, void **connection);
void gpiPeerMessageCallback(unsigned int ip, unsigned short port, unsigned char *message, int messageLength, int unused, void *userData);
void gpiPeerAcceptedCallback(unsigned int ip, unsigned short port, int unused, int rejected, void *userData);
void gpiPeerPingReplyCallback(void);
void gpiPeerAddOp(GPIPeer *peer, GPIPeerOp *operation);
void gpiPeerRemoveOp(GPIPeer *peer, GPIPeerOp *operation);
/* END mkheaders: generated region */

#endif
