/*
 * file:     gsplatformutil.c
 * unit:     yes
 * function: gsiInt64ToString, gsiStartResolvingHostname, gsiCancelResolvingHostname, gsiGetResolvedIP, goastrdup, _strlwr, SocketStartUp, SocketShutDown, current_time, current_time_hires, msleep, gsiSecondsToDate, gsiDateToSeconds, nextlongrand, longrand, Util_RandSeed, Util_RandInt, QuartToTrip, TripToQuart, B64Decode, B64Encode, B64DecodeLen, B64InitEncodeStream, B64EncodeStream
 * address:  0x0217F130
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 * Initialises a base64 encode stream: stores input pointer, input length
 * and the current position (home: gsplatformutil.o, just before B64EncodeStream).
 * sdk:      B64EncodeStream (libdwcgscommon.TWL.HYB.a(gsplatformutil.o))
 *
 * symbols:
 *   OS_SPrintf                  0x02084F40  arm
 *   gGsInt64Format                     0x021A3834  data
 *   gsDebugFormat                  0x0217D254  arm ov009
 *   SOC_GetHostByName                  0x0215F650  arm ov009
 *   gGsResolveDebugFmt                     0x021A383C  data
 *   gsifree  0x0217EAE0  arm  ov009
 *   strlen     0x0209477C  arm
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   memcpy     0x02092344  arm
 *   __tolower_map     0x020A60DC  data
 *   OS_GetTick     0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   OS_Sleep 0x02085A38 arm
 *   gGsTimeBuffer                     0x021AD164  data
 *   gGsMonthDaysLeap                     0x021A37CC  data
 *   gGsMonthDays                     0x021A3800  data
 *   _s32_div_f                     0x0209C0A4  arm
 *   gGsRandState  0x021A37C8  data
 *   _u32_div_f     0x0209C2B0  arm
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   gGsB64CharsDefault     0x021A19FC  data
 *   gGsB64CharsUrl     0x021A19FF  data
 *   gGsB64CharsAlt     0x021A1A02  data
 */
#define ChkAdd(dest, src1, src2) (((src1 >= 0L) && (src2 >= 0L) && (dest < 0L)) || ((src1 < 0L) && (src2 < 0L) && (dest >= 0L)))
#define ChkMul(dest, src1, src2) (src1 ? (dest / src1 != src2) : 0)
#define RANa         16807
#define LONGRAND_MAX 2147483647L
#define GSI_MIN(a, b) ((a) < (b) ? (a) : (b))
struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};

struct GSIResolveHostnameInfo {
    void *reserved0;
    unsigned long ip;
};

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

typedef unsigned char u8;

typedef unsigned int   u32;

typedef struct {
    char *data;
    int len;
    int mode;
} B64StreamData;

extern int OS_SPrintf(char *dst, char *fmt, ...);
extern void gsDebugFormat(int cat, int type, int level, char *fmt, ...);
extern struct SOCHostEnt *SOC_GetHostByName(char *name);
extern void gsifree(void *p);
extern int strlen(char *s);
extern void *gsimalloc(unsigned long size);
extern void *memcpy(void *dst, void *src, unsigned long n);
extern unsigned long long OS_GetTick(void);
extern unsigned long long _ll_udiv(unsigned long long a, unsigned long long b);
extern void OS_Sleep(unsigned int msec);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);
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
void B64InitEncodeStream(int *stream, int input, int inputLength, int position);
int B64EncodeStream(B64StreamData *data, char *output);
extern char gGsInt64Format[];
extern char gGsResolveDebugFmt[];
extern unsigned char __tolower_map[];
extern struct tm gGsTimeBuffer;
extern int gGsMonthDaysLeap[];
extern int gGsMonthDays[];
extern char gGsRandState[];
extern char gGsB64CharsDefault[];
extern char gGsB64CharsUrl[];
extern char gGsB64CharsAlt[];




/*
 * sdk:      gsiInt64ToString (gsplatformutil.o)
 */
