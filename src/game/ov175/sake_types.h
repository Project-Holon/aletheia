/*
 * Types of the GameSpy Sake client (libdwcgssake) shared by sakemain.c,
 * sakerequest.c, sakerequestmodify.c and sakerequestread.c.
 *
 * Sake is the record store behind the Wi-Fi battle ranking: a request is a
 * SOAP call; sakerequest.c owns the generic steps, and each request kind
 * supplies a SAKERequestInfo table with its tags and its four callbacks.
 */
#ifndef SAKE_TYPES_H
#define SAKE_TYPES_H

/* Result of starting a request (SAKE_StartRequest result codes). */
typedef enum SAKEStartRequestResult {
    SAKEStartRequestResult_SUCCESS = 0,
    SAKEStartRequestResult_NOT_AUTHENTICATED = 1,
    SAKEStartRequestResult_OUT_OF_MEMORY = 2,
    SAKEStartRequestResult_BAD_INPUT = 3,
    SAKEStartRequestResult_BAD_TABLEID = 4,
    SAKEStartRequestResult_BAD_FIELDS = 5,
    SAKEStartRequestResult_NO_FIELDS = 6,
    SAKEStartRequestResult_BAD_FIELD_NAME = 7,
    SAKEStartRequestResult_BAD_FIELD_TYPE = 8,
    SAKEStartRequestResult_BAD_FIELD_VALUE = 9,
    SAKEStartRequestResult_BAD_OFFSET = 10,
    SAKEStartRequestResult_BAD_MAX = 11,
    SAKEStartRequestResult_BAD_RECORDIDS = 12,
    SAKEStartRequestResult_BAD_NUM_RECORDIDS = 13
} SAKEStartRequestResult;

/* Result passed to the request callback (SAKERequestResult). */
typedef enum SAKERequestResult {
    SAKERequestResult_SUCCESS = 0,
    SAKERequestResult_SECRET_KEY_INVALID = 1,
    SAKERequestResult_SERVICE_DISABLED = 2,
    SAKERequestResult_CONNECTION_TIMEOUT = 3,
    SAKERequestResult_CONNECTION_ERROR = 4,
    SAKERequestResult_MALFORMED_RESPONSE = 5,
    SAKERequestResult_OUT_OF_MEMORY = 6,
    SAKERequestResult_DATABASE_UNAVAILABLE = 7,
    SAKERequestResult_LOGIN_TICKET_INVALID = 8,
    SAKERequestResult_LOGIN_TICKET_EXPIRED = 9,
    SAKERequestResult_TABLE_NOT_FOUND = 10,
    SAKERequestResult_RECORD_NOT_FOUND = 11,
    SAKERequestResult_FIELD_NOT_FOUND = 12,
    SAKERequestResult_FIELD_TYPE_INVALID = 13,
    SAKERequestResult_NO_PERMISSION = 14,
    SAKERequestResult_RECORD_LIMIT_REACHED = 15,
    SAKERequestResult_ALREADY_RATED = 16,
    SAKERequestResult_NOT_RATEABLE = 17,
    SAKERequestResult_NOT_OWNED = 18,
    SAKERequestResult_FILTER_INVALID = 19,
    SAKERequestResult_SORT_INVALID = 20,
    SAKERequestResult_TARGET_FILTER_INVALID = 21,
    SAKERequestResult_UNKNOWN_ERROR = 22,
    SAKERequestResult_REQUEST_CANCELLED = 23
} SAKERequestResult;

/* Type tag of a SAKEField value. */
typedef enum SAKEFieldType {
    SAKEFieldType_BYTE = 0,
    SAKEFieldType_SHORT = 1,
    SAKEFieldType_INT = 2,
    SAKEFieldType_FLOAT = 3,
    SAKEFieldType_ASCII_STRING = 4,
    SAKEFieldType_UNICODE_STRING = 5,
    SAKEFieldType_BOOLEAN = 6,
    SAKEFieldType_DATE_AND_TIME = 7,
    SAKEFieldType_BINARY_DATA = 8,
    SAKEFieldType_INT64 = 9
} SAKEFieldType;

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

