/*
 * file:     sakerequestread.c
 * unit:     yes
 * function: sakeiValidateRequestFieldNames, sakeiFillSoapRequestFieldNames, sakeiFillSoapRequestRecordIds, sakeiFillSoapRequestOwnerIds, sakeiReadOutputRecords, sakeiFreeOutputRecord, sakeiFreeOutputRecords, sakeiSearchForRecordsValidateInput, sakeiSearchForRecordsFillSoapRequest, sakeiSearchForRecordsProcessSoapResponse, sakeiSearchForRecordsFreeData, sakeiGetMyRecordsValidateInput, sakeiGetMyRecordsFillSoapRequest, sakeiGetMyRecordsProcessSoapResponse, sakeiGetMyRecordsFreeData, sakeiStartGetMyRecordsRequest, sakeiGetSpecificRecordsValidateInput, sakeiGetSpecificRecordsFillSoapRequest, sakeiGetSpecificRecordsProcessSoapResponse, sakeiGetSpecificRecordsFreeData, sakeiStartGetSpecificRecordsRequest, sakeiGetRandomRecordValidateInput, sakeiGetRandomRecordFillSoapRequest, sakeiGetRandomRecordProcessSoapResponse, sakeiGetRandomRecordFreeData
 * address:  0x021DE14C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy Sake client (libdwcgssake, object sakerequestread.o): the request
 * kinds that read records (SearchForRecords, GetMyRecords, GetSpecificRecords,
 * GetRandomRecord).  Each kind has a SAKERequestInfo table (in data) naming
 * its validate, fill, process-response and free callbacks; the helpers here
 * write the shared parts of the SOAP request and decode the record list of
 * the response.
 *
 * symbols:
 *   UTF8ToUCS2StringAlloc  0x021802C8  arm ov009
 *   gsXmlCountChildren  0x02183EE0  arm ov009
 *   gsXmlMoveToChild  0x021835D0  arm ov009
 *   gsXmlMoveToNext  0x021834E8  arm ov009
 *   gsXmlReadChildAsBase64Binary  0x02183918  arm ov009
 *   gsXmlReadChildAsDateTimeElement  0x02183BA4  arm ov009
 *   gsXmlReadChildAsFloat  0x02183CD4  arm ov009
 *   gsXmlReadChildAsInt  0x02183A24  arm ov009
 *   gsXmlReadChildAsInt64  0x02183AE4  arm ov009
 *   gsXmlReadChildAsString  0x02183670  arm ov009
 *   gsXmlWriteCloseTag  0x02182A2C  arm ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm ov009
 *   gsifree  0x0217EAE0  arm ov009
 *   gsimalloc  0x0217EAB0  arm ov009
 *   memset  0x020923B0  arm
 *   strcmp  0x020948E0  arm
 *   sGetSpecificRecordsRequestInfo  0x021E3C78  data
 *   sGetMyRecordsRequestInfo  0x021E3CA0  data
 *   sReadXmlNamespacePrefix  0x021E3DF8  data
 *   sReadTagFields  0x021E3DFC  data
 *   sReadTagString  0x021E3E04  data
 *   sReadTagRecordids  0x021E3E0C  data
 *   sReadTagInt  0x021E3E18  data
 *   sReadTagOwnerids  0x021E3E1C  data
 *   sReadTagTableid  0x021E3EFC  data
 *   sReadTagFilter  0x021E3F04  data
 *   sReadTagSort  0x021E3F0C  data
 *   sReadTagOffset  0x021E3F14  data
 *   sReadTagMax  0x021E3F1C  data
 *   sReadTagTargetfilter  0x021E3F20  data
 *   sReadTagSurrounding  0x021E3F30  data
 *   sReadTagCacheFlag  0x021E3F3C  data
 *   sakeiStartRequest  0x021DDB10  arm
 *   sReadTagValues  0x021E3E28  data
 *   sReadTagArrayOfRecordValue  0x021E3E30  data
 *   sReadTagRecordValue  0x021E3E44  data
 *   sReadTagByteValue  0x021E3E50  data
 *   sReadTagValue  0x021E3E5C  data
 *   sReadTagShortValue  0x021E3E64  data
 *   sReadTagIntValue  0x021E3E70  data
 *   sReadTagInt64Value  0x021E3E7C  data
 *   sReadTagFloatValue  0x021E3E88  data
 *   sReadTagAsciiStringValue  0x021E3E94  data
 *   sReadEmptyString  0x021E3EA8  data
 *   sReadTagUnicodeStringValue  0x021E3EAC  data
 *   sReadTagBooleanValue  0x021E3EC0  data
 *   sReadTagTrue  0x021E3ED0  data
 *   sReadTagDateAndTimeValue  0x021E3ED8  data
 *   sReadTagBinaryDataValue  0x021E3EEC  data
 */