void gsiInt64ToString(char *theNumberStr, long long theNumber)
{
    OS_SPrintf(theNumberStr, gGsInt64Format, theNumber);
}




/*
 * sdk:      gsiStartResolvingHostname (gsplatformutil.o)
 */
int gsiStartResolvingHostname(char *hostname, struct GSIResolveHostnameInfo **handle)
{
    struct GSIResolveHostnameInfo *info;
    struct SOCHostEnt *SOCHostEnt;

    gsDebugFormat((int)8, (int)3, 16, gGsResolveDebugFmt);
    SOCHostEnt = SOC_GetHostByName(hostname);
    if (SOCHostEnt == 0)
        return -1;
    info = (struct GSIResolveHostnameInfo *)gsimalloc(8);
    if (info == 0)
        return -1;
    info->ip = *(unsigned long *)SOCHostEnt->addrList[0];
    *handle = info;
    return 0;
}



void gsiCancelResolvingHostname(void *p)
{
    gsifree(p);
}




/*
 * Saves the word at +4, calls the helper and returns it.
 */
int gsiGetResolvedIP(int *p)
{
    int v = p[1];

    gsifree(p);

    return v;
}




char *goastrdup(char *src)
{
    unsigned long len;
    char *res;

    if (src == 0)
        return 0;
    len = strlen(src);
    res = (char *)gsimalloc(len + 1);
    if (res != 0)
        memcpy(res, src, len + 1);

    return res;
}




/*
 * In-place character remap: for every byte of the NUL-terminated string at
 * s that is a non-negative value below 0x80, replace it with the byte at
 * the same index in the 128-entry table at 0x020A60DC; leave negative and
 * high bytes alone.  Returns s.
 */
char *_strlwr(char *s)
{
    char *ret = s;
    int c = *s;

    if (c != 0) {
        do {
            if (c >= 0 && c < 0x80) {
                c = __tolower_map[c];
            }
            *s = c;
            c = *++s;
        } while (c != 0);
    }
    return ret;
}


/*
 * Empty stub; nothing but a return.
 */
void SocketStartUp(void)
{
}


void SocketShutDown(void)
{
}



/*
 * current_time: GameSpy's millisecond clock.  The 64-bit tick from
 * OS_GetTick is scaled by 64 then divided by 33514 (0x82EA); the quotient's
 * low word is the result.  The scale/divide is the inlined u64 arithmetic
 * that mwcc turns into the _ll_udiv runtime call.
 */
unsigned int current_time(void)
{
    unsigned long long t = OS_GetTick();

    return (unsigned int)((t << 6) / 33514);
}



unsigned int current_time_hires(void)
{
    return (unsigned int)((OS_GetTick() * 0xfa00ULL) / 0x82eaULL);
}


void msleep(unsigned int msec)
{
    OS_Sleep(msec);
}




/*
 * The whole-day count is read into its own long before tm_mon is stored
 * (permuter lead): computing it inline in the tm_wday statement colours
 * ptb into r3 instead of lr.
 */
/*
 * sdk:      gsiSecondsToDate (gsplatformutil.o)
 */
struct tm *gsiSecondsToDate(long *timp)
{
    long caltim = *timp;
    long alldays;
    int islpyr = 0;
    int tmptim;
    int *mdays;
    struct tm *ptb = &gGsTimeBuffer;

    if (caltim < 0)
        return 0;

    tmptim = (int)(caltim / (1461L * 86400L));
    caltim -= (long)tmptim * (1461L * 86400L);
    tmptim = (tmptim * 4) + 70;

    if (caltim >= 365L * 86400L) {
        tmptim++;
        caltim -= 365L * 86400L;
        if (caltim >= 365L * 86400L) {
            tmptim++;
            caltim -= 365L * 86400L;
            if (caltim >= 366L * 86400L) {
                tmptim++;
                caltim -= 366L * 86400L;
            } else {
                islpyr++;
            }
        }
    }

    ptb->tm_year = tmptim;
    ptb->tm_yday = (int)(caltim / 86400L);
    caltim -= (long)ptb->tm_yday * 86400L;

