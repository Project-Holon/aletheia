#ifndef GAME_OV009_GPIINFO_H
#define GAME_OV009_GPIINFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpiinfo.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"
#include "../ov009/gpi_types.h"

int gpiIsValidDate(int day, int month, int year);
int gpiIntToDate(void **connection, int date, int *day, int *month, int *year);
void gpiInfoCacheToArg(GPIInfoCache *cache, GPGetInfoResponseArg *arg);
int gpiProcessGetInfo(void **connection, GPIOperation *operation, char *input);
int gpiAddLocalInfo(void **connection, void *buffer);
int gpiSendLocalInfo(void **connection, char *info, char *value);
int gpiSendUserInfo(void **connection, char *info, char *value);
GPResult gpiSetInfoi(void **connection, int info, int value);
GPResult gpiSetInfos(void **connection, int info, char *value);
int gpiSendGetInfo(void **connection, int profileid, int operationid);
int gpiGetInfo(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
int gpiSetInfoCache(void **connection, GPIProfile *profile, GPIInfoCache *cache);
void gpiFreeInfoCache(GPIProfile *profile);
/* END mkheaders: generated region */

#endif