#include "sake_types.h"

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlMoveToChild(void *stream, char *matchtag);
extern int gsXmlCountChildren(void *stream, char *matchtag);
extern void *gsimalloc(unsigned long size);
extern void memset(void *dst, int val, unsigned long n);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern int gsXmlReadChildAsInt64(void *stream, char *matchtag, long long *valueOut);
extern int gsXmlReadChildAsFloat(void *stream, char *matchtag, float *valueOut);
extern int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *lenOut);
extern unsigned short *UTF8ToUCS2StringAlloc(char *theUTF8String);
extern int strcmp(const char *a, const char *b);
extern int gsXmlReadChildAsDateTimeElement(void *stream, char *matchtag, long *valueOut);
extern int gsXmlReadChildAsBase64Binary(void *stream, char *matchtag, unsigned char *valueOut, int *lenOut);
extern void gsifree(void *ptr);
extern int sakeiStartRequest(SAKERequestInternal *request, SAKERequestInfo *info);
int sakeiValidateRequestFieldNames(char **fieldNames, int numFields);
void sakeiFillSoapRequestFieldNames(SAKERequestInternal *request, char **fieldNames, int numFields);
void sakeiFillSoapRequestRecordIds(SAKERequestInternal *request, int *recordIds, int numRecordIds);
void sakeiFillSoapRequestOwnerIds(SAKERequestInternal *request, int *ownerIds, int numOwnerIds);
int sakeiReadOutputRecords(SAKERequestInternal *request, SAKEField ***outputRecordsPtr, int *numRecords, int numFields, char **fieldNames);
void sakeiFreeOutputRecord(int numFields, SAKEField *record);
void sakeiFreeOutputRecords(int numFields, int numRecords, SAKEField **records);
int sakeiSearchForRecordsValidateInput(SAKERequestInternal *request);
int sakeiSearchForRecordsFillSoapRequest(SAKERequestInternal *request);
int sakeiSearchForRecordsProcessSoapResponse(SAKERequestInternal *request);
void sakeiSearchForRecordsFreeData(SAKERequestInternal *request);
int sakeiGetMyRecordsValidateInput(SAKERequestInternal *request);
int sakeiGetMyRecordsFillSoapRequest(SAKERequestInternal *request);
int sakeiGetMyRecordsProcessSoapResponse(SAKERequestInternal *request);
void sakeiGetMyRecordsFreeData(SAKERequestInternal *request);
int sakeiStartGetMyRecordsRequest(SAKERequestInternal *request);
int sakeiGetSpecificRecordsValidateInput(SAKERequestInternal *request);
int sakeiGetSpecificRecordsFillSoapRequest(SAKERequestInternal *request);
int sakeiGetSpecificRecordsProcessSoapResponse(SAKERequestInternal *request);
void sakeiGetSpecificRecordsFreeData(SAKERequestInternal *request);
int sakeiStartGetSpecificRecordsRequest(SAKERequestInternal *request);
int sakeiGetRandomRecordValidateInput(SAKERequestInternal *request);
int sakeiGetRandomRecordFillSoapRequest(SAKERequestInternal *request);
int sakeiGetRandomRecordProcessSoapResponse(SAKERequestInternal *request);
void sakeiGetRandomRecordFreeData(SAKERequestInternal *request);
extern char sReadXmlNamespacePrefix[];
extern char sReadTagFields[];
extern char sReadTagString[];
extern char sReadTagRecordids[];
extern char sReadTagInt[];
extern char sReadTagOwnerids[];
extern char sReadTagValues[];
extern char sReadTagArrayOfRecordValue[];
extern char sReadTagRecordValue[];
extern char sReadTagByteValue[];
extern char sReadTagValue[];
extern char sReadTagShortValue[];
extern char sReadTagIntValue[];
extern char sReadTagInt64Value[];
extern char sReadTagFloatValue[];
extern char sReadTagAsciiStringValue[];
extern char sReadEmptyString[];
extern char sReadTagUnicodeStringValue[];
extern char sReadTagBooleanValue[];
extern char sReadTagTrue[];
extern char sReadTagDateAndTimeValue[];
extern char sReadTagBinaryDataValue[];
extern char sReadTagTableid[];
extern char sReadTagFilter[];
extern char sReadTagSort[];
extern char sReadTagOffset[];
extern char sReadTagMax[];
extern char sReadTagTargetfilter[];
extern char sReadTagSurrounding[];
extern char sReadTagCacheFlag[];
extern SAKERequestInfo sGetMyRecordsRequestInfo;
extern SAKERequestInfo sGetSpecificRecordsRequestInfo;