    if (islpyr)
        mdays = gGsMonthDaysLeap;
    else
        mdays = gGsMonthDays;

    for (tmptim = 1; mdays[tmptim] < ptb->tm_yday; tmptim++)
        ;

    alldays = *timp / 86400L;
    ptb->tm_mon = --tmptim;
    ptb->tm_mday = ptb->tm_yday - mdays[tmptim];
    ptb->tm_wday = ((int)alldays + 4) % 7;
    ptb->tm_hour = (int)(caltim / 3600);
    caltim -= (long)ptb->tm_hour * 3600L;
    ptb->tm_min = (int)(caltim / 60);
    ptb->tm_sec = (int)(caltim - ptb->tm_min * 60);
    ptb->tm_isdst = 0;
    return ptb;
}




/*
 * sdk:      gsiDateToSeconds (gsplatformutil.o)
 */
long gsiDateToSeconds(struct tm *tb)
{
    long tmptm1;
    long tmptm2;
    long tmptm3;

    if (((tmptm1 = tb->tm_year) < 69) || (tmptm1 > 139))
        return -1;

    if ((tb->tm_mon < 0) || (tb->tm_mon > 11)) {
        tmptm1 += (tb->tm_mon / 12);
        if ((tb->tm_mon %= 12) < 0) {
            tb->tm_mon += 12;
            tmptm1--;
        }
        if ((tmptm1 < 69) || (tmptm1 > 139))
            return -1;
    }

    tmptm2 = gGsMonthDays[tb->tm_mon];
    if (!(tmptm1 & 3) && (tb->tm_mon > 1))
        tmptm2++;

    tmptm3 = (tmptm1 - 70) * 365L + ((tmptm1 - 1L) >> 2) - 17;
    tmptm3 += tmptm2;
    tmptm1 = tmptm3 + (tmptm2 = (long)(tb->tm_mday));
    if (ChkAdd(tmptm1, tmptm3, tmptm2))
        return -1;

    tmptm2 = tmptm1 * 24L;
    if (ChkMul(tmptm2, tmptm1, 24L))
        return -1;
    tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_hour);
    if (ChkAdd(tmptm1, tmptm2, tmptm3))
        return -1;

    tmptm2 = tmptm1 * 60L;
    if (ChkMul(tmptm2, tmptm1, 60L))
        return -1;
    tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_min);
    if (ChkAdd(tmptm1, tmptm2, tmptm3))
        return -1;

    tmptm2 = tmptm1 * 60L;
    if (ChkMul(tmptm2, tmptm1, 60L))
        return -1;
    tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_sec);
    if (ChkAdd(tmptm1, tmptm2, tmptm3))
        return -1;

    {
        struct tm *tbtemp;
        if ((tbtemp = gsiSecondsToDate(&tmptm1)) == 0)
            return -1;
        *tb = *tbtemp;
    }
    return tmptm1;
}




/*
 * nextlongrand: one step of the GameSpy Park-Miller LCG (multiplier 16807,
 * modulus 2**31-1), written in 16-bit halves so the product fits a 32-bit
 * register.  The two `if (lo > LONGRAND_MAX)` folds are the compiler's
 * `(x & 0x7fffffff) + (x >> 31)` reduction, emitted as cmn/bic/addhi.
 *
 * Reached from longrand (0x0217F774) <- Util_RandInt (0x0217F7AC) <-
 * gpiEncodeString.
 */
int nextlongrand(long seed)
{
    unsigned long lo, hi;

    lo = RANa * (unsigned long)(seed & 0xFFFF);
    hi = RANa * ((unsigned long)seed >> 16);
    lo += (hi & 0x7FFF) << 16;
    if (lo > LONGRAND_MAX) {
        lo &= LONGRAND_MAX;
        ++lo;
    }
    lo += hi >> 15;
    if (lo > LONGRAND_MAX) {
        lo &= LONGRAND_MAX;
        ++lo;
    }
    return (int)lo;
}




/*
 * Advances the generator state and returns the new value.
 */
/*
 * Refreshes the word the state object holds.
 */