/* One named, typed value of a record (16 bytes). */
typedef struct SAKEField {
    char *mName;
    SAKEFieldType mType;
    SAKEValue mValue;
} SAKEField;

/* Sake client state (0x4C bytes), allocated by sakeStartup. */
typedef struct SAKEInternal {
    int mStartedUp;
    char mGameName[16];
    int mGameId;
    char mSecretKey[12];
    int mProfileSet;
    int mProfileId;
    char mLoginTicket[25];
    int mStartRequestResult;
} SAKEInternal;

struct SAKERequestInternal;
struct GSTask;

typedef void (*SAKERequestCallback)(SAKEInternal *sake, struct SAKERequestInternal *request, int result,
                                    void *inputData, void *outputData, void *userData);

/*
 * Per request kind: SOAP tags, the four callbacks and the handle of the
 * running SOAP task.  One writable table per kind (d_ data in the object).
 */
typedef struct SAKERequestInfo {
    int mOutputSize;
    char *mFuncName;
    char *mSoapAction;
    char *mResponseTag;
    char *mResultTag;
    int (*mValidateInputFunc)(struct SAKERequestInternal *request);
    int (*mFillSoapRequestFunc)(struct SAKERequestInternal *request);
    int (*mProcessSoapResponseFunc)(struct SAKERequestInternal *request);
    void (*mFreeDataFunc)(struct SAKERequestInternal *request);
    struct GSTask *mSoapTask;
} SAKERequestInfo;

/* A running request (0x24 bytes). */
typedef struct SAKERequestInternal {
    SAKEInternal *mSake;
    int mType;
    void *mInput;
    void *mOutput;
    SAKERequestCallback mCallback;
    void *mUserData;
    void *mSoapRequest;
    void *mSoapResponse;
    SAKERequestInfo *mInfo;
} SAKERequestInternal;

/* Request inputs, one per request kind (mInput of the request). */
typedef struct SAKECreateRecordInput {
    char *mTableId;
    SAKEField *mFields;
    int mNumFields;
} SAKECreateRecordInput;

typedef struct SAKEUpdateRecordInput {
    char *mTableId;
    int mRecordId;
    SAKEField *mFields;
    int mNumFields;
} SAKEUpdateRecordInput;

typedef struct SAKEDeleteRecordInput {
    char *mTableId;
    int mRecordId;
} SAKEDeleteRecordInput;

typedef struct SAKESearchForRecordsInput {
    char *mTableId;
    char **mFieldNames;
    int mNumFields;
    char *mFilter;
    char *mSort;
    int mOffset;
    int mMaxRecords;
    char *mTargetRecordFilter;
    int mSurroundingRecordsCount;
    int *mOwnerIds;
    int mNumOwnerIds;
    int mCacheFlag;
} SAKESearchForRecordsInput;

typedef struct SAKEGetMyRecordsInput {
    char *mTableId;
    char **mFieldNames;
    int mNumFields;
} SAKEGetMyRecordsInput;

typedef struct SAKEGetSpecificRecordsInput {
    char *mTableId;
    int *mRecordIds;
    int mNumRecordIds;
    char **mFieldNames;
    int mNumFields;
} SAKEGetSpecificRecordsInput;

typedef struct SAKEGetRandomRecordInput {
    char *mTableId;
    char **mFieldNames;
    int mNumFields;
    char *mFilter;
} SAKEGetRandomRecordInput;

/* Request outputs (mOutput of the request, allocated by the response parser). */
typedef struct SAKECreateRecordOutput {
    int mRecordId;
} SAKECreateRecordOutput;

typedef struct SAKERecordsOutput {
    int mNumRecords;
    SAKEField **mRecords;
} SAKERecordsOutput;

typedef struct SAKEGetRandomRecordOutput {
    SAKEField *mRecord;
} SAKEGetRandomRecordOutput;

#endif
