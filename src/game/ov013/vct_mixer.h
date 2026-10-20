#ifndef GAME_OV013_VCT_MIXER_H
#define GAME_OV013_VCT_MIXER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of vct_mixer.c, prototypes copied from their definitions. */

#include "../ov013/vct_types.h"
#include "../types.h"

int VCT_MIXER_Init(void);
void VCT_MIXER_ClearMemberCount(void);
int VCT_MIXER_AddMember(VctPeer *peer);
void VCT_MIXER_RemoveMember(VctPeer *peer);
int VCT_MIXER_QueueFrame(const u8 *src, u32 length);
int VCT_MIXER_ReadChannel(void *dst, u32 size, u32 channelIndex, u32 *sourceMask);
int VCT_MIXER_MixVoices(void *output, u32 length, u32 *sourceMask);
int VCT_MIXER_SetCodecMode(int codecMode);
void VCT_MIXER_SetSendEnabled(int enabled);
void VCT_MIXER_SetFilterEnabled(int enabled);
/* END mkheaders: generated region */

#endif
