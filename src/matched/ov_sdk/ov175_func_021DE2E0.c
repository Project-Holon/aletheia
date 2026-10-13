/*
 * function: sakeiReadOutputRecords
 * address:  0x021DE2E0
 * packet:   pkt_ov175_021DE2E0
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeiReadOutputRecords (libdwcgssake.TWL.HYB.a sakerequestread.o)
 *
 * symbols:
 *   gsXmlMoveToChild              0x021835D0 arm ov009
 *   gsXmlCountChildren            0x02183EE0 arm ov009
 *   gsimalloc                     0x0217EAB0 arm ov009
 *   memset                        0x020923B0 arm
 *   gsXmlMoveToNext               0x021834E8 arm ov009
 *   gsXmlReadChildAsInt           0x02183A24 arm ov009
 *   gsXmlReadChildAsInt64         0x02183AE4 arm ov009
 *   gsXmlReadChildAsFloat         0x02183CD4 arm ov009
 *   gsXmlReadChildAsString        0x02183670 arm ov009
 *   UTF8ToUCS2StringAlloc         0x021802C8 arm ov009
 *   strcmp                        0x020948E0 arm
 *   gsXmlReadChildAsDateTimeElement 0x02183BA4 arm ov009
 *   gsXmlReadChildAsBase64Binary  0x02183918 arm ov009
 *   gsifree                       0x0217EAE0 arm ov009
 *   sReadTagValues                    0x021E3E28 data ov175
 *   sReadTagArrayOfRecordValue                    0x021E3E30 data ov175
 *   sReadTagRecordValue                    0x021E3E44 data ov175
 *   sReadTagByteValue                    0x021E3E50 data ov175
 *   sReadTagValue                    0x021E3E5C data ov175
 *   sReadTagShortValue                    0x021E3E64 data ov175
 *   sReadTagIntValue                    0x021E3E70 data ov175
 *   sReadTagInt64Value                    0x021E3E7C data ov175
 *   sReadTagFloatValue                    0x021E3E88 data ov175
 *   sReadTagAsciiStringValue                    0x021E3E94 data ov175
 *   sReadEmptyString                    0x021E3EA8 data ov175
 *   sReadTagUnicodeStringValue                    0x021E3EAC data ov175
 *   sReadTagBooleanValue                    0x021E3EC0 data ov175
 *   sReadTagTrue                    0x021E3ED0 data ov175
 *   sReadTagDateAndTimeValue                    0x021E3ED8 data ov175
 *   sReadTagBinaryDataValue                    0x021E3EEC data ov175
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SAKEField {
    char *name;
    int type;
    union {
        u8 byte;
        u16 sshort;
        int ival;
        float fval;
        char *str;
        unsigned short *ustr;
        long long i64;
        struct {
            unsigned char *ptr;
            int len;
        } binary;
        int bval;
        long date;
    } value;
} SAKEField;

typedef struct SAKERequestInternal {
    char pad0[0x1c];
    void *stream;
} SAKERequestInternal;

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

static int sakeiReadOutputRecords(SAKERequestInternal *request,
                                  SAKEField ***outputRecordsPtr, int *numRecords,
                                  int numFields, char **fieldNames)
{
    SAKEField **outputRecords;
    SAKEField *outputRecord;
    SAKEField *outputField;
    int fieldIndex;
    int recordIndex;
    unsigned long size;

    if (!gsXmlMoveToChild(request->stream, sReadTagValues))
        return 5;

    *numRecords = gsXmlCountChildren(request->stream, sReadTagArrayOfRecordValue);
    if (*numRecords == 0) {
        *outputRecordsPtr = 0;
        return 0;
    }

    size = *numRecords * 4;
    outputRecords = (SAKEField **)gsimalloc(size);
    if (outputRecords == 0)
        return 6;
    memset(outputRecords, 0, size);
    *outputRecordsPtr = outputRecords;

    for (recordIndex = 0; recordIndex < *numRecords; recordIndex++) {
        size = numFields << 4;
        {
            if (!gsXmlMoveToNext(request->stream, sReadTagArrayOfRecordValue))
                return 5;

            outputRecord = (SAKEField *)gsimalloc(size);
            if (outputRecord == 0)
                return 6;
            memset(outputRecord, 0, size);
            outputRecords[recordIndex] = outputRecord;

            if (gsXmlCountChildren(request->stream, sReadTagRecordValue) != numFields)
                return 5;

            for (fieldIndex = 0; fieldIndex < numFields; fieldIndex++) {
                outputField = &outputRecord[fieldIndex];
                outputField->name = fieldNames[fieldIndex];
                if (!gsXmlMoveToNext(request->stream, sReadTagRecordValue))
                    return 5;

                if (gsXmlMoveToChild(request->stream, sReadTagByteValue)) {
                    int value;
                    if (!gsXmlReadChildAsInt(request->stream, sReadTagValue, &value))
                        return 5;
                    outputField->type = 0;
                    outputField->value.byte = (u8)value;
                } else if (gsXmlMoveToChild(request->stream, sReadTagShortValue)) {
                    int value;
                    if (!gsXmlReadChildAsInt(request->stream, sReadTagValue, &value))
                        return 5;
                    outputField->type = 1;
                    outputField->value.sshort = (u16)value;
                } else if (gsXmlMoveToChild(request->stream, sReadTagIntValue)) {
                    int value;
                    if (!gsXmlReadChildAsInt(request->stream, sReadTagValue, &value))
                        return 5;
                    outputField->type = 2;
                    outputField->value.ival = value;
                } else if (gsXmlMoveToChild(request->stream, sReadTagInt64Value)) {
                    long long value;
                    if (!gsXmlReadChildAsInt64(request->stream, sReadTagValue, &value))
                        return 5;
                    outputField->type = 9;
                    outputField->value.i64 = value;
                } else if (gsXmlMoveToChild(request->stream, sReadTagFloatValue)) {
                    float value;
                    if (!gsXmlReadChildAsFloat(request->stream, sReadTagValue, &value))
                        return 5;
                    outputField->type = 3;
                    outputField->value.fval = value;
                } else if (gsXmlMoveToChild(request->stream, sReadTagAsciiStringValue)) {
                    char *value;
                    int len;
                    if (!gsXmlReadChildAsString(request->stream, sReadTagValue, &value, &len))
                        return 5;
                    if (value != 0)
                        value[len] = 0;
                    else
                        value = sReadEmptyString;
                    outputField->type = 4;
                    outputField->value.str = value;
                } else if (gsXmlMoveToChild(request->stream, sReadTagUnicodeStringValue)) {
                    char *value;
                    int len;
                    unsigned short *valueUnicode;
                    if (!gsXmlReadChildAsString(request->stream, sReadTagValue, &value, &len))
                        return 5;
                    if (value != 0)
                        value[len] = 0;
                    else
                        value = sReadEmptyString;
                    valueUnicode = UTF8ToUCS2StringAlloc(value);
                    if (valueUnicode == 0)
                        return 6;
                    outputField->type = 5;
                    outputField->value.ustr = valueUnicode;
                } else if (gsXmlMoveToChild(request->stream, sReadTagBooleanValue)) {
                    char *value;
                    int len;
                    int boolval;
                    if (!gsXmlReadChildAsString(request->stream, sReadTagValue, &value, &len))
                        return 5;
                    if (value != 0) {
                        value[len] = 0;
                        boolval = (strcmp(value, sReadTagTrue) == 0);
                    } else {
                        boolval = 0;
                    }
                    outputField->type = 6;
                    outputField->value.bval = boolval;
                } else if (gsXmlMoveToChild(request->stream, sReadTagDateAndTimeValue)) {
                    long value;
                    if (!gsXmlReadChildAsDateTimeElement(request->stream, sReadTagValue, &value))
                        return 5;
                    outputField->type = 7;
                    outputField->value.date = value;
                } else if (gsXmlMoveToChild(request->stream, sReadTagBinaryDataValue)) {
                    unsigned char *value;
                    int len;
                    if (!gsXmlReadChildAsBase64Binary(request->stream, sReadTagValue, 0, &len))
                        return 5;
                    if (len > 0) {
                        value = (unsigned char *)gsimalloc(len);
                        if (value == 0)
                            return 6;
                        if (!gsXmlReadChildAsBase64Binary(request->stream, sReadTagValue, value, &len)) {
                            gsifree(value);
                            return 5;
                        }
                    } else {
                        len = 0;
                        value = 0;
                    }
                    outputField->type = 8;
                    outputField->value.binary.len = len;
                    outputField->value.binary.ptr = value;
                } else {
                    return 22;
                }
            }
        }
    }

    return 0;
}
