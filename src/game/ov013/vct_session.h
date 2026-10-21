#ifndef GAME_OV013_VCT_SESSION_H
#define GAME_OV013_VCT_SESSION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vct_session.c, prototypes copied from their definitions. */

#include "../ov013/vct_types.h"
#include "../ov013/vct_types.h"

void VCT_SESSION_CheckAnnounceTimeout(void);
int VCT_SESSION_HandlePacket(int senderId, VctPacket *packet, int length, VctEvent *event);
VctPeer *VCT_SESSION_AllocPeer(unsigned int peerId);
int VCT_SESSION_SendCommand(VctPeer *peer, int command);
int VCT_SESSION_SendReply(VctPeer *peer, int command);
void VCT_SESSION_FillAnnounceFields(VctPeer *peer, VctPacket *packet);
int VCT_SESSION_BroadcastPacket(VctPeer *peer, VctPacket *packet);
void VCT_SESSION_BroadcastState(int flag);
void VCT_SESSION_InitPeer(VctPeer *peer, unsigned int peerId);
int VCT_SESSION_SendPacket(VctPeer *peer, VctPacket *packet);
int VCT_SESSION_GetEventCode(VctPacket *packet, VctPeer *peer);
int VCT_SESSION_InitPacketHeader(VctPeer *peer, VctPacket *packet, int command);
int VCT_SESSION_AdvancePhase(VctPeer *peer, VctPacket *packet);
int VCT_SESSION_HasNoOtherTalker(VctPeer *peer);
int VCT_SESSION_CheckCommandAllowed(VctPeer *peer, const VctPacket *packet);
VctPeer *VCT_SESSION_FindPeer(int peerId);
int VCT_SESSION_HandlePairedPacket(VctPacket *packet, VctEvent *event);
int VCT_SESSION_HandleSharedPacket(VctPacket *packet, VctEvent *event);
int VCT_SESSION_HandleUnknownProtocolPacket(VctPacket *packet, VctEvent *event);
int VCT_SESSION_HandleAnnounce(VctPacket *packet, VctEvent *event);
/* END mkheaders: generated region */

#endif
