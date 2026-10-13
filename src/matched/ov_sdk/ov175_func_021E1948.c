/*
 * function: DWCi_GdbSakeRequestCallback
 * address:  0x021E1948
 * packet:   pkt_ov175_021E1948
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GdbSakeRequestCallback (dwc_gdb.o)
 *
 * The process local and the s_tbl field are both enum typed (DWARF).  With an
 * enum local the error paths reload s_tbl.process after the state test, as the
 * object does; an int local lets the compiler reuse the entry load there.
 *
 * symbols:
 *   DWCi_GdbPrintf  0x021E17D8  arm   ov175
 *   DWCi_GdbHandleRequestResult  0x021E20D4  arm   ov175
 *   gDwcGdbEntity     0x021E5334  data
 *   g_021E534C     0x021E534C  data
 *   sDwcGdbProcessNames     0x021E44D4  data
 *   sDwcGdbCreateRecordDoneFormat     0x021E4674  data
 *   sDwcGdbDeleteRecordDoneFormat     0x021E46A0  data
 *   sDwcGdbUpdateRecordDoneFormat     0x021E46BC  data
 *   sDwcGdbRecordNumFormat     0x021E46E8  data
 *   sDwcGdbGetRecordLimitDoneFormat     0x021E4700  data
 *   sDwcGdbRateRecordDoneFormat     0x021E472C  data
 *   sDwcGdbOneRecordFormat     0x021E4754  data
 *   sDwcGdbNoRecordFormat     0x021E4768  data
 *   sDwcGdbGetRecordCountDoneFormat     0x021E477C  data
 *   sDwcGdbIllegalProcess     0x021E457C  data
 *   sDwcGdbCanceledFormat     0x021E478C  data
 *   sDwcGdbFailedFormat     0x021E47A0  data
 */

typedef enum { DWC_GDB_PROCESS_NONE } DWCGdbProcess;

typedef void (*DWCGdbGetRecordsCallback)(int num, void **records, void *user_param);

typedef struct {
    int unk0;
    void *sake;
    int state;
    DWCGdbProcess process;
    int result;
    unsigned long current_work;
} Tbl;

typedef struct {
    void *request;
    char *mTableId;
    void *mFields;
    int mNumFields;
    int *recordId;
} CreateRecordWork;

typedef struct {
    void *request;
    char *mTableId;
    int mRecordId;
} DeleteRecordWork;

typedef struct {
    void *request;
    char *mTableId;
    int mRecordId;
    void *mFields;
    int mNumFields;
} UpdateRecordWork;

typedef struct {
    void *request;
    char *mTableId;
    char **mFieldNames;
    int mNumFields;
    DWCGdbGetRecordsCallback callback;
} GetMyRecordsWork;

typedef struct {
    void *request;
    char *mTableId;
    int *limit_num;
    int *owned_num;
} GetRecordLimitWork;

typedef struct {
    void *request;
    char *mTableId;
    int *mRecordIds;
    int mNumRecordIds;
    char **mFieldNames;
    int mNumFields;
    DWCGdbGetRecordsCallback callback;
} GetRecordsWork;

typedef struct {
    void *request;
    char *mTableId;
    int mRecordId;
    unsigned char mRating;
} RateRecordWork;

typedef struct {
    void *request;
    char pad4[0x34 - 0x4];
    DWCGdbGetRecordsCallback callback;
} SearchRecordsWork;

typedef struct {
    void *request;
    char *mTableId;
    char **mFieldNames;
    int mNumFields;
    char *mFilter;
    DWCGdbGetRecordsCallback callback;
} GetRandomRecordWork;

typedef struct {
    void *request;
    char *mTableId;
    char *mFilter;
    int mCacheFlag;
    int *count;
} GetRecordCountWork;

typedef union {
    CreateRecordWork create;
    DeleteRecordWork del;
    UpdateRecordWork update;
    GetMyRecordsWork getMyRecords;
    GetRecordLimitWork getRecordLimit;
    GetRecordsWork getRecords;
    RateRecordWork rate;
    SearchRecordsWork search;
    GetRandomRecordWork getRandomRecord;
    GetRecordCountWork getRecordCount;
    char size[0x38];
} Work;

typedef struct {
    int mNumRecords;
    void **mRecords;
} RecordsOutput;

extern Tbl gDwcGdbEntity;
extern Work g_021E534C[];
extern char *sDwcGdbProcessNames[];
extern char sDwcGdbCreateRecordDoneFormat[];
extern char sDwcGdbDeleteRecordDoneFormat[];
extern char sDwcGdbUpdateRecordDoneFormat[];
extern char sDwcGdbRecordNumFormat[];
extern char sDwcGdbGetRecordLimitDoneFormat[];
extern char sDwcGdbRateRecordDoneFormat[];
extern char sDwcGdbOneRecordFormat[];
extern char sDwcGdbNoRecordFormat[];
extern char sDwcGdbGetRecordCountDoneFormat[];
extern char sDwcGdbIllegalProcess[];
extern char sDwcGdbCanceledFormat[];
extern char sDwcGdbFailedFormat[];
extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern int DWCi_GdbHandleRequestResult(int process, int result);

