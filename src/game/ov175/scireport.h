#ifndef GAME_OV175_SCIREPORT_H
#define GAME_OV175_SCIREPORT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of scireport.c, prototypes copied from their definitions. */

#include "../ov175/sc_types.h"

int sciCreateReport(unsigned char *theSessionId, unsigned int theHeaderVersion, unsigned int thePlayerCount, unsigned int theTeamCount, SCIReport **theReportOut);
int sciDestroyReport(SCIReport *theReport);
int sciReportSetPlayerConnectionId(SCIReport *theReport, unsigned int thePlayerIndex, unsigned char *thePlayerConnectionId);
int sciReportSetPlayerTeamIndex(SCIReport *theReport, unsigned int thePlayerIndex, unsigned int thePlayerTeamIndex);
int sciReportSetPlayerGameResult(SCIReport *theReport, int thePlayerIndex, int thePlayerResult);
int sciReportReturnZero(SCIReport *theReport, unsigned int thePlayerIndex, void *theCertificate, unsigned char *theAuthHash);
int sciReportBeginNewPlayer(SCIReport *theReport);
int sciReportBeginGlobalData(SCIReport *theReport);
int sciReportBeginPlayerData(SCIReport *theReport);
int sciReportBeginTeamData(SCIReport *theReport);
int sciReportReturnZeroWithArg(SCIReport *theReport);
int sciReportEnd(SCIReport *theReport, int isAuthoritative, unsigned int theGameStatus);
int sciReportAddIntValue(SCIReport *theReport, int theKey, int theValue);
int sciReportAddByteValue(SCIReport *theReport, int theKey, int theValue);
/* END mkheaders: generated region */

#endif
