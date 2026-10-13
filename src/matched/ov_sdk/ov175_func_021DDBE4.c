/*
 * function: sakeiFillSoapRequestFieldValues
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
 *   sModifyXmlNamespacePrefix  0x021E3A8C  data
 *   sModifyTagValues  0x021E3A90  data
 *   sModifyTagRecordField  0x021E3A98  data
 *   sModifyTagName  0x021E3AA4  data
 *   sModifyTagValue  0x021E3AAC  data
 *   sModifyTagByteValue  0x021E3AB4  data
 *   sModifyTagShortValue  0x021E3AC0  data
 *   sModifyTagIntValue  0x021E3ACC  data
 *   sModifyTagInt64Value  0x021E3AD8  data
 *   sModifyTagFloatValue  0x021E3AE4  data
 *   sModifyTagAsciiStringValue  0x021E3AF0  data
 *   sModifyTagUnicodeStringValue  0x021E3B04  data
 *   sModifyTagBooleanValue  0x021E3B18  data
 *   sModifyTagDateAndTimeValue  0x021E3B28  data
 *   sModifyTagBinaryDataValue  0x021E3B3C  data
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

extern char sModifyXmlNamespacePrefix[];
extern char sModifyTagValues[];
extern char sModifyTagRecordField[];
extern char sModifyTagName[];
extern char sModifyTagValue[];
extern char sModifyTagByteValue[];
extern char sModifyTagShortValue[];
extern char sModifyTagIntValue[];
extern char sModifyTagInt64Value[];
extern char sModifyTagFloatValue[];
extern char sModifyTagAsciiStringValue[];
extern char sModifyTagUnicodeStringValue[];
extern char sModifyTagBooleanValue[];
extern char sModifyTagDateAndTimeValue[];
extern char sModifyTagBinaryDataValue[];

extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182D78(void *stream, char *namespaceName, char *tag, long long value);
extern int func_02182DFC(void *stream, char *namespaceName, char *tag, float value);
extern int func_02182C10(void *stream, char *namespaceName, char *tag, unsigned short *value);
extern int func_02182FF8(void *stream, char *namespaceName, char *tag, long value);
extern int func_02182F40(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);

void sakeiFillSoapRequestFieldValues(SAKERequestInternal *request, SAKEField *fields, int numFields)
{
    int i;

    func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValues);
    for (i = 0; i < numFields; i++) {
        func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagRecordField);
        func_02182AC0(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagName, fields[i].mName);
        func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue);
        if (fields[i].mType == 0) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagByteValue);
            func_02182CF0(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mByte);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagByteValue);
        } else if (fields[i].mType == 1) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagShortValue);
            func_02182CF0(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mShort);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagShortValue);
        } else if (fields[i].mType == 2) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagIntValue);
            func_02182CF0(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mInt);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagIntValue);
        } else if (fields[i].mType == 9) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagInt64Value);
            func_02182D78(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mInt64);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagInt64Value);
        } else if (fields[i].mType == 3) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagFloatValue);
            func_02182DFC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mFloat);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagFloatValue);
        } else if (fields[i].mType == 4) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagAsciiStringValue);
            func_02182AC0(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mAsciiString);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagAsciiStringValue);
        } else if (fields[i].mType == 5) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagUnicodeStringValue);
            func_02182C10(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mUnicodeString);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagUnicodeStringValue);
        } else if (fields[i].mType == 6) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBooleanValue);
            func_02182CF0(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mBoolean ? 1 : 0);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBooleanValue);
        } else if (fields[i].mType == 7) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagDateAndTimeValue);
            func_02182FF8(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mDateAndTime);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagDateAndTimeValue);
        } else if (fields[i].mType == 8) {
            func_021829AC(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBinaryDataValue);
            func_02182F40(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mBinaryData.mValue, fields[i].mValue.mBinaryData.mLength);
            func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBinaryDataValue);
        }
        func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue);
        func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagRecordField);
    }
    func_02182A2C(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValues);
}
