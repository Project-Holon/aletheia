/*
 * Types of the DWC game database wrapper (libdwcgdb, dwc_gdb.c).
 *
 * The game database is the Sake record store (sake_types.h).  The wrapper keeps
 * one request in flight at a time: DWCiGdbEntity holds its state, the kind of
 * request and, per request, the Sake input record with the caller's output
 * pointers or callback behind it.  Two work slots alternate, so a new request
 * can start while the callback of the previous one still reads its slot.
 */
#ifndef GDB_TYPES_H
#define GDB_TYPES_H

#include "sake_types.h"

/* Account data that the wrapper reads the GameSpy profile id from. */
typedef struct DWCstAccUserData {
    int size;
    unsigned int pseudo[3];
    unsigned int authentic[3];
    int gs_profile_id;
    int flag;
    unsigned int gamecode;
    int reserved[5];
    unsigned int crc32;
} DWCstAccUserData;

/* State of the wrapper (DWCiGdbEntity.state). */
typedef enum DWCGdbState {
    DWC_GDB_STATE_NOT_INITIALIZED = 0,
    DWC_GDB_STATE_IDLE = 1,
    DWC_GDB_STATE_IN_ASYNC_PROCESS = 2,
    DWC_GDB_STATE_IN_CANCEL_PROCESS = 3,
    DWC_GDB_STATE_ERROR = 4
} DWCGdbState;

/* Kind of the request in flight (DWCiGdbEntity.process); the names are the debug strings. */
typedef enum DWCGdbProcess {
    DWC_GDB_PROCESS_NONE = 0,
    DWC_GDB_PROCESS_INITIALIZE = 1,
    DWC_GDB_PROCESS_CREATE_RECORD = 2,
    DWC_GDB_PROCESS_DELETE_RECORD = 3,
    DWC_GDB_PROCESS_UPDATE_RECORD = 4,
    DWC_GDB_PROCESS_DOWNLOAD_FILE = 5,
    DWC_GDB_PROCESS_UPLOAD_FILE = 6,
    DWC_GDB_PROCESS_GET_MY_RECORDS = 7,
    DWC_GDB_PROCESS_GET_RECORD_LIMIT = 8,
    DWC_GDB_PROCESS_GET_RECORDS = 9,
    DWC_GDB_PROCESS_RATE_RECORD = 10,
    DWC_GDB_PROCESS_SEARCH_RECORDS = 11,
    DWC_GDB_PROCESS_GET_RANDOM_RECORD = 12,
    DWC_GDB_PROCESS_GET_RECORD_COUNT = 13
} DWCGdbProcess;

/* Result of a call (DWCGdbError). */
typedef enum DWCGdbError {
    DWC_GDB_ERROR_NONE = 0,
    DWC_GDB_ERROR_OUT_OF_MEMORY = 1,
    DWC_GDB_ERROR_NOT_AVAILABLE = 2,
    DWC_GDB_ERROR_CORE_SHUTDOWN = 3,
    DWC_GDB_ERROR_LOGIN_TICKET = 4,
    DWC_GDB_ERROR_NOT_AUTHENTICATED = 5,
    DWC_GDB_ERROR_BAD_INPUT = 6,
    DWC_GDB_ERROR_BAD_TABLE_ID = 7,
    DWC_GDB_ERROR_BAD_FIELDS = 8,
    DWC_GDB_ERROR_NO_FIELDS = 9,
    DWC_GDB_ERROR_BAD_FIELD_NAME = 10,
    DWC_GDB_ERROR_BAD_FIELD_TYPE = 11,
    DWC_GDB_ERROR_BAD_FIELD_VALUE = 12,
    DWC_GDB_ERROR_BAD_OFFSET = 13,
    DWC_GDB_ERROR_BAD_MAX = 14,
    DWC_GDB_ERROR_BAD_RECORD_IDS = 15,
    DWC_GDB_ERROR_BAD_NUM_RECORD_IDS = 16,
    DWC_GDB_ERROR_ILLEGAL = 17,
    DWC_GDB_ERROR_ALREADY_INITIALIZED = 18,
    DWC_GDB_ERROR_NOT_INITIALIZED = 19,
    DWC_GDB_ERROR_IN_ASYNC_PROCESS = 20,
    DWC_GDB_ERROR_IN_DWC_ERROR = 22,
    DWC_GDB_ERROR_IN_CANCEL_PROCESS = 23
} DWCGdbError;