int longrand(void)
{
    int next = nextlongrand(*(int *)gGsRandState);
    *(int *)gGsRandState = next;
    return next;
}




/*
 * probe
 */
void Util_RandSeed(unsigned int v)
{
    *(int *)gGsRandState = v ? (int)(v & 0x7fffffff) : 1;
}




/*
 * Util_RandInt: longrand() modulo (max-min), offset by min.  max==min returns
 * min without touching the RNG.
 *
 * The `% range` result is bound to a local before adding min: that is what
 * makes the compiler keep min in a callee-saved register and emit the direct
 * `add r0, r1, r5` return instead of a branch plus `mov r0, r5` (and it drops
 * the four-byte conditional-pop epilogue).  The modulo is unsigned (u32),
 * so it calls the runtime division entry at 0x0209C2B0.
 */
unsigned int Util_RandInt(unsigned int min, unsigned int max)
{
    unsigned int range = max - min;
    unsigned int r;

    if (range == 0)
        return min;
    r = longrand() % range;
    return r + min;
}



/*
 * QuartToTrip: pack up to four signed bytes into three (6-6-6-6 base64
 * bit groups folded into 6-6-2+6 layout).  `char` is signed under the pinned
 * flags, so the loads are ldrsb and the shifts arithmetic.
 */
void QuartToTrip(char *quart, char *trip, int inlen)
{
    if (inlen >= 2)
        trip[0] = (char)(quart[0] << 2 | quart[1] >> 4);
    if (inlen >= 3)
        trip[1] = (char)((quart[1] & 0x0F) << 4 | quart[2] >> 2);
    if (inlen >= 4)
        trip[2] = (char)((quart[2] & 0x3) << 6 | quart[3]);
}




/*
 * Pack up to three input bytes into four 6-bit values (the base64 index
 * order).  The source bytes go through a local three-byte buffer, padded
 * with zeros before the shift network runs.
 */
void TripToQuart(const char *src, u8 *dst, int n)
{
    unsigned char buf[4];
    int i;

    for (i = 0; i < n; i++)
        buf[i] = src[i];
    for (; i < 3; i++)
        buf[i] = 0;
    dst[0] = buf[0] >> 2;
    dst[1] = ((buf[0] & 3) << 4) | (buf[1] >> 4);
    dst[2] = ((buf[1] & 0xf) << 2) | (buf[2] >> 6);
    dst[3] = buf[2] & 0x3f;
}




/*
 * B64Decode: GameSpy base64 decoder.  Decode characters into 4-byte groups,
 * run QuartToTrip over each full group, pad and convert the tail, and publish
 * the output length.  encodingType 1 selects the alternate table, 2 the
 * URL-safe table, otherwise the default.
 */
void B64Decode(const char *input, char *output, int inlen, int *outlen, int encodingType)
{
    const char *encoding;
    int readpos = 0;
    int writepos = 0;
    char block[4];

    switch (encodingType) {
    case 1:
        encoding = gGsB64CharsAlt;
        break;
    case 2:
        encoding = gGsB64CharsUrl;
        break;
    default:
        encoding = gGsB64CharsDefault;
    }

    if (inlen <= 0) {
        if (outlen)
            *outlen = 0;
        output[0] = 0;
        return;
    }

    while (readpos < inlen && input[readpos] != encoding[2]) {
        if (input[readpos] >= '0' && input[readpos] <= '9')
            block[readpos % 4] = (char)(input[readpos] - 48 + 52);
        else if (input[readpos] >= 'a' && input[readpos] <= 'z')
            block[readpos % 4] = (char)(input[readpos] - 71);
        else if (input[readpos] >= 'A' && input[readpos] <= 'Z')
            block[readpos % 4] = (char)(input[readpos] - 65);
        else if (input[readpos] == encoding[0])
            block[readpos % 4] = 62;
        else if (input[readpos] == encoding[1])
            block[readpos % 4] = 63;
        else if (input[readpos] == encoding[2])
            break;
        else if (input[readpos] == '\0')
            break;
        else {
            if (outlen)
                *outlen = 0;
            output[0] = 0;
            return;
        }

        if (readpos % 4 == 3) {
            QuartToTrip(block, &output[writepos], 4);
            writepos += 3;
        }
        readpos++;
    }

    if (readpos != 0 && readpos % 4 != 0) {
        MSL_C_LIB_MemsetPtr(&block[readpos % 4], encoding[2], 4 - readpos % 4);
        QuartToTrip(block, &output[writepos], readpos % 4);
        if (readpos % 4 == 3)
            writepos += 2;
        else
            writepos += 1;
    }

    if (outlen)
        *outlen = writepos;
}