/* Every field name must be a non-empty string. */
int sakeiValidateRequestFieldNames(char **fieldNames, int numFields)
{
    int i;

    for (i = 0; i < numFields; i++) {
        char *name = fieldNames[i];
        if (name == 0 || *name == 0)
            return SAKEStartRequestResult_BAD_FIELD_NAME;
    }
    return SAKEStartRequestResult_SUCCESS;
}

/* Writes the <fields> list with one <string> element per field name. */
void sakeiFillSoapRequestFieldNames(SAKERequestInternal *request, char **fieldNames, int numFields)
{
    int i;

    gsXmlWriteOpenTag(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagFields);
    for (i = 0; i < numFields; i++)
        gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagString, fieldNames[i]);
    gsXmlWriteCloseTag(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagFields);
}

/* Writes the <recordids> list with one <int> element per record id. */
void sakeiFillSoapRequestRecordIds(SAKERequestInternal *request, int *recordIds, int numRecordIds)
{
    int i;

    gsXmlWriteOpenTag(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagRecordids);
    for (i = 0; i < numRecordIds; i++)
        gsXmlWriteIntElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagInt, recordIds[i]);
    gsXmlWriteCloseTag(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagRecordids);
}

/* Writes the <ownerids> list with one <int> element per owner id. */
void sakeiFillSoapRequestOwnerIds(SAKERequestInternal *request, int *ownerIds, int numOwnerIds)
{
    int i;

    gsXmlWriteOpenTag(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagOwnerids);
    for (i = 0; i < numOwnerIds; i++)
        gsXmlWriteIntElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagInt, ownerIds[i]);
    gsXmlWriteCloseTag(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagOwnerids);
}

/*
 * Decodes the <values> list of the response into an array of records, each an
 * array of numFields typed values named after fieldNames.  Returns a
 * SAKERequestResult; on failure the records read so far stay in
 * *outputRecordsPtr for the free function.
 */
