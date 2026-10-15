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
 *   gsXmlWriteOpenTag  0x021829AC  arm  ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm  ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm  ov009
 *   gsXmlWriteInt64Element  0x02182D78  arm  ov009
 *   gsXmlWriteFloatElement  0x02182DFC  arm  ov009
 *   gsXmlWriteUnicodeStringElement  0x02182C10  arm  ov009
 *   gsXmlWriteDateTimeElement  0x02182FF8  arm  ov009
 *   gsXmlWriteBase64BinaryElement  0x02182F40  arm  ov009
 *   gsXmlWriteCloseTag  0x02182A2C  arm  ov009
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

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlWriteInt64Element(void *stream, char *namespaceName, char *tag, long long value);
extern int gsXmlWriteFloatElement(void *stream, char *namespaceName, char *tag, float value);
extern int gsXmlWriteUnicodeStringElement(void *stream, char *namespaceName, char *tag, unsigned short *value);
extern int gsXmlWriteDateTimeElement(void *stream, char *namespaceName, char *tag, long value);
extern int gsXmlWriteBase64BinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);

void sakeiFillSoapRequestFieldValues(SAKERequestInternal *request, SAKEField *fields, int numFields)
{
    int i;

    gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValues);
    for (i = 0; i < numFields; i++) {
        gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagRecordField);
        gsXmlWriteStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagName, fields[i].mName);
        gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue);
        if (fields[i].mType == 0) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagByteValue);
            gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mByte);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagByteValue);
        } else if (fields[i].mType == 1) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagShortValue);
            gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mShort);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagShortValue);
        } else if (fields[i].mType == 2) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagIntValue);
            gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mInt);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagIntValue);
        } else if (fields[i].mType == 9) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagInt64Value);
            gsXmlWriteInt64Element(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mInt64);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagInt64Value);
        } else if (fields[i].mType == 3) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagFloatValue);
            gsXmlWriteFloatElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mFloat);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagFloatValue);
        } else if (fields[i].mType == 4) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagAsciiStringValue);
            gsXmlWriteStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mAsciiString);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagAsciiStringValue);
        } else if (fields[i].mType == 5) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagUnicodeStringValue);
            gsXmlWriteUnicodeStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mUnicodeString);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagUnicodeStringValue);
        } else if (fields[i].mType == 6) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBooleanValue);
            gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mBoolean ? 1 : 0);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBooleanValue);
        } else if (fields[i].mType == 7) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagDateAndTimeValue);
            gsXmlWriteDateTimeElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mDateAndTime);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagDateAndTimeValue);
        } else if (fields[i].mType == 8) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBinaryDataValue);
            gsXmlWriteBase64BinaryElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mBinaryData.mValue, fields[i].mValue.mBinaryData.mLength);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBinaryDataValue);
        }
        gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue);
        gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagRecordField);
    }
    gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValues);
}
