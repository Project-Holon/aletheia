#ifndef GAME_OV015_IRC_INTERNAL_H
#define GAME_OV015_IRC_INTERNAL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc_internal.c, prototypes copied from their definitions. */

struct IRCParam;

#include "../types.h"

void IRCi_WaitCommand(void);
void IRCi_Init(void);
void IRCi_End(void);
unsigned char IRCi_CommWrite(struct IRCParam *param);
void IRCi_CommRead(struct IRCParam *param);
int IRCi_Read(u8 *buf);
void IRCi_Write(unsigned char *data, unsigned char size);
/* END mkheaders: generated region */

#endif