int sakeiReadOutputRecords(SAKERequestInternal *request, SAKEField ***outputRecordsPtr, int *numRecords, int numFields, char **fieldNames)
{
    SAKEField **outputRecords;
    SAKEField *outputRecord;
    SAKEField *outputField;
    int fieldIndex;
    int recordIndex;
    unsigned long size;

    if (!gsXmlMoveToChild(request->mSoapResponse, sReadTagValues))
        return SAKERequestResult_MALFORMED_RESPONSE;
    *numRecords = gsXmlCountChildren(request->mSoapResponse, sReadTagArrayOfRecordValue);
    if (*numRecords == 0) {
        *outputRecordsPtr = 0;
        return SAKERequestResult_SUCCESS;
    }
    size = *numRecords * sizeof(SAKEField *);
    outputRecords = (SAKEField **)gsimalloc(size);
    if (outputRecords == 0)
        return SAKERequestResult_OUT_OF_MEMORY;
    memset(outputRecords, 0, size);
    *outputRecordsPtr = outputRecords;
    for (recordIndex = 0; recordIndex < *numRecords; recordIndex++) {
        size = numFields * sizeof(SAKEField);
        if (!gsXmlMoveToNext(request->mSoapResponse, sReadTagArrayOfRecordValue))
            return SAKERequestResult_MALFORMED_RESPONSE;
        outputRecord = (SAKEField *)gsimalloc(size);
        if (outputRecord == 0)
            return SAKERequestResult_OUT_OF_MEMORY;
        memset(outputRecord, 0, size);
        outputRecords[recordIndex] = outputRecord;
        if (gsXmlCountChildren(request->mSoapResponse, sReadTagRecordValue) != numFields)
            return SAKERequestResult_MALFORMED_RESPONSE;
        for (fieldIndex = 0; fieldIndex < numFields; fieldIndex++) {
            outputField = &outputRecord[fieldIndex];
            outputField->mName = fieldNames[fieldIndex];
            if (!gsXmlMoveToNext(request->mSoapResponse, sReadTagRecordValue))
                return SAKERequestResult_MALFORMED_RESPONSE;
            if (gsXmlMoveToChild(request->mSoapResponse, sReadTagByteValue)) {
                int value;
                if (!gsXmlReadChildAsInt(request->mSoapResponse, sReadTagValue, &value))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                outputField->mType = SAKEFieldType_BYTE;
                outputField->mValue.mByte = (unsigned char)value;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagShortValue)) {
                int value;
                if (!gsXmlReadChildAsInt(request->mSoapResponse, sReadTagValue, &value))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                outputField->mType = SAKEFieldType_SHORT;
                outputField->mValue.mShort = (unsigned short)value;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagIntValue)) {
                int value;
                if (!gsXmlReadChildAsInt(request->mSoapResponse, sReadTagValue, &value))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                outputField->mType = SAKEFieldType_INT;
                outputField->mValue.mInt = value;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagInt64Value)) {
                long long value;
                if (!gsXmlReadChildAsInt64(request->mSoapResponse, sReadTagValue, &value))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                outputField->mType = SAKEFieldType_INT64;
                outputField->mValue.mInt64 = value;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagFloatValue)) {
                float value;
                if (!gsXmlReadChildAsFloat(request->mSoapResponse, sReadTagValue, &value))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                outputField->mType = SAKEFieldType_FLOAT;
                outputField->mValue.mFloat = value;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagAsciiStringValue)) {
                char *value;
                int len;
                if (!gsXmlReadChildAsString(request->mSoapResponse, sReadTagValue, &value, &len))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                if (value != 0)
                    value[len] = 0;
                else
                    value = sReadEmptyString;
                outputField->mType = SAKEFieldType_ASCII_STRING;
                outputField->mValue.mAsciiString = value;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagUnicodeStringValue)) {
                char *value;
                int len;
                unsigned short *valueUnicode;
                if (!gsXmlReadChildAsString(request->mSoapResponse, sReadTagValue, &value, &len))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                if (value != 0)
                    value[len] = 0;
                else
                    value = sReadEmptyString;
                valueUnicode = UTF8ToUCS2StringAlloc(value);
                if (valueUnicode == 0)
                    return SAKERequestResult_OUT_OF_MEMORY;
                outputField->mType = SAKEFieldType_UNICODE_STRING;
                outputField->mValue.mUnicodeString = valueUnicode;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagBooleanValue)) {
                char *value;
                int len;
                int boolval;
                if (!gsXmlReadChildAsString(request->mSoapResponse, sReadTagValue, &value, &len))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                if (value != 0) {
                    value[len] = 0;
                    boolval = (strcmp(value, sReadTagTrue) == 0);
                } else {
                    boolval = 0;
                }
                outputField->mType = SAKEFieldType_BOOLEAN;
                outputField->mValue.mBoolean = boolval;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagDateAndTimeValue)) {
                long value;
                if (!gsXmlReadChildAsDateTimeElement(request->mSoapResponse, sReadTagValue, &value))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                outputField->mType = SAKEFieldType_DATE_AND_TIME;
                outputField->mValue.mDateAndTime = value;
            } else if (gsXmlMoveToChild(request->mSoapResponse, sReadTagBinaryDataValue)) {
                unsigned char *value;
                int len;
                if (!gsXmlReadChildAsBase64Binary(request->mSoapResponse, sReadTagValue, 0, &len))
                    return SAKERequestResult_MALFORMED_RESPONSE;
                if (len > 0) {
                    value = (unsigned char *)gsimalloc(len);
                    if (value == 0)
                        return SAKERequestResult_OUT_OF_MEMORY;
                    if (!gsXmlReadChildAsBase64Binary(request->mSoapResponse, sReadTagValue, value, &len)) {
                        gsifree(value);
                        return SAKERequestResult_MALFORMED_RESPONSE;
                    }
                } else {
                    len = 0;
                    value = 0;
                }
                outputField->mType = SAKEFieldType_BINARY_DATA;
                outputField->mValue.mBinaryData.mLength = len;
                outputField->mValue.mBinaryData.mValue = value;
            } else {
                return SAKERequestResult_UNKNOWN_ERROR;
            }
        }
    }
    return SAKERequestResult_SUCCESS;
}

