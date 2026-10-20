#ifndef GAME_OV107_MB_GAMEINFO_H
#define GAME_OV107_MB_GAMEINFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mb_gameinfo.c, prototypes copied from their definitions. */

struct MbGameInfo;
typedef struct MbGameInfo MbGameInfo;

#include "../types.h"

void MBi_MakeGameInfo(u8 *gameInfop, const u8 *mbGameRegp, const u8 *parent);
int MBi_ReadIconInfo(char *filePathp, unsigned char *iconp, int char_flag);
void MB_UpdateGameInfoMember(unsigned char *gameInfop, void *member, unsigned short nowPlayerFlag, unsigned short changePlayerFlag);
int mystrlen(const u16 *str);
void MB_AddGameInfo(MbGameInfo *newGameInfop);
void MB_InitSendGameInfoStatus(void);
void MBi_ClearSendStatus(void);
void MB_SendGameInfoBeacon(u32 ggid, u16 tgid, u8 attribute);
int MBi_ReadyBeaconSendStatus(void);
void MBi_InitSendFixedBeacon(void);
void MBi_InitSendVolatBeacon(void);
BOOL MBi_CheckMBParent(void *bssDescp);
/* END mkheaders: generated region */

#endif