/*
 * B64Encode: GameSpy base64 encoder.  TripToQuart every 3 input bytes, then
 * walk the output backwards mapping each 6-bit group to its character,
 * padding the tail with encoding[2].  encodingType 1 selects the alternate
 * table, 2 the URL-safe table, otherwise the default.
 */
void B64Encode(const char *input, char *output, int inlen, int encodingType)
{
    const char *encoding;
    char *holdout = output;
    char *lastchar;
    int todo = inlen;

    switch (encodingType) {
    case 1:
        encoding = gGsB64CharsAlt;
        break;
    case 2:
        encoding = gGsB64CharsUrl;
        break;
    default:
        encoding = gGsB64CharsDefault;
    }

    while (todo > 0) {
        TripToQuart(input, (u8 *)output, GSI_MIN(todo, 3));
        output += 4;
        input += 3;
        todo -= 3;
    }
    lastchar = output;
    if (inlen % 3 == 1)
        lastchar -= 2;
    else if (inlen % 3 == 2)
        lastchar -= 1;
    *output = 0;
    while (output > holdout) {
        output--;
        if (output >= lastchar)
            *output = encoding[2];
        else if (*output <= 25)
            *output = (char)(*output + 65);
        else if (*output <= 51)
            *output = (char)(*output + 71);
        else if (*output <= 61)
            *output = (char)(*output + 48 - 52);
        else if (*output == 62)
            *output = encoding[0];
        else if (*output == 63)
            *output = encoding[1];
    }
}




/*
 * sdk:      B64DecodeLen (gsplatformutil.o)
 */
int B64DecodeLen(char *input, int encodingType)
{
    char *encoding;
    char *holdin = input;
    int len;

    switch (encodingType) {
    case 1:
        encoding = gGsB64CharsAlt;
        break;
    case 2:
        encoding = gGsB64CharsUrl;
        break;
    default:
        encoding = gGsB64CharsDefault;
        break;
    }
    while (*input != 0) {
        if (*input == encoding[2]) {
            len = input - holdin;
            return (len / 4) * 3 + (len - 1) % 4;
        }
        input++;
    }
    len = input - holdin;
    return (len / 4) * 3;
}

void B64InitEncodeStream(int *stream, int input, int inputLength, int position)
{
    stream[0] = input;
    stream[1] = inputLength;
    stream[2] = position;
}


int B64EncodeStream(B64StreamData *data, char *output)
{
    int i;
    char *encoding;
    char c;

    if (data->len <= 0)
        return 0;

    switch (data->mode) {
    case 1:
        encoding = gGsB64CharsAlt;
        break;
    case 2:
        encoding = gGsB64CharsUrl;
        break;
    default:
        encoding = gGsB64CharsDefault;
        break;
    }

    TripToQuart(data->data, (u8 *)output, data->len >= 3 ? 3 : data->len);
    data->data += 3;
    data->len -= 3;

    for (i = 0; i < 4; i++) {
        c = output[i];
        if (c <= 25)
            output[i] = c + 'A';
        else if (c <= 51)
            output[i] = c + 'G';
        else if (c <= 61)
            output[i] = c - 4;
        else if (c == 62)
            output[i] = encoding[0];
        else if (c == 63)
            output[i] = encoding[1];
    }
    if (data->len < 0) {
        output[3] = encoding[2];
        if (data->len == -2)
            output[2] = encoding[2];
    }
    return 1;
}
