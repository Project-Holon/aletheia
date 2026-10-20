#ifndef GAME_OV015_IRC_H
#define GAME_OV015_IRC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc.c, prototypes copied from their definitions. */

#include "../types.h"

unsigned short IRCi_CalcSum(void *input, unsigned long length);
void IRCi_Restore(void);
void IRCi_ResetState(void);
void IRC_Init(u8 unitId);
void IRC_Connect(void);
unsigned int IRC_IsSender(void);
unsigned int IRC_IsConnect(void);
void IRCi_Send(unsigned char *data, unsigned char size, int command, unsigned char id);
void IRCi_Finish(int n);
void IRC_Shutdown(void);
void IRC_Send(u8 *data, u8 size, int command);
void IRCi_Nop(void);
int IRCi_CheckLength(unsigned long n);
int IRCi_CheckTimeout(void);
int IRCi_CheckPacket(unsigned long n);
int IRC_Move(void);
void IRC_SetRecvCallback(void *cb);
void IRC_SetUnitNumber(unsigned int n);
unsigned int IRC_GetUnitNumber(void);
/* END mkheaders: generated region */

#endif