/* Result of a finished request (DWCGdbAsyncResult); 2 to 0x20 follow the Sake result codes. */
typedef enum DWCGdbAsyncResult {
    DWC_GDB_ASYNC_RESULT_NONE = 0,
    DWC_GDB_ASYNC_RESULT_SUCCESS = 1,
    DWC_GDB_ASYNC_RESULT_SECRET_KEY_INVALID = 2,
    DWC_GDB_ASYNC_RESULT_SERVICE_DISABLED = 3,
    DWC_GDB_ASYNC_RESULT_CONNECTION_TIMEOUT = 4,
    DWC_GDB_ASYNC_RESULT_CONNECTION_ERROR = 5,
    DWC_GDB_ASYNC_RESULT_MALFORMED_RESPONSE = 6,
    DWC_GDB_ASYNC_RESULT_OUT_OF_MEMORY = 7,
    DWC_GDB_ASYNC_RESULT_DATABASE_UNAVAILABLE = 8,
    DWC_GDB_ASYNC_RESULT_LOGIN_TICKET_INVALID = 9,
    DWC_GDB_ASYNC_RESULT_LOGIN_TICKET_EXPIRED = 10,
    DWC_GDB_ASYNC_RESULT_TABLE_NOT_FOUND = 11,
    DWC_GDB_ASYNC_RESULT_RECORD_NOT_FOUND = 12,
    DWC_GDB_ASYNC_RESULT_FIELD_NOT_FOUND = 13,
    DWC_GDB_ASYNC_RESULT_FIELD_TYPE_INVALID = 14,
    DWC_GDB_ASYNC_RESULT_NO_PERMISSION = 15,
    DWC_GDB_ASYNC_RESULT_RECORD_LIMIT_REACHED = 16,
    DWC_GDB_ASYNC_RESULT_ALREADY_RATED = 17,
    DWC_GDB_ASYNC_RESULT_NOT_RATEABLE = 18,
    DWC_GDB_ASYNC_RESULT_NOT_OWNED = 19,
    DWC_GDB_ASYNC_RESULT_FILTER_INVALID = 20,
    DWC_GDB_ASYNC_RESULT_SORT_INVALID = 21,
    DWC_GDB_ASYNC_RESULT_UNKNOWN_ERROR = 22,
    DWC_GDB_ASYNC_RESULT_TARGET_FILTER_INVALID = 30,
    DWC_GDB_ASYNC_RESULT_CANCELED = 32
} DWCGdbAsyncResult;

/* Callback for requests that return records: record count, the records, the caller's data. */
typedef void (*DWCGdbGetRecordsCallback)(int num, SAKEField **records, void *user_param);

/* Output of a get-record-limit request. */
typedef struct DWCiGdbRecordLimitOutput {
    int mLimitNum;
    int mOwnedNum;
} DWCiGdbRecordLimitOutput;

/* Output of a get-record-count request. */
typedef struct DWCiGdbRecordCountOutput {
    int mCount;
} DWCiGdbRecordCountOutput;

/*
 * One slot of work data (56 bytes).  Every variant starts with the running
 * request and holds the Sake input record of its kind, then the caller's
 * output pointers or callback.  The file transfers keep a GHTTP request handle.
 */
typedef union DWCiGdbWork {
    struct {
        SAKERequestInternal *request;
    } sake;
    struct {
        int ghttpRequest;
    } downloadFile;
    struct {
        int reserved;
        int ghttpRequest;
    } uploadFile;
    struct {
        SAKERequestInternal *request;
        SAKECreateRecordInput input;
        int *recordIdOut;
    } createRecord;
    struct {
        SAKERequestInternal *request;
        SAKEDeleteRecordInput input;
    } deleteRecord;
    struct {
        SAKERequestInternal *request;
        SAKEUpdateRecordInput input;
    } updateRecord;
    struct {
        SAKERequestInternal *request;
        SAKEGetMyRecordsInput input;
        DWCGdbGetRecordsCallback callback;
    } getMyRecords;
    struct {
        SAKERequestInternal *request;
        char *mTableId;
        int *limitNumOut;
        int *ownedNumOut;
    } getRecordLimit;
    struct {
        SAKERequestInternal *request;
        SAKEGetSpecificRecordsInput input;
        DWCGdbGetRecordsCallback callback;
    } getRecords;
    struct {
        SAKERequestInternal *request;
        char *mTableId;
        int mRecordId;
        unsigned char mRating;
    } rateRecord;
    struct {
        SAKERequestInternal *request;
        SAKESearchForRecordsInput input;
        DWCGdbGetRecordsCallback callback;
    } searchRecords;
    struct {
        SAKERequestInternal *request;
        SAKEGetRandomRecordInput input;
        DWCGdbGetRecordsCallback callback;
    } getRandomRecord;
    struct {
        SAKERequestInternal *request;
        char *mTableId;
        char *mFilter;
        int mCacheFlag;
        int *countOut;
    } getRecordCount;
} DWCiGdbWork;

/* State of the wrapper (0x88 bytes); one instance in the overlay's data. */
typedef struct DWCiGdbEntity {
    int reserved;
    SAKEInternal *sake;
    int state;
    DWCGdbProcess process;
    int result;
    int currentWork;
    DWCiGdbWork work[2];
} DWCiGdbEntity;

#endif
