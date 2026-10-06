/*
 * function: func_021DD84C
 * address:  0x021DD84C
 * packet:   pkt_ov175_021DD84C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeiSoapCallback (libdwcgssake.TWL.HYB.a sakerequest.o)
 *
 * symbols:
 *   func_021DD610  0x021DD610  arm  ov175
 *   func_021834D0  0x021834D0  arm  ov009
 *   func_021834E8  0x021834E8  arm  ov009
 *   func_0218372C  0x0218372C  arm  ov009
 *   func_021DD64C  0x021DD64C  arm  ov175
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021DD604  0x021DD604  arm  ov175
 */

struct SAKERequestInternal;
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

extern int func_021DD610(int httpResult);
typedef signed int     s32;
extern int func_021834D0(int *p);
extern int func_021834E8(void *stream, char *matchtag);
extern int func_0218372C(void *stream, char *matchtag, char *valueOut, int maxLen);
extern s32 func_021DD64C(const char *p);
extern void *func_0217EAB0(unsigned long size);
extern void func_0217EAE0(void *ptr);
extern void func_021DD604(void *request);

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