/* Frees one record: the heap values of binary and unicode fields, then the array. */
void sakeiFreeOutputRecord(int numFields, SAKEField *record)
{
    int i;

    if (record == 0)
        return;
    for (i = 0; i < numFields; i++) {
        if (record[i].mType == SAKEFieldType_BINARY_DATA && record[i].mValue.mBinaryData.mValue != 0)
            gsifree(record[i].mValue.mBinaryData.mValue);
        if (record[i].mType == SAKEFieldType_UNICODE_STRING)
            gsifree(record[i].mValue.mUnicodeString);
    }
    gsifree(record);
}

/* Frees every record of the list and the list itself. */
void sakeiFreeOutputRecords(int numFields, int numRecords, SAKEField **records)
{
    int i, j;

    if (records == 0)
        return;
    for (i = 0; i < numRecords; i++) {
        if (records[i] == 0)
            continue;
        for (j = 0; j < numFields; j++) {
            if (records[i][j].mType == SAKEFieldType_BINARY_DATA && records[i][j].mValue.mBinaryData.mValue != 0)
                gsifree(records[i][j].mValue.mBinaryData.mValue);
            if (records[i][j].mType == SAKEFieldType_UNICODE_STRING)
                gsifree(records[i][j].mValue.mUnicodeString);
        }
        gsifree(records[i]);
        records[i] = 0;
    }
    gsifree(records);
}

/* SearchForRecords: table, a field list, a non-negative offset and a positive maximum. */
int sakeiSearchForRecordsValidateInput(SAKERequestInternal *request)
{
    SAKESearchForRecordsInput *input = (SAKESearchForRecordsInput *)request->mInput;

    if (input->mTableId == 0)
        return SAKEStartRequestResult_BAD_TABLEID;
    if (input->mNumFields <= 0)
        return SAKEStartRequestResult_NO_FIELDS;
    if (input->mFieldNames == 0)
        return SAKEStartRequestResult_BAD_FIELDS;
    if (input->mOffset < 0)
        return SAKEStartRequestResult_BAD_OFFSET;
    if (input->mMaxRecords <= 0)
        return SAKEStartRequestResult_BAD_MAX;
    return sakeiValidateRequestFieldNames(input->mFieldNames, input->mNumFields);
}

int sakeiSearchForRecordsFillSoapRequest(SAKERequestInternal *request)
{
    SAKESearchForRecordsInput *input = (SAKESearchForRecordsInput *)request->mInput;

    gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagTableid, input->mTableId);
    if (input->mFilter) {
        gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagFilter, input->mFilter);
    }
    if (input->mSort) {
        gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagSort, input->mSort);
    }
    gsXmlWriteIntElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagOffset, input->mOffset);
    gsXmlWriteIntElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagMax, input->mMaxRecords);
    if (input->mTargetRecordFilter) {
        gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagTargetfilter, input->mTargetRecordFilter);
    }
    gsXmlWriteIntElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagSurrounding, input->mSurroundingRecordsCount);
    sakeiFillSoapRequestOwnerIds(request, input->mOwnerIds, input->mNumOwnerIds);
    gsXmlWriteIntElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagCacheFlag, input->mCacheFlag);
    sakeiFillSoapRequestFieldNames(request, input->mFieldNames, input->mNumFields);
    return 0;
}

