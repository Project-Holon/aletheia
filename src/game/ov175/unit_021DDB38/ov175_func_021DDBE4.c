/*
 * function: func_021DDBE4
 * address:  0x021DDBE4
 * packet:   pkt_ov175_021DDBE4
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeiFillSoapRequestFieldValues (sakerequestmodif)
 *
 * symbols:
 *   g_021E3A8C  0x021E3A8C  data
 *   g_021E3A90  0x021E3A90  data
 *   g_021E3A98  0x021E3A98  data
 *   g_021E3AA4  0x021E3AA4  data
 *   g_021E3AAC  0x021E3AAC  data
 *   g_021E3AB4  0x021E3AB4  data
 *   g_021E3AC0  0x021E3AC0  data
 *   g_021E3ACC  0x021E3ACC  data
 *   g_021E3AD8  0x021E3AD8  data
 *   g_021E3AE4  0x021E3AE4  data
 *   g_021E3AF0  0x021E3AF0  data
 *   g_021E3B04  0x021E3B04  data
 *   g_021E3B18  0x021E3B18  data
 *   g_021E3B28  0x021E3B28  data
 *   g_021E3B3C  0x021E3B3C  data
 *   func_021829AC  0x021829AC  arm  ov009
 *   func_02182AC0  0x02182AC0  arm  ov009
 *   func_02182CF0  0x02182CF0  arm  ov009
 *   func_02182D78  0x02182D78  arm  ov009
 *   func_02182DFC  0x02182DFC  arm  ov009
 *   func_02182C10  0x02182C10  arm  ov009
 *   func_02182FF8  0x02182FF8  arm  ov009
 *   func_02182F40  0x02182F40  arm  ov009
 *   func_02182A2C  0x02182A2C  arm  ov009
 */

typedef struct SAKEBinaryData {
    unsigned char *mValue;
    int mLength;
} SAKEBinaryData;

typedef union SAKEValue {
    unsigned char mByte;
    short mShort;
    int mInt;
    long long mInt64;
    float mFloat;
    char *mAsciiString;
    unsigned short *mUnicodeString;
    int mBoolean;
    long mDateAndTime;
    SAKEBinaryData mBinaryData;
} SAKEValue;

typedef struct SAKEField {
    char *mName;
    int mType;
    SAKEValue mValue;
} SAKEField;

typedef struct SAKERequestInternal {
    void *mSake;
    int mType;
    void *mInput;
    void *mOutput;
    void *mCallback;
    void *mUserData;
    void *mSoapRequest;
    void *mSoapResponse;
    void *mInfo;
} SAKERequestInternal;

extern char g_021E3A8C[];
extern char g_021E3A90[];
extern char g_021E3A98[];
extern char g_021E3AA4[];
extern char g_021E3AAC[];
extern char g_021E3AB4[];
extern char g_021E3AC0[];
extern char g_021E3ACC[];
extern char g_021E3AD8[];
extern char g_021E3AE4[];
extern char g_021E3AF0[];
extern char g_021E3B04[];
extern char g_021E3B18[];
extern char g_021E3B28[];
extern char g_021E3B3C[];

extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182D78(void *stream, char *namespaceName, char *tag, long long value);
extern int func_02182DFC(void *stream, char *namespaceName, char *tag, float value);
extern int func_02182C10(void *stream, char *namespaceName, char *tag, unsigned short *value);
extern int func_02182FF8(void *stream, char *namespaceName, char *tag, long value);
extern int func_02182F40(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);

void func_021DDBE4(SAKERequestInternal *request, SAKEField *fields, int numFields)
{
    int i;

    func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3A90);
    for (i = 0; i < numFields; i++) {
        func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3A98);
        func_02182AC0(request->mSoapRequest, g_021E3A8C, g_021E3AA4, fields[i].mName);
        func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AAC);
        if (fields[i].mType == 0) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AB4);
            func_02182CF0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mByte);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AB4);
        } else if (fields[i].mType == 1) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AC0);
            func_02182CF0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mShort);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AC0);
        } else if (fields[i].mType == 2) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3ACC);
            func_02182CF0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mInt);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3ACC);
        } else if (fields[i].mType == 9) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AD8);
            func_02182D78(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mInt64);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AD8);
        } else if (fields[i].mType == 3) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AE4);
            func_02182DFC(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mFloat);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AE4);
        } else if (fields[i].mType == 4) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3AF0);
            func_02182AC0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mAsciiString);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AF0);
        } else if (fields[i].mType == 5) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3B04);
            func_02182C10(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mUnicodeString);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3B04);
        } else if (fields[i].mType == 6) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3B18);
            func_02182CF0(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mBoolean ? 1 : 0);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3B18);
        } else if (fields[i].mType == 7) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3B28);
            func_02182FF8(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mDateAndTime);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3B28);
        } else if (fields[i].mType == 8) {
            func_021829AC(request->mSoapRequest, g_021E3A8C, g_021E3B3C);
            func_02182F40(request->mSoapRequest, g_021E3A8C, g_021E3AAC, fields[i].mValue.mBinaryData.mValue, fields[i].mValue.mBinaryData.mLength);
            func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3B3C);
        }
        func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3AAC);
        func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3A98);
    }
    func_02182A2C(request->mSoapRequest, g_021E3A8C, g_021E3A90);
}
