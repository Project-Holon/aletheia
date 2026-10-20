#ifndef GAME_OV009_GSTATS_H
#define GAME_OV009_GSTATS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gstats.c, prototypes copied from their definitions. */

void PlayerOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);
double PlayerOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
void PlayerOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
void TeamOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);
double TeamOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
void TeamOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
void *ServerOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);
double ServerOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
int ServerOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
int GetPlayerIndex(int *game, int pnum);
int GetTeamIndex(int *game, int tnum);
void ClosePendingCallbacks(void);
void CallReqCallback(int reqindex, int success, long modified, char *data, int length);
int ProcessInBuffer(char *buff, int len);
void ProcessStatement(char *buff, int len);
void ProcessSetData(char *buf, int len);
void ProcessGetData(char *buf, int len);
void ProcessGetPid(char *buf, int len);
void ProcessPlayerAuth(char *buf, int len);
int FindRequest(int reqtype, int localid, int profileid);
char *FindFinal(char *buff, int len);
int PersistCanReceiveOnSocket(int sock);
char *value_for_key_safe(char *s, char *key);
char *value_for_key(char *s, char *key);
void xcode_buf(char *buf, int len);
int PersistThink(void);
int IsStatsConnected(void);
void CloseStatsConnection(void);
/* END mkheaders: generated region */

#endif