int sakeiSearchForRecordsProcessSoapResponse(SAKERequestInternal *request)
{
    SAKESearchForRecordsInput *input = (SAKESearchForRecordsInput *)request->mInput;
    SAKERecordsOutput *output = (SAKERecordsOutput *)request->mOutput;

    return sakeiReadOutputRecords(request, &output->mRecords, &output->mNumRecords, input->mNumFields, input->mFieldNames);
}

void sakeiSearchForRecordsFreeData(SAKERequestInternal *request)
{
    SAKERecordsOutput *output = (SAKERecordsOutput *)request->mOutput;
    SAKESearchForRecordsInput *input = (SAKESearchForRecordsInput *)request->mInput;

    if (output == 0)
        return;
    sakeiFreeOutputRecords(input->mNumFields, output->mNumRecords, output->mRecords);
}

/* GetMyRecords: a table and a non-empty field list. */
int sakeiGetMyRecordsValidateInput(SAKERequestInternal *request)
{
    SAKEGetMyRecordsInput *input = (SAKEGetMyRecordsInput *)request->mInput;

    if (input->mTableId == 0)
        return SAKEStartRequestResult_BAD_TABLEID;
    if (input->mNumFields <= 0)
        return SAKEStartRequestResult_NO_FIELDS;
    if (input->mFieldNames == 0)
        return SAKEStartRequestResult_BAD_FIELDS;
    return sakeiValidateRequestFieldNames(input->mFieldNames, input->mNumFields);
}

int sakeiGetMyRecordsFillSoapRequest(SAKERequestInternal *request)
{
    SAKEGetMyRecordsInput *input = (SAKEGetMyRecordsInput *)request->mInput;

    gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagTableid, input->mTableId);
    sakeiFillSoapRequestFieldNames(request, input->mFieldNames, input->mNumFields);
    return 0;
}

int sakeiGetMyRecordsProcessSoapResponse(SAKERequestInternal *request)
{
    SAKEGetMyRecordsInput *input = (SAKEGetMyRecordsInput *)request->mInput;
    SAKERecordsOutput *output = (SAKERecordsOutput *)request->mOutput;

    return sakeiReadOutputRecords(request, &output->mRecords, &output->mNumRecords, input->mNumFields, input->mFieldNames);
}

void sakeiGetMyRecordsFreeData(SAKERequestInternal *request)
{
    SAKERecordsOutput *output = (SAKERecordsOutput *)request->mOutput;
    SAKEGetMyRecordsInput *input = (SAKEGetMyRecordsInput *)request->mInput;

    if (output == 0)
        return;
    sakeiFreeOutputRecords(input->mNumFields, output->mNumRecords, output->mRecords);
}

int sakeiStartGetMyRecordsRequest(SAKERequestInternal *request)
{
    return sakeiStartRequest(request, &sGetMyRecordsRequestInfo);
}

/* GetSpecificRecords: a table, record ids and a field list. */
int sakeiGetSpecificRecordsValidateInput(SAKERequestInternal *request)
{
    SAKEGetSpecificRecordsInput *input = (SAKEGetSpecificRecordsInput *)request->mInput;

    if (input->mTableId == 0)
        return SAKEStartRequestResult_BAD_TABLEID;
    if (input->mNumRecordIds <= 0)
        return SAKEStartRequestResult_BAD_NUM_RECORDIDS;
    if (input->mRecordIds == 0)
        return SAKEStartRequestResult_BAD_RECORDIDS;
    if (input->mNumFields <= 0)
        return SAKEStartRequestResult_NO_FIELDS;
    if (input->mFieldNames == 0)
        return SAKEStartRequestResult_BAD_FIELDS;
    return sakeiValidateRequestFieldNames(input->mFieldNames, input->mNumFields);
}