void DWCi_GdbSakeRequestCallback(void *sake, void *request, int result, void *inputData, void *outputData, void *userData)
{
    DWCGdbProcess process = gDwcGdbEntity.process;

    if (gDwcGdbEntity.state != 2 && gDwcGdbEntity.state != 3)
        return;

    if (result == 0) {
        gDwcGdbEntity.result = 1;
        gDwcGdbEntity.state = 1;
        gDwcGdbEntity.process = 0;

        switch (process) {
        case 2: {
            CreateRecordWork *work = &g_021E534C[gDwcGdbEntity.current_work].create;
            *work->recordId = *(int *)outputData;
            DWCi_GdbPrintf(0x5af, sDwcGdbCreateRecordDoneFormat, sDwcGdbProcessNames[process], work->mTableId, work->mNumFields, *work->recordId);
            break;
        }
        case 3: {
            DeleteRecordWork *work = &g_021E534C[gDwcGdbEntity.current_work].del;
            DWCi_GdbPrintf(0x5b8, sDwcGdbDeleteRecordDoneFormat, sDwcGdbProcessNames[process], work->mTableId, work->mRecordId);
            break;
        }
        case 4: {
            UpdateRecordWork *work = &g_021E534C[gDwcGdbEntity.current_work].update;
            DWCi_GdbPrintf(0x5c2, sDwcGdbUpdateRecordDoneFormat, sDwcGdbProcessNames[process], work->mTableId, work->mRecordId, work->mNumFields);
            break;
        }
        case 7: {
            GetMyRecordsWork *work = &g_021E534C[gDwcGdbEntity.current_work].getMyRecords;
            RecordsOutput *output = outputData;
            DWCi_GdbPrintf(0x5cb, sDwcGdbRecordNumFormat, sDwcGdbProcessNames[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 8: {
            GetRecordLimitWork *work = &g_021E534C[gDwcGdbEntity.current_work].getRecordLimit;
            *work->limit_num = ((int *)outputData)[0];
            *work->owned_num = ((int *)outputData)[1];
            DWCi_GdbPrintf(0x5d8, sDwcGdbGetRecordLimitDoneFormat, sDwcGdbProcessNames[process], work->mTableId, *work->limit_num, *work->owned_num);
            break;
        }
        case 9: {
            GetRecordsWork *work = &g_021E534C[gDwcGdbEntity.current_work].getRecords;
            RecordsOutput *output = outputData;
            DWCi_GdbPrintf(0x5e1, sDwcGdbRecordNumFormat, sDwcGdbProcessNames[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 10: {
            RateRecordWork *work = &g_021E534C[gDwcGdbEntity.current_work].rate;
            DWCi_GdbPrintf(0x5ec, sDwcGdbRateRecordDoneFormat, sDwcGdbProcessNames[process], work->mTableId, work->mRecordId, work->mRating);
            break;
        }
        case 11: {
            SearchRecordsWork *work = &g_021E534C[gDwcGdbEntity.current_work].search;
            RecordsOutput *output = outputData;
            DWCi_GdbPrintf(0x5f5, sDwcGdbRecordNumFormat, sDwcGdbProcessNames[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 12: {
            GetRandomRecordWork *work = &g_021E534C[gDwcGdbEntity.current_work].getRandomRecord;
            void **output = outputData;
            if (*output != 0) {
                DWCi_GdbPrintf(0x5ff, sDwcGdbOneRecordFormat, sDwcGdbProcessNames[process]);
                work->callback(1, output, userData);
            } else {
                DWCi_GdbPrintf(0x604, sDwcGdbNoRecordFormat, sDwcGdbProcessNames[process]);
                work->callback(0, 0, userData);
            }
            break;
        }
        case 13: {
            GetRecordCountWork *work = &g_021E534C[gDwcGdbEntity.current_work].getRecordCount;
            *work->count = *(int *)outputData;
            DWCi_GdbPrintf(0x60d, sDwcGdbGetRecordCountDoneFormat, sDwcGdbProcessNames[process], *work->count);
            break;
        }
        default:
            DWCi_GdbPrintf(0x613, sDwcGdbIllegalProcess, process);
            break;
        }
    } else if (result == 0x17) {
        DWCi_GdbPrintf(0x61a, sDwcGdbCanceledFormat, sDwcGdbProcessNames[gDwcGdbEntity.process], result);
        gDwcGdbEntity.result = 0x20;
        gDwcGdbEntity.state = 1;
        gDwcGdbEntity.process = 0;
    } else {
        DWCi_GdbPrintf(0x621, sDwcGdbFailedFormat, sDwcGdbProcessNames[gDwcGdbEntity.process], result);
        gDwcGdbEntity.result = DWCi_GdbHandleRequestResult(gDwcGdbEntity.process, result);
        gDwcGdbEntity.state = 1;
        gDwcGdbEntity.process = 0;
    }
}
