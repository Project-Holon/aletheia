#ifndef GAME_ARM9_GF_STANDARD_H
#define GAME_ARM9_GF_STANDARD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gf_standard.c, prototypes copied from their definitions. */

struct Lcg64;
struct RtcRequest;
struct RtcDateSigned;

#include "../types.h"
#include "../sdk_rtc.h"
#include "../sdk_rtc.h"

void GF_STANDARD_Init(u32 heapId);
s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
u32 GF_STANDARD_GetStringLength(const u8 *s);
int GF_STANDARD_CompareString(const char *s1, const char *s2);
void GF_STANDARD_RandSeed(u32 seed);
u32 GF_STANDARD_Rand(void);
u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);
void GF_STANDARD_SeedLcg64(struct Lcg64 *out);
u32 GF_STANDARD_Checksum(const u8 *p, u32 len);
void GF_STANDARD_XorCrypt(u16 *p, u32 size, u32 seed);
void GF_STANDARD_XorCryptEx(void *p, unsigned int size, unsigned int seed);
u16 GF_STANDARD_RandLcg(u32 *seed);
void GF_STANDARD_InitRtc(void);
void GF_STANDARD_UpdateRtc(void);
void GF_STANDARD_RtcReadDone(int result, void *arg);
void GF_STANDARD_RequestRtc(struct RtcRequest *req);
void GF_STANDARD_CopyCachedRtc(RTCDate *date, RTCTime *time);
void GF_STANDARD_GetCachedTime(RTCTime *time);
void GF_STANDARD_GetCachedDate(RTCDate *date);
u32 GF_STANDARD_GetSecondsOfDay(void);
s64 GF_STANDARD_GetRtcTimestamp(void);
s32 GF_STANDARD_GetDayOfYear(struct RtcDateSigned *d);
int GF_STANDARD_SinFromDegrees(u32 x);
short GF_STANDARD_CosFromDegrees(u32 x);
short GF_STANDARD_SinFromDegreesWrapped(unsigned short x);
short GF_STANDARD_CosFromDegreesWrapped(s32 x);
u16 GF_STANDARD_DegToAngle(int x);
int GF_STANDARD_CalcAngle(int ax, int ay, int bx, int by, int cx, int cy, int radius);
s32 GF_STANDARD_SignedDistanceToLine(s32 ax, s32 ay, s32 bx, s32 by, s32 cx, s32 cy);
/* END mkheaders: generated region */

#endif
