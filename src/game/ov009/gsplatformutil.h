#ifndef GAME_OV009_GSPLATFORMUTIL_H
#define GAME_OV009_GSPLATFORMUTIL_H

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

typedef struct B64StreamData {
    char *data;
    int len;
    int mode;
} B64StreamData;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsplatformutil.c, prototypes copied from their definitions. */

struct GSIResolveHostnameInfo;
struct tm;

#include "../types.h"

void gsiInt64ToString(char *theNumberStr, long long theNumber);
int gsiStartResolvingHostname(char *hostname, struct GSIResolveHostnameInfo **handle);
void gsiCancelResolvingHostname(void *p);
int gsiGetResolvedIP(int *p);
char *goastrdup(char *src);
char *_strlwr(char *s);
void SocketStartUp(void);
void SocketShutDown(void);
unsigned int current_time(void);
unsigned int current_time_hires(void);
void msleep(unsigned int msec);
struct tm *gsiSecondsToDate(long *timp);
long gsiDateToSeconds(struct tm *tb);
int nextlongrand(long seed);
int longrand(void);
void Util_RandSeed(unsigned int v);
unsigned int Util_RandInt(unsigned int min, unsigned int max);
void QuartToTrip(char *quart, char *trip, int inlen);
void TripToQuart(const char *src, u8 *dst, int n);
void B64Decode(const char *input, char *output, int inlen, int *outlen, int encodingType);
void B64Encode(const char *input, char *output, int inlen, int encodingType);
int B64DecodeLen(char *input, int encodingType);
void B64InitEncodeStream(B64StreamData *data, unsigned char *input, int len, int type);
int B64EncodeStream(B64StreamData *data, char *output);
/* END mkheaders: generated region */

#endif
