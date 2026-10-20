#ifndef GAME_OV009_GSSOAP_H
#define GAME_OV009_GSSOAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gssoap.c, prototypes copied from their definitions. */

struct GSSoapTask;
typedef struct GSSoapTask GSSoapTask;

#include "../ov175/auth_types.h"

void *gsiExecuteSoap(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void *theUserData);
GSSoapTask *gsiExecuteSoapWithTimeout(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, unsigned int theTimeoutMs, void *theUserData);
GSSoapTask *gsiExecuteSoapCustom(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc, void (*theCustomFunc)(void *, void *), void *theUserData);
int gsiSoapTaskHttpCompletedCallback(int request, int result, char *buffer, int bufferLen, void *param);
int gsiSoapTaskThink(void *theTask);
void gsiSoapTaskExecute(void *theTask);
void gsiSoapTaskCancel(void *theTask);
void gsiSoapTaskCallback(void *theTask, int theResult);
int gsiSoapTaskCleanup(void *theTask);
/* END mkheaders: generated region */

#endif
