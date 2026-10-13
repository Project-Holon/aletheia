/*
 * file:     sakerequestmodify.c
 * unit:     yes
 * function: sakeiValidateRequestFields, sakeiFillSoapRequestFieldValues, sakeiCreateRecordValidateInput, sakeiCreateRecordFillSoapRequest, sakeiCreateRecordProcessSoapResponse, sakeiStartCreateRecordRequest, sakeiUpdateRecordValidateInput, sakeiUpdateRecordFillSoapRequest, sakeiStartUpdateRecordRequest, sakeiDeleteRecordValidateInput, sakeiDeleteRecordFillSoapRequest
 * address:  0x021DDB38
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Sake client (libdwcgssake, object sakerequestmodify.o): the request
 * kinds that write records.  Each kind has a SAKERequestInfo table (in data)
 * naming these callbacks: validate the input, fill the SOAP envelope and, for
 * CreateRecord, read the new record id from the response.
 *
 * symbols:
 *   gsXmlReadChildAsInt  0x02183A24  arm ov009
 *   gsXmlWriteBase64BinaryElement  0x02182F40  arm ov009
 *   gsXmlWriteCloseTag  0x02182A2C  arm ov009
 *   gsXmlWriteDateTimeElement  0x02182FF8  arm ov009
 *   gsXmlWriteFloatElement  0x02182DFC  arm ov009
 *   gsXmlWriteInt64Element  0x02182D78  arm ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm ov009
 *   gsXmlWriteUnicodeStringElement  0x02182C10  arm ov009
 *   sUpdateRecordRequestInfo  0x021E3978  data
 *   sCreateRecordRequestInfo  0x021E39A0  data
 *   sakeiStartRequest  0x021DDB10  arm
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
 *   sModifyTagTableid  0x021E3B4C  data
 *   sModifyTagRecordid  0x021E3B54  data
 */
#include "sake_types.h"

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlWriteInt64Element(void *stream, char *namespaceName, char *tag, long long value);
extern int gsXmlWriteFloatElement(void *stream, char *namespaceName, char *tag, float value);
extern int gsXmlWriteUnicodeStringElement(void *stream, char *namespaceName, char *tag, unsigned short *value);
extern int gsXmlWriteDateTimeElement(void *stream, char *namespaceName, char *tag, long value);
extern int gsXmlWriteBase64BinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern int sakeiStartRequest(SAKERequestInternal *request, SAKERequestInfo *info);
int sakeiValidateRequestFields(SAKEField *fields, int numFields);
void sakeiFillSoapRequestFieldValues(SAKERequestInternal *request, SAKEField *fields, int numFields);
int sakeiCreateRecordValidateInput(SAKERequestInternal *request);
int sakeiCreateRecordFillSoapRequest(SAKERequestInternal *request);
int sakeiCreateRecordProcessSoapResponse(SAKERequestInternal *request);
int sakeiStartCreateRecordRequest(SAKERequestInternal *request);
int sakeiUpdateRecordValidateInput(SAKERequestInternal *request);
int sakeiUpdateRecordFillSoapRequest(SAKERequestInternal *request);
int sakeiStartUpdateRecordRequest(SAKERequestInternal *request);
int sakeiDeleteRecordValidateInput(SAKERequestInternal *request);
int sakeiDeleteRecordFillSoapRequest(SAKERequestInternal *request);
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
extern char sModifyTagTableid[];
extern char sModifyTagRecordid[];
extern SAKERequestInfo sCreateRecordRequestInfo;
extern SAKERequestInfo sUpdateRecordRequestInfo;

/*
 * Checks a field array: every field needs a name and a known type, string
 * values need a pointer and binary data a non-negative length (and a pointer
 * unless it is empty).  Returns a SAKEStartRequestResult.
 */
int sakeiValidateRequestFields(SAKEField *fields, int numFields)
{
    int i;

    for (i = 0; i < numFields; i++) {
        if (fields[i].mName == 0 || *fields[i].mName == 0)
            return SAKEStartRequestResult_BAD_FIELD_NAME;
        if (fields[i].mType >= 10)
            return SAKEStartRequestResult_BAD_FIELD_TYPE;
        if (fields[i].mType == SAKEFieldType_ASCII_STRING && fields[i].mValue.mAsciiString == 0)
            return SAKEStartRequestResult_BAD_FIELD_VALUE;
        if (fields[i].mType == SAKEFieldType_UNICODE_STRING && fields[i].mValue.mUnicodeString == 0)
            return SAKEStartRequestResult_BAD_FIELD_VALUE;
        if (fields[i].mType == SAKEFieldType_BINARY_DATA) {
            if (fields[i].mValue.mBinaryData.mLength < 0)
                return SAKEStartRequestResult_BAD_FIELD_VALUE;
            if (fields[i].mValue.mBinaryData.mValue == 0 && fields[i].mValue.mBinaryData.mLength > 0)
                return SAKEStartRequestResult_BAD_FIELD_VALUE;
        }
    }
    return SAKEStartRequestResult_SUCCESS;
}

