/*
 * function: func_021E1948
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
 *   func_021E17D8  0x021E17D8  arm   ov175
 *   func_021E20D4  0x021E20D4  arm   ov175
 *   g_021E5334     0x021E5334  data
 *   g_021E534C     0x021E534C  data
 *   g_021E44D4     0x021E44D4  data
 *   g_021E4674     0x021E4674  data
 *   g_021E46A0     0x021E46A0  data
 *   g_021E46BC     0x021E46BC  data
 *   g_021E46E8     0x021E46E8  data
 *   g_021E4700     0x021E4700  data
 *   g_021E472C     0x021E472C  data
 *   g_021E4754     0x021E4754  data
 *   g_021E4768     0x021E4768  data
 *   g_021E477C     0x021E477C  data
 *   g_021E457C     0x021E457C  data
 *   g_021E478C     0x021E478C  data
 *   g_021E47A0     0x021E47A0  data
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

extern Tbl g_021E5334;
extern Work g_021E534C[];
extern char *g_021E44D4[];
extern char g_021E4674[];
extern char g_021E46A0[];
extern char g_021E46BC[];
extern char g_021E46E8[];
extern char g_021E4700[];
extern char g_021E472C[];
extern char g_021E4754[];
extern char g_021E4768[];
extern char g_021E477C[];
extern char g_021E457C[];
extern char g_021E478C[];
extern char g_021E47A0[];
extern void func_021E17D8(int line, char *fmt, ...);
extern int func_021E20D4(int process, int result);

void func_021E1948(void *sake, void *request, int result, void *inputData, void *outputData, void *userData)
{
    DWCGdbProcess process = g_021E5334.process;

    if (g_021E5334.state != 2 && g_021E5334.state != 3)
        return;

    if (result == 0) {
        g_021E5334.result = 1;
        g_021E5334.state = 1;
        g_021E5334.process = 0;

        switch (process) {
        case 2: {
            CreateRecordWork *work = &g_021E534C[g_021E5334.current_work].create;
            *work->recordId = *(int *)outputData;
            func_021E17D8(0x5af, g_021E4674, g_021E44D4[process], work->mTableId, work->mNumFields, *work->recordId);
            break;
        }
        case 3: {
            DeleteRecordWork *work = &g_021E534C[g_021E5334.current_work].del;
            func_021E17D8(0x5b8, g_021E46A0, g_021E44D4[process], work->mTableId, work->mRecordId);
            break;
        }
        case 4: {
            UpdateRecordWork *work = &g_021E534C[g_021E5334.current_work].update;
            func_021E17D8(0x5c2, g_021E46BC, g_021E44D4[process], work->mTableId, work->mRecordId, work->mNumFields);
            break;
        }
        case 7: {
            GetMyRecordsWork *work = &g_021E534C[g_021E5334.current_work].getMyRecords;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5cb, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 8: {
            GetRecordLimitWork *work = &g_021E534C[g_021E5334.current_work].getRecordLimit;
            *work->limit_num = ((int *)outputData)[0];
            *work->owned_num = ((int *)outputData)[1];
            func_021E17D8(0x5d8, g_021E4700, g_021E44D4[process], work->mTableId, *work->limit_num, *work->owned_num);
            break;
        }
        case 9: {
            GetRecordsWork *work = &g_021E534C[g_021E5334.current_work].getRecords;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5e1, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 10: {
            RateRecordWork *work = &g_021E534C[g_021E5334.current_work].rate;
            func_021E17D8(0x5ec, g_021E472C, g_021E44D4[process], work->mTableId, work->mRecordId, work->mRating);
            break;
        }
        case 11: {
            SearchRecordsWork *work = &g_021E534C[g_021E5334.current_work].search;
            RecordsOutput *output = outputData;
            func_021E17D8(0x5f5, g_021E46E8, g_021E44D4[process], output->mNumRecords);
            work->callback(output->mNumRecords, output->mRecords, userData);
            break;
        }
        case 12: {
            GetRandomRecordWork *work = &g_021E534C[g_021E5334.current_work].getRandomRecord;
            void **output = outputData;
            if (*output != 0) {
                func_021E17D8(0x5ff, g_021E4754, g_021E44D4[process]);
                work->callback(1, output, userData);
            } else {
                func_021E17D8(0x604, g_021E4768, g_021E44D4[process]);
                work->callback(0, 0, userData);
            }
            break;
        }
        case 13: {
            GetRecordCountWork *work = &g_021E534C[g_021E5334.current_work].getRecordCount;
            *work->count = *(int *)outputData;
            func_021E17D8(0x60d, g_021E477C, g_021E44D4[process], *work->count);
            break;
        }
        default:
            func_021E17D8(0x613, g_021E457C, process);
            break;
        }
    } else if (result == 0x17) {
        func_021E17D8(0x61a, g_021E478C, g_021E44D4[g_021E5334.process], result);
        g_021E5334.result = 0x20;
        g_021E5334.state = 1;
        g_021E5334.process = 0;
    } else {
        func_021E17D8(0x621, g_021E47A0, g_021E44D4[g_021E5334.process], result);
        g_021E5334.result = func_021E20D4(g_021E5334.process, result);
        g_021E5334.state = 1;
        g_021E5334.process = 0;
    }
}
