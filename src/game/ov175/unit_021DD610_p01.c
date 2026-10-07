/*
 * file:     unit_021DD610_p01.c
 * unit:     yes
 * function: func_021DD610, func_021DD64C, func_021DD84C
 * address:  0x021DD610
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020948E0  0x020948E0  arm
 *   d_021E3730     0x021E3730  data
 *   d_021E3738     0x021E3738  data
 *   d_021E374C     0x021E374C  data
 *   d_021E375C     0x021E375C  data
 *   d_021E3770     0x021E3770  data
 *   d_021E3784     0x021E3784  data
 *   d_021E3798     0x021E3798  data
 *   d_021E37A8     0x021E37A8  data
 *   d_021E37B8     0x021E37B8  data
 *   d_021E37C8     0x021E37C8  data
 *   d_021E37DC     0x021E37DC  data
 *   d_021E37EC     0x021E37EC  data
 *   d_021E3800     0x021E3800  data
 *   d_021E3810     0x021E3810  data
 *   d_021E381C     0x021E381C  data
 *   d_021E3828     0x021E3828  data
 *   d_021E3838     0x021E3838  data
 *   d_021E3844     0x021E3844  data
 *   func_021834D0  0x021834D0  arm  ov009
 *   func_021834E8  0x021834E8  arm  ov009
 *   func_0218372C  0x0218372C  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021DD604  0x021DD604  arm  ov175
 */
struct SAKERequestInternal;
typedef int s32_021DD610;

typedef int s32_021DD64C;

typedef struct {
    int mOutputSize;
    int pad4;
    int pad8;
    char *mSoapResponseTag;
    char *mResultTag;
    int pad14;
    int pad18;
    int (*mParseFunc)(struct SAKERequestInternal *);
    void (*mFreeFunc)(struct SAKERequestInternal *);
} SAKEIRequestInfo;

typedef struct SAKERequestInternal {
    void *mSake;
    int mType;
    void *mInput;
    void *mOutput;
    void (*mCallback)(void *, struct SAKERequestInternal *, int, void *, void *, void *);
    void *mUserData;
    void *mSoapRequest;
    void *mSoapResponse;
    SAKEIRequestInfo *mInfo;
} SAKERequestInternal;

typedef signed int     s32_021DD84C;

extern s32_021DD64C func_020948E0(const char *a, const char *b);
extern int func_021834D0(int *p);
extern int func_021834E8(void *stream, char *matchtag);
extern int func_0218372C(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void *func_0217EAB0(unsigned long size);
extern void func_0217EAE0(void *ptr);
extern void func_021DD604(void *request);
s32_021DD610 func_021DD610(s32_021DD610 a);
s32_021DD64C func_021DD64C(const char *p);
void func_021DD84C(int httpResult, int unused, void *responseData, void *userData);
extern char d_021E3730[];
extern char d_021E3738[];
extern char d_021E374C[];
extern char d_021E375C[];
extern char d_021E3770[];
extern char d_021E3784[];
extern char d_021E3798[];
extern char d_021E37A8[];
extern char d_021E37B8[];
extern char d_021E37C8[];
extern char d_021E37DC[];
extern char d_021E37EC[];
extern char d_021E3800[];
extern char d_021E3810[];
extern char d_021E381C[];
extern char d_021E3828[];
extern char d_021E3838[];
extern char d_021E3844[];


/*
 * Category selector: 0 -> 0, 1 -> 6, 0x12 -> 0x17, anything else -> 4.
 */
s32_021DD610 func_021DD610(s32_021DD610 a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        return 6;
    case 0x12:
        return 0x17;
    default:
        return 4;
    }
}


/*
 * Nintendo WFC / Wi-Fi connection error-name to index table: a plain
 * strcmp-style probe (func_020948E0) against each known status string,
 * returning the string's index.  Seven indices (6 in the 9..0x14 range)
 * are skipped because they are not reachable from this pool; the caller
 * reads the dedicated return value from those.
 */
s32_021DD64C func_021DD64C(const char *p)
{
    if (func_020948E0(p, d_021E3730) == 0)
        return 0;
    if (func_020948E0(p, d_021E3738) == 0)
        return 1;
    if (func_020948E0(p, d_021E374C) == 0)
        return 2;
    if (func_020948E0(p, d_021E375C) == 0)
        return 7;
    if (func_020948E0(p, d_021E3770) == 0)
        return 8;
    if (func_020948E0(p, d_021E3784) == 0)
        return 9;
    if (func_020948E0(p, d_021E3798) == 0)
        return 0xa;
    if (func_020948E0(p, d_021E37A8) == 0)
        return 0xb;
    if (func_020948E0(p, d_021E37B8) == 0)
        return 0xc;
    if (func_020948E0(p, d_021E37C8) == 0)
        return 0xd;
    if (func_020948E0(p, d_021E37DC) == 0)
        return 0xe;
    if (func_020948E0(p, d_021E37EC) == 0)
        return 0xf;
    if (func_020948E0(p, d_021E3800) == 0)
        return 0x10;
    if (func_020948E0(p, d_021E3810) == 0)
        return 0x11;
    if (func_020948E0(p, d_021E381C) == 0)
        return 0x12;
    if (func_020948E0(p, d_021E3828) == 0)
        return 0x13;
    if (func_020948E0(p, d_021E3838) == 0)
        return 0x14;
    return func_020948E0(p, d_021E3844) == 0 ? 0x15 : 0x16;
}


/*
 * sdk:      sakeiSoapCallback (libdwcgssake.TWL.HYB.a sakerequest.o)
 */
void func_021DD84C(int httpResult, int unused, void *responseData, void *userData)
{
    SAKERequestInternal *request;
    void *output;
    int result;
    char resultString[32];

    request = (SAKERequestInternal *)userData;
    output = 0;
    if (!request || !request->mSake || !request->mInfo)
        return;
    result = func_021DD610(httpResult);
    if (result == 0) {
        if (!func_021834D0(responseData) || !func_021834E8(responseData, request->mInfo->mSoapResponseTag) ||
            !func_0218372C(responseData, request->mInfo->mResultTag, resultString, 32)) {
            result = 5;
        } else {
            result = func_021DD64C(resultString);
            if (result == 0 && request->mInfo->mOutputSize) {
                request->mOutput = func_0217EAB0(request->mInfo->mOutputSize);
                if (request->mOutput) {
                    request->mSoapResponse = responseData;
                    result = request->mInfo->mParseFunc(request);
                    if (result == 0)
                        output = request->mOutput;
                } else {
                    result = 6;
                }
            }
        }
    }
    if (request->mCallback)
        request->mCallback(request->mSake, request, result, request->mInput, output, request->mUserData);
    if (request->mInfo->mFreeFunc)
        request->mInfo->mFreeFunc(request);
    func_0217EAE0(request->mOutput);
    request->mOutput = 0;
    func_021DD604(request);
}