/* Writes the <values> list: one <RecordField> with name and typed value per field. */
void sakeiFillSoapRequestFieldValues(SAKERequestInternal *request, SAKEField *fields, int numFields)
{
    int i;

    gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValues);
    for (i = 0; i < numFields; i++) {
        gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagRecordField);
        gsXmlWriteStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagName, fields[i].mName);
        gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue);
        if (fields[i].mType == SAKEFieldType_BYTE) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagByteValue);
            gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mByte);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagByteValue);
        } else if (fields[i].mType == SAKEFieldType_SHORT) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagShortValue);
            gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mShort);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagShortValue);
        } else if (fields[i].mType == SAKEFieldType_INT) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagIntValue);
            gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mInt);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagIntValue);
        } else if (fields[i].mType == SAKEFieldType_INT64) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagInt64Value);
            gsXmlWriteInt64Element(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mInt64);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagInt64Value);
        } else if (fields[i].mType == SAKEFieldType_FLOAT) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagFloatValue);
            gsXmlWriteFloatElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mFloat);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagFloatValue);
        } else if (fields[i].mType == SAKEFieldType_ASCII_STRING) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagAsciiStringValue);
            gsXmlWriteStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mAsciiString);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagAsciiStringValue);
        } else if (fields[i].mType == SAKEFieldType_UNICODE_STRING) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagUnicodeStringValue);
            gsXmlWriteUnicodeStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mUnicodeString);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagUnicodeStringValue);
        } else if (fields[i].mType == SAKEFieldType_BOOLEAN) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBooleanValue);
            gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mBoolean ? 1 : 0);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBooleanValue);
        } else if (fields[i].mType == SAKEFieldType_DATE_AND_TIME) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagDateAndTimeValue);
            gsXmlWriteDateTimeElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mDateAndTime);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagDateAndTimeValue);
        } else if (fields[i].mType == SAKEFieldType_BINARY_DATA) {
            gsXmlWriteOpenTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBinaryDataValue);
            gsXmlWriteBase64BinaryElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue, fields[i].mValue.mBinaryData.mValue, fields[i].mValue.mBinaryData.mLength);
            gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagBinaryDataValue);
        }
        gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValue);
        gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagRecordField);
    }
    gsXmlWriteCloseTag(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagValues);
}

/* CreateRecord: needs a table id; an empty field list is allowed, a negative count is not. */
int sakeiCreateRecordValidateInput(SAKERequestInternal *request)
{
    SAKECreateRecordInput *input = (SAKECreateRecordInput *)request->mInput;

    if (input->mTableId == 0)
        return SAKEStartRequestResult_BAD_TABLEID;
    if (input->mNumFields < 0)
        return SAKEStartRequestResult_NO_FIELDS;
    if (input->mFields == 0) {
        if (input->mNumFields > 0)
            return SAKEStartRequestResult_BAD_FIELDS;
    }
    return sakeiValidateRequestFields(input->mFields, input->mNumFields);
}

int sakeiCreateRecordFillSoapRequest(SAKERequestInternal *request)
{
    SAKECreateRecordInput *input = (SAKECreateRecordInput *)request->mInput;

    gsXmlWriteStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagTableid, input->mTableId);
    sakeiFillSoapRequestFieldValues(request, input->mFields, input->mNumFields);
    return 0;
}

/* Reads the id of the new record into the output; a missing id is a malformed response. */
int sakeiCreateRecordProcessSoapResponse(SAKERequestInternal *request)
{
    return gsXmlReadChildAsInt(request->mSoapResponse, sModifyTagRecordid, &((SAKECreateRecordOutput *)request->mOutput)->mRecordId) == 0 ? SAKERequestResult_MALFORMED_RESPONSE : 0;
}

int sakeiStartCreateRecordRequest(SAKERequestInternal *request)
{
    return sakeiStartRequest(request, &sCreateRecordRequestInfo);
}

/* UpdateRecord: needs a table id, at least one field and a field array. */
int sakeiUpdateRecordValidateInput(SAKERequestInternal *request)
{
    SAKEUpdateRecordInput *input = (SAKEUpdateRecordInput *)request->mInput;

    if (input->mTableId == 0)
        return SAKEStartRequestResult_BAD_TABLEID;
    if (input->mNumFields <= 0)
        return SAKEStartRequestResult_NO_FIELDS;
    if (input->mFields == 0)
        return SAKEStartRequestResult_BAD_FIELDS;
    return sakeiValidateRequestFields(input->mFields, input->mNumFields);
}

int sakeiUpdateRecordFillSoapRequest(SAKERequestInternal *request)
{
    SAKEUpdateRecordInput *input = (SAKEUpdateRecordInput *)request->mInput;

    gsXmlWriteStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagTableid, input->mTableId);
    gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagRecordid, input->mRecordId);
    sakeiFillSoapRequestFieldValues(request, input->mFields, input->mNumFields);
    return 0;
}

int sakeiStartUpdateRecordRequest(SAKERequestInternal *request)
{
    return sakeiStartRequest(request, &sUpdateRecordRequestInfo);
}

/* DeleteRecord: only the table id is checked. */
int sakeiDeleteRecordValidateInput(SAKERequestInternal *request)
{
    return ((SAKEDeleteRecordInput *)request->mInput)->mTableId != 0 ? 0 : SAKEStartRequestResult_BAD_TABLEID;
}

int sakeiDeleteRecordFillSoapRequest(SAKERequestInternal *request)
{
    SAKEDeleteRecordInput *input = (SAKEDeleteRecordInput *)request->mInput;

    gsXmlWriteStringElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagTableid, input->mTableId);
    gsXmlWriteIntElement(request->mSoapRequest, sModifyXmlNamespacePrefix, sModifyTagRecordid, input->mRecordId);
    return 0;
}