int sakeiGetSpecificRecordsFillSoapRequest(SAKERequestInternal *request)
{
    SAKEGetSpecificRecordsInput *input = (SAKEGetSpecificRecordsInput *)request->mInput;

    gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagTableid, input->mTableId);
    sakeiFillSoapRequestRecordIds(request, input->mRecordIds, input->mNumRecordIds);
    sakeiFillSoapRequestFieldNames(request, input->mFieldNames, input->mNumFields);
    return 0;
}

int sakeiGetSpecificRecordsProcessSoapResponse(SAKERequestInternal *request)
{
    SAKEGetSpecificRecordsInput *input = (SAKEGetSpecificRecordsInput *)request->mInput;
    SAKERecordsOutput *output = (SAKERecordsOutput *)request->mOutput;

    return sakeiReadOutputRecords(request, &output->mRecords, &output->mNumRecords, input->mNumFields, input->mFieldNames);
}

void sakeiGetSpecificRecordsFreeData(SAKERequestInternal *request)
{
    SAKERecordsOutput *output = (SAKERecordsOutput *)request->mOutput;
    SAKEGetSpecificRecordsInput *input = (SAKEGetSpecificRecordsInput *)request->mInput;

    if (output == 0)
        return;
    sakeiFreeOutputRecords(input->mNumFields, output->mNumRecords, output->mRecords);
}

int sakeiStartGetSpecificRecordsRequest(SAKERequestInternal *request)
{
    return sakeiStartRequest(request, &sGetSpecificRecordsRequestInfo);
}

/* GetRandomRecord: a table and a non-empty field list. */
int sakeiGetRandomRecordValidateInput(SAKERequestInternal *request)
{
    SAKEGetRandomRecordInput *input = (SAKEGetRandomRecordInput *)request->mInput;

    if (input->mTableId == 0)
        return SAKEStartRequestResult_BAD_TABLEID;
    if (input->mNumFields <= 0)
        return SAKEStartRequestResult_NO_FIELDS;
    if (input->mFieldNames == 0)
        return SAKEStartRequestResult_BAD_FIELDS;
    return sakeiValidateRequestFieldNames(input->mFieldNames, input->mNumFields);
}

/* Asks for one record: the maximum is the constant 1. */
int sakeiGetRandomRecordFillSoapRequest(SAKERequestInternal *request)
{
    SAKEGetRandomRecordInput *input = (SAKEGetRandomRecordInput *)request->mInput;

    gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagTableid, input->mTableId);
    if (input->mFilter != 0)
        gsXmlWriteStringElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagFilter, input->mFilter);
    gsXmlWriteIntElement(request->mSoapRequest, sReadXmlNamespacePrefix, sReadTagMax, 1);
    sakeiFillSoapRequestFieldNames(request, input->mFieldNames, input->mNumFields);
    return 0;
}

/* Reads the record list and keeps only its first record as the output. */
int sakeiGetRandomRecordProcessSoapResponse(SAKERequestInternal *request)
{
    SAKEGetRandomRecordInput *input = (SAKEGetRandomRecordInput *)request->mInput;
    SAKEGetRandomRecordOutput *output = (SAKEGetRandomRecordOutput *)request->mOutput;
    SAKEField **records;
    int numRecords;
    int result = sakeiReadOutputRecords(request, &records, &numRecords, input->mNumFields, input->mFieldNames);

    if (result == 0) {
        if (records != 0 && numRecords > 0)
            output->mRecord = *records;
        else
            output->mRecord = 0;
    }
    gsifree(records);
    return result;
}

void sakeiGetRandomRecordFreeData(SAKERequestInternal *request)
{
    SAKEGetRandomRecordOutput *output = (SAKEGetRandomRecordOutput *)request->mOutput;
    SAKEGetRandomRecordInput *input = (SAKEGetRandomRecordInput *)request->mInput;

    if (output == 0)
        return;
    sakeiFreeOutputRecord(input->mNumFields, output->mRecord);
}
